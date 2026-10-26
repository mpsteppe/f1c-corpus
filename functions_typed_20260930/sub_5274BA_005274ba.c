__m64 *__stdcall sub_5274BA(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4)
{
  __m64 v4; // mm7
  __m64 v5; // mm4
  __m64 v6; // mm7
  __m64 v7; // mm4
  __m64 v8; // mm5
  __m64 *result; // eax
  __m64 v10; // mm2
  __m64 v11; // mm2
  __m64 v12; // mm2
  __m64 v13; // mm5

  v4 = _mm_cvtsi32_si64(a3[1].m64_u32[0]);
  v5 = _m_pfsub(
         _m_pfadd(_m_pfmul((__m64)a2->m64_u64, (__m64)a3->m64_u64), _m_pfmul(a2[1], v4)),
         _m_pfadd(_m_pfmul((__m64)a2->m64_u64, (__m64)a4->m64_u64), _m_pfmul(a2[1], _mm_cvtsi32_si64(a4[1].m64_u32[0]))));
  v6 = _m_punpckldq(v4, (__m64)1065353216LL);
  v7 = _m_pfacc(v5, v5);
  v8 = _m_pfrcp(v7);
  result = a1;
  v10 = _m_pfmul((__m64)a2->m64_u64, (__m64)a3->m64_u64);
  if ( _mm_cvtsi64_si32(_m_pfcmpeq(0, v7)) )
  {
    result = 0;
  }
  else
  {
    v11 = _m_pfadd(v10, _m_pfmul(a2[1], v6));
    v12 = _m_pfmul(_m_pfacc(v11, v11), _m_pfrcpit2(_m_pfrcpit1(v7, v8), v8));
    v13 = _m_pfadd(_m_pfmul(_m_pfsub(_mm_cvtsi32_si64(a4[1].m64_u32[0]), v6), v12), v6);
    a1->m64_u64 = (unsigned __int64)_m_pfadd(
                                      _m_pfmul(_m_pfsub((__m64)a4->m64_u64, (__m64)a3->m64_u64), v12),
                                      (__m64)a3->m64_u64);
    a1[1].m64_i32[0] = _mm_cvtsi64_si32(v13);
  }
  _m_femms();
  return result;
}

