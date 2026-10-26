double __stdcall sub_5B080C(int a1)
{
  __m128 v1; // xmm7
  __m128 v2; // xmm1
  __m128 v3; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm0
  __m128 v9; // xmm4
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  __m128 v15; // xmm0

  if ( (a1 & 0xF) != 0 )
  {
    v2 = _mm_loadh_ps((const double *)(a1 + 24));
    v1 = _mm_loadh_ps((const double *)(a1 + 8));
    v3 = _mm_loadh_ps((const double *)(a1 + 40));
    v4 = _mm_loadh_ps((const double *)(a1 + 56));
  }
  else
  {
    v1 = *(__m128 *)a1;
    v2 = *(__m128 *)(a1 + 16);
    v3 = *(__m128 *)(a1 + 32);
    v4 = *(__m128 *)(a1 + 48);
  }
  v5 = _mm_shuffle_ps(v3, v3, 57);
  v6 = _mm_mul_ps(v4, v5);
  v7 = _mm_shuffle_ps(v4, v4, 78);
  v8 = _mm_shuffle_ps(v7, v7, 57);
  v9 = _mm_mul_ps(v7, v5);
  v10 = _mm_mul_ps(v5, v8);
  v11 = _mm_sub_ps(_mm_shuffle_ps(v10, v10, 78), v10);
  v12 = _mm_shuffle_ps(v2, v2, 57);
  v13 = _mm_shuffle_ps(v12, v12, 57);
  v14 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(v12, _mm_sub_ps(_mm_shuffle_ps(v9, v9, 57), _mm_shuffle_ps(v6, v6, 78))),
              _mm_mul_ps(v11, v13)),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 57), _mm_sub_ps(v9, _mm_shuffle_ps(v6, v6, 57)))),
          v1);
  v15 = _mm_add_ps(v14, _mm_movehl_ps(v14, v14));
  return (float)(v15.m128_f32[0] - _mm_shuffle_ps(v15, v15, 1).m128_f32[0]);
}
