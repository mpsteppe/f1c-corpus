__m128 *__stdcall sub_5AF7AE(__m128 *a1, int a2)
{
  __m128 v2; // xmm1
  __m128 *result; // eax
  __m128 v4; // xmm0
  __m128 v5; // xmm0
  float v6; // xmm3_4
  __m128 v7; // xmm0
  __m128 v8; // [esp-14h] [ebp-18h]

  v2 = _mm_loadh_ps((const double *)(a2 + 8));
  result = a1;
  v4 = _mm_mul_ps(v2, v2);
  v5 = _mm_add_ps(v4, _mm_movehl_ps(v4, v4));
  v5.m128_f32[0] = v5.m128_f32[0] + _mm_shuffle_ps(v5, v5, 85).m128_f32[0];
  v8 = v5;
  v8.m128_f32[0] = 1.0 / v5.m128_f32[0];
  v6 = (float)(1.0 / v5.m128_f32[0]) * v5.m128_f32[0];
  v7 = v8;
  v7.m128_f32[0] = (float)(v7.m128_f32[0] + v7.m128_f32[0]) - (float)(v6 * v8.m128_f32[0]);
  *a1 = _mm_mul_ps(_mm_mul_ps(v2, (__m128)xmmword_905D80), _mm_shuffle_ps(v7, v7, 0));
  return result;
}
