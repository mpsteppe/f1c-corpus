__m128 *__stdcall sub_5BB223(__m128i *a1, __m128 *a2, __m128 *a3)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm3
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // xmm4
  __m128 v8; // xmm7
  __m128i v9; // xmm0
  __m128i v10; // xmm3
  __m128 v11; // xmm7
  __m128 v12; // xmm0
  __m128 v13; // xmm5
  __m128 v14; // xmm6
  __m128 *result; // eax

  v3 = (__m128)_mm_and_si128(*a1, (__m128i)xmmword_906530);
  v4 = _mm_add_ps(_mm_mul_ps(v3, (__m128)xmmword_906510), (__m128)xmmword_9064C0);
  v5 = _mm_sub_ps(v4, (__m128)xmmword_9064C0);
  v6 = _mm_sub_ps(
         _mm_sub_ps(
           _mm_sub_ps(_mm_sub_ps(v3, _mm_mul_ps((__m128)xmmword_906500, v5)), _mm_mul_ps((__m128)xmmword_9064F0, v5)),
           _mm_mul_ps((__m128)xmmword_9064E0, v5)),
         _mm_mul_ps((__m128)xmmword_9064D0, v5));
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_and_ps(v4, (__m128)xmmword_906490);
  v9 = (__m128i)_mm_and_ps(v8, (__m128)xmmword_906480);
  v10 = _mm_sub_epi32((__m128i)v8, v9);
  v11 = (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32((__m128i)v8, v9), (__m128i)xmmword_906470), 0x1Eu);
  v12 = _mm_cmpneq_ps((__m128)_mm_slli_epi32(v9, 0x1Eu), (__m128)0LL);
  v13 = _mm_mul_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_add_ps(_mm_mul_ps((__m128)xmmword_9064B0, v7), (__m128)xmmword_906460), v7),
                (__m128)xmmword_906440),
              v7),
            (__m128)xmmword_906420),
          v6);
  v14 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_add_ps(_mm_mul_ps((__m128)xmmword_9064A0, v7), (__m128)xmmword_906450), v7),
                  (__m128)xmmword_906430),
                v7),
              (__m128)xmmword_906410),
            v7),
          (__m128)xmmword_906400);
  result = a2;
  *a2 = _mm_xor_ps(
          _mm_or_ps(_mm_andnot_ps(v12, v13), _mm_and_ps(v12, v14)),
          (__m128)_mm_xor_si128(
                    _mm_slli_epi32(_mm_and_si128(v10, (__m128i)xmmword_906470), 0x1Eu),
                    _mm_and_si128(*a1, (__m128i)xmmword_906520)));
  *a3 = _mm_xor_ps(_mm_or_ps(_mm_and_ps(v12, v13), _mm_andnot_ps(v12, v14)), v11);
  return result;
}
