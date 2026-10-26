__m128 *__stdcall sub_5AFA1D(__m128 *a1, unsigned int *a2, __m128 *a3)
{
  *a1 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)*a2, (__m128)*a2, 0), *a3), a3[3]),
          _mm_mul_ps(_mm_shuffle_ps((__m128)a2[1], (__m128)a2[1], 0), a3[1]));
  return a1;
}
