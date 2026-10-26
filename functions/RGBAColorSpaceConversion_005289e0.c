__m128 *__cdecl sub_5289E0(__m128 *a1, __m128 *a2, __m128 *a3)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 *v5; // edx
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  __m128 *result; // eax
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  v3 = _mm_and_ps(*a1, (__m128)xmmword_5D9050);
  v4 = _mm_and_ps(*a1, (__m128)xmmword_5D9060);
  v5 = (__m128 *)(&savedregs - 16);
  v6 = _mm_add_ps(_mm_mul_ps(v4, (__m128)xmmword_5D9040), (__m128)xmmword_5D8FF0);
  v7 = _mm_sub_ps(v6, (__m128)xmmword_5D8FF0);
  v8 = (__m128)xmmword_5D8FE0;
  v9 = (__m128)xmmword_5D8FD0;
  v10 = _mm_sub_ps(
          _mm_sub_ps(
            _mm_sub_ps(_mm_sub_ps(v4, _mm_mul_ps((__m128)xmmword_5D9030, v7)), _mm_mul_ps((__m128)xmmword_5D9020, v7)),
            _mm_mul_ps((__m128)xmmword_5D9010, v7)),
          _mm_mul_ps((__m128)xmmword_5D9000, v7));
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_and_ps(v6, (__m128)xmmword_5D8FC0);
  *v5 = _mm_and_ps(v12, (__m128)xmmword_5D8FB0);
  v5[1] = v12;
  v5[2] = v12;
  v5[1].m128_i32[0] = (dword_5D8FA0 & (v5[1].m128_i32[0] - v5->m128_i32[0])) << 30;
  v5[1].m128_i32[1] = (dword_5D8FA0 & (v5[1].m128_i32[1] - v5->m128_i32[1])) << 30;
  v5[1].m128_i32[2] = (dword_5D8FA0 & (v5[1].m128_i32[2] - v5->m128_i32[2])) << 30;
  v5[1].m128_i32[3] = (dword_5D8FA0 & (v5[1].m128_i32[3] - v5->m128_i32[3])) << 30;
  v5[2].m128_i32[0] = (dword_5D8FA0 & (v5->m128_i32[0] + v5[2].m128_i32[0])) << 30;
  v5[2].m128_i32[1] = (dword_5D8FA0 & (v5->m128_i32[1] + v5[2].m128_i32[1])) << 30;
  v5[2].m128_i32[2] = (dword_5D8FA0 & (v5->m128_i32[2] + v5[2].m128_i32[2])) << 30;
  v5[2].m128_i32[3] = (dword_5D8FA0 & (v5->m128_i32[3] + v5[2].m128_i32[3])) << 30;
  v5->m128_i32[0] = *(&savedregs - 16) << 30;
  v5->m128_i32[1] <<= 30;
  v5->m128_i32[2] <<= 30;
  v5->m128_i32[3] = *(&savedregs - 13) << 30;
  v13 = _mm_xor_ps(*((__m128 *)&savedregs - 3), v3);
  v14 = _mm_cmpneq_ps(*((__m128 *)&savedregs - 4), (__m128)0LL);
  v15 = _mm_mul_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v8, v11), (__m128)xmmword_5D8F90), v11),
                (__m128)xmmword_5D8F70),
              v11),
            (__m128)xmmword_5D8F50),
          v10);
  v16 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v9, v11), (__m128)xmmword_5D8F80), v11),
                  (__m128)xmmword_5D8F60),
                v11),
              (__m128)xmmword_5D8F40),
            v11),
          (__m128)xmmword_5D8F30);
  v17 = _mm_or_ps(_mm_andnot_ps(v14, v15), _mm_and_ps(v14, v16));
  v18 = _mm_xor_ps(_mm_or_ps(_mm_and_ps(v14, v15), _mm_andnot_ps(v14, v16)), *((__m128 *)&savedregs - 2));
  result = a2;
  *a2 = _mm_xor_ps(v17, v13);
  *a3 = v18;
  return result;
}
