// Address: 0x0051f5f0
// Size: 92 bytes
// Name: sub_51F5F0
// Type: int __stdcall(int, const double *, const double *, const double *, unsigned int, unsigned int)
// Source: IDA Hex-Rays decompilation

int __stdcall sub_51F5F0(
        int a1,
        const double *a2,
        const double *a3,
        const double *a4,
        unsigned int a5,
        unsigned int a6)
{
  __m128 v6; // xmm2
  __m128 v7; // xmm3

  v6 = _mm_loadh_ps(a2);
  v7 = _mm_add_ps(
         _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_loadh_ps(a3), v6), _mm_shuffle_ps((__m128)a5, (__m128)a5, 0)), v6),
         _mm_mul_ps(_mm_sub_ps(_mm_loadh_ps(a4), v6), _mm_shuffle_ps((__m128)a6, (__m128)a6, 0)));
  *(_DWORD *)(a1 + 8) = v7.m128_i32[0];
  _mm_storeh_ps((double *)a1, v7);
  return a1;
}
