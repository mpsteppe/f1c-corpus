// f1c  0x0053bce0  size=255
__m128 *__stdcall sub_53BCE0(float *a1, float *a2, __m128 *a3)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm1
  __m128 *result; // eax
  float v6; // [esp+Ch] [ebp-14h]
  float v7; // [esp+Ch] [ebp-14h]
  unsigned int v8; // [esp+Ch] [ebp-14h]
  __m128 v9; // [esp+10h] [ebp-10h]

  v9.m128_u64[0] = 0x437F0000437F0000LL;
  v9.m128_u64[1] = 1132396544;
  v3 = v9;
  v9.m128_f32[0] = a2[19];
  v9.m128_f32[1] = a2[18];
  v9.m128_u64[1] = COERCE_UNSIGNED_INT(a2[17]);
  v6 = a1[8] * a1[9];
  v4 = v9;
  v9.m128_f32[0] = v6;
  v7 = a1[7] * a1[9];
  result = a3;
  v9.m128_f32[1] = v7;
  *(float *)&v8 = a1[6] * a1[9];
  v9.m128_u64[1] = v8;
  *a3 = _mm_mul_ps(_mm_mul_ps(v9, v4), v3);
  return result;
}
