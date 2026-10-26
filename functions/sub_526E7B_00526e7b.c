__m64 *__stdcall sub_526E7B(__m64 *a1, __m64 *a2)
{
  __m64 v2; // mm0
  __m64 *result; // eax
  __m64 v4; // mm0
  __m64 v5; // mm5

  v2 = _m_pfmul((__m64)a2->m64_u64, (__m64)a2->m64_u64);
  result = a1;
  v4 = _m_pfacc(v2, v2);
  v5 = _m_pfrsqrt(v4);
  a1->m64_u64 = (unsigned __int64)_m_pfmul(
                                    _m_pand((__m64)a2->m64_u64, _m_pfcmpgt(v4, (__m64)0x80000000800000LL)),
                                    _m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v5, v5), v4), v5));
  _m_femms();
  return result;
}
