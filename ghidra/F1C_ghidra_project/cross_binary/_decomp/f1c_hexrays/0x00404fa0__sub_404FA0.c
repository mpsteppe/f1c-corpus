// f1c  0x00404fa0  size=24
char *__fastcall sub_404FA0(unsigned int a1)
{
  char *result; // eax

  result = 0;
  if ( a1 < 4 )
    return &aLowpassFilter[32 * a1];
  return result;
}
