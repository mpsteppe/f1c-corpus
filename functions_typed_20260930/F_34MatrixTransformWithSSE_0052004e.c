int __stdcall sub_52004E(int a1, int a2, int a3)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm2
  __m128 v6; // xmm2
  __m128 v7; // xmm0
  __m128 v9; // xmm6
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  __m128 v13; // xmm4

  if ( (a3 & 0xF) != 0 )
  {
    v9 = _mm_loadl_ps((const double *)a2);
    v10 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 8)), _mm_shuffle_ps(v9, v9, 0)),
              _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 24)), _mm_shuffle_ps(v9, v9, 85))),
            _mm_add_ps(
              _mm_mul_ps(
                _mm_loadh_ps((const double *)(a3 + 40)),
                _mm_shuffle_ps((__m128)*(unsigned int *)(a2 + 8), (__m128)*(unsigned int *)(a2 + 8), 0)),
              _mm_loadh_ps((const double *)(a3 + 56))));
    v11 = _mm_rcp_ps(v10);
    v12 = _mm_sub_ps(_mm_add_ps(v11, v11), _mm_mul_ps(_mm_mul_ps(v11, v10), v11));
    v13 = _mm_mul_ps(v10, _mm_shuffle_ps(v12, v12, 255));
    _mm_storel_ps((double *)a1, v13);
    *(_DWORD *)(a1 + 8) = _mm_movehl_ps(v13, v13).m128_u32[0];
  }
  else
  {
    v3 = _mm_loadl_ps((const double *)a2);
    v4 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), *(__m128 *)a3),
             _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), *(__m128 *)(a3 + 16))),
           _mm_add_ps(
             _mm_mul_ps(
               _mm_shuffle_ps((__m128)*(unsigned int *)(a2 + 8), (__m128)*(unsigned int *)(a2 + 8), 0),
               *(__m128 *)(a3 + 32)),
             *(__m128 *)(a3 + 48)));
    v5 = _mm_rcp_ps(v4);
    v6 = _mm_sub_ps(_mm_add_ps(v5, v5), _mm_mul_ps(_mm_mul_ps(v5, v4), v5));
    v7 = _mm_mul_ps(v4, _mm_shuffle_ps(v6, v6, 255));
    _mm_storel_ps((double *)a1, v7);
    *(_DWORD *)(a1 + 8) = _mm_movehl_ps(v7, v7).m128_u32[0];
  }
  return a1;
}

