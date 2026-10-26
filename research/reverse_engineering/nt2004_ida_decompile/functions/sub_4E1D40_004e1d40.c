int __thiscall sub_4E1D40(int this, int a2, float a3)
{
  int v3; // edx
  double v5; // st7
  double v6; // st7
  double v7; // st6
  double v8; // st7
  double v9; // st7
  double v10; // st6

  v3 = 0;
  if ( dword_75CBB0 != 7 )
    return 0;
  if ( *(_DWORD *)dword_766B6C == 3 )
    return sub_428090((_DWORD *)a2, *(_DWORD *)(a2 + 20848)) <= -1 ? 0 : 2;
  if ( *(_BYTE *)(this + 384) )
  {
    v5 = *(_BYTE *)(this + 387) ? 0.050000001 : *(float *)(a2 + 24012) * 0.0099999998;
    v6 = v5 / (double)*(int *)(this + 416) * a3;
    v7 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
    if ( v7 <= v6 )
      v3 = 1;
  }
  if ( *(_BYTE *)(this + 385) && v3 != 1 )
  {
    if ( *(_BYTE *)(this + 387) )
      v8 = 0.050000001;
    else
      v8 = 1.0 - *(float *)(a2 + 23972) * 0.0099999998;
    v9 = v8 / (double)*(int *)(this + 416) * a3 * *(float *)(this + 388);
    v10 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
    if ( v10 <= v9 )
      return 2;
  }
  return v3;
}
