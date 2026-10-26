__m128 *__userpurge sub_5B03E7@<eax>(
        __m128 a1@<xmm1>,
        __m128 a2@<xmm2>,
        __m128 *a3,
        __m128 *a4,
        __m128 *a5,
        __m128 *a6,
        __m128 *a7,
        float a8)
{
  __m128 v8; // xmm0
  __m128 v9; // xmm0

  v8 = (__m128)LODWORD(a8);
  a1.m128_f32[0] = v8.m128_f32[0] * v8.m128_f32[0];
  a2.m128_f32[0] = a8 * (float)(v8.m128_f32[0] * v8.m128_f32[0]);
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), (__m128)xmmword_905DF0), (__m128)xmmword_905E00),
           _mm_mul_ps(_mm_shuffle_ps(a1, a1, 0), (__m128)xmmword_905DE0)),
         _mm_mul_ps(_mm_shuffle_ps(a2, a2, 0), (__m128)xmmword_905DD0));
  *a3 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(*a4, _mm_shuffle_ps(v9, v9, 0)), _mm_mul_ps(*a5, _mm_shuffle_ps(v9, v9, 85))),
            _mm_mul_ps(*a6, _mm_shuffle_ps(v9, v9, 170))),
          _mm_mul_ps(*a7, _mm_shuffle_ps(v9, v9, 255)));
  return a3;
}
