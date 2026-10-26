__m128 *__stdcall sub_520E0E(__m128 *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __m128 v4; // xmm0
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm3
  __m128 *result; // eax
  __m128 v10; // [esp+10h] [ebp-4Ch] BYREF
  __m128 v11[3]; // [esp+20h] [ebp-3Ch] BYREF

  v10 = _mm_mul_ps(
          _mm_shuffle_ps(
            _mm_unpacklo_ps((__m128)a3, (__m128)a4),
            _mm_unpacklo_ps((__m128)(unsigned int)dword_8D62C0, (__m128)a2),
            17),
          (__m128)xmmword_8D62B0);
  sub_528CC0(&v10, &v10, v11);
  v4 = _mm_shuffle_ps(v10, v11[0], 0);
  v5 = _mm_shuffle_ps(v4, v4, 138);
  v6 = _mm_shuffle_ps(v10, v11[0], 153);
  v7 = _mm_shuffle_ps(v6, v6, 247);
  v8 = _mm_shuffle_ps(v6, v6, 168);
  v10 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v5, v7), v8),
          _mm_xor_ps(
            _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 138), _mm_shuffle_ps(v7, v7, 81)), _mm_shuffle_ps(v8, v8, 1)),
            (__m128)xmmword_8D62A0));
  result = a1;
  *a1 = v10;
  return result;
}
