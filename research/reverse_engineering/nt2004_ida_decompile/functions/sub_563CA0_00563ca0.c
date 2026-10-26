__m64 *__stdcall sub_563CA0(__m64 *a1, __m64 *a2, __m64 *a3)
{
  __m64 m64_u64; // mm1
  __m64 v4; // mm0
  __m64 v5; // mm2
  __m64 v6; // mm4
  __m64 v7; // mm5
  __m64 v8; // mm1
  __m64 v9; // mm3
  __m64 v10; // mm5
  __m64 v11; // mm4
  __m64 v12; // mm5

  _m_femms();
  m64_u64 = (__m64)a2->m64_u64;
  v4 = _m_punpckldq(m64_u64, m64_u64);
  v5 = _mm_cvtsi32_si64(a2[1].m64_u32[0]);
  v6 = _m_punpckhdq(m64_u64, m64_u64);
  v7 = _m_punpckldq(v5, v5);
  v8 = _m_pfadd(_m_pfmul(v6, a3[2]), _m_pfmul(v7, a3[4]));
  v9 = _m_pfadd(_m_pfadd(_m_pfmul(v4, a3[1]), a3[7]), _m_pfadd(_m_pfmul(v6, a3[3]), _m_pfmul(v7, a3[5])));
  v10 = _m_punpckhdq(v9, v9);
  v11 = _m_pfrcp(v10);
  v12 = _m_pfrcpit2(_m_pfrcpit1(v10, v11), v11);
  a1->m64_u64 = (unsigned __int64)_m_pfmul(_m_pfadd(_m_pfadd(_m_pfmul(v4, (__m64)a3->m64_u64), a3[6]), v8), v12);
  a1[1].m64_i32[0] = _mm_cvtsi64_si32(_m_pfmul(v9, v12));
  _m_femms();
  return a1;
}
