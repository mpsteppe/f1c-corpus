__m64 *__stdcall sub_522B5B(__m64 *a1, __m64 *a2)
{
  __m64 *result; // eax
  __m64 m64_u64; // mm3
  __m64 v4; // mm0
  __m64 v5; // mm7
  __m64 v6; // mm2
  __m64 v7; // mm4
  __m64 v8; // mm3
  __m64 v9; // mm1
  __m64 v10; // mm5
  __m64 v11; // mm7
  __m64 v12; // mm6
  __m64 v13; // mm2
  __m64 v14; // mm1
  __m64 v15; // mm6
  __m64 v16; // mm7
  __m64 v17; // mm3
  __m64 v18; // mm2
  __m64 v19; // mm3
  __m64 v20; // mm5
  __m64 v21; // mm6

  result = a1;
  m64_u64 = (__m64)a2->m64_u64;
  v4 = _m_pfadd(m64_u64, m64_u64);
  v5 = a2[1];
  v6 = _m_punpckhdq(m64_u64, m64_u64);
  v7 = _m_punpckhdq(v5, v5);
  v8 = _m_pfmul((__m64)a2->m64_u64, v4);
  v9 = _m_punpckldq(_m_pfadd(v5, v5), v4);
  v10 = _m_pfmul(v4, v7);
  v11 = _m_pfmul(_m_punpckldq(v5, v5), v9);
  v12 = _m_pfmul(v9, v7);
  v13 = _m_pfmul(v9, v6);
  v14 = _m_punpckhdq(v13, v11);
  a1[6].m64_u64 = 0;
  v15 = _m_punpckhdq(_m_punpckldq(v12, v12), v10);
  v16 = _m_pfsubr(_m_pfadd(_m_punpckldq(v11, v11), v8), (__m64)0x3F8000003F800000LL);
  a1[5].m64_u64 = (unsigned __int64)_m_punpckldq(_m_pfsubr(_m_pfacc(v8, v8), (__m64)0x3F8000003F800000LL), 0);
  v17 = v13;
  v18 = _m_pfadd(v13, v10);
  v19 = _m_pfsub(v17, v10);
  v20 = _m_pfsub(v14, v15);
  v21 = _m_pfadd(v14, v15);
  a1[3].m64_u64 = (unsigned __int64)_m_punpckldq(v18, 0);
  a1[1].m64_u64 = (unsigned __int64)_m_punpckhdq(v20, 0);
  a1[2].m64_u64 = (unsigned __int64)_m_punpckldq(v20, v16);
  a1->m64_u64 = (unsigned __int64)_m_punpckhdq(v16, _m_punpckldq(v21, v21));
  a1[4].m64_u64 = (unsigned __int64)_m_punpckldq(_m_punpckhdq(v21, v21), v19);
  a1[7].m64_u64 = (unsigned __int64)_m_punpckldq(0, (__m64)1065353216LL);
  _m_femms();
  return result;
}

