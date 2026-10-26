__m64 *__stdcall sub_5229B5(__m64 *a1, unsigned int a2)
{
  __m64 *result; // eax
  __m64 v3; // mm4
  __m64 v4; // mm0
  __m64 v5; // mm4

  _m_femms();
  PackedFloatingPointMath();
  result = a1;
  v3 = _mm_cvtsi32_si64(a2);
  v4 = _m_pand(v3, (__m64)0xFFFFFFFFLL);
  v5 = _m_psrlqi(v3, 0x20u);
  a1[2].m64_u64 = 0x3F80000000000000LL;
  a1[3].m64_u64 = 0;
  a1[6].m64_u64 = 0;
  a1[7].m64_u64 = 0x3F80000000000000LL;
  a1[4].m64_u64 = (unsigned __int64)v5;
  a1->m64_u64 = (unsigned __int64)v4;
  a1[5].m64_u64 = (unsigned __int64)v4;
  a1[1].m64_u64 = (unsigned __int64)_m_pxor(v5, (__m64)0x80000000LL);
  _m_femms();
  return result;
}
