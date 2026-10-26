// f1c  0x00534120  size=2444
__m64 *__cdecl sub_534120(_WORD *a1, _WORD *a2, __m64 *a3)
{
  __m64 v3; // mm4
  __m64 v4; // mm5
  __m64 v5; // mm6
  __m64 v6; // mm7
  __m64 v7; // mm0
  __m64 v8; // mm1
  __m64 v9; // mm2
  __m64 v10; // mm3
  __m64 v11; // mm4
  __m64 v12; // mm5
  __m64 v13; // mm7
  __m64 v14; // mm7
  __int16 v15; // dx
  __m64 v16; // mm4
  __m64 v17; // mm5
  __m64 v18; // mm7
  __m64 v19; // mm6
  __m64 v20; // mm7
  __int16 v21; // dx
  __m64 v22; // mm4
  __m64 v23; // mm5
  __m64 v24; // mm7
  __m64 v25; // mm6
  __m64 v26; // mm7
  __int16 v27; // dx
  __m64 v28; // mm4
  __m64 v29; // mm5
  __m64 v30; // mm7
  __m64 v31; // mm6
  __m64 v32; // mm7
  __int16 v33; // dx
  __m64 v34; // mm4
  __m64 v35; // mm5
  __m64 v36; // mm7
  __m64 v37; // mm6
  __m64 v38; // mm7
  __int16 v39; // dx
  __m64 v40; // mm4
  __m64 v41; // mm5
  __m64 v42; // mm7
  __m64 v43; // mm6
  __m64 v44; // mm7
  __int16 v45; // dx
  __m64 v46; // mm4
  __m64 v47; // mm5
  __m64 v48; // mm7
  __m64 v49; // mm6
  __m64 v50; // mm7
  __int16 v51; // dx
  __m64 v52; // mm4
  __m64 v53; // mm5
  __m64 v54; // mm7
  __m64 v55; // mm6
  __m64 v56; // mm7
  __int16 v57; // dx
  __m64 v58; // mm4
  __m64 v59; // mm5
  __m64 v60; // mm7
  __m64 v61; // mm6
  __m64 v62; // mm7
  __int16 v63; // dx
  __m64 v64; // mm4
  __m64 v65; // mm5
  __m64 v66; // mm7
  __m64 v67; // mm6
  __m64 v68; // mm7
  __int16 v69; // dx
  __m64 v70; // mm4
  __m64 v71; // mm5
  __m64 v72; // mm7
  __m64 v73; // mm6
  __m64 v74; // mm7
  __int16 v75; // dx
  __m64 v76; // mm4
  __m64 v77; // mm5
  __m64 v78; // mm7
  __m64 v79; // mm6
  __m64 v80; // mm7
  __int16 v81; // dx
  __m64 v82; // mm4
  __m64 v83; // mm5
  __m64 v84; // mm7
  __m64 v85; // mm6
  __m64 v86; // mm7
  __int16 v87; // dx
  __m64 v88; // mm4
  __m64 v89; // mm5
  __m64 v90; // mm7
  __m64 v91; // mm6
  __m64 v92; // mm7
  __int16 v93; // dx
  __m64 v94; // mm4
  __m64 v95; // mm5
  __m64 v96; // mm7
  __m64 v97; // mm6
  __m64 v98; // mm7
  __int16 v99; // dx
  __m64 *result; // eax
  __m64 v101; // mm4
  __m64 v102; // mm5
  __m64 v103; // mm7
  __m64 v104; // mm6
  __m64 v105; // mm7
  __int16 v106; // dx
  __m64 v107; // mm4
  __m64 v108; // mm5
  __m64 v109; // mm7
  __m64 v110; // mm6
  __m64 v111; // mm7
  __int16 v112; // dx
  __m64 v113; // mm4
  __m64 v114; // mm5
  __m64 v115; // mm7
  __m64 v116; // mm6
  __m64 v117; // mm7
  __int16 v118; // dx
  __m64 v119; // mm4
  __m64 v120; // mm5
  __m64 v121; // mm7
  __m64 v122; // mm6
  __m64 v123; // mm7
  __int16 v124; // dx
  __m64 v125; // mm4
  __m64 v126; // mm5
  __m64 v127; // mm7
  __m64 v128; // mm6
  __m64 v129; // mm7
  __int16 v130; // dx
  __m64 v131; // mm4
  __m64 v132; // mm5
  __m64 v133; // mm7
  __m64 v134; // mm6
  __m64 v135; // mm7
  __int16 v136; // dx
  __m64 v137; // mm4
  __m64 v138; // mm5
  __m64 v139; // mm7
  __m64 v140; // mm6
  __m64 v141; // mm7
  __int16 v142; // dx
  __m64 v143; // mm4
  __m64 v144; // mm5
  __m64 v145; // mm7
  __m64 v146; // mm6
  __m64 v147; // mm7
  __int16 v148; // dx
  __m64 v149; // mm4
  __m64 v150; // mm5
  __m64 v151; // mm7
  __m64 v152; // mm6
  __m64 v153; // mm7
  __int16 v154; // dx
  __m64 v155; // mm4
  __m64 v156; // mm5
  __m64 v157; // mm7
  __m64 v158; // mm6
  __m64 v159; // mm7
  __int16 v160; // dx
  __m64 v161; // mm4
  __m64 v162; // mm5
  __m64 v163; // mm7
  __m64 v164; // mm6
  __m64 v165; // mm7
  __int16 v166; // dx
  __m64 v167; // mm4
  __m64 v168; // mm5
  __m64 v169; // mm7
  __m64 v170; // mm6
  __m64 v171; // mm7
  __int16 v172; // dx
  __m64 v173; // mm4
  __m64 v174; // mm5
  __m64 v175; // mm7
  __m64 v176; // mm6
  __m64 v177; // mm7
  __int16 v178; // dx
  __m64 v179; // mm4
  __m64 v180; // mm5
  __m64 v181; // mm7
  __m64 v182; // mm6
  __m64 v183; // mm7
  __int16 v184; // dx
  __m64 v185; // mm4
  __m64 v186; // mm5
  __m64 v187; // mm7
  __m64 v188; // mm6
  __m64 v189; // mm7
  __int16 v190; // dx
  __m64 v191; // mm4
  __m64 v192; // mm5
  __m64 v193; // mm7
  __m64 v194; // mm6
  __m64 v195; // mm7
  __m64 v196; // [esp+0h] [ebp-2Ch]
  __m64 v197; // [esp+8h] [ebp-24h]
  __m64 v198; // [esp+10h] [ebp-1Ch]
  __m64 v199; // [esp+18h] [ebp-14h]

  v3 = _m_punpckldq(_m_psrlqi(_m_punpckhdq(a3[7], a3[7]), 0x10u), _m_psrlqi(_m_punpckldq(a3[7], a3[7]), 0x10u));
  v4 = _m_punpckldq(_m_psrlqi(_m_punpckhdq(a3[6], a3[6]), 0x10u), _m_psrlqi(_m_punpckldq(a3[6], a3[6]), 0x10u));
  v5 = _m_punpckldq(_m_psrlqi(_m_punpckhdq(a3[5], a3[5]), 0x10u), _m_psrlqi(_m_punpckldq(a3[5], a3[5]), 0x10u));
  v6 = _m_punpckldq(_m_psrlqi(_m_punpckhdq(a3[4], a3[4]), 0x10u), _m_psrlqi(_m_punpckldq(a3[4], a3[4]), 0x10u));
  v196 = _m_psubw((__m64)a3->m64_u64, v3);
  v197 = _m_psubw(a3[1], v4);
  v198 = _m_psubw(a3[2], v5);
  v199 = _m_psubw(a3[3], v6);
  v7 = _m_paddw((__m64)a3->m64_u64, v3);
  v8 = _m_paddw(a3[1], v4);
  v9 = _m_paddw(a3[2], v5);
  v10 = _m_paddw(a3[3], v6);
  v11.m64_u64 = unk_8D7220;
  v12.m64_u64 = unk_8D7228;
  v13 = _m_paddd(
          _m_paddd(_m_pmaddwd(unk_8D7210, v9), _m_pmaddwd(unk_8D7200, v7)),
          _m_paddd(_m_pmaddwd(unk_8D7218, v10), _m_pmaddwd(unk_8D7208, v8)));
  a1[256] = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v13, 0x20u), v13), 0xEu));
  v14 = _m_paddd(
          _m_paddd(_m_pmaddwd(unk_8D7230, v9), _m_pmaddwd(v11, v7)),
          _m_paddd(_m_pmaddwd(unk_8D7238, v10), _m_pmaddwd(v12, v8)));
  v15 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v14, 0x20u), v14), 0xEu));
  v16 = _m_pmaddwd(unk_8D7240, v7);
  v17 = _m_pmaddwd(unk_8D7248, v8);
  v18.m64_u64 = unk_8D7258;
  v19 = _m_pmaddwd(unk_8D7250, v9);
  a1[224] = v15;
  v20 = _m_paddd(_m_paddd(v19, v16), _m_paddd(_m_pmaddwd(v18, v10), v17));
  v21 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v20, 0x20u), v20), 0xEu));
  v22 = _m_pmaddwd(unk_8D7260, v7);
  v23 = _m_pmaddwd(unk_8D7268, v8);
  v24.m64_u64 = unk_8D7278;
  v25 = _m_pmaddwd(unk_8D7270, v9);
  a1[192] = v21;
  v26 = _m_paddd(_m_paddd(v25, v22), _m_paddd(_m_pmaddwd(v24, v10), v23));
  v27 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v26, 0x20u), v26), 0xEu));
  v28 = _m_pmaddwd(unk_8D7280, v7);
  v29 = _m_pmaddwd(unk_8D7288, v8);
  v30.m64_u64 = unk_8D7298;
  v31 = _m_pmaddwd(unk_8D7290, v9);
  a1[160] = v27;
  v32 = _m_paddd(_m_paddd(v31, v28), _m_paddd(_m_pmaddwd(v30, v10), v29));
  v33 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v32, 0x20u), v32), 0xEu));
  v34 = _m_pmaddwd(unk_8D72A0, v7);
  v35 = _m_pmaddwd(unk_8D72A8, v8);
  v36.m64_u64 = unk_8D72B8;
  v37 = _m_pmaddwd(unk_8D72B0, v9);
  a1[128] = v33;
  v38 = _m_paddd(_m_paddd(v37, v34), _m_paddd(_m_pmaddwd(v36, v10), v35));
  v39 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v38, 0x20u), v38), 0xEu));
  v40 = _m_pmaddwd(unk_8D72C0, v7);
  v41 = _m_pmaddwd(unk_8D72C8, v8);
  v42.m64_u64 = unk_8D72D8;
  v43 = _m_pmaddwd(unk_8D72D0, v9);
  a1[96] = v39;
  v44 = _m_paddd(_m_paddd(v43, v40), _m_paddd(_m_pmaddwd(v42, v10), v41));
  v45 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v44, 0x20u), v44), 0xEu));
  v46 = _m_pmaddwd(unk_8D72E0, v7);
  v47 = _m_pmaddwd(unk_8D72E8, v8);
  v48.m64_u64 = unk_8D72F8;
  v49 = _m_pmaddwd(unk_8D72F0, v9);
  a1[64] = v45;
  v50 = _m_paddd(_m_paddd(v49, v46), _m_paddd(_m_pmaddwd(v48, v10), v47));
  v51 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v50, 0x20u), v50), 0xEu));
  v52 = _m_pmaddwd(unk_8D7300, v7);
  v53 = _m_pmaddwd(unk_8D7308, v8);
  v54.m64_u64 = unk_8D7318;
  v55 = _m_pmaddwd(unk_8D7310, v9);
  a1[32] = v51;
  v56 = _m_paddd(_m_paddd(v55, v52), _m_paddd(_m_pmaddwd(v54, v10), v53));
  v57 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v56, 0x20u), v56), 0xEu));
  v58 = _m_pmaddwd(unk_8D7320, v7);
  v59 = _m_pmaddwd(unk_8D7328, v8);
  v60.m64_u64 = unk_8D7338;
  v61 = _m_pmaddwd(unk_8D7330, v9);
  *a1 = v57;
  *a2 = v57;
  v62 = _m_paddd(_m_paddd(v61, v58), _m_paddd(_m_pmaddwd(v60, v10), v59));
  v63 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v62, 0x20u), v62), 0xEu));
  v64 = _m_pmaddwd(unk_8D7340, v7);
  v65 = _m_pmaddwd(unk_8D7348, v8);
  v66.m64_u64 = unk_8D7358;
  v67 = _m_pmaddwd(unk_8D7350, v9);
  a2[32] = v63;
  v68 = _m_paddd(_m_paddd(v67, v64), _m_paddd(_m_pmaddwd(v66, v10), v65));
  v69 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v68, 0x20u), v68), 0xEu));
  v70 = _m_pmaddwd(unk_8D7360, v7);
  v71 = _m_pmaddwd(unk_8D7368, v8);
  v72.m64_u64 = unk_8D7378;
  v73 = _m_pmaddwd(unk_8D7370, v9);
  a2[64] = v69;
  v74 = _m_paddd(_m_paddd(v73, v70), _m_paddd(_m_pmaddwd(v72, v10), v71));
  v75 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v74, 0x20u), v74), 0xEu));
  v76 = _m_pmaddwd(unk_8D7380, v7);
  v77 = _m_pmaddwd(unk_8D7388, v8);
  v78.m64_u64 = unk_8D7398;
  v79 = _m_pmaddwd(unk_8D7390, v9);
  a2[96] = v75;
  v80 = _m_paddd(_m_paddd(v79, v76), _m_paddd(_m_pmaddwd(v78, v10), v77));
  v81 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v80, 0x20u), v80), 0xEu));
  v82 = _m_pmaddwd(unk_8D73A0, v7);
  v83 = _m_pmaddwd(unk_8D73A8, v8);
  v84.m64_u64 = unk_8D73B8;
  v85 = _m_pmaddwd(unk_8D73B0, v9);
  a2[128] = v81;
  v86 = _m_paddd(_m_paddd(v85, v82), _m_paddd(_m_pmaddwd(v84, v10), v83));
  v87 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v86, 0x20u), v86), 0xEu));
  v88 = _m_pmaddwd(unk_8D73C0, v7);
  v89 = _m_pmaddwd(unk_8D73C8, v8);
  v90.m64_u64 = unk_8D73D8;
  v91 = _m_pmaddwd(unk_8D73D0, v9);
  a2[160] = v87;
  v92 = _m_paddd(_m_paddd(v91, v88), _m_paddd(_m_pmaddwd(v90, v10), v89));
  v93 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v92, 0x20u), v92), 0xEu));
  v94 = _m_pmaddwd(unk_8D73E0, v7);
  v95 = _m_pmaddwd(unk_8D73E8, v8);
  v96.m64_u64 = unk_8D73F8;
  v97 = _m_pmaddwd(unk_8D73F0, v9);
  a2[192] = v93;
  v98 = _m_paddd(_m_paddd(v97, v94), _m_paddd(_m_pmaddwd(v96, v10), v95));
  v99 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v98, 0x20u), v98), 0xEu));
  result = qword_8D7000;
  v101 = _m_pmaddwd(qword_8D7000[0], v196);
  v102 = _m_pmaddwd(qword_8D7000[1], v197);
  v103 = qword_8D7000[3];
  v104 = _m_pmaddwd(qword_8D7000[2], v198);
  a2[224] = v99;
  v105 = _m_paddd(_m_paddd(v104, v101), _m_paddd(_m_pmaddwd(v103, v199), v102));
  v106 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v105, 0x20u), v105), 0xEu));
  v107 = _m_pmaddwd(qword_8D7000[4], v196);
  v108 = _m_pmaddwd(qword_8D7000[5], v197);
  v109 = qword_8D7000[7];
  v110 = _m_pmaddwd(qword_8D7000[6], v198);
  a1[240] = v106;
  v111 = _m_paddd(_m_paddd(v110, v107), _m_paddd(_m_pmaddwd(v109, v199), v108));
  v112 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v111, 0x20u), v111), 0xEu));
  v113 = _m_pmaddwd(qword_8D7000[8], v196);
  v114 = _m_pmaddwd(qword_8D7000[9], v197);
  v115 = qword_8D7000[11];
  v116 = _m_pmaddwd(qword_8D7000[10], v198);
  a1[208] = v112;
  v117 = _m_paddd(_m_paddd(v116, v113), _m_paddd(_m_pmaddwd(v115, v199), v114));
  v118 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v117, 0x20u), v117), 0xEu));
  v119 = _m_pmaddwd(qword_8D7000[12], v196);
  v120 = _m_pmaddwd(qword_8D7000[13], v197);
  v121 = qword_8D7000[15];
  v122 = _m_pmaddwd(qword_8D7000[14], v198);
  a1[176] = v118;
  v123 = _m_paddd(_m_paddd(v122, v119), _m_paddd(_m_pmaddwd(v121, v199), v120));
  v124 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v123, 0x20u), v123), 0xEu));
  v125 = _m_pmaddwd(qword_8D7000[16], v196);
  v126 = _m_pmaddwd(qword_8D7000[17], v197);
  v127 = qword_8D7000[19];
  v128 = _m_pmaddwd(qword_8D7000[18], v198);
  a1[144] = v124;
  v129 = _m_paddd(_m_paddd(v128, v125), _m_paddd(_m_pmaddwd(v127, v199), v126));
  v130 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v129, 0x20u), v129), 0xEu));
  v131 = _m_pmaddwd(qword_8D7000[20], v196);
  v132 = _m_pmaddwd(qword_8D7000[21], v197);
  v133 = qword_8D7000[23];
  v134 = _m_pmaddwd(qword_8D7000[22], v198);
  a1[112] = v130;
  v135 = _m_paddd(_m_paddd(v134, v131), _m_paddd(_m_pmaddwd(v133, v199), v132));
  v136 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v135, 0x20u), v135), 0xEu));
  v137 = _m_pmaddwd(qword_8D7000[24], v196);
  v138 = _m_pmaddwd(qword_8D7000[25], v197);
  v139 = qword_8D7000[27];
  v140 = _m_pmaddwd(qword_8D7000[26], v198);
  a1[80] = v136;
  v141 = _m_paddd(_m_paddd(v140, v137), _m_paddd(_m_pmaddwd(v139, v199), v138));
  v142 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v141, 0x20u), v141), 0xEu));
  v143 = _m_pmaddwd(qword_8D7000[28], v196);
  v144 = _m_pmaddwd(qword_8D7000[29], v197);
  v145 = qword_8D7000[31];
  v146 = _m_pmaddwd(qword_8D7000[30], v198);
  a1[48] = v142;
  v147 = _m_paddd(_m_paddd(v146, v143), _m_paddd(_m_pmaddwd(v145, v199), v144));
  v148 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v147, 0x20u), v147), 0xEu));
  v149 = _m_pmaddwd(qword_8D7000[32], v196);
  v150 = _m_pmaddwd(qword_8D7000[33], v197);
  v151 = qword_8D7000[35];
  v152 = _m_pmaddwd(qword_8D7000[34], v198);
  a1[16] = v148;
  v153 = _m_paddd(_m_paddd(v152, v149), _m_paddd(_m_pmaddwd(v151, v199), v150));
  v154 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v153, 0x20u), v153), 0xEu));
  v155 = _m_pmaddwd(qword_8D7000[36], v196);
  v156 = _m_pmaddwd(qword_8D7000[37], v197);
  v157 = qword_8D7000[39];
  v158 = _m_pmaddwd(qword_8D7000[38], v198);
  a2[16] = v154;
  v159 = _m_paddd(_m_paddd(v158, v155), _m_paddd(_m_pmaddwd(v157, v199), v156));
  v160 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v159, 0x20u), v159), 0xEu));
  v161 = _m_pmaddwd(qword_8D7000[40], v196);
  v162 = _m_pmaddwd(qword_8D7000[41], v197);
  v163 = qword_8D7000[43];
  v164 = _m_pmaddwd(qword_8D7000[42], v198);
  a2[48] = v160;
  v165 = _m_paddd(_m_paddd(v164, v161), _m_paddd(_m_pmaddwd(v163, v199), v162));
  v166 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v165, 0x20u), v165), 0xEu));
  v167 = _m_pmaddwd(qword_8D7000[44], v196);
  v168 = _m_pmaddwd(qword_8D7000[45], v197);
  v169 = qword_8D7000[47];
  v170 = _m_pmaddwd(qword_8D7000[46], v198);
  a2[80] = v166;
  v171 = _m_paddd(_m_paddd(v170, v167), _m_paddd(_m_pmaddwd(v169, v199), v168));
  v172 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v171, 0x20u), v171), 0xEu));
  v173 = _m_pmaddwd(qword_8D7000[48], v196);
  v174 = _m_pmaddwd(qword_8D7000[49], v197);
  v175 = qword_8D7000[51];
  v176 = _m_pmaddwd(qword_8D7000[50], v198);
  a2[112] = v172;
  v177 = _m_paddd(_m_paddd(v176, v173), _m_paddd(_m_pmaddwd(v175, v199), v174));
  v178 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v177, 0x20u), v177), 0xEu));
  v179 = _m_pmaddwd(qword_8D7000[52], v196);
  v180 = _m_pmaddwd(qword_8D7000[53], v197);
  v181 = qword_8D7000[55];
  v182 = _m_pmaddwd(qword_8D7000[54], v198);
  a2[144] = v178;
  v183 = _m_paddd(_m_paddd(v182, v179), _m_paddd(_m_pmaddwd(v181, v199), v180));
  v184 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v183, 0x20u), v183), 0xEu));
  v185 = _m_pmaddwd(qword_8D7000[56], v196);
  v186 = _m_pmaddwd(qword_8D7000[57], v197);
  v187 = qword_8D7000[59];
  v188 = _m_pmaddwd(qword_8D7000[58], v198);
  a2[176] = v184;
  v189 = _m_paddd(_m_paddd(v188, v185), _m_paddd(_m_pmaddwd(v187, v199), v186));
  v190 = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v189, 0x20u), v189), 0xEu));
  v191 = _m_pmaddwd(qword_8D7000[60], v196);
  v192 = _m_pmaddwd(qword_8D7000[61], v197);
  v193 = qword_8D7000[63];
  v194 = _m_pmaddwd(qword_8D7000[62], v198);
  a2[208] = v190;
  v195 = _m_paddd(_m_paddd(v194, v191), _m_paddd(_m_pmaddwd(v193, v199), v192));
  a2[240] = _mm_cvtsi64_si32(_m_psradi(_m_paddd(_m_psrlqi(v195, 0x20u), v195), 0xEu));
  return result;
}
