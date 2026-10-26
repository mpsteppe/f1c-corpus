__m128 *__stdcall sub_5B3273(__m128 *a1, const double *a2, const double *a3, const double *a4)
{
  __m128 *result; // eax
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm4
  __m128 v9; // xmm5
  __m128 v10; // xmm3
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm5
  __m128 v15; // xmm0
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm0

  result = a1;
  v5 = _mm_loadh_ps(a2);
  v6 = _mm_sub_ps(v5, _mm_loadh_ps(a4));
  v7 = _mm_shuffle_ps(v6, v6, 120);
  v8 = v5;
  v9 = _mm_sub_ps(v5, _mm_loadh_ps(a3));
  v10 = _mm_shuffle_ps(v9, v9, 99);
  v11 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 120), _mm_shuffle_ps(v6, v6, 99));
  v12 = (__m128)xmmword_729340;
  v13 = _mm_sub_ps(_mm_mul_ps(v7, v10), v11);
  v14 = _mm_mul_ps(v13, v13);
  v15 = _mm_add_ps(v14, _mm_movehl_ps(v14, v14));
  v15.m128_f32[0] = v15.m128_f32[0] + _mm_shuffle_ps(v15, v15, 1).m128_f32[0];
  v16 = v15;
  v15.m128_f32[0] = fsqrt(v15.m128_f32[0]);
  v12.m128_f32[0] = (float)(0.5 * (float)(1.0 / v15.m128_f32[0]))
                  * (float)(3.0
                          - (float)((float)(v16.m128_f32[0] * (float)(1.0 / v15.m128_f32[0]))
                                  * (float)(1.0 / v15.m128_f32[0])));
  v17 = _mm_mul_ps(v13, _mm_shuffle_ps(v12, v12, 0));
  *a1 = v17;
  v18 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 14), v17);
  a1->m128_i32[3] = COERCE_UNSIGNED_INT(
                      v18.m128_f32[0]
                    + (float)(_mm_movehl_ps(v16, v18).m128_f32[0] + _mm_shuffle_ps(v18, v18, 85).m128_f32[0]))
                  ^ xmmword_906040;
  return result;
}
