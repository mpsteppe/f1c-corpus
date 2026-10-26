// f1c  0x005272b5  size=222
__m64 *__stdcall sub_5272B5(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4, __m64 *a5, unsigned int a6)
{
  __m64 v6; // mm1
  __m64 v7; // mm0
  __m64 v8; // mm1
  __m64 v9; // mm0
  __m64 v10; // mm3
  __m64 v11; // mm1
  __m64 v12; // mm0
  __m64 v13; // mm5
  __m64 v14; // mm0
  __m64 v15; // mm2
  __m64 v16; // mm3
  __m64 v17; // mm4
  __m64 v18; // mm5
  __m64 v19; // mm6
  __m64 v20; // mm7
  __m64 *result; // eax
  __m64 v22; // mm0
  __m64 v23; // mm4

  v6 = _mm_cvtsi32_si64(a6);
  v7 = _m_punpckldq(v6, v6);
  v8 = _m_punpckldq(v6, (__m64)1065353216LL);
  v9 = _m_pfmul(_m_pfmul(v7, v7), v8);
  v10 = v8;
  v11 = _m_pfmul(v8, v8);
  v12 = _m_pfsub(v9, v11);
  v13 = _m_pfmul(v12, (__m64)0x4000000040400000LL);
  v14 = _m_punpckldq(v13, v12);
  v15 = _m_pfsub(_m_pfadd(_m_punpckldq(v11, v11), _m_pxor(_m_punpckldq(v10, v10), (__m64)0x8000000000000000uLL)), v14);
  v16 = _m_pfsub(v14, _m_punpckhdq(v13, 0));
  v17 = _m_punpckhdq(v15, v15);
  v18 = _m_punpckldq(v16, v16);
  v19 = _m_punpckldq(v15, v15);
  v20 = _m_punpckhdq(v16, v16);
  result = a1;
  v22 = _m_pfadd(
          _m_pfadd(_m_pfmul(v18, (__m64)a3->m64_u64), _m_pfmul(v17, (__m64)a2->m64_u64)),
          _m_pfmul(v19, (__m64)a4->m64_u64));
  v23 = _m_pfadd(
          _m_pfadd(_m_pfadd(_m_pfmul(v17, a2[1]), _m_pfmul(v18, a3[1])), _m_pfmul(v19, a4[1])),
          _m_pfmul(v20, a5[1]));
  a1->m64_u64 = (unsigned __int64)_m_pfmul(
                                    _m_pfadd(v22, _m_pfmul(v20, (__m64)a5->m64_u64)),
                                    (__m64)0x3F0000003F000000LL);
  a1[1].m64_u64 = (unsigned __int64)_m_pfmul(v23, (__m64)0x3F0000003F000000LL);
  _m_femms();
  return result;
}
