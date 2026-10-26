bool __thiscall sub_5217F0(float *this, float *a2, float a3, float a4, float a5, float *a6)
{
  float *v8; // eax
  double v9; // st7
  bool v10; // dl
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  double v19; // st5
  double v20; // st4
  double v21; // st5
  double v22; // st4
  long double v23; // st5
  float v24[3]; // [esp+10h] [ebp-Ch] BYREF
  float v25; // [esp+2Ch] [ebp+10h]

  if ( fabs(this[5] - a5) >= 0.1 || fabs(this[4] - a4) >= 0.1 || fabs(this[3] - a3) >= 0.05235987755982988 )
    return 1;
  v8 = sub_401290(a2, this, v24);
  v9 = v8[2] * v8[2] + v8[1] * v8[1] + *v8 * *v8;
  if ( v9 >= 2500.0 )
    return 1;
  if ( !a6 || v9 < 1.0 )
    return 0;
  v10 = 1;
  if ( *(_DWORD *)(dword_91E084 + 3168) )
  {
    if ( *(_BYTE *)(dword_91E084 + 3232) )
    {
      v11 = *(_DWORD *)(dword_91E084 + 16400);
      if ( v11 )
      {
        v12 = *(_DWORD *)(v11 + 84);
        if ( v12 )
          v10 = *(_BYTE *)(v12 + 92) != 0;
      }
    }
  }
  if ( *(_DWORD *)(dword_91E084 + 3464) )
  {
    if ( *(_BYTE *)(dword_91E084 + 3528) )
    {
      v13 = *(_DWORD *)(dword_91E084 + 16652);
      if ( v13 )
      {
        v14 = *(_DWORD *)(v13 + 84);
        if ( v14 )
        {
          if ( !*(_BYTE *)(v14 + 92) )
            v10 = 0;
        }
      }
    }
  }
  if ( *(_DWORD *)(dword_91E084 + 3760) )
  {
    if ( *(_BYTE *)(dword_91E084 + 3824) )
    {
      v15 = *(_DWORD *)(dword_91E084 + 16904);
      if ( v15 )
      {
        v16 = *(_DWORD *)(v15 + 84);
        if ( v16 )
        {
          if ( !*(_BYTE *)(v16 + 92) )
            v10 = 0;
        }
      }
    }
  }
  if ( *(_DWORD *)(dword_91E084 + 4056) )
  {
    if ( *(_BYTE *)(dword_91E084 + 4120) )
    {
      v17 = *(_DWORD *)(dword_91E084 + 17156);
      if ( v17 )
      {
        v18 = *(_DWORD *)(v17 + 84);
        if ( v18 )
        {
          if ( !*(_BYTE *)(v18 + 92) )
            return 0;
        }
      }
    }
  }
  if ( !v10 )
    return 0;
  v19 = this[2] - a6[2];
  v20 = *this - *a6;
  v25 = sqrt(v19 * v19 + v20 * v20);
  if ( v25 == 0.0 )
    return 0;
  v21 = a2[2] - a6[2];
  v22 = *a2 - *a6;
  v23 = sqrt(v21 * v21 + v22 * v22);
  return v23 != 0.0 && fabs((this[1] - a6[1]) / v25 - (a2[1] - a6[1]) / v23) >= 0.001745329278001762;
}
