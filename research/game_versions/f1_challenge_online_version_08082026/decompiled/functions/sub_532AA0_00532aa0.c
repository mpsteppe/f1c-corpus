int __thiscall sub_532AA0(int this, _WORD *a2, int a3)
{
  unsigned __int8 v4; // cl
  int v5; // edi
  int result; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  int v10; // eax
  __m64 *v11; // ebx
  __m64 v12; // mm2
  __m64 v13; // mm1
  __m64 v14; // mm3
  __m64 v15; // mm2
  __m64 v16; // mm5
  __m64 v17; // mm7
  __m64 v18; // mm3
  __m64 v19; // mm0
  __m64 v20; // mm2
  __m64 v21; // mm3
  __m64 v22; // mm4
  __m64 v23; // mm6
  __m64 v24; // mm2
  __m64 v25; // mm1
  __m64 v26; // mm3
  __m64 v27; // mm2
  __m64 v28; // mm5
  __m64 v29; // mm7
  __m64 v30; // mm3
  __m64 v31; // mm0
  __m64 v32; // mm2
  __m64 v33; // mm3
  __m64 v34; // mm4
  __m64 v35; // mm6
  __m64 v36; // mm2
  __m64 v37; // mm1
  __m64 v38; // mm3
  __m64 v39; // mm2
  __m64 v40; // mm5
  __m64 v41; // mm7
  __m64 v42; // mm3
  __m64 v43; // mm0
  __m64 v44; // mm2
  __m64 v45; // mm3
  __m64 v46; // mm4
  __m64 v47; // mm6
  __m64 v48; // mm2
  __m64 v49; // mm1
  __m64 v50; // mm3
  __m64 v51; // mm2
  __m64 v52; // mm5
  __m64 v53; // mm7
  __m64 v54; // mm3
  __m64 v55; // mm0
  __m64 v56; // mm2
  __m64 v57; // mm3
  __m64 v58; // mm4
  __m64 v59; // mm6
  __m64 v60; // mm2
  __m64 v61; // mm1
  __m64 v62; // mm3
  __m64 v63; // mm2
  __m64 v64; // mm5
  __m64 v65; // mm7
  __m64 v66; // mm3
  __m64 v67; // mm0
  __m64 v68; // mm2
  __m64 v69; // mm3
  __m64 v70; // mm4
  __m64 v71; // mm6
  __m64 v72; // mm2
  __m64 v73; // mm1
  __m64 v74; // mm3
  __m64 v75; // mm2
  __m64 v76; // mm5
  __m64 v77; // mm7
  __m64 v78; // mm3
  __m64 v79; // mm0
  __m64 v80; // mm2
  __m64 v81; // mm3
  __m64 v82; // mm4
  __m64 v83; // mm6
  __m64 v84; // mm2
  __m64 v85; // mm1
  __m64 v86; // mm3
  __m64 v87; // mm2
  __m64 v88; // mm5
  __m64 v89; // mm7
  __m64 v90; // mm3
  __m64 v91; // mm0
  __m64 v92; // mm2
  __m64 v93; // mm3
  __m64 v94; // mm4
  __m64 v95; // mm6
  __m64 v96; // mm2
  __m64 v97; // mm1
  __m64 v98; // mm3
  __m64 v99; // mm2
  __m64 v100; // mm5
  __m64 v101; // mm7
  __m64 v102; // mm3
  __m64 v103; // mm3
  __m64 v104; // mm6
  __m64 v105; // mm0
  __m64 v106; // mm2
  __m64 v107; // mm4
  __m64 *v108; // ebx
  __m64 v109; // mm0
  __m64 v110; // mm1
  __m64 v111; // mm3
  __m64 v112; // mm5
  __m64 v113; // mm0
  __m64 v114; // mm7
  __m64 v115; // mm1
  __m64 v116; // mm0
  __m64 v117; // mm2
  __m64 v118; // mm1
  __m64 v119; // mm4
  __m64 v120; // mm6
  __m64 v121; // mm0
  __m64 v122; // mm1
  __m64 v123; // mm3
  __m64 v124; // mm0
  __m64 v125; // mm5
  __m64 v126; // mm7
  __m64 v127; // mm1
  __m64 v128; // mm0
  __m64 v129; // mm2
  __m64 v130; // mm1
  __m64 v131; // mm4
  __m64 v132; // mm6
  __m64 v133; // mm0
  __m64 v134; // mm1
  __m64 v135; // mm3
  __m64 v136; // mm0
  __m64 v137; // mm5
  __m64 v138; // mm7
  __m64 v139; // mm1
  __m64 v140; // mm0
  __m64 v141; // mm2
  __m64 v142; // mm1
  __m64 v143; // mm4
  __m64 v144; // mm6
  __m64 v145; // mm0
  __m64 v146; // mm1
  __m64 v147; // mm3
  __m64 v148; // mm0
  __m64 v149; // mm5
  __m64 v150; // mm7
  __m64 v151; // mm1
  __m64 v152; // mm0
  __m64 v153; // mm2
  __m64 v154; // mm1
  __m64 v155; // mm4
  __m64 v156; // mm6
  __m64 v157; // mm0
  __m64 v158; // mm1
  __m64 v159; // mm3
  __m64 v160; // mm0
  __m64 v161; // mm5
  __m64 v162; // mm7
  __m64 v163; // mm1
  __m64 v164; // mm0
  __m64 v165; // mm2
  __m64 v166; // mm1
  __m64 v167; // mm4
  __m64 v168; // mm6
  __m64 v169; // mm0
  __m64 v170; // mm1
  __m64 v171; // mm3
  __m64 v172; // mm0
  __m64 v173; // mm5
  __m64 v174; // mm7
  __m64 v175; // mm1
  __m64 v176; // mm0
  __m64 v177; // mm2
  __m64 v178; // mm1
  __m64 v179; // mm4
  __m64 v180; // mm6
  __m64 v181; // mm0
  __m64 v182; // mm1
  __m64 v183; // mm3
  __m64 v184; // mm0
  __m64 v185; // mm5
  __m64 v186; // mm7
  __m64 v187; // mm1
  __m64 v188; // mm0
  __m64 v189; // mm2
  __m64 v190; // mm1
  __m64 v191; // mm4
  __m64 v192; // mm6
  __m64 v193; // mm0
  __m64 v194; // mm0
  __m64 v195; // mm5
  __m64 v196; // mm7
  __m64 v197; // mm1
  __m64 v198; // mm1
  __m64 v199; // mm1
  __m64 *v200; // ebx
  __m64 v201; // mm2
  __m64 v202; // mm1
  __m64 v203; // mm3
  __m64 v204; // mm2
  __m64 v205; // mm5
  __m64 v206; // mm7
  __m64 v207; // mm3
  __m64 v208; // mm0
  __m64 v209; // mm2
  __m64 v210; // mm3
  __m64 v211; // mm4
  __m64 v212; // mm6
  __m64 v213; // mm2
  __m64 v214; // mm1
  __m64 v215; // mm3
  __m64 v216; // mm2
  __m64 v217; // mm5
  __m64 v218; // mm7
  __m64 v219; // mm3
  __m64 v220; // mm0
  __m64 v221; // mm2
  __m64 v222; // mm3
  __m64 v223; // mm4
  __m64 v224; // mm6
  __m64 v225; // mm2
  __m64 v226; // mm1
  __m64 v227; // mm3
  __m64 v228; // mm2
  __m64 v229; // mm5
  __m64 v230; // mm7
  __m64 v231; // mm3
  __m64 v232; // mm0
  __m64 v233; // mm2
  __m64 v234; // mm3
  __m64 v235; // mm4
  __m64 v236; // mm6
  __m64 v237; // mm2
  __m64 v238; // mm1
  __m64 v239; // mm3
  __m64 v240; // mm2
  __m64 v241; // mm5
  __m64 v242; // mm7
  __m64 v243; // mm3
  __m64 v244; // mm0
  __m64 v245; // mm2
  __m64 v246; // mm3
  __m64 v247; // mm4
  __m64 v248; // mm6
  __m64 v249; // mm2
  __m64 v250; // mm1
  __m64 v251; // mm3
  __m64 v252; // mm2
  __m64 v253; // mm5
  __m64 v254; // mm7
  __m64 v255; // mm3
  __m64 v256; // mm0
  __m64 v257; // mm2
  __m64 v258; // mm3
  __m64 v259; // mm4
  __m64 v260; // mm6
  __m64 v261; // mm2
  __m64 v262; // mm1
  __m64 v263; // mm3
  __m64 v264; // mm2
  __m64 v265; // mm5
  __m64 v266; // mm7
  __m64 v267; // mm3
  __m64 v268; // mm0
  __m64 v269; // mm2
  __m64 v270; // mm3
  __m64 v271; // mm4
  __m64 v272; // mm6
  __m64 v273; // mm2
  __m64 v274; // mm1
  __m64 v275; // mm3
  __m64 v276; // mm2
  __m64 v277; // mm5
  __m64 v278; // mm7
  __m64 v279; // mm3
  __m64 v280; // mm0
  __m64 v281; // mm2
  __m64 v282; // mm3
  __m64 v283; // mm4
  __m64 v284; // mm6
  __m64 v285; // mm2
  __m64 v286; // mm1
  __m64 v287; // mm3
  __m64 v288; // mm2
  __m64 v289; // mm5
  __m64 v290; // mm7
  __m64 v291; // mm3
  __m64 v292; // mm3
  __m64 v293; // mm6
  __m64 v294; // mm0
  __m64 v295; // mm2
  __m64 v296; // mm4
  __m64 v297; // mm0
  __m64 v298; // mm1
  __m64 v299; // mm3
  __m64 v300; // mm5
  __m64 v301; // mm0
  __m64 v302; // mm7
  __m64 v303; // mm1
  __m64 v304; // mm0
  __m64 v305; // mm2
  __m64 v306; // mm1
  __m64 v307; // mm4
  __m64 v308; // mm6
  __m64 v309; // mm0
  __m64 v310; // mm1
  __m64 v311; // mm3
  __m64 v312; // mm0
  __m64 v313; // mm5
  __m64 v314; // mm7
  __m64 v315; // mm1
  __m64 v316; // mm0
  __m64 v317; // mm2
  __m64 v318; // mm1
  __m64 v319; // mm4
  __m64 v320; // mm6
  __m64 v321; // mm0
  __m64 v322; // mm1
  __m64 v323; // mm3
  __m64 v324; // mm0
  __m64 v325; // mm5
  __m64 v326; // mm7
  __m64 v327; // mm1
  __m64 v328; // mm0
  __m64 v329; // mm2
  __m64 v330; // mm1
  __m64 v331; // mm4
  __m64 v332; // mm6
  __m64 v333; // mm0
  __m64 v334; // mm1
  __m64 v335; // mm3
  __m64 v336; // mm0
  __m64 v337; // mm5
  __m64 v338; // mm7
  __m64 v339; // mm1
  __m64 v340; // mm0
  __m64 v341; // mm2
  __m64 v342; // mm1
  __m64 v343; // mm4
  __m64 v344; // mm6
  __m64 v345; // mm0
  __m64 v346; // mm1
  __m64 v347; // mm3
  __m64 v348; // mm0
  __m64 v349; // mm5
  __m64 v350; // mm7
  __m64 v351; // mm1
  __m64 v352; // mm0
  __m64 v353; // mm2
  __m64 v354; // mm1
  __m64 v355; // mm4
  __m64 v356; // mm6
  __m64 v357; // mm0
  __m64 v358; // mm1
  __m64 v359; // mm3
  __m64 v360; // mm0
  __m64 v361; // mm5
  __m64 v362; // mm7
  __m64 v363; // mm1
  __m64 v364; // mm0
  __m64 v365; // mm2
  __m64 v366; // mm1
  __m64 v367; // mm4
  __m64 v368; // mm6
  __m64 v369; // mm0
  __m64 v370; // mm1
  __m64 v371; // mm3
  __m64 v372; // mm0
  __m64 v373; // mm5
  __m64 v374; // mm7
  __m64 v375; // mm1
  __m64 v376; // mm0
  __m64 v377; // mm2
  __m64 v378; // mm1
  __m64 v379; // mm4
  __m64 v380; // mm6
  __m64 v381; // mm0
  __m64 v382; // mm0
  __m64 v383; // mm5
  __m64 v384; // mm7
  __m64 v385; // mm1
  __m64 v386; // mm1
  __m64 v387; // mm1
  bool v388; // cc
  int v389; // [esp+Ch] [ebp-20h]
  int v390; // [esp+10h] [ebp-1Ch]
  int v391; // [esp+14h] [ebp-18h]
  __m64 *v392; // [esp+18h] [ebp-14h]
  _WORD *v393; // [esp+20h] [ebp-Ch]
  int v395; // [esp+28h] [ebp-4h]
  int v396; // [esp+38h] [ebp+Ch]

  v389 = 0;
  v4 = (*(_BYTE *)(this + 9404) - 1) & 0xF;
  *(_BYTE *)(this + 9404) = v4;
  v5 = v4 & 1;
  result = !(v4 & 1);
  v7 = v4 + result;
  v391 = v7;
  if ( *(int *)(this + 9420) > 0 )
  {
    v393 = a2;
    v8 = 576 * result;
    v396 = this + 4;
    v390 = 576 * result;
    v9 = 288 * v5;
    v10 = this + 576 * result + 2 * v7 + 4;
    v395 = v10;
    while ( 1 )
    {
      v392 = (__m64 *)(v8 + v396);
      sub_534120(v396 + 2 * (v9 + (((_BYTE)v5 + *(_BYTE *)(this + 9404)) & 0xF)), v10, a3);
      if ( a2 )
      {
        if ( *(_DWORD *)(this + 9420) == 2 )
        {
          v11 = (__m64 *)((char *)&unk_8B3724 + 544 * v391);
          v12 = _m_paddd(
                  _m_paddd(
                    _m_paddd(_m_pmaddwd((__m64)v392->m64_u64, (__m64)v11->m64_u64), _m_pmaddwd(v11[1], v392[1])),
                    _m_pmaddwd(v11[2], v392[2])),
                  _m_pmaddwd(v11[3], v392[3]));
          v13 = _m_pmaddwd(v11[4], v392[4]);
          v14 = _m_pmaddwd(v11[5], v392[5]);
          v15 = _m_psradi(_m_paddd(v12, _m_psrlqi(v12, 0x20u)), 0xDu);
          v16 = _m_pmaddwd(v11[6], v392[6]);
          v17 = _m_pmaddwd(v11[7], v392[7]);
          *v393 = _mm_cvtsi64_si32(_m_packssdw(v15, v15));
          v18 = _m_paddd(_m_paddd(_m_paddd(v13, v14), v16), v17);
          v19 = _m_pmaddwd(v11[8], v392[8]);
          v20 = _m_pmaddwd(v11[9], v392[9]);
          v21 = _m_psradi(_m_paddd(v18, _m_psrlqi(v18, 0x20u)), 0xDu);
          v22 = _m_pmaddwd(v11[10], v392[10]);
          v23 = _m_pmaddwd(v11[11], v392[11]);
          v393[2] = _mm_cvtsi64_si32(_m_packssdw(v21, v21));
          v24 = _m_paddd(_m_paddd(_m_paddd(v19, v20), v22), v23);
          v25 = _m_pmaddwd(v11[12], v392[12]);
          v26 = _m_pmaddwd(v11[13], v392[13]);
          v27 = _m_psradi(_m_paddd(v24, _m_psrlqi(v24, 0x20u)), 0xDu);
          v28 = _m_pmaddwd(v11[14], v392[14]);
          v29 = _m_pmaddwd(v11[15], v392[15]);
          v393[4] = _mm_cvtsi64_si32(_m_packssdw(v27, v27));
          v30 = _m_paddd(_m_paddd(_m_paddd(v25, v26), v28), v29);
          v31 = _m_pmaddwd(v11[16], v392[16]);
          v32 = _m_pmaddwd(v11[17], v392[17]);
          v33 = _m_psradi(_m_paddd(v30, _m_psrlqi(v30, 0x20u)), 0xDu);
          v34 = _m_pmaddwd(v11[18], v392[18]);
          v35 = _m_pmaddwd(v11[19], v392[19]);
          v393[6] = _mm_cvtsi64_si32(_m_packssdw(v33, v33));
          v36 = _m_paddd(_m_paddd(_m_paddd(v31, v32), v34), v35);
          v37 = _m_pmaddwd(v11[20], v392[20]);
          v38 = _m_pmaddwd(v11[21], v392[21]);
          v39 = _m_psradi(_m_paddd(v36, _m_psrlqi(v36, 0x20u)), 0xDu);
          v40 = _m_pmaddwd(v11[22], v392[22]);
          v41 = _m_pmaddwd(v11[23], v392[23]);
          v393[8] = _mm_cvtsi64_si32(_m_packssdw(v39, v39));
          v42 = _m_paddd(_m_paddd(_m_paddd(v37, v38), v40), v41);
          v43 = _m_pmaddwd(v11[24], v392[24]);
          v44 = _m_pmaddwd(v11[25], v392[25]);
          v45 = _m_psradi(_m_paddd(v42, _m_psrlqi(v42, 0x20u)), 0xDu);
          v46 = _m_pmaddwd(v11[26], v392[26]);
          v47 = _m_pmaddwd(v11[27], v392[27]);
          v393[10] = _mm_cvtsi64_si32(_m_packssdw(v45, v45));
          v48 = _m_paddd(_m_paddd(_m_paddd(v43, v44), v46), v47);
          v49 = _m_pmaddwd(v11[28], v392[28]);
          v50 = _m_pmaddwd(v11[29], v392[29]);
          v51 = _m_psradi(_m_paddd(v48, _m_psrlqi(v48, 0x20u)), 0xDu);
          v52 = _m_pmaddwd(v11[30], v392[30]);
          v53 = _m_pmaddwd(v11[31], v392[31]);
          v393[12] = _mm_cvtsi64_si32(_m_packssdw(v51, v51));
          v54 = _m_paddd(_m_paddd(_m_paddd(v49, v50), v52), v53);
          v55 = _m_pmaddwd(v11[32], v392[32]);
          v56 = _m_pmaddwd(v11[33], v392[33]);
          v57 = _m_psradi(_m_paddd(v54, _m_psrlqi(v54, 0x20u)), 0xDu);
          v58 = _m_pmaddwd(v11[34], v392[34]);
          v59 = _m_pmaddwd(v11[35], v392[35]);
          v393[14] = _mm_cvtsi64_si32(_m_packssdw(v57, v57));
          v60 = _m_paddd(_m_paddd(_m_paddd(v55, v56), v58), v59);
          v61 = _m_pmaddwd(v11[36], v392[36]);
          v62 = _m_pmaddwd(v11[37], v392[37]);
          v63 = _m_psradi(_m_paddd(v60, _m_psrlqi(v60, 0x20u)), 0xDu);
          v64 = _m_pmaddwd(v11[38], v392[38]);
          v65 = _m_pmaddwd(v11[39], v392[39]);
          v393[16] = _mm_cvtsi64_si32(_m_packssdw(v63, v63));
          v66 = _m_paddd(_m_paddd(_m_paddd(v61, v62), v64), v65);
          v67 = _m_pmaddwd(v11[40], v392[40]);
          v68 = _m_pmaddwd(v11[41], v392[41]);
          v69 = _m_psradi(_m_paddd(v66, _m_psrlqi(v66, 0x20u)), 0xDu);
          v70 = _m_pmaddwd(v11[42], v392[42]);
          v71 = _m_pmaddwd(v11[43], v392[43]);
          v393[18] = _mm_cvtsi64_si32(_m_packssdw(v69, v69));
          v72 = _m_paddd(_m_paddd(_m_paddd(v67, v68), v70), v71);
          v73 = _m_pmaddwd(v11[44], v392[44]);
          v74 = _m_pmaddwd(v11[45], v392[45]);
          v75 = _m_psradi(_m_paddd(v72, _m_psrlqi(v72, 0x20u)), 0xDu);
          v76 = _m_pmaddwd(v11[46], v392[46]);
          v77 = _m_pmaddwd(v11[47], v392[47]);
          v393[20] = _mm_cvtsi64_si32(_m_packssdw(v75, v75));
          v78 = _m_paddd(_m_paddd(_m_paddd(v73, v74), v76), v77);
          v79 = _m_pmaddwd(v11[48], v392[48]);
          v80 = _m_pmaddwd(v11[49], v392[49]);
          v81 = _m_psradi(_m_paddd(v78, _m_psrlqi(v78, 0x20u)), 0xDu);
          v82 = _m_pmaddwd(v11[50], v392[50]);
          v83 = _m_pmaddwd(v11[51], v392[51]);
          v393[22] = _mm_cvtsi64_si32(_m_packssdw(v81, v81));
          v84 = _m_paddd(_m_paddd(_m_paddd(v79, v80), v82), v83);
          v85 = _m_pmaddwd(v11[52], v392[52]);
          v86 = _m_pmaddwd(v11[53], v392[53]);
          v87 = _m_psradi(_m_paddd(v84, _m_psrlqi(v84, 0x20u)), 0xDu);
          v88 = _m_pmaddwd(v11[54], v392[54]);
          v89 = _m_pmaddwd(v11[55], v392[55]);
          v393[24] = _mm_cvtsi64_si32(_m_packssdw(v87, v87));
          v90 = _m_paddd(_m_paddd(_m_paddd(v85, v86), v88), v89);
          v91 = _m_pmaddwd(v11[56], v392[56]);
          v92 = _m_pmaddwd(v11[57], v392[57]);
          v93 = _m_psradi(_m_paddd(v90, _m_psrlqi(v90, 0x20u)), 0xDu);
          v94 = _m_pmaddwd(v11[58], v392[58]);
          v95 = _m_pmaddwd(v11[59], v392[59]);
          v393[26] = _mm_cvtsi64_si32(_m_packssdw(v93, v93));
          v96 = _m_paddd(_m_paddd(_m_paddd(v91, v92), v94), v95);
          v97 = _m_pmaddwd(v11[60], v392[60]);
          v98 = _m_pmaddwd(v11[61], v392[61]);
          v99 = _m_psradi(_m_paddd(v96, _m_psrlqi(v96, 0x20u)), 0xDu);
          v100 = _m_pmaddwd(v11[62], v392[62]);
          v101 = _m_pmaddwd(v11[63], v392[63]);
          v393[28] = _mm_cvtsi64_si32(_m_packssdw(v99, v99));
          v102 = _m_paddd(_m_paddd(_m_paddd(v97, v98), v100), v101);
          v103 = _m_psradi(_m_paddd(v102, _m_psrlqi(v102, 0x20u)), 0xDu);
          v104 = _m_pmulhw(v11[67], v392[67]);
          v105 = _m_pslldi(_m_pmulhw(v11[64], v392[64]), 0x10u);
          v106 = _m_pslldi(_m_pmulhw(v11[65], v392[65]), 0x10u);
          v107 = _m_pslldi(_m_pmulhw(v11[66], v392[66]), 0x10u);
          v393[30] = _mm_cvtsi64_si32(_m_packssdw(v103, v103));
          v108 = (__m64 *)((char *)&unk_8B1924 + 480 * v391);
          v109 = _m_paddd(_m_paddd(_m_paddd(v105, v106), v107), _m_pslldi(v104, 0x10u));
          v110 = _m_pmaddwd((__m64)v108->m64_u64, v392[60]);
          v111 = _m_pmaddwd(v108[1], v392[61]);
          v112 = _m_pmaddwd(v108[2], v392[62]);
          v113 = _m_psradi(_m_paddd(v109, _m_psrlqi(v109, 0x20u)), 0xDu);
          v114 = _m_pmaddwd(v108[3], v392[63]);
          v393[32] = _mm_cvtsi64_si32(_m_packssdw(v113, v113));
          v115 = _m_paddd(_m_paddd(_m_paddd(v110, v111), v112), v114);
          v116 = _m_pmaddwd(v108[4], v392[56]);
          v117 = _m_pmaddwd(v108[5], v392[57]);
          v118 = _m_psradi(_m_paddd(v115, _m_psrlqi(v115, 0x20u)), 0xDu);
          v119 = _m_pmaddwd(v108[6], v392[58]);
          v120 = _m_pmaddwd(v108[7], v392[59]);
          v393[34] = _mm_cvtsi64_si32(_m_packssdw(v118, v118));
          v121 = _m_paddd(_m_paddd(_m_paddd(v116, v117), v119), v120);
          v122 = _m_pmaddwd(v108[8], v392[52]);
          v123 = _m_pmaddwd(v108[9], v392[53]);
          v124 = _m_psradi(_m_paddd(v121, _m_psrlqi(v121, 0x20u)), 0xDu);
          v125 = _m_pmaddwd(v108[10], v392[54]);
          v126 = _m_pmaddwd(v108[11], v392[55]);
          v393[36] = _mm_cvtsi64_si32(_m_packssdw(v124, v124));
          v127 = _m_paddd(_m_paddd(_m_paddd(v122, v123), v125), v126);
          v128 = _m_pmaddwd(v108[12], v392[48]);
          v129 = _m_pmaddwd(v108[13], v392[49]);
          v130 = _m_psradi(_m_paddd(v127, _m_psrlqi(v127, 0x20u)), 0xDu);
          v131 = _m_pmaddwd(v108[14], v392[50]);
          v132 = _m_pmaddwd(v108[15], v392[51]);
          v393[38] = _mm_cvtsi64_si32(_m_packssdw(v130, v130));
          v133 = _m_paddd(_m_paddd(_m_paddd(v128, v129), v131), v132);
          v134 = _m_pmaddwd(v108[16], v392[44]);
          v135 = _m_pmaddwd(v108[17], v392[45]);
          v136 = _m_psradi(_m_paddd(v133, _m_psrlqi(v133, 0x20u)), 0xDu);
          v137 = _m_pmaddwd(v108[18], v392[46]);
          v138 = _m_pmaddwd(v108[19], v392[47]);
          v393[40] = _mm_cvtsi64_si32(_m_packssdw(v136, v136));
          v139 = _m_paddd(_m_paddd(_m_paddd(v134, v135), v137), v138);
          v140 = _m_pmaddwd(v108[20], v392[40]);
          v141 = _m_pmaddwd(v108[21], v392[41]);
          v142 = _m_psradi(_m_paddd(v139, _m_psrlqi(v139, 0x20u)), 0xDu);
          v143 = _m_pmaddwd(v108[22], v392[42]);
          v144 = _m_pmaddwd(v108[23], v392[43]);
          v393[42] = _mm_cvtsi64_si32(_m_packssdw(v142, v142));
          v145 = _m_paddd(_m_paddd(_m_paddd(v140, v141), v143), v144);
          v146 = _m_pmaddwd(v108[24], v392[36]);
          v147 = _m_pmaddwd(v108[25], v392[37]);
          v148 = _m_psradi(_m_paddd(v145, _m_psrlqi(v145, 0x20u)), 0xDu);
          v149 = _m_pmaddwd(v108[26], v392[38]);
          v150 = _m_pmaddwd(v108[27], v392[39]);
          v393[44] = _mm_cvtsi64_si32(_m_packssdw(v148, v148));
          v151 = _m_paddd(_m_paddd(_m_paddd(v146, v147), v149), v150);
          v152 = _m_pmaddwd(v108[28], v392[32]);
          v153 = _m_pmaddwd(v108[29], v392[33]);
          v154 = _m_psradi(_m_paddd(v151, _m_psrlqi(v151, 0x20u)), 0xDu);
          v155 = _m_pmaddwd(v108[30], v392[34]);
          v156 = _m_pmaddwd(v108[31], v392[35]);
          v393[46] = _mm_cvtsi64_si32(_m_packssdw(v154, v154));
          v157 = _m_paddd(_m_paddd(_m_paddd(v152, v153), v155), v156);
          v158 = _m_pmaddwd(v108[32], v392[28]);
          v159 = _m_pmaddwd(v108[33], v392[29]);
          v160 = _m_psradi(_m_paddd(v157, _m_psrlqi(v157, 0x20u)), 0xDu);
          v161 = _m_pmaddwd(v108[34], v392[30]);
          v162 = _m_pmaddwd(v108[35], v392[31]);
          v393[48] = _mm_cvtsi64_si32(_m_packssdw(v160, v160));
          v163 = _m_paddd(_m_paddd(_m_paddd(v158, v159), v161), v162);
          v164 = _m_pmaddwd(v108[36], v392[24]);
          v165 = _m_pmaddwd(v108[37], v392[25]);
          v166 = _m_psradi(_m_paddd(v163, _m_psrlqi(v163, 0x20u)), 0xDu);
          v167 = _m_pmaddwd(v108[38], v392[26]);
          v168 = _m_pmaddwd(v108[39], v392[27]);
          v393[50] = _mm_cvtsi64_si32(_m_packssdw(v166, v166));
          v169 = _m_paddd(_m_paddd(_m_paddd(v164, v165), v167), v168);
          v170 = _m_pmaddwd(v108[40], v392[20]);
          v171 = _m_pmaddwd(v108[41], v392[21]);
          v172 = _m_psradi(_m_paddd(v169, _m_psrlqi(v169, 0x20u)), 0xDu);
          v173 = _m_pmaddwd(v108[42], v392[22]);
          v174 = _m_pmaddwd(v108[43], v392[23]);
          v393[52] = _mm_cvtsi64_si32(_m_packssdw(v172, v172));
          v175 = _m_paddd(_m_paddd(_m_paddd(v170, v171), v173), v174);
          v176 = _m_pmaddwd(v108[44], v392[16]);
          v177 = _m_pmaddwd(v108[45], v392[17]);
          v178 = _m_psradi(_m_paddd(v175, _m_psrlqi(v175, 0x20u)), 0xDu);
          v179 = _m_pmaddwd(v108[46], v392[18]);
          v180 = _m_pmaddwd(v108[47], v392[19]);
          v393[54] = _mm_cvtsi64_si32(_m_packssdw(v178, v178));
          v181 = _m_paddd(_m_paddd(_m_paddd(v176, v177), v179), v180);
          v182 = _m_pmaddwd(v108[48], v392[12]);
          v183 = _m_pmaddwd(v108[49], v392[13]);
          v184 = _m_psradi(_m_paddd(v181, _m_psrlqi(v181, 0x20u)), 0xDu);
          v185 = _m_pmaddwd(v108[50], v392[14]);
          v186 = _m_pmaddwd(v108[51], v392[15]);
          v393[56] = _mm_cvtsi64_si32(_m_packssdw(v184, v184));
          v187 = _m_paddd(_m_paddd(_m_paddd(v182, v183), v185), v186);
          v188 = _m_pmaddwd(v108[52], v392[8]);
          v189 = _m_pmaddwd(v108[53], v392[9]);
          v190 = _m_psradi(_m_paddd(v187, _m_psrlqi(v187, 0x20u)), 0xDu);
          v191 = _m_pmaddwd(v108[54], v392[10]);
          v192 = _m_pmaddwd(v108[55], v392[11]);
          v393[58] = _mm_cvtsi64_si32(_m_packssdw(v190, v190));
          v193 = _m_paddd(_m_paddd(_m_paddd(v188, v189), v191), v192);
          v194 = _m_psradi(_m_paddd(v193, _m_psrlqi(v193, 0x20u)), 0xDu);
          v195 = _m_pmaddwd(v108[58], v392[6]);
          v196 = _m_pmaddwd(v108[59], v392[7]);
          v197 = _m_paddd(_m_pmaddwd(v108[56], v392[4]), _m_pmaddwd(v108[57], v392[5]));
          v393[60] = _mm_cvtsi64_si32(_m_packssdw(v194, v194));
          v198 = _m_paddd(_m_paddd(v197, v195), v196);
          v199 = _m_psradi(_m_paddd(v198, _m_psrlqi(v198, 0x20u)), 0xDu);
          v393[62] = _mm_cvtsi64_si32(_m_packssdw(v199, v199));
        }
        else
        {
          v200 = (__m64 *)((char *)&unk_5B730C - 2 * v391);
          v201 = _m_paddd(
                   _m_paddd(
                     _m_paddd(_m_pmaddwd((__m64)v392->m64_u64, (__m64)v200->m64_u64), _m_pmaddwd(v200[1], v392[1])),
                     _m_pmaddwd(v200[2], v392[2])),
                   _m_pmaddwd(v200[3], v392[3]));
          v202 = _m_pmaddwd(v200[8], v392[4]);
          v203 = _m_pmaddwd(v200[9], v392[5]);
          v204 = _m_psradi(_m_paddd(v201, _m_psrlqi(v201, 0x20u)), 0xDu);
          v205 = _m_pmaddwd(v200[10], v392[6]);
          v206 = _m_pmaddwd(v200[11], v392[7]);
          *v393 = _mm_cvtsi64_si32(_m_packssdw(v204, v204));
          v207 = _m_paddd(_m_paddd(_m_paddd(v202, v203), v205), v206);
          v208 = _m_pmaddwd(v200[16], v392[8]);
          v209 = _m_pmaddwd(v200[17], v392[9]);
          v210 = _m_psradi(_m_paddd(v207, _m_psrlqi(v207, 0x20u)), 0xDu);
          v211 = _m_pmaddwd(v200[18], v392[10]);
          v212 = _m_pmaddwd(v200[19], v392[11]);
          v393[1] = _mm_cvtsi64_si32(_m_packssdw(v210, v210));
          v213 = _m_paddd(_m_paddd(_m_paddd(v208, v209), v211), v212);
          v214 = _m_pmaddwd(v200[24], v392[12]);
          v215 = _m_pmaddwd(v200[25], v392[13]);
          v216 = _m_psradi(_m_paddd(v213, _m_psrlqi(v213, 0x20u)), 0xDu);
          v217 = _m_pmaddwd(v200[26], v392[14]);
          v218 = _m_pmaddwd(v200[27], v392[15]);
          v393[2] = _mm_cvtsi64_si32(_m_packssdw(v216, v216));
          v219 = _m_paddd(_m_paddd(_m_paddd(v214, v215), v217), v218);
          v220 = _m_pmaddwd(v200[32], v392[16]);
          v221 = _m_pmaddwd(v200[33], v392[17]);
          v222 = _m_psradi(_m_paddd(v219, _m_psrlqi(v219, 0x20u)), 0xDu);
          v223 = _m_pmaddwd(v200[34], v392[18]);
          v224 = _m_pmaddwd(v200[35], v392[19]);
          v393[3] = _mm_cvtsi64_si32(_m_packssdw(v222, v222));
          v225 = _m_paddd(_m_paddd(_m_paddd(v220, v221), v223), v224);
          v226 = _m_pmaddwd(v200[40], v392[20]);
          v227 = _m_pmaddwd(v200[41], v392[21]);
          v228 = _m_psradi(_m_paddd(v225, _m_psrlqi(v225, 0x20u)), 0xDu);
          v229 = _m_pmaddwd(v200[42], v392[22]);
          v230 = _m_pmaddwd(v200[43], v392[23]);
          v393[4] = _mm_cvtsi64_si32(_m_packssdw(v228, v228));
          v231 = _m_paddd(_m_paddd(_m_paddd(v226, v227), v229), v230);
          v232 = _m_pmaddwd(v200[48], v392[24]);
          v233 = _m_pmaddwd(v200[49], v392[25]);
          v234 = _m_psradi(_m_paddd(v231, _m_psrlqi(v231, 0x20u)), 0xDu);
          v235 = _m_pmaddwd(v200[50], v392[26]);
          v236 = _m_pmaddwd(v200[51], v392[27]);
          v393[5] = _mm_cvtsi64_si32(_m_packssdw(v234, v234));
          v237 = _m_paddd(_m_paddd(_m_paddd(v232, v233), v235), v236);
          v238 = _m_pmaddwd(v200[56], v392[28]);
          v239 = _m_pmaddwd(v200[57], v392[29]);
          v240 = _m_psradi(_m_paddd(v237, _m_psrlqi(v237, 0x20u)), 0xDu);
          v241 = _m_pmaddwd(v200[58], v392[30]);
          v242 = _m_pmaddwd(v200[59], v392[31]);
          v393[6] = _mm_cvtsi64_si32(_m_packssdw(v240, v240));
          v243 = _m_paddd(_m_paddd(_m_paddd(v238, v239), v241), v242);
          v244 = _m_pmaddwd(v200[64], v392[32]);
          v245 = _m_pmaddwd(v200[65], v392[33]);
          v246 = _m_psradi(_m_paddd(v243, _m_psrlqi(v243, 0x20u)), 0xDu);
          v247 = _m_pmaddwd(v200[66], v392[34]);
          v248 = _m_pmaddwd(v200[67], v392[35]);
          v393[7] = _mm_cvtsi64_si32(_m_packssdw(v246, v246));
          v249 = _m_paddd(_m_paddd(_m_paddd(v244, v245), v247), v248);
          v250 = _m_pmaddwd(v200[72], v392[36]);
          v251 = _m_pmaddwd(v200[73], v392[37]);
          v252 = _m_psradi(_m_paddd(v249, _m_psrlqi(v249, 0x20u)), 0xDu);
          v253 = _m_pmaddwd(v200[74], v392[38]);
          v254 = _m_pmaddwd(v200[75], v392[39]);
          v393[8] = _mm_cvtsi64_si32(_m_packssdw(v252, v252));
          v255 = _m_paddd(_m_paddd(_m_paddd(v250, v251), v253), v254);
          v256 = _m_pmaddwd(v200[80], v392[40]);
          v257 = _m_pmaddwd(v200[81], v392[41]);
          v258 = _m_psradi(_m_paddd(v255, _m_psrlqi(v255, 0x20u)), 0xDu);
          v259 = _m_pmaddwd(v200[82], v392[42]);
          v260 = _m_pmaddwd(v200[83], v392[43]);
          v393[9] = _mm_cvtsi64_si32(_m_packssdw(v258, v258));
          v261 = _m_paddd(_m_paddd(_m_paddd(v256, v257), v259), v260);
          v262 = _m_pmaddwd(v200[88], v392[44]);
          v263 = _m_pmaddwd(v200[89], v392[45]);
          v264 = _m_psradi(_m_paddd(v261, _m_psrlqi(v261, 0x20u)), 0xDu);
          v265 = _m_pmaddwd(v200[90], v392[46]);
          v266 = _m_pmaddwd(v200[91], v392[47]);
          v393[10] = _mm_cvtsi64_si32(_m_packssdw(v264, v264));
          v267 = _m_paddd(_m_paddd(_m_paddd(v262, v263), v265), v266);
          v268 = _m_pmaddwd(v200[96], v392[48]);
          v269 = _m_pmaddwd(v200[97], v392[49]);
          v270 = _m_psradi(_m_paddd(v267, _m_psrlqi(v267, 0x20u)), 0xDu);
          v271 = _m_pmaddwd(v200[98], v392[50]);
          v272 = _m_pmaddwd(v200[99], v392[51]);
          v393[11] = _mm_cvtsi64_si32(_m_packssdw(v270, v270));
          v273 = _m_paddd(_m_paddd(_m_paddd(v268, v269), v271), v272);
          v274 = _m_pmaddwd(v200[104], v392[52]);
          v275 = _m_pmaddwd(v200[105], v392[53]);
          v276 = _m_psradi(_m_paddd(v273, _m_psrlqi(v273, 0x20u)), 0xDu);
          v277 = _m_pmaddwd(v200[106], v392[54]);
          v278 = _m_pmaddwd(v200[107], v392[55]);
          v393[12] = _mm_cvtsi64_si32(_m_packssdw(v276, v276));
          v279 = _m_paddd(_m_paddd(_m_paddd(v274, v275), v277), v278);
          v280 = _m_pmaddwd(v200[112], v392[56]);
          v281 = _m_pmaddwd(v200[113], v392[57]);
          v282 = _m_psradi(_m_paddd(v279, _m_psrlqi(v279, 0x20u)), 0xDu);
          v283 = _m_pmaddwd(v200[114], v392[58]);
          v284 = _m_pmaddwd(v200[115], v392[59]);
          v393[13] = _mm_cvtsi64_si32(_m_packssdw(v282, v282));
          v285 = _m_paddd(_m_paddd(_m_paddd(v280, v281), v283), v284);
          v286 = _m_pmaddwd(v200[120], v392[60]);
          v287 = _m_pmaddwd(v200[121], v392[61]);
          v288 = _m_psradi(_m_paddd(v285, _m_psrlqi(v285, 0x20u)), 0xDu);
          v289 = _m_pmaddwd(v200[122], v392[62]);
          v290 = _m_pmaddwd(v200[123], v392[63]);
          v393[14] = _mm_cvtsi64_si32(_m_packssdw(v288, v288));
          v291 = _m_paddd(_m_paddd(_m_paddd(v286, v287), v289), v290);
          v292 = _m_psradi(_m_paddd(v291, _m_psrlqi(v291, 0x20u)), 0xDu);
          v293 = _m_pmulhw(v200[131], v392[67]);
          v294 = _m_pslldi(_m_pmulhw(v200[128], v392[64]), 0x10u);
          v295 = _m_pslldi(_m_pmulhw(v200[129], v392[65]), 0x10u);
          v296 = _m_pslldi(_m_pmulhw(v200[130], v392[66]), 0x10u);
          v393[15] = _mm_cvtsi64_si32(_m_packssdw(v292, v292));
          v297 = _m_paddd(_m_paddd(_m_paddd(v294, v295), v296), _m_pslldi(v293, 0x10u));
          v298 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6F0C - 2 * v391), v392[60]);
          v299 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6F14 - 2 * v391), v392[61]);
          v300 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6F1C - 2 * v391), v392[62]);
          v301 = _m_psradi(_m_paddd(v297, _m_psrlqi(v297, 0x20u)), 0xDu);
          v302 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6F24 - 2 * v391), v392[63]);
          v393[16] = _mm_cvtsi64_si32(_m_packssdw(v301, v301));
          v303 = _m_paddd(_m_paddd(_m_paddd(v298, v299), v300), v302);
          v304 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6F4C - 2 * v391), v392[56]);
          v305 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6F54 - 2 * v391), v392[57]);
          v306 = _m_psradi(_m_paddd(v303, _m_psrlqi(v303, 0x20u)), 0xDu);
          v307 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6F5C - 2 * v391), v392[58]);
          v308 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6F64 - 2 * v391), v392[59]);
          v393[17] = _mm_cvtsi64_si32(_m_packssdw(v306, v306));
          v309 = _m_paddd(_m_paddd(_m_paddd(v304, v305), v307), v308);
          v310 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6F8C - 2 * v391), v392[52]);
          v311 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6F94 - 2 * v391), v392[53]);
          v312 = _m_psradi(_m_paddd(v309, _m_psrlqi(v309, 0x20u)), 0xDu);
          v313 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6F9C - 2 * v391), v392[54]);
          v314 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6FA4 - 2 * v391), v392[55]);
          v393[18] = _mm_cvtsi64_si32(_m_packssdw(v312, v312));
          v315 = _m_paddd(_m_paddd(_m_paddd(v310, v311), v313), v314);
          v316 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6FCC - 2 * v391), v392[48]);
          v317 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6FD4 - 2 * v391), v392[49]);
          v318 = _m_psradi(_m_paddd(v315, _m_psrlqi(v315, 0x20u)), 0xDu);
          v319 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6FDC - 2 * v391), v392[50]);
          v320 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B6FE4 - 2 * v391), v392[51]);
          v393[19] = _mm_cvtsi64_si32(_m_packssdw(v318, v318));
          v321 = _m_paddd(_m_paddd(_m_paddd(v316, v317), v319), v320);
          v322 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B700C - 2 * v391), v392[44]);
          v323 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7014 - 2 * v391), v392[45]);
          v324 = _m_psradi(_m_paddd(v321, _m_psrlqi(v321, 0x20u)), 0xDu);
          v325 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B701C - 2 * v391), v392[46]);
          v326 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7024 - 2 * v391), v392[47]);
          v393[20] = _mm_cvtsi64_si32(_m_packssdw(v324, v324));
          v327 = _m_paddd(_m_paddd(_m_paddd(v322, v323), v325), v326);
          v328 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B704C - 2 * v391), v392[40]);
          v329 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7054 - 2 * v391), v392[41]);
          v330 = _m_psradi(_m_paddd(v327, _m_psrlqi(v327, 0x20u)), 0xDu);
          v331 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B705C - 2 * v391), v392[42]);
          v332 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7064 - 2 * v391), v392[43]);
          v393[21] = _mm_cvtsi64_si32(_m_packssdw(v330, v330));
          v333 = _m_paddd(_m_paddd(_m_paddd(v328, v329), v331), v332);
          v334 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B708C - 2 * v391), v392[36]);
          v335 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7094 - 2 * v391), v392[37]);
          v336 = _m_psradi(_m_paddd(v333, _m_psrlqi(v333, 0x20u)), 0xDu);
          v337 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B709C - 2 * v391), v392[38]);
          v338 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B70A4 - 2 * v391), v392[39]);
          v393[22] = _mm_cvtsi64_si32(_m_packssdw(v336, v336));
          v339 = _m_paddd(_m_paddd(_m_paddd(v334, v335), v337), v338);
          v340 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B70CC - 2 * v391), v392[32]);
          v341 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B70D4 - 2 * v391), v392[33]);
          v342 = _m_psradi(_m_paddd(v339, _m_psrlqi(v339, 0x20u)), 0xDu);
          v343 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B70DC - 2 * v391), v392[34]);
          v344 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B70E4 - 2 * v391), v392[35]);
          v393[23] = _mm_cvtsi64_si32(_m_packssdw(v342, v342));
          v345 = _m_paddd(_m_paddd(_m_paddd(v340, v341), v343), v344);
          v346 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B710C - 2 * v391), v392[28]);
          v347 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7114 - 2 * v391), v392[29]);
          v348 = _m_psradi(_m_paddd(v345, _m_psrlqi(v345, 0x20u)), 0xDu);
          v349 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B711C - 2 * v391), v392[30]);
          v350 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7124 - 2 * v391), v392[31]);
          v393[24] = _mm_cvtsi64_si32(_m_packssdw(v348, v348));
          v351 = _m_paddd(_m_paddd(_m_paddd(v346, v347), v349), v350);
          v352 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B714C - 2 * v391), v392[24]);
          v353 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7154 - 2 * v391), v392[25]);
          v354 = _m_psradi(_m_paddd(v351, _m_psrlqi(v351, 0x20u)), 0xDu);
          v355 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B715C - 2 * v391), v392[26]);
          v356 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7164 - 2 * v391), v392[27]);
          v393[25] = _mm_cvtsi64_si32(_m_packssdw(v354, v354));
          v357 = _m_paddd(_m_paddd(_m_paddd(v352, v353), v355), v356);
          v358 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B718C - 2 * v391), v392[20]);
          v359 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7194 - 2 * v391), v392[21]);
          v360 = _m_psradi(_m_paddd(v357, _m_psrlqi(v357, 0x20u)), 0xDu);
          v361 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B719C - 2 * v391), v392[22]);
          v362 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B71A4 - 2 * v391), v392[23]);
          v393[26] = _mm_cvtsi64_si32(_m_packssdw(v360, v360));
          v363 = _m_paddd(_m_paddd(_m_paddd(v358, v359), v361), v362);
          v364 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B71CC - 2 * v391), v392[16]);
          v365 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B71D4 - 2 * v391), v392[17]);
          v366 = _m_psradi(_m_paddd(v363, _m_psrlqi(v363, 0x20u)), 0xDu);
          v367 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B71DC - 2 * v391), v392[18]);
          v368 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B71E4 - 2 * v391), v392[19]);
          v393[27] = _mm_cvtsi64_si32(_m_packssdw(v366, v366));
          v369 = _m_paddd(_m_paddd(_m_paddd(v364, v365), v367), v368);
          v370 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B720C - 2 * v391), v392[12]);
          v371 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7214 - 2 * v391), v392[13]);
          v372 = _m_psradi(_m_paddd(v369, _m_psrlqi(v369, 0x20u)), 0xDu);
          v373 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B721C - 2 * v391), v392[14]);
          v374 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7224 - 2 * v391), v392[15]);
          v393[28] = _mm_cvtsi64_si32(_m_packssdw(v372, v372));
          v375 = _m_paddd(_m_paddd(_m_paddd(v370, v371), v373), v374);
          v376 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B724C - 2 * v391), v392[8]);
          v377 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7254 - 2 * v391), v392[9]);
          v378 = _m_psradi(_m_paddd(v375, _m_psrlqi(v375, 0x20u)), 0xDu);
          v379 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B725C - 2 * v391), v392[10]);
          v380 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B7264 - 2 * v391), v392[11]);
          v393[29] = _mm_cvtsi64_si32(_m_packssdw(v378, v378));
          v381 = _m_paddd(_m_paddd(_m_paddd(v376, v377), v379), v380);
          v382 = _m_psradi(_m_paddd(v381, _m_psrlqi(v381, 0x20u)), 0xDu);
          v383 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B729C - 2 * v391), v392[6]);
          v384 = _m_pmaddwd(*(__m64 *)((char *)&unk_5B72A4 - 2 * v391), v392[7]);
          v385 = _m_paddd(
                   _m_pmaddwd(*(__m64 *)((char *)&unk_5B728C - 2 * v391), v392[4]),
                   _m_pmaddwd(*(__m64 *)((char *)&unk_5B7294 - 2 * v391), v392[5]));
          v393[30] = _mm_cvtsi64_si32(_m_packssdw(v382, v382));
          v386 = _m_paddd(_m_paddd(v385, v383), v384);
          v387 = _m_psradi(_m_paddd(v386, _m_psrlqi(v386, 0x20u)), 0xDu);
          v393[31] = _mm_cvtsi64_si32(_m_packssdw(v387, v387));
        }
        v8 = v390;
      }
      v396 += 1152;
      v395 += 1152;
      a3 += 64;
      result = v389 + 1;
      v388 = ++v389 < *(_DWORD *)(this + 9420);
      ++v393;
      if ( !v388 )
        break;
      v10 = v395;
      v9 = 288 * v5;
    }
  }
  return result;
}
