// f1c  0x0053bde0  size=123
double __stdcall sub_53BDE0(__int32 *a1, __m128 *a2)
{
  __m128 v2; // xmm0
  __m128 v4; // [esp+0h] [ebp-10h]

  v4.m128_i32[0] = 0;
  v4.m128_i32[1] = a1[2];
  v4.m128_i32[2] = a1[1];
  v4.m128_i32[3] = *a1;
  v2 = _mm_mul_ps(v4, *a2);
  return (float)(v2.m128_f32[0]
               + (float)(_mm_shuffle_ps(v2, v2, 1).m128_f32[0]
                       + (float)(_mm_shuffle_ps(v2, v2, 2).m128_f32[0] + _mm_shuffle_ps(v2, v2, 3).m128_f32[0])));
}
