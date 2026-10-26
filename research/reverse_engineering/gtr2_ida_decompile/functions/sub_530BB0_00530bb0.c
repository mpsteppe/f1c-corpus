int __thiscall sub_530BB0(int this, int a2, float a3)
{
  int v3; // edi
  int v5; // eax
  _BYTE *v6; // edx
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st6

  v3 = 0;
  if ( *(_DWORD *)dword_B640C8 != 6 )
    return 0;
  v5 = 0;
  v6 = (_BYTE *)(a2 + 3232);
  do
  {
    if ( !*v6 )
      return 1;
    ++v5;
    v6 += 296;
  }
  while ( v5 < 4 );
  if ( *(_DWORD *)(a2 + 18428) == 2 )
    return 2;
  if ( dword_B6FD6C == 3 )
    return sub_41FCD0() <= -1 ? 0 : 2;
  if ( *(_BYTE *)(this + 832) )
  {
    v7 = *(float *)(a2 + 20668) * 0.0099999998 / (double)*(int *)(this + 860) * a3;
    v8 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
    if ( v8 <= v7 )
      v3 = 1;
  }
  if ( *(_BYTE *)(this + 833) && v3 != 1 )
  {
    v9 = (1.0 - *(float *)(a2 + 20680) * 0.0099999998) / (double)*(int *)(this + 860) * a3 * *(float *)(this + 836);
    v10 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
    if ( v10 <= v9 )
      return 2;
  }
  return v3;
}
