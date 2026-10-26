// f1c  0x00521831  size=100
__m64 *__stdcall sub_521831(__m64 *a1, __m64 *a2)
{
  __m64 v2; // mm3
  __m64 v3; // mm0
  __m64 v4; // mm0
  __m64 *result; // eax
  __m64 v6; // mm4
  __m64 v7; // mm5
  __m64 v8; // mm0

  v2 = a2[1];
  v3 = _m_pfadd(_m_pfmul((__m64)a2->m64_u64, (__m64)a2->m64_u64), _m_pfmul(v2, v2));
  v4 = _m_pfacc(v3, v3);
  result = a1;
  v6 = _m_pfrcp(v4);
  v7 = _m_pfcmpgt(v4, (__m64)0x80000000800000LL);
  v8 = _m_pfrcpit2(_m_pfrcpit1(v4, v6), v6);
  a1->m64_u64 = (unsigned __int64)_m_pfmul(_m_pand(_m_pxor((__m64)a2->m64_u64, (__m64)0x8000000080000000uLL), v7), v8);
  a1[1].m64_u64 = (unsigned __int64)_m_pfmul(_m_pand(_m_pxor(v2, (__m64)0x80000000LL), v7), v8);
  _m_femms();
  return result;
}
