int __thiscall sub_5944B0(int this)
{
  bool v1; // c0
  double v2; // st7
  int v3; // edx
  double v4; // st7
  double v5; // st7
  int result; // eax
  float i; // [esp+0h] [ebp-8h]
  float v8; // [esp+0h] [ebp-8h]
  float v9; // [esp+4h] [ebp-4h]

  if ( !*(_DWORD *)(this + 60) )
  {
    if ( *(float *)(this + 36) != 0.0 )
    {
      v1 = *(float *)(this + 40) < 0.60000002;
      goto LABEL_19;
    }
    return 1;
  }
  if ( *(_DWORD *)dword_B640C8 == 6 )
    v2 = dbl_FB1D18 + 5400.0;
  else
    v2 = dbl_FB1D18 + 3000.0;
  v3 = *(_DWORD *)(this + 60);
  v9 = v2;
  v4 = *(float *)(v3 + 8);
  for ( i = *(float *)(v3 + 8); v3; v3 = *(_DWORD *)(v3 + 12) )
  {
    if ( i < (double)*(float *)(v3 + 8) )
      i = *(float *)(v3 + 8);
    if ( v4 > *(float *)(v3 + 8) )
      v4 = *(float *)(v3 + 8);
    if ( *(float *)v3 > (double)v9 )
      break;
  }
  v5 = (v4 + i) * 0.5 + *(float *)(this + 492);
  v8 = v5;
  if ( v5 < 0.0 )
    return 1;
  if ( v8 <= 1.0 )
  {
    if ( v8 >= 0.61650002 )
    {
      v1 = v8 < 0.90999997;
LABEL_19:
      result = 2;
      if ( v1 )
        return result;
      return 3;
    }
    return 1;
  }
  return 3;
}
