__m64 *__userpurge sub_523E7A@<eax>(__m64 *a1, __m64 a2, __m64 a3)
{
  __m64 v3; // mm0
  __m64 v4; // mm6
  __m64 v5; // mm2
  __m64 v6; // mm6
  __m64 v7; // mm7
  __m64 *result; // eax
  __m64 v9; // mm3
  __m64 v10; // mm0
  __m64 v11; // mm7
  __m64 v12; // mm2
  __m64 v13; // mm4
  __m64 v14; // mm3
  __m64 v15; // mm1
  __m64 v16; // mm5
  __m64 v17; // mm7
  __m64 v18; // mm6
  __m64 v19; // mm2
  __m64 v20; // mm1
  __m64 v21; // mm6
  __m64 v22; // mm7
  __m64 v23; // mm3
  __m64 v24; // mm2
  __m64 v25; // mm3
  __m64 v26; // mm5
  __m64 v27; // mm6
  __m64 v28; // [esp+8h] [ebp-28h]
  __m64 v29; // [esp+28h] [ebp-8h]

  sub_5295E0();
  v28 = _m_pfmul((__m64)0x3F0000003F000000LL, a3);
  sub_5295E0();
  v3 = _m_pfmul((__m64)0x3F0000003F000000LL, a2);
  sub_5295E0();
  v4 = _m_punpckhdq(v3, v3);
  v5 = _m_punpckldq(v4, v4);
  v6 = _m_punpckhdq(v4, v4);
  v7 = _m_punpckldq(_m_punpckhdq(v28, v28), v28);
  v29 = _m_pfadd(
          _m_pfmul(_m_pfmul(_m_punpckldq(v3, v3), v5), v7),
          _m_pfmul(_m_pfmul(_m_pxor(_m_punpckhdq(v3, v3), _m_psrlqi((__m64)0x8000000000000000uLL, 0x20u)), v6), v28));
  result = a1;
  v9 = _m_pfadd(
         _m_pfmul(_m_pfmul(_m_pxor(_m_punpckldq(v3, v3), (__m64)0x8000000000000000uLL), v6), v28),
         _m_pfmul(_m_pfmul(_m_punpckhdq(v3, v3), v5), v7));
  v10 = _m_pfadd(v9, v9);
  v11 = v29;
  v12 = _m_punpckhdq(v9, v9);
  v13 = _m_punpckhdq(v11, v11);
  v14 = _m_pfmul(v9, v10);
  v15 = _m_punpckldq(_m_pfadd(v11, v11), v10);
  v16 = _m_pfmul(v10, v13);
  v17 = _m_pfmul(_m_punpckldq(v11, v11), v15);
  v18 = _m_pfmul(v15, v13);
  v19 = _m_pfmul(v15, v12);
  v20 = _m_punpckhdq(v19, v17);
  a1[6].m64_u64 = 0;
  v21 = _m_punpckhdq(_m_punpckldq(v18, v18), v16);
  v22 = _m_pfsubr(_m_pfadd(_m_punpckldq(v17, v17), v14), (__m64)0x3F8000003F800000LL);
  a1[5].m64_u64 = (unsigned __int64)_m_punpckldq(_m_pfsubr(_m_pfacc(v14, v14), (__m64)0x3F8000003F800000LL), 0);
  v23 = v19;
  v24 = _m_pfadd(v19, v16);
  v25 = _m_pfsub(v23, v16);
  v26 = _m_pfsub(v20, v21);
  v27 = _m_pfadd(v20, v21);
  a1[3].m64_u64 = (unsigned __int64)_m_punpckldq(v24, 0);
  a1[1].m64_u64 = (unsigned __int64)_m_punpckhdq(v26, 0);
  a1[2].m64_u64 = (unsigned __int64)_m_punpckldq(v26, v22);
  a1->m64_u64 = (unsigned __int64)_m_punpckhdq(v22, _m_punpckldq(v27, v27));
  a1[4].m64_u64 = (unsigned __int64)_m_punpckldq(_m_punpckhdq(v27, v27), v25);
  a1[7].m64_u64 = (unsigned __int64)_m_punpckldq(0, (__m64)1065353216LL);
  _m_femms();
  return result;
}
