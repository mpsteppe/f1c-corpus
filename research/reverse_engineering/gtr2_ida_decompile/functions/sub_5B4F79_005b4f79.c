__m64 *__userpurge sub_5B4F79@<eax>(unsigned int a1@<esi>, __m64 *a2, __m64 *a3)
{
  __m64 v3; // mm1
  __m64 v4; // mm0
  __m64 v5; // mm0
  __m64 v6; // mm2
  __m64 v7; // mm1
  __m64 v8; // mm1
  __m64 v9; // mm0
  __m64 *result; // eax
  char v11; // cl
  __m64 m64_u64; // mm2
  __m64 v13; // mm0
  __m64 v14; // mm1
  __m64 v15; // mm3
  __m64 v16; // mm1
  __m64 v17; // [esp+0h] [ebp-Ch]

  v3 = _mm_cvtsi32_si64(a3[1].m64_u32[0]);
  v4 = _m_pfadd(_m_pfmul((__m64)a3->m64_u64, (__m64)a3->m64_u64), _m_pfmul(v3, v3));
  v5 = _m_pfacc(v4, v4);
  v6 = _m_pfrsqrt(v5);
  v7 = _m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v6, v6), v5), v6);
  v17.m64_u64 = __PAIR64__(a1, _mm_cvtsi64_si32(v7));
  sub_5BBB20();
  v8 = _m_pfmul(v5, v7);
  v9 = _m_pfcmpge(_m_pand(v8, (__m64)0x7FFFFFFFFFFFFFFFLL), (__m64)0x3400000034000000LL);
  result = a2;
  v11 = _mm_cvtsi64_si32(_m_punpckhdq(v9, v9));
  m64_u64 = (__m64)a3->m64_u64;
  v13 = v8;
  v14 = _m_pfmul(_m_punpckhdq(v8, v8), v17);
  v15 = _mm_cvtsi32_si64(a3[1].m64_u32[0]);
  if ( (v11 & 1) != 0 )
  {
    v16 = _m_punpckldq(v14, v14);
    v15 = _m_pfmul(v15, v16);
    m64_u64 = _m_pfmul(m64_u64, v16);
  }
  a2->m64_u64 = (unsigned __int64)m64_u64;
  a2[1].m64_u64 = (unsigned __int64)_m_punpckldq(v15, v13);
  _m_femms();
  return result;
}
