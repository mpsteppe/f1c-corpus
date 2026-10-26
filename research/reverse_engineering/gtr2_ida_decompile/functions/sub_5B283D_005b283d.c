double *__stdcall sub_5B283D(double *a1, int a2, int a3, int a4, unsigned int *a5, unsigned int a6)
{
  double *v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // esi
  int v10; // esi
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v28[16]; // [esp-134h] [ebp-138h] BYREF
  __m128 v29; // [esp-34h] [ebp-38h]
  __m128 v30; // [esp-24h] [ebp-28h]
  unsigned int v31; // [esp-10h] [ebp-14h]
  double *v32; // [esp-Ch] [ebp-10h]
  unsigned int v33; // [esp-8h] [ebp-Ch]

  v6 = a1;
  v7 = a6 > 0xA ? a6 & 0xFFFFFFFC : 0;
  v8 = a6 - v7;
  v9 = v7 >> 2;
  v31 = v8;
  v32 = a1;
  if ( v9 )
  {
    sub_5B139F(v28, a5);
    v33 = v9;
    v10 = a3;
    do
    {
      v11 = _mm_loadh_ps((const double *)(v10 + a4));
      v12 = _mm_loadh_ps((const double *)(a4 + v10 + 8));
      v13 = _mm_loadh_ps((const double *)(3 * a4 + v10));
      v14 = _mm_shuffle_ps(v11, v13, 136);
      v15 = _mm_shuffle_ps(v11, v13, 221);
      v16 = _mm_loadh_ps((const double *)(3 * a4 + v10 + 8));
      v17 = _mm_shuffle_ps(v12, v16, 221);
      v18 = _mm_shuffle_ps(v12, v16, 136);
      v29 = v17;
      v19 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v14, v28[0]), _mm_mul_ps(v15, v28[4])), _mm_mul_ps(v18, v28[8])),
              _mm_mul_ps(v17, v28[12]));
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v14, v28[1]), _mm_mul_ps(v15, v28[5])), _mm_mul_ps(v18, v28[9])),
              _mm_mul_ps(v17, v28[13]));
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v14, v28[2]), _mm_mul_ps(v15, v28[6])), _mm_mul_ps(v18, v28[10])),
              _mm_mul_ps(v17, v28[14]));
      v21 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v14, v28[3]), _mm_mul_ps(v15, v28[7])), _mm_mul_ps(v18, v28[11]));
      v22 = _mm_unpacklo_ps(v19, v30);
      v23 = _mm_unpackhi_ps(v19, v30);
      v24 = _mm_add_ps(v21, _mm_mul_ps(v29, v28[15]));
      _mm_storel_ps(v6, v22);
      v25 = _mm_unpacklo_ps(v20, v24);
      _mm_storel_ps(v6 + 1, v25);
      _mm_storeh_ps((double *)((char *)v6 + a2), v22);
      _mm_storeh_ps((double *)((char *)v6 + a2 + 8), v25);
      v26 = _mm_unpackhi_ps(v20, v24);
      _mm_storel_ps((double *)((char *)v6 + 2 * a2), v23);
      _mm_storel_ps((double *)((char *)v6 + 2 * a2 + 8), v26);
      _mm_storeh_ps((double *)((char *)v6 + 3 * a2), v23);
      _mm_storeh_ps((double *)((char *)v6 + 3 * a2 + 8), v26);
      v10 += 4 * a4;
      v6 = (double *)((char *)v6 + 4 * a2);
      --v33;
    }
    while ( v33 );
  }
  else
  {
    v10 = a3;
  }
  if ( v31 )
  {
    v33 = v31;
    do
    {
      sub_5B2FBC((int)v6, v10, (int)a5);
      v10 += a4;
      v6 = (double *)((char *)v6 + a2);
      --v33;
    }
    while ( v33 );
  }
  return v32;
}
