double *__userpurge sub_5B0360@<eax>(
        __m128 a1@<xmm1>,
        __m128 a2@<xmm2>,
        double *a3,
        int a4,
        const double *a5,
        int a6,
        const double *a7,
        float a8)
{
  __m128 v8; // xmm0
  __m128 v9; // xmm0
  __m128 v10; // xmm6
  __m128 v11; // xmm4

  v8 = (__m128)LODWORD(a8);
  a1.m128_f32[0] = v8.m128_f32[0] * v8.m128_f32[0];
  a2.m128_f32[0] = a8 * (float)(v8.m128_f32[0] * v8.m128_f32[0]);
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), (__m128)xmmword_905DF0), (__m128)xmmword_905E00),
           _mm_mul_ps(_mm_shuffle_ps(a1, a1, 0), (__m128)xmmword_905DE0)),
         _mm_mul_ps(_mm_shuffle_ps(a2, a2, 0), (__m128)xmmword_905DD0));
  v10 = _mm_mul_ps(_mm_loadh_ps(a7), _mm_shuffle_ps(v9, v9, 250));
  v11 = _mm_add_ps(_mm_mul_ps(_mm_loadh_ps(a5), _mm_shuffle_ps(v9, v9, 80)), v10);
  _mm_storel_ps(a3, _mm_add_ps(v11, _mm_movehl_ps(v10, v11)));
  return a3;
}
