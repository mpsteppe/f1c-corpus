__m128 *__stdcall sub_591010(float *a1, float *a2, float *a3, __m128 *a4)
{
  __m128 v4; // xmm0
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 *result; // eax
  float v10; // [esp+Ch] [ebp-14h]
  float v11; // [esp+Ch] [ebp-14h]
  unsigned int v12; // [esp+Ch] [ebp-14h]
  __m128 v13; // [esp+10h] [ebp-10h]
  __m128 v14; // [esp+10h] [ebp-10h]

  v10 = a2[4] * a2[5];
  v13.m128_f32[0] = v10;
  v11 = a2[3] * a2[5];
  v13.m128_f32[1] = v11;
  *(float *)&v12 = a2[2] * a2[5];
  v13.m128_u64[1] = v12;
  v4 = v13;
  v13.m128_f32[0] = a3[23];
  v13.m128_f32[1] = a3[22];
  v13.m128_u64[1] = COERCE_UNSIGNED_INT(a3[21]);
  v5 = v13;
  v13.m128_f32[0] = a3[31];
  v13.m128_f32[1] = a3[30];
  v13.m128_u64[1] = COERCE_UNSIGNED_INT(a3[29]);
  v6 = v13;
  v13.m128_u64[0] = 0x437F0000437F0000LL;
  v13.m128_u64[1] = 1132396544;
  v7 = v13;
  v8 = _mm_mul_ps(v4, v5);
  if ( a1 )
  {
    v14.m128_f32[0] = a1[100];
    v14.m128_f32[1] = a1[99];
    v14.m128_u64[1] = COERCE_UNSIGNED_INT(a1[98]);
    v8 = _mm_add_ps(v14, v8);
  }
  result = a4;
  *a4 = _mm_mul_ps(_mm_add_ps(v8, v6), v7);
  return result;
}
