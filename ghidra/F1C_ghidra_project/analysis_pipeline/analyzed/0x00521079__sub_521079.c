// Address: 0x00521079
// Size: 540 bytes
// Name: sub_521079
// Type: __m64 *__stdcall(__m64 *, __m64 *)
// Source: IDA Hex-Rays decompilation

__m64 *__stdcall sub_521079(__m64 *a1, __m64 *a2)
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
  __m64 v12; // mm6
  int v13; // ecx
  __m64 v14; // mm0
  __m64 v15; // mm7
  __m64 v16; // mm2
  __m64 v17; // mm0
  __m64 v18; // mm4
  __m64 *result; // eax
  __m64 v20; // mm1
  __m64 v21; // mm1
  __m64 v22; // mm0
  __m64 v23; // mm1
  __m64 v24; // mm4
  __m64 v25; // mm1
  __m64 v26; // mm2
  __m64 v27; // mm0
  __m64 v28; // mm2
  __m64 v29; // mm4
  __m64 v30; // mm1
  __m64 v31; // mm3
  __m64 v32; // mm0
  __m64 v33; // mm3
  __m64 v34; // mm2
  __m64 v35; // mm3

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
  v12 = _m_packssdw(_m_pfcmpge(_m_punpckldq(0, v6), v10), _m_pfcmpge(_m_punpckldq(v7, v6), v11));
  v13 = _mm_cvtsi64_si32(_m_packsswb(v12, v12));
  if ( (v13 & 1) != 0 )
  {
    if ( (v13 & 0xFF00FF00) == 0xFF00FF00 )
    {
      v21 = _m_pfadd(v6, (__m64)0xBF8000003F800000uLL);
      v22 = _m_pfrsqrt(v21);
      v23 = _m_punpckldq(v21, v21);
      v24 = _m_pfmul(_m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v22, v22), v23), v22), (__m64)0x3F0000003F000000LL);
      result = a1;
      v25 = _m_punpckldq(
              _m_pfmul(v23, v24),
              _m_pfmul(_m_pfsub(_mm_cvtsi32_si64(a2[2].m64_u32[0]), _m_punpckhdq(v7, v7)), v24));
      a1[1].m64_u64 = (unsigned __int64)_m_pfmul(
                                          _m_pfadd(
                                            _m_punpckldq(v8, (__m64)a2[3].m64_u32[0]),
                                            _m_pxor(
                                              _m_punpckldq(_mm_cvtsi32_si64(a2[1].m64_u32[0]), _m_punpckhdq(v8, v8)),
                                              (__m64)0x8000000000000000uLL)),
                                          v24);
      a1->m64_u64 = (unsigned __int64)v25;
      _m_femms();
    }
    else
    {
      result = a1;
      if ( (v13 & 0x10000) != 0 )
      {
        v26 = _m_pfadd(v7, (__m64)0xBF8000003F800000uLL);
        v27 = _m_pfrsqrt(v26);
        v28 = _m_punpckldq(v26, v26);
        v29 = _m_pfmul(_m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v27, v27), v28), v27), (__m64)0x3F0000003F000000LL);
        v30 = _m_punpckldq(
                _m_pfmul(_m_pfadd(_m_punpckhdq(v6, v6), _mm_cvtsi32_si64(a2[2].m64_u32[0])), v29),
                _m_pfmul(v28, v29));
        a1[1].m64_u64 = (unsigned __int64)_m_pfmul(
                                            _m_pfadd(
                                              _m_punpckldq(_mm_cvtsi32_si64(a2[3].m64_u32[0]), v8),
                                              _m_pxor(
                                                _m_punpckldq(_m_punpckhdq(v8, v8), (__m64)a2[1].m64_u32[0]),
                                                (__m64)0x8000000000000000uLL)),
                                            v29);
        a1->m64_u64 = (unsigned __int64)v30;
      }
      else
      {
        v31 = _m_pfadd(v11, (__m64)0xBF8000003F800000uLL);
        v32 = _m_pfrsqrt(v31);
        v33 = _m_punpckldq(v31, v31);
        v34 = _m_pfmul(_m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v32, v32), v33), v32), (__m64)0x3F0000003F000000LL);
        v35 = _m_punpckldq(
                _m_pfmul(v33, v34),
                _m_pfmul(_m_pfsub(_m_punpckhdq(v6, v6), _mm_cvtsi32_si64(a2[2].m64_u32[0])), v34));
        a1->m64_u64 = (unsigned __int64)_m_pfmul(
                                          _m_pfadd(
                                            _m_punpckldq(v8, (__m64)a2[3].m64_u32[0]),
                                            _m_punpckldq(_mm_cvtsi32_si64(a2[1].m64_u32[0]), _m_punpckhdq(v8, v8))),
                                          v34);
        a1[1].m64_u64 = (unsigned __int64)v35;
      }
      _m_femms();
    }
  }
  else
  {
    v14 = _m_pfadd(v10, (__m64)0xBF8000003F800000uLL);
    v15 = _mm_cvtsi32_si64(a2[1].m64_u32[0]);
    v16 = _m_pfrsqrt(v14);
    v17 = _m_punpckldq(v14, v14);
    v18 = _m_pfmul(_m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v16, v16), v17), v16), (__m64)0x3F0000003F000000LL);
    result = a1;
    v20 = _m_punpckldq(
            _m_pfmul(_m_pfsub(_m_punpckhdq(v6, v6), _mm_cvtsi32_si64(a2[2].m64_u32[0])), v18),
            _m_pfmul(v17, v18));
    a1->m64_u64 = (unsigned __int64)_m_pfmul(
                                      _m_pfsub(
                                        _m_punpckldq(_mm_cvtsi32_si64(a2[3].m64_u32[0]), v8),
                                        _m_punpckhdq(v8, _m_punpckldq(v15, v15))),
                                      v18);
    a1[1].m64_u64 = (unsigned __int64)v20;
    _m_femms();
  }
  return result;
}
