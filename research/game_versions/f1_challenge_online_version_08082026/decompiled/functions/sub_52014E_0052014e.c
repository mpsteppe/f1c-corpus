__m128 *__stdcall sub_52014E(__m128 *a1, __m128 *a2, int a3)
{
  if ( (a3 & 0xF) != 0 )
    *a1 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 8)), _mm_shuffle_ps(*a2, *a2, 0)),
              _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 24)), _mm_shuffle_ps(*a2, *a2, 85))),
            _mm_add_ps(
              _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 40)), _mm_shuffle_ps(*a2, *a2, 170)),
              _mm_mul_ps(_mm_loadh_ps((const double *)(a3 + 56)), _mm_shuffle_ps(*a2, *a2, 255))));
  else
    *a1 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*a2, *a2, 0), *(__m128 *)a3),
              _mm_mul_ps(_mm_shuffle_ps(*a2, *a2, 85), *(__m128 *)(a3 + 16))),
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*a2, *a2, 170), *(__m128 *)(a3 + 32)),
              _mm_mul_ps(_mm_shuffle_ps(*a2, *a2, 255), *(__m128 *)(a3 + 48))));
  return a1;
}
