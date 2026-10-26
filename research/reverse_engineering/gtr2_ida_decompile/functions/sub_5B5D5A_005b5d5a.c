__m64 *__stdcall sub_5B5D5A(__m64 *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __m64 *result; // eax

  result = a1;
  _m_femms();
  a1->m64_u64 = 1065353216;
  a1[1].m64_u64 = 0;
  a1[2].m64_u64 = 0x3F80000000000000LL;
  a1[3].m64_u64 = 0;
  a1[4].m64_u64 = 0;
  a1[5].m64_u64 = 1065353216;
  a1[6].m64_u64 = (unsigned __int64)_m_punpckldq(_mm_cvtsi32_si64(a2), _mm_cvtsi32_si64(a3));
  a1[7].m64_u64 = (unsigned __int64)_m_punpckldq(_mm_cvtsi32_si64(a4), (__m64)1065353216LL);
  _m_femms();
  return result;
}
