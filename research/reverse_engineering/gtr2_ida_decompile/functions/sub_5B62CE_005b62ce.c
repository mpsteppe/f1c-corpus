__m64 *__stdcall sub_5B62CE(__m64 *a1, __m64 *a2, __m64 *a3, __m64 *a4, __m64 *a5, __m64 *a6, __m64 *a7)
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
  __m64 v263; // mm2
  __m64 v264; // mm3
  __m64 v265; // mm5
  __m64 v266; // mm1
  __m64 v267; // mm4
  __m64 v268; // mm5
  __m64 v269; // mm1
  __m64 v270; // mm2
  __m64 v271; // mm3
  __m64 v272; // mm0
  __m64 v273; // mm7
  __m64 v274; // mm2
  __m64 v275; // mm4
  __m64 v276; // mm3
  __m64 v277; // mm1
  __m64 v278; // mm5
  __m64 v279; // mm7
  __m64 v280; // mm6
  __m64 v281; // mm2
  __m64 v282; // mm1
  __m64 v283; // mm6
  __m64 v284; // mm7
  __m64 v285; // mm3
  __m64 v286; // mm2
  __m64 v287; // mm3
  __m64 v288; // mm5
  __m64 v289; // mm2
  __m64 v290; // mm6
  __m64 v291; // mm2
  __m64 v292; // mm3
  __m64 v293; // mm1
  __m64 v294; // mm1
  __m64 v295; // mm2
  __m64 v296; // mm3
  __m64 v297; // mm0
  __m64 v298; // mm1
  __m64 v299; // mm2
  __m64 v300; // mm5
  __m64 v301; // mm3
  __m64 v302; // mm2
  __m64 v303; // mm7
  __m64 v304; // mm0
  __m64 v305; // mm3
  __m64 v306; // mm1
  __m64 v307; // mm2
  __m64 v308; // mm3
  __m64 v309; // mm0
  __m64 v310; // mm1
  __m64 v311; // mm2
  __m64 v312; // mm5
  __m64 v313; // mm3
  __m64 v314; // mm2
  __m64 v315; // mm7
  __m64 v316; // mm0
  __m64 v317; // mm3
  __m64 v318; // mm1
  __m64 v319; // mm2
  __m64 v320; // mm3
  __m64 v321; // mm0
  __m64 v322; // mm1
  __m64 v323; // mm2
  __m64 v324; // mm5
  __m64 v325; // mm3
  __m64 v326; // mm2
  __m64 v327; // mm7
  __m64 v328; // mm0
  __m64 v329; // mm3
  __m64 v330; // mm1
  __m64 v331; // mm2
  __m64 v332; // mm3
  __m64 v333; // mm0
  __m64 v334; // mm1
  __m64 v335; // mm2
  __m64 v336; // mm3
  __m64 v337; // mm1
  __m64 v338; // mm1
  __m64 v339; // mm2
  __m64 v340; // mm3
  __m64 v341; // mm0
  __m64 v342; // mm1
  __m64 v343; // mm2
  __m64 v344; // mm5
  __m64 v345; // mm3
  __m64 v346; // mm2
  __m64 v347; // mm7
  __m64 v348; // mm0
  __m64 v349; // mm3
  __m64 v350; // mm1
  __m64 v351; // mm2
  __m64 v352; // mm3
  __m64 v353; // mm0
  __m64 v354; // mm1
  __m64 v355; // mm2
  __m64 v356; // mm5
  __m64 v357; // mm3
  __m64 v358; // mm2
  __m64 v359; // mm7
  __m64 v360; // mm0
  __m64 v361; // mm3
  __m64 v362; // mm1
  __m64 v363; // mm2
  __m64 v364; // mm3
  __m64 v365; // mm0
  __m64 v366; // mm1
  __m64 v367; // mm2
  __m64 v368; // mm5
  __m64 v369; // mm3
  __m64 v370; // mm2
  __m64 v371; // mm7
  __m64 v372; // mm0
  __m64 v373; // mm3
  __m64 v374; // mm1
  __m64 v375; // mm2
  __m64 v376; // mm3
  __m64 v377; // mm0
  __m64 v378; // mm1
  __m64 v379; // mm2
  __m64 v380; // mm3
  __m64 v381; // mm1
  __m64 v382; // [esp+0h] [ebp-C0h]
  __m64 v383; // [esp+10h] [ebp-B0h]
  __m64 v384; // [esp+28h] [ebp-98h]
  __m64 v385; // [esp+40h] [ebp-80h]
  __m64 v386; // [esp+40h] [ebp-80h]
  __m64 v387; // [esp+48h] [ebp-78h]
  __m64 v388; // [esp+48h] [ebp-78h]
  __m64 v389; // [esp+50h] [ebp-70h]
  __m64 v390; // [esp+50h] [ebp-70h]
  __m64 v391; // [esp+58h] [ebp-68h]
  __m64 v392; // [esp+58h] [ebp-68h]
  __m64 v393; // [esp+60h] [ebp-60h]
  __m64 v394; // [esp+60h] [ebp-60h]
  __m64 v395; // [esp+68h] [ebp-58h]
  __m64 v396; // [esp+68h] [ebp-58h]
  __m64 v397; // [esp+78h] [ebp-48h]
  __m64 v398; // [esp+78h] [ebp-48h]
  __m64 v399; // [esp+80h] [ebp-40h]
  __m64 v400; // [esp+88h] [ebp-38h]
  __m64 v401; // [esp+90h] [ebp-30h]
  __m64 v402; // [esp+98h] [ebp-28h]
  __m64 v403; // [esp+A0h] [ebp-20h]
  __m64 v404; // [esp+A8h] [ebp-18h]
  __m64 v405; // [esp+B0h] [ebp-10h]
  __m64 v406; // [esp+B8h] [ebp-8h]

  result = a1;
  if ( a4 )
  {
    if ( a3 )
    {
      v382 = _m_punpckldq((__m64)a4->m64_u64, 0);
      v383 = _m_punpckhdq(0, (__m64)a4->m64_u64);
      v384 = _mm_cvtsi32_si64(a4[1].m64_u32[0]);
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
      v395 = _m_punpckldq(_m_pfsubr(_m_pfacc(v13, v13), (__m64)0x3F8000003F800000LL), 0);
      v22 = v18;
      v23 = _m_pfadd(v18, v15);
      v24 = _m_pfsub(v22, v15);
      v25 = _m_pfsub(v19, v20);
      v26 = _m_pfadd(v19, v20);
      v391 = _m_punpckldq(v23, 0);
      v387 = _m_punpckhdq(v25, 0);
      v389 = _m_punpckldq(v25, v21);
      v385 = _m_punpckhdq(v21, _m_punpckldq(v26, v26));
      v393 = _m_punpckldq(_m_punpckhdq(v26, v26), v24);
      v397 = _m_punpckldq(0, (__m64)1065353216LL);
      if ( a2 )
      {
        v399 = _m_punpckldq(v385, v389);
        v401 = _m_punpckhdq(v385, v389);
        v404 = _m_punpckldq(v395, v397);
        v406 = _m_punpckhdq(v395, v397);
        v403 = _m_punpckldq(v387, v391);
        v405 = _m_punpckhdq(v387, v391);
        v402 = _m_punpckhdq(v393, 0);
        v400 = _m_punpckldq(v393, 0);
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
        v38 = _m_pfmul(v401, v37);
        v39 = _m_punpckhdq(v34, v34);
        v40 = _m_pfadd(_m_pfadd(_m_pfmul(v37, v402), _m_pfmul(v35, v400)), _m_pfmul(v36, v404));
        v41 = _m_pfadd(_m_pfmul(v405, v39), _m_pfadd(_m_pfmul(v403, v36), _m_pfadd(v38, _m_pfmul(v399, v35))));
        v42 = a1[2];
        v43 = _m_pfadd(_m_pfmul(v39, v406), v40);
        v44 = a1[3];
        a1->m64_u64 = (unsigned __int64)v41;
        a1[1].m64_u64 = (unsigned __int64)v43;
        v45 = _m_punpckhdq(v40, v42);
        v46 = _m_punpckhdq(v43, v44);
        v47 = _m_punpckldq(v42, v42);
        v48 = _m_punpckldq(v44, v44);
        v49 = _m_punpckhdq(v45, v45);
        v50 = _m_pfmul(v401, v49);
        v51 = _m_punpckhdq(v46, v46);
        v52 = _m_pfadd(_m_pfadd(_m_pfmul(v49, v402), _m_pfmul(v47, v400)), _m_pfmul(v48, v404));
        v53 = _m_pfadd(_m_pfmul(v405, v51), _m_pfadd(_m_pfmul(v403, v48), _m_pfadd(v50, _m_pfmul(v399, v47))));
        v54 = a1[4];
        v55 = _m_pfadd(_m_pfmul(v51, v406), v52);
        v56 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v53;
        a1[3].m64_u64 = (unsigned __int64)v55;
        v57 = _m_punpckhdq(v52, v54);
        v58 = _m_punpckhdq(v55, v56);
        v59 = _m_punpckldq(v54, v54);
        v60 = _m_punpckldq(v56, v56);
        v61 = _m_punpckhdq(v57, v57);
        v62 = _m_pfmul(v401, v61);
        v63 = _m_punpckhdq(v58, v58);
        v64 = _m_pfadd(_m_pfadd(_m_pfmul(v61, v402), _m_pfmul(v59, v400)), _m_pfmul(v60, v404));
        v65 = _m_pfadd(_m_pfmul(v405, v63), _m_pfadd(_m_pfmul(v403, v60), _m_pfadd(v62, _m_pfmul(v399, v59))));
        v66 = a1[6];
        v67 = _m_pfadd(_m_pfmul(v63, v406), v64);
        v68 = a1[7];
        a1[4].m64_u64 = (unsigned __int64)v65;
        a1[5].m64_u64 = (unsigned __int64)v67;
        v69 = _m_punpckhdq(v64, v66);
        v70 = _m_punpckhdq(v67, v68);
        v71 = _m_punpckldq(v66, v66);
        v72 = _m_punpckldq(v68, v68);
        v73 = _m_punpckhdq(v69, v69);
        v74 = _m_pfmul(v401, v73);
        v75 = _m_punpckhdq(v70, v70);
        v76 = _m_pfmul(v405, v75);
        v77 = _m_pfadd(_m_pfadd(_m_pfmul(v73, v402), _m_pfmul(v71, v400)), _m_pfmul(v72, v404));
        v78 = _m_pfadd(_m_pfmul(v75, v406), v77);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            v76,
                                            _m_pfadd(_m_pfmul(v403, v72), _m_pfadd(v74, _m_pfmul(v399, v71))));
        a1[7].m64_u64 = (unsigned __int64)v78;
        v79 = a1[1];
        v80 = _m_punpckhdq(v77, (__m64)a1->m64_u64);
        v81 = _m_punpckhdq(v78, v79);
        v82 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v83 = _m_punpckldq(v79, v79);
        v84 = _m_punpckhdq(v80, v80);
        v85 = _m_pfmul(v383, v84);
        v86 = _m_punpckhdq(v81, v81);
        v87 = _m_pfadd(_m_pfadd(_m_pfmul(v84, 0), _m_pfmul(v82, 0)), _m_pfmul(v83, v384));
        v88 = _m_pfadd(_m_pfmul(0, v86), _m_pfadd(_m_pfmul(0, v83), _m_pfadd(v85, _m_pfmul(v382, v82))));
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
        v97 = _m_pfmul(v383, v96);
        v98 = _m_punpckhdq(v93, v93);
        v99 = _m_pfadd(_m_pfadd(_m_pfmul(v96, 0), _m_pfmul(v94, 0)), _m_pfmul(v95, v384));
        v100 = _m_pfadd(_m_pfmul(0, v98), _m_pfadd(_m_pfmul(0, v95), _m_pfadd(v97, _m_pfmul(v382, v94))));
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
        v109 = _m_pfmul(v383, v108);
        v110 = _m_punpckhdq(v105, v105);
        v111 = _m_pfadd(_m_pfadd(_m_pfmul(v108, 0), _m_pfmul(v106, 0)), _m_pfmul(v107, v384));
        v112 = _m_pfadd(_m_pfmul(0, v110), _m_pfadd(_m_pfmul(0, v107), _m_pfadd(v109, _m_pfmul(v382, v106))));
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
        v121 = _m_pfmul(v383, v120);
        v122 = _m_punpckhdq(v117, v117);
        v123 = _m_pfmul(0, v122);
        v124 = _m_pfadd(_m_pfadd(_m_pfmul(v120, 0), _m_pfmul(v118, 0)), _m_pfmul(v119, v384));
        v125 = _m_pfadd(_m_pfmul(v122, (__m64)0x3F80000000000000LL), v124);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            v123,
                                            _m_pfadd(_m_pfmul(0, v119), _m_pfadd(v121, _m_pfmul(v382, v118))));
        a1[7].m64_u64 = (unsigned __int64)v125;
        v126 = a1[1];
        v127 = _m_punpckhdq(v124, (__m64)a1->m64_u64);
        v128 = _m_punpckhdq(v125, v126);
        v129 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v130 = _m_punpckldq(v126, v126);
        v131 = _m_punpckhdq(v127, v127);
        v132 = _m_pfmul(v389, v131);
        v133 = _m_punpckhdq(v128, v128);
        v134 = _m_pfadd(_m_pfadd(_m_pfmul(v131, v391), _m_pfmul(v129, v387)), _m_pfmul(v130, v395));
        v135 = _m_pfadd(_m_pfmul(0, v133), _m_pfadd(_m_pfmul(v393, v130), _m_pfadd(v132, _m_pfmul(v385, v129))));
        v136 = a1[2];
        v137 = _m_pfadd(_m_pfmul(v133, v397), v134);
        v138 = a1[3];
        a1->m64_u64 = (unsigned __int64)v135;
        a1[1].m64_u64 = (unsigned __int64)v137;
        v139 = _m_punpckhdq(v134, v136);
        v140 = _m_punpckhdq(v137, v138);
        v141 = _m_punpckldq(v136, v136);
        v142 = _m_punpckldq(v138, v138);
        v143 = _m_punpckhdq(v139, v139);
        v144 = _m_pfmul(v389, v143);
        v145 = _m_punpckhdq(v140, v140);
        v146 = _m_pfadd(_m_pfadd(_m_pfmul(v143, v391), _m_pfmul(v141, v387)), _m_pfmul(v142, v395));
        v147 = _m_pfadd(_m_pfmul(0, v145), _m_pfadd(_m_pfmul(v393, v142), _m_pfadd(v144, _m_pfmul(v385, v141))));
        v148 = a1[4];
        v149 = _m_pfadd(_m_pfmul(v145, v397), v146);
        v150 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v147;
        a1[3].m64_u64 = (unsigned __int64)v149;
        v151 = _m_punpckhdq(v146, v148);
        v152 = _m_punpckhdq(v149, v150);
        v153 = _m_punpckldq(v148, v148);
        v154 = _m_punpckldq(v150, v150);
        v155 = _m_punpckhdq(v151, v151);
        v156 = _m_pfmul(v389, v155);
        v157 = _m_punpckhdq(v152, v152);
        v158 = _m_pfadd(_m_pfadd(_m_pfmul(v155, v391), _m_pfmul(v153, v387)), _m_pfmul(v154, v395));
        v159 = _m_pfadd(_m_pfmul(0, v157), _m_pfadd(_m_pfmul(v393, v154), _m_pfadd(v156, _m_pfmul(v385, v153))));
        v160 = a1[6];
        v161 = _m_pfadd(_m_pfmul(v157, v397), v158);
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
                                              _m_pfmul(v393, v166),
                                              _m_pfadd(_m_pfmul(v389, v167), _m_pfmul(v385, v165))));
        a1[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                            _m_pfmul(v168, v397),
                                            _m_pfadd(
                                              _m_pfadd(_m_pfmul(v167, v391), _m_pfmul(v165, v387)),
                                              _m_pfmul(v166, v395)));
        v169 = _m_pfadd(_mm_cvtsi32_si64(a2[1].m64_u32[0]), _mm_cvtsi32_si64(a1[7].m64_u32[0]));
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd((__m64)a2->m64_u64, a1[6]);
        a1[7].m64_i32[0] = _mm_cvtsi64_si32(v169);
      }
      else
      {
        result = a1;
        a1->m64_u64 = (unsigned __int64)_m_punpckldq(v385, v389);
        a1[2].m64_u64 = (unsigned __int64)_m_punpckhdq(v385, v389);
        v170 = _m_punpckldq(v395, v397);
        a1[5].m64_u64 = (unsigned __int64)v170;
        a1[7].m64_u64 = (unsigned __int64)_m_punpckhdq(v395, v397);
        a1[4].m64_u64 = (unsigned __int64)_m_punpckldq(v387, v391);
        v171 = _m_punpckldq(v393, 0);
        a1[6].m64_u64 = (unsigned __int64)_m_punpckhdq(v387, v391);
        a1[3].m64_u64 = (unsigned __int64)_m_punpckhdq(v393, 0);
        a1[1].m64_u64 = (unsigned __int64)v171;
        v172 = a1[1];
        v173 = _m_punpckhdq(v171, (__m64)a1->m64_u64);
        v174 = _m_punpckhdq(v170, v172);
        v175 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v176 = _m_punpckldq(v172, v172);
        v177 = _m_punpckhdq(v173, v173);
        v178 = _m_pfmul(v383, v177);
        v179 = _m_punpckhdq(v174, v174);
        v180 = _m_pfadd(_m_pfadd(_m_pfmul(v177, 0), _m_pfmul(v175, 0)), _m_pfmul(v176, v384));
        v181 = _m_pfadd(_m_pfmul(0, v179), _m_pfadd(_m_pfmul(0, v176), _m_pfadd(v178, _m_pfmul(v382, v175))));
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
        v190 = _m_pfmul(v383, v189);
        v191 = _m_punpckhdq(v186, v186);
        v192 = _m_pfadd(_m_pfadd(_m_pfmul(v189, 0), _m_pfmul(v187, 0)), _m_pfmul(v188, v384));
        v193 = _m_pfadd(_m_pfmul(0, v191), _m_pfadd(_m_pfmul(0, v188), _m_pfadd(v190, _m_pfmul(v382, v187))));
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
        v202 = _m_pfmul(v383, v201);
        v203 = _m_punpckhdq(v198, v198);
        v204 = _m_pfadd(_m_pfadd(_m_pfmul(v201, 0), _m_pfmul(v199, 0)), _m_pfmul(v200, v384));
        v205 = _m_pfadd(_m_pfmul(0, v203), _m_pfadd(_m_pfmul(0, v200), _m_pfadd(v202, _m_pfmul(v382, v199))));
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
        v214 = _m_pfmul(v383, v213);
        v215 = _m_punpckhdq(v210, v210);
        v216 = _m_pfmul(0, v215);
        v217 = _m_pfadd(_m_pfadd(_m_pfmul(v213, 0), _m_pfmul(v211, 0)), _m_pfmul(v212, v384));
        v218 = _m_pfadd(_m_pfmul(v215, (__m64)0x3F80000000000000LL), v217);
        a1[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                            v216,
                                            _m_pfadd(_m_pfmul(0, v212), _m_pfadd(v214, _m_pfmul(v382, v211))));
        a1[7].m64_u64 = (unsigned __int64)v218;
        v219 = a1[1];
        v220 = _m_punpckhdq(v217, (__m64)a1->m64_u64);
        v221 = _m_punpckhdq(v218, v219);
        v222 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
        v223 = _m_punpckldq(v219, v219);
        v224 = _m_punpckhdq(v220, v220);
        v225 = _m_pfmul(v389, v224);
        v226 = _m_punpckhdq(v221, v221);
        v227 = _m_pfadd(_m_pfadd(_m_pfmul(v224, v391), _m_pfmul(v222, v387)), _m_pfmul(v223, v395));
        v228 = _m_pfadd(_m_pfmul(0, v226), _m_pfadd(_m_pfmul(v393, v223), _m_pfadd(v225, _m_pfmul(v385, v222))));
        v229 = a1[2];
        v230 = _m_pfadd(_m_pfmul(v226, v397), v227);
        v231 = a1[3];
        a1->m64_u64 = (unsigned __int64)v228;
        a1[1].m64_u64 = (unsigned __int64)v230;
        v232 = _m_punpckhdq(v227, v229);
        v233 = _m_punpckhdq(v230, v231);
        v234 = _m_punpckldq(v229, v229);
        v235 = _m_punpckldq(v231, v231);
        v236 = _m_punpckhdq(v232, v232);
        v237 = _m_pfmul(v389, v236);
        v238 = _m_punpckhdq(v233, v233);
        v239 = _m_pfadd(_m_pfadd(_m_pfmul(v236, v391), _m_pfmul(v234, v387)), _m_pfmul(v235, v395));
        v240 = _m_pfadd(_m_pfmul(0, v238), _m_pfadd(_m_pfmul(v393, v235), _m_pfadd(v237, _m_pfmul(v385, v234))));
        v241 = a1[4];
        v242 = _m_pfadd(_m_pfmul(v238, v397), v239);
        v243 = a1[5];
        a1[2].m64_u64 = (unsigned __int64)v240;
        a1[3].m64_u64 = (unsigned __int64)v242;
        v244 = _m_punpckhdq(v239, v241);
        v245 = _m_punpckhdq(v242, v243);
        v246 = _m_punpckldq(v241, v241);
        v247 = _m_punpckldq(v243, v243);
        v248 = _m_punpckhdq(v244, v244);
        v249 = _m_pfmul(v389, v248);
        v250 = _m_punpckhdq(v245, v245);
        v251 = _m_pfadd(_m_pfadd(_m_pfmul(v248, v391), _m_pfmul(v246, v387)), _m_pfmul(v247, v395));
        v252 = _m_pfadd(_m_pfmul(0, v250), _m_pfadd(_m_pfmul(v393, v247), _m_pfadd(v249, _m_pfmul(v385, v246))));
        v253 = a1[6];
        v254 = _m_pfadd(_m_pfmul(v250, v397), v251);
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
                                              _m_pfmul(v393, v259),
                                              _m_pfadd(_m_pfmul(v389, v260), _m_pfmul(v385, v258))));
        a1[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                            _m_pfmul(v261, v397),
                                            _m_pfadd(
                                              _m_pfadd(_m_pfmul(v260, v391), _m_pfmul(v258, v387)),
                                              _m_pfmul(v259, v395)));
      }
    }
    else if ( a2 )
    {
      v262 = (__m64)a2->m64_u64;
      v263 = (__m64)a4->m64_u64;
      v264 = _mm_cvtsi32_si64(a4[1].m64_u32[0]);
      v265 = _m_punpckldq(_mm_cvtsi32_si64(a2[1].m64_u32[0]), (__m64)0x3F8000003F800000LL);
      v266 = _m_pfsub((__m64)0x3F8000003F800000LL, (__m64)a4->m64_u64);
      a1[5].m64_u64 = (unsigned __int64)v264;
      a1[1].m64_u64 = 0;
      a1[3].m64_u64 = 0;
      a1[4].m64_u64 = 0;
      a1->m64_u64 = (unsigned __int64)_m_punpckldq(v263, 0);
      a1[2].m64_u64 = (unsigned __int64)_m_punpckhdq(0, v263);
      a1[6].m64_u64 = (unsigned __int64)_m_pfmul(v266, v262);
      a1[7].m64_u64 = (unsigned __int64)_m_pfmul(_m_pfsub((__m64)0x3F8000003F800000LL, v264), v265);
    }
    else
    {
      v267 = _mm_cvtsi32_si64(a4[1].m64_u32[0]);
      v268 = _m_punpckhdq(0, (__m64)a4->m64_u64);
      a1->m64_u64 = (unsigned __int64)_m_punpckldq((__m64)a4->m64_u64, 0);
      a1[1].m64_u64 = 0;
      a1[2].m64_u64 = (unsigned __int64)v268;
      a1[3].m64_u64 = 0;
      a1[4].m64_u64 = 0;
      a1[5].m64_u64 = (unsigned __int64)v267;
      a1[6].m64_u64 = 0;
      a1[7].m64_u64 = 0x3F80000000000000LL;
    }
  }
  else
  {
    v269 = _mm_cvtsi32_si64(0x3F800000u);
    v270 = _m_punpckldq(_m_punpckhdq(v269, v269), v269);
    a1->m64_u64 = (unsigned __int64)v269;
    a1[1].m64_u64 = 0;
    a1[2].m64_u64 = (unsigned __int64)v270;
    a1[3].m64_u64 = 0;
    a1[4].m64_u64 = 0;
    a1[5].m64_u64 = (unsigned __int64)v269;
    a1[6].m64_u64 = 0;
    a1[7].m64_u64 = (unsigned __int64)v270;
  }
  if ( a6 )
  {
    v271 = (__m64)a6->m64_u64;
    v272 = _m_pfadd(v271, v271);
    v273 = a6[1];
    v274 = _m_punpckhdq(v271, v271);
    v275 = _m_punpckhdq(v273, v273);
    v276 = _m_pfmul((__m64)a6->m64_u64, v272);
    v277 = _m_punpckldq(_m_pfadd(v273, v273), v272);
    v278 = _m_pfmul(v272, v275);
    v279 = _m_pfmul(_m_punpckldq(v273, v273), v277);
    v280 = _m_pfmul(v277, v275);
    v281 = _m_pfmul(v277, v274);
    v282 = _m_punpckhdq(v281, v279);
    v283 = _m_punpckhdq(_m_punpckldq(v280, v280), v278);
    v284 = _m_pfsubr(_m_pfadd(_m_punpckldq(v279, v279), v276), (__m64)0x3F8000003F800000LL);
    v396 = _m_punpckldq(_m_pfsubr(_m_pfacc(v276, v276), (__m64)0x3F8000003F800000LL), 0);
    v285 = v281;
    v286 = _m_pfadd(v281, v278);
    v287 = _m_pfsub(v285, v278);
    v288 = _m_pfsub(v282, v283);
    v289 = _m_punpckldq(v286, 0);
    v290 = _m_pfadd(v282, v283);
    v392 = v289;
    v388 = _m_punpckhdq(v288, 0);
    v390 = _m_punpckldq(v288, v284);
    v386 = _m_punpckhdq(v284, _m_punpckldq(v290, v290));
    v394 = _m_punpckldq(_m_punpckhdq(v290, v290), v287);
    v398 = _m_punpckldq(0, (__m64)1065353216LL);
    if ( a5 )
    {
      v291 = (__m64)a5->m64_u64;
      v292 = _mm_cvtsi32_si64(a5[1].m64_u32[0]);
      v293 = _m_pfsub(_mm_cvtsi32_si64(result[7].m64_u32[0]), v292);
      result[6].m64_u64 = (unsigned __int64)_m_pfsub(result[6], (__m64)a5->m64_u64);
      result[7].m64_i32[0] = _mm_cvtsi64_si32(v293);
      v294 = result[1];
      v295 = _m_punpckhdq(v291, (__m64)result->m64_u64);
      v296 = _m_punpckhdq(v292, v294);
      v297 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
      v298 = _m_punpckldq(v294, v294);
      v299 = _m_punpckhdq(v295, v295);
      v300 = _m_pfmul(v390, v299);
      v301 = _m_punpckhdq(v296, v296);
      v302 = _m_pfadd(_m_pfadd(_m_pfmul(v299, v392), _m_pfmul(v297, v388)), _m_pfmul(v298, v396));
      v303 = _m_pfadd(_m_pfmul(0, v301), _m_pfadd(_m_pfmul(v394, v298), _m_pfadd(v300, _m_pfmul(v386, v297))));
      v304 = result[2];
      v305 = _m_pfadd(_m_pfmul(v301, v398), v302);
      v306 = result[3];
      result->m64_u64 = (unsigned __int64)v303;
      result[1].m64_u64 = (unsigned __int64)v305;
      v307 = _m_punpckhdq(v302, v304);
      v308 = _m_punpckhdq(v305, v306);
      v309 = _m_punpckldq(v304, v304);
      v310 = _m_punpckldq(v306, v306);
      v311 = _m_punpckhdq(v307, v307);
      v312 = _m_pfmul(v390, v311);
      v313 = _m_punpckhdq(v308, v308);
      v314 = _m_pfadd(_m_pfadd(_m_pfmul(v311, v392), _m_pfmul(v309, v388)), _m_pfmul(v310, v396));
      v315 = _m_pfadd(_m_pfmul(0, v313), _m_pfadd(_m_pfmul(v394, v310), _m_pfadd(v312, _m_pfmul(v386, v309))));
      v316 = result[4];
      v317 = _m_pfadd(_m_pfmul(v313, v398), v314);
      v318 = result[5];
      result[2].m64_u64 = (unsigned __int64)v315;
      result[3].m64_u64 = (unsigned __int64)v317;
      v319 = _m_punpckhdq(v314, v316);
      v320 = _m_punpckhdq(v317, v318);
      v321 = _m_punpckldq(v316, v316);
      v322 = _m_punpckldq(v318, v318);
      v323 = _m_punpckhdq(v319, v319);
      v324 = _m_pfmul(v390, v323);
      v325 = _m_punpckhdq(v320, v320);
      v326 = _m_pfadd(_m_pfadd(_m_pfmul(v323, v392), _m_pfmul(v321, v388)), _m_pfmul(v322, v396));
      v327 = _m_pfadd(_m_pfmul(0, v325), _m_pfadd(_m_pfmul(v394, v322), _m_pfadd(v324, _m_pfmul(v386, v321))));
      v328 = result[6];
      v329 = _m_pfadd(_m_pfmul(v325, v398), v326);
      v330 = result[7];
      result[4].m64_u64 = (unsigned __int64)v327;
      result[5].m64_u64 = (unsigned __int64)v329;
      v331 = _m_punpckhdq(v326, v328);
      v332 = _m_punpckhdq(v329, v330);
      v333 = _m_punpckldq(v328, v328);
      v334 = _m_punpckldq(v330, v330);
      v335 = _m_punpckhdq(v331, v331);
      v336 = _m_punpckhdq(v332, v332);
      result[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(0, v336),
                                              _m_pfadd(
                                                _m_pfmul(v394, v334),
                                                _m_pfadd(_m_pfmul(v390, v335), _m_pfmul(v386, v333))));
      result[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(v336, v398),
                                              _m_pfadd(
                                                _m_pfadd(_m_pfmul(v335, v392), _m_pfmul(v333, v388)),
                                                _m_pfmul(v334, v396)));
      v337 = _m_pfadd(_mm_cvtsi32_si64(result[7].m64_u32[0]), _mm_cvtsi32_si64(a5[1].m64_u32[0]));
      result[6].m64_u64 = (unsigned __int64)_m_pfadd(result[6], (__m64)a5->m64_u64);
      result[7].m64_i32[0] = _mm_cvtsi64_si32(v337);
    }
    else
    {
      v338 = result[1];
      v339 = _m_punpckhdq(v289, (__m64)result->m64_u64);
      v340 = _m_punpckhdq(v287, v338);
      v341 = _m_punpckldq((__m64)result->m64_u64, (__m64)result->m64_u64);
      v342 = _m_punpckldq(v338, v338);
      v343 = _m_punpckhdq(v339, v339);
      v344 = _m_pfmul(v390, v343);
      v345 = _m_punpckhdq(v340, v340);
      v346 = _m_pfadd(_m_pfadd(_m_pfmul(v343, v392), _m_pfmul(v341, v388)), _m_pfmul(v342, v396));
      v347 = _m_pfadd(_m_pfmul(0, v345), _m_pfadd(_m_pfmul(v394, v342), _m_pfadd(v344, _m_pfmul(v386, v341))));
      v348 = result[2];
      v349 = _m_pfadd(_m_pfmul(v345, v398), v346);
      v350 = result[3];
      result->m64_u64 = (unsigned __int64)v347;
      result[1].m64_u64 = (unsigned __int64)v349;
      v351 = _m_punpckhdq(v346, v348);
      v352 = _m_punpckhdq(v349, v350);
      v353 = _m_punpckldq(v348, v348);
      v354 = _m_punpckldq(v350, v350);
      v355 = _m_punpckhdq(v351, v351);
      v356 = _m_pfmul(v390, v355);
      v357 = _m_punpckhdq(v352, v352);
      v358 = _m_pfadd(_m_pfadd(_m_pfmul(v355, v392), _m_pfmul(v353, v388)), _m_pfmul(v354, v396));
      v359 = _m_pfadd(_m_pfmul(0, v357), _m_pfadd(_m_pfmul(v394, v354), _m_pfadd(v356, _m_pfmul(v386, v353))));
      v360 = result[4];
      v361 = _m_pfadd(_m_pfmul(v357, v398), v358);
      v362 = result[5];
      result[2].m64_u64 = (unsigned __int64)v359;
      result[3].m64_u64 = (unsigned __int64)v361;
      v363 = _m_punpckhdq(v358, v360);
      v364 = _m_punpckhdq(v361, v362);
      v365 = _m_punpckldq(v360, v360);
      v366 = _m_punpckldq(v362, v362);
      v367 = _m_punpckhdq(v363, v363);
      v368 = _m_pfmul(v390, v367);
      v369 = _m_punpckhdq(v364, v364);
      v370 = _m_pfadd(_m_pfadd(_m_pfmul(v367, v392), _m_pfmul(v365, v388)), _m_pfmul(v366, v396));
      v371 = _m_pfadd(_m_pfmul(0, v369), _m_pfadd(_m_pfmul(v394, v366), _m_pfadd(v368, _m_pfmul(v386, v365))));
      v372 = result[6];
      v373 = _m_pfadd(_m_pfmul(v369, v398), v370);
      v374 = result[7];
      result[4].m64_u64 = (unsigned __int64)v371;
      result[5].m64_u64 = (unsigned __int64)v373;
      v375 = _m_punpckhdq(v370, v372);
      v376 = _m_punpckhdq(v373, v374);
      v377 = _m_punpckldq(v372, v372);
      v378 = _m_punpckldq(v374, v374);
      v379 = _m_punpckhdq(v375, v375);
      v380 = _m_punpckhdq(v376, v376);
      result[6].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(0, v380),
                                              _m_pfadd(
                                                _m_pfmul(v394, v378),
                                                _m_pfadd(_m_pfmul(v390, v379), _m_pfmul(v386, v377))));
      result[7].m64_u64 = (unsigned __int64)_m_pfadd(
                                              _m_pfmul(v380, v398),
                                              _m_pfadd(
                                                _m_pfadd(_m_pfmul(v379, v392), _m_pfmul(v377, v388)),
                                                _m_pfmul(v378, v396)));
    }
  }
  if ( a7 )
  {
    v381 = _m_pfadd(_mm_cvtsi32_si64(result[7].m64_u32[0]), _mm_cvtsi32_si64(a7[1].m64_u32[0]));
    result[6].m64_u64 = (unsigned __int64)_m_pfadd(result[6], (__m64)a7->m64_u64);
    result[7].m64_i32[0] = _mm_cvtsi64_si32(v381);
  }
  _m_femms();
  return result;
}
