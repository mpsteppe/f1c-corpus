// f1c  0x00591cf3  size=18
double __cdecl sub_591CF3(double a1)
{
  double result; // st7

  _ST7 = a1;
  __asm { frndint }
  return result;
}
