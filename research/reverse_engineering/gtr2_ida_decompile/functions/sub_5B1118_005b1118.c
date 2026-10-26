int __stdcall sub_5B1118(int a1, int a2, int a3)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __m128 v6; // xmm0
  __m128 v7; // xmm0
  int result; // eax
  __m128 v9; // xmm0

  if ( (a3 & 0xF) != 0 )
  {
    v7 = _mm_loadl_ps((const double *)a2);
    v4 = _mm_mul_ps(
           _mm_loadh_ps((const double *)(a3 + 40)),
           _mm_shuffle_ps((__m128)*(unsigned int *)(a2 + 8), (__m128)*(unsigned int *)(a2 + 8), 0));
    v5 = _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 24)), _mm_shuffle_ps(v7, v7, 85));
    v6 = _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 8)), _mm_shuffle_ps(v7, v7, 0));
  }
  else
  {
    v3 = _mm_loadl_ps((const double *)a2);
    v4 = _mm_mul_ps(
           _mm_shuffle_ps((__m128)*(unsigned int *)(a2 + 8), (__m128)*(unsigned int *)(a2 + 8), 0),
           *(__m128 *)(a3 + 32));
    v5 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), *(__m128 *)(a3 + 16));
    v6 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), *(__m128 *)a3);
  }
  result = a1;
  v9 = _mm_add_ps(_mm_add_ps(v6, v5), v4);
  _mm_storel_ps((double *)a1, v9);
  *(_DWORD *)(a1 + 8) = _mm_movehl_ps(v9, v9).m128_u32[0];
  return result;
}
