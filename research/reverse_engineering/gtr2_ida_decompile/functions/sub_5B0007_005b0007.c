double *__stdcall sub_5B0007(double *a1, unsigned int *a2, const double *a3)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  __m128 v14; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm2

  v3 = _mm_loadh_ps(a3 + 1);
  v4 = _mm_loadh_ps(a3 + 3);
  v5 = _mm_loadh_ps(a3 + 5);
  v6 = _mm_loadh_ps(a3 + 7);
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps((__m128)*a2, (__m128)*a2, 0), v3),
           _mm_mul_ps(_mm_shuffle_ps((__m128)a2[1], (__m128)a2[1], 0), v4)),
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps((__m128)a2[2], (__m128)a2[2], 0), v5),
           _mm_mul_ps(_mm_shuffle_ps((__m128)a2[3], (__m128)a2[3], 0), v6)));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps((__m128)a2[4], (__m128)a2[4], 0), v3),
             _mm_mul_ps(_mm_shuffle_ps((__m128)a2[5], (__m128)a2[5], 0), v4)),
           _mm_mul_ps(_mm_shuffle_ps((__m128)a2[6], (__m128)a2[6], 0), v5)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)a2[7], (__m128)a2[7], 0), v6));
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps((__m128)a2[8], (__m128)a2[8], 0), v3),
             _mm_mul_ps(_mm_shuffle_ps((__m128)a2[9], (__m128)a2[9], 0), v4)),
           _mm_mul_ps(_mm_shuffle_ps((__m128)a2[10], (__m128)a2[10], 0), v5)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)a2[11], (__m128)a2[11], 0), v6));
  v10 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(v3, _mm_shuffle_ps((__m128)a2[12], (__m128)a2[12], 0)),
            _mm_mul_ps(v4, _mm_shuffle_ps((__m128)a2[13], (__m128)a2[13], 0))),
          _mm_add_ps(
            _mm_mul_ps(v5, _mm_shuffle_ps((__m128)a2[14], (__m128)a2[14], 0)),
            _mm_mul_ps(v6, _mm_shuffle_ps((__m128)a2[15], (__m128)a2[15], 0))));
  v11 = v7;
  v12 = v9;
  v13 = _mm_unpacklo_ps(v7, v8);
  v14 = _mm_unpacklo_ps(v9, v10);
  v15 = _mm_unpackhi_ps(v11, v8);
  v16 = _mm_unpackhi_ps(v12, v10);
  _mm_storel_ps(a1, v13);
  _mm_storel_ps(a1 + 1, v14);
  _mm_storeh_ps(a1 + 2, v13);
  _mm_storeh_ps(a1 + 3, v14);
  _mm_storel_ps(a1 + 4, v15);
  _mm_storel_ps(a1 + 5, v16);
  _mm_storeh_ps(a1 + 6, v15);
  _mm_storeh_ps(a1 + 7, v16);
  return a1;
}
