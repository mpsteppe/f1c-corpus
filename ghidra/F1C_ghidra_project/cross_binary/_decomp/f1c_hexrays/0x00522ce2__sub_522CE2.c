// f1c  0x00522ce2  size=4504
__m64 *__stdcall sub_522CE2(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4, __m64 *a5, __m64 *a6, __m64 *a7)
{
  __m64 *result; // eax
  __m64 m64_u64; // mm3
  __m64 v9; // mm0
  __m64 v10; // mm7
  __m64 v11; // mm2
  __m64 v12; // mm4
  __m64 v13; // mm3
  __m64 v14; // mm1
  __m64 v15; // mm5
  __m64 v16; // mm7
  __m64 v17; // mm6
  __m64 v18; // mm2
  __m64 v19; // mm1
  __m64 v20; // mm6
  __m64 v21; // mm7
  __m64 v22; // mm3
  __m64 v23; // mm2
  __m64 v24; // mm3
  __m64 v25; // mm5
  __m64 v26; // mm6
  __m64 v27; // mm3
  __m64 v28; // mm4
  __m64 v29; // mm1
  __m64 v30; // mm2
  __m64 v31; // mm2
  __m64 v32; // mm1
  __m64 v33; // mm2
  __m64 v34; // mm3
  __m64 v35; // mm0
  __m64 v36; // mm1
  __m64 v37; // mm2
  __m64 v38; // mm5
  __m64 v39; // mm3
  __m64 v40; // mm2
  __m64 v41; // mm7
  __m64 v42; // mm0
  __m64 v43; // mm3
  __m64 v44; // mm1
  __m64 v45; // mm2
  __m64 v46; // mm3
  __m64 v47; // mm0
  __m64 v48; // mm1
  __m64 v49; // mm2
  __m64 v50; // mm5
  __m64 v51; // mm3
  __m64 v52; // mm2
  __m64 v53; // mm7
  __m64 v54; // mm0
  __m64 v55; // mm3
  __m64 v56; // mm1
  __m64 v57; // mm2
  __m64 v58; // mm3
  __m64 v59; // mm0
  __m64 v60; // mm1
  __m64 v61; // mm2
  __m64 v62; // mm5
  __m64 v63; // mm3
  __m64 v64; // mm2
  __m64 v65; // mm7
  __m64 v66; // mm0
  __m64 v67; // mm3
  __m64 v68; // mm1
  __m64 v69; // mm2
  __m64 v70; // mm3
  __m64 v71; // mm0
  __m64 v72; // mm1
  __m64 v73; // mm2
  __m64 v74; // mm5
  __m64 v75; // mm3
  __m64 v76; // mm7
  __m64 v77; // mm2
  __m64 v78; // mm3
  __m64 v79; // mm1
  __m64 v80; // mm2
  __m64 v81; // mm3
  __m64 v82; // mm0
  __m64 v83; // mm1
  __m64 v84; // mm2
  __m64 v85; // mm5
  __m64 v86; // mm3
  __m64 v87; // mm2
  __m64 v88; // mm7
  __m64 v89; // mm0
  __m64 v90; // mm3
  __m64 v91; // mm1
  __m64 v92; // mm2
  __m64 v93; // mm3
  __m64 v94; // mm0
  __m64 v95; // mm1
  __m64 v96; // mm2
  __m64 v97; // mm5
  __m64 v98; // mm3
  __m64 v99; // mm2
  __m64 v100; // mm7
  __m64 v101; // mm0
  __m64 v102; // mm3
  __m64 v103; // mm1
  __m64 v104; // mm2
  __m64 v105; // mm3
  __m64 v106; // mm0
  __m64 v107; // mm1
  __m64 v108; // mm2
  __m64 v109; // mm5
  __m64 v110; // mm3
  __m64 v111; // mm2
  __m64 v112; // mm7
  __m64 v113; // mm0
  __m64 v114; // mm3
  __m64 v115; // mm1
  __m64 v116; // mm2
  __m64 v117; // mm3
  __m64 v118; // mm0
  __m64 v119; // mm1
  __m64 v120; // mm2
  __m64 v121; // mm5
  __m64 v122; // mm3
  __m64 v123; // mm7
  __m64 v124; // mm2
  __m64 v125; // mm3
  __m64 v126; // mm1
  __m64 v127; // mm2
  __m64 v128; // mm3
  __m64 v129; // mm0
  __m64 v130; // mm1
  __m64 v131; // mm2
  __m64 v132; // mm5
  __m64 v133; // mm3
  __m64 v134; // mm2
  __m64 v135; // mm7
  __m64 v136; // mm0
  __m64 v137; // mm3
  __m64 v138; // mm1
  __m64 v139; // mm2
  __m64 v140; // mm3
  __m64 v141; // mm0
  __m64 v142; // mm1
  __m64 v143; // mm2
  __m64 v144; // mm5
  __m64 v145; // mm3
  __m64 v146; // mm2
  __m64 v147; // mm7
  __m64 v148; // mm0
  __m64 v149; // mm3
  __m64 v150; // mm1
  __m64 v151; // mm2
  __m64 v152; // mm3
  __m64 v153; // mm0
  __m64 v154; // mm1
  __m64 v155; // mm2
  __m64 v156; // mm5
  __m64 v157; // mm3
  __m64 v158; // mm2
  __m64 v159; // mm7
  __m64 v160; // mm0
  __m64 v161; // mm3
  __m64 v162; // mm1
  __m64 v163; // mm2
  __m64 v164; // mm3
  __m64 v165; // mm0
  __m64 v166; // mm1
  __m64 v167; // mm2
  __m64 v168; // mm3
  __m64 v169; // mm2
  __m64 v170; // mm3
  __m64 v171; // mm2
  __m64 v172; // mm1
  __m64 v173; // mm2
  __m64 v174; // mm3
  __m64 v175; // mm0
  __m64 v176; // mm1
  __m64 v177; // mm2
  __m64 v178; // mm5
  __m64 v179; // mm3
  __m64 v180; // mm2
  __m64 v181; // mm7
  __m64 v182; // mm0
  __m64 v183; // mm3
  __m64 v184; // mm1
  __m64 v185; // mm2
  __m64 v186; // mm3
  __m64 v187; // mm0
  __m64 v188; // mm1
  __m64 v189; // mm2
  __m64 v190; // mm5
  __m64 v191; // mm3
  __m64 v192; // mm2
  __m64 v193; // mm7
  __m64 v194; // mm0
  __m64 v195; // mm3
  __m64 v196; // mm1
  __m64 v197; // mm2
  __m64 v198; // mm3
  __m64 v199; // mm0
  __m64 v200; // mm1
  __m64 v201; // mm2
  __m64 v202; // mm5
  __m64 v203; // mm3
  __m64 v204; // mm2
  __m64 v205; // mm7
  __m64 v206; // mm0
  __m64 v207; // mm3
  __m64 v208; // mm1
  __m64 v209; // mm2
  __m64 v210; // mm3
  __m64 v211; // mm0
  __m64 v212; // mm1
  __m64 v213; // mm2
  __m64 v214; // mm5
  __m64 v215; // mm3
  __m64 v216; // mm7
  __m64 v217; // mm2
  __m64 v218; // mm3
  __m64 v219; // mm1
  __m64 v220; // mm2
  __m64 v221; // mm3
  __m64 v222; // mm0
  __m64 v223; // mm1
  __m64 v224; // mm2
  __m64 v225; // mm5
  __m64 v226; // mm3
  __m64 v227; // mm2
  __m64 v228; // mm7
  __m64 v229; // mm0
  __m64 v230; // mm3
  __m64 v231; // mm1
  __m64 v232; // mm2
  __m64 v233; // mm3
  __m64 v234; // mm0
  __m64 v235; // mm1
  __m64 v236; // mm2
  __m64 v237; // mm5
  __m64 v238; // mm3
  __m64 v239; // mm2
  __m64 v240; // mm7
  __m64 v241; // mm0
  __m64 v242; // mm3
  __m64 v243; // mm1
  __m64 v244; // mm2
  __m64 v245; // mm3
  __m64 v246; // mm0
  __m64 v247; // mm1
  __m64 v248; // mm2
  __m64 v249; // mm5
  __m64 v250; // mm3
  __m64 v251; // mm2
  __m64 v252; // mm7
  __m64 v253; // mm0
  __m64 v254; // mm3
  __m64 v255; // mm1
  __m64 v256; // mm2
  __m64 v257; // mm3
  __m64 v258; // mm0
  __m64 v259; // mm1
  __m64 v260; // mm2
  __m64 v261; // mm3
  __m64 v262; // mm4
  __m64 v263; // mm5
  __m64 v264; // mm1
  __m64 v265; // mm2
  __m64 v266; // mm3
  __m64 v267; // mm0
  __m64 v268; // mm7
  __m64 v269; // mm2
  __m64 v270; // mm4
  __m64 v271; // mm3
  __m64 v272; // mm1
  __m64 v273; // mm5
  __m64 v274; // mm7
  __m64 v275; // mm6
  __m64 v276; // mm2
  __m64 v277; // mm1
  __m64 v278; // mm6
  __m64 v279; // mm7
  __m64 v280; // mm3
  __m64 v281; // mm2
  __m64 v282; // mm3
  __m64 v283; // mm5
  __m64 v284; // mm2
  __m64 v285; // mm6
  __m64 v286; // mm2
  __m64 v287; // mm3
  __m64 v288; // mm1
  __m64 v289; // mm1
  __m64 v290; // mm2
  __m64 v291; // mm3
  __m64 v292; // mm0
  __m64 v293; // mm1
  __m64 v294; // mm2
  __m64 v295; // mm5
  __m64 v296; // mm3
  __m64 v297; // mm2
  __m64 v298; // mm7
  __m64 v299; // mm0
  __m64 v300; // mm3
  __m64 v301; // mm1
  __m64 v302; // mm2
  __m64 v303; // mm3
  __m64 v304; // mm0
  __m64 v305; // mm1
  __m64 v306; // mm2
  __m64 v307; // mm5
  __m64 v308; // mm3
  __m64 v309; // mm2
  __m64 v310; // mm7
  __m64 v311; // mm0
  __m64 v312; // mm3
  __m64 v313; // mm1
  __m64 v314; // mm2
  __m64 v315; // mm3
  __m64 v316; // mm0
  __m64 v317; // mm1
  __m64 v318; // mm2
  __m64 v319; // mm5
  __m64 v320; // mm3
  __m64 v321; // mm2
  __m64 v322; // mm7
  __m64 v323; // mm0
  __m64 v324; // mm3
  __m64 v325; // mm1
  __m64 v326; // mm2
  __m64 v327; // mm3
  __m64 v328; // mm0
  __m64 v329; // mm1
  __m64 v330; // mm2
  __m64 v331; // mm3
  __m64 v332; // mm1
  __m64 v333; // mm1
  __m64 v334; // mm2
  __m64 v335; // mm3
  __m64 v336; // mm0
  __m64 v337; // mm1
  __m64 v338; // mm2
  __m64 v339; // mm5
  __m64 v340; // mm3
  __m64 v341; // mm2
  __m64 v342; // mm7
  __m64 v343; // mm0
  __m64 v344; // mm3
  __m64 v345; // mm1
  __m64 v346; // mm2
  __m64 v347; // mm3
  __m64 v348; // mm0
  __m64 v349; // mm1
  __m64 v350; // mm2
  __m64 v351; // mm5
  __m64 v352; // mm3
  __m64 v353; // mm2
  __m64 v354; // mm7
  __m64 v355; // mm0
  __m64 v356; // mm3
  __m64 v357; // mm1
  __m64 v358; // mm2
  __m64 v359; // mm3
  __m64 v360; // mm0
  __m64 v361; // mm1
  __m64 v362; // mm2
  __m64 v363; // mm5
  __m64 v364; // mm3
  __m64 v365; // mm2
  __m64 v366; // mm7
  __m64 v367; // mm0
  __m64 v368; // mm3
  __m64 v369; // mm1
  __m64 v370; // mm2
  __m64 v371; // mm3
  __m64 v372; // mm0
  __m64 v373; // mm1
  __m64 v374; // mm2
  __m64 v375; // mm3
  __m64 v376; // mm1
  __m64 v377; // [esp+0h] [ebp-C0h]
  __m64 v378; // [esp+10h] [ebp-B0h]
  __m64 v379; // [esp+28h] [ebp-98h]
  __m64 v380; // [esp+40h] [ebp-80h]
  __m64 v381; // [esp+40h] [ebp-80h]
  __m64 v382; // [esp+48h] [ebp-78h]
  __m64 v383; // [esp+48h] [ebp-78h]
  __m64 v384; // [esp+50h] [ebp-70h]
  __m64 v385; // [esp+50h] [ebp-70h]
  __m64 v386; // [esp+58h] [ebp-68h]
  __m64 v387; // [esp+58h] [ebp-68h]
  __m64 v388; // [esp+60h] [ebp-60h]
  __m64 v389; // [esp+60h] [ebp-60h]
  __m64 v390; // [esp+68h] [ebp-58h]
  __m64 v391; // [esp+68h] [ebp-58h]
  __m64 v392; // [esp+78h] [ebp-48h]
  __m64 v393; // [esp+78h] [ebp-48h]
  __m64 v394; // [esp+80h] [ebp-40h]
  __m64 v395; // [esp+88h] [ebp-38h]
  __m64 v396; // [esp+90h] [ebp-30h]
  __m64 v397; // [esp+98h] [ebp-28h]
  __m64 v398; // [esp+A0h] [ebp-20h]
  __m64 v399; // [esp+A8h] [ebp-18h]
  __m64 v400; // [esp+B0h] [ebp-10h]
  __m64 v401; // [esp+B8h] [ebp-8h]

  result = a1;
  if ( a4 )
  {
    if ( a3 )
    {
      v377 = _m_punpckldq((__m64)a4->m64_u64, 0);
      v378 = _m_punpckhdq(0, (__m64)a4->m64_u64);
      v379 = _mm_cvtsi32_si64(a4[1].m64_u32[0]);
      m64_u64 = (__m64)a3->m64_u64;
      v9 = _m_pfadd(m64_u64, m64_u64);
      v10 = a3[1];
      v11 = _m_punpckhdq(m64_u64, m64_u64);
      v12 = _m_punpckhdq(v10, v10);
      v13 = _m_pfmul((__m64)a3->m64_u64, v9);
      v14 = _m_punpckldq(_m_pfadd(v10, v10), v9);
      v15 = _m_pfmul(v9, v12);
      v16 = _m_pfmul(_m_punpckldq(v10, v10), v14);
      v17 = _m_pfmul(v14, v12);
      v18 = _m_pfmul(v14, v11);
      v19 = _m_punpckhdq(v18, v16);
      v20 = _m_punpckhdq(_m_punpckldq(v17, v17), v15);
      v21 = _m_pfsubr(_m_pfadd(_m_punpckldq(v16, v16), v13), (__m64)0x3F8000003F800000LL);
      v390 = _m_punpckldq(_m_pfsubr(_m_pfacc(v13, v13), (__m64)0x3F8000003F800000LL), 0);
      v22 = v18;
      v23 = _m_pfadd(v18, v15);
      v24 = _m_pfsub(v22, v15);
      v25 = _m_pfsub(v19, v20);
      v26 = _m_pfadd(v19, v20);
      v386 = _m_punpckldq(v23, 0);
      v382 = _m_punpckhdq(v25, 0);
      v384 = _m_punpckldq(v25, v21);
      v380 = _m_punpckhdq(v21, _m_punpckldq(v26, v26));
      v388 = _m_punpckldq(_m_punpckhdq(v26, v26), v24);
      v392 = _m_punpckldq(0, (__m64)1065353216LL);
      if ( a2 )
      {
        v394 = _m_punpckldq(v380, v384);
        v396 = _m_punpckhdq(v380, v384);
        v399 = _m_punpckldq(v390, v392);
        v401 = _m_punpckhdq(v390, v392);
        v398 = _m_punpckldq(v382, v386);
        v400 = _m_punpckhdq(v382, v386);
        v397 = _m_punpckhdq(v388, 0);
        v395 = _m_punpckldq(v388, 0);
        result = a1;
        v27 = (__m64)a2->m64_u64;
        v28 = _mm_cvtsi32_si64(a2[1].m64_u32[0]);
        v29 = _mm_cvtsi32_si64(0x3F800000u);
        v30 = _m_punpckldq(_m_punpckhdq(v29, v29), v29);
        a1->m64_u64 = (unsigned __int64)v29;
        a1[1].m64_u64 = 0;
        a1[2].m64_u64 = (unsigned __int64)v30;
        a1[3].m64_u64 = 0;
        a1[4].m64_u64 = 0;
        a1[5].m64_u64 = (unsigned __int64)v29;
        v31 = _m_pfsub(v30, v28);
        a1[7].m64_u64 = (unsigned __int64)v31;
        a1[6].m64_u64 = (unsigned __int64)_m_pfsub(0, v27);
        v32 = a1[1];
        v33 = _m_punpckhdq(v31, (__m64)a1->m64_u64);
        v34 = _m_punpckhdq(v27, v32);
        v35 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v36 = _m_punpckldq(v32, v32);
        v37 = _m_punpckhdq(v33, v33);
        v38 = _m_pfmul(v396, v37);
        v39 = _m_punpckhdq(v34, v34);
        v40 = _m_pfadd(_m_pfadd(_m_pfmul(v37, v397), _m_pfmul(v35, v395)), _m_pfmul(v36, v399));
        v41 = _m_pfadd(_m_pfmul(v400, v39), _m_pfadd(_m_pfmul(v398, v36), _m_pfadd(v38, _m_pfmul(v394, v35))));
        v42 = a1[2];
        v43 = _m_pfadd(_m_pfmul(v39, v401), v40);
        v44 = a1[3];
        a1->m64_u64 = (unsigned __int64)v41;
        a1[1].m64_u64 = (unsigned __int64)v43;
        v45 = _m_punpckhdq(v40, v42);
        v46 = _m_punpckhdq(v43, v44);
        v47 = _m_punpckldq(v42, v42);
        v48 = _m_punpckldq(v44, v44);
        v49 = _m_punpckhdq(v45, v45);
        v50 = _m_pfmul(v396, v49);
        v51 = _m_punpckhdq(v46, v46);
        v52 = _m_pfadd(_m_pfadd(_m_pfmul(v49, v397), _m_pfmul(v47, v395)), _m_pfmul(v48, v399));
        v53 = _m_pfadd(_m_pfmul(v400, v51), _m_pfadd(_m_pfmul(v398, v48), _m_pfadd(v50, _m_pfmul(v394, v47))));
        v54 = a1[4];
        v55 = _m_pfadd(_m_pfmul(v51, v401), v52);
        v56 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v53;
        a1[3].m64_u64 = (unsigned __int64)v55;
        v57 = _m_punpckhdq(v52, v54);
        v58 = _m_punpckhdq(v55, v56);
        v59 = _m_punpckldq(v54, v54);
        v60 = _m_punpckldq(v56, v56);
        v61 = _m_punpckhdq(v57, v57);
        v62 = _m_pfmul(v396, v61);
        v63 = _m_punpckhdq(v58, v58);
        v64 = _m_pfadd(_m_pfadd(_m_pfmul(v61, v397), _m_pfmul(v59, v395)), _m_pfmul(v60, v399));
        v65 = _m_pfadd(_m_pfmul(v400, v63), _m_pfadd(_m_pfmul(v398, v60), _m_pfadd(v62, _m_pfmul(v394, v59))));
        v66 = a1[6];
        v67 = _m_pfadd(_m_pfmul(v63, v401), v64);
        v68 = a1[7];
        a1[4].m64_u64 = (unsigned __int64)v65;
        a1[5].m64_u64 = (unsigned __int64)v67;
        v69 = _m_punpckhdq(v64, v66);
        v70 = _m_punpckhdq(v67, v68);
        v71 = _m_punpckldq(v66, v66);
        v72 = _m_punpckldq(v68, v68);
        v73 = _m_punpckhdq(v69, v69);
        v74 = _m_pfmul(v396, v73);
        v75 = _m_punpckhdq(v70, v70);
        v76 = _m_pfmul(v400, v75);
        v77 = _m_pfadd(_m_pfadd(_m_pfmul(v73, v397), _m_pfmul(v71, v395)), _m_pfmul(v72, v399));
        v78 = _m_pfadd(_m_pfmul(v75, v401), v77);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            v76,
                                            _m_pfadd(_m_pfmul(v398, v72), _m_pfadd(v74, _m_pfmul(v394, v71))));
        a1[7].m64_u64 = (unsigned __int64)v78;
        v79 = a1[1];
        v80 = _m_punpckhdq(v77, (__m64)a1->m64_u64);
        v81 = _m_punpckhdq(v78, v79);
        v82 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v83 = _m_punpckldq(v79, v79);
        v84 = _m_punpckhdq(v80, v80);
        v85 = _m_pfmul(v378, v84);
        v86 = _m_punpckhdq(v81, v81);
        v87 = _m_pfadd(_m_pfadd(_m_pfmul(v84, 0), _m_pfmul(v82, 0)), _m_pfmul(v83, v379));
        v88 = _m_pfadd(_m_pfmul(0, v86), _m_pfadd(_m_pfmul(0, v83), _m_pfadd(v85, _m_pfmul(v377, v82))));
        v89 = a1[2];
        v90 = _m_pfadd(_m_pfmul(v86, (__m64)0x3F80000000000000LL), v87);
        v91 = a1[3];
        a1->m64_u64 = (unsigned __int64)v88;
        a1[1].m64_u64 = (unsigned __int64)v90;
        v92 = _m_punpckhdq(v87, v89);
        v93 = _m_punpckhdq(v90, v91);
        v94 = _m_punpckldq(v89, v89);
        v95 = _m_punpckldq(v91, v91);
        v96 = _m_punpckhdq(v92, v92);
        v97 = _m_pfmul(v378, v96);
        v98 = _m_punpckhdq(v93, v93);
        v99 = _m_pfadd(_m_pfadd(_m_pfmul(v96, 0), _m_pfmul(v94, 0)), _m_pfmul(v95, v379));
        v100 = _m_pfadd(_m_pfmul(0, v98), _m_pfadd(_m_pfmul(0, v95), _m_pfadd(v97, _m_pfmul(v377, v94))));
        v101 = a1[4];
        v102 = _m_pfadd(_m_pfmul(v98, (__m64)0x3F80000000000000LL), v99);
        v103 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v100;
        a1[3].m64_u64 = (unsigned __int64)v102;
        v104 = _m_punpckhdq(v99, v101);
        v105 = _m_punpckhdq(v102, v103);
        v106 = _m_punpckldq(v101, v101);
        v107 = _m_punpckldq(v103, v103);
        v108 = _m_punpckhdq(v104, v104);
        v109 = _m_pfmul(v378, v108);
        v110 = _m_punpckhdq(v105, v105);
        v111 = _m_pfadd(_m_pfadd(_m_pfmul(v108, 0), _m_pfmul(v106, 0)), _m_pfmul(v107, v379));
        v112 = _m_pfadd(_m_pfmul(0, v110), _m_pfadd(_m_pfmul(0, v107), _m_pfadd(v109, _m_pfmul(v377, v106))));
        v113 = a1[6];
        v114 = _m_pfadd(_m_pfmul(v110, (__m64)0x3F80000000000000LL), v111);
        v115 = a1[7];
        a1[4].m64_u64 = (unsigned __int64)v112;
        a1[5].m64_u64 = (unsigned __int64)v114;
        v116 = _m_punpckhdq(v111, v113);
        v117 = _m_punpckhdq(v114, v115);
        v118 = _m_punpckldq(v113, v113);
        v119 = _m_punpckldq(v115, v115);
        v120 = _m_punpckhdq(v116, v116);
        v121 = _m_pfmul(v378, v120);
        v122 = _m_punpckhdq(v117, v117);
        v123 = _m_pfmul(0, v122);
        v124 = _m_pfadd(_m_pfadd(_m_pfmul(v120, 0), _m_pfmul(v118, 0)), _m_pfmul(v119, v379));
        v125 = _m_pfadd(_m_pfmul(v122, (__m64)0x3F80000000000000LL), v124);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            v123,
                                            _m_pfadd(_m_pfmul(0, v119), _m_pfadd(v121, _m_pfmul(v377, v118))));
        a1[7].m64_u64 = (unsigned __int64)v125;
        v126 = a1[1];
        v127 = _m_punpckhdq(v124, (__m64)a1->m64_u64);
        v128 = _m_punpckhdq(v125, v126);
        v129 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v130 = _m_punpckldq(v126, v126);
        v131 = _m_punpckhdq(v127, v127);
        v132 = _m_pfmul(v384, v131);
        v133 = _m_punpckhdq(v128, v128);
        v134 = _m_pfadd(_m_pfadd(_m_pfmul(v131, v386), _m_pfmul(v129, v382)), _m_pfmul(v130, v390));
        v135 = _m_pfadd(_m_pfmul(0, v133), _m_pfadd(_m_pfmul(v388, v130), _m_pfadd(v132, _m_pfmul(v380, v129))));
        v136 = a1[2];
        v137 = _m_pfadd(_m_pfmul(v133, v392), v134);
        v138 = a1[3];
        a1->m64_u64 = (unsigned __int64)v135;
        a1[1].m64_u64 = (unsigned __int64)v137;
        v139 = _m_punpckhdq(v134, v136);
        v140 = _m_punpckhdq(v137, v138);
        v141 = _m_punpckldq(v136, v136);
        v142 = _m_punpckldq(v138, v138);
        v143 = _m_punpckhdq(v139, v139);
        v144 = _m_pfmul(v384, v143);
        v145 = _m_punpckhdq(v140, v140);
        v146 = _m_pfadd(_m_pfadd(_m_pfmul(v143, v386), _m_pfmul(v141, v382)), _m_pfmul(v142, v390));
        v147 = _m_pfadd(_m_pfmul(0, v145), _m_pfadd(_m_pfmul(v388, v142), _m_pfadd(v144, _m_pfmul(v380, v141))));
        v148 = a1[4];
        v149 = _m_pfadd(_m_pfmul(v145, v392), v146);
        v150 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v147;
        a1[3].m64_u64 = (unsigned __int64)v149;
        v151 = _m_punpckhdq(v146, v148);
        v152 = _m_punpckhdq(v149, v150);
        v153 = _m_punpckldq(v148, v148);
        v154 = _m_punpckldq(v150, v150);
        v155 = _m_punpckhdq(v151, v151);
        v156 = _m_pfmul(v384, v155);
        v157 = _m_punpckhdq(v152, v152);
        v158 = _m_pfadd(_m_pfadd(_m_pfmul(v155, v386), _m_pfmul(v153, v382)), _m_pfmul(v154, v390));
        v159 = _m_pfadd(_m_pfmul(0, v157), _m_pfadd(_m_pfmul(v388, v154), _m_pfadd(v156, _m_pfmul(v380, v153))));
        v160 = a1[6];
        v161 = _m_pfadd(_m_pfmul(v157, v392), v158);
        v162 = a1[7];
        a1[4].m64_u64 = (unsigned __int64)v159;
        a1[5].m64_u64 = (unsigned __int64)v161;
        v163 = _m_punpckhdq(v158, v160);
        v164 = _m_punpckhdq(v161, v162);
        v165 = _m_punpckldq(v160, v160);
        v166 = _m_punpckldq(v162, v162);
        v167 = _m_punpckhdq(v163, v163);
        v168 = _m_punpckhdq(v164, v164);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            _m_pfmul(0, v168),
                                            _m_pfadd(
                                              _m_pfmul(v388, v166),
                                              _m_pfadd(_m_pfmul(v384, v167), _m_pfmul(v380, v165))));
        a1[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                            _m_pfmul(v168, v392),
                                            _m_pfadd(
                                              _m_pfadd(_m_pfmul(v167, v386), _m_pfmul(v165, v382)),
                                              _m_pfmul(v166, v390)));
        v169 = _m_pfadd(_mm_cvtsi32_si64(a2[1].m64_u32[0]), _mm_cvtsi32_si64(a1[7].m64_u32[0]));
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd((__m64)a2->m64_u64, a1[6]);
        a1[7].m64_i32[0] = _mm_cvtsi64_si32(v169);
      }
      else
      {
        result = a1;
        a1->m64_u64 = (unsigned __int64)_m_punpckldq(v380, v384);
        a1[2].m64_u64 = (unsigned __int64)_m_punpckhdq(v380, v384);
        v170 = _m_punpckldq(v390, v392);
        a1[5].m64_u64 = (unsigned __int64)v170;
        a1[7].m64_u64 = (unsigned __int64)_m_punpckhdq(v390, v392);
        a1[4].m64_u64 = (unsigned __int64)_m_punpckldq(v382, v386);
        v171 = _m_punpckldq(v388, 0);
        a1[6].m64_u64 = (unsigned __int64)_m_punpckhdq(v382, v386);
        a1[3].m64_u64 = (unsigned __int64)_m_punpckhdq(v388, 0);
        a1[1].m64_u64 = (unsigned __int64)v171;
        v172 = a1[1];
        v173 = _m_punpckhdq(v171, (__m64)a1->m64_u64);
        v174 = _m_punpckhdq(v170, v172);
        v175 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v176 = _m_punpckldq(v172, v172);
        v177 = _m_punpckhdq(v173, v173);
        v178 = _m_pfmul(v378, v177);
        v179 = _m_punpckhdq(v174, v174);
        v180 = _m_pfadd(_m_pfadd(_m_pfmul(v177, 0), _m_pfmul(v175, 0)), _m_pfmul(v176, v379));
        v181 = _m_pfadd(_m_pfmul(0, v179), _m_pfadd(_m_pfmul(0, v176), _m_pfadd(v178, _m_pfmul(v377, v175))));
        v182 = a1[2];
        v183 = _m_pfadd(_m_pfmul(v179, (__m64)0x3F80000000000000LL), v180);
        v184 = a1[3];
        a1->m64_u64 = (unsigned __int64)v181;
        a1[1].m64_u64 = (unsigned __int64)v183;
        v185 = _m_punpckhdq(v180, v182);
        v186 = _m_punpckhdq(v183, v184);
        v187 = _m_punpckldq(v182, v182);
        v188 = _m_punpckldq(v184, v184);
        v189 = _m_punpckhdq(v185, v185);
        v190 = _m_pfmul(v378, v189);
        v191 = _m_punpckhdq(v186, v186);
        v192 = _m_pfadd(_m_pfadd(_m_pfmul(v189, 0), _m_pfmul(v187, 0)), _m_pfmul(v188, v379));
        v193 = _m_pfadd(_m_pfmul(0, v191), _m_pfadd(_m_pfmul(0, v188), _m_pfadd(v190, _m_pfmul(v377, v187))));
        v194 = a1[4];
        v195 = _m_pfadd(_m_pfmul(v191, (__m64)0x3F80000000000000LL), v192);
        v196 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v193;
        a1[3].m64_u64 = (unsigned __int64)v195;
        v197 = _m_punpckhdq(v192, v194);
        v198 = _m_punpckhdq(v195, v196);
        v199 = _m_punpckldq(v194, v194);
        v200 = _m_punpckldq(v196, v196);
        v201 = _m_punpckhdq(v197, v197);
        v202 = _m_pfmul(v378, v201);
        v203 = _m_punpckhdq(v198, v198);
        v204 = _m_pfadd(_m_pfadd(_m_pfmul(v201, 0), _m_pfmul(v199, 0)), _m_pfmul(v200, v379));
        v205 = _m_pfadd(_m_pfmul(0, v203), _m_pfadd(_m_pfmul(0, v200), _m_pfadd(v202, _m_pfmul(v377, v199))));
        v206 = a1[6];
        v207 = _m_pfadd(_m_pfmul(v203, (__m64)0x3F80000000000000LL), v204);
        v208 = a1[7];
        a1[4].m64_u64 = (unsigned __int64)v205;
        a1[5].m64_u64 = (unsigned __int64)v207;
        v209 = _m_punpckhdq(v204, v206);
        v210 = _m_punpckhdq(v207, v208);
        v211 = _m_punpckldq(v206, v206);
        v212 = _m_punpckldq(v208, v208);
        v213 = _m_punpckhdq(v209, v209);
        v214 = _m_pfmul(v378, v213);
        v215 = _m_punpckhdq(v210, v210);
        v216 = _m_pfmul(0, v215);
        v217 = _m_pfadd(_m_pfadd(_m_pfmul(v213, 0), _m_pfmul(v211, 0)), _m_pfmul(v212, v379));
        v218 = _m_pfadd(_m_pfmul(v215, (__m64)0x3F80000000000000LL), v217);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            v216,
                                            _m_pfadd(_m_pfmul(0, v212), _m_pfadd(v214, _m_pfmul(v377, v211))));
        a1[7].m64_u64 = (unsigned __int64)v218;
        v219 = a1[1];
        v220 = _m_punpckhdq(v217, (__m64)a1->m64_u64);
        v221 = _m_punpckhdq(v218, v219);
        v222 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v223 = _m_punpckldq(v219, v219);
        v224 = _m_punpckhdq(v220, v220);
        v225 = _m_pfmul(v384, v224);
        v226 = _m_punpckhdq(v221, v221);
        v227 = _m_pfadd(_m_pfadd(_m_pfmul(v224, v386), _m_pfmul(v222, v382)), _m_pfmul(v223, v390));
        v228 = _m_pfadd(_m_pfmul(0, v226), _m_pfadd(_m_pfmul(v388, v223), _m_pfadd(v225, _m_pfmul(v380, v222))));
        v229 = a1[2];
        v230 = _m_pfadd(_m_pfmul(v226, v392), v227);
        v231 = a1[3];
        a1->m64_u64 = (unsigned __int64)v228;
        a1[1].m64_u64 = (unsigned __int64)v230;
        v232 = _m_punpckhdq(v227, v229);
        v233 = _m_punpckhdq(v230, v231);
        v234 = _m_punpckldq(v229, v229);
        v235 = _m_punpckldq(v231, v231);
        v236 = _m_punpckhdq(v232, v232);
        v237 = _m_pfmul(v384, v236);
        v238 = _m_punpckhdq(v233, v233);
        v239 = _m_pfadd(_m_pfadd(_m_pfmul(v236, v386), _m_pfmul(v234, v382)), _m_pfmul(v235, v390));
        v240 = _m_pfadd(_m_pfmul(0, v238), _m_pfadd(_m_pfmul(v388, v235), _m_pfadd(v237, _m_pfmul(v380, v234))));
        v241 = a1[4];
        v242 = _m_pfadd(_m_pfmul(v238, v392), v239);
        v243 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v240;
        a1[3].m64_u64 = (unsigned __int64)v242;
        v244 = _m_punpckhdq(v239, v241);
        v245 = _m_punpckhdq(v242, v243);
        v246 = _m_punpckldq(v241, v241);
        v247 = _m_punpckldq(v243, v243);
        v248 = _m_punpckhdq(v244, v244);
        v249 = _m_pfmul(v384, v248);
        v250 = _m_punpckhdq(v245, v245);
        v251 = _m_pfadd(_m_pfadd(_m_pfmul(v248, v386), _m_pfmul(v246, v382)), _m_pfmul(v247, v390));
        v252 = _m_pfadd(_m_pfmul(0, v250), _m_pfadd(_m_pfmul(v388, v247), _m_pfadd(v249, _m_pfmul(v380, v246))));
        v253 = a1[6];
        v254 = _m_pfadd(_m_pfmul(v250, v392), v251);
        v255 = a1[7];
        a1[4].m64_u64 = (unsigned __int64)v252;
        a1[5].m64_u64 = (unsigned __int64)v254;
        v256 = _m_punpckhdq(v251, v253);
        v257 = _m_punpckhdq(v254, v255);
        v258 = _m_punpckldq(v253, v253);
        v259 = _m_punpckldq(v255, v255);
        v260 = _m_punpckhdq(v256, v256);
        v261 = _m_punpckhdq(v257, v257);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            _m_pfmul(0, v261),
                                            _m_pfadd(
                                              _m_pfmul(v388, v259),
                                              _m_pfadd(_m_pfmul(v384, v260), _m_pfmul(v380, v258))));
        a1[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                            _m_pfmul(v261, v392),
                                            _m_pfadd(
                                              _m_pfadd(_m_pfmul(v260, v386), _m_pfmul(v258, v382)),
                                              _m_pfmul(v259, v390)));
      }
    }
    else
    {
      v262 = _mm_cvtsi32_si64(a4[1].m64_u32[0]);
      v263 = _m_punpckhdq(0, (__m64)a4->m64_u64);
      a1->m64_u64 = (unsigned __int64)_m_punpckldq((__m64)a4->m64_u64, 0);
      a1[1].m64_u64 = 0;
      a1[2].m64_u64 = (unsigned __int64)v263;
      a1[3].m64_u64 = 0;
      a1[4].m64_u64 = 0;
      a1[5].m64_u64 = (unsigned __int64)v262;
      a1[6].m64_u64 = 0;
      a1[7].m64_u64 = 0x3F80000000000000LL;
    }
  }
  else
  {
    v264 = _mm_cvtsi32_si64(0x3F800000u);
    v265 = _m_punpckldq(_m_punpckhdq(v264, v264), v264);
    a1->m64_u64 = (unsigned __int64)v264;
    a1[1].m64_u64 = 0;
    a1[2].m64_u64 = (unsigned __int64)v265;
    a1[3].m64_u64 = 0;
    a1[4].m64_u64 = 0;
    a1[5].m64_u64 = (unsigned __int64)v264;
    a1[6].m64_u64 = 0;
    a1[7].m64_u64 = (unsigned __int64)v265;
  }
  if ( a6 )
  {
    v266 = (__m64)a6->m64_u64;
    v267 = _m_pfadd(v266, v266);
    v268 = a6[1];
    v269 = _m_punpckhdq(v266, v266);
    v270 = _m_punpckhdq(v268, v268);
    v271 = _m_pfmul((__m64)a6->m64_u64, v267);
    v272 = _m_punpckldq(_m_pfadd(v268, v268), v267);
    v273 = _m_pfmul(v267, v270);
    v274 = _m_pfmul(_m_punpckldq(v268, v268), v272);
    v275 = _m_pfmul(v272, v270);
    v276 = _m_pfmul(v272, v269);
    v277 = _m_punpckhdq(v276, v274);
    v278 = _m_punpckhdq(_m_punpckldq(v275, v275), v273);
    v279 = _m_pfsubr(_m_pfadd(_m_punpckldq(v274, v274), v271), (__m64)0x3F8000003F800000LL);
    v391 = _m_punpckldq(_m_pfsubr(_m_pfacc(v271, v271), (__m64)0x3F8000003F800000LL), 0);
    v280 = v276;
    v281 = _m_pfadd(v276, v273);
    v282 = _m_pfsub(v280, v273);
    v283 = _m_pfsub(v277, v278);
    v284 = _m_punpckldq(v281, 0);
    v285 = _m_pfadd(v277, v278);
    v387 = v284;
    v383 = _m_punpckhdq(v283, 0);
    v385 = _m_punpckldq(v283, v279);
    v381 = _m_punpckhdq(v279, _m_punpckldq(v285, v285));
    v389 = _m_punpckldq(_m_punpckhdq(v285, v285), v282);
    v393 = _m_punpckldq(0, (__m64)1065353216LL);
    if ( a5 )
    {
      v286 = (__m64)a5->m64_u64;
      v287 = _mm_cvtsi32_si64(a5[1].m64_u32[0]);
      v288 = _m_pfsub(_mm_cvtsi32_si64(result[7].m64_u32[0]), v287);
      result[6].m64_u64 = (unsigned __int64)_m_pfsub(result[6], (__m64)a5->m64_u64);
      result[7].m64_i32[0] = _mm_cvtsi64_si32(v288);
      v289 = result[1];
      v290 = _m_punpckhdq(v286, (__m64)result->m64_u64);
      v291 = _m_punpckhdq(v287, v289);
      v292 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
      v293 = _m_punpckldq(v289, v289);
      v294 = _m_punpckhdq(v290, v290);
      v295 = _m_pfmul(v385, v294);
      v296 = _m_punpckhdq(v291, v291);
      v297 = _m_pfadd(_m_pfadd(_m_pfmul(v294, v387), _m_pfmul(v292, v383)), _m_pfmul(v293, v391));
      v298 = _m_pfadd(_m_pfmul(0, v296), _m_pfadd(_m_pfmul(v389, v293), _m_pfadd(v295, _m_pfmul(v381, v292))));
      v299 = result[2];
      v300 = _m_pfadd(_m_pfmul(v296, v393), v297);
      v301 = result[3];
      result->m64_u64 = (unsigned __int64)v298;
      result[1].m64_u64 = (unsigned __int64)v300;
      v302 = _m_punpckhdq(v297, v299);
      v303 = _m_punpckhdq(v300, v301);
      v304 = _m_punpckldq(v299, v299);
      v305 = _m_punpckldq(v301, v301);
      v306 = _m_punpckhdq(v302, v302);
      v307 = _m_pfmul(v385, v306);
      v308 = _m_punpckhdq(v303, v303);
      v309 = _m_pfadd(_m_pfadd(_m_pfmul(v306, v387), _m_pfmul(v304, v383)), _m_pfmul(v305, v391));
      v310 = _m_pfadd(_m_pfmul(0, v308), _m_pfadd(_m_pfmul(v389, v305), _m_pfadd(v307, _m_pfmul(v381, v304))));
      v311 = result[4];
      v312 = _m_pfadd(_m_pfmul(v308, v393), v309);
      v313 = result[5];
      result[2].m64_u64 = (unsigned __int64)v310;
      result[3].m64_u64 = (unsigned __int64)v312;
      v314 = _m_punpckhdq(v309, v311);
      v315 = _m_punpckhdq(v312, v313);
      v316 = _m_punpckldq(v311, v311);
      v317 = _m_punpckldq(v313, v313);
      v318 = _m_punpckhdq(v314, v314);
      v319 = _m_pfmul(v385, v318);
      v320 = _m_punpckhdq(v315, v315);
      v321 = _m_pfadd(_m_pfadd(_m_pfmul(v318, v387), _m_pfmul(v316, v383)), _m_pfmul(v317, v391));
      v322 = _m_pfadd(_m_pfmul(0, v320), _m_pfadd(_m_pfmul(v389, v317), _m_pfadd(v319, _m_pfmul(v381, v316))));
      v323 = result[6];
      v324 = _m_pfadd(_m_pfmul(v320, v393), v321);
      v325 = result[7];
      result[4].m64_u64 = (unsigned __int64)v322;
      result[5].m64_u64 = (unsigned __int64)v324;
      v326 = _m_punpckhdq(v321, v323);
      v327 = _m_punpckhdq(v324, v325);
      v328 = _m_punpckldq(v323, v323);
      v329 = _m_punpckldq(v325, v325);
      v330 = _m_punpckhdq(v326, v326);
      v331 = _m_punpckhdq(v327, v327);
      result[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(0, v331),
                                              _m_pfadd(
                                                _m_pfmul(v389, v329),
                                                _m_pfadd(_m_pfmul(v385, v330), _m_pfmul(v381, v328))));
      result[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(v331, v393),
                                              _m_pfadd(
                                                _m_pfadd(_m_pfmul(v330, v387), _m_pfmul(v328, v383)),
                                                _m_pfmul(v329, v391)));
      v332 = _m_pfadd(_mm_cvtsi32_si64(result[7].m64_u32[0]), _mm_cvtsi32_si64(a5[1].m64_u32[0]));
      result[6].m64_u64 = (unsigned __int64)_m_pfadd(result[6], (__m64)a5->m64_u64);
      result[7].m64_i32[0] = _mm_cvtsi64_si32(v332);
    }
    else
    {
      v333 = result[1];
      v334 = _m_punpckhdq(v284, (__m64)result->m64_u64);
      v335 = _m_punpckhdq(v282, v333);
      v336 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
      v337 = _m_punpckldq(v333, v333);
      v338 = _m_punpckhdq(v334, v334);
      v339 = _m_pfmul(v385, v338);
      v340 = _m_punpckhdq(v335, v335);
      v341 = _m_pfadd(_m_pfadd(_m_pfmul(v338, v387), _m_pfmul(v336, v383)), _m_pfmul(v337, v391));
      v342 = _m_pfadd(_m_pfmul(0, v340), _m_pfadd(_m_pfmul(v389, v337), _m_pfadd(v339, _m_pfmul(v381, v336))));
      v343 = result[2];
      v344 = _m_pfadd(_m_pfmul(v340, v393), v341);
      v345 = result[3];
      result->m64_u64 = (unsigned __int64)v342;
      result[1].m64_u64 = (unsigned __int64)v344;
      v346 = _m_punpckhdq(v341, v343);
      v347 = _m_punpckhdq(v344, v345);
      v348 = _m_punpckldq(v343, v343);
      v349 = _m_punpckldq(v345, v345);
      v350 = _m_punpckhdq(v346, v346);
      v351 = _m_pfmul(v385, v350);
      v352 = _m_punpckhdq(v347, v347);
      v353 = _m_pfadd(_m_pfadd(_m_pfmul(v350, v387), _m_pfmul(v348, v383)), _m_pfmul(v349, v391));
      v354 = _m_pfadd(_m_pfmul(0, v352), _m_pfadd(_m_pfmul(v389, v349), _m_pfadd(v351, _m_pfmul(v381, v348))));
      v355 = result[4];
      v356 = _m_pfadd(_m_pfmul(v352, v393), v353);
      v357 = result[5];
      result[2].m64_u64 = (unsigned __int64)v354;
      result[3].m64_u64 = (unsigned __int64)v356;
      v358 = _m_punpckhdq(v353, v355);
      v359 = _m_punpckhdq(v356, v357);
      v360 = _m_punpckldq(v355, v355);
      v361 = _m_punpckldq(v357, v357);
      v362 = _m_punpckhdq(v358, v358);
      v363 = _m_pfmul(v385, v362);
      v364 = _m_punpckhdq(v359, v359);
      v365 = _m_pfadd(_m_pfadd(_m_pfmul(v362, v387), _m_pfmul(v360, v383)), _m_pfmul(v361, v391));
      v366 = _m_pfadd(_m_pfmul(0, v364), _m_pfadd(_m_pfmul(v389, v361), _m_pfadd(v363, _m_pfmul(v381, v360))));
      v367 = result[6];
      v368 = _m_pfadd(_m_pfmul(v364, v393), v365);
      v369 = result[7];
      result[4].m64_u64 = (unsigned __int64)v366;
      result[5].m64_u64 = (unsigned __int64)v368;
      v370 = _m_punpckhdq(v365, v367);
      v371 = _m_punpckhdq(v368, v369);
      v372 = _m_punpckldq(v367, v367);
      v373 = _m_punpckldq(v369, v369);
      v374 = _m_punpckhdq(v370, v370);
      v375 = _m_punpckhdq(v371, v371);
      result[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(0, v375),
                                              _m_pfadd(
                                                _m_pfmul(v389, v373),
                                                _m_pfadd(_m_pfmul(v385, v374), _m_pfmul(v381, v372))));
      result[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(v375, v393),
                                              _m_pfadd(
                                                _m_pfadd(_m_pfmul(v374, v387), _m_pfmul(v372, v383)),
                                                _m_pfmul(v373, v391)));
    }
  }
  if ( a7 )
  {
    v376 = _m_pfadd(_mm_cvtsi32_si64(result[7].m64_u32[0]), _mm_cvtsi32_si64(a7[1].m64_u32[0]));
    result[6].m64_u64 = (unsigned __int64)_m_pfadd(result[6], (__m64)a7->m64_u64);
    result[7].m64_i32[0] = _mm_cvtsi64_si32(v376);
  }
  _m_femms();
  return result;
}
