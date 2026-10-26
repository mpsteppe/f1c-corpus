double *__stdcall sub_55D74E(double *a1, unsigned int *a2, const double *a3)
{
  double *result; // eax
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm7
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm7

  result = a1;
  v5 = _mm_loadh_ps(a3 + 1);
  v6 = _mm_loadh_ps(a3 + 3);
  v7 = _mm_loadh_ps(a3 + 5);
  v8 = _mm_loadh_ps(a3 + 7);
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps((__m128)*a2, (__m128)*a2, 0), v5),
             _mm_mul_ps(_mm_shuffle_ps((__m128)a2[1], (__m128)a2[1], 0), v6)),
           _mm_mul_ps(_mm_shuffle_ps((__m128)a2[2], (__m128)a2[2], 0), v7)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)a2[3], (__m128)a2[3], 0), v8));
  v10 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps((__m128)a2[4], (__m128)a2[4], 0), v5),
              _mm_mul_ps(_mm_shuffle_ps((__m128)a2[5], (__m128)a2[5], 0), v6)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)a2[6], (__m128)a2[6], 0), v7)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)a2[7], (__m128)a2[7], 0), v8));
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps((__m128)a2[8], (__m128)a2[8], 0), v5),
              _mm_mul_ps(_mm_shuffle_ps((__m128)a2[9], (__m128)a2[9], 0), v6)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)a2[10], (__m128)a2[10], 0), v7)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)a2[11], (__m128)a2[11], 0), v8));
  v12 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)a2[12], (__m128)a2[12], 0), v5),
          _mm_mul_ps(_mm_shuffle_ps((__m128)a2[13], (__m128)a2[13], 0), v6));
  v13 = _mm_mul_ps(_mm_shuffle_ps((__m128)a2[14], (__m128)a2[14], 0), v7);
  v14 = (__m128)a2[15];
  _mm_storel_ps(a1, v9);
  _mm_storeh_ps(a1 + 1, v9);
  _mm_storel_ps(a1 + 2, v10);
  _mm_storeh_ps(a1 + 3, v10);
  _mm_storel_ps(a1 + 4, v11);
  _mm_storeh_ps(a1 + 5, v11);
  v15 = _mm_add_ps(_mm_add_ps(v12, v13), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v8));
  _mm_storel_ps(a1 + 6, v15);
  _mm_storeh_ps(a1 + 7, v15);
  return result;
}
