__m64 *__userpurge sub_55EC1A@<eax>(__m64 *a1, __m64 a2, __m64 a3)
{
  __m64 v3; // mm1
  __m64 *result; // eax
  __m64 v5; // mm6
  __m64 v6; // mm2
  __m64 v7; // mm6
  __m64 v8; // mm7
  __m64 v9; // [esp+10h] [ebp-10h]

  _m_femms();
  v9 = _m_pfmul((__m64)0x3F0000003F000000LL, a2);
  sub_566D20();
  sub_566D20();
  sub_566D20();
  v3 = _m_pfmul((__m64)0x3F0000003F000000LL, a3);
  result = a1;
  v5 = _m_punpckhdq(v9, v9);
  v6 = _m_punpckldq(v5, v5);
  v7 = _m_punpckhdq(v5, v5);
  v8 = _m_punpckldq(_m_punpckhdq(v3, v3), v3);
  a1->m64_u64 = (unsigned __int64)_m_pfadd(
                                    _m_pfmul(
                                      _m_pfmul(_m_pxor(_m_punpckldq(v9, v9), (__m64)0x8000000000000000uLL), v7),
                                      v3),
                                    _m_pfmul(_m_pfmul(_m_punpckhdq(v9, v9), v6), v8));
  a1[1].m64_u64 = (unsigned __int64)_m_pfadd(
                                      _m_pfmul(_m_pfmul(_m_punpckldq(v9, v9), v6), v8),
                                      _m_pfmul(
                                        _m_pfmul(
                                          _m_pxor(_m_punpckhdq(v9, v9), _m_psrlqi((__m64)0x8000000000000000uLL, 0x20u)),
                                          v7),
                                        v3));
  _m_femms();
  return result;
}
