char __userpurge sub_6D3510@<al>(__m64 **a1@<eax>, int a2@<edx>, int *a3@<ecx>, _DWORD *a4)
{
  _DWORD *v6; // eax
  unsigned int **v7; // eax
  unsigned int *v8; // esi
  unsigned int *v9; // eax
  unsigned int *v10; // ebx
  unsigned int *v11; // ecx
  __m64 *v12; // edi
  __m64 *v13; // edx
  __m64 v14; // mm0
  __m64 v15; // mm0
  __m64 v16; // mm4
  __m64 v17; // mm1
  __m64 v18; // mm1
  __m64 v19; // mm5
  __m64 v20; // mm6
  __m64 v21; // mm0
  __m64 v22; // mm1
  __m64 v23; // mm7
  __m64 v24; // mm1
  __m64 v25; // mm4
  __m64 v26; // mm2
  __m64 v27; // mm6
  __m64 v28; // mm5
  __m64 v29; // mm3
  __m64 v30; // mm5
  __m64 v31; // mm0
  __m64 v32; // mm1
  __m64 v33; // mm0
  __m64 v34; // mm5
  __m64 v35; // mm4
  __m64 v36; // mm3
  __m64 v37; // mm3
  __m64 v38; // mm7
  __m64 v39; // mm0
  __m64 v40; // mm6
  __m64 v41; // mm4
  __m64 v42; // mm3
  __m64 v43; // mm2
  __m64 v44; // mm7
  __m64 v45; // mm3
  __m64 v46; // mm0
  __m64 v47; // mm3
  __m64 v48; // mm1
  __m64 v49; // mm5
  __m64 *v50; // esi
  __m64 *v51; // edi
  int v52; // eax
  int v53; // eax
  int v54; // edx
  int v55; // ecx
  int v56; // edx
  __int8 *v57; // esi
  int v58; // edx
  __int8 *v59; // edi
  int v60; // ecx
  int v61; // edx
  int v62; // eax
  int v63; // edx
  int v64; // esi
  __m64 v66; // [esp+Ch] [ebp-4Ch]
  int v67; // [esp+24h] [ebp-34h]
  int v68; // [esp+28h] [ebp-30h]
  int v69; // [esp+2Ch] [ebp-2Ch]
  int v70; // [esp+30h] [ebp-28h]
  int v71; // [esp+34h] [ebp-24h]
  int v72; // [esp+38h] [ebp-20h]
  int v73; // [esp+3Ch] [ebp-1Ch]
  int v74; // [esp+3Ch] [ebp-1Ch]
  int v75; // [esp+40h] [ebp-18h]
  int v76; // [esp+40h] [ebp-18h]
  int v77; // [esp+40h] [ebp-18h]
  __m64 *v78; // [esp+44h] [ebp-14h]
  int v79; // [esp+44h] [ebp-14h]
  int v80; // [esp+44h] [ebp-14h]
  unsigned int *v81; // [esp+48h] [ebp-10h]
  unsigned int *v82; // [esp+48h] [ebp-10h]
  unsigned int *v83; // [esp+4Ch] [ebp-Ch]
  unsigned int *v84; // [esp+4Ch] [ebp-Ch]
  __m64 *v85; // [esp+50h] [ebp-8h]
  int v86; // [esp+50h] [ebp-8h]
  int v87; // [esp+50h] [ebp-8h]
  unsigned int *v88; // [esp+54h] [ebp-4h]
  unsigned int *v89; // [esp+54h] [ebp-4h]
  unsigned int *v90; // [esp+60h] [ebp+8h]
  unsigned int *v91; // [esp+60h] [ebp+8h]
  unsigned __int8 *v92; // [esp+60h] [ebp+8h]

  v66.m64_i32[0] = (__int32)&unk_800080;
  v66.m64_i32[1] = (__int32)&unk_800080;
  v6 = (_DWORD *)a3[114];
  v67 = a3[82];
  v71 = v6[4];
  v68 = v6[5];
  v70 = v6[7];
  v75 = a3[28] >> 3;
  v73 = v75;
  v69 = v6[6];
  v72 = a3[28] - 8 * v75;
  v7 = (unsigned int **)(*a4 + 8 * a2);
  v90 = *v7;
  v88 = v7[1];
  v83 = *(unsigned int **)(a4[1] + 4 * a2);
  v81 = *(unsigned int **)(a4[2] + 4 * a2);
  v78 = *a1;
  v85 = a1[1];
  v8 = *v7;
  v9 = v88;
  v10 = v81;
  v11 = v83;
  v12 = *a1;
  v13 = v85;
  do
  {
    v14 = _mm_cvtsi32_si64(*v10);
    v15 = _m_punpcklbw(v14, v14);
    v16 = _m_punpcklwd(v15, v15);
    v17 = _mm_cvtsi32_si64(*v11);
    v18 = _m_punpcklbw(v17, v17);
    v19 = _m_punpcklwd(v18, v18);
    v20 = _mm_cvtsi32_si64(*v8);
    v21 = _m_paddsw(
            _m_pmulhw(
              _m_paddsw(_m_psllwi(_m_psubsw(_m_punpcklbw(v16, 0), v66), 2u), (__m64)0x1000000000001LL),
              (__m64)0x59BA0000D24B59BALL),
            _m_pmulhw(
              _m_paddsw(_m_psllwi(_m_psubsw(_m_punpcklbw(v19, 0), v66), 2u), (__m64)0x1FFFA0000LL),
              (__m64)0x7168E9FA0000LL));
    v22 = _m_punpcklbw(v20, v20);
    v23 = _m_punpcklwd(v22, v20);
    v24 = _m_psrlqi(v22, 0x10u);
    v25 = _m_paddsw(
            _m_pmulhw(
              _m_paddsw(_m_psllwi(_m_psubsw(_m_punpckhbw(v16, 0), v66), 2u), (__m64)0x10000LL),
              (__m64)0xD24B59BA0000LL),
            _m_pmulhw(
              _m_paddsw(_m_psllwi(_m_psubsw(_m_punpckhbw(v19, 0), v66), 2u), (__m64)0x1FFFA00000001LL),
              (__m64)0x7168E9FA00007168LL));
    v26 = _m_por(
            _m_psrlqi(_m_pand(v21, (__m64)0xFFFFFFFF0000LL), 0x10u),
            _m_psllqi(_m_pand(v25, (__m64)0xFFFFFFFF0000LL), 0x10u));
    v27 = _mm_cvtsi32_si64(*v9);
    v12->m64_u64 = (unsigned __int64)_m_packuswb(
                                       _m_paddsw(_m_punpcklbw(v23, 0), v21),
                                       _m_paddsw(_m_punpcklbw(v24, 0), v26));
    v28 = _m_punpcklbw(v27, v27);
    v29 = _m_punpcklbw(_m_punpcklwd(v28, v27), 0);
    v30 = _m_psrlqi(v28, 0x10u);
    v13->m64_u64 = (unsigned __int64)_m_packuswb(
                                       _m_paddsw(v29, v21),
                                       _m_paddsw(_m_punpcklbw(_m_punpckldq(v30, v30), 0), v26));
    v31 = _m_psrlqi(_mm_cvtsi32_si64(*v10), 0x10u);
    v32 = _m_paddsw(_m_punpcklbw(_m_punpcklwd(_m_psrlqi(v24, 0x18u), _m_psrlqi(v24, 0x20u)), 0), v25);
    v33 = _m_punpcklbw(v31, v31);
    v34 = _m_paddsw(_m_punpcklbw(_m_punpcklwd(_m_psrlqi(v30, 0x18u), _m_psrlqi(v30, 0x20u)), 0), v25);
    v35 = _m_punpcklwd(v33, v33);
    v36 = _m_psrlqi(_mm_cvtsi32_si64(*v11), 0x10u);
    v37 = _m_punpcklbw(v36, v36);
    v38 = _m_punpcklwd(v37, v37);
    v39 = _m_paddsw(
            _m_pmulhw(
              _m_paddsw(_m_psllwi(_m_psubsw(_m_punpcklbw(v35, 0), v66), 2u), (__m64)0x1000000000001LL),
              (__m64)0x59BA0000D24B59BALL),
            _m_pmulhw(
              _m_paddsw(_m_psllwi(_m_psubsw(_m_punpcklbw(v38, 0), v66), 2u), (__m64)0x1FFFA0000LL),
              (__m64)0x7168E9FA0000LL));
    v40 = _mm_cvtsi32_si64(v8[1]);
    v41 = _m_paddsw(
            _m_pmulhw(
              _m_paddsw(_m_psllwi(_m_psubsw(_m_punpckhbw(v35, 0), v66), 2u), (__m64)0x10000LL),
              (__m64)0xD24B59BA0000LL),
            _m_pmulhw(
              _m_paddsw(_m_psllwi(_m_psubsw(_m_punpckhbw(v38, 0), v66), 2u), (__m64)0x1FFFA00000001LL),
              (__m64)0x7168E9FA00007168LL));
    v42 = _mm_cvtsi32_si64(v9[1]);
    v12[1].m64_u64 = (unsigned __int64)_m_packuswb(
                                         v32,
                                         _m_paddsw(_m_punpcklbw(_m_punpcklwd(_m_punpcklbw(v40, v40), v40), 0), v39));
    v43 = _m_por(
            _m_psrlqi(_m_pand(v39, (__m64)0xFFFFFFFF0000LL), 0x10u),
            _m_psllqi(_m_pand(v41, (__m64)0xFFFFFFFF0000LL), 0x10u));
    v44 = v42;
    v45 = _m_paddsw(_m_punpcklbw(_m_punpcklwd(_m_punpcklbw(v42, v42), v42), 0), v39);
    v46 = _m_psrlqi(v44, 8u);
    v13[1].m64_u64 = (unsigned __int64)_m_packuswb(v34, v45);
    v47 = _m_psrlqi(v40, 8u);
    v48 = _m_psrlqi(v47, 8u);
    v8 += 2;
    v9 += 2;
    v49 = _m_psrlqi(v46, 8u);
    v12 += 3;
    v13 += 3;
    ++v10;
    v12[-1].m64_u64 = (unsigned __int64)_m_packuswb(
                                          _m_paddsw(_m_punpcklbw(_m_punpcklbw(v47, v47), 0), v43),
                                          _m_paddsw(
                                            _m_punpcklbw(_m_punpcklwd(v48, _m_psrlqi(_m_punpcklbw(v48, v48), 0x10u)), 0),
                                            v41));
    ++v11;
    v13[-1].m64_u64 = (unsigned __int64)_m_packuswb(
                                          _m_paddsw(_m_punpcklbw(_m_punpcklbw(v46, v46), 0), v43),
                                          _m_paddsw(
                                            _m_punpcklbw(_m_punpcklwd(v49, _m_psrlqi(_m_punpcklbw(v49, v49), 0x10u)), 0),
                                            v41));
    --v75;
  }
  while ( v75 );
  _m_empty();
  v91 = &v90[2 * v73];
  v89 = &v88[2 * v73];
  v50 = &v78[3 * v73];
  v51 = &v85[3 * v73];
  v52 = v72 >> 1;
  v84 = &v83[v73];
  v82 = &v81[v73];
  if ( v72 >> 1 )
  {
    v74 = v72 >> 1;
    do
    {
      v53 = *(unsigned __int8 *)v84;
      v84 = (unsigned int *)((char *)v84 + 1);
      v54 = *(unsigned __int8 *)v82;
      v82 = (unsigned int *)((char *)v82 + 1);
      v86 = *(_DWORD *)(v71 + 4 * v54);
      v55 = *(_DWORD *)(v69 + 4 * v54) + *(_DWORD *)(v70 + 4 * v53);
      v79 = *(_DWORD *)(v68 + 4 * v53);
      v56 = *(unsigned __int8 *)v91;
      v55 >>= 16;
      v92 = (unsigned __int8 *)v91 + 1;
      v50->m64_i8[0] = *(_BYTE *)(v56 + v86 + v67);
      v50->m64_i8[1] = *(_BYTE *)(v56 + v55 + v67);
      v50->m64_i8[2] = *(_BYTE *)(v79 + v56 + v67);
      v76 = *v92;
      v57 = &v50->m64_i8[3];
      v91 = (unsigned int *)(v92 + 1);
      *v57 = *(_BYTE *)(v86 + v76 + v67);
      v57[1] = *(_BYTE *)(v76 + v55 + v67);
      v57[2] = *(_BYTE *)(v79 + v76 + v67);
      v50 = (__m64 *)(v57 + 3);
      v77 = *(unsigned __int8 *)v89;
      v51->m64_i8[0] = *(_BYTE *)(v86 + v77 + v67);
      v51->m64_i8[1] = *(_BYTE *)(v77 + v55 + v67);
      v51->m64_i8[2] = *(_BYTE *)(v79 + v77 + v67);
      v58 = *((unsigned __int8 *)v89 + 1);
      v59 = &v51->m64_i8[3];
      v89 = (unsigned int *)((char *)v89 + 2);
      *v59 = *(_BYTE *)(v58 + v86 + v67);
      v59[1] = *(_BYTE *)(v58 + v55 + v67);
      v59[2] = *(_BYTE *)(v79 + v58 + v67);
      v51 = (__m64 *)(v59 + 3);
      v52 = v74 - 1;
      v74 = v52;
    }
    while ( v52 );
  }
  if ( (v72 & 1) != 0 )
  {
    v60 = *(unsigned __int8 *)v84;
    v61 = *(unsigned __int8 *)v82;
    v87 = *(_DWORD *)(v71 + 4 * v61);
    v62 = *(_DWORD *)(v69 + 4 * v61) + *(_DWORD *)(v70 + 4 * v60);
    v63 = *(unsigned __int8 *)v91;
    v80 = *(_DWORD *)(v68 + 4 * v60);
    v50->m64_i8[0] = *(_BYTE *)(v63 + v87 + v67);
    v52 = v62 >> 16;
    v50->m64_i8[1] = *(_BYTE *)(v63 + v52 + v67);
    v50->m64_i8[2] = *(_BYTE *)(v80 + v63 + v67);
    v64 = *(unsigned __int8 *)v89;
    v51->m64_i8[0] = *(_BYTE *)(v64 + v87 + v67);
    LOBYTE(v63) = *(_BYTE *)(v64 + v52 + v67);
    LOBYTE(v52) = *(_BYTE *)(v80 + v64 + v67);
    v51->m64_i8[1] = v63;
    v51->m64_i8[2] = v52;
  }
  return v52;
}
