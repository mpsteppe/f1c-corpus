__m64 *__stdcall sub_55EA05(__m64 *a1, __m64 *a2)
{
  __m64 v2; // mm4
  __m64 v3; // mm5
  __m64 v4; // mm3
  __m64 v5; // mm0
  __m64 v6; // mm1
  __m64 v7; // mm2
  __m64 v8; // mm5
  __m64 v9; // mm3
  __m64 v10; // mm0
  __m64 v11; // mm3
  char v12; // cl
  __m64 v13; // mm0
  __m64 v14; // mm7
  __m64 v15; // mm2
  __m64 v16; // mm0
  __m64 v17; // mm4
  __m64 *result; // eax
  __m64 v19; // mm1
  __m64 v20; // mm1
  __m64 v21; // mm0
  __m64 v22; // mm1
  __m64 v23; // mm4
  __m64 v24; // mm1
  __m64 v25; // mm2
  __m64 v26; // mm0
  __m64 v27; // mm2
  __m64 v28; // mm4
  __m64 v29; // mm1
  __m64 v30; // mm3
  __m64 v31; // mm0
  __m64 v32; // mm3
  __m64 v33; // mm2
  __m64 v34; // mm3

  v2 = _mm_cvtsi32_si64(a2[2].m64_u32[1]);
  v3 = _mm_cvtsi32_si64(a2[5].m64_u32[0]);
  v4 = _m_pfsubr((__m64)a2->m64_u64, v3);
  v5 = _m_pfadd(_m_pfadd((__m64)a2->m64_u64, v2), v3);
  v6 = _m_pfsub(_m_pfsub((__m64)a2->m64_u64, v2), v3);
  v7 = _m_pfsub(_m_pfsubr((__m64)a2->m64_u64, v2), v3);
  v8 = a2[4];
  v9 = _m_pfsub(v4, v2);
  v10 = _m_punpckldq(v5, v7);
  v11 = _m_punpckldq(v9, v9);
  v12 = _m_pmovmskb(_m_packssdw(_m_pfcmpge(_m_punpckldq(0, v6), v10), _m_pfcmpge(_m_punpckldq(v7, v6), v11)));
  if ( (v12 & 1) != 0 )
  {
    if ( (v12 & 0xCC) == 0xCC )
    {
      v20 = _m_pfadd(v6, (__m64)0xBF8000003F800000uLL);
      v21 = _m_pfrsqrt(v20);
      v22 = _m_punpckldq(v20, v20);
      v23 = _m_pfmul(_m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v21, v21), v22), v21), (__m64)0x3F0000003F000000LL);
      result = a1;
      v24 = _m_punpckldq(
              _m_pfmul(v22, v23),
              _m_pfmul(_m_pfsub(_mm_cvtsi32_si64(a2[2].m64_u32[0]), _m_punpckhdq(v7, v7)), v23));
      a1[1].m64_u64 = (unsigned __int64)_m_pfmul(
                                          _m_pfadd(
                                            _m_punpckldq(v8, (__m64)a2[3].m64_u32[0]),
                                            _m_pxor(
                                              _m_punpckldq(_mm_cvtsi32_si64(a2[1].m64_u32[0]), _m_punpckhdq(v8, v8)),
                                              (__m64)0x8000000000000000uLL)),
                                          v23);
      a1->m64_u64 = (unsigned __int64)v24;
      _m_femms();
    }
    else
    {
      result = a1;
      if ( (v12 & 0x10) != 0 )
      {
        v25 = _m_pfadd(v7, (__m64)0xBF8000003F800000uLL);
        v26 = _m_pfrsqrt(v25);
        v27 = _m_punpckldq(v25, v25);
        v28 = _m_pfmul(_m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v26, v26), v27), v26), (__m64)0x3F0000003F000000LL);
        v29 = _m_punpckldq(
                _m_pfmul(_m_pfadd(_m_punpckhdq(v6, v6), _mm_cvtsi32_si64(a2[2].m64_u32[0])), v28),
                _m_pfmul(v27, v28));
        a1[1].m64_u64 = (unsigned __int64)_m_pfmul(
                                            _m_pfadd(
                                              _m_punpckldq(_mm_cvtsi32_si64(a2[3].m64_u32[0]), v8),
                                              _m_pxor(
                                                _m_punpckldq(_m_punpckhdq(v8, v8), (__m64)a2[1].m64_u32[0]),
                                                (__m64)0x8000000000000000uLL)),
                                            v28);
        a1->m64_u64 = (unsigned __int64)v29;
      }
      else
      {
        v30 = _m_pfadd(v11, (__m64)0xBF8000003F800000uLL);
        v31 = _m_pfrsqrt(v30);
        v32 = _m_punpckldq(v30, v30);
        v33 = _m_pfmul(_m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v31, v31), v32), v31), (__m64)0x3F0000003F000000LL);
        v34 = _m_punpckldq(
                _m_pfmul(v32, v33),
                _m_pfmul(_m_pfsub(_m_punpckhdq(v6, v6), _mm_cvtsi32_si64(a2[2].m64_u32[0])), v33));
        a1->m64_u64 = (unsigned __int64)_m_pfmul(
                                          _m_pfadd(
                                            _m_punpckldq(v8, (__m64)a2[3].m64_u32[0]),
                                            _m_punpckldq(_mm_cvtsi32_si64(a2[1].m64_u32[0]), _m_punpckhdq(v8, v8))),
                                          v33);
        a1[1].m64_u64 = (unsigned __int64)v34;
      }
      _m_femms();
    }
  }
  else
  {
    v13 = _m_pfadd(v10, (__m64)0xBF8000003F800000uLL);
    v14 = _mm_cvtsi32_si64(a2[1].m64_u32[0]);
    v15 = _m_pfrsqrt(v13);
    v16 = _m_punpckldq(v13, v13);
    v17 = _m_pfmul(_m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v15, v15), v16), v15), (__m64)0x3F0000003F000000LL);
    result = a1;
    v19 = _m_punpckldq(
            _m_pfmul(_m_pfsub(_m_punpckhdq(v6, v6), _mm_cvtsi32_si64(a2[2].m64_u32[0])), v17),
            _m_pfmul(v16, v17));
    a1->m64_u64 = (unsigned __int64)_m_pfmul(
                                      _m_pfsub(
                                        _m_punpckldq(_mm_cvtsi32_si64(a2[3].m64_u32[0]), v8),
                                        _m_punpckhdq(v8, _m_punpckldq(v14, v14))),
                                      v17);
    a1[1].m64_u64 = (unsigned __int64)v19;
    _m_femms();
  }
  return result;
}
