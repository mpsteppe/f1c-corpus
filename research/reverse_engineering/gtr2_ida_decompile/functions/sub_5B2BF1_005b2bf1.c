int __stdcall sub_5B2BF1(int a1, int a2, int a3, int a4, unsigned int *a5, unsigned int a6)
{
  int v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // esi
  int v10; // esi
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm0
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm4
  __m128 v19; // xmm6
  __m128 v20; // xmm7
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // xmm5
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm0
  __m128 v30[17]; // [esp-124h] [ebp-128h] BYREF
  unsigned int v31; // [esp-10h] [ebp-14h]
  int v32; // [esp-Ch] [ebp-10h]
  unsigned int v33; // [esp-8h] [ebp-Ch]

  v6 = a1;
  v7 = a6 > 0xA ? a6 & 0xFFFFFFFC : 0;
  v8 = a6 - v7;
  v9 = v7 >> 2;
  v31 = v8;
  v32 = a1;
  if ( v9 )
  {
    sub_5B139F(v30, a5);
    v33 = v9;
    v10 = a3;
    do
    {
      v11 = _mm_loadh_ps((const double *)(v10 + a4));
      v12 = _mm_loadh_ps((const double *)(3 * a4 + v10));
      v13 = _mm_shuffle_ps(v11, v12, 136);
      v14 = _mm_shuffle_ps(v11, v12, 221);
      v15 = _mm_shuffle_ps(
              _mm_movelh_ps((__m128)*(unsigned int *)(v10 + 8), (__m128)*(unsigned int *)(a4 + v10 + 8)),
              _mm_movelh_ps((__m128)*(unsigned int *)(v10 + 2 * a4 + 8), (__m128)*(unsigned int *)(3 * a4 + v10 + 8)),
              136);
      v16 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v13, v30[3]), _mm_mul_ps(v14, v30[7])), _mm_mul_ps(v15, v30[11])),
              v30[15]);
      v17 = _mm_rcp_ps(v16);
      v18 = _mm_sub_ps(_mm_add_ps(v17, v17), _mm_mul_ps(_mm_mul_ps(v17, v16), v17));
      v19 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v13, v30[0]), _mm_mul_ps(v14, v30[4])), _mm_mul_ps(v15, v30[8]));
      v20 = v13;
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v13, v30[2]), _mm_mul_ps(v14, v30[6])), _mm_mul_ps(v15, v30[10])),
              v30[14]);
      v22 = _mm_mul_ps(_mm_add_ps(v19, v30[12]), v18);
      v23 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(v20, v30[1]), _mm_mul_ps(v14, v30[5])), _mm_mul_ps(v15, v30[9])),
                v30[13]),
              v18);
      v24 = _mm_unpacklo_ps(v22, v23);
      _mm_storel_ps((double *)v6, v24);
      _mm_storeh_ps((double *)(v6 + a2), v24);
      v25 = _mm_mul_ps(v21, v18);
      v26 = _mm_unpacklo_ps(v25, v18);
      *(_DWORD *)(v6 + 8) = v26.m128_i32[0];
      *(_DWORD *)(a2 + v6 + 8) = _mm_movehl_ps(v26, v26).m128_u32[0];
      v27 = _mm_unpackhi_ps(v22, v23);
      v28 = _mm_unpackhi_ps(v25, v18);
      _mm_storel_ps((double *)(v6 + 2 * a2), v27);
      _mm_storeh_ps((double *)(3 * a2 + v6), v27);
      *(_DWORD *)(v6 + 2 * a2 + 8) = v28.m128_i32[0];
      *(_DWORD *)(3 * a2 + v6 + 8) = _mm_movehl_ps(v28, v28).m128_u32[0];
      v10 += 4 * a4;
      v6 += 4 * a2;
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
      sub_5B12AB(v6, v10, (int)a5);
      v10 += a4;
      v6 += a2;
      --v33;
    }
    while ( v33 );
  }
  return v32;
}
