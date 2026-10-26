__m64 *__stdcall sub_520F69(__m64 *a1, __m64 *a2)
{
  __m64 v2; // mm3
  __m64 v3; // mm0
  __m64 *result; // eax
  __m64 v5; // mm0
  __m64 v6; // mm4
  __m64 v7; // mm5
  __m64 v8; // mm0

  v2 = a2[1];
  v3 = _m_pfadd(_m_pfmul((__m64)a2->m64_u64, (__m64)a2->m64_u64), _m_pfmul(v2, v2));
  result = a1;
  v5 = _m_pfacc(v3, v3);
  v6 = _m_pfrsqrt(v5);
  v7 = _m_pfcmpgt(v5, (__m64)0x80000000800000LL);
  v8 = _m_pfrcpit2(_m_pfrsqit1(v5, _m_pfmul(v6, v6)), v6);
  a1->m64_u64 = (unsigned __int64)_m_pfmul(_m_pand((__m64)a2->m64_u64, v7), v8);
  a1[1].m64_u64 = (unsigned __int64)_m_pfmul(_m_pand(v2, v7), v8);
  _m_femms();
  return result;
}

