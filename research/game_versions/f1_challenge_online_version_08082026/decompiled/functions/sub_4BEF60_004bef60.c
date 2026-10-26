int __thiscall sub_4BEF60(int this, int a2, float a3)
{
  int v3; // edi
  int v5; // edx
  int v6; // eax
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st6

  v3 = 0;
  if ( dword_7C56A4 != 7 )
    return 0;
  v5 = 0;
  v6 = a2 + 2100;
  do
  {
    if ( !*(_DWORD *)v6 || !*(_BYTE *)(v6 + 64) )
      return 1;
    ++v5;
    v6 += 296;
  }
  while ( v5 < 4 );
  if ( *(_DWORD *)(a2 + 15724) == 2 )
    return 2;
  if ( dword_7CEA5C == 3 )
    return sub_42AEB0((_DWORD *)a2, *(_DWORD *)(a2 + 16444)) <= -1 ? 0 : 2;
  if ( *(_BYTE *)(this + 832) )
  {
    v7 = *(float *)(a2 + 17616) * 0.0099999998 / (double)*(int *)(this + 860) * a3;
    v8 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
    if ( v8 <= v7 )
      v3 = 1;
  }
  if ( *(_BYTE *)(this + 833) && v3 != 1 )
  {
    v9 = (1.0 - *(float *)(a2 + 17628) * 0.0099999998) / (double)*(int *)(this + 860) * a3 * *(float *)(this + 836);
    v10 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
    if ( v10 <= v9 )
      return 2;
  }
  return v3;
}
