__m64 *__cdecl sub_522B22(__m64 *a1)
{
  __m64 v1; // mm1
  __m64 *result; // eax
  __m64 v3; // mm2

  v1 = _mm_cvtsi32_si64(0x3F800000u);
  result = a1;
  a1->m64_u64 = (unsigned __int64)v1;
  a1[1].m64_u64 = 0;
  a1[3].m64_u64 = 0;
  a1[4].m64_u64 = 0;
  a1[5].m64_u64 = (unsigned __int64)v1;
  v3 = _m_punpckldq(_m_punpckhdq(v1, v1), v1);
  a1[6].m64_u64 = 0;
  a1[2].m64_u64 = (unsigned __int64)v3;
  a1[7].m64_u64 = (unsigned __int64)v3;
  _m_femms();
  return result;
}

