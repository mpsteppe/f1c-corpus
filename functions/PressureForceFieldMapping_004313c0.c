int __thiscall sub_4313C0(int this)
{
  _DWORD *v2; // edi
  int v3; // ebx
  int v4; // ebp
  int v5; // edi
  int v6; // ebx
  int v7; // edi
  double v8; // st7
  double v9; // st7
  double v10; // st6
  double v11; // st7
  int i; // eax
  int v13; // ebx
  int v14; // ebp
  double v15; // st7
  double v16; // st7
  double v17; // st7
  int v18; // ebp
  int *v19; // edi
  int result; // eax
  int v21; // ebx
  long double v22; // st7
  int v23; // ecx
  int v24; // ecx
  double v25; // [esp+18h] [ebp-388h]
  double v26; // [esp+18h] [ebp-388h]
  double v27; // [esp+18h] [ebp-388h]
  double v28; // [esp+18h] [ebp-388h]
  int v29; // [esp+24h] [ebp-37Ch]
  double *v30; // [esp+24h] [ebp-37Ch]
  double v31; // [esp+28h] [ebp-378h]
  int v32; // [esp+28h] [ebp-378h]
  double v33[44]; // [esp+30h] [ebp-370h]
  double v34[66]; // [esp+190h] [ebp-210h] BYREF

  v25 = (*(float *)(this + 7340) - 0.5) * 0.5 + *(float *)(this + 7336);
  PositionIndexClamp((_DWORD *)(this + 4720), v25);
  PositionIndexClamp((_DWORD *)(this + 3568), v25);
  PositionIndexClamp((_DWORD *)(this + 3632), v25);
  PositionIndexClamp((_DWORD *)(this + 4784), (0.5 - *(float *)(this + 7340)) * 0.5 + *(float *)(this + 7336));
  PositionIndexClamp((_DWORD *)(this + 4976), *(float *)(this + 7340));
  PositionIndexClamp((_DWORD *)(this + 3312), (1.0 - *(float *)(this + 7340) + *(float *)(this + 7344)) * 0.5);
  PositionIndexClamp((_DWORD *)(this + 3376), (*(float *)(this + 7344) + *(float *)(this + 7340)) * 0.5);
  v2 = (_DWORD *)(this + 496);
  v3 = 4;
  do
  {
    PositionIndexClamp(v2 - 16, *(float *)(this + 7344));
    PositionIndexClamp(v2, *(float *)(this + 7344));
    PositionIndexClamp(v2 + 16, *(float *)(this + 7344));
    PositionIndexClamp(v2 + 32, *(float *)(this + 7344));
    PositionIndexClamp(v2 + 48, *(float *)(this + 7344));
    v2 += 176;
    --v3;
  }
  while ( v3 );
  v4 = 44;
  *(_DWORD *)(this + 5700) = *(_DWORD *)(this + 5704);
  v29 = 44;
  v5 = 44;
  v6 = this + 5828;
  do
  {
    *(_DWORD *)v6 = *(_DWORD *)(v6 + 4);
    v34[v5 + 11] = SessionStateIndexedLookup((int *)this, v5);
    if ( *(_BYTE *)(v6 + 8) )
    {
      v29 = v5;
      v4 = v5;
    }
    ++v5;
    v6 += 64;
  }
  while ( v5 <= 50 );
  v7 = 0;
  *(_DWORD *)(this + 5700) = 0;
  *(_DWORD *)(this + 5828) = 0;
  v8 = SessionStateIndexedLookup((int *)this, 44);
  *(_DWORD *)(this + 5700) = *(_DWORD *)(this + 5696) - 1;
  *(_DWORD *)((v4 << 6) + this + 3012) = *(_DWORD *)(((v4 + 47) << 6) + this) - 1;
  if ( *(float *)(this + 7348) < 0.5 )
  {
    v10 = v8;
    v11 = *(float *)(this + 7348) + *(float *)(this + 7348);
    v9 = v11 + v10 / v34[55] * (1.0 - v11);
  }
  else
  {
    v26 = *(float *)(this + 7348) + *(float *)(this + 7348) - 1.0;
    v9 = SessionStateIndexedLookup((int *)this, v4) / v34[v4 + 11] * v26 + 1.0 - v26;
  }
  for ( i = 0; i <= 6; v33[i + 43] = v9 * v34[i + 54] )
    ++i;
  v13 = *(_DWORD *)(this + 5704);
  v27 = 1.797693134862316e308;
  if ( *(int *)(this + 5696) > 0 )
  {
    v14 = -v13;
    do
    {
      v31 = 0.0;
      *(_DWORD *)(this + 5700) = v7;
      v15 = SessionStateIndexedLookup((int *)this, 44);
      if ( v15 < v34[0] )
        v31 = v34[0] - v15;
      v16 = SessionStateIndexedLookup((int *)this, v29);
      if ( v16 > v33[v29] )
      {
        v17 = v16 - v33[v29];
        if ( v31 < v17 )
          v31 = v17;
      }
      if ( v31 == v27 )
      {
        if ( (int)abs32(v14) < (int)abs32(v13 - *(_DWORD *)(this + 5704)) )
        {
          v27 = v31;
LABEL_24:
          v13 = v7;
        }
      }
      else if ( v31 < v27 )
      {
        v27 = v31;
        goto LABEL_24;
      }
      ++v7;
      ++v14;
    }
    while ( v7 < *(_DWORD *)(this + 5696) );
  }
  *(_DWORD *)(this + 5700) = v13;
  v18 = 44;
  v30 = v34;
  v19 = (int *)(this + 5824);
  do
  {
    result = 0;
    v21 = 0;
    v32 = 0;
    v28 = 1.797693134862316e308;
    if ( *v19 > 0 )
    {
      do
      {
        v19[1] = v21;
        v22 = fabs(SessionStateIndexedLookup((int *)this, v18) - *v30);
        if ( v22 < v28 )
        {
          v28 = v22;
          v32 = v21;
        }
        ++v21;
      }
      while ( v21 < *v19 );
      result = v32;
    }
    v19[1] = result;
    if ( v18 > 44 )
    {
      v23 = *(v19 - 15);
      if ( v23 >= result )
      {
        result = *v19;
        v24 = v23 + 1;
        if ( v24 >= *v19 )
          v19[1] = --result;
        else
          v19[1] = v24;
      }
    }
    ++v18;
    v19 += 16;
    ++v30;
  }
  while ( v18 <= 50 );
  return result;
}
