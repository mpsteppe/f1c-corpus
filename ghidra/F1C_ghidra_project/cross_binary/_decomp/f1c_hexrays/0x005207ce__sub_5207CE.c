// f1c  0x005207ce  size=152
__m128 *__stdcall sub_5207CE(__m128 *a1, int a2, int a3, int a4)
{
  __m128 *result; // eax
  __m128 v5; // xmm2
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm4
  __m128 v10; // xmm0
  __m128 v11; // xmm4
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm1

  result = a1;
  v5 = _mm_loadh_ps((const double *)(a3 + 8));
  v6 = _mm_shuffle_ps(v5, v5, 57);
  v7 = _mm_loadh_ps((const double *)(a2 + 8));
  v8 = _mm_loadh_ps((const double *)(a4 + 8));
  v9 = _mm_shuffle_ps(v8, v8, 78);
  v10 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 57), v6);
  v11 = _mm_mul_ps(v9, v6);
  v12 = _mm_mul_ps(v6, v8);
  v13 = _mm_shuffle_ps(v7, v7, 57);
  v14 = _mm_shuffle_ps(v13, v13, 57);
  *a1 = _mm_xor_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(v13, _mm_sub_ps(_mm_shuffle_ps(v11, v11, 57), _mm_shuffle_ps(v12, v12, 78))),
              _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v10, v10, 78), v10), v14)),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 57), _mm_sub_ps(v11, _mm_shuffle_ps(v12, v12, 57)))),
          (__m128)xmmword_5D8C20);
  return result;
}
