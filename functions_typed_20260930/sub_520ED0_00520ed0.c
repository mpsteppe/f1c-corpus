__m64 *__stdcall sub_520ED0(__m64 *a1, __m64 *a2, __m64 *a3)
{
  __m64 v3; // mm3
  __m64 v4; // mm1
  __m64 *result; // eax
  __m64 v6; // mm6
  __m64 v7; // mm7
  __m64 v8; // mm4
  __m64 v9; // mm6
  __m64 v10; // mm5
  __m64 v11; // mm3

  v3 = a3[1];
  v4 = a2[1];
  result = a1;
  v6 = _m_punpckldq(_m_punpckhdq((__m64)a3->m64_u64, (__m64)a3->m64_u64), (__m64)a3->m64_u64);
  v7 = _m_punpckldq(_m_punpckhdq(v3, v3), v3);
  v8 = _m_pfacc(
         _m_pfsub(_m_pfmul(v6, v4), _m_pfmul(_m_pxor(v7, (__m64)0x80000000LL), (__m64)a2->m64_u64)),
         _m_pfadd(_m_pxor(_m_pfmul((__m64)a3->m64_u64, v4), (__m64)0x80000000LL), _m_pfmul(v3, (__m64)a2->m64_u64)));
  v9 = _m_pfmul(_m_pxor(v6, (__m64)0x80000000LL), (__m64)a2->m64_u64);
  v10 = _m_pxor(v3, (__m64)0x80000000LL);
  v11 = _m_pfmul((__m64)a3->m64_u64, (__m64)a2->m64_u64);
  a1->m64_u64 = (unsigned __int64)v8;
  a1[1].m64_u64 = (unsigned __int64)_m_pfacc(_m_pfadd(v9, _m_pfmul(v7, v4)), _m_pfsub(_m_pfmul(v10, v4), v11));
  _m_femms();
  return result;
}

