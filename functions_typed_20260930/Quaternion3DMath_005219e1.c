__m64 *__userpurge sub_5219E1@<eax>(
        unsigned int a1@<esi>,
        __m64 *a2,
        __m64 *a3,
        __m64 *a4,
        __m64 *a5,
        __m64 *a6,
        __m64 *a7,
        __m64 *a8)
{
  __m64 v8; // mm0
  __m64 v9; // mm1
  __m64 v10; // mm2
  __m64 v11; // mm3
  __m64 *v12; // edx
  __m64 v13; // mm0
  __m64 v14; // mm2
  __m64 v15; // mm4
  __m64 v16; // mm5
  __m64 v17; // mm1
  __m64 v18; // mm3
  __m64 v19; // mm2
  int v20; // eax
  __m64 v21; // mm4
  __m64 v22; // mm6
  __m64 v23; // mm7
  __m64 v24; // mm3
  __m64 v25; // mm5
  __m64 v26; // mm6
  __m64 v27; // mm3
  __m64 v28; // mm0
  __m64 v29; // mm0
  __m64 v30; // mm4
  __m64 v31; // mm5
  __m64 v32; // mm0
  __m64 v33; // mm6
  __m64 v34; // mm7
  __m64 v35; // mm6
  __m64 v36; // mm7
  __m64 v37; // mm1
  __m64 v38; // mm2
  __m64 v39; // mm0
  __m64 v40; // mm3
  __m64 v41; // mm4
  __m64 v42; // mm3
  __m64 v43; // mm1
  __m64 v44; // mm2
  __m64 v45; // mm0
  __m64 v46; // mm3
  __m64 v47; // mm4
  __m64 v48; // mm3
  __m64 v49; // mm1
  __m64 v50; // mm0
  __m64 v51; // mm0
  __m64 v52; // mm2
  __m64 v53; // mm1
  __int32 v54; // edx
  __m64 v55; // mm1
  __m64 v56; // mm0
  char v57; // cl
  __m64 v58; // mm2
  __m64 v59; // mm0
  __m64 v60; // mm1
  __m64 v61; // mm3
  __m64 v62; // mm1
  __m64 v63; // mm6
  __m64 v64; // mm7
  __m64 v65; // mm0
  __m64 v66; // mm0
  __m64 v67; // mm4
  __m64 v68; // mm5
  __m64 v69; // mm0
  __m64 v70; // mm6
  __m64 v71; // mm7
  __m64 v72; // mm6
  __m64 v73; // mm7
  __m64 v74; // mm1
  __m64 v75; // mm2
  __m64 v76; // mm0
  __m64 v77; // mm3
  __m64 v78; // mm4
  __m64 v79; // mm3
  __m64 v80; // mm1
  __m64 v81; // mm2
  __m64 v82; // mm0
  __m64 v83; // mm3
  __m64 v84; // mm4
  __m64 v85; // mm3
  __m64 v86; // mm1
  __m64 v87; // mm0
  __m64 v88; // mm0
  __m64 v89; // mm2
  __m64 v90; // mm1
  __m64 v91; // mm1
  __m64 v92; // mm0
  char v93; // cl
  __m64 v94; // mm2
  __m64 v95; // mm0
  __m64 v96; // mm1
  __m64 v97; // mm3
  __m64 v98; // mm1
  __m64 v99; // mm6
  __m64 v100; // mm7
  __m64 *result; // eax
  unsigned int v102; // [esp+0h] [ebp-ACh]
  unsigned int v103; // [esp+0h] [ebp-ACh]
  __m64 v104; // [esp+0h] [ebp-ACh]
  unsigned int v105; // [esp+0h] [ebp-ACh]
  unsigned int v106; // [esp+0h] [ebp-ACh]
  __m64 v107; // [esp+0h] [ebp-ACh]
  __m64 m64_u64; // [esp+Ch] [ebp-A0h]
  __m64 v109; // [esp+14h] [ebp-98h]
  __m64 v110; // [esp+1Ch] [ebp-90h]
  __m64 v111; // [esp+24h] [ebp-88h]
  __m64 v112; // [esp+2Ch] [ebp-80h]
  __m64 v113; // [esp+34h] [ebp-78h]
  __m64 v114; // [esp+3Ch] [ebp-70h]
  __m64 v115; // [esp+44h] [ebp-68h]
  __m64 v116; // [esp+4Ch] [ebp-60h]
  __m64 v117; // [esp+4Ch] [ebp-60h]
  __m64 v118; // [esp+54h] [ebp-58h]
  __m64 v119; // [esp+54h] [ebp-58h]
  __m64 v120; // [esp+5Ch] [ebp-50h]
  __m64 v121; // [esp+5Ch] [ebp-50h]
  __m64 v122; // [esp+64h] [ebp-48h]
  __m64 v123; // [esp+64h] [ebp-48h]
  __m64 v124; // [esp+84h] [ebp-28h]
  __m64 v125; // [esp+84h] [ebp-28h]
  __m64 v126; // [esp+8Ch] [ebp-20h]
  __m64 v127; // [esp+8Ch] [ebp-20h]
  __m64 v128; // [esp+8Ch] [ebp-20h]
  __m64 v129; // [esp+8Ch] [ebp-20h]
  __m64 v130; // [esp+94h] [ebp-18h]
  unsigned int v131; // [esp+94h] [ebp-18h]
  __m64 v132; // [esp+94h] [ebp-18h]
  unsigned int v133; // [esp+94h] [ebp-18h]
  __m64 v134; // [esp+9Ch] [ebp-10h]
  __m64 v135; // [esp+9Ch] [ebp-10h]
  __m64 v136; // [esp+A4h] [ebp-8h]
  __m64 v137; // [esp+A4h] [ebp-8h]

  m64_u64 = (__m64)a5->m64_u64;
  v109 = a5[1];
  v110 = (__m64)a6->m64_u64;
  v8 = _m_pfadd((__m64)a5->m64_u64, (__m64)a6->m64_u64);
  v111 = a6[1];
  v9 = _m_pfadd(v109, v111);
  v10 = _m_pfsub((__m64)a5->m64_u64, (__m64)a6->m64_u64);
  v11 = _m_pfsub(v109, v111);
  v12 = a7;
  v13 = _m_pfadd(_m_pfmul(v8, v8), _m_pfmul(v9, v9));
  v14 = _m_pfadd(_m_pfmul(v10, v10), _m_pfmul(v11, v11));
  v112 = (__m64)a7->m64_u64;
  v113 = a7[1];
  v15 = _m_pfadd((__m64)a6->m64_u64, (__m64)a7->m64_u64);
  v16 = _m_pfadd(v111, v113);
  v17 = _m_pfsub((__m64)a6->m64_u64, (__m64)a7->m64_u64);
  v18 = _m_pfsub(v111, v113);
  v19 = _m_pfcmpgt(
          _m_pfacc(v14, _m_pfadd(_m_pfmul(v17, v17), _m_pfmul(v18, v18))),
          _m_pfacc(v13, _m_pfadd(_m_pfmul(v15, v15), _m_pfmul(v16, v16))));
  v20 = _mm_cvtsi64_si32(_m_packsswb(v19, v19));
  if ( (v20 & 1) != 0 )
  {
    v12 = a5;
    m64_u64 = _m_pxor((__m64)0x8000000080000000uLL, (__m64)a5->m64_u64);
    v109 = _m_pxor((__m64)0x8000000080000000uLL, a5[1]);
  }
  if ( (v20 & 0x10000) != 0 )
  {
    v112 = _m_pxor((__m64)0x8000000080000000uLL, (__m64)a7->m64_u64);
    v113 = _m_pxor((__m64)0x8000000080000000uLL, a7[1]);
  }
  v21 = a8[1];
  v22 = _m_pfadd(v112, (__m64)a8->m64_u64);
  v114 = (__m64)a8->m64_u64;
  v23 = _m_pfadd(v113, v21);
  v115 = v21;
  v24 = _m_pfsub(v112, (__m64)a8->m64_u64);
  v25 = _m_pfsub(v113, v21);
  v26 = _m_pfadd(_m_pfmul(v22, v22), _m_pfmul(v23, v23));
  v27 = _m_pfadd(_m_pfmul(v24, v24), _m_pfmul(v25, v25));
  if ( (_mm_cvtsi64_si32(_m_pfcmpgt(_m_pfacc(v27, v27), _m_pfacc(v26, v26))) & 1) != 0 )
  {
    v12 = a8;
    v114 = _m_pxor((__m64)0x8000000080000000uLL, (__m64)a8->m64_u64);
    v115 = _m_pxor((__m64)0x8000000080000000uLL, a8[1]);
  }
  v28 = _m_pfadd(_m_pfmul(v110, v110), _m_pfmul(v111, v111));
  v29 = _m_pfacc(v28, v28);
  v30 = _m_pfrcp(v29);
  v31 = _m_pfcmpgt(v29, (__m64)0x80000000800000LL);
  v32 = _m_pfrcpit2(_m_pfrcpit1(v29, v30), v30);
  v116 = _m_pfmul(_m_pand(_m_pxor(v110, (__m64)0x8000000080000000uLL), v31), v32);
  v118 = _m_pfmul(_m_pand(_m_pxor(v111, (__m64)0x80000000LL), v31), v32);
  v33 = _m_punpckldq(_m_punpckhdq(m64_u64, m64_u64), m64_u64);
  v34 = _m_punpckldq(_m_punpckhdq(v109, v109), v109);
  v126 = _m_pfacc(
           _m_pfsub(_m_pfmul(v33, v118), _m_pfmul(_m_pxor(v34, (__m64)0x80000000LL), v116)),
           _m_pfadd(_m_pxor(_m_pfmul(m64_u64, v118), (__m64)0x80000000LL), _m_pfmul(v109, v116)));
  v130 = _m_pfacc(
           _m_pfadd(_m_pfmul(_m_pxor(v33, (__m64)0x80000000LL), v116), _m_pfmul(v34, v118)),
           _m_pfsub(_m_pfmul(_m_pxor(v109, (__m64)0x80000000LL), v118), _m_pfmul(m64_u64, v116)));
  v35 = _m_punpckldq(_m_punpckhdq(v112, v112), v112);
  v36 = _m_punpckldq(_m_punpckhdq(v113, v113), v113);
  v134 = _m_pfacc(
           _m_pfsub(_m_pfmul(v35, v118), _m_pfmul(_m_pxor(v36, (__m64)0x80000000LL), v116)),
           _m_pfadd(_m_pxor(_m_pfmul(v112, v118), (__m64)0x80000000LL), _m_pfmul(v113, v116)));
  v136 = _m_pfacc(
           _m_pfadd(_m_pfmul(_m_pxor(v35, (__m64)0x80000000LL), v116), _m_pfmul(v36, v118)),
           _m_pfsub(_m_pfmul(_m_pxor(v113, (__m64)0x80000000LL), v118), _m_pfmul(v112, v116)));
  v37 = v126;
  v38 = v130;
  v39 = _m_punpckhdq(v130, v130);
  if ( !_mm_cvtsi64_si32(_m_pfcmpge(v39, (__m64)0x3F8000003F800000LL)) )
  {
    SquareRootApproximation(0, v12);
    v102 = _mm_cvtsi64_si32(v39);
    sub_529700();
    v12 = (__m64 *)m64_u64.m64_i32[1];
    v37 = v126;
    v38 = v130;
    if ( _mm_cvtsi64_si32(_m_pfcmpge(_m_pand(v39, (__m64)0x7FFFFFFF7FFFFFFFLL), (__m64)0x3400000034000000LL)) )
    {
      v40 = _mm_cvtsi32_si64(v102);
      v41 = _m_pfrcp(v39);
      v42 = _m_pfmul(_m_punpckldq(v40, v40), _m_pfrcpit2(_m_pfrcpit1(v39, v41), v41));
      v37 = _m_pfmul(v126, v42);
      v38 = _m_pfmul(v130, v42);
    }
  }
  v120 = v37;
  v122 = _m_pand(v38, (__m64)0xFFFFFFFFLL);
  v43 = v134;
  v44 = v136;
  v45 = _m_punpckhdq(v136, v136);
  if ( !_mm_cvtsi64_si32(_m_pfcmpge(v45, (__m64)0x3F8000003F800000LL)) )
  {
    SquareRootApproximation(0, v12);
    v103 = _mm_cvtsi64_si32(v45);
    sub_529700();
    v43 = v134;
    v44 = v136;
    if ( _mm_cvtsi64_si32(_m_pfcmpge(_m_pand(v45, (__m64)0x7FFFFFFF7FFFFFFFLL), (__m64)0x3400000034000000LL)) )
    {
      v46 = _mm_cvtsi32_si64(v103);
      v47 = _m_pfrcp(v45);
      v48 = _m_pfmul(_m_punpckldq(v46, v46), _m_pfrcpit2(_m_pfrcpit1(v45, v47), v47));
      v43 = _m_pfmul(v134, v48);
      v44 = _m_pfmul(v136, v48);
    }
  }
  v127 = _m_pfmul(_m_pfadd(v120, v43), (__m64)0xBE800000BE800000uLL);
  v131 = _m_pfmul(_m_pfadd(v122, _m_pand(v44, (__m64)0xFFFFFFFFLL)), (__m64)0xBE800000BE800000uLL).m64_u32[0];
  v49 = _mm_cvtsi32_si64(v131);
  v50 = _m_pfadd(_m_pfmul(v127, v127), _m_pfmul(v49, v49));
  v51 = _m_pfacc(v50, v50);
  v52 = _m_pfrsqrt(v51);
  v53 = _m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v52, v52), v51), v52);
  v104.m64_u64 = __PAIR64__(a1, _mm_cvtsi64_si32(v53));
  PackedFloatingPointMath();
  v55 = _m_pfmul(v51, v53);
  v56 = _m_pfcmpge(_m_pand(v55, (__m64)0x7FFFFFFFFFFFFFFFLL), (__m64)0x3400000034000000LL);
  v57 = _mm_cvtsi64_si32(_m_punpckhdq(v56, v56));
  v58 = v127;
  v59 = v55;
  v60 = _m_pfmul(_m_punpckhdq(v55, v55), v104);
  v61 = _mm_cvtsi32_si64(v131);
  if ( (v57 & 1) != 0 )
  {
    v62 = _m_punpckldq(v60, v60);
    v61 = _m_pfmul(v61, v62);
    v58 = _m_pfmul(v127, v62);
  }
  v124 = _m_punpckldq(v61, v59);
  v63 = _m_punpckldq(_m_punpckhdq(v58, v58), v58);
  v64 = _m_punpckldq(_m_punpckhdq(v124, v124), v124);
  a2->m64_u64 = (unsigned __int64)_m_pfacc(
                                    _m_pfsub(_m_pfmul(v63, v111), _m_pfmul(_m_pxor(v64, (__m64)0x80000000LL), v110)),
                                    _m_pfadd(_m_pxor(_m_pfmul(v58, v111), (__m64)0x80000000LL), _m_pfmul(v124, v110)));
  a2[1].m64_u64 = (unsigned __int64)_m_pfacc(
                                      _m_pfadd(_m_pfmul(_m_pxor(v63, (__m64)0x80000000LL), v110), _m_pfmul(v64, v111)),
                                      _m_pfsub(_m_pfmul(_m_pxor(v124, (__m64)0x80000000LL), v111), _m_pfmul(v58, v110)));
  v65 = _m_pfadd(_m_pfmul(v112, v112), _m_pfmul(v113, v113));
  v66 = _m_pfacc(v65, v65);
  v67 = _m_pfrcp(v66);
  v68 = _m_pfcmpgt(v66, (__m64)0x80000000800000LL);
  v69 = _m_pfrcpit2(_m_pfrcpit1(v66, v67), v67);
  v117 = _m_pfmul(_m_pand(_m_pxor(v112, (__m64)0x8000000080000000uLL), v68), v69);
  v119 = _m_pfmul(_m_pand(_m_pxor(v113, (__m64)0x80000000LL), v68), v69);
  v70 = _m_punpckldq(_m_punpckhdq(v110, v110), v110);
  v71 = _m_punpckldq(_m_punpckhdq(v111, v111), v111);
  v128 = _m_pfacc(
           _m_pfsub(_m_pfmul(v70, v119), _m_pfmul(_m_pxor(v71, (__m64)0x80000000LL), v117)),
           _m_pfadd(_m_pxor(_m_pfmul(v110, v119), (__m64)0x80000000LL), _m_pfmul(v111, v117)));
  v132 = _m_pfacc(
           _m_pfadd(_m_pfmul(_m_pxor(v70, (__m64)0x80000000LL), v117), _m_pfmul(v71, v119)),
           _m_pfsub(_m_pfmul(_m_pxor(v111, (__m64)0x80000000LL), v119), _m_pfmul(v110, v117)));
  v72 = _m_punpckldq(_m_punpckhdq(v114, v114), v114);
  v73 = _m_punpckldq(_m_punpckhdq(v115, v115), v115);
  v135 = _m_pfacc(
           _m_pfsub(_m_pfmul(v72, v119), _m_pfmul(_m_pxor(v73, (__m64)0x80000000LL), v117)),
           _m_pfadd(_m_pxor(_m_pfmul(v114, v119), (__m64)0x80000000LL), _m_pfmul(v115, v117)));
  v137 = _m_pfacc(
           _m_pfadd(_m_pfmul(_m_pxor(v72, (__m64)0x80000000LL), v117), _m_pfmul(v73, v119)),
           _m_pfsub(_m_pfmul(_m_pxor(v115, (__m64)0x80000000LL), v119), _m_pfmul(v114, v117)));
  v74 = v128;
  v75 = v132;
  v76 = _m_punpckhdq(v132, v132);
  if ( !_mm_cvtsi64_si32(_m_pfcmpge(v76, (__m64)0x3F8000003F800000LL)) )
  {
    SquareRootApproximation(0, v54);
    v105 = _mm_cvtsi64_si32(v76);
    sub_529700();
    v54 = m64_u64.m64_i32[1];
    v74 = v128;
    v75 = v132;
    if ( _mm_cvtsi64_si32(_m_pfcmpge(_m_pand(v76, (__m64)0x7FFFFFFF7FFFFFFFLL), (__m64)0x3400000034000000LL)) )
    {
      v77 = _mm_cvtsi32_si64(v105);
      v78 = _m_pfrcp(v76);
      v79 = _m_pfmul(_m_punpckldq(v77, v77), _m_pfrcpit2(_m_pfrcpit1(v76, v78), v78));
      v74 = _m_pfmul(v128, v79);
      v75 = _m_pfmul(v132, v79);
    }
  }
  v121 = v74;
  v123 = _m_pand(v75, (__m64)0xFFFFFFFFLL);
  v80 = v135;
  v81 = v137;
  v82 = _m_punpckhdq(v137, v137);
  if ( !_mm_cvtsi64_si32(_m_pfcmpge(v82, (__m64)0x3F8000003F800000LL)) )
  {
    SquareRootApproximation(0, v54);
    v106 = _mm_cvtsi64_si32(v82);
    sub_529700();
    v80 = v135;
    v81 = v137;
    if ( _mm_cvtsi64_si32(_m_pfcmpge(_m_pand(v82, (__m64)0x7FFFFFFF7FFFFFFFLL), (__m64)0x3400000034000000LL)) )
    {
      v83 = _mm_cvtsi32_si64(v106);
      v84 = _m_pfrcp(v82);
      v85 = _m_pfmul(_m_punpckldq(v83, v83), _m_pfrcpit2(_m_pfrcpit1(v82, v84), v84));
      v80 = _m_pfmul(v135, v85);
      v81 = _m_pfmul(v137, v85);
    }
  }
  v129 = _m_pfmul(_m_pfadd(v121, v80), (__m64)0xBE800000BE800000uLL);
  v133 = _m_pfmul(_m_pfadd(v123, _m_pand(v81, (__m64)0xFFFFFFFFLL)), (__m64)0xBE800000BE800000uLL).m64_u32[0];
  v86 = _mm_cvtsi32_si64(v133);
  v87 = _m_pfadd(_m_pfmul(v129, v129), _m_pfmul(v86, v86));
  v88 = _m_pfacc(v87, v87);
  v89 = _m_pfrsqrt(v88);
  v90 = _m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v89, v89), v88), v89);
  v107.m64_u64 = __PAIR64__(v104.m64_u32[1], _mm_cvtsi64_si32(v90));
  PackedFloatingPointMath();
  v91 = _m_pfmul(v88, v90);
  v92 = _m_pfcmpge(_m_pand(v91, (__m64)0x7FFFFFFFFFFFFFFFLL), (__m64)0x3400000034000000LL);
  v93 = _mm_cvtsi64_si32(_m_punpckhdq(v92, v92));
  v94 = v129;
  v95 = v91;
  v96 = _m_pfmul(_m_punpckhdq(v91, v91), v107);
  v97 = _mm_cvtsi32_si64(v133);
  if ( (v93 & 1) != 0 )
  {
    v98 = _m_punpckldq(v96, v96);
    v97 = _m_pfmul(v97, v98);
    v94 = _m_pfmul(v129, v98);
  }
  v125 = _m_punpckldq(v97, v95);
  v99 = _m_punpckldq(_m_punpckhdq(v94, v94), v94);
  v100 = _m_punpckldq(_m_punpckhdq(v125, v125), v125);
  a3->m64_u64 = (unsigned __int64)_m_pfacc(
                                    _m_pfsub(_m_pfmul(v99, v113), _m_pfmul(_m_pxor(v100, (__m64)0x80000000LL), v112)),
                                    _m_pfadd(_m_pxor(_m_pfmul(v94, v113), (__m64)0x80000000LL), _m_pfmul(v125, v112)));
  a3[1].m64_u64 = (unsigned __int64)_m_pfacc(
                                      _m_pfadd(_m_pfmul(_m_pxor(v99, (__m64)0x80000000LL), v112), _m_pfmul(v100, v113)),
                                      _m_pfsub(_m_pfmul(_m_pxor(v125, (__m64)0x80000000LL), v113), _m_pfmul(v94, v112)));
  result = a4;
  a4->m64_u64 = (unsigned __int64)v112;
  a4[1].m64_u64 = (unsigned __int64)v113;
  _m_femms();
  return result;
}

