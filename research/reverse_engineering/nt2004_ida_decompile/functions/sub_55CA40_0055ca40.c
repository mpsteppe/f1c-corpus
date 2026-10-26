double *__userpurge sub_55CA40@<eax>(
        __m128 a1@<xmm1>,
        __m128 a2@<xmm2>,
        __m128 a3@<xmm3>,
        double *a4,
        int a5,
        const double *a6,
        int a7,
        const double *a8,
        float a9)
{
  __m128 v9; // xmm0
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  __m128 v12; // xmm4

  v9 = (__m128)LODWORD(a9);
  a1.m128_f32[0] = v9.m128_f32[0] * v9.m128_f32[0];
  a2.m128_f32[0] = a9 * (float)(v9.m128_f32[0] * v9.m128_f32[0]);
  v10 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), (__m128)xmmword_618740);
  v10.m128_f32[0] = v10.m128_f32[0] + *(float *)&dword_618720;
  v11 = _mm_add_ps(
          _mm_add_ps(v10, _mm_mul_ps(_mm_shuffle_ps(a1, a1, 0), (__m128)xmmword_618730)),
          _mm_mul_ps(_mm_shuffle_ps(a2, a2, 0), (__m128)xmmword_618710));
  v12 = _mm_add_ps(
          _mm_mul_ps(_mm_loadh_ps(a6), _mm_shuffle_ps(v11, v11, 80)),
          _mm_mul_ps(_mm_loadh_ps(a8), _mm_shuffle_ps(v11, v11, 250)));
  _mm_storel_ps(a4, _mm_add_ps(v12, _mm_movehl_ps(a3, v12)));
  return a4;
}
