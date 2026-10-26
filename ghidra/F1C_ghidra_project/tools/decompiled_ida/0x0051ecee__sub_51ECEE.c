// Address: 0x0051ecee
// Size: 163 bytes
// Name: sub_51ECEE
// Type: __m128 *__stdcall(__m128 *, int, int)
// Source: IDA Hex-Rays decompilation

__m128 *__stdcall sub_51ECEE(__m128 *a1, int a2, int a3)
{
  __m128 v3; // xmm2
  __m128 v5; // xmm6

  if ( (a3 & 0xF) != 0 )
  {
    v5 = _mm_loadl_ps((const double *)a2);
    *a1 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 8)), _mm_shuffle_ps(v5, v5, 0)),
              _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 24)), _mm_shuffle_ps(v5, v5, 85))),
            _mm_add_ps(
              _mm_mul_ps(
                _mm_loadh_ps((const double *)(a3 + 40)),
                _mm_shuffle_ps((__m128)*(unsigned int *)(a2 + 8), (__m128)*(unsigned int *)(a2 + 8), 0)),
              _mm_loadh_ps((const double *)(a3 + 56))));
  }
  else
  {
    v3 = _mm_loadl_ps((const double *)a2);
    *a1 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), *(__m128 *)a3),
              _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), *(__m128 *)(a3 + 16))),
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)*(unsigned int *)(a2 + 8), (__m128)*(unsigned int *)(a2 + 8), 0),
                *(__m128 *)(a3 + 32)),
              *(__m128 *)(a3 + 48)));
  }
  return a1;
}
