__m64 *__stdcall sub_5215DB(__m64 *a1, __m64 *a2, __m64 *a3, unsigned int a4)
{
  __m64 v4; // mm1
  __m64 v5; // mm4
  __m64 v6; // mm0
  __m64 v7; // mm1
  __m64 v8; // mm7
  __m64 v9; // mm1
  __m64 v10; // mm3
  __m64 v11; // mm4
  __m64 v12; // mm0
  __m64 v13; // mm1
  __m64 *result; // eax
  __m64 v15; // mm4
  __m64 v16; // mm5
  __m64 v17; // mm6
  __m64 v18; // mm0
  __m64 v19; // mm5
  unsigned int v20; // [esp+28h] [ebp+10h]

  _m_femms();
  v4 = _m_pfadd(_m_pfmul((__m64)a2->m64_u64, (__m64)a3->m64_u64), _m_pfmul(a2[1], a3[1]));
  v5 = _mm_cvtsi32_si64(a4);
  v6 = _m_pfsub(_mm_cvtsi32_si64(0x3F800000u), v5);
  v7 = _m_pfacc(v4, v4);
  v8 = _m_pand(_m_pfcmpge(0, v7), (__m64)0x8000000080000000uLL);
  v9 = _m_pxor(v7, v8);
  v10 = _m_pfsubr(_m_pfmul(v9, v9), (__m64)0x3F8000003F800000LL);
  if ( _mm_cvtsi64_si32(_m_pfcmpge((__m64)0x3F7FFF583F7FFF58LL, v9)) )
  {
    v11 = _m_pfrsqrt(v10);
    sub_528F00();
    sub_529700();
    v20 = _mm_cvtsi64_si32(_m_pfmul(v9, _mm_cvtsi32_si64(a4)));
    v12 = _m_pfmul(_mm_cvtsi32_si64(_mm_cvtsi64_si32(v9)), _mm_cvtsi32_si64(_mm_cvtsi64_si32(v6)));
    sub_529700();
    v13 = _mm_cvtsi32_si64(_mm_cvtsi64_si32(_m_pfrcpit2(_m_pfrsqit1(v10, _m_pfmul(v11, v11)), v11)));
    v8 = _mm_cvtsi32_si64(_mm_cvtsi64_si32(v8));
    v6 = _m_pfmul(v12, v13);
    v5 = _m_pfmul(_mm_cvtsi32_si64(v20), v13);
  }
  result = a1;
  v15 = _m_pxor(v5, v8);
  v16 = _m_punpckldq(v6, v6);
  v17 = _m_punpckldq(v15, v15);
  v18 = _m_pfmul(v16, (__m64)a2->m64_u64);
  v19 = _m_pfadd(_m_pfmul(v16, a2[1]), _m_pfmul(v17, a3[1]));
  a1->m64_u64 = (unsigned __int64)_m_pfadd(v18, _m_pfmul(v17, (__m64)a3->m64_u64));
  a1[1].m64_u64 = (unsigned __int64)v19;
  _m_femms();
  return result;
}
