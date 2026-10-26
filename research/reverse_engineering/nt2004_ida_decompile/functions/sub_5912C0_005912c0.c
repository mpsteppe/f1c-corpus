double __stdcall sub_5912C0(__m128 *a1, __m128 *a2)
{
  __m128 v2; // xmm0

  v2 = _mm_mul_ps(*a1, *a2);
  return (float)(v2.m128_f32[0] + (float)(_mm_shuffle_ps(v2, v2, 1).m128_f32[0] + _mm_shuffle_ps(v2, v2, 2).m128_f32[0]));
}
