__m64 *__stdcall sub_5BAA25(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4)
{
  __m64 *result; // eax
  __m64 v5; // mm2
  __m64 v6; // mm3
  __m64 v7; // mm4
  __m64 v8; // mm5
  __m64 v9; // mm6
  __m64 v10; // mm1
  __m64 m64_u64; // mm0
  __m64 v12; // mm7
  __m64 v13; // mm2
  __m64 v14; // mm6
  __m64 v15; // mm7

  _m_femms();
  result = a1;
  v5 = a3[1];
  v6 = a4[1];
  v7 = _m_pfsub(
         _m_pfmul(_m_punpckhdq(v6, v6), _m_punpckhdq(_m_punpckldq(v5, v5), (__m64)a3->m64_u64)),
         _m_pfmul(_m_punpckhdq(v5, v5), _m_punpckhdq(_m_punpckldq(v6, v6), (__m64)a4->m64_u64)));
  v8 = _m_pfsub(
         _m_pfmul(_m_punpckhdq((__m64)a3->m64_u64, v5), _m_punpckldq(v6, (__m64)a4->m64_u64)),
         _m_pfmul(_m_punpckhdq((__m64)a4->m64_u64, v6), _m_punpckldq(v5, (__m64)a3->m64_u64)));
  v9 = _m_pfsub(
         _m_pfmul(
           _m_punpckldq((__m64)a4->m64_u64, (__m64)a4->m64_u64),
           _m_punpckhdq(_m_punpckldq(v5, v5), (__m64)a3->m64_u64)),
         _m_pfmul(
           _m_punpckldq((__m64)a3->m64_u64, (__m64)a3->m64_u64),
           _m_punpckhdq(_m_punpckldq(v6, v6), (__m64)a4->m64_u64)));
  v10 = a2[1];
  m64_u64 = (__m64)a2->m64_u64;
  a1->m64_u64 = (unsigned __int64)_m_pfsub(
                                    _m_pfmul(
                                      _m_pxor(_m_punpckldq(v7, v7), (__m64)0x8000000000000000uLL),
                                      _m_punpckhdq(
                                        (__m64)a2->m64_u64,
                                        _m_punpckldq((__m64)a2->m64_u64, (__m64)a2->m64_u64))),
                                    _m_pfacc(
                                      _m_pxor(
                                        _m_pfmul(_m_punpckldq(_m_punpckhdq(v7, v7), v8), v10),
                                        (__m64)0x8000000000000000uLL),
                                      _m_pxor(
                                        _m_pfmul(_m_punpckldq(_m_punpckhdq(v8, v8), v9), v10),
                                        (__m64)0x8000000000000000uLL)));
  v12 = _m_psrlqi((__m64)0x8000000000000000uLL, 0x20u);
  v13 = _m_pxor(_m_punpckldq(v8, v9), v12);
  v14 = _m_pxor(_m_punpckhdq(v9, v9), v12);
  v15 = _m_psllqi(v12, 0x20u);
  a1[1].m64_u64 = (unsigned __int64)_m_pfadd(
                                      _m_pfmul(_m_punpckhdq(v10, _m_punpckldq(v10, v10)), v14),
                                      _m_pfacc(
                                        _m_pxor(
                                          _m_pfmul(_m_pxor(_m_punpckhdq(v7, v8), (__m64)0x8000000000000000uLL), m64_u64),
                                          v15),
                                        _m_pxor(_m_pfmul(v13, m64_u64), v15)));
  _m_femms();
  return result;
}
