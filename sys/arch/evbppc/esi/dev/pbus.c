/*	$NetBSD: pbus.c,v 1.13 2011/07/01 19:03:51 dyoung Exp $	*/

/*
 * Copyright 2001 Wasabi Systems, Inc.
 * All rights reserved.
 *
 * Written by Eduardo Horvath and Simon Burge for Wasabi Systems, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed for the NetBSD Project by
 *      Wasabi Systems, Inc.
 * 4. The name of Wasabi Systems, Inc. may not be used to endorse
 *    or promote products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Copyright (c) 1996 Christopher G. Demetriou.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Christopher G. Demetriou
 *	for the NetBSD Project.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: pbus.c,v 1.13 2011/07/01 19:03:51 dyoung Exp $");

#include "locators.h"
#include "pckbc.h"

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/device.h>

#include <sys/bus.h>
#include <machine/walnut.h>

#include <evbppc/walnut/dev/pbusvar.h>

#include <powerpc/ibm4xx/ibm405gp.h>
#include <powerpc/ibm4xx/dev/plbvar.h>

/*
 * The external devices on the Walnut 405GP evaluation board.
 */
const struct pbus_dev {
	const char *name;
	bus_addr_t addr;
	int irq;
} pbus_devs [] = {
	{ NULL }
};

static int	pbus_match(device_t, cfdata_t, void *);
static void	pbus_attach(device_t, device_t, void *);
static int	pbus_print(void *, const char *);

CFATTACH_DECL_NEW(pbus, 0,
    pbus_match, pbus_attach, NULL, NULL);

static struct powerpc_bus_space pbus_tag = {
	_BUS_SPACE_LITTLE_ENDIAN | _BUS_SPACE_MEM_TYPE,
	0x00000000,
	0x80000000,
	0x8fffffff
};

/*
 * Probe for the peripheral bus.
 */
static int
pbus_match(device_t parent, cfdata_t cf, void *aux)
{
	struct pbus_attach_args *pba = aux;

	/* match only pbus devices */
	if (strcmp(pba->pb_name, cf->cf_name) != 0)
		return (0);

	return (1);
}

/*
 * Attach the peripheral bus.
 */
static void
pbus_attach(device_t parent, device_t self, void *aux)
{
	struct plb_attach_args *paa = aux;
	struct pbus_attach_args pba;
	int i;

	printf("\n");

	if (bus_space_init(&pbus_tag, "pbus", NULL, 0))
		panic("pbus_attach: can't init tag");

	for (i = 0; pbus_devs[i].name != NULL; i++) {
		pba.pb_name = pbus_devs[i].name;
		pba.pb_addr = pbus_devs[i].addr;
		pba.pb_irq = pbus_devs[i].irq;
		pba.pb_bt = &pbus_tag;
		pba.pb_dmat = paa->plb_dmat;

		const int locs[PBUSCF_NLOCS] = {
		    [PBUSCF_ADDR] = pba.pb_addr,
		    [PBUSCF_IRQ] = pba.pb_irq
		};

		(void) config_found_sm_loc(self, "pbus", locs, &pba, pbus_print,
		    config_stdsubmatch);
	}

}

static int
pbus_print(void *aux, const char *pnp)
{
	struct pbus_attach_args *pba = aux;

	if (pnp)
		printf("%s at %s", pba->pb_name, pnp);

	if (pba->pb_addr != PBUSCF_ADDR_DEFAULT)
		aprint_normal(" addr 0x%08lx", pba->pb_addr);
	if (pba->pb_irq != PBUSCF_IRQ_DEFAULT)
		aprint_normal(" irq %d", pba->pb_irq);

	return (UNCONF);
}
