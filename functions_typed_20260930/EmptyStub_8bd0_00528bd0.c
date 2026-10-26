__m128 __userpurge sub_528BD0@<xmm0>(__m128i a1@<xmm0>, int a2, int a3, int a4, int a5)
{
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  __m128 v14; // xmm4
  __m128 v15; // xmm7
  __m128i v16; // xmm0
  __m128i v17; // xmm3
  __m128 v18; // xmm7
  __m128 v19; // xmm5
  __m128 v20; // xmm2
  __m128 v21; // xmm0
  __m128 v22; // xmm2

  v6 = (__m128)_mm_and_si128(a1, (__m128i)xmmword_5D9140);
  v7 = _mm_add_ps(_mm_mul_ps(v6, (__m128)xmmword_5D9120), (__m128)xmmword_5D9100);
  v8 = _mm_mul_ps((__m128)xmmword_5D9110, _mm_sub_ps(v7, (__m128)xmmword_5D9100));
  v9 = _mm_sub_ps(v6, v8);
  v10 = _mm_shuffle_ps(v8, v8, 57);
  v11 = _mm_sub_ps(v9, v10);
  v12 = _mm_shuffle_ps(v10, v10, 57);
  v13 = _mm_sub_ps(_mm_sub_ps(v11, v12), _mm_shuffle_ps(v12, v12, 57));
  v14 = _mm_mul_ps(v13, v13);
  v15 = _mm_and_ps(v7, (__m128)xmmword_5D90F0);
  v16 = (__m128i)_mm_and_ps(v15, (__m128)xmmword_5D90E0);
  v17 = _mm_sub_epi32((__m128i)v15, v16);
  v18 = (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32((__m128i)v15, v16), (__m128i)xmmword_5D90D0), 0x1Eu);
  v19 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_add_ps(_mm_mul_ps((__m128)xmmword_5D90C0, v14), (__m128)xmmword_5D90B0), v14),
                  (__m128)xmmword_5D90A0),
                v14),
              (__m128)xmmword_5D9090),
            _mm_unpacklo_ps(v13, v14)),
          (__m128)xmmword_5D9080);
  v20 = _mm_cmpneq_ps((__m128)_mm_slli_epi32(v16, 0x1Eu), (__m128)0LL);
  v21 = _mm_and_ps(v20, v19);
  v22 = _mm_andnot_ps(v20, v19);
  return _mm_xor_ps(
           _mm_or_ps(v21, _mm_shuffle_ps(v22, v22, 177)),
           _mm_unpacklo_ps(
             v18,
             (__m128)_mm_xor_si128(
                       _mm_slli_epi32(_mm_and_si128(v17, (__m128i)xmmword_5D90D0), 0x1Eu),
                       _mm_and_si128(a1, (__m128i)xmmword_5D9130))));
}

