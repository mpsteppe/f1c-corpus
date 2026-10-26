__m64 *__stdcall sub_526CA8(__m64 *a1, __m64 *a2, __m64 *a3)
{
  __m64 m64_u64; // mm1
  __m64 v4; // mm0
  __m64 v5; // mm4
  __m64 v6; // mm3

  _m_femms();
  m64_u64 = (__m64)a2->m64_u64;
  v4 = _m_punpckldq(m64_u64, m64_u64);
  v5 = _m_punpckhdq(m64_u64, m64_u64);
  v6 = _m_pfadd(_m_pfadd(_m_pfmul(v4, a3[1]), a3[7]), _m_pfmul(v5, a3[3]));
  a1->m64_u64 = (unsigned __int64)_m_pfadd(_m_pfadd(_m_pfmul(v4, (__m64)a3->m64_u64), a3[6]), _m_pfmul(v5, a3[2]));
  a1[1].m64_u64 = (unsigned __int64)v6;
  _m_femms();
  return a1;
}
