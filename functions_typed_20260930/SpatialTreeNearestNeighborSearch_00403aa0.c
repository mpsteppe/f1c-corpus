int __thiscall sub_403AA0(_DWORD *this, float *a2, int a3, int a4, char a5)
{
  int v5; // edi
  int v6; // ebp
  int v9; // eax
  int v10; // edx
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // st6
  double v15; // st5
  double v16; // st3
  double i; // st7
  double v18; // st6
  double v19; // st5
  double v20; // st3
  int v21; // edx
  double v22; // st6
  double v23; // st5
  double v24; // st3
  double v25; // st7
  double v26; // st6
  double v27; // st5
  double v28; // st3
  float v29; // [esp+1Ch] [ebp+Ch]
  float v30; // [esp+1Ch] [ebp+Ch]

  v5 = a3;
  v6 = a3;
  if ( !a3 )
    return SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4);
  if ( *(_DWORD *)(a3 + 300) != a4 )
  {
    v9 = *(_DWORD *)(a3 + 276);
    if ( v9 )
    {
      if ( *(_DWORD *)(v9 + 300) == a4 )
      {
        v5 = *(_DWORD *)(a3 + 276);
        v6 = v5;
      }
    }
  }
  v10 = *(_DWORD *)(v5 + 268);
  v11 = *a2 - *(float *)(v5 + 148);
  v12 = a2[1] - *(float *)(v5 + 152);
  v13 = a2[2] - *(float *)(v5 + 156);
  v29 = v13 * v13 + v12 * v12 + v11 * v11;
  if ( v10 )
  {
    v14 = a2[1] - *(float *)(v10 + 152);
    v15 = a2[2] - *(float *)(v10 + 156);
    v16 = *a2 - *(float *)(v10 + 148);
    for ( i = v15 * v15 + v14 * v14 + v16 * v16; i < v29; i = v19 * v19 + v18 * v18 + v20 * v20 )
    {
      if ( a4 != *(_DWORD *)(v10 + 300) )
        break;
      v5 = v10;
      v29 = i;
      v10 = *(_DWORD *)(v10 + 268);
      if ( !v10 )
        return SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4);
      v18 = a2[1] - *(float *)(v10 + 152);
      v19 = a2[2] - *(float *)(v10 + 156);
      v20 = *a2 - *(float *)(v10 + 148);
    }
  }
  v21 = *(_DWORD *)(v6 + 272);
  if ( v21 )
  {
    v22 = a2[1] - *(float *)(v21 + 152);
    v23 = a2[2] - *(float *)(v21 + 156);
    v24 = *a2 - *(float *)(v21 + 148);
    v25 = v23 * v23 + v22 * v22 + v24 * v24;
    if ( v25 < v29 )
    {
      do
      {
        v5 = v21;
        v30 = v25;
        v21 = *(_DWORD *)(v21 + 272);
        if ( !v21 )
          return SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4);
        v26 = a2[1] - *(float *)(v21 + 152);
        v27 = a2[2] - *(float *)(v21 + 156);
        v28 = *a2 - *(float *)(v21 + 148);
        v25 = v27 * v27 + v26 * v26 + v28 * v28;
      }
      while ( v25 < v30 );
    }
  }
  if ( a5 )
  {
    if ( !v5 )
      return SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4);
    if ( *(float *)(v5 + 172) * (*(float *)(v5 + 156) - a2[2]) + *(float *)(v5 + 164) * (*(float *)(v5 + 148) - *a2) < 0.0 )
      v5 = *(_DWORD *)(v5 + 272);
  }
  if ( !v5 )
    return SpatialNearestNeighborQueryWithPlaneTest(this, a2, a4);
  return v5;
}

