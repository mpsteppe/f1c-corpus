__m64 *__stdcall sub_55F005(__m64 *a1, __m64 *a2)
{
  __m64 *result; // eax
  __m64 m64_u64; // mm1
  __m64 v4; // mm2
  __m64 v5; // mm0
  __m64 v6; // mm3
  __m64 v7; // mm4
  __m64 v8; // mm3
  unsigned int v9; // [esp+0h] [ebp-Ch]

  _m_femms();
  result = a1;
  m64_u64 = (__m64)a2->m64_u64;
  v4 = a2[1];
  v5 = _m_punpckhdq(v4, v4);
  if ( !_mm_cvtsi64_si32(_m_pfcmpge(v5, (__m64)0x3F8000003F800000LL)) )
  {
    sub_566740(0, a2);
    v9 = _mm_cvtsi64_si32(v5);
    sub_566E20();
    result = a1;
    m64_u64 = (__m64)a2->m64_u64;
    v4 = a2[1];
    if ( _mm_cvtsi64_si32(_m_pfcmpge(_m_pand(v5, (__m64)0x7FFFFFFF7FFFFFFFLL), (__m64)0x3400000034000000LL)) )
    {
      v6 = _mm_cvtsi32_si64(v9);
      v7 = _m_pfrcp(v5);
      v8 = _m_pfmul(_m_punpckldq(v6, v6), _m_pfrcpit2(_m_pfrcpit1(v5, v7), v7));
      m64_u64 = _m_pfmul(m64_u64, v8);
      v4 = _m_pfmul(v4, v8);
    }
  }
  result->m64_u64 = (unsigned __int64)m64_u64;
  result[1].m64_u64 = (unsigned __int64)_m_pand(v4, (__m64)0xFFFFFFFFLL);
  _m_femms();
  return result;
}
