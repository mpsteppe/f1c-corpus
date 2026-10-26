__m128 *__stdcall sub_51F650(__m128 *a1, __m128 *a2, __m128 *a3, __m128 *a4, unsigned int a5, unsigned int a6)
{
  *a1 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*a3, *a2), _mm_shuffle_ps((__m128)a5, (__m128)a5, 0)), *a2),
          _mm_mul_ps(_mm_sub_ps(*a4, *a2), _mm_shuffle_ps((__m128)a6, (__m128)a6, 0)));
  return a1;
}
