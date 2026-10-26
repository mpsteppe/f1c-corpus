__m64 *__stdcall sub_5600A2(__m64 *a1, unsigned int a2)
{
  __m64 v2; // mm0
  __m64 *result; // eax
  __m64 v4; // mm4

  _m_femms();
  v2 = _mm_cvtsi32_si64(a2);
  sub_566D20();
  result = a1;
  v4 = _m_psrlqi(v2, 0x20u);
  a1->m64_u64 = 1065353216;
  a1[1].m64_u64 = 0;
  a1[2].m64_i32[0] = _mm_cvtsi64_si32(0);
  a1[2].m64_i32[1] = _mm_cvtsi64_si32(v2);
  a1[3].m64_u64 = (unsigned __int64)v4;
  a1[6].m64_u64 = 0;
  a1[7].m64_u64 = 0x3F80000000000000LL;
  a1[4].m64_i32[0] = _mm_cvtsi64_si32(0);
  a1[4].m64_i32[1] = _mm_cvtsi64_si32(_m_pxor(v4, (__m64)0x80000000LL));
  a1[5].m64_i32[0] = _mm_cvtsi64_si32(v2);
  a1[5].m64_i32[1] = _mm_cvtsi64_si32(0);
  _m_femms();
  return result;
}
