int __thiscall sub_5943E0(int this)
{
  int v1; // edx
  bool v2; // c0
  float *v3; // esi
  double v4; // st7
  int v5; // edx
  double v6; // st7
  double v7; // st7
  int result; // eax
  float v9; // [esp+0h] [ebp-4h]

  v1 = *(_DWORD *)(this + 60);
  if ( !v1 )
  {
    if ( *(float *)(this + 36) != 0.0 )
    {
      v2 = *(float *)(this + 40) < 0.60000002;
      goto LABEL_16;
    }
    return 1;
  }
  v9 = dbl_FB1D18;
  if ( dbl_FB1D18 > *(float *)v1 && (v3 = *(float **)(v1 + 12)) != 0 )
  {
    if ( v9 < (double)*v3 )
    {
      v5 = *(_DWORD *)(this + 60);
      v6 = **(float **)(v5 + 12) - *(float *)v5;
      if ( v6 <= 0.0 )
        v7 = 0.0;
      else
        v7 = (v9 - *(float *)v5) / v6;
      v4 = (1.0 - v7) * *(float *)(*(_DWORD *)(this + 60) + 8)
         + v7 * *(float *)(*(_DWORD *)(*(_DWORD *)(this + 60) + 12) + 8);
    }
    else
    {
      v4 = v3[2];
    }
  }
  else
  {
    v4 = *(float *)(v1 + 8);
  }
  if ( v4 < 0.61650002 )
    return 1;
  v2 = v4 < 0.90999997;
LABEL_16:
  result = 2;
  if ( !v2 )
    return 3;
  return result;
}
