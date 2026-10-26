// Address: 0x0051eca0
// Size: 57 bytes
// Name: sub_51ECA0
// Type: double *__stdcall(double *, unsigned int *, __m128 *)
// Source: IDA Hex-Rays decompilation

double *__stdcall sub_51ECA0(double *a1, unsigned int *a2, __m128 *a3)
{
  _mm_storel_ps(
    a1,
    _mm_add_ps(
      _mm_mul_ps(_mm_shuffle_ps((__m128)*a2, (__m128)*a2, 0), *a3),
      _mm_mul_ps(_mm_shuffle_ps((__m128)a2[1], (__m128)a2[1], 0), a3[1])));
  return a1;
}
