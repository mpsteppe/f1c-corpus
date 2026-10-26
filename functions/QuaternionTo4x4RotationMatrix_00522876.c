__m64 *__stdcall sub_522876(__m64 *a1, int a2)
{
  __m64 *result; // eax
  __m64 v3; // mm3
  __m64 v4; // mm0
  __m64 v5; // mm1
  __m64 v6; // mm6
  __m64 v7; // mm4
  __m64 v8; // mm6
  __m64 v9; // mm4
  __m64 v10; // mm6
  __m64 v11; // [esp+0h] [ebp-14h] BYREF
  __m64 v12; // [esp+8h] [ebp-Ch]

  _m_femms();
  F_3DVectorNormalize_7578((int)&v11, a2);
  result = a1;
  v3 = v12;
  v4 = _m_pfmul(v11, (__m64)0xC0000000C0000000uLL);
  v5 = _m_pfmul(v12, (__m64)0x3F800000C0000000LL);
  v6 = v11;
  v7 = _m_punpckldq(v6, v6);
  v8 = _m_punpckhdq(v6, v6);
  a1->m64_u64 = (unsigned __int64)_m_pfadd(_m_pfmul(v7, v4), (__m64)1065353216LL);
  a1[1].m64_u64 = (unsigned __int64)_m_pfmul(_m_psrlqi(v7, 0x20u), v5);
  a1[2].m64_u64 = (unsigned __int64)_m_pfadd(_m_pfmul(v8, v4), (__m64)0x3F80000000000000LL);
  a1[3].m64_u64 = (unsigned __int64)_m_pfmul(_m_psrlqi(v8, 0x20u), v5);
  v9 = _m_punpckldq(v3, v3);
  v10 = _m_punpckhdq(v3, v3);
  a1[4].m64_u64 = (unsigned __int64)_m_pfmul(v9, v4);
  a1[5].m64_u64 = (unsigned __int64)_m_pfadd(_m_pfmul(_m_psrlqi(v9, 0x20u), v5), (__m64)1065353216LL);
  a1[6].m64_u64 = (unsigned __int64)_m_pfmul(v10, v4);
  a1[7].m64_u64 = (unsigned __int64)_m_pfadd(_m_pfmul(_m_psrlqi(v10, 0x20u), v5), (__m64)0x3F80000000000000LL);
  _m_femms();
  return result;
}
