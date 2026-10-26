__m64 *__stdcall sub_5273D6(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4)
{
  __m64 v4; // mm2
  __m64 v5; // mm1
  __m64 v6; // mm4
  __m64 v7; // mm7
  __m64 v8; // mm5
  __m64 v9; // mm0
  __m64 v10; // mm1
  __m64 v11; // mm1
  __m64 v12; // mm7
  __m64 v13; // mm6
  __m64 v14; // mm6
  __m64 v15; // mm4
  __m64 v16; // mm5
  __m64 v17; // mm6
  __m64 *result; // eax
  __m64 v19; // mm4
  __m64 v20; // mm5
  __m64 v21; // mm0

  _m_femms();
  v4 = _mm_cvtsi32_si64(a2[1].m64_u32[0]);
  v5 = _m_pfsub(_m_punpckldq(v4, v4), _m_punpckldq(_mm_cvtsi32_si64(a4[1].m64_u32[0]), (__m64)a3[1].m64_u32[0]));
  v6 = _m_pfsub((__m64)a2->m64_u64, (__m64)a4->m64_u64);
  v7 = _m_pfsub(0, v6);
  v8 = _m_pfsub((__m64)a2->m64_u64, (__m64)a3->m64_u64);
  v9 = _m_pxor(
         _m_pfacc(
           _m_pfmul(_m_punpckhdq(v8, v7), v5),
           _m_pfmul(_m_punpckldq(_m_punpckhdq(v5, (__m64)0x8000000000000000uLL), v8), _m_punpckldq(v7, v5))),
         (__m64)0x8000000000000000uLL);
  v10 = _m_pfmul(_m_punpckhdq(v6, _m_punpckldq(v6, v7)), v8);
  v11 = _m_pfacc(v10, v10);
  v12 = _m_psllqi(v11, 0x20u);
  v13 = _m_pfadd(_m_pfmul(v9, v9), _m_pfmul(v12, v12));
  v14 = _m_pfacc(v13, v13);
  v15 = _m_pfrsqrt(v14);
  v16 = _m_pfcmpgt(v14, (__m64)0x80000000800000LL);
  v17 = _m_pfrcpit2(_m_pfrsqit1(v14, _m_pfmul(v15, v15)), v15);
  result = a1;
  v19 = _m_pfmul(_m_pand(v9, v16), v17);
  v20 = _m_pfmul(_m_pand(v11, v16), v17);
  v21 = _m_pfmul(v19, (__m64)a2->m64_u64);
  a1->m64_u64 = (unsigned __int64)v19;
  a1[1].m64_u64 = (unsigned __int64)_m_pxor(
                                      _m_punpckldq(v20, _m_pfadd(_m_pfacc(v21, v21), _m_pfmul(v20, v4))),
                                      (__m64)0x8000000000000000uLL);
  _m_femms();
  return result;
}
