int __stdcall sub_51FF8E(int a1, int a2, int a3)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm0
  __m128 v6; // xmm5
  __m128 v7; // xmm3

  if ( (a3 & 0xF) != 0 )
  {
    v6 = _mm_loadl_ps((const double *)a2);
    v7 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 8)), _mm_shuffle_ps(v6, v6, 0)),
             _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 24)), _mm_shuffle_ps(v6, v6, 85))),
           _mm_mul_ps(
             _mm_loadh_ps((const double *)(a3 + 40)),
             _mm_shuffle_ps((__m128)*(unsigned int *)(a2 + 8), (__m128)*(unsigned int *)(a2 + 8), 0)));
    _mm_storel_ps((double *)a1, v7);
    *(_DWORD *)(a1 + 8) = _mm_movehl_ps(v7, v7).m128_u32[0];
  }
  else
  {
    v3 = _mm_loadl_ps((const double *)a2);
    v4 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), *(__m128 *)a3),
             _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), *(__m128 *)(a3 + 16))),
           _mm_mul_ps(
             _mm_shuffle_ps((__m128)*(unsigned int *)(a2 + 8), (__m128)*(unsigned int *)(a2 + 8), 0),
             *(__m128 *)(a3 + 32)));
    _mm_storel_ps((double *)a1, v4);
    *(_DWORD *)(a1 + 8) = _mm_movehl_ps(v4, v4).m128_u32[0];
  }
  return a1;
}

