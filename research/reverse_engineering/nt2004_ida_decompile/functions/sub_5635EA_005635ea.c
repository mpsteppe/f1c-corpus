int __stdcall sub_5635EA(__m64 *a1, _DWORD *a2, __m64 *a3)
{
  __m64 v3; // mm1
  __m64 v4; // mm2
  __m64 v5; // mm5
  __m64 v6; // mm0
  __m64 v7; // mm4
  __m64 v8; // mm3
  __m64 v9; // mm6
  __m64 v10; // mm4
  __m64 v11; // mm6
  __m64 v12; // mm1
  __m64 v13; // mm0
  __m64 v14; // mm7
  __m64 v15; // mm2
  __m64 v16; // mm0
  __m64 v17; // mm1
  __m64 v18; // mm5
  __m64 v19; // mm0
  __m64 v20; // mm4
  __m64 v21; // mm3
  __m64 v22; // mm6
  __m64 v23; // mm4
  __m64 v24; // mm6
  __m64 v25; // mm1
  __m64 v26; // mm0
  __m64 v27; // mm7
  __m64 v28; // mm2
  __m64 v29; // mm2
  __m64 v30; // mm0
  __m64 v31; // mm0
  __m64 v32; // mm1
  int result; // eax
  __m64 v34; // mm0
  __m64 v35; // mm1
  __m64 v36; // mm3
  __m64 v37; // mm6
  __m64 v38; // mm4
  __m64 v39; // mm7
  __m64 v40; // mm3
  __m64 v41; // mm6
  __m64 v42; // mm4
  __m64 v43; // mm7
  __m64 v44; // [esp+0h] [ebp-44h]
  __m64 v45; // [esp+8h] [ebp-3Ch]
  __m64 v46; // [esp+10h] [ebp-34h]
  __m64 v47; // [esp+18h] [ebp-2Ch]
  __m64 v48; // [esp+20h] [ebp-24h]
  __m64 v49; // [esp+28h] [ebp-1Ch]
  __m64 v50; // [esp+38h] [ebp-Ch]

  v3 = a3[2];
  v4 = a3[4];
  v5 = _m_pfsub(
         _m_pfmul(_m_punpckldq((__m64)a3->m64_u64, (__m64)a3->m64_u64), _m_punpckhdq(v3, v4)),
         _m_pfmul(_m_punpckhdq((__m64)a3->m64_u64, (__m64)a3->m64_u64), _m_punpckldq(v3, v4)));
  v6 = _m_punpckldq((__m64)a3->m64_u64, v3);
  v7 = a3[6];
  v8 = _m_punpckhdq(v7, v7);
  v9 = _m_punpckhdq(v7, v4);
  v10 = _m_punpckldq(v7, v4);
  v11 = _m_pfsub(_m_pfmul(v9, v6), _m_pfmul(_m_punpckhdq((__m64)a3->m64_u64, v3), v10));
  v12 = _m_pfsubr(_m_pfmul(_m_punpckhdq(v3, v4), _m_punpckldq(v10, v10)), _m_pfmul(_m_punpckhdq(v6, v10), v8));
  v13 = a3[7];
  v14 = a3[5];
  v45 = _m_pfsub(
          _m_pfadd(_m_pfmul(_m_punpckhdq(v11, v11), v13), _m_pfmul(_m_punpckhdq(v12, v12), a3[3])),
          _m_pfmul(_m_punpckldq(v12, v12), v14));
  v47 = _m_pfadd(
          _m_pfsub(_m_pfmul(_m_punpckhdq(v5, v5), v13), _m_pfmul(_m_punpckldq(v11, v11), v14)),
          _m_pfmul(_m_punpckhdq(v12, v12), a3[1]));
  v15 = _m_punpckldq(v5, v5);
  v49 = _m_pfsub(
          _m_pfadd(_m_pfmul(v13, v15), _m_pfmul(_m_punpckldq(v12, v12), a3[1])),
          _m_pfmul(_m_punpckldq(v11, v11), a3[3]));
  v50 = _m_pfadd(
          _m_pfsub(_m_pfmul(v15, v14), _m_pfmul(_m_punpckhdq(v5, v5), a3[3])),
          _m_pfmul(_m_punpckhdq(v11, v11), a3[1]));
  v16 = a3[1];
  v17 = a3[3];
  v18 = _m_pfsub(
          _m_pfmul(_m_punpckldq(v16, v16), _m_punpckhdq(v17, v14)),
          _m_pfmul(_m_punpckhdq(v16, v16), _m_punpckldq(v17, v14)));
  v19 = _m_punpckldq(v16, v17);
  v20 = a3[7];
  v21 = _m_punpckhdq(v20, v20);
  v22 = _m_punpckhdq(v20, v14);
  v23 = _m_punpckldq(v20, v14);
  v24 = _m_pfsub(_m_pfmul(v22, v19), _m_pfmul(_m_punpckhdq(a3[1], v17), v23));
  v25 = _m_pfsubr(_m_pfmul(_m_punpckhdq(v17, v14), _m_punpckldq(v23, v23)), _m_pfmul(_m_punpckhdq(v19, v23), v21));
  v26 = a3[6];
  v27 = a3[4];
  v44 = _m_pfsub(
          _m_pfadd(_m_pfmul(_m_punpckhdq(v24, v24), v26), _m_pfmul(_m_punpckhdq(v25, v25), a3[2])),
          _m_pfmul(_m_punpckldq(v25, v25), v27));
  v46 = _m_pfadd(
          _m_pfsub(_m_pfmul(_m_punpckhdq(v18, v18), v26), _m_pfmul(_m_punpckldq(v24, v24), v27)),
          _m_pfmul(_m_punpckhdq(v25, v25), (__m64)a3->m64_u64));
  v28 = _m_punpckldq(v18, v18);
  v48 = _m_pfsub(
          _m_pfadd(_m_pfmul(v26, v28), _m_pfmul(_m_punpckldq(v25, v25), (__m64)a3->m64_u64)),
          _m_pfmul(_m_punpckldq(v24, v24), a3[2]));
  v29 = _m_pfadd(
          _m_pfsub(_m_pfmul(v28, v27), _m_pfmul(_m_punpckhdq(v18, v18), a3[2])),
          _m_pfmul(_m_punpckhdq(v24, v24), (__m64)a3->m64_u64));
  v30 = _m_pfadd(
          _m_pfmul(_m_punpckhdq(v48, v29), _m_pfmul(_m_punpckldq(v27, v26), (__m64)0xBF8000003F800000uLL)),
          _m_pfmul(
            _m_pfmul(_m_punpckldq((__m64)a3->m64_u64, (__m64)a3[2].m64_u32[0]), (__m64)0xBF8000003F800000uLL),
            _m_punpckhdq(v44, v46)));
  v31 = _m_pfacc(v30, v30);
  if ( a2 )
    *a2 = _mm_cvtsi64_si32(v31);
  v32 = _m_pfrcp(v31);
  result = _mm_cvtsi64_si32(_m_pfcmpeq(0, v31));
  v34 = _m_pfmul(_m_pfrcpit2(_m_pfrcpit1(_m_punpckldq(v31, v31), v32), v32), (__m64)0xBF8000003F800000uLL);
  v35 = _m_punpckhdq(v34, _m_punpckldq(v29, v34));
  if ( !result )
  {
    result = (int)a1;
    v36 = _m_pfmul(v46, v34);
    v37 = _m_pfmul(v47, v34);
    v38 = _m_pfmul(v44, v35);
    v39 = _m_pfmul(v45, v35);
    a1->m64_u64 = (unsigned __int64)_m_punpckhdq(v38, v36);
    a1[2].m64_u64 = (unsigned __int64)_m_punpckldq(v38, v36);
    a1[4].m64_u64 = (unsigned __int64)_m_punpckhdq(v39, v37);
    a1[6].m64_u64 = (unsigned __int64)_m_punpckldq(v39, v37);
    v40 = _m_pfmul(v29, v34);
    v41 = _m_pfmul(v50, v34);
    v42 = _m_pfmul(v48, v35);
    v43 = _m_pfmul(v49, v35);
    a1[1].m64_u64 = (unsigned __int64)_m_punpckhdq(v42, v40);
    a1[3].m64_u64 = (unsigned __int64)_m_punpckldq(v42, v40);
    a1[5].m64_u64 = (unsigned __int64)_m_punpckhdq(v43, v41);
    a1[7].m64_u64 = (unsigned __int64)_m_punpckldq(v43, v41);
  }
  return result;
}
