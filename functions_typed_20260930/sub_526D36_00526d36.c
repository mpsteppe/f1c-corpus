__m64 *__stdcall sub_526D36(__m64 *a1, __m64 *a2, __m64 *a3)
{
  __m64 m64_u64; // mm1
  __m64 v4; // mm0
  __m64 v5; // mm4
  __m64 v6; // mm1
  __m64 v7; // mm3
  __m64 v8; // mm3
  __m64 v9; // mm4

  _m_femms();
  m64_u64 = (__m64)a2->m64_u64;
  v4 = _m_punpckldq(m64_u64, m64_u64);
  v5 = _m_punpckhdq(m64_u64, m64_u64);
  v6 = _m_pfmul(v5, a3[2]);
  v7 = _m_pfadd(_m_pfadd(_m_pfmul(v4, a3[1]), a3[7]), _m_pfmul(v5, a3[3]));
  v8 = _m_punpckhdq(v7, v7);
  v9 = _m_pfrcp(v8);
  a1->m64_u64 = (unsigned __int64)_m_pfmul(
                                    _m_pfadd(_m_pfadd(_m_pfmul(v4, (__m64)a3->m64_u64), a3[6]), v6),
                                    _m_pfrcpit2(_m_pfrcpit1(v8, v9), v9));
  _m_femms();
  return a1;
}

