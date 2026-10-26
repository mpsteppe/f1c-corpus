__m128 *__cdecl sub_566410(__m128i *a1, __m128 *a2, __m128 *a3)
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

  v3 = (__m128)_mm_and_si128(*a1, (__m128i)xmmword_618F00);
  v4 = _mm_add_ps(_mm_mul_ps(v3, (__m128)xmmword_618EE0), (__m128)xmmword_618E90);
  v5 = _mm_sub_ps(v4, (__m128)xmmword_618E90);
  v6 = _mm_sub_ps(
         _mm_sub_ps(
           _mm_sub_ps(_mm_sub_ps(v3, _mm_mul_ps((__m128)xmmword_618ED0, v5)), _mm_mul_ps((__m128)xmmword_618EC0, v5)),
           _mm_mul_ps((__m128)xmmword_618EB0, v5)),
         _mm_mul_ps((__m128)xmmword_618EA0, v5));
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_and_ps(v4, (__m128)xmmword_618E60);
  v9 = (__m128i)_mm_and_ps(v8, (__m128)xmmword_618E50);
  v10 = _mm_sub_epi32((__m128i)v8, v9);
  v11 = (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32((__m128i)v8, v9), (__m128i)xmmword_618E40), 0x1Eu);
  v12 = _mm_cmpneq_ps((__m128)_mm_slli_epi32(v9, 0x1Eu), (__m128)0LL);
  v13 = _mm_mul_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_add_ps(_mm_mul_ps((__m128)xmmword_618E80, v7), (__m128)xmmword_618E30), v7),
                (__m128)xmmword_618E10),
              v7),
            (__m128)xmmword_618DF0),
          v6);
  v14 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_add_ps(_mm_mul_ps((__m128)xmmword_618E70, v7), (__m128)xmmword_618E20), v7),
                  (__m128)xmmword_618E00),
                v7),
              (__m128)xmmword_618DE0),
            v7),
          (__m128)xmmword_618DD0);
  result = a2;
  *a2 = _mm_xor_ps(
          _mm_or_ps(_mm_andnot_ps(v12, v13), _mm_and_ps(v12, v14)),
          (__m128)_mm_xor_si128(
                    _mm_slli_epi32(_mm_and_si128(v10, (__m128i)xmmword_618E40), 0x1Eu),
                    _mm_and_si128(*a1, (__m128i)xmmword_618EF0)));
  *a3 = _mm_xor_ps(_mm_or_ps(_mm_and_ps(v12, v13), _mm_andnot_ps(v12, v14)), v11);
  return result;
}
