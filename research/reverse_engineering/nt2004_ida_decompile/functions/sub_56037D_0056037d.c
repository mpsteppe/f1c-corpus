__m64 *__stdcall sub_56037D(__m64 *a1, __m64 *a2)
{
  __m64 *result; // eax
  __m64 v3; // mm4
  __m64 v4; // mm1
  __m64 v5; // mm5
  __m64 v6; // mm0
  __m64 v7; // mm5
  __m64 v8; // mm2
  __m64 v9; // mm3
  __m64 v10; // mm1
  __m64 v11; // mm6
  __m64 v12; // mm3
  __m64 v13; // mm6
  __m64 v14; // mm2
  __m64 v15; // mm1

  result = a1;
  v3 = a2[1];
  v4 = _m_pfadd(v3, v3);
  v5 = _m_pfadd((__m64)a2->m64_u64, (__m64)a2->m64_u64);
  v6 = _m_pfmul(v5, (__m64)a2->m64_u64);
  v7 = _m_punpckldq(v5, v4);
  v8 = _m_pfmul((__m64)a2->m64_u64, v4);
  v9 = _m_pfmul(_m_pswapd((__m64)a2->m64_u64), v4);
  v10 = _m_pfmul(v4, v3);
  v11 = _m_pfmul(_m_punpckhdq((__m64)a2->m64_u64, v3), v7);
  v12 = _m_pfpnacc(v9, v9);
  v13 = _m_pfpnacc(v11, v11);
  v14 = _m_pfpnacc(v8, v8);
  v15 = _m_pfsub(_m_pfsubr(v6, (__m64)0x3F8000003F800000LL), _m_punpckldq(v10, v10));
  a1[6].m64_u64 = 0;
  a1[4].m64_u64 = (unsigned __int64)_m_punpckldq(_m_pswapd(v14), v12);
  a1[1].m64_u64 = (unsigned __int64)_m_punpckldq(v14, 0);
  a1[5].m64_u64 = (unsigned __int64)_m_punpckhdq(_m_pfsubr(_m_pfacc(v6, v6), (__m64)0x3F8000003F800000LL), 0);
  a1->m64_u64 = (unsigned __int64)_m_punpckhdq(v15, v13);
  a1[2].m64_u64 = (unsigned __int64)_m_punpckldq(v13, v15);
  a1[3].m64_u64 = (unsigned __int64)_m_punpckhdq(v12, 0);
  a1[7].m64_u64 = (unsigned __int64)_m_punpckldq(0, (__m64)1065353216LL);
  _m_femms();
  return result;
}
