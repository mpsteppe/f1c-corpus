__m64 *__stdcall sub_5BA80B(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4, unsigned int a5, unsigned int a6)
{
  __m64 v6; // mm6
  __m64 v7; // mm7
  __m64 *result; // eax

  v6 = _mm_cvtsi32_si64(a5);
  v7 = _mm_cvtsi32_si64(a6);
  result = a1;
  a1->m64_u64 = (unsigned __int64)_m_pfadd(
                                    _m_pfadd(
                                      (__m64)a2->m64_u64,
                                      _m_pfmul(_m_pfsub((__m64)a3->m64_u64, (__m64)a2->m64_u64), _m_punpckldq(v6, v6))),
                                    _m_pfmul(_m_pfsub((__m64)a4->m64_u64, (__m64)a2->m64_u64), _m_punpckldq(v7, v7)));
  _m_femms();
  return result;
}
