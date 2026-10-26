double *__stdcall sub_5B19B4(double *a1, int a2, int a3, int a4, unsigned int *a5, unsigned int a6)
{
  double *v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // esi
  int v10; // esi
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v21[17]; // [esp-124h] [ebp-128h] BYREF
  unsigned int v22; // [esp-10h] [ebp-14h]
  double *v23; // [esp-Ch] [ebp-10h]
  unsigned int v24; // [esp-8h] [ebp-Ch]

  v6 = a1;
  v7 = a6 > 0xC ? a6 & 0xFFFFFFFC : 0;
  v8 = a6 - v7;
  v9 = v7 >> 2;
  v22 = v8;
  v23 = a1;
  if ( v9 )
  {
    sub_5B139F(v21, a5);
    v24 = v9;
    v10 = a3;
    do
    {
      v11 = _mm_loadh_ps((const double *)(v10 + a4));
      v12 = _mm_loadh_ps((const double *)(3 * a4 + v10));
      v13 = _mm_shuffle_ps(v11, v12, 221);
      v14 = _mm_shuffle_ps(v11, v12, 136);
      v15 = _mm_mul_ps(v14, v21[0]);
      v16 = _mm_add_ps(_mm_mul_ps(v14, v21[1]), _mm_mul_ps(v13, v21[5]));
      v17 = _mm_add_ps(v15, _mm_mul_ps(v13, v21[4]));
      v18 = _mm_unpacklo_ps(v17, v16);
      _mm_storel_ps(v6, v18);
      _mm_storeh_ps((double *)((char *)v6 + a2), v18);
      v19 = _mm_unpackhi_ps(v17, v16);
      _mm_storel_ps((double *)((char *)v6 + 2 * a2), v19);
      _mm_storeh_ps((double *)((char *)v6 + 3 * a2), v19);
      v10 += 4 * a4;
      v6 = (double *)((char *)v6 + 4 * a2);
      --v24;
    }
    while ( v24 );
  }
  else
  {
    v10 = a3;
  }
  if ( v22 )
  {
    v24 = v22;
    do
    {
      sub_5A9799();
      v10 += a4;
      v6 = (double *)((char *)v6 + a2);
      --v24;
    }
    while ( v24 );
  }
  return v23;
}
