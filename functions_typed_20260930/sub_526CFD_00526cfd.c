__m64 *__stdcall sub_526CFD(__m64 *a1, __m64 *a2, __m64 *a3)
{
  _m_femms();
  a1->m64_u64 = (unsigned __int64)_m_pfadd(
                                    _m_pfmul(_m_punpckldq((__m64)a2->m64_u64, (__m64)a2->m64_u64), (__m64)a3->m64_u64),
                                    _m_pfmul(_m_punpckhdq((__m64)a2->m64_u64, (__m64)a2->m64_u64), a3[2]));
  _m_femms();
  return a1;
}

