double *__stdcall sub_55CB80(
        double *a1,
        const double *a2,
        const double *a3,
        const double *a4,
        unsigned int a5,
        unsigned int a6)
{
  __m128 v6; // xmm2

  v6 = _mm_loadh_ps(a2);
  _mm_storeh_ps(
    a1,
    _mm_add_ps(
      _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_loadh_ps(a3), v6), _mm_shuffle_ps((__m128)a5, (__m128)a5, 0)), v6),
      _mm_mul_ps(_mm_sub_ps(_mm_loadh_ps(a4), v6), _mm_shuffle_ps((__m128)a6, (__m128)a6, 0))));
  return a1;
}
