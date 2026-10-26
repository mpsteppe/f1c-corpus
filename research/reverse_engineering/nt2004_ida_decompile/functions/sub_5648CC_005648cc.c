__m64 *__stdcall sub_5648CC(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4, unsigned int a5, unsigned int a6)
{
  __m64 v6; // mm6
  __m64 v7; // mm7
  __m64 *result; // eax
  __m64 v9; // mm6
  __m64 v10; // mm7
  __m64 v11; // mm1

  v6 = _mm_cvtsi32_si64(a5);
  v7 = _mm_cvtsi32_si64(a6);
  result = a1;
  v9 = _m_punpckldq(v6, v6);
  v10 = _m_punpckldq(v7, v7);
  v11 = _m_pfadd(_m_pfadd(_m_pfmul(_m_pfsub(a3[1], a2[1]), v9), a2[1]), _m_pfmul(_m_pfsub(a4[1], a2[1]), v10));
  a1->m64_u64 = (unsigned __int64)_m_pfadd(
                                    _m_pfadd(
                                      _m_pfmul(_m_pfsub((__m64)a3->m64_u64, (__m64)a2->m64_u64), v9),
                                      (__m64)a2->m64_u64),
                                    _m_pfmul(_m_pfsub((__m64)a4->m64_u64, (__m64)a2->m64_u64), v10));
  a1[1].m64_u64 = (unsigned __int64)v11;
  _m_femms();
  return result;
}
