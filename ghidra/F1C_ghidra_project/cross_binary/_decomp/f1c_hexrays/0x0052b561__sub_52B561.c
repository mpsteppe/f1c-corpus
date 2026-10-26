// f1c  0x0052b561  size=3539
char __cdecl sub_52B561(__m64 *a1, __m64 *a2, __m64 *a3, _DWORD *a4, int a5, int a6)
{
  __m64 v6; // mm0
  __m64 v7; // mm2
  __m64 v8; // mm5
  __m64 v9; // mm6
  __m64 v10; // mm2
  __m64 v11; // mm4
  __m64 v12; // mm3
  __m64 v13; // mm4
  __m64 v14; // mm5
  __m64 v15; // mm6
  __m64 v16; // mm0
  __m64 v17; // mm3
  __m64 v18; // mm7
  __m64 v19; // mm4
  __m64 v20; // mm3
  __m64 v21; // mm0
  __m64 v22; // mm5
  __m64 v23; // mm4
  __m64 v24; // mm0
  __m64 v25; // mm4
  __m64 v26; // mm5
  __m64 v27; // mm2
  __m64 v28; // mm1
  __m64 v29; // mm0
  __m64 v30; // mm3
  __m64 v31; // mm4
  __m64 v32; // mm1
  __m64 v33; // mm2
  __m64 v34; // mm4
  __m64 v35; // mm0
  __m64 v36; // mm6
  __m64 v37; // mm3
  __m64 v38; // mm0
  __m64 v39; // mm1
  __m64 m64_u64; // mm6
  __m64 v41; // mm1
  __m64 v42; // mm7
  __m64 v43; // mm5
  __m64 v44; // mm2
  __m64 v45; // mm4
  __m64 v46; // mm0
  __m64 v47; // mm1
  __m64 v48; // mm4
  __m64 v49; // mm3
  __m64 v50; // mm1
  __m64 v51; // mm6
  __m64 v52; // mm5
  __m64 v53; // mm6
  __m64 v54; // mm7
  __m64 v55; // mm3
  __m64 v56; // mm0
  __m64 v57; // mm3
  __m64 v58; // mm4
  __m64 v59; // mm6
  __m64 v60; // mm5
  __m64 v61; // mm6
  __m64 v62; // mm4
  __m64 v63; // mm5
  __m64 v64; // mm1
  __m64 v65; // mm2
  __m64 v66; // mm7
  __m64 v67; // mm3
  __m64 v68; // mm6
  __m64 v69; // mm3
  __m64 v70; // mm1
  __m64 v71; // mm4
  __m64 v72; // mm0
  __m64 v73; // mm2
  __m64 v74; // mm6
  __m64 v75; // mm1
  __m64 v76; // mm0
  __m64 v77; // mm5
  __m64 v78; // mm6
  __m64 v79; // mm0
  __m64 v80; // mm5
  __m64 v81; // mm0
  __m64 v82; // mm6
  __m64 v83; // mm2
  __m64 v84; // mm3
  __m64 v85; // mm7
  __m64 v86; // mm2
  __m64 v87; // mm5
  __m64 v88; // mm4
  __m64 v89; // mm3
  __m64 v90; // mm2
  __m64 v91; // mm7
  __m64 v92; // mm3
  __m64 v93; // mm1
  __m64 v94; // mm2
  __m64 v95; // mm0
  __m64 v96; // mm2
  __m64 v97; // mm1
  __m64 v98; // mm4
  __m64 v99; // mm3
  __m64 v100; // mm4
  __m64 v101; // mm1
  __m64 v102; // mm5
  __m64 v103; // mm0
  __m64 v104; // mm1
  __m64 v105; // mm3
  __m64 v106; // mm2
  __m64 v107; // mm5
  __m64 v108; // mm4
  __m64 v109; // mm1
  __m64 v110; // mm0
  __m64 v111; // mm3
  __m64 v112; // mm1
  __m64 v113; // mm4
  __m64 v114; // mm2
  __m64 v115; // mm0
  __m64 v116; // mm2
  __m64 v117; // mm0
  __m64 v118; // mm2
  __m64 v119; // mm5
  __m64 v120; // mm4
  __m64 v121; // mm2
  __m64 v122; // mm1
  __m64 v123; // mm4
  __m64 v124; // mm6
  __m64 v125; // mm5
  __m64 v126; // mm0
  __m64 v127; // mm3
  __m64 v128; // mm7
  __m64 v129; // mm4
  __m64 v130; // mm3
  __m64 v131; // mm0
  __m64 v132; // mm2
  __m64 v133; // mm6
  __m64 v134; // mm4
  __m64 v135; // mm5
  __m64 v136; // mm1
  __m64 v137; // mm0
  __m64 v138; // mm3
  __m64 v139; // mm1
  __m64 v140; // mm2
  __m64 v141; // mm4
  __m64 v142; // mm0
  __m64 v143; // mm6
  __m64 v144; // mm3
  __m64 v145; // mm0
  __m64 v146; // mm1
  __m64 v147; // mm6
  __m64 v148; // mm1
  __m64 v149; // mm7
  __m64 v150; // mm5
  __m64 v151; // mm2
  __m64 v152; // mm6
  __m64 v153; // mm4
  __m64 v154; // mm3
  __m64 v155; // mm1
  __m64 v156; // mm5
  __m64 v157; // mm7
  __m64 v158; // mm6
  __m64 v159; // mm4
  __m64 v160; // mm3
  __m64 v161; // mm0
  __m64 v162; // mm3
  __m64 v163; // mm6
  __m64 v164; // mm5
  __m64 v165; // mm6
  __m64 v166; // mm4
  __m64 v167; // mm5
  __m64 v168; // mm1
  __m64 v169; // mm2
  __m64 v170; // mm4
  __m64 v171; // mm2
  __m64 v172; // mm3
  __m64 v173; // mm6
  __m64 v174; // mm3
  __m64 v175; // mm1
  __m64 v176; // mm4
  __m64 v177; // mm2
  __m64 v178; // mm6
  __m64 v179; // mm1
  __m64 v180; // mm5
  __m64 v181; // mm0
  __m64 v182; // mm6
  _BYTE *v183; // ebx
  __m64 v184; // mm0
  __m64 v185; // mm5
  __m64 v186; // mm0
  __m64 v187; // mm2
  __m64 v188; // mm6
  __m64 v189; // mm3
  __m64 v190; // mm7
  __m64 v191; // mm2
  __m64 v192; // mm4
  __m64 v193; // mm5
  __m64 v194; // mm5
  __m64 v195; // mm5
  _BYTE *v196; // ebx
  __m64 v197; // mm4
  __m64 v198; // mm3
  __m64 v199; // mm4
  __m64 v200; // mm4
  __m64 v201; // mm4
  _BYTE *v202; // ecx
  __m64 v203; // mm0
  __m64 v204; // mm0
  __m64 v205; // mm0
  _BYTE *v206; // ebx
  __m64 v207; // mm3
  __m64 v208; // mm3
  __m64 v209; // mm3
  _BYTE *v210; // ebx
  __m64 v211; // mm4
  __m64 v212; // mm5
  __m64 v213; // mm2
  __m64 v214; // mm3
  __m64 v215; // mm7
  __m64 v216; // mm3
  __m64 v217; // mm1
  __m64 v218; // mm6
  __m64 v219; // mm6
  __m64 v220; // mm6
  _BYTE *v221; // ebx
  __m64 v222; // mm2
  __m64 v223; // mm2
  __m64 v224; // mm2
  _BYTE *v225; // ecx
  __m64 v226; // mm5
  __m64 v227; // mm5
  __m64 v228; // mm5
  _BYTE *v229; // ebx
  __m64 v230; // mm1
  __m64 v231; // mm1
  __m64 v232; // mm1
  _BYTE *v233; // ebx
  __m64 v234; // mm1
  __m64 v235; // mm2
  __m64 v236; // mm0
  __m64 v237; // mm2
  __m64 v238; // mm4
  __m64 v239; // mm1
  __m64 v240; // mm5
  __m64 v241; // mm3
  __m64 v242; // mm4
  __m64 v243; // mm1
  __m64 v244; // mm0
  __m64 v245; // mm1
  __m64 v246; // mm3
  __m64 v247; // mm0
  __m64 v248; // mm0
  __m64 v249; // mm0
  _BYTE *v250; // ebx
  __m64 v251; // mm2
  __m64 v252; // mm5
  __m64 v253; // mm4
  __m64 v254; // mm1
  __m64 v255; // mm1
  __m64 v256; // mm1
  _BYTE *v257; // ecx
  __m64 v258; // mm0
  __m64 v259; // mm1
  __m64 v260; // mm3
  __m64 v261; // mm1
  __m64 v262; // mm4
  __m64 v263; // mm2
  __m64 v264; // mm2
  __m64 v265; // mm2
  _BYTE *v266; // ebx
  __m64 v267; // mm2
  __m64 v268; // mm5
  __m64 v269; // mm5
  __m64 v270; // mm5
  __m64 v271; // mm0
  __m64 v272; // mm2
  __m64 v273; // mm4
  __m64 v274; // mm5
  _BYTE *v275; // ebx
  __m64 v276; // mm3
  __m64 v277; // mm3
  __m64 v278; // mm3
  _BYTE *v279; // ebx
  __m64 v280; // mm4
  __m64 v281; // mm4
  __m64 v282; // mm4
  _BYTE *v283; // ecx
  __m64 v284; // mm1
  __m64 v285; // mm1
  __m64 v286; // mm1
  _BYTE *v287; // ebx
  __m64 v288; // mm5
  __m64 v289; // mm5
  __m64 v290; // mm5
  char result; // al
  __m64 v292; // [esp+14h] [ebp-10h]
  __m64 v293; // [esp+14h] [ebp-10h]
  __m64 v294; // [esp+1Ch] [ebp-8h]

  v6 = _m_pmullw(a1[12], a3[12]);
  v7 = _m_pmullw(a1[4], a3[4]);
  v8 = _m_pmullw(a1[8], a3[8]);
  v9 = _m_psubw(v7, v6);
  v10 = _m_paddw(v7, v6);
  v11 = _m_pmullw((__m64)a1->m64_u64, (__m64)a3->m64_u64);
  v12 = _m_paddw(v11, v8);
  v13 = _m_psubw(v11, v8);
  v14 = _m_psubw(
          _m_packssdw(
            _m_psradi(_m_pmaddwd(_m_punpcklwd(v9, 0), (__m64)0x16A0000016ALL), 8u),
            _m_psradi(_m_pmaddwd(_m_punpckhwd(v9, 0), (__m64)0x16A0000016ALL), 8u)),
          v10);
  a2[4].m64_u64 = (unsigned __int64)_m_paddw(v12, v10);
  a2[12].m64_u64 = (unsigned __int64)_m_paddw(v14, v13);
  v15 = _m_psubw(v12, v10);
  a2->m64_u64 = (unsigned __int64)_m_psubw(v13, v14);
  v16 = _m_pmullw(a1[6], a3[6]);
  v17 = _m_pmullw(a1[10], a3[10]);
  v18 = _m_psubw(v17, v16);
  v19 = _m_pmullw(a1[14], a3[14]);
  v20 = _m_paddw(v17, v16);
  v21 = _m_pmullw(a1[2], a3[2]);
  v22 = _m_paddw(v21, v19);
  v23 = _m_psubw(v21, v19);
  v292 = _m_packssdw(
           _m_psradi(_m_pmaddwd(_m_punpcklwd(v23, 0), (__m64)0x11500000115LL), 8u),
           _m_psradi(_m_pmaddwd(_m_punpckhwd(v23, 0), (__m64)0x11500000115LL), 8u));
  v24 = _m_paddw(v18, v23);
  v25 = v22;
  v26 = _m_paddw(v22, v20);
  v27 = _m_psubw(v25, v20);
  v28 = _m_packssdw(
          _m_psradi(_m_pmaddwd(_m_punpcklwd(v24, 0), (__m64)0x1D9000001D9LL), 8u),
          _m_psradi(_m_pmaddwd(_m_punpckhwd(v24, 0), (__m64)0x1D9000001D9LL), 8u));
  v29 = _m_psubw(v292, v28);
  v30 = v15;
  v31 = _m_packssdw(
          _m_psradi(_m_pmaddwd(_m_punpcklwd(v27, 0), (__m64)0x16A0000016ALL), 8u),
          _m_psradi(_m_pmaddwd(_m_punpckhwd(v27, 0), (__m64)0x16A0000016ALL), 8u));
  v32 = _m_psubw(
          _m_paddw(
            v28,
            _m_packssdw(
              _m_psradi(_m_pmaddwd(_m_punpcklwd(v18, 0), (__m64)0xFD630000FD63LL), 8u),
              _m_psradi(_m_pmaddwd(_m_punpckhwd(v18, 0), (__m64)0xFD630000FD63LL), 8u))),
          v26);
  v33 = a2[12];
  v34 = _m_psubw(v31, v32);
  v35 = _m_paddw(v29, v34);
  v36 = _m_psubw(v15, v35);
  v37 = _m_paddw(v30, v35);
  v38 = v32;
  v39 = a2[4];
  a2[8].m64_u64 = (unsigned __int64)v37;
  a2[6].m64_u64 = (unsigned __int64)v36;
  m64_u64 = (__m64)a2->m64_u64;
  a2->m64_u64 = (unsigned __int64)_m_paddw(v39, v26);
  a2[14].m64_u64 = (unsigned __int64)_m_psubw(v39, v26);
  a2[2].m64_u64 = (unsigned __int64)_m_paddw(v33, v38);
  a2[12].m64_u64 = (unsigned __int64)_m_psubw(v33, v38);
  v41 = _m_pmullw(a1[5], a3[5]);
  a2[4].m64_u64 = (unsigned __int64)_m_paddw(m64_u64, v34);
  a2[10].m64_u64 = (unsigned __int64)_m_psubw(m64_u64, v34);
  v42 = _m_pmullw(a1[13], a3[13]);
  v43 = _m_pmullw(a1[9], a3[9]);
  v44 = _m_paddw(v41, v42);
  v45 = _m_psubw(v41, v42);
  v46 = _m_pmullw(a1[11], a3[11]);
  v47 = _m_packssdw(
          _m_psradi(_m_pmaddwd(_m_punpcklwd(v45, 0), (__m64)0x16A0000016ALL), 8u),
          _m_psradi(_m_pmaddwd(_m_punpckhwd(v45, 0), (__m64)0x16A0000016ALL), 8u));
  v48 = _m_pmullw(a1[1], a3[1]);
  v49 = _m_paddw(v48, v43);
  v50 = _m_psubw(v47, v44);
  v51 = a1[7];
  v52 = _m_psubw(v48, v43);
  a2[5].m64_u64 = (unsigned __int64)_m_paddw(v49, v44);
  v53 = _m_pmullw(v51, a3[7]);
  v54 = _m_psubw(v49, v44);
  a2[13].m64_u64 = (unsigned __int64)_m_paddw(v52, v50);
  v55 = v46;
  a2[9].m64_u64 = (unsigned __int64)_m_psubw(v52, v50);
  v56 = _m_paddw(v46, v53);
  v57 = _m_psubw(v55, v53);
  v58 = _m_pmullw(a1[15], a3[15]);
  v294 = v54;
  v59 = _m_pmullw(a1[3], a3[3]);
  v60 = _m_paddw(v59, v58);
  v61 = _m_psubw(v59, v58);
  v62 = v60;
  v63 = _m_paddw(v60, v56);
  v64 = _m_packssdw(
          _m_psradi(_m_pmaddwd(_m_punpcklwd(v57, 0), (__m64)0xFD630000FD63LL), 8u),
          _m_psradi(_m_pmaddwd(_m_punpckhwd(v57, 0), (__m64)0xFD630000FD63LL), 8u));
  v65 = _m_psubw(v62, v56);
  v66 = _m_paddw(v57, v61);
  v67 = _m_packssdw(
          _m_psradi(_m_pmaddwd(_m_punpcklwd(v66, 0), (__m64)0x1D9000001D9LL), 8u),
          _m_psradi(_m_pmaddwd(_m_punpckhwd(v66, 0), (__m64)0x1D9000001D9LL), 8u));
  v68 = _m_psubw(
          _m_packssdw(
            _m_psradi(_m_pmaddwd(_m_punpcklwd(v61, 0), (__m64)0x11500000115LL), 8u),
            _m_psradi(_m_pmaddwd(_m_punpckhwd(v61, 0), (__m64)0x11500000115LL), 8u)),
          v67);
  v69 = _m_psubw(_m_paddw(v67, v64), v63);
  v70 = a2[5];
  v71 = _m_psubw(
          _m_packssdw(
            _m_psradi(_m_pmaddwd(_m_punpcklwd(v65, 0), (__m64)0x16A0000016ALL), 8u),
            _m_psradi(_m_pmaddwd(_m_punpckhwd(v65, 0), (__m64)0x16A0000016ALL), 8u)),
          v69);
  v72 = _m_paddw(v70, v63);
  v73 = a2[13];
  v74 = _m_paddw(v68, v71);
  v75 = _m_psubw(v70, v63);
  a2[1].m64_u64 = (unsigned __int64)v72;
  v76 = a2[9];
  v77 = _m_paddw(v294, v74);
  a2[7].m64_u64 = (unsigned __int64)_m_psubw(v294, v74);
  a2[3].m64_u64 = (unsigned __int64)_m_paddw(v73, v69);
  v78 = _m_psubw(v76, v71);
  a2[5].m64_u64 = (unsigned __int64)_m_paddw(v76, v71);
  v79 = v77;
  v80 = _m_punpcklwd(v77, v78);
  v81 = _m_punpckhwd(v79, v78);
  v82 = (__m64)a2->m64_u64;
  v83 = _m_psubw(v73, v69);
  v84 = _m_punpcklwd(v83, v75);
  v85 = a2[2];
  v86 = _m_punpckhwd(v83, v75);
  a2[9].m64_u64 = (unsigned __int64)_m_punpckldq(v80, v84);
  a2[11].m64_u64 = (unsigned __int64)_m_punpckhdq(v80, v84);
  a2[13].m64_u64 = (unsigned __int64)_m_punpckldq(v81, v86);
  a2[15].m64_u64 = (unsigned __int64)_m_punpckhdq(v81, v86);
  v87 = _m_punpckhwd(v82, v85);
  v88 = a2[6];
  v89 = a2[4];
  v90 = _m_punpcklwd(v82, v85);
  v91 = _m_punpcklwd(v89, v88);
  v92 = _m_punpckhwd(v89, v88);
  a2->m64_u64 = (unsigned __int64)_m_punpckldq(v90, v91);
  a2[2].m64_u64 = (unsigned __int64)_m_punpckhdq(v90, v91);
  a2[4].m64_u64 = (unsigned __int64)_m_punpckldq(v87, v92);
  a2[6].m64_u64 = (unsigned __int64)_m_punpckhdq(v87, v92);
  v93 = a2[3];
  v94 = a2[1];
  v95 = _m_punpcklwd(v94, v93);
  v96 = _m_punpckhwd(v94, v93);
  v97 = a2[7];
  v98 = a2[5];
  v99 = _m_punpcklwd(v98, v97);
  v100 = _m_punpckhwd(v98, v97);
  v101 = v95;
  v102 = v96;
  v103 = _m_punpckldq(v95, v99);
  v104 = _m_punpckhdq(v101, v99);
  v105 = a2[8];
  a2[8].m64_u64 = (unsigned __int64)v103;
  v106 = _m_punpckldq(v96, v100);
  v107 = _m_punpckhdq(v102, v100);
  v108 = a2[10];
  a2[10].m64_u64 = (unsigned __int64)v104;
  v109 = v105;
  v110 = a2[12];
  v111 = _m_punpcklwd(v105, v108);
  v112 = _m_punpckhwd(v109, v108);
  v113 = a2[14];
  a2[12].m64_u64 = (unsigned __int64)v106;
  v114 = v110;
  a2[14].m64_u64 = (unsigned __int64)v107;
  v115 = _m_punpcklwd(v110, v113);
  v116 = _m_punpckhwd(v114, v113);
  a2[1].m64_u64 = (unsigned __int64)_m_punpckldq(v111, v115);
  a2[3].m64_u64 = (unsigned __int64)_m_punpckhdq(v111, v115);
  a2[5].m64_u64 = (unsigned __int64)_m_punpckldq(v112, v116);
  a2[7].m64_u64 = (unsigned __int64)_m_punpckhdq(v112, v116);
  v117 = a2[12];
  v118 = a2[4];
  v119 = a2[8];
  v120 = _m_psubw(v118, v117);
  v121 = _m_paddw(v118, v117);
  v122 = _m_packssdw(
           _m_psradi(_m_pmaddwd(_m_punpcklwd(v120, 0), (__m64)0x16A0000016ALL), 8u),
           _m_psradi(_m_pmaddwd(_m_punpckhwd(v120, 0), (__m64)0x16A0000016ALL), 8u));
  v123 = _m_psubw((__m64)a2->m64_u64, v119);
  v124 = _m_paddw((__m64)a2->m64_u64, v119);
  v125 = _m_psubw(v122, v121);
  a2[4].m64_u64 = (unsigned __int64)_m_paddw(v124, v121);
  a2[12].m64_u64 = (unsigned __int64)_m_paddw(v125, v123);
  a2->m64_u64 = (unsigned __int64)_m_psubw(v123, v125);
  v126 = a2[6];
  v127 = a2[10];
  v128 = _m_psubw(v127, v126);
  v129 = a2[14];
  v130 = _m_paddw(v127, v126);
  v293 = _m_psubw(v124, v121);
  v131 = a2[2];
  v132 = _m_psubw(v131, v129);
  v133 = _m_paddw(v128, v132);
  v134 = _m_paddw(v131, v129);
  v135 = _m_paddw(v134, v130);
  v136 = _m_packssdw(
           _m_psradi(_m_pmaddwd(_m_punpcklwd(v133, 0), (__m64)0x1D9000001D9LL), 8u),
           _m_psradi(_m_pmaddwd(_m_punpckhwd(v133, 0), (__m64)0x1D9000001D9LL), 8u));
  v137 = _m_psubw(
           _m_packssdw(
             _m_psradi(_m_pmaddwd(_m_punpcklwd(v132, 0), (__m64)0x11500000115LL), 8u),
             _m_psradi(_m_pmaddwd(_m_punpckhwd(v132, 0), (__m64)0x11500000115LL), 8u)),
           v136);
  v138 = _m_psubw(v134, v130);
  v139 = _m_psubw(
           _m_paddw(
             v136,
             _m_packssdw(
               _m_psradi(_m_pmaddwd(_m_punpcklwd(v128, 0), (__m64)0xFD630000FD63LL), 8u),
               _m_psradi(_m_pmaddwd(_m_punpckhwd(v128, 0), (__m64)0xFD630000FD63LL), 8u))),
           v135);
  v140 = a2[12];
  v141 = _m_psubw(
           _m_packssdw(
             _m_psradi(_m_pmaddwd(_m_punpcklwd(v138, 0), (__m64)0x16A0000016ALL), 8u),
             _m_psradi(_m_pmaddwd(_m_punpckhwd(v138, 0), (__m64)0x16A0000016ALL), 8u)),
           v139);
  v142 = _m_paddw(v137, v141);
  v143 = _m_psubw(v293, v142);
  v144 = _m_paddw(v293, v142);
  v145 = v139;
  v146 = a2[4];
  a2[8].m64_u64 = (unsigned __int64)v144;
  a2[6].m64_u64 = (unsigned __int64)v143;
  v147 = (__m64)a2->m64_u64;
  a2->m64_u64 = (unsigned __int64)_m_paddw(v146, v135);
  a2[14].m64_u64 = (unsigned __int64)_m_psubw(v146, v135);
  a2[2].m64_u64 = (unsigned __int64)_m_paddw(v140, v145);
  a2[12].m64_u64 = (unsigned __int64)_m_psubw(v140, v145);
  v148 = a2[5];
  a2[4].m64_u64 = (unsigned __int64)_m_paddw(v147, v141);
  a2[10].m64_u64 = (unsigned __int64)_m_psubw(v147, v141);
  v149 = a2[13];
  v150 = a2[9];
  v151 = _m_paddw(v148, v149);
  v152 = _m_psubw(v148, v149);
  v153 = a2[1];
  v154 = _m_paddw(v153, v150);
  v155 = _m_psubw(
           _m_packssdw(
             _m_psradi(_m_pmaddwd(_m_punpcklwd(v152, 0), (__m64)0x16A0000016ALL), 8u),
             _m_psradi(_m_pmaddwd(_m_punpckhwd(v152, 0), (__m64)0x16A0000016ALL), 8u)),
           v151);
  v156 = _m_psubw(v153, v150);
  a2[5].m64_u64 = (unsigned __int64)_m_paddw(v154, v151);
  a2[13].m64_u64 = (unsigned __int64)_m_paddw(v156, v155);
  v157 = _m_psubw(v154, v151);
  a2[9].m64_u64 = (unsigned __int64)_m_psubw(v156, v155);
  v158 = a2[7];
  v159 = a2[15];
  v160 = a2[11];
  v161 = _m_paddw(v160, v158);
  v162 = _m_psubw(v160, v158);
  v163 = a2[3];
  v164 = _m_paddw(v163, v159);
  v165 = _m_psubw(v163, v159);
  v166 = v164;
  v167 = _m_paddw(v164, v161);
  v168 = _m_packssdw(
           _m_psradi(_m_pmaddwd(_m_punpcklwd(v162, 0), (__m64)0xFD630000FD63LL), 8u),
           _m_psradi(_m_pmaddwd(_m_punpckhwd(v162, 0), (__m64)0xFD630000FD63LL), 8u));
  v169 = _m_psubw(v166, v161);
  v170 = _m_packssdw(
           _m_psradi(_m_pmaddwd(_m_punpcklwd(v169, 0), (__m64)0x16A0000016ALL), 8u),
           _m_psradi(_m_pmaddwd(_m_punpckhwd(v169, 0), (__m64)0x16A0000016ALL), 8u));
  v171 = _m_paddw(v162, v165);
  v172 = _m_packssdw(
           _m_psradi(_m_pmaddwd(_m_punpcklwd(v171, 0), (__m64)0x1D9000001D9LL), 8u),
           _m_psradi(_m_pmaddwd(_m_punpckhwd(v171, 0), (__m64)0x1D9000001D9LL), 8u));
  v173 = _m_psubw(
           _m_packssdw(
             _m_psradi(_m_pmaddwd(_m_punpcklwd(v165, 0), (__m64)0x11500000115LL), 8u),
             _m_psradi(_m_pmaddwd(_m_punpckhwd(v165, 0), (__m64)0x11500000115LL), 8u)),
           v172);
  v174 = _m_psubw(_m_paddw(v172, v168), v167);
  v175 = a2[5];
  v176 = _m_psubw(v170, v174);
  v177 = a2[13];
  v178 = _m_paddw(v173, v176);
  a2[1].m64_u64 = (unsigned __int64)_m_paddw(v175, v167);
  v179 = _m_psubw(v175, v167);
  v180 = _m_paddw(v157, v178);
  v181 = a2[9];
  a2[7].m64_u64 = (unsigned __int64)_m_psubw(v157, v178);
  a2[3].m64_u64 = (unsigned __int64)_m_paddw(v177, v174);
  v182 = _m_psubw(v181, v176);
  a2[5].m64_u64 = (unsigned __int64)_m_paddw(v181, v176);
  v183 = (_BYTE *)(a5 + a4[4]);
  v184 = v180;
  v185 = _m_punpcklwd(v180, v182);
  v186 = _m_punpckhwd(v184, v182);
  v187 = _m_psubw(v177, v174);
  v188 = (__m64)a2->m64_u64;
  v189 = _m_punpcklwd(v187, v179);
  v190 = a2[2];
  v191 = _m_punpckhwd(v187, v179);
  v192 = v185;
  v193 = _m_psrlwi(_m_punpckldq(v185, v189), 5u);
  v183[4] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v193) & 0x3FF));
  v194 = _m_psrlqi(v193, 0x10u);
  v183[5] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v194) & 0x3FF));
  v195 = _m_psrlqi(v194, 0x10u);
  v183[6] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v195) & 0x3FF));
  v183[7] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v195, 0x10u)) & 0x3FF));
  v196 = (_BYTE *)(a5 + a4[5]);
  v197 = _m_punpckhdq(v192, v189);
  v198 = v186;
  v199 = _m_psrlwi(v197, 5u);
  v196[4] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v199) & 0x3FF));
  v200 = _m_psrlqi(v199, 0x10u);
  v196[5] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v200) & 0x3FF));
  v201 = _m_psrlqi(v200, 0x10u);
  v196[6] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v201) & 0x3FF));
  v196[7] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v201, 0x10u)) & 0x3FF));
  v202 = (_BYTE *)(a5 + a4[6]);
  v203 = _m_psrlwi(_m_punpckldq(v186, v191), 5u);
  v202[4] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v203) & 0x3FF));
  v204 = _m_psrlqi(v203, 0x10u);
  v202[5] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v204) & 0x3FF));
  v205 = _m_psrlqi(v204, 0x10u);
  v202[6] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v205) & 0x3FF));
  v202[7] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v205, 0x10u)) & 0x3FF));
  v206 = (_BYTE *)(a5 + a4[7]);
  v207 = _m_psrlwi(_m_punpckhdq(v198, v191), 5u);
  v206[4] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v207) & 0x3FF));
  v208 = _m_psrlqi(v207, 0x10u);
  v206[5] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v208) & 0x3FF));
  v209 = _m_psrlqi(v208, 0x10u);
  v206[6] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v209) & 0x3FF));
  v206[7] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v209, 0x10u)) & 0x3FF));
  v210 = (_BYTE *)(a5 + *a4);
  v211 = a2[6];
  v212 = _m_punpckhwd(v188, v190);
  v213 = _m_punpcklwd(v188, v190);
  v214 = a2[4];
  v215 = _m_punpcklwd(v214, v211);
  v216 = _m_punpckhwd(v214, v211);
  v217 = v212;
  v218 = _m_psrlwi(_m_punpckldq(v213, v215), 5u);
  *v210 = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v218) & 0x3FF));
  v219 = _m_psrlqi(v218, 0x10u);
  v210[1] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v219) & 0x3FF));
  v220 = _m_psrlqi(v219, 0x10u);
  v210[2] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v220) & 0x3FF));
  v210[3] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v220, 0x10u)) & 0x3FF));
  v221 = (_BYTE *)(a5 + a4[1]);
  v222 = _m_psrlwi(_m_punpckhdq(v213, v215), 5u);
  *v221 = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v222) & 0x3FF));
  v223 = _m_psrlqi(v222, 0x10u);
  v221[1] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v223) & 0x3FF));
  v224 = _m_psrlqi(v223, 0x10u);
  v221[2] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v224) & 0x3FF));
  v221[3] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v224, 0x10u)) & 0x3FF));
  v225 = (_BYTE *)(a5 + a4[2]);
  v226 = _m_psrlwi(_m_punpckldq(v212, v216), 5u);
  *v225 = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v226) & 0x3FF));
  v227 = _m_psrlqi(v226, 0x10u);
  v225[1] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v227) & 0x3FF));
  v228 = _m_psrlqi(v227, 0x10u);
  v225[2] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v228) & 0x3FF));
  v225[3] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v228, 0x10u)) & 0x3FF));
  v229 = (_BYTE *)(a5 + a4[3]);
  v230 = _m_psrlwi(_m_punpckhdq(v217, v216), 5u);
  *v229 = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v230) & 0x3FF));
  v231 = _m_psrlqi(v230, 0x10u);
  v229[1] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v231) & 0x3FF));
  v232 = _m_psrlqi(v231, 0x10u);
  v229[2] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v232) & 0x3FF));
  v229[3] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v232, 0x10u)) & 0x3FF));
  v233 = (_BYTE *)(a5 + a4[4]);
  v234 = a2[3];
  v235 = a2[1];
  v236 = _m_punpcklwd(v235, v234);
  v237 = _m_punpckhwd(v235, v234);
  v238 = a2[5];
  v239 = a2[7];
  v240 = v237;
  v241 = _m_punpcklwd(v238, v239);
  v242 = _m_punpckhwd(v238, v239);
  v243 = v236;
  v244 = _m_punpckldq(v236, v241);
  v245 = _m_punpckhdq(v243, v241);
  v246 = a2[8];
  v247 = _m_psrlwi(v244, 5u);
  *v233 = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v247) & 0x3FF));
  v248 = _m_psrlqi(v247, 0x10u);
  v233[1] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v248) & 0x3FF));
  v249 = _m_psrlqi(v248, 0x10u);
  v233[2] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v249) & 0x3FF));
  v233[3] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v249, 0x10u)) & 0x3FF));
  v250 = (_BYTE *)(a5 + a4[5]);
  v251 = _m_punpckldq(v237, v242);
  v252 = _m_punpckhdq(v240, v242);
  v253 = a2[10];
  v254 = _m_psrlwi(v245, 5u);
  *v250 = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v254) & 0x3FF));
  v255 = _m_psrlqi(v254, 0x10u);
  v250[1] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v255) & 0x3FF));
  v256 = _m_psrlqi(v255, 0x10u);
  v250[2] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v256) & 0x3FF));
  v250[3] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v256, 0x10u)) & 0x3FF));
  v257 = (_BYTE *)(a5 + a4[6]);
  v258 = a2[12];
  v259 = v246;
  v260 = _m_punpcklwd(v246, v253);
  v261 = _m_punpckhwd(v259, v253);
  v262 = a2[14];
  v263 = _m_psrlwi(v251, 5u);
  *v257 = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v263) & 0x3FF));
  v264 = _m_psrlqi(v263, 0x10u);
  v257[1] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v264) & 0x3FF));
  v265 = _m_psrlqi(v264, 0x10u);
  v257[2] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v265) & 0x3FF));
  v257[3] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v265, 0x10u)) & 0x3FF));
  v266 = (_BYTE *)(a5 + a4[7]);
  v267 = v258;
  v268 = _m_psrlwi(v252, 5u);
  *v266 = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v268) & 0x3FF));
  v269 = _m_psrlqi(v268, 0x10u);
  v266[1] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v269) & 0x3FF));
  v270 = _m_psrlqi(v269, 0x10u);
  v266[2] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v270) & 0x3FF));
  v266[3] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v270, 0x10u)) & 0x3FF));
  v271 = _m_punpcklwd(v258, v262);
  v272 = _m_punpckhwd(v267, v262);
  v273 = v260;
  v274 = v261;
  v275 = (_BYTE *)(a5 + *a4);
  v276 = _m_psrlwi(_m_punpckldq(v260, v271), 5u);
  v275[4] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v276) & 0x3FF));
  v277 = _m_psrlqi(v276, 0x10u);
  v275[5] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v277) & 0x3FF));
  v278 = _m_psrlqi(v277, 0x10u);
  v275[6] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v278) & 0x3FF));
  v275[7] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v278, 0x10u)) & 0x3FF));
  v279 = (_BYTE *)(a5 + a4[1]);
  v280 = _m_psrlwi(_m_punpckhdq(v273, v271), 5u);
  v279[4] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v280) & 0x3FF));
  v281 = _m_psrlqi(v280, 0x10u);
  v279[5] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v281) & 0x3FF));
  v282 = _m_psrlqi(v281, 0x10u);
  v279[6] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v282) & 0x3FF));
  v279[7] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v282, 0x10u)) & 0x3FF));
  v283 = (_BYTE *)(a5 + a4[2]);
  v284 = _m_psrlwi(_m_punpckldq(v261, v272), 5u);
  v283[4] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v284) & 0x3FF));
  v285 = _m_psrlqi(v284, 0x10u);
  v283[5] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v285) & 0x3FF));
  v286 = _m_psrlqi(v285, 0x10u);
  v283[6] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v286) & 0x3FF));
  v283[7] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v286, 0x10u)) & 0x3FF));
  v287 = (_BYTE *)(a5 + a4[3]);
  v288 = _m_psrlwi(_m_punpckhdq(v274, v272), 5u);
  v287[4] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v288) & 0x3FF));
  v289 = _m_psrlqi(v288, 0x10u);
  v287[5] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v289) & 0x3FF));
  v290 = _m_psrlqi(v289, 0x10u);
  v287[6] = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(v290) & 0x3FF));
  result = *(_BYTE *)(a6 + (_mm_cvtsi64_si32(_m_psrlqi(v290, 0x10u)) & 0x3FF));
  v287[7] = result;
  _m_empty();
  return result;
}
