double *__stdcall sub_5AFA5D(double *a1, unsigned int *a2, __m128 *a3)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm0

  v3 = _mm_add_ps(
         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)*a2, (__m128)*a2, 0), *a3), a3[3]),
         _mm_mul_ps(_mm_shuffle_ps((__m128)a2[1], (__m128)a2[1], 0), a3[1]));
  v4 = _mm_rcp_ps(v3);
  v5 = _mm_sub_ps(_mm_add_ps(v4, v4), _mm_mul_ps(_mm_mul_ps(v4, v4), v3));
  _mm_storel_ps(a1, _mm_mul_ps(v3, _mm_shuffle_ps(v5, v5, 255)));
  return a1;
}
