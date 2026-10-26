// f1c  0x0058850f  size=87
double __cdecl sub_58850F(unsigned __int8 *a1)
{
  _BYTE v4[24]; // [esp+4h] [ebp-18h] BYREF

  while ( cbMultiByte <= 1 ? off_5E69C8[0][*a1] & 8 : sub_58C674(*a1, 8) )
    ++a1;
  sub_58E1B0(a1);
  return *(double *)(sub_58E12E(v4, a1) + 16);
}
