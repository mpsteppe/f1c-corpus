int __stdcall sub_5B2A3D(int a1, int a2, int a3, int a4, unsigned int *a5, unsigned int a6)
{
  int v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // esi
  int v10; // esi
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm6
  __m128 v19; // xmm0
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm2
  __m128 v26[16]; // [esp-124h] [ebp-128h] BYREF
  __m128 v27; // [esp-24h] [ebp-28h]
  unsigned int v28; // [esp-10h] [ebp-14h]
  int v29; // [esp-Ch] [ebp-10h]
  unsigned int v30; // [esp-8h] [ebp-Ch]

  v6 = a1;
  v7 = a6 > 0xA ? a6 & 0xFFFFFFFC : 0;
  v8 = a6 - v7;
  v9 = v7 >> 2;
  v28 = v8;
  v29 = a1;
  if ( v9 )
  {
    sub_5B139F(v26, a5);
    v30 = v9;
    v10 = a3;
    do
    {
      v11 = _mm_loadh_ps((const double *)(v10 + a4));
      v12 = _mm_loadh_ps((const double *)(3 * a4 + v10));
      v13 = _mm_shuffle_ps(v11, v12, 221);
      v14 = _mm_shuffle_ps(v11, v12, 136);
      v15 = v13;
      v16 = _mm_shuffle_ps(
              _mm_movelh_ps((__m128)*(unsigned int *)(v10 + 8), (__m128)*(unsigned int *)(a4 + v10 + 8)),
              _mm_movelh_ps((__m128)*(unsigned int *)(v10 + 2 * a4 + 8), (__m128)*(unsigned int *)(3 * a4 + v10 + 8)),
              136);
      v17 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v14, v26[0]), _mm_mul_ps(v15, v26[4])), _mm_mul_ps(v16, v26[8]));
      v18 = v14;
      v19 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v14, v26[2]), _mm_mul_ps(v15, v26[6])), _mm_mul_ps(v16, v26[10]));
      v20 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v18, v26[1]), _mm_mul_ps(v15, v26[5])), _mm_mul_ps(v16, v26[9]));
      v21 = _mm_unpacklo_ps(v17, v20);
      _mm_storel_ps((double *)v6, v21);
      _mm_storeh_ps((double *)(v6 + a2), v21);
      v22 = _mm_unpacklo_ps(v19, v27);
      v23 = _mm_unpackhi_ps(v19, v27);
      *(_DWORD *)(v6 + 8) = v22.m128_i32[0];
      *(_DWORD *)(a2 + v6 + 8) = _mm_movehl_ps(v22, v22).m128_u32[0];
      v24 = _mm_unpackhi_ps(v17, v20);
      _mm_storel_ps((double *)(v6 + 2 * a2), v24);
      _mm_storeh_ps((double *)(3 * a2 + v6), v24);
      *(_DWORD *)(v6 + 2 * a2 + 8) = v23.m128_i32[0];
      *(_DWORD *)(3 * a2 + v6 + 8) = _mm_movehl_ps(v23, v23).m128_u32[0];
      v10 += 4 * a4;
      v6 += 4 * a2;
      --v30;
    }
    while ( v30 );
  }
  else
  {
    v10 = a3;
  }
  if ( v28 )
  {
    v30 = v28;
    do
    {
      sub_5B1118(v6, v10, (int)a5);
      v10 += a4;
      v6 += a2;
      --v30;
    }
    while ( v30 );
  }
  return v29;
}
