__m64 *__stdcall sub_526D9A(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4, __m64 *a5, unsigned int a6)
{
  __m64 v6; // mm0
  __m64 v7; // mm1
  __m64 v8; // mm2
  __m64 v9; // mm7
  __m64 v10; // mm4
  __m64 v11; // mm6
  __m64 v12; // mm2
  __m64 v13; // mm5
  __m64 v14; // mm1
  __m64 v15; // mm6
  __m64 v16; // mm2
  __m64 *result; // eax

  _m_femms();
  v6 = _mm_cvtsi32_si64(a6);
  v7 = _m_pfmul(v6, v6);
  v8 = _m_pfmul(v7, v6);
  v9 = _m_pfsub(v8, v7);
  v10 = _m_pfmul(v7, (__m64)0x4000000040000000LL);
  v11 = v8;
  v12 = _m_pfmul(v8, (__m64)0x4000000040000000LL);
  v13 = _m_pfmul(v7, (__m64)0x4040000040400000LL);
  v14 = _m_pfsub(v13, v12);
  v15 = _m_pfadd(_m_pfsub(v11, v10), v6);
  v16 = _m_pfadd(_m_pfsub(v12, v13), (__m64)0x3F8000003F800000LL);
  result = a1;
  a1->m64_u64 = (unsigned __int64)_m_pfadd(
                                    _m_pfadd(
                                      _m_pfmul(_m_punpckldq(v16, v16), (__m64)a2->m64_u64),
                                      _m_pfmul(_m_punpckldq(v15, v15), (__m64)a3->m64_u64)),
                                    _m_pfadd(
                                      _m_pfmul(_m_punpckldq(v14, v14), (__m64)a4->m64_u64),
                                      _m_pfmul(_m_punpckldq(v9, v9), (__m64)a5->m64_u64)));
  _m_femms();
  return result;
}
