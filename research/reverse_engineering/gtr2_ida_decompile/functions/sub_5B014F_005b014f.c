__m128 *__stdcall sub_5B014F(__m128 *a1, int a2, int a3, int a4)
{
  __m128 v4; // xmm4
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 *result; // eax
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // [esp-14h] [ebp-18h]

  v4 = _mm_loadh_ps((const double *)(a2 + 8));
  v5 = _mm_loadh_ps((const double *)(a3 + 8));
  v6 = _mm_loadh_ps((const double *)(a4 + 8));
  result = a1;
  v8 = _mm_shuffle_ps(v5, v5, 57);
  v9 = _mm_mul_ps(v8, v6);
  v10 = _mm_shuffle_ps(v6, v6, 78);
  v11 = _mm_mul_ps(v8, v10);
  v16 = _mm_mul_ps(v8, _mm_shuffle_ps(v10, v10, 57));
  v12 = _mm_sub_ps(_mm_shuffle_ps(v11, v11, 57), _mm_shuffle_ps(v9, v9, 78));
  v13 = _mm_shuffle_ps(v9, v9, 57);
  v14 = _mm_shuffle_ps(v4, v4, 57);
  v15 = _mm_shuffle_ps(v14, v14, 57);
  *a1 = _mm_xor_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(v14, v12), _mm_mul_ps(v15, _mm_sub_ps(_mm_shuffle_ps(v16, v16, 78), v16))),
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 57), _mm_sub_ps(v11, v13))),
          (__m128)xmmword_905EE0);
  return result;
}
