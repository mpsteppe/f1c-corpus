__m128 *__stdcall sub_5B2FBC(__m128 *a1, __m128 *a2, int a3)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 *result; // eax

  v3 = *a2;
  v4 = _mm_shuffle_ps(v3, v3, 255);
  if ( (a3 & 0xF) != 0 )
  {
    v5 = _mm_add_ps(
           _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 40)), _mm_shuffle_ps(v3, v3, 170)),
           _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 56)), v4));
    v6 = _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 24)), _mm_shuffle_ps(v3, v3, 85));
    v7 = _mm_shuffle_ps(v3, v3, 0);
    v8 = _mm_loadh_ps((const double *)(a3 + 8));
  }
  else
  {
    v5 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(a3 + 32), _mm_shuffle_ps(v3, v3, 170)), _mm_mul_ps(*(__m128 *)(a3 + 48), v4));
    v6 = _mm_mul_ps(*(__m128 *)(a3 + 16), _mm_shuffle_ps(v3, v3, 85));
    v7 = _mm_shuffle_ps(v3, v3, 0);
    v8 = *(__m128 *)a3;
  }
  result = a1;
  *a1 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v8, v7), v6), v5);
  return result;
}
