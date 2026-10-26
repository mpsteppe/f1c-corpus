unsigned int *__cdecl sub_51C813(unsigned int a1, unsigned int *a2, unsigned int *a3, unsigned int *a4, int a5)
{
  unsigned int *result; // eax
  unsigned int v8; // edi
  __m64 v10; // mm0
  __m64 v11; // mm3
  __m64 v12; // mm4
  __m64 v13; // mm6
  __m64 v14; // mm2
  __m64 v15; // mm5
  __m64 v16; // mm6
  __m64 v17; // mm7
  __m64 v18; // mm1
  __m64 v19; // mm0
  __m64 v20; // mm1
  __m64 v21; // mm4
  __m64 v22; // mm0
  __m64 v23; // mm3
  __m64 v24; // mm2
  __m64 v25; // mm3

  result = a2;
  v8 = a1 >> 2;
  do
  {
    v10 = _m_punpcklbw(_mm_cvtsi32_si64(*result), 0);
    v11 = _m_psubsw(_m_punpcklbw(_mm_cvtsi32_si64(*a4), 0), (__m64)qword_5D89E8);
    v12 = _m_psubsw(_m_punpcklbw(_mm_cvtsi32_si64(*a3), 0), (__m64)qword_5D89E8);
    v13 = _m_psllwi(v10, 8u);
    v14 = _m_psradi(_m_paddd(_m_pmaddwd(_m_punpcklwd(v12, v11), (__m64)qword_5D89F0), _m_punpcklwd(v13, 0)), 8u);
    v15 = _m_psradi(_m_paddd(_m_pmaddwd(_m_punpckhwd(v12, v11), (__m64)qword_5D89F0), _m_punpckhwd(v13, 0)), 8u);
    v16 = _m_psradi(_m_pmaddwd(_m_punpcklwd(v11, v10), (__m64)qword_5D89F8), 8u);
    v17 = _m_pmaddwd(_m_punpckhwd(v12, v10), (__m64)qword_5D8A00);
    v18 = _m_pmaddwd(_m_punpckhwd(v11, v10), (__m64)qword_5D89F8);
    v19 = _m_psradi(_m_pmaddwd(_m_punpcklwd(v12, v10), (__m64)qword_5D8A00), 8u);
    v20 = _m_psradi(v18, 8u);
    v21 = _m_psradi(v17, 8u);
    v22 = _m_packuswb(
            _m_packssdw(_m_punpckldq(v16, v14), _m_punpckldq(v19, (__m64)(unsigned int)qword_8B00C0)),
            _m_packssdw(_m_punpckhdq(v16, v14), _m_punpckhdq(v19, (__m64)qword_8B00C0)));
    v23 = _m_psrlqi(_m_pand(v22, (__m64)qword_5D8A08), 8u);
    a5 += 12;
    v24 = _m_packuswb(
            _m_packssdw(_m_punpckldq(v20, v15), _m_punpckldq(v21, (__m64)(unsigned int)qword_8B00C0)),
            _m_packssdw(_m_punpckhdq(v20, v15), _m_punpckhdq(v21, (__m64)qword_8B00C0)));
    ++result;
    *(_DWORD *)(a5 - 12) = _mm_cvtsi64_si32(_m_por(v22, v23));
    v25 = _m_punpcklwd(_m_psrlqi(v23, 0x20u), v24);
    ++a4;
    *(_DWORD *)(a5 - 8) = _mm_cvtsi64_si32(v25);
    ++a3;
    *(_DWORD *)(a5 - 4) = _mm_cvtsi64_si32(_m_por(_m_psrlqi(v24, 0x18u), _m_psrlqi(v25, 0x30u)));
    --v8;
  }
  while ( v8 );
  return result;
}

