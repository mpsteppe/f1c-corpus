__m128 *__stdcall sub_5AF832(__m128 *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 *result; // eax
  __m128 v10; // [esp-24h] [ebp-28h] BYREF
  __m128 v11; // [esp-14h] [ebp-18h] BYREF

  v11.m128_u64[0] = __PAIR64__(a3, a4);
  v11.m128_u64[1] = a2;
  v11 = _mm_mul_ps(v11, unk_729370);
  sub_5BB037(&v11, &v11, &v10);
  v4 = _mm_shuffle_ps(v11, v10, 153);
  v5 = _mm_shuffle_ps(v11, v10, 0);
  v6 = _mm_shuffle_ps(v4, v4, 247);
  v7 = _mm_shuffle_ps(v4, v4, 168);
  v8 = _mm_shuffle_ps(v5, v5, 138);
  result = a1;
  *a1 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v8, v6), v7),
          _mm_xor_ps(
            _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 138), _mm_shuffle_ps(v6, v6, 81)), _mm_shuffle_ps(v7, v7, 1)),
            unk_729360));
  return result;
}
