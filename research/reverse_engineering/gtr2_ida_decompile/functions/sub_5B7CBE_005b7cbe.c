__m64 *__stdcall sub_5B7CBE(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4, __m64 *a5, __m64 *a6, __m64 *a7)
{
  __m64 *result; // eax
  __m64 v8; // mm4
  __m64 v9; // mm1
  __m64 v10; // mm5
  __m64 v11; // mm0
  __m64 v12; // mm5
  __m64 v13; // mm2
  __m64 v14; // mm3
  __m64 v15; // mm1
  __m64 v16; // mm6
  __m64 v17; // mm3
  __m64 v18; // mm6
  __m64 v19; // mm2
  __m64 v20; // mm1
  __m64 m64_u64; // mm3
  __m64 v22; // mm4
  __m64 v23; // mm1
  __m64 v24; // mm2
  __m64 v25; // mm2
  __m64 v26; // mm1
  __m64 v27; // mm2
  __m64 v28; // mm3
  __m64 v29; // mm0
  __m64 v30; // mm1
  __m64 v31; // mm2
  __m64 v32; // mm5
  __m64 v33; // mm3
  __m64 v34; // mm2
  __m64 v35; // mm7
  __m64 v36; // mm0
  __m64 v37; // mm3
  __m64 v38; // mm1
  __m64 v39; // mm2
  __m64 v40; // mm3
  __m64 v41; // mm0
  __m64 v42; // mm1
  __m64 v43; // mm2
  __m64 v44; // mm5
  __m64 v45; // mm3
  __m64 v46; // mm2
  __m64 v47; // mm7
  __m64 v48; // mm0
  __m64 v49; // mm3
  __m64 v50; // mm1
  __m64 v51; // mm2
  __m64 v52; // mm3
  __m64 v53; // mm0
  __m64 v54; // mm1
  __m64 v55; // mm2
  __m64 v56; // mm5
  __m64 v57; // mm3
  __m64 v58; // mm2
  __m64 v59; // mm7
  __m64 v60; // mm0
  __m64 v61; // mm3
  __m64 v62; // mm1
  __m64 v63; // mm2
  __m64 v64; // mm3
  __m64 v65; // mm0
  __m64 v66; // mm1
  __m64 v67; // mm2
  __m64 v68; // mm5
  __m64 v69; // mm3
  __m64 v70; // mm7
  __m64 v71; // mm2
  __m64 v72; // mm3
  __m64 v73; // mm1
  __m64 v74; // mm2
  __m64 v75; // mm3
  __m64 v76; // mm0
  __m64 v77; // mm1
  __m64 v78; // mm2
  __m64 v79; // mm5
  __m64 v80; // mm3
  __m64 v81; // mm2
  __m64 v82; // mm7
  __m64 v83; // mm0
  __m64 v84; // mm3
  __m64 v85; // mm1
  __m64 v86; // mm2
  __m64 v87; // mm3
  __m64 v88; // mm0
  __m64 v89; // mm1
  __m64 v90; // mm2
  __m64 v91; // mm5
  __m64 v92; // mm3
  __m64 v93; // mm2
  __m64 v94; // mm7
  __m64 v95; // mm0
  __m64 v96; // mm3
  __m64 v97; // mm1
  __m64 v98; // mm2
  __m64 v99; // mm3
  __m64 v100; // mm0
  __m64 v101; // mm1
  __m64 v102; // mm2
  __m64 v103; // mm5
  __m64 v104; // mm3
  __m64 v105; // mm2
  __m64 v106; // mm7
  __m64 v107; // mm0
  __m64 v108; // mm3
  __m64 v109; // mm1
  __m64 v110; // mm2
  __m64 v111; // mm3
  __m64 v112; // mm0
  __m64 v113; // mm1
  __m64 v114; // mm2
  __m64 v115; // mm5
  __m64 v116; // mm3
  __m64 v117; // mm7
  __m64 v118; // mm2
  __m64 v119; // mm3
  __m64 v120; // mm1
  __m64 v121; // mm2
  __m64 v122; // mm3
  __m64 v123; // mm0
  __m64 v124; // mm1
  __m64 v125; // mm2
  __m64 v126; // mm5
  __m64 v127; // mm3
  __m64 v128; // mm2
  __m64 v129; // mm7
  __m64 v130; // mm0
  __m64 v131; // mm3
  __m64 v132; // mm1
  __m64 v133; // mm2
  __m64 v134; // mm3
  __m64 v135; // mm0
  __m64 v136; // mm1
  __m64 v137; // mm2
  __m64 v138; // mm5
  __m64 v139; // mm3
  __m64 v140; // mm2
  __m64 v141; // mm7
  __m64 v142; // mm0
  __m64 v143; // mm3
  __m64 v144; // mm1
  __m64 v145; // mm2
  __m64 v146; // mm3
  __m64 v147; // mm0
  __m64 v148; // mm1
  __m64 v149; // mm2
  __m64 v150; // mm5
  __m64 v151; // mm3
  __m64 v152; // mm2
  __m64 v153; // mm7
  __m64 v154; // mm0
  __m64 v155; // mm3
  __m64 v156; // mm1
  __m64 v157; // mm2
  __m64 v158; // mm3
  __m64 v159; // mm0
  __m64 v160; // mm1
  __m64 v161; // mm2
  __m64 v162; // mm3
  __m64 v163; // mm2
  __m64 v164; // mm3
  __m64 v165; // mm2
  __m64 v166; // mm1
  __m64 v167; // mm2
  __m64 v168; // mm3
  __m64 v169; // mm0
  __m64 v170; // mm1
  __m64 v171; // mm2
  __m64 v172; // mm5
  __m64 v173; // mm3
  __m64 v174; // mm2
  __m64 v175; // mm7
  __m64 v176; // mm0
  __m64 v177; // mm3
  __m64 v178; // mm1
  __m64 v179; // mm2
  __m64 v180; // mm3
  __m64 v181; // mm0
  __m64 v182; // mm1
  __m64 v183; // mm2
  __m64 v184; // mm5
  __m64 v185; // mm3
  __m64 v186; // mm2
  __m64 v187; // mm7
  __m64 v188; // mm0
  __m64 v189; // mm3
  __m64 v190; // mm1
  __m64 v191; // mm2
  __m64 v192; // mm3
  __m64 v193; // mm0
  __m64 v194; // mm1
  __m64 v195; // mm2
  __m64 v196; // mm5
  __m64 v197; // mm3
  __m64 v198; // mm2
  __m64 v199; // mm7
  __m64 v200; // mm0
  __m64 v201; // mm3
  __m64 v202; // mm1
  __m64 v203; // mm2
  __m64 v204; // mm3
  __m64 v205; // mm0
  __m64 v206; // mm1
  __m64 v207; // mm2
  __m64 v208; // mm5
  __m64 v209; // mm3
  __m64 v210; // mm7
  __m64 v211; // mm2
  __m64 v212; // mm3
  __m64 v213; // mm1
  __m64 v214; // mm2
  __m64 v215; // mm3
  __m64 v216; // mm0
  __m64 v217; // mm1
  __m64 v218; // mm2
  __m64 v219; // mm5
  __m64 v220; // mm3
  __m64 v221; // mm2
  __m64 v222; // mm7
  __m64 v223; // mm0
  __m64 v224; // mm3
  __m64 v225; // mm1
  __m64 v226; // mm2
  __m64 v227; // mm3
  __m64 v228; // mm0
  __m64 v229; // mm1
  __m64 v230; // mm2
  __m64 v231; // mm5
  __m64 v232; // mm3
  __m64 v233; // mm2
  __m64 v234; // mm7
  __m64 v235; // mm0
  __m64 v236; // mm3
  __m64 v237; // mm1
  __m64 v238; // mm2
  __m64 v239; // mm3
  __m64 v240; // mm0
  __m64 v241; // mm1
  __m64 v242; // mm2
  __m64 v243; // mm5
  __m64 v244; // mm3
  __m64 v245; // mm2
  __m64 v246; // mm7
  __m64 v247; // mm0
  __m64 v248; // mm3
  __m64 v249; // mm1
  __m64 v250; // mm2
  __m64 v251; // mm3
  __m64 v252; // mm0
  __m64 v253; // mm1
  __m64 v254; // mm2
  __m64 v255; // mm3
  __m64 v256; // mm4
  __m64 v257; // mm2
  __m64 v258; // mm3
  __m64 v259; // mm5
  __m64 v260; // mm1
  __m64 v261; // mm4
  __m64 v262; // mm5
  __m64 v263; // mm1
  __m64 v264; // mm2
  __m64 v265; // mm4
  __m64 v266; // mm1
  __m64 v267; // mm5
  __m64 v268; // mm0
  __m64 v269; // mm5
  __m64 v270; // mm2
  __m64 v271; // mm3
  __m64 v272; // mm1
  __m64 v273; // mm6
  __m64 v274; // mm3
  __m64 v275; // mm6
  __m64 v276; // mm2
  __m64 v277; // mm1
  __m64 v278; // mm5
  __m64 v279; // mm2
  __m64 v280; // mm3
  __m64 v281; // mm2
  __m64 v282; // mm3
  __m64 v283; // mm1
  __m64 v284; // mm1
  __m64 v285; // mm2
  __m64 v286; // mm3
  __m64 v287; // mm0
  __m64 v288; // mm1
  __m64 v289; // mm2
  __m64 v290; // mm5
  __m64 v291; // mm3
  __m64 v292; // mm2
  __m64 v293; // mm7
  __m64 v294; // mm0
  __m64 v295; // mm3
  __m64 v296; // mm1
  __m64 v297; // mm2
  __m64 v298; // mm3
  __m64 v299; // mm0
  __m64 v300; // mm1
  __m64 v301; // mm2
  __m64 v302; // mm5
  __m64 v303; // mm3
  __m64 v304; // mm2
  __m64 v305; // mm7
  __m64 v306; // mm0
  __m64 v307; // mm3
  __m64 v308; // mm1
  __m64 v309; // mm2
  __m64 v310; // mm3
  __m64 v311; // mm0
  __m64 v312; // mm1
  __m64 v313; // mm2
  __m64 v314; // mm5
  __m64 v315; // mm3
  __m64 v316; // mm2
  __m64 v317; // mm7
  __m64 v318; // mm0
  __m64 v319; // mm3
  __m64 v320; // mm1
  __m64 v321; // mm2
  __m64 v322; // mm3
  __m64 v323; // mm0
  __m64 v324; // mm1
  __m64 v325; // mm2
  __m64 v326; // mm3
  __m64 v327; // mm1
  __m64 v328; // mm1
  __m64 v329; // mm2
  __m64 v330; // mm3
  __m64 v331; // mm0
  __m64 v332; // mm1
  __m64 v333; // mm2
  __m64 v334; // mm5
  __m64 v335; // mm3
  __m64 v336; // mm2
  __m64 v337; // mm7
  __m64 v338; // mm0
  __m64 v339; // mm3
  __m64 v340; // mm1
  __m64 v341; // mm2
  __m64 v342; // mm3
  __m64 v343; // mm0
  __m64 v344; // mm1
  __m64 v345; // mm2
  __m64 v346; // mm5
  __m64 v347; // mm3
  __m64 v348; // mm2
  __m64 v349; // mm7
  __m64 v350; // mm0
  __m64 v351; // mm3
  __m64 v352; // mm1
  __m64 v353; // mm2
  __m64 v354; // mm3
  __m64 v355; // mm0
  __m64 v356; // mm1
  __m64 v357; // mm2
  __m64 v358; // mm5
  __m64 v359; // mm3
  __m64 v360; // mm2
  __m64 v361; // mm7
  __m64 v362; // mm0
  __m64 v363; // mm3
  __m64 v364; // mm1
  __m64 v365; // mm2
  __m64 v366; // mm3
  __m64 v367; // mm0
  __m64 v368; // mm1
  __m64 v369; // mm2
  __m64 v370; // mm3
  __m64 v371; // mm1
  __m64 v372; // [esp+0h] [ebp-C0h]
  __m64 v373; // [esp+10h] [ebp-B0h]
  __m64 v374; // [esp+28h] [ebp-98h]
  __m64 v375; // [esp+40h] [ebp-80h]
  __m64 v376; // [esp+40h] [ebp-80h]
  __m64 v377; // [esp+48h] [ebp-78h]
  __m64 v378; // [esp+48h] [ebp-78h]
  __m64 v379; // [esp+50h] [ebp-70h]
  __m64 v380; // [esp+50h] [ebp-70h]
  __m64 v381; // [esp+58h] [ebp-68h]
  __m64 v382; // [esp+58h] [ebp-68h]
  __m64 v383; // [esp+60h] [ebp-60h]
  __m64 v384; // [esp+60h] [ebp-60h]
  __m64 v385; // [esp+68h] [ebp-58h]
  __m64 v386; // [esp+68h] [ebp-58h]
  __m64 v387; // [esp+78h] [ebp-48h]
  __m64 v388; // [esp+78h] [ebp-48h]
  __m64 v389; // [esp+80h] [ebp-40h]
  __m64 v390; // [esp+88h] [ebp-38h]
  __m64 v391; // [esp+90h] [ebp-30h]
  __m64 v392; // [esp+98h] [ebp-28h]
  __m64 v393; // [esp+A0h] [ebp-20h]
  __m64 v394; // [esp+A8h] [ebp-18h]
  __m64 v395; // [esp+B0h] [ebp-10h]
  __m64 v396; // [esp+B8h] [ebp-8h]

  result = a1;
  if ( a4 )
  {
    if ( a3 )
    {
      v372 = _m_punpckldq((__m64)a4->m64_u64, 0);
      v373 = _m_punpckhdq(0, (__m64)a4->m64_u64);
      v374 = _mm_cvtsi32_si64(a4[1].m64_u32[0]);
      v8 = a3[1];
      v9 = _m_pfadd(v8, v8);
      v10 = _m_pfadd((__m64)a3->m64_u64, (__m64)a3->m64_u64);
      v11 = _m_pfmul(v10, (__m64)a3->m64_u64);
      v12 = _m_punpckldq(v10, v9);
      v13 = _m_pfmul((__m64)a3->m64_u64, v9);
      v14 = _m_pfmul(_m_pswapd((__m64)a3->m64_u64), v9);
      v15 = _m_pfmul(v9, v8);
      v16 = _m_pfmul(_m_punpckhdq((__m64)a3->m64_u64, v8), v12);
      v17 = _m_pfpnacc(v14, v14);
      v18 = _m_pfpnacc(v16, v16);
      v19 = _m_pfpnacc(v13, v13);
      v20 = _m_pfsub(_m_pfsubr(v11, (__m64)0x3F8000003F800000LL), _m_punpckldq(v15, v15));
      v383 = _m_punpckldq(_m_pswapd(v19), v17);
      v377 = _m_punpckldq(v19, 0);
      v385 = _m_punpckhdq(_m_pfsubr(_m_pfacc(v11, v11), (__m64)0x3F8000003F800000LL), 0);
      v375 = _m_punpckhdq(v20, v18);
      v379 = _m_punpckldq(v18, v20);
      v381 = _m_punpckhdq(v17, 0);
      v387 = _m_punpckldq(0, (__m64)1065353216LL);
      if ( a2 )
      {
        v389 = _m_punpckldq(v375, v379);
        v391 = _m_punpckhdq(v375, v379);
        v394 = _m_punpckldq(v385, v387);
        v396 = _m_punpckhdq(v385, v387);
        v393 = _m_punpckldq(v377, v381);
        v395 = _m_punpckhdq(v377, v381);
        v392 = _m_punpckhdq(v383, 0);
        v390 = _m_punpckldq(v383, 0);
        result = a1;
        m64_u64 = (__m64)a2->m64_u64;
        v22 = _mm_cvtsi32_si64(a2[1].m64_u32[0]);
        v23 = _mm_cvtsi32_si64(0x3F800000u);
        v24 = _m_pswapd(v23);
        a1->m64_u64 = (unsigned __int64)v23;
        a1[1].m64_u64 = 0;
        a1[2].m64_u64 = (unsigned __int64)v24;
        a1[3].m64_u64 = 0;
        a1[4].m64_u64 = 0;
        a1[5].m64_u64 = (unsigned __int64)v23;
        v25 = _m_pfsub(v24, v22);
        a1[7].m64_u64 = (unsigned __int64)v25;
        a1[6].m64_u64 = (unsigned __int64)_m_pfsub(0, m64_u64);
        v26 = a1[1];
        v27 = _m_punpckhdq(v25, (__m64)a1->m64_u64);
        v28 = _m_punpckhdq(m64_u64, v26);
        v29 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v30 = _m_punpckldq(v26, v26);
        v31 = _m_punpckhdq(v27, v27);
        v32 = _m_pfmul(v391, v31);
        v33 = _m_punpckhdq(v28, v28);
        v34 = _m_pfadd(_m_pfadd(_m_pfmul(v31, v392), _m_pfmul(v29, v390)), _m_pfmul(v30, v394));
        v35 = _m_pfadd(_m_pfmul(v395, v33), _m_pfadd(_m_pfmul(v393, v30), _m_pfadd(v32, _m_pfmul(v389, v29))));
        v36 = a1[2];
        v37 = _m_pfadd(_m_pfmul(v33, v396), v34);
        v38 = a1[3];
        a1->m64_u64 = (unsigned __int64)v35;
        a1[1].m64_u64 = (unsigned __int64)v37;
        v39 = _m_punpckhdq(v34, v36);
        v40 = _m_punpckhdq(v37, v38);
        v41 = _m_punpckldq(v36, v36);
        v42 = _m_punpckldq(v38, v38);
        v43 = _m_punpckhdq(v39, v39);
        v44 = _m_pfmul(v391, v43);
        v45 = _m_punpckhdq(v40, v40);
        v46 = _m_pfadd(_m_pfadd(_m_pfmul(v43, v392), _m_pfmul(v41, v390)), _m_pfmul(v42, v394));
        v47 = _m_pfadd(_m_pfmul(v395, v45), _m_pfadd(_m_pfmul(v393, v42), _m_pfadd(v44, _m_pfmul(v389, v41))));
        v48 = a1[4];
        v49 = _m_pfadd(_m_pfmul(v45, v396), v46);
        v50 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v47;
        a1[3].m64_u64 = (unsigned __int64)v49;
        v51 = _m_punpckhdq(v46, v48);
        v52 = _m_punpckhdq(v49, v50);
        v53 = _m_punpckldq(v48, v48);
        v54 = _m_punpckldq(v50, v50);
        v55 = _m_punpckhdq(v51, v51);
        v56 = _m_pfmul(v391, v55);
        v57 = _m_punpckhdq(v52, v52);
        v58 = _m_pfadd(_m_pfadd(_m_pfmul(v55, v392), _m_pfmul(v53, v390)), _m_pfmul(v54, v394));
        v59 = _m_pfadd(_m_pfmul(v395, v57), _m_pfadd(_m_pfmul(v393, v54), _m_pfadd(v56, _m_pfmul(v389, v53))));
        v60 = a1[6];
        v61 = _m_pfadd(_m_pfmul(v57, v396), v58);
        v62 = a1[7];
        a1[4].m64_u64 = (unsigned __int64)v59;
        a1[5].m64_u64 = (unsigned __int64)v61;
        v63 = _m_punpckhdq(v58, v60);
        v64 = _m_punpckhdq(v61, v62);
        v65 = _m_punpckldq(v60, v60);
        v66 = _m_punpckldq(v62, v62);
        v67 = _m_punpckhdq(v63, v63);
        v68 = _m_pfmul(v391, v67);
        v69 = _m_punpckhdq(v64, v64);
        v70 = _m_pfmul(v395, v69);
        v71 = _m_pfadd(_m_pfadd(_m_pfmul(v67, v392), _m_pfmul(v65, v390)), _m_pfmul(v66, v394));
        v72 = _m_pfadd(_m_pfmul(v69, v396), v71);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            v70,
                                            _m_pfadd(_m_pfmul(v393, v66), _m_pfadd(v68, _m_pfmul(v389, v65))));
        a1[7].m64_u64 = (unsigned __int64)v72;
        v73 = a1[1];
        v74 = _m_punpckhdq(v71, (__m64)a1->m64_u64);
        v75 = _m_punpckhdq(v72, v73);
        v76 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v77 = _m_punpckldq(v73, v73);
        v78 = _m_punpckhdq(v74, v74);
        v79 = _m_pfmul(v373, v78);
        v80 = _m_punpckhdq(v75, v75);
        v81 = _m_pfadd(_m_pfadd(_m_pfmul(v78, 0), _m_pfmul(v76, 0)), _m_pfmul(v77, v374));
        v82 = _m_pfadd(_m_pfmul(0, v80), _m_pfadd(_m_pfmul(0, v77), _m_pfadd(v79, _m_pfmul(v372, v76))));
        v83 = a1[2];
        v84 = _m_pfadd(_m_pfmul(v80, (__m64)0x3F80000000000000LL), v81);
        v85 = a1[3];
        a1->m64_u64 = (unsigned __int64)v82;
        a1[1].m64_u64 = (unsigned __int64)v84;
        v86 = _m_punpckhdq(v81, v83);
        v87 = _m_punpckhdq(v84, v85);
        v88 = _m_punpckldq(v83, v83);
        v89 = _m_punpckldq(v85, v85);
        v90 = _m_punpckhdq(v86, v86);
        v91 = _m_pfmul(v373, v90);
        v92 = _m_punpckhdq(v87, v87);
        v93 = _m_pfadd(_m_pfadd(_m_pfmul(v90, 0), _m_pfmul(v88, 0)), _m_pfmul(v89, v374));
        v94 = _m_pfadd(_m_pfmul(0, v92), _m_pfadd(_m_pfmul(0, v89), _m_pfadd(v91, _m_pfmul(v372, v88))));
        v95 = a1[4];
        v96 = _m_pfadd(_m_pfmul(v92, (__m64)0x3F80000000000000LL), v93);
        v97 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v94;
        a1[3].m64_u64 = (unsigned __int64)v96;
        v98 = _m_punpckhdq(v93, v95);
        v99 = _m_punpckhdq(v96, v97);
        v100 = _m_punpckldq(v95, v95);
        v101 = _m_punpckldq(v97, v97);
        v102 = _m_punpckhdq(v98, v98);
        v103 = _m_pfmul(v373, v102);
        v104 = _m_punpckhdq(v99, v99);
        v105 = _m_pfadd(_m_pfadd(_m_pfmul(v102, 0), _m_pfmul(v100, 0)), _m_pfmul(v101, v374));
        v106 = _m_pfadd(_m_pfmul(0, v104), _m_pfadd(_m_pfmul(0, v101), _m_pfadd(v103, _m_pfmul(v372, v100))));
        v107 = a1[6];
        v108 = _m_pfadd(_m_pfmul(v104, (__m64)0x3F80000000000000LL), v105);
        v109 = a1[7];
        a1[4].m64_u64 = (unsigned __int64)v106;
        a1[5].m64_u64 = (unsigned __int64)v108;
        v110 = _m_punpckhdq(v105, v107);
        v111 = _m_punpckhdq(v108, v109);
        v112 = _m_punpckldq(v107, v107);
        v113 = _m_punpckldq(v109, v109);
        v114 = _m_punpckhdq(v110, v110);
        v115 = _m_pfmul(v373, v114);
        v116 = _m_punpckhdq(v111, v111);
        v117 = _m_pfmul(0, v116);
        v118 = _m_pfadd(_m_pfadd(_m_pfmul(v114, 0), _m_pfmul(v112, 0)), _m_pfmul(v113, v374));
        v119 = _m_pfadd(_m_pfmul(v116, (__m64)0x3F80000000000000LL), v118);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            v117,
                                            _m_pfadd(_m_pfmul(0, v113), _m_pfadd(v115, _m_pfmul(v372, v112))));
        a1[7].m64_u64 = (unsigned __int64)v119;
        v120 = a1[1];
        v121 = _m_punpckhdq(v118, (__m64)a1->m64_u64);
        v122 = _m_punpckhdq(v119, v120);
        v123 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v124 = _m_punpckldq(v120, v120);
        v125 = _m_punpckhdq(v121, v121);
        v126 = _m_pfmul(v379, v125);
        v127 = _m_punpckhdq(v122, v122);
        v128 = _m_pfadd(_m_pfadd(_m_pfmul(v125, v381), _m_pfmul(v123, v377)), _m_pfmul(v124, v385));
        v129 = _m_pfadd(_m_pfmul(0, v127), _m_pfadd(_m_pfmul(v383, v124), _m_pfadd(v126, _m_pfmul(v375, v123))));
        v130 = a1[2];
        v131 = _m_pfadd(_m_pfmul(v127, v387), v128);
        v132 = a1[3];
        a1->m64_u64 = (unsigned __int64)v129;
        a1[1].m64_u64 = (unsigned __int64)v131;
        v133 = _m_punpckhdq(v128, v130);
        v134 = _m_punpckhdq(v131, v132);
        v135 = _m_punpckldq(v130, v130);
        v136 = _m_punpckldq(v132, v132);
        v137 = _m_punpckhdq(v133, v133);
        v138 = _m_pfmul(v379, v137);
        v139 = _m_punpckhdq(v134, v134);
        v140 = _m_pfadd(_m_pfadd(_m_pfmul(v137, v381), _m_pfmul(v135, v377)), _m_pfmul(v136, v385));
        v141 = _m_pfadd(_m_pfmul(0, v139), _m_pfadd(_m_pfmul(v383, v136), _m_pfadd(v138, _m_pfmul(v375, v135))));
        v142 = a1[4];
        v143 = _m_pfadd(_m_pfmul(v139, v387), v140);
        v144 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v141;
        a1[3].m64_u64 = (unsigned __int64)v143;
        v145 = _m_punpckhdq(v140, v142);
        v146 = _m_punpckhdq(v143, v144);
        v147 = _m_punpckldq(v142, v142);
        v148 = _m_punpckldq(v144, v144);
        v149 = _m_punpckhdq(v145, v145);
        v150 = _m_pfmul(v379, v149);
        v151 = _m_punpckhdq(v146, v146);
        v152 = _m_pfadd(_m_pfadd(_m_pfmul(v149, v381), _m_pfmul(v147, v377)), _m_pfmul(v148, v385));
        v153 = _m_pfadd(_m_pfmul(0, v151), _m_pfadd(_m_pfmul(v383, v148), _m_pfadd(v150, _m_pfmul(v375, v147))));
        v154 = a1[6];
        v155 = _m_pfadd(_m_pfmul(v151, v387), v152);
        v156 = a1[7];
        a1[4].m64_u64 = (unsigned __int64)v153;
        a1[5].m64_u64 = (unsigned __int64)v155;
        v157 = _m_punpckhdq(v152, v154);
        v158 = _m_punpckhdq(v155, v156);
        v159 = _m_punpckldq(v154, v154);
        v160 = _m_punpckldq(v156, v156);
        v161 = _m_punpckhdq(v157, v157);
        v162 = _m_punpckhdq(v158, v158);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            _m_pfmul(0, v162),
                                            _m_pfadd(
                                              _m_pfmul(v383, v160),
                                              _m_pfadd(_m_pfmul(v379, v161), _m_pfmul(v375, v159))));
        a1[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                            _m_pfmul(v162, v387),
                                            _m_pfadd(
                                              _m_pfadd(_m_pfmul(v161, v381), _m_pfmul(v159, v377)),
                                              _m_pfmul(v160, v385)));
        v163 = _m_pfadd(_mm_cvtsi32_si64(a2[1].m64_u32[0]), _mm_cvtsi32_si64(a1[7].m64_u32[0]));
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd((__m64)a2->m64_u64, a1[6]);
        a1[7].m64_i32[0] = _mm_cvtsi64_si32(v163);
      }
      else
      {
        result = a1;
        a1->m64_u64 = (unsigned __int64)_m_punpckldq(v375, v379);
        a1[2].m64_u64 = (unsigned __int64)_m_punpckhdq(v375, v379);
        v164 = _m_punpckldq(v385, v387);
        a1[5].m64_u64 = (unsigned __int64)v164;
        a1[7].m64_u64 = (unsigned __int64)_m_punpckhdq(v385, v387);
        a1[4].m64_u64 = (unsigned __int64)_m_punpckldq(v377, v381);
        v165 = _m_punpckldq(v383, 0);
        a1[6].m64_u64 = (unsigned __int64)_m_punpckhdq(v377, v381);
        a1[3].m64_u64 = (unsigned __int64)_m_punpckhdq(v383, 0);
        a1[1].m64_u64 = (unsigned __int64)v165;
        v166 = a1[1];
        v167 = _m_punpckhdq(v165, (__m64)a1->m64_u64);
        v168 = _m_punpckhdq(v164, v166);
        v169 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v170 = _m_punpckldq(v166, v166);
        v171 = _m_punpckhdq(v167, v167);
        v172 = _m_pfmul(v373, v171);
        v173 = _m_punpckhdq(v168, v168);
        v174 = _m_pfadd(_m_pfadd(_m_pfmul(v171, 0), _m_pfmul(v169, 0)), _m_pfmul(v170, v374));
        v175 = _m_pfadd(_m_pfmul(0, v173), _m_pfadd(_m_pfmul(0, v170), _m_pfadd(v172, _m_pfmul(v372, v169))));
        v176 = a1[2];
        v177 = _m_pfadd(_m_pfmul(v173, (__m64)0x3F80000000000000LL), v174);
        v178 = a1[3];
        a1->m64_u64 = (unsigned __int64)v175;
        a1[1].m64_u64 = (unsigned __int64)v177;
        v179 = _m_punpckhdq(v174, v176);
        v180 = _m_punpckhdq(v177, v178);
        v181 = _m_punpckldq(v176, v176);
        v182 = _m_punpckldq(v178, v178);
        v183 = _m_punpckhdq(v179, v179);
        v184 = _m_pfmul(v373, v183);
        v185 = _m_punpckhdq(v180, v180);
        v186 = _m_pfadd(_m_pfadd(_m_pfmul(v183, 0), _m_pfmul(v181, 0)), _m_pfmul(v182, v374));
        v187 = _m_pfadd(_m_pfmul(0, v185), _m_pfadd(_m_pfmul(0, v182), _m_pfadd(v184, _m_pfmul(v372, v181))));
        v188 = a1[4];
        v189 = _m_pfadd(_m_pfmul(v185, (__m64)0x3F80000000000000LL), v186);
        v190 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v187;
        a1[3].m64_u64 = (unsigned __int64)v189;
        v191 = _m_punpckhdq(v186, v188);
        v192 = _m_punpckhdq(v189, v190);
        v193 = _m_punpckldq(v188, v188);
        v194 = _m_punpckldq(v190, v190);
        v195 = _m_punpckhdq(v191, v191);
        v196 = _m_pfmul(v373, v195);
        v197 = _m_punpckhdq(v192, v192);
        v198 = _m_pfadd(_m_pfadd(_m_pfmul(v195, 0), _m_pfmul(v193, 0)), _m_pfmul(v194, v374));
        v199 = _m_pfadd(_m_pfmul(0, v197), _m_pfadd(_m_pfmul(0, v194), _m_pfadd(v196, _m_pfmul(v372, v193))));
        v200 = a1[6];
        v201 = _m_pfadd(_m_pfmul(v197, (__m64)0x3F80000000000000LL), v198);
        v202 = a1[7];
        a1[4].m64_u64 = (unsigned __int64)v199;
        a1[5].m64_u64 = (unsigned __int64)v201;
        v203 = _m_punpckhdq(v198, v200);
        v204 = _m_punpckhdq(v201, v202);
        v205 = _m_punpckldq(v200, v200);
        v206 = _m_punpckldq(v202, v202);
        v207 = _m_punpckhdq(v203, v203);
        v208 = _m_pfmul(v373, v207);
        v209 = _m_punpckhdq(v204, v204);
        v210 = _m_pfmul(0, v209);
        v211 = _m_pfadd(_m_pfadd(_m_pfmul(v207, 0), _m_pfmul(v205, 0)), _m_pfmul(v206, v374));
        v212 = _m_pfadd(_m_pfmul(v209, (__m64)0x3F80000000000000LL), v211);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            v210,
                                            _m_pfadd(_m_pfmul(0, v206), _m_pfadd(v208, _m_pfmul(v372, v205))));
        a1[7].m64_u64 = (unsigned __int64)v212;
        v213 = a1[1];
        v214 = _m_punpckhdq(v211, (__m64)a1->m64_u64);
        v215 = _m_punpckhdq(v212, v213);
        v216 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v217 = _m_punpckldq(v213, v213);
        v218 = _m_punpckhdq(v214, v214);
        v219 = _m_pfmul(v379, v218);
        v220 = _m_punpckhdq(v215, v215);
        v221 = _m_pfadd(_m_pfadd(_m_pfmul(v218, v381), _m_pfmul(v216, v377)), _m_pfmul(v217, v385));
        v222 = _m_pfadd(_m_pfmul(0, v220), _m_pfadd(_m_pfmul(v383, v217), _m_pfadd(v219, _m_pfmul(v375, v216))));
        v223 = a1[2];
        v224 = _m_pfadd(_m_pfmul(v220, v387), v221);
        v225 = a1[3];
        a1->m64_u64 = (unsigned __int64)v222;
        a1[1].m64_u64 = (unsigned __int64)v224;
        v226 = _m_punpckhdq(v221, v223);
        v227 = _m_punpckhdq(v224, v225);
        v228 = _m_punpckldq(v223, v223);
        v229 = _m_punpckldq(v225, v225);
        v230 = _m_punpckhdq(v226, v226);
        v231 = _m_pfmul(v379, v230);
        v232 = _m_punpckhdq(v227, v227);
        v233 = _m_pfadd(_m_pfadd(_m_pfmul(v230, v381), _m_pfmul(v228, v377)), _m_pfmul(v229, v385));
        v234 = _m_pfadd(_m_pfmul(0, v232), _m_pfadd(_m_pfmul(v383, v229), _m_pfadd(v231, _m_pfmul(v375, v228))));
        v235 = a1[4];
        v236 = _m_pfadd(_m_pfmul(v232, v387), v233);
        v237 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v234;
        a1[3].m64_u64 = (unsigned __int64)v236;
        v238 = _m_punpckhdq(v233, v235);
        v239 = _m_punpckhdq(v236, v237);
        v240 = _m_punpckldq(v235, v235);
        v241 = _m_punpckldq(v237, v237);
        v242 = _m_punpckhdq(v238, v238);
        v243 = _m_pfmul(v379, v242);
        v244 = _m_punpckhdq(v239, v239);
        v245 = _m_pfadd(_m_pfadd(_m_pfmul(v242, v381), _m_pfmul(v240, v377)), _m_pfmul(v241, v385));
        v246 = _m_pfadd(_m_pfmul(0, v244), _m_pfadd(_m_pfmul(v383, v241), _m_pfadd(v243, _m_pfmul(v375, v240))));
        v247 = a1[6];
        v248 = _m_pfadd(_m_pfmul(v244, v387), v245);
        v249 = a1[7];
        a1[4].m64_u64 = (unsigned __int64)v246;
        a1[5].m64_u64 = (unsigned __int64)v248;
        v250 = _m_punpckhdq(v245, v247);
        v251 = _m_punpckhdq(v248, v249);
        v252 = _m_punpckldq(v247, v247);
        v253 = _m_punpckldq(v249, v249);
        v254 = _m_punpckhdq(v250, v250);
        v255 = _m_punpckhdq(v251, v251);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            _m_pfmul(0, v255),
                                            _m_pfadd(
                                              _m_pfmul(v383, v253),
                                              _m_pfadd(_m_pfmul(v379, v254), _m_pfmul(v375, v252))));
        a1[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                            _m_pfmul(v255, v387),
                                            _m_pfadd(
                                              _m_pfadd(_m_pfmul(v254, v381), _m_pfmul(v252, v377)),
                                              _m_pfmul(v253, v385)));
      }
    }
    else if ( a2 )
    {
      v256 = (__m64)a2->m64_u64;
      v257 = (__m64)a4->m64_u64;
      v258 = _mm_cvtsi32_si64(a4[1].m64_u32[0]);
      v259 = _m_punpckldq(_mm_cvtsi32_si64(a2[1].m64_u32[0]), (__m64)0x3F8000003F800000LL);
      v260 = _m_pfsub((__m64)0x3F8000003F800000LL, (__m64)a4->m64_u64);
      a1[5].m64_u64 = (unsigned __int64)v258;
      a1[1].m64_u64 = 0;
      a1[3].m64_u64 = 0;
      a1[4].m64_u64 = 0;
      a1->m64_u64 = (unsigned __int64)_m_punpckldq(v257, 0);
      a1[2].m64_u64 = (unsigned __int64)_m_punpckhdq(0, v257);
      a1[6].m64_u64 = (unsigned __int64)_m_pfmul(v260, v256);
      a1[7].m64_u64 = (unsigned __int64)_m_pfmul(_m_pfsub((__m64)0x3F8000003F800000LL, v258), v259);
    }
    else
    {
      v261 = _mm_cvtsi32_si64(a4[1].m64_u32[0]);
      v262 = _m_punpckhdq(0, (__m64)a4->m64_u64);
      a1->m64_u64 = (unsigned __int64)_m_punpckldq((__m64)a4->m64_u64, 0);
      a1[1].m64_u64 = 0;
      a1[2].m64_u64 = (unsigned __int64)v262;
      a1[3].m64_u64 = 0;
      a1[4].m64_u64 = 0;
      a1[5].m64_u64 = (unsigned __int64)v261;
      a1[6].m64_u64 = 0;
      a1[7].m64_u64 = 0x3F80000000000000LL;
    }
  }
  else
  {
    v263 = _mm_cvtsi32_si64(0x3F800000u);
    v264 = _m_pswapd(v263);
    a1->m64_u64 = (unsigned __int64)v263;
    a1[1].m64_u64 = 0;
    a1[2].m64_u64 = (unsigned __int64)v264;
    a1[3].m64_u64 = 0;
    a1[4].m64_u64 = 0;
    a1[5].m64_u64 = (unsigned __int64)v263;
    a1[6].m64_u64 = 0;
    a1[7].m64_u64 = (unsigned __int64)v264;
  }
  if ( a6 )
  {
    v265 = a6[1];
    v266 = _m_pfadd(v265, v265);
    v267 = _m_pfadd((__m64)a6->m64_u64, (__m64)a6->m64_u64);
    v268 = _m_pfmul(v267, (__m64)a6->m64_u64);
    v269 = _m_punpckldq(v267, v266);
    v270 = _m_pfmul((__m64)a6->m64_u64, v266);
    v271 = _m_pfmul(_m_pswapd((__m64)a6->m64_u64), v266);
    v272 = _m_pfmul(v266, v265);
    v273 = _m_pfmul(_m_punpckhdq((__m64)a6->m64_u64, v265), v269);
    v274 = _m_pfpnacc(v271, v271);
    v275 = _m_pfpnacc(v273, v273);
    v276 = _m_pfpnacc(v270, v270);
    v277 = _m_pfsub(_m_pfsubr(v268, (__m64)0x3F8000003F800000LL), _m_punpckldq(v272, v272));
    v278 = _m_punpckldq(_m_pswapd(v276), v274);
    v279 = _m_punpckldq(v276, 0);
    v384 = v278;
    v280 = _m_punpckhdq(v274, 0);
    v378 = v279;
    v386 = _m_punpckhdq(_m_pfsubr(_m_pfacc(v268, v268), (__m64)0x3F8000003F800000LL), 0);
    v376 = _m_punpckhdq(v277, v275);
    v380 = _m_punpckldq(v275, v277);
    v382 = v280;
    v388 = _m_punpckldq(0, (__m64)1065353216LL);
    if ( a5 )
    {
      v281 = (__m64)a5->m64_u64;
      v282 = _mm_cvtsi32_si64(a5[1].m64_u32[0]);
      v283 = _m_pfsub(_mm_cvtsi32_si64(result[7].m64_u32[0]), v282);
      result[6].m64_u64 = (unsigned __int64)_m_pfsub(result[6], (__m64)a5->m64_u64);
      result[7].m64_i32[0] = _mm_cvtsi64_si32(v283);
      v284 = result[1];
      v285 = _m_punpckhdq(v281, (__m64)result->m64_u64);
      v286 = _m_punpckhdq(v282, v284);
      v287 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
      v288 = _m_punpckldq(v284, v284);
      v289 = _m_punpckhdq(v285, v285);
      v290 = _m_pfmul(v380, v289);
      v291 = _m_punpckhdq(v286, v286);
      v292 = _m_pfadd(_m_pfadd(_m_pfmul(v289, v382), _m_pfmul(v287, v378)), _m_pfmul(v288, v386));
      v293 = _m_pfadd(_m_pfmul(0, v291), _m_pfadd(_m_pfmul(v384, v288), _m_pfadd(v290, _m_pfmul(v376, v287))));
      v294 = result[2];
      v295 = _m_pfadd(_m_pfmul(v291, v388), v292);
      v296 = result[3];
      result->m64_u64 = (unsigned __int64)v293;
      result[1].m64_u64 = (unsigned __int64)v295;
      v297 = _m_punpckhdq(v292, v294);
      v298 = _m_punpckhdq(v295, v296);
      v299 = _m_punpckldq(v294, v294);
      v300 = _m_punpckldq(v296, v296);
      v301 = _m_punpckhdq(v297, v297);
      v302 = _m_pfmul(v380, v301);
      v303 = _m_punpckhdq(v298, v298);
      v304 = _m_pfadd(_m_pfadd(_m_pfmul(v301, v382), _m_pfmul(v299, v378)), _m_pfmul(v300, v386));
      v305 = _m_pfadd(_m_pfmul(0, v303), _m_pfadd(_m_pfmul(v384, v300), _m_pfadd(v302, _m_pfmul(v376, v299))));
      v306 = result[4];
      v307 = _m_pfadd(_m_pfmul(v303, v388), v304);
      v308 = result[5];
      result[2].m64_u64 = (unsigned __int64)v305;
      result[3].m64_u64 = (unsigned __int64)v307;
      v309 = _m_punpckhdq(v304, v306);
      v310 = _m_punpckhdq(v307, v308);
      v311 = _m_punpckldq(v306, v306);
      v312 = _m_punpckldq(v308, v308);
      v313 = _m_punpckhdq(v309, v309);
      v314 = _m_pfmul(v380, v313);
      v315 = _m_punpckhdq(v310, v310);
      v316 = _m_pfadd(_m_pfadd(_m_pfmul(v313, v382), _m_pfmul(v311, v378)), _m_pfmul(v312, v386));
      v317 = _m_pfadd(_m_pfmul(0, v315), _m_pfadd(_m_pfmul(v384, v312), _m_pfadd(v314, _m_pfmul(v376, v311))));
      v318 = result[6];
      v319 = _m_pfadd(_m_pfmul(v315, v388), v316);
      v320 = result[7];
      result[4].m64_u64 = (unsigned __int64)v317;
      result[5].m64_u64 = (unsigned __int64)v319;
      v321 = _m_punpckhdq(v316, v318);
      v322 = _m_punpckhdq(v319, v320);
      v323 = _m_punpckldq(v318, v318);
      v324 = _m_punpckldq(v320, v320);
      v325 = _m_punpckhdq(v321, v321);
      v326 = _m_punpckhdq(v322, v322);
      result[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(0, v326),
                                              _m_pfadd(
                                                _m_pfmul(v384, v324),
                                                _m_pfadd(_m_pfmul(v380, v325), _m_pfmul(v376, v323))));
      result[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(v326, v388),
                                              _m_pfadd(
                                                _m_pfadd(_m_pfmul(v325, v382), _m_pfmul(v323, v378)),
                                                _m_pfmul(v324, v386)));
      v327 = _m_pfadd(_mm_cvtsi32_si64(result[7].m64_u32[0]), _mm_cvtsi32_si64(a5[1].m64_u32[0]));
      result[6].m64_u64 = (unsigned __int64)_m_pfadd(result[6], (__m64)a5->m64_u64);
      result[7].m64_i32[0] = _mm_cvtsi64_si32(v327);
    }
    else
    {
      v328 = result[1];
      v329 = _m_punpckhdq(v279, (__m64)result->m64_u64);
      v330 = _m_punpckhdq(v280, v328);
      v331 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
      v332 = _m_punpckldq(v328, v328);
      v333 = _m_punpckhdq(v329, v329);
      v334 = _m_pfmul(v380, v333);
      v335 = _m_punpckhdq(v330, v330);
      v336 = _m_pfadd(_m_pfadd(_m_pfmul(v333, v382), _m_pfmul(v331, v378)), _m_pfmul(v332, v386));
      v337 = _m_pfadd(_m_pfmul(0, v335), _m_pfadd(_m_pfmul(v384, v332), _m_pfadd(v334, _m_pfmul(v376, v331))));
      v338 = result[2];
      v339 = _m_pfadd(_m_pfmul(v335, v388), v336);
      v340 = result[3];
      result->m64_u64 = (unsigned __int64)v337;
      result[1].m64_u64 = (unsigned __int64)v339;
      v341 = _m_punpckhdq(v336, v338);
      v342 = _m_punpckhdq(v339, v340);
      v343 = _m_punpckldq(v338, v338);
      v344 = _m_punpckldq(v340, v340);
      v345 = _m_punpckhdq(v341, v341);
      v346 = _m_pfmul(v380, v345);
      v347 = _m_punpckhdq(v342, v342);
      v348 = _m_pfadd(_m_pfadd(_m_pfmul(v345, v382), _m_pfmul(v343, v378)), _m_pfmul(v344, v386));
      v349 = _m_pfadd(_m_pfmul(0, v347), _m_pfadd(_m_pfmul(v384, v344), _m_pfadd(v346, _m_pfmul(v376, v343))));
      v350 = result[4];
      v351 = _m_pfadd(_m_pfmul(v347, v388), v348);
      v352 = result[5];
      result[2].m64_u64 = (unsigned __int64)v349;
      result[3].m64_u64 = (unsigned __int64)v351;
      v353 = _m_punpckhdq(v348, v350);
      v354 = _m_punpckhdq(v351, v352);
      v355 = _m_punpckldq(v350, v350);
      v356 = _m_punpckldq(v352, v352);
      v357 = _m_punpckhdq(v353, v353);
      v358 = _m_pfmul(v380, v357);
      v359 = _m_punpckhdq(v354, v354);
      v360 = _m_pfadd(_m_pfadd(_m_pfmul(v357, v382), _m_pfmul(v355, v378)), _m_pfmul(v356, v386));
      v361 = _m_pfadd(_m_pfmul(0, v359), _m_pfadd(_m_pfmul(v384, v356), _m_pfadd(v358, _m_pfmul(v376, v355))));
      v362 = result[6];
      v363 = _m_pfadd(_m_pfmul(v359, v388), v360);
      v364 = result[7];
      result[4].m64_u64 = (unsigned __int64)v361;
      result[5].m64_u64 = (unsigned __int64)v363;
      v365 = _m_punpckhdq(v360, v362);
      v366 = _m_punpckhdq(v363, v364);
      v367 = _m_punpckldq(v362, v362);
      v368 = _m_punpckldq(v364, v364);
      v369 = _m_punpckhdq(v365, v365);
      v370 = _m_punpckhdq(v366, v366);
      result[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(0, v370),
                                              _m_pfadd(
                                                _m_pfmul(v384, v368),
                                                _m_pfadd(_m_pfmul(v380, v369), _m_pfmul(v376, v367))));
      result[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(v370, v388),
                                              _m_pfadd(
                                                _m_pfadd(_m_pfmul(v369, v382), _m_pfmul(v367, v378)),
                                                _m_pfmul(v368, v386)));
    }
  }
  if ( a7 )
  {
    v371 = _m_pfadd(_mm_cvtsi32_si64(result[7].m64_u32[0]), _mm_cvtsi32_si64(a7[1].m64_u32[0]));
    result[6].m64_u64 = (unsigned __int64)_m_pfadd(result[6], (__m64)a7->m64_u64);
    result[7].m64_i32[0] = _mm_cvtsi64_si32(v371);
  }
  _m_femms();
  return result;
}
