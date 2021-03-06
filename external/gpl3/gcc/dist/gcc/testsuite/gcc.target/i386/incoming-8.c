/* PR target/40838 */
/* { dg-do compile { target { { ! *-*-darwin* } && ilp32 } } } */
/* { dg-options "-w -mstackrealign -O3 -msse2 -mpreferred-stack-boundary=4" } */
/* { dg-require-effective-target sse2 } */

float
foo (float f)
{
  float array[128];
  float x;
  int i;
  for (i = 0; i < sizeof(array) / sizeof(*array); i++)
    array[i] = f;
  for (i = 0; i < sizeof(array) / sizeof(*array); i++)
    x += array[i];
  return x;
}

/* { dg-final { scan-assembler "andl\[\\t \]*\\$-16,\[\\t \]*%esp" } } */
