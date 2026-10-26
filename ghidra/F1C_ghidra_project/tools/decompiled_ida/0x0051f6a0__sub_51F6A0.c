// Address: 0x0051f6a0
// Size: 81 bytes
// Name: sub_51F6A0
// Type: double *__stdcall(double *, const double *, const double *, const double *, unsigned int, unsigned int)
// Source: IDA Hex-Rays decompilation

double *__stdcall sub_51F6A0(
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
