double *__stdcall sub_5B1858(double *a1, int a2, int a3, int a4, unsigned int *a5, unsigned int a6)
{
  double *v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // esi
  int v10; // esi
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v23[17]; // [esp-124h] [ebp-128h] BYREF
  unsigned int v24; // [esp-10h] [ebp-14h]
  double *v25; // [esp-Ch] [ebp-10h]
  unsigned int v26; // [esp-8h] [ebp-Ch]

  v6 = a1;
  v7 = a6 > 0xC ? a6 & 0xFFFFFFFC : 0;
  v8 = a6 - v7;
  v9 = v7 >> 2;
  v24 = v8;
  v25 = a1;
  if ( v9 )
  {
    sub_5B139F(v23, a5);
    v26 = v9;
    v10 = a3;
    do
    {
      v11 = _mm_loadh_ps((const double *)(v10 + a4));
      v12 = _mm_loadh_ps((const double *)(3 * a4 + v10));
      v13 = _mm_shuffle_ps(v11, v12, 136);
      v14 = _mm_shuffle_ps(v11, v12, 221);
      v15 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v13, v23[3]), _mm_mul_ps(v14, v23[7])), v23[15]);
      v16 = _mm_rcp_ps(v15);
      v17 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps(_mm_mul_ps(v16, v15), v16));
      v18 = _mm_mul_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v13, v23[0]), _mm_mul_ps(v14, v23[4])), v23[12]), v17);
      v19 = _mm_mul_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v13, v23[1]), _mm_mul_ps(v14, v23[5])), v23[13]), v17);
      v20 = _mm_unpacklo_ps(v18, v19);
      _mm_storel_ps(v6, v20);
      _mm_storeh_ps((double *)((char *)v6 + a2), v20);
      v21 = _mm_unpackhi_ps(v18, v19);
      _mm_storel_ps((double *)((char *)v6 + 2 * a2), v21);
      _mm_storeh_ps((double *)((char *)v6 + 3 * a2), v21);
      v10 += 4 * a4;
      v6 = (double *)((char *)v6 + 4 * a2);
      --v26;
    }
    while ( v26 );
  }
  else
  {
    v10 = a3;
  }
  if ( v24 )
  {
    v26 = v24;
    do
    {
      sub_5A976D();
      v10 += a4;
      v6 = (double *)((char *)v6 + a2);
      --v26;
    }
    while ( v26 );
  }
  return v25;
}
