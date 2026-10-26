// f1c  0x005275dc  size=126
__m64 *__stdcall sub_5275DC(__m64 *a1, __m64 *a2, __m64 *a3)
{
  __m64 m64_u64; // mm1
  __m64 v4; // mm0
  __m64 v5; // mm3
  __m64 v6; // mm5
  __m64 v7; // mm6
  __m64 v8; // mm7
  __m64 *result; // eax
  __m64 v10; // mm4

  _m_femms();
  m64_u64 = (__m64)a2->m64_u64;
  v4 = _m_punpckldq(m64_u64, m64_u64);
  v5 = a2[1];
  v6 = _m_punpckhdq(m64_u64, m64_u64);
  v7 = _m_punpckldq(v5, v5);
  v8 = _m_punpckhdq(v5, v5);
  result = a1;
  v10 = _m_pfadd(_m_pfadd(_m_pfmul(v4, a3[1]), _m_pfmul(v6, a3[3])), _m_pfadd(_m_pfmul(v7, a3[5]), _m_pfmul(v8, a3[7])));
  a1->m64_u64 = (unsigned __int64)_m_pfadd(
                                    _m_pfadd(_m_pfmul(v4, (__m64)a3->m64_u64), _m_pfmul(v6, a3[2])),
                                    _m_pfadd(_m_pfmul(v7, a3[4]), _m_pfmul(v8, a3[6])));
  a1[1].m64_u64 = (unsigned __int64)v10;
  _m_femms();
  return result;
}
