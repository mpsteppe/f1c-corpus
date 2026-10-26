double *__stdcall sub_5B2450(double *a1, int a2, int a3, int a4, unsigned int *a5, unsigned int a6)
{
  double *v6; // esi
  unsigned int v7; // ecx
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm5
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v21[17]; // [esp-124h] [ebp-128h] BYREF
  unsigned int v22; // [esp-10h] [ebp-14h]
  double *v23; // [esp-Ch] [ebp-10h]
  unsigned int v24; // [esp-8h] [ebp-Ch]

  v6 = a1;
  v7 = a6 > 0xA ? a6 & 0xFFFFFFFC : 0;
  v22 = a6 - v7;
  v24 = v7 >> 2;
  v23 = a1;
  if ( v7 >> 2 )
  {
    sub_5B139F(v21, a5);
    for ( ; v24; --v24 )
    {
      v8 = _mm_loadh_ps((const double *)(a3 + a4));
      v9 = _mm_loadh_ps((const double *)(3 * a4 + a3));
      v10 = _mm_shuffle_ps(v8, v9, 136);
      v11 = _mm_shuffle_ps(v8, v9, 221);
      v12 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v10, v21[0]), _mm_mul_ps(v11, v21[4])), v21[12]);
      v13 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v10, v21[1]), _mm_mul_ps(v11, v21[5])), v21[13]);
      v14 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v10, v21[2]), _mm_mul_ps(v11, v21[6])), v21[14]);
      v15 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v10, v21[3]), _mm_mul_ps(v11, v21[7])), v21[15]);
      v16 = _mm_unpacklo_ps(v12, v13);
      _mm_storel_ps(v6, v16);
      v17 = _mm_unpacklo_ps(v14, v15);
      _mm_storel_ps(v6 + 1, v17);
      _mm_storeh_ps((double *)((char *)v6 + a2), v16);
      _mm_storeh_ps((double *)((char *)v6 + a2 + 8), v17);
      v18 = _mm_unpackhi_ps(v12, v13);
      _mm_storel_ps((double *)((char *)v6 + 2 * a2), v18);
      v19 = _mm_unpackhi_ps(v14, v15);
      _mm_storel_ps((double *)((char *)v6 + 2 * a2 + 8), v19);
      _mm_storeh_ps((double *)((char *)v6 + 3 * a2), v18);
      _mm_storeh_ps((double *)((char *)v6 + 3 * a2 + 8), v19);
      a3 += 4 * a4;
      v6 = (double *)((char *)v6 + 4 * a2);
    }
  }
  if ( v22 )
  {
    v24 = v22;
    do
    {
      sub_5A9741();
      a3 += a4;
      v6 = (double *)((char *)v6 + a2);
      --v24;
    }
    while ( v24 );
  }
  return v23;
}
