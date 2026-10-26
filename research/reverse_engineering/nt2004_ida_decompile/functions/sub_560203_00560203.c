__m64 *__stdcall sub_560203(__m64 *a1, __m64 *a2)
{
  __m64 v2; // mm1
  __m64 v3; // mm4
  __m64 *result; // eax
  __m64 v5; // mm2
  __m64 v6; // mm5
  __m64 v7; // mm7
  __m64 v8; // mm0
  __m64 v9; // mm1
  __m64 v10; // mm4

  v2 = a2[2];
  v3 = a2[7];
  result = a1;
  v5 = _m_punpckhdq((__m64)a2->m64_u64, v2);
  v6 = a2[5];
  a1->m64_u64 = (unsigned __int64)_m_punpckldq((__m64)a2->m64_u64, v2);
  a1[2].m64_u64 = (unsigned __int64)v5;
  v7 = a2[3];
  v8 = a2[4];
  v9 = a2[1];
  a1[5].m64_u64 = (unsigned __int64)_m_punpckldq(v6, v3);
  a1[7].m64_u64 = (unsigned __int64)_m_punpckhdq(v6, v3);
  v10 = a2[6];
  a1[4].m64_u64 = (unsigned __int64)_m_punpckldq(v9, v7);
  a1[6].m64_u64 = (unsigned __int64)_m_punpckhdq(v9, v7);
  a1[3].m64_u64 = (unsigned __int64)_m_punpckhdq(v8, v10);
  a1[1].m64_u64 = (unsigned __int64)_m_punpckldq(v8, v10);
  _m_femms();
  return result;
}
