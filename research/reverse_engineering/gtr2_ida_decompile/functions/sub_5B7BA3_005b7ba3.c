__m64 *__stdcall sub_5B7BA3(__m64 *a1, __m64 *a2, unsigned int a3)
{
  __m64 v3; // mm1
  __m64 v4; // mm1
  __m64 v5; // mm0
  __m64 v6; // mm7
  __m64 v7; // mm3
  __m64 v8; // mm0
  __m64 v9; // mm1
  __m64 v10; // mm2
  __m64 *result; // eax
  __m64 v12; // mm3
  __m64 v13; // mm4
  __m64 v14; // mm5
  __m64 v15; // mm1
  __m64 v16; // mm1
  __m64 v17; // mm6
  __m64 v18; // mm7
  __m64 v19; // mm1
  __m64 v20; // mm6
  __m64 v21; // mm2
  __m64 v22; // mm1
  unsigned __int64 m64_u64; // [esp+0h] [ebp-18h] BYREF
  unsigned int v24; // [esp+8h] [ebp-10h]
  unsigned int v25; // [esp+Ch] [ebp-Ch]

  v3 = _mm_cvtsi32_si64(a2[1].m64_u32[0]);
  m64_u64 = a2->m64_u64;
  v24 = _mm_cvtsi64_si32(v3);
  sub_5B9980((int)&m64_u64, (int)&m64_u64);
  sub_5BBB20();
  v4 = _mm_cvtsi32_si64(a3);
  v5 = _m_pfsubr(v4, (__m64)0x3F8000003F800000LL);
  v25 = _mm_cvtsi64_si32(_m_punpckhdq(v4, v4));
  v6 = _mm_cvtsi32_si64(v24);
  v7 = _m_punpckldq(v6, v6);
  v8 = _m_punpckldq(v5, v5);
  v9 = _m_punpckldq(v4, v4);
  v10 = _m_pfmul(_m_pfmul(_m_punpckhdq((__m64)m64_u64, v7), (__m64)m64_u64), v8);
  result = a1;
  v12 = _m_pfmul(_m_pfmul(v7, (__m64)m64_u64), v8);
  v13 = _m_pfadd(_m_pfmul(_m_pfmul((__m64)m64_u64, (__m64)m64_u64), v8), v9);
  v14 = _m_pfadd(_m_pfmul(_m_pfmul(v6, v6), v8), v9);
  v15 = _mm_cvtsi32_si64(v25);
  v16 = _m_punpckldq(v15, v15);
  v17 = _m_pfmul((__m64)m64_u64, v16);
  a1[6].m64_u64 = 0;
  v18 = _m_punpckldq(_m_pfmul(v6, v16), v17);
  v19 = v10;
  v20 = _m_punpckhdq(v17, v17);
  a1[5].m64_u64 = (unsigned __int64)_m_punpckldq(v14, 0);
  v21 = _m_pfsub(v10, v18);
  v22 = _m_pfadd(v19, v18);
  a1->m64_u64 = (unsigned __int64)_m_punpckldq(v13, v22);
  a1[1].m64_u64 = (unsigned __int64)_m_punpckldq(_m_pfsub(v12, v20), 0);
  a1[3].m64_u64 = (unsigned __int64)_m_punpckhdq(v22, 0);
  a1[7].m64_u64 = (unsigned __int64)_m_punpckhdq(0, (__m64)0x3F8000003F800000LL);
  a1[4].m64_u64 = (unsigned __int64)_m_punpckhdq(_m_pfadd(_m_punpckldq(v12, v12), v20), v21);
  a1[2].m64_u64 = (unsigned __int64)_m_punpckldq(v21, _m_punpckhdq(v13, v13));
  _m_femms();
  return result;
}
