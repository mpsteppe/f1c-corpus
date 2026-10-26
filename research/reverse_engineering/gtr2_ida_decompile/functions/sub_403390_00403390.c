int __stdcall sub_403390(float *a1, int a2, int a3, char a4)
{
  int v4; // edi
  int v5; // ebx
  int v7; // eax
  double v8; // st7
  int v9; // esi
  double v10; // st6
  double v11; // st5
  double v12; // st6
  double v13; // st5
  double v14; // st3
  double i; // st7
  double v16; // st7
  double v17; // st6
  double v18; // st5
  int v19; // esi
  double v20; // st6
  double v21; // st5
  double v22; // st3
  double v23; // st7
  double v24; // st7
  double v25; // st6
  double v26; // st5
  float v28; // [esp+14h] [ebp+Ch]
  float v29; // [esp+14h] [ebp+Ch]

  v4 = a2;
  v5 = a2;
  if ( !a2 )
    return sub_4031C0();
  if ( *(_DWORD *)(a2 + 304) != a3 )
  {
    v7 = *(_DWORD *)(a2 + 280);
    if ( v7 )
    {
      if ( *(_DWORD *)(v7 + 304) == a3 )
      {
        v4 = *(_DWORD *)(a2 + 280);
        v5 = v4;
      }
    }
  }
  v8 = *a1 - *(float *)(v4 + 152);
  v9 = *(_DWORD *)(v4 + 272);
  v10 = a1[1] - *(float *)(v4 + 156);
  v11 = a1[2] - *(float *)(v4 + 160);
  v28 = v11 * v11 + v10 * v10 + v8 * v8;
  if ( v9 )
  {
    v12 = a1[1] - *(float *)(v9 + 156);
    v13 = a1[2] - *(float *)(v9 + 160);
    v14 = *a1 - *(float *)(v9 + 152);
    for ( i = v13 * v13 + v12 * v12 + v14 * v14; i < v28; i = v18 * v18 + v17 * v17 + v16 * v16 )
    {
      if ( a3 != *(_DWORD *)(v9 + 304) )
        break;
      v4 = v9;
      v28 = i;
      v9 = *(_DWORD *)(v9 + 272);
      if ( !v9 )
        return sub_4031C0();
      v16 = *a1 - *(float *)(v9 + 152);
      v17 = a1[1] - *(float *)(v9 + 156);
      v18 = a1[2] - *(float *)(v9 + 160);
    }
  }
  v19 = *(_DWORD *)(v5 + 276);
  if ( v19 )
  {
    v20 = a1[1] - *(float *)(v19 + 156);
    v21 = a1[2] - *(float *)(v19 + 160);
    v22 = *a1 - *(float *)(v19 + 152);
    v23 = v21 * v21 + v20 * v20 + v22 * v22;
    if ( v23 < v28 )
    {
      do
      {
        v4 = v19;
        v29 = v23;
        v19 = *(_DWORD *)(v19 + 276);
        if ( !v19 )
          return sub_4031C0();
        v24 = *a1 - *(float *)(v19 + 152);
        v25 = a1[1] - *(float *)(v19 + 156);
        v26 = a1[2] - *(float *)(v19 + 160);
        v23 = v26 * v26 + v25 * v25 + v24 * v24;
      }
      while ( v23 < v29 );
    }
  }
  if ( a4 )
  {
    if ( !v4 )
      return sub_4031C0();
    if ( *(float *)(v4 + 176) * (*(float *)(v4 + 160) - a1[2]) + *(float *)(v4 + 168) * (*(float *)(v4 + 152) - *a1) < 0.0 )
      v4 = *(_DWORD *)(v4 + 276);
  }
  if ( v4 )
    return v4;
  return sub_4031C0();
}
