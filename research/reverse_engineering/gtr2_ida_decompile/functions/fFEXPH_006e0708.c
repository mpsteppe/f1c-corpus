double __usercall fFEXPH@<st0>(char a1@<ch>, int a2@<ebp>, double a3@<st2>, double a4@<st0>)
{
  double v5; // st6
  long double v6; // st7
  char v7; // dl

  v5 = 1.442695040888963407;
  v6 = a4 * 1.442695040888963407;
  _ffexpm1(a1, a2);
  if ( (*(_BYTE *)(a2 - 159) & 1) != 0 )
  {
    ExpHypCopyInv();
    v5 = a3;
  }
  if ( (v7 & 0x40) == 0 )
    return __FSCALE__(v5 + 1.0, v6);
  return v5;
}
