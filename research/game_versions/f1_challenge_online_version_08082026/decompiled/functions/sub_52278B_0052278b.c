__m64 *__stdcall sub_52278B(__m64 *a1, __m64 *a2, int a3)
{
  __m64 *result; // eax
  __m64 m64_u64; // mm6
  __m64 v5; // mm7
  __m64 v6; // mm3
  __m64 v7; // mm1
  __m64 v8; // mm0
  __m64 v9; // mm2
  __m64 v10; // mm1
  __m64 v11; // mm3
  __m64 v12; // mm1
  __m64 v13; // mm3
  __m64 v14; // [esp+0h] [ebp-14h] BYREF
  __m64 v15; // [esp+8h] [ebp-Ch]

  _m_femms();
  sub_527578((int)&v14, a3);
  result = a1;
  m64_u64 = (__m64)a2->m64_u64;
  v5 = a2[1];
  v6 = _m_pfmul(v5, v15);
  v7 = _m_pfadd(_m_pfmul((__m64)a2->m64_u64, v14), v6);
  v8 = _m_pxor(v14, (__m64)0x8000000080000000uLL);
  v9 = _m_pxor(v15, (__m64)0x8000000080000000uLL);
  v10 = _m_pfacc(v7, v7);
  v11 = _m_punpckldq(v6, v10);
  v12 = _m_psllqi(v10, 0x20u);
  v13 = _m_psrlqi(v11, 0x20u);
  a1->m64_u64 = (unsigned __int64)_m_pfadd(_m_pfmul(_m_punpckldq(v8, v8), (__m64)a2->m64_u64), v13);
  a1[1].m64_u64 = (unsigned __int64)_m_pfmul(_m_punpckldq(v8, v8), v5);
  a1[2].m64_u64 = (unsigned __int64)_m_pfadd(_m_pfmul(_m_punpckhdq(v8, v8), m64_u64), v12);
  a1[3].m64_u64 = (unsigned __int64)_m_pfmul(_m_punpckhdq(v8, v8), v5);
  a1[4].m64_u64 = (unsigned __int64)_m_pfmul(_m_punpckldq(v9, v9), m64_u64);
  a1[5].m64_u64 = (unsigned __int64)_m_pfadd(_m_pfmul(_m_punpckldq(v9, v9), v5), v13);
  a1[6].m64_u64 = (unsigned __int64)_m_pfmul(_m_punpckhdq(v9, v9), m64_u64);
  a1[7].m64_u64 = (unsigned __int64)_m_pfadd(_m_pfmul(_m_punpckhdq(v9, v9), v5), v12);
  _m_femms();
  return result;
}
