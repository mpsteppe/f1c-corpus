int __stdcall sub_5B12AB(int a1, int a2, int a3)
{
  __m128 v3; // xmm0
  unsigned int v4; // ecx
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  int result; // eax
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  __m128 v13; // xmm0

  v3 = _mm_loadl_ps((const double *)a2);
  v4 = *(_DWORD *)(a2 + 8);
  if ( (a3 & 0xF) != 0 )
  {
    v5 = _mm_add_ps(
           _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 40)), _mm_shuffle_ps((__m128)v4, (__m128)v4, 0)),
           _mm_loadh_ps((const double *)(a3 + 56)));
    v6 = _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 24)), _mm_shuffle_ps(v3, v3, 85));
    v7 = _mm_shuffle_ps(v3, v3, 0);
    v8 = _mm_loadh_ps((const double *)(a3 + 8));
  }
  else
  {
    v5 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(a3 + 32), _mm_shuffle_ps((__m128)v4, (__m128)v4, 0)), *(__m128 *)(a3 + 48));
    v6 = _mm_mul_ps(*(__m128 *)(a3 + 16), _mm_shuffle_ps(v3, v3, 85));
    v7 = _mm_shuffle_ps(v3, v3, 0);
    v8 = *(__m128 *)a3;
  }
  result = a1;
  v10 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v8, v7), v6), v5);
  v11 = _mm_rcp_ps(v10);
  v12 = _mm_sub_ps(_mm_add_ps(v11, v11), _mm_mul_ps(_mm_mul_ps(v11, v10), v11));
  v13 = _mm_mul_ps(v10, _mm_shuffle_ps(v12, v12, 255));
  _mm_storel_ps((double *)a1, v13);
  *(_DWORD *)(a1 + 8) = _mm_movehl_ps(v13, v13).m128_u32[0];
  return result;
}
