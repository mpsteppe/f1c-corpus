int sub_61FD4E()
{
  double v0; // st7
  double *v1; // edx
  double **v2; // eax
  double v3; // st6
  double *v4; // edx
  int *v5; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st5
  double *v9; // eax
  int *v10; // edx
  double v11; // st6
  double v12; // st5
  double v13; // st5
  double *v14; // edx
  int *v15; // esi
  double v16; // st5
  double v17; // st5
  double *v18; // esi
  double v19; // st6
  int *v20; // edx
  double v21; // st5
  double *v22; // esi
  int *v23; // edx
  double v24; // st6
  double v25; // st5
  double *v26; // esi
  int *v27; // edx
  double v28; // st6
  double v29; // st5
  double v30; // st4
  double *v31; // edx
  int *v32; // esi
  double v33; // st5
  double v34; // st4
  double v35; // st4
  double *v36; // edx
  int *v37; // esi
  double v38; // st4
  double v39; // st4
  double *v40; // esi
  double v41; // st5
  int *v42; // edx
  double v43; // st4
  double *v44; // edx
  int *v45; // esi
  double v46; // st6
  double v47; // st5
  double v48; // st5
  double *v49; // edx
  int *v50; // esi
  double v51; // st5
  double v52; // st5
  double *v53; // esi
  double v54; // st6
  int *v55; // edx
  double v56; // st5
  int i; // edx
  double v58; // st5
  double *v59; // esi
  int *v60; // edx
  double v61; // st6
  double v62; // st6
  double *v63; // edx
  int *v64; // esi
  double v65; // st5
  double v66; // st4
  double v67; // st3
  double v68; // st2
  double v69; // st1
  double v70; // st0
  double v71; // st1
  double *v72; // esi
  int *v73; // edx
  double v74; // st6
  double v75; // st5
  int j; // edx
  double v77; // st5
  double *v78; // edx
  int *v79; // esi
  double v80; // st6
  double v81; // st5
  double v82; // st4
  double v83; // st4
  double *v84; // edx
  int *v85; // esi
  double v86; // st4
  double v87; // st4
  double *v88; // esi
  double v89; // st5
  int *v90; // edx
  double v91; // st4
  int k; // edx
  double v93; // st4
  double *v94; // esi
  int *v95; // edx
  double v96; // st5
  double v97; // st5
  double *v98; // edx
  int *v99; // esi
  double v100; // st4
  double v101; // st3
  double v102; // st2
  double v103; // st1
  double v104; // st1
  double *v105; // esi
  int *v106; // edx
  double v107; // st5
  double v108; // st4
  int m; // edx
  double v110; // st4
  double *v111; // esi
  int *v112; // edx
  double v113; // st5
  double v114; // st4
  double v115; // st3
  double *v116; // esi
  int *v117; // edx
  double v118; // st4
  double v119; // st3
  double v120; // st2
  double *v121; // edx
  int *v122; // esi
  double v123; // st3
  double v124; // st2
  double v125; // st2
  double *v126; // edx
  int *v127; // esi
  double v128; // st2
  double v129; // st2
  double *v130; // esi
  double v131; // st3
  int *v132; // edx
  double v133; // st2
  double *v134; // esi
  int *v135; // edx
  double v136; // st3
  double v137; // st2
  double *v138; // esi
  int *v139; // edx
  double v140; // st3
  double v141; // st2
  double v142; // st1
  double *v143; // edx
  int *v144; // esi
  double v145; // st2
  double v146; // st1
  double v147; // st1
  double *v148; // edx
  int *v149; // esi
  double v150; // st1
  double v151; // st1
  double *v152; // esi
  double v153; // st2
  int *v154; // edx
  double v155; // st1
  double *v156; // edx
  int *v157; // esi
  double v158; // st3
  double v159; // st2
  double v160; // st2
  double *v161; // edx
  int *v162; // esi
  double v163; // st2
  double v164; // st2
  double *v165; // esi
  double v166; // st3
  int *v167; // edx
  double v168; // st2
  int n; // edx
  double v170; // st2
  double *v171; // esi
  int *v172; // edx
  double v173; // st3
  double v174; // st3
  double *v175; // edx
  int *v176; // esi
  double v177; // st2
  double v178; // st1
  double v179; // st1
  double *v180; // esi
  int *v181; // edx
  double v182; // st3
  double v183; // st2
  int ii; // edx
  double v185; // st2
  double *v186; // edx
  int *v187; // esi
  double v188; // st3
  double v189; // st2
  double v190; // st1
  double v191; // st1
  double *v192; // edx
  int *v193; // esi
  double v194; // st1
  double v195; // st1
  double *v196; // esi
  double v197; // st2
  int *v198; // edx
  double v199; // st1
  int jj; // edx
  double v201; // st1
  double *v202; // esi
  int *v203; // edx
  double v204; // st2
  double v205; // st2
  double *v206; // edx
  int *v207; // esi
  double v208; // st1
  double v209; // st1
  double *v210; // esi
  int *v211; // edx
  double v212; // st2
  double v213; // st1
  int kk; // edx
  double v215; // st1
  double *v216; // eax
  int *v217; // edx
  double v218; // st2
  double v219; // st1
  double v220; // st1
  double *v221; // eax
  int *v222; // edx
  double v223; // st1
  double v224; // st1
  double *v225; // edx
  int *v226; // eax
  double v227; // st2
  int mm; // eax
  double v229; // st2
  double v230; // st2
  double *v231; // eax
  int *v232; // edx
  double v233; // st1
  double v234; // st1
  double *v235; // eax
  int *v236; // edx
  double v237; // st1
  double v238; // st1
  double *v239; // edx
  int *v240; // eax
  double v241; // st1
  int nn; // eax
  double v243; // st1
  double *v244; // eax
  int *v245; // edx
  double v246; // st1
  double v247; // st1
  double *v248; // eax
  int *v249; // edx
  double v250; // st1
  double v251; // st1
  double *v252; // eax
  int *v253; // edx
  double v254; // st1
  double v255; // st1
  double *v256; // eax
  int *v257; // edx
  double v258; // st1
  double v259; // st1
  double *v260; // edx
  int *v261; // eax
  double v262; // st1
  int i1; // eax
  double v264; // st1
  double *v265; // eax
  int *v266; // edx
  double v267; // st1
  double v268; // st0
  double v269; // st0
  double *v270; // eax
  int *v271; // edx
  double v272; // st0
  double v273; // st0
  double *v274; // eax
  int *v275; // edx
  double v276; // st0
  double v277; // st0
  double *v278; // eax
  int *v279; // edx
  double v280; // st1
  double v281; // st1
  double *v282; // edx
  int *v283; // eax
  double v284; // st1
  double v285; // st1
  int i2; // eax
  double v287; // st0
  int i3; // eax
  double v289; // st0
  double *v290; // edx
  int *v291; // eax
  double v292; // st1
  double v293; // st0
  double v294; // st0
  double *v295; // edx
  int *v296; // eax
  double v297; // st0
  double v298; // st0
  double *v299; // eax
  int *v300; // edx
  double v301; // st1
  double v302; // st1
  double *v303; // edx
  int *v304; // eax
  double v305; // st1
  double v306; // st1
  int i4; // eax
  double v308; // st0
  int i5; // eax
  double v310; // st0
  double *v311; // eax
  int *v312; // edx
  double v313; // st2
  double v314; // st1
  double v315; // st1
  double *v316; // eax
  int *v317; // edx
  double v318; // st1
  double v319; // st1
  double *v320; // eax
  int *v321; // edx
  double v322; // st1
  double v323; // st1
  double *v324; // eax
  int *v325; // edx
  double v326; // st1
  double v327; // st1
  double *v328; // edx
  int *v329; // eax
  double v330; // st2
  double v331; // st2
  int i6; // eax
  double v333; // st1
  int i7; // eax
  double v335; // st1
  double *v336; // eax
  double v337; // st2
  int *v338; // edx
  double v339; // st1
  double v340; // st1
  double *v341; // eax
  int *v342; // edx
  double v343; // st1
  double v344; // st1
  double *v345; // eax
  int *v346; // edx
  double v347; // st1
  double v348; // st1
  double *v349; // eax
  int *v350; // edx
  double v351; // st1
  double v352; // st1
  double *v353; // edx
  int *v354; // eax
  double v355; // st1
  double v356; // st1
  int i8; // eax
  double v358; // st0
  int i9; // eax
  double v360; // st0
  double *v361; // eax
  int *v362; // edx
  double v363; // st1
  double v364; // st1
  double *v365; // eax
  int *v366; // edx
  double v367; // st1
  double v368; // st1
  double *v369; // eax
  int *v370; // edx
  double v371; // st1
  double v372; // st1
  double *v373; // eax
  int *v374; // edx
  double v375; // st1
  double v376; // st1
  double *v377; // edx
  int *v378; // eax
  double v379; // st1
  double v380; // st1
  int i10; // eax
  double v382; // st0
  int i11; // eax
  double v384; // st0
  double *v385; // eax
  int *v386; // edx
  double v387; // st1
  double v388; // st0
  double v389; // st0
  double *v390; // eax
  int *v391; // edx
  double v392; // st0
  double v393; // st0
  double *v394; // eax
  int *v395; // edx
  double v396; // st0
  double v397; // st0
  double *v398; // eax
  int *v399; // edx
  double v400; // st1
  double v401; // st1
  double *v402; // edx
  int *v403; // eax
  double v404; // st1
  double v405; // st1
  int i12; // eax
  double v407; // st0
  int i13; // eax
  double v409; // st0
  double *v410; // edx
  int *v411; // eax
  double v412; // st1
  double v413; // st0
  double v414; // st0
  double *v415; // edx
  int *v416; // eax
  double v417; // st0
  double v418; // st0
  double *v419; // eax
  int *v420; // edx
  double v421; // st1
  double v422; // st1
  double *v423; // edx
  int *v424; // eax
  double v425; // st1
  double v426; // st1
  int i14; // eax
  double v428; // st0
  int i15; // eax
  double v430; // st0
  double *v431; // eax
  int *v432; // edx
  double v433; // st2
  double v434; // st1
  double v435; // st1
  double *v436; // eax
  int *v437; // edx
  double v438; // st1
  double v439; // st1
  double *v440; // eax
  int *v441; // edx
  double v442; // st1
  double v443; // st1
  double *v444; // edx
  int *v445; // esi
  double v446; // st1
  double v447; // st1
  double *v448; // esi
  int *v449; // edx
  double v450; // st2
  double v451; // st2
  int i16; // edx
  double v453; // st1
  int i17; // edx
  double v455; // st1
  double *v456; // edx
  double v457; // st2
  int *v458; // esi
  double v459; // st1
  double v460; // st0
  double v461; // st0
  double *v462; // edx
  int *v463; // esi
  double v464; // st0
  double v465; // st0
  double *v466; // edx
  int *v467; // esi
  double v468; // st0
  double v469; // st0
  double *v470; // edx
  int *v471; // esi
  double v472; // st0
  double v473; // st0
  double *v474; // esi
  int *v475; // edx
  double v476; // st1
  double v477; // st1
  int i18; // edx
  double v479; // st0
  int i19; // edx
  double v481; // st0
  double *v482; // edx
  int *v483; // esi
  double v484; // st1
  double v485; // st0
  double v486; // st0
  double *v487; // edx
  int *v488; // esi
  double v489; // st0
  double v490; // st0
  double *v491; // edx
  int *v492; // esi
  double v493; // st0
  double v494; // st0
  double *v495; // edx
  int *v496; // esi
  double v497; // st0
  double v498; // st0
  double *v499; // esi
  int *v500; // edx
  double v501; // st1
  double v502; // st1
  int i20; // edx
  double v504; // st0
  int i21; // edx
  double v506; // st0
  double *v507; // edx
  int *v508; // esi
  double v509; // st1
  double v510; // st0
  double v511; // st0
  double *v512; // edx
  int *v513; // esi
  double v514; // st0
  double v515; // st0
  double *v516; // edx
  int *v517; // esi
  double v518; // st0
  double v519; // st0
  double *v520; // edx
  int *v521; // esi
  double v522; // st0
  double v523; // st0
  double *v524; // esi
  int *v525; // edx
  double v526; // st1
  double v527; // st1
  int i22; // edx
  double v529; // st0
  int i23; // edx
  double v531; // st0
  double *v532; // esi
  int *v533; // edx
  double v534; // st1
  double v535; // st0
  double v536; // st0
  double *v537; // esi
  int *v538; // edx
  double v539; // st0
  double v540; // st0
  double *v541; // eax
  int *v542; // edx
  double v543; // st1
  double v544; // st1
  double *v545; // edx
  int *v546; // eax
  double v547; // st1
  double v548; // st1
  int i24; // eax
  double v550; // st0
  int i25; // eax
  double v552; // st0
  double *v553; // eax
  int *v554; // edx
  double v555; // st1
  double v556; // st1
  double *v557; // eax
  int *v558; // edx
  double v559; // st1
  double v560; // st1
  double v561; // st1
  double *v562; // edx
  int *v563; // eax
  double v564; // st0
  int i26; // eax
  double v566; // st0
  int i27; // eax
  double v568; // st0
  double *v569; // eax
  int *v570; // edx
  double v571; // st1
  double v572; // st1
  double *v573; // eax
  int *v574; // edx
  double v575; // st1
  double v576; // st1
  double v577; // st1
  double *v578; // edx
  int *v579; // eax
  double v580; // st0
  int i28; // eax
  double v582; // st0
  int i29; // eax
  double v584; // st0
  double *v585; // eax
  int *v586; // edx
  double v587; // st1
  double v588; // st0
  double v589; // st0
  double *v590; // eax
  int *v591; // edx
  double v592; // st0
  double v593; // st0
  int v594; // eax
  double v595; // st0
  int i30; // eax
  double v597; // st0
  double *v598; // eax
  int *v599; // edx
  double v600; // st1
  double v601; // st0
  double v602; // st0
  double *v603; // eax
  int *v604; // edx
  double v605; // st0
  double v606; // st0
  int v607; // eax
  double v608; // st1
  double v609; // st0
  int v610; // eax
  double v611; // st0
  double v612; // st0
  double *v613; // edx
  int *v614; // eax
  double v615; // st1
  double v616; // st0
  double v617; // st0
  double *v618; // edx
  int *v619; // eax
  double v620; // st0
  double v621; // st0
  int v622; // eax
  double v623; // st1
  double v624; // st0
  int v625; // eax
  double v626; // st0
  double v627; // st0
  int v628; // eax
  double v629; // st1
  int i31; // eax
  double v631; // st1
  int i32; // eax
  double v633; // st1
  int i33; // eax
  double v635; // st1
  int i34; // eax
  double v637; // st1
  int i35; // eax
  double v639; // st1
  int i36; // eax
  double v641; // st1
  int i37; // eax
  double v643; // st1
  int i38; // eax
  double v645; // st1
  int i39; // eax
  double v647; // st1
  int i40; // eax
  double v649; // st1
  int i41; // eax
  double v651; // st1
  int i42; // eax
  double v653; // st1
  int i43; // eax
  double v655; // st1
  int i44; // eax
  double v657; // st1
  int i45; // eax
  double v659; // st1
  int i46; // eax
  double v661; // st1
  int i47; // eax
  double v663; // st1
  double v664; // st1
  int v665; // eax
  double v666; // st0
  double v667; // st0
  int v668; // eax
  double v669; // st1
  int v670; // eax
  double v671; // st1
  double v672; // st1
  int v673; // eax
  double v674; // st1
  int v675; // eax
  double v676; // st1
  int v677; // eax
  double v678; // st1
  int v679; // eax
  double v680; // st1
  int v681; // eax
  double v682; // st1
  int v683; // eax
  double v684; // st1
  double v685; // st1
  int v686; // eax
  double v687; // st4
  double v688; // st4
  int v689; // eax
  double v690; // st3
  double v691; // st3
  int v692; // eax
  double v693; // st3
  double v694; // st3
  int v695; // eax
  double v696; // st2
  double v697; // st2
  int v698; // eax
  double v699; // st3
  double v700; // st2
  double v701; // st2
  int v702; // eax
  double v703; // st2
  double v704; // st1
  double v705; // st1
  int v706; // eax
  double v707; // st2
  int v708; // eax
  double v709; // st5
  double v710; // st4
  double v711; // st4
  int v712; // eax
  double v713; // st4
  double v714; // st3
  double v715; // st3
  int result; // eax
  double v717; // st4
  double v718; // st4
  double v719; // [esp+10h] [ebp-8h]
  double v720; // [esp+10h] [ebp-8h]
  double v721; // [esp+10h] [ebp-8h]
  double v722; // [esp+10h] [ebp-8h]
  double v723; // [esp+10h] [ebp-8h]
  double v724; // [esp+10h] [ebp-8h]
  double v725; // [esp+10h] [ebp-8h]
  double v726; // [esp+10h] [ebp-8h]
  double v727; // [esp+10h] [ebp-8h]
  double v728; // [esp+10h] [ebp-8h]
  double v729; // [esp+10h] [ebp-8h]
  double v730; // [esp+10h] [ebp-8h]
  double v731; // [esp+10h] [ebp-8h]
  double v732; // [esp+10h] [ebp-8h]
  double v733; // [esp+10h] [ebp-8h]
  double v734; // [esp+10h] [ebp-8h]

  v0 = 1.0 / dbl_FB5C30;
  v1 = (double *)&unk_FB5CD0;
  v2 = (double **)&dword_FB5BE0;
  dbl_FB5C38 = dbl_FB5CF8 * (1.0 / dbl_FB5C30);
  dbl_FB5C40 = dbl_FB5DC0 * (1.0 / dbl_FB5C30);
  dbl_FB5C60 = dbl_FB6110 * (1.0 / dbl_FB5C30);
  dbl_FB5C68 = dbl_FB61D8 * (1.0 / dbl_FB5C30);
  do
  {
    v3 = v0 * **v2++;
    *v1++ = v3;
  }
  while ( (int)v2 < (int)&dword_FB5BF4 );
  v4 = (double *)&unk_FB5D98;
  v5 = &dword_FB5BE0;
  dbl_FB59C8 = dbl_FB59C8 * v0;
  v6 = dbl_FB59C8;
  dbl_FB5D00 = dbl_FB5D00 - dbl_FB5CF8 * dbl_FB5C38;
  dbl_FB5DC8 = dbl_FB5DC8 - dbl_FB5DC0 * dbl_FB5C38;
  dbl_FB6118 = dbl_FB6118 - dbl_FB6110 * dbl_FB5C38;
  dbl_FB61E0 = dbl_FB61E0 - dbl_FB61D8 * dbl_FB5C38;
  dbl_FB6C78 = dbl_FB6C78 - dbl_FB6C70 * dbl_FB5C38;
  dbl_FB6DB8 = dbl_FB6DB8 - dbl_FB6DB0 * dbl_FB5C38;
  dbl_FB6EF8 = dbl_FB6EF8 - dbl_FB6EF0 * dbl_FB5C38;
  dbl_FB7038 = dbl_FB7038 - dbl_FB7030 * dbl_FB5C38;
  dbl_FB7178 = dbl_FB7178 - dbl_FB7170 * dbl_FB5C38;
  v7 = 1.0 / dbl_FB5D00;
  dbl_FB5D08 = dbl_FB5DC8 * (1.0 / dbl_FB5D00);
  dbl_FB5D28 = dbl_FB6118 * (1.0 / dbl_FB5D00);
  dbl_FB5D30 = dbl_FB61E0 * (1.0 / dbl_FB5D00);
  do
  {
    v8 = v7 * *(double *)(*v5++ + 8);
    *v4++ = v8;
  }
  while ( (int)v5 < (int)&dword_FB5BF4 );
  v9 = &dbl_FB61D8;
  v10 = &dword_FB5B90;
  dbl_FB59D0 = (dbl_FB59D0 - v6 * dbl_FB5CF8) * v7;
  v11 = dbl_FB5DD0 - (dbl_FB5D08 * dbl_FB5DC8 + dbl_FB5C40 * dbl_FB5DC0);
  dbl_FB5DD0 = v11;
  do
  {
    v12 = *(double *)(*v10++ + 16);
    dbl_FB6120 = dbl_FB6120 - v12 * *(v9 - 25);
    v13 = v12 * *v9++;
    dbl_FB61E8 = dbl_FB61E8 - v13;
  }
  while ( (int)v10 < (int)&dword_FB5B98 );
  v14 = &dbl_FB6DB0;
  v15 = &dword_FB5B90;
  do
  {
    v16 = *(double *)(*v15++ + 16);
    dbl_FB6C80 = dbl_FB6C80 - v16 * *(v14 - 40);
    dbl_FB6DC0 = dbl_FB6DC0 - v16 * *v14;
    dbl_FB6F00 = dbl_FB6F00 - v16 * v14[40];
    dbl_FB7040 = dbl_FB7040 - v16 * v14[80];
    v17 = v16 * v14[120];
    ++v14;
    dbl_FB7180 = dbl_FB7180 - v17;
  }
  while ( (int)v15 < (int)&dword_FB5B98 );
  v18 = (double *)&unk_FB5E60;
  v19 = 1.0 / v11;
  v20 = &dword_FB5BE0;
  dbl_FB5DF0 = dbl_FB6120 * v19;
  dbl_FB5DF8 = dbl_FB61E8 * v19;
  do
  {
    v21 = v19 * *(double *)(*v20++ + 16);
    *v18++ = v21;
  }
  while ( (int)v20 < (int)&dword_FB5BF4 );
  v22 = (double *)&unk_FB5F38;
  v23 = &dword_FB5BF4;
  dbl_FB59D8 = (dbl_FB59D8 - (dbl_FB59D0 * dbl_FB5DC8 + v6 * dbl_FB5DC0)) * v19;
  v24 = 1.0 / dbl_FB5E88;
  dbl_FB5E90 = dbl_FB5F60 * (1.0 / dbl_FB5E88);
  dbl_FB5E98 = dbl_FB6038 * (1.0 / dbl_FB5E88);
  dbl_FB5EB0 = dbl_FB62A0 * (1.0 / dbl_FB5E88);
  dbl_FB5EB8 = dbl_FB6378 * (1.0 / dbl_FB5E88);
  do
  {
    v25 = v24 * *(double *)(*v23++ + 24);
    *v22++ = v25;
  }
  while ( (int)v23 < (int)&dword_FB5C08 );
  v26 = (double *)&unk_FB6010;
  v27 = &dword_FB5BF4;
  dbl_FB59E0 = dbl_FB59E0 * v24;
  v28 = dbl_FB59E0;
  dbl_FB5F68 = dbl_FB5F68 - dbl_FB5F60 * dbl_FB5E90;
  dbl_FB6040 = dbl_FB6040 - dbl_FB6038 * dbl_FB5E90;
  dbl_FB62A8 = dbl_FB62A8 - dbl_FB62A0 * dbl_FB5E90;
  dbl_FB6380 = dbl_FB6380 - dbl_FB6378 * dbl_FB5E90;
  dbl_FB72B8 = dbl_FB72B8 - dbl_FB72B0 * dbl_FB5E90;
  dbl_FB73E0 = dbl_FB73E0 - dbl_FB73D8 * dbl_FB5E90;
  dbl_FB7508 = dbl_FB7508 - dbl_FB7500 * dbl_FB5E90;
  dbl_FB7630 = dbl_FB7630 - dbl_FB7628 * dbl_FB5E90;
  dbl_FB7758 = dbl_FB7758 - dbl_FB7750 * dbl_FB5E90;
  v29 = 1.0 / dbl_FB5F68;
  dbl_FB5F70 = dbl_FB6040 * (1.0 / dbl_FB5F68);
  dbl_FB5F88 = dbl_FB62A8 * (1.0 / dbl_FB5F68);
  dbl_FB5F90 = dbl_FB6380 * (1.0 / dbl_FB5F68);
  do
  {
    v30 = v29 * *(double *)(*v27++ + 32);
    *v26++ = v30;
  }
  while ( (int)v27 < (int)&dword_FB5C08 );
  v31 = &dbl_FB6378;
  v32 = &dword_FB5B9C;
  dbl_FB59E8 = (dbl_FB59E8 - v28 * dbl_FB5F60) * v29;
  v33 = dbl_FB6048 - (dbl_FB5F70 * dbl_FB6040 + dbl_FB5E98 * dbl_FB6038);
  dbl_FB6048 = v33;
  do
  {
    v34 = *(double *)(*v32++ + 40);
    dbl_FB62B0 = dbl_FB62B0 - v34 * *(v31 - 27);
    v35 = v34 * *v31++;
    dbl_FB6388 = dbl_FB6388 - v35;
  }
  while ( (int)v32 < (int)&dword_FB5BA4 );
  v36 = &dbl_FB73D8;
  v37 = &dword_FB5B9C;
  do
  {
    v38 = *(double *)(*v37++ + 40);
    dbl_FB72C0 = dbl_FB72C0 - v38 * *(v36 - 37);
    dbl_FB73E8 = dbl_FB73E8 - v38 * *v36;
    dbl_FB7510 = dbl_FB7510 - v38 * v36[37];
    dbl_FB7638 = dbl_FB7638 - v38 * v36[74];
    v39 = v38 * v36[111];
    ++v36;
    dbl_FB7760 = dbl_FB7760 - v39;
  }
  while ( (int)v37 < (int)&dword_FB5BA4 );
  v40 = (double *)&unk_FB60E8;
  v41 = 1.0 / v33;
  v42 = &dword_FB5BF4;
  dbl_FB6060 = dbl_FB62B0 * v41;
  dbl_FB6068 = dbl_FB6388 * v41;
  do
  {
    v43 = v41 * *(double *)(*v42++ + 40);
    *v40++ = v43;
  }
  while ( (int)v42 < (int)&dword_FB5C08 );
  v44 = &dbl_FB61D8;
  v45 = &dword_FB5B90;
  dbl_FB59F0 = (dbl_FB59F0 - (dbl_FB59E8 * dbl_FB6040 + v28 * dbl_FB6038)) * v41;
  v46 = dbl_FB6140;
  do
  {
    v47 = *(double *)(*v45++ + 48);
    dbl_FB6140 = v46 - v47 * *(v44 - 25);
    v46 = dbl_FB6140;
    v48 = v47 * *v44++;
    dbl_FB6208 = dbl_FB6208 - v48;
  }
  while ( (int)v45 < (int)&dword_FB5B9C );
  v49 = &dbl_FB6DB0;
  v50 = &dword_FB5B90;
  do
  {
    v51 = *(double *)(*v50++ + 48);
    dbl_FB6CA0 = dbl_FB6CA0 - v51 * *(v49 - 40);
    dbl_FB6DE0 = dbl_FB6DE0 - v51 * *v49;
    dbl_FB6F20 = dbl_FB6F20 - v51 * v49[40];
    dbl_FB7060 = dbl_FB7060 - v51 * v49[80];
    v52 = v51 * v49[120];
    ++v49;
    dbl_FB71A0 = dbl_FB71A0 - v52;
  }
  while ( (int)v50 < (int)&dword_FB5B9C );
  v53 = (double *)&unk_FB61B0;
  v54 = 1.0 / dbl_FB6140;
  v55 = &dword_FB5BE0;
  dbl_FB6148 = dbl_FB6208 * (1.0 / dbl_FB6140);
  do
  {
    v56 = v54 * *(double *)(*v55++ + 48);
    *v53++ = v56;
  }
  while ( (int)v55 < (int)&dword_FB5BF4 );
  for ( i = 0; i < 24; i += 8 )
  {
    v58 = *(double *)(i + 16472520) * *(double *)(i + 16474384);
    dbl_FB59F8 = dbl_FB59F8 - v58;
  }
  v59 = &dbl_FB61D8;
  v60 = &dword_FB5B90;
  dbl_FB59F8 = dbl_FB59F8 * v54;
  do
  {
    v61 = *(double *)(*v60++ + 56);
    v62 = v61 * *v59++;
    dbl_FB6210 = dbl_FB6210 - v62;
  }
  while ( (int)v60 < (int)&dword_FB5B9C );
  v63 = &dbl_FB6DB0;
  v64 = &dword_FB5B90;
  dbl_FB6210 = dbl_FB6210 - dbl_FB6208 * dbl_FB6148;
  v65 = dbl_FB7068;
  v66 = dbl_FB6F28;
  v67 = dbl_FB6DE8;
  v68 = dbl_FB6CA8;
  do
  {
    v69 = *(double *)(*v64++ + 56);
    dbl_FB6CA8 = v68 - v69 * *(v63 - 40);
    v68 = dbl_FB6CA8;
    dbl_FB6DE8 = v67 - v69 * *v63;
    v67 = dbl_FB6DE8;
    dbl_FB6F28 = v66 - v69 * v63[40];
    v66 = dbl_FB6F28;
    v70 = v65 - v69 * v63[80];
    dbl_FB7068 = v70;
    v65 = v70;
    v71 = v69 * v63[120];
    ++v63;
    dbl_FB71A8 = dbl_FB71A8 - v71;
  }
  while ( (int)v64 < (int)&dword_FB5B9C );
  v72 = (double *)&unk_FB6278;
  v73 = &dword_FB5BE0;
  dbl_FB6CA8 = dbl_FB6CA8 - dbl_FB6148 * dbl_FB6CA0;
  dbl_FB6DE8 = dbl_FB6DE8 - dbl_FB6148 * dbl_FB6DE0;
  dbl_FB6F28 = dbl_FB6F28 - dbl_FB6148 * dbl_FB6F20;
  dbl_FB7068 = v70 - dbl_FB6148 * dbl_FB7060;
  dbl_FB71A8 = dbl_FB71A8 - dbl_FB6148 * dbl_FB71A0;
  v74 = 1.0 / dbl_FB6210;
  do
  {
    v75 = v74 * *(double *)(*v73++ + 56);
    *v72++ = v75;
  }
  while ( (int)v73 < (int)&dword_FB5BF4 );
  for ( j = 0; j < 24; j += 8 )
  {
    v77 = *(double *)(j + 16474584) * *(double *)(j + 16472520);
    dbl_FB5A00 = dbl_FB5A00 - v77;
  }
  v78 = &dbl_FB6378;
  v79 = &dword_FB5B9C;
  dbl_FB5A00 = (dbl_FB5A00 - dbl_FB59F8 * dbl_FB6208) * v74;
  v80 = dbl_FB5A00;
  v81 = dbl_FB62C8;
  do
  {
    v82 = *(double *)(*v79++ + 64);
    dbl_FB62C8 = v81 - v82 * *(v78 - 27);
    v81 = dbl_FB62C8;
    v83 = v82 * *v78++;
    dbl_FB63A0 = dbl_FB63A0 - v83;
  }
  while ( (int)v79 < (int)&dword_FB5BA8 );
  v84 = &dbl_FB73D8;
  v85 = &dword_FB5B9C;
  do
  {
    v86 = *(double *)(*v85++ + 64);
    dbl_FB72D8 = dbl_FB72D8 - v86 * *(v84 - 37);
    dbl_FB7400 = dbl_FB7400 - v86 * *v84;
    dbl_FB7528 = dbl_FB7528 - v86 * v84[37];
    dbl_FB7650 = dbl_FB7650 - v86 * v84[74];
    v87 = v86 * v84[111];
    ++v84;
    dbl_FB7778 = dbl_FB7778 - v87;
  }
  while ( (int)v85 < (int)&dword_FB5BA8 );
  v88 = (double *)&unk_FB6350;
  v89 = 1.0 / dbl_FB62C8;
  v90 = &dword_FB5BF4;
  dbl_FB62D0 = dbl_FB63A0 * (1.0 / dbl_FB62C8);
  do
  {
    v91 = v89 * *(double *)(*v90++ + 64);
    *v88++ = v91;
  }
  while ( (int)v90 < (int)&dword_FB5C08 );
  for ( k = 0; k < 24; k += 8 )
  {
    v93 = *(double *)(k + 16472544) * *(double *)(k + 16474784);
    dbl_FB5A08 = dbl_FB5A08 - v93;
  }
  v94 = &dbl_FB6378;
  v95 = &dword_FB5B9C;
  dbl_FB5A08 = dbl_FB5A08 * v89;
  do
  {
    v96 = *(double *)(*v95++ + 72);
    v97 = v96 * *v94++;
    dbl_FB63A8 = dbl_FB63A8 - v97;
  }
  while ( (int)v95 < (int)&dword_FB5BA8 );
  v98 = &dbl_FB73D8;
  v99 = &dword_FB5B9C;
  dbl_FB63A8 = dbl_FB63A8 - dbl_FB63A0 * dbl_FB62D0;
  v100 = dbl_FB7530;
  v101 = dbl_FB7408;
  v102 = dbl_FB72E0;
  do
  {
    v103 = *(double *)(*v99++ + 72);
    dbl_FB72E0 = v102 - v103 * *(v98 - 37);
    v102 = dbl_FB72E0;
    dbl_FB7408 = v101 - v103 * *v98;
    v101 = dbl_FB7408;
    dbl_FB7530 = v100 - v103 * v98[37];
    v100 = dbl_FB7530;
    dbl_FB7658 = dbl_FB7658 - v103 * v98[74];
    v104 = v103 * v98[111];
    ++v98;
    dbl_FB7780 = dbl_FB7780 - v104;
  }
  while ( (int)v99 < (int)&dword_FB5BA8 );
  v105 = (double *)&unk_FB6428;
  v106 = &dword_FB5BF4;
  dbl_FB72E0 = dbl_FB72E0 - dbl_FB62D0 * dbl_FB72D8;
  dbl_FB7408 = dbl_FB7408 - dbl_FB62D0 * dbl_FB7400;
  dbl_FB7530 = dbl_FB7530 - dbl_FB62D0 * dbl_FB7528;
  dbl_FB7658 = dbl_FB7658 - dbl_FB7650 * dbl_FB62D0;
  dbl_FB7780 = dbl_FB7780 - dbl_FB62D0 * dbl_FB7778;
  v107 = 1.0 / dbl_FB63A8;
  do
  {
    v108 = v107 * *(double *)(*v106++ + 72);
    *v105++ = v108;
  }
  while ( (int)v106 < (int)&dword_FB5C08 );
  for ( m = 0; m < 24; m += 8 )
  {
    v110 = *(double *)(m + 16472544) * *(double *)(m + 16475000);
    dbl_FB5A10 = dbl_FB5A10 - v110;
  }
  v111 = (double *)&unk_FB64F0;
  v112 = &dword_FB5C08;
  dbl_FB5A10 = (dbl_FB5A10 - dbl_FB5A08 * dbl_FB63A0) * v107;
  v113 = dbl_FB5A10;
  v114 = 1.0 / dbl_FB6450;
  dbl_FB6458 = dbl_FB6518 * (1.0 / dbl_FB6450);
  dbl_FB6460 = dbl_FB65E0 * (1.0 / dbl_FB6450);
  dbl_FB6480 = dbl_FB6930 * (1.0 / dbl_FB6450);
  dbl_FB6488 = dbl_FB69F8 * (1.0 / dbl_FB6450);
  do
  {
    v115 = v114 * *(double *)(*v112++ + 80);
    *v111++ = v115;
  }
  while ( (int)v112 < (int)&dword_FB5C1C );
  v116 = (double *)&unk_FB65B8;
  v117 = &dword_FB5C08;
  dbl_FB5A18 = dbl_FB5A18 * v114;
  v118 = dbl_FB5A18;
  dbl_FB6520 = dbl_FB6520 - dbl_FB6518 * dbl_FB6458;
  dbl_FB65E8 = dbl_FB65E8 - dbl_FB65E0 * dbl_FB6458;
  dbl_FB6938 = dbl_FB6938 - dbl_FB6930 * dbl_FB6458;
  dbl_FB6A00 = dbl_FB6A00 - dbl_FB69F8 * dbl_FB6458;
  dbl_FB7880 = dbl_FB7880 - dbl_FB7878 * dbl_FB6458;
  dbl_FB7970 = dbl_FB7970 - dbl_FB7968 * dbl_FB6458;
  dbl_FB7A60 = dbl_FB7A60 - dbl_FB7A58 * dbl_FB6458;
  dbl_FB7B50 = dbl_FB7B50 - dbl_FB7B48 * dbl_FB6458;
  dbl_FB7C40 = dbl_FB7C40 - dbl_FB7C38 * dbl_FB6458;
  v119 = 1.0 / dbl_FB6520;
  dbl_FB6528 = dbl_FB65E8 * (1.0 / dbl_FB6520);
  dbl_FB6548 = dbl_FB6938 * (1.0 / dbl_FB6520);
  dbl_FB6550 = dbl_FB6A00 * (1.0 / dbl_FB6520);
  do
  {
    v120 = v119 * *(double *)(*v117++ + 88);
    *v116++ = v120;
  }
  while ( (int)v117 < (int)&dword_FB5C1C );
  v121 = &dbl_FB69F8;
  v122 = &dword_FB5BB8;
  dbl_FB5A20 = (dbl_FB5A20 - v118 * dbl_FB6518) * v119;
  v123 = dbl_FB65F0 - (dbl_FB6528 * dbl_FB65E8 + dbl_FB6460 * dbl_FB65E0);
  dbl_FB65F0 = v123;
  do
  {
    v124 = *(double *)(*v122++ + 96);
    dbl_FB6940 = dbl_FB6940 - v124 * *(v121 - 25);
    v125 = v124 * *v121++;
    dbl_FB6A08 = dbl_FB6A08 - v125;
  }
  while ( (int)v122 < (int)&dword_FB5BC0 );
  v126 = &dbl_FB7968;
  v127 = &dword_FB5BB8;
  do
  {
    v128 = *(double *)(*v127++ + 96);
    dbl_FB7888 = dbl_FB7888 - v128 * *(v126 - 30);
    dbl_FB7978 = dbl_FB7978 - v128 * *v126;
    dbl_FB7A68 = dbl_FB7A68 - v128 * v126[30];
    dbl_FB7B58 = dbl_FB7B58 - v128 * v126[60];
    v129 = v128 * v126[90];
    ++v126;
    dbl_FB7C48 = dbl_FB7C48 - v129;
  }
  while ( (int)v127 < (int)&dword_FB5BC0 );
  v130 = (double *)&unk_FB6680;
  v131 = 1.0 / v123;
  v132 = &dword_FB5C08;
  dbl_FB6610 = dbl_FB6940 * v131;
  dbl_FB6618 = dbl_FB6A08 * v131;
  do
  {
    v133 = v131 * *(double *)(*v132++ + 96);
    *v130++ = v133;
  }
  while ( (int)v132 < (int)&dword_FB5C1C );
  v134 = (double *)&unk_FB6758;
  v135 = &dword_FB5C1C;
  dbl_FB5A28 = (dbl_FB5A28 - (dbl_FB5A20 * dbl_FB65E8 + v118 * dbl_FB65E0)) * v131;
  v136 = 1.0 / dbl_FB66A8;
  dbl_FB66B0 = dbl_FB6780 * (1.0 / dbl_FB66A8);
  dbl_FB66B8 = dbl_FB6858 * (1.0 / dbl_FB66A8);
  dbl_FB66D0 = dbl_FB6AC0 * (1.0 / dbl_FB66A8);
  dbl_FB66D8 = dbl_FB6B98 * (1.0 / dbl_FB66A8);
  do
  {
    v137 = v136 * *(double *)(*v135++ + 104);
    *v134++ = v137;
  }
  while ( (int)v135 < (int)&dbl_FB5C30 );
  v138 = (double *)&unk_FB6830;
  v139 = &dword_FB5C1C;
  dbl_FB5A30 = dbl_FB5A30 * v136;
  v140 = dbl_FB5A30;
  dbl_FB6788 = dbl_FB6788 - dbl_FB6780 * dbl_FB66B0;
  dbl_FB6860 = dbl_FB6860 - dbl_FB6858 * dbl_FB66B0;
  dbl_FB6AC8 = dbl_FB6AC8 - dbl_FB6AC0 * dbl_FB66B0;
  dbl_FB6BA0 = dbl_FB6BA0 - dbl_FB6B98 * dbl_FB66B0;
  dbl_FB7D30 = dbl_FB7D30 - dbl_FB7D28 * dbl_FB66B0;
  dbl_FB7E08 = dbl_FB7E08 - dbl_FB7E00 * dbl_FB66B0;
  dbl_FB7EE0 = dbl_FB7EE0 - dbl_FB7ED8 * dbl_FB66B0;
  dbl_FB7FB8 = dbl_FB7FB8 - dbl_FB7FB0 * dbl_FB66B0;
  dbl_FB8090 = dbl_FB8090 - dbl_FB8088 * dbl_FB66B0;
  v141 = 1.0 / dbl_FB6788;
  dbl_FB6790 = dbl_FB6860 * (1.0 / dbl_FB6788);
  dbl_FB67A8 = dbl_FB6AC8 * (1.0 / dbl_FB6788);
  dbl_FB67B0 = dbl_FB6BA0 * (1.0 / dbl_FB6788);
  do
  {
    v142 = v141 * *(double *)(*v139++ + 112);
    *v138++ = v142;
  }
  while ( (int)v139 < (int)&dbl_FB5C30 );
  v143 = &dbl_FB6B98;
  v144 = &dword_FB5BC4;
  dbl_FB5A38 = (dbl_FB5A38 - v140 * dbl_FB6780) * v141;
  v145 = dbl_FB6868 - (dbl_FB66B8 * dbl_FB6858 + dbl_FB6790 * dbl_FB6860);
  dbl_FB6868 = v145;
  do
  {
    v146 = *(double *)(*v144++ + 120);
    dbl_FB6AD0 = dbl_FB6AD0 - v146 * *(v143 - 27);
    v147 = v146 * *v143++;
    dbl_FB6BA8 = dbl_FB6BA8 - v147;
  }
  while ( (int)v144 < (int)&dword_FB5BCC );
  v148 = &dbl_FB7E00;
  v149 = &dword_FB5BC4;
  do
  {
    v150 = *(double *)(*v149++ + 120);
    dbl_FB7D38 = dbl_FB7D38 - v150 * *(v148 - 27);
    dbl_FB7E10 = dbl_FB7E10 - v150 * *v148;
    dbl_FB7EE8 = dbl_FB7EE8 - v150 * v148[27];
    dbl_FB7FC0 = dbl_FB7FC0 - v150 * v148[54];
    v151 = v150 * v148[81];
    ++v148;
    dbl_FB8098 = dbl_FB8098 - v151;
  }
  while ( (int)v149 < (int)&dword_FB5BCC );
  v152 = (double *)&unk_FB6908;
  v153 = 1.0 / v145;
  v154 = &dword_FB5C1C;
  dbl_FB6880 = dbl_FB6AD0 * v153;
  dbl_FB6888 = dbl_FB6BA8 * v153;
  do
  {
    v155 = v153 * *(double *)(*v154++ + 120);
    *v152++ = v155;
  }
  while ( (int)v154 < (int)&dbl_FB5C30 );
  v156 = &dbl_FB69F8;
  v157 = &dword_FB5BB8;
  dbl_FB5A40 = (dbl_FB5A40 - (v140 * dbl_FB6858 + dbl_FB5A38 * dbl_FB6860)) * v153;
  v158 = dbl_FB6960;
  do
  {
    v159 = *(double *)(*v157++ + 128);
    dbl_FB6960 = v158 - v159 * *(v156 - 25);
    v158 = dbl_FB6960;
    v160 = v159 * *v156++;
    dbl_FB6A28 = dbl_FB6A28 - v160;
  }
  while ( (int)v157 < (int)&dword_FB5BC4 );
  v161 = &dbl_FB7968;
  v162 = &dword_FB5BB8;
  do
  {
    v163 = *(double *)(*v162++ + 128);
    dbl_FB78A8 = dbl_FB78A8 - v163 * *(v161 - 30);
    dbl_FB7998 = dbl_FB7998 - v163 * *v161;
    dbl_FB7A88 = dbl_FB7A88 - v163 * v161[30];
    dbl_FB7B78 = dbl_FB7B78 - v163 * v161[60];
    v164 = v163 * v161[90];
    ++v161;
    dbl_FB7C68 = dbl_FB7C68 - v164;
  }
  while ( (int)v162 < (int)&dword_FB5BC4 );
  v165 = (double *)&unk_FB69D0;
  v166 = 1.0 / dbl_FB6960;
  v167 = &dword_FB5C08;
  dbl_FB6968 = dbl_FB6A28 * (1.0 / dbl_FB6960);
  do
  {
    v168 = v166 * *(double *)(*v167++ + 128);
    *v165++ = v168;
  }
  while ( (int)v167 < (int)&dword_FB5C1C );
  for ( n = 0; n < 24; n += 8 )
  {
    v170 = *(double *)(n + 16472600) * *(double *)(n + 16476464);
    dbl_FB5A48 = dbl_FB5A48 - v170;
  }
  v171 = &dbl_FB69F8;
  v172 = &dword_FB5BB8;
  dbl_FB5A48 = dbl_FB5A48 * v166;
  do
  {
    v173 = *(double *)(*v172++ + 136);
    v174 = v173 * *v171++;
    dbl_FB6A30 = dbl_FB6A30 - v174;
  }
  while ( (int)v172 < (int)&dword_FB5BC4 );
  v175 = &dbl_FB7968;
  v176 = &dword_FB5BB8;
  dbl_FB6A30 = dbl_FB6A30 - dbl_FB6A28 * dbl_FB6968;
  v177 = dbl_FB78B0;
  do
  {
    v178 = *(double *)(*v176++ + 136);
    dbl_FB78B0 = v177 - v178 * *(v175 - 30);
    v177 = dbl_FB78B0;
    dbl_FB79A0 = dbl_FB79A0 - v178 * *v175;
    dbl_FB7A90 = dbl_FB7A90 - v178 * v175[30];
    dbl_FB7B80 = dbl_FB7B80 - v178 * v175[60];
    v179 = v178 * v175[90];
    ++v175;
    dbl_FB7C70 = dbl_FB7C70 - v179;
  }
  while ( (int)v176 < (int)&dword_FB5BC4 );
  v180 = (double *)&unk_FB6A98;
  v181 = &dword_FB5C08;
  dbl_FB78B0 = dbl_FB78B0 - dbl_FB6968 * dbl_FB78A8;
  dbl_FB79A0 = dbl_FB79A0 - dbl_FB7998 * dbl_FB6968;
  dbl_FB7A90 = dbl_FB7A90 - dbl_FB7A88 * dbl_FB6968;
  dbl_FB7B80 = dbl_FB7B80 - dbl_FB7B78 * dbl_FB6968;
  dbl_FB7C70 = dbl_FB7C70 - dbl_FB6968 * dbl_FB7C68;
  v182 = 1.0 / dbl_FB6A30;
  do
  {
    v183 = v182 * *(double *)(*v181++ + 136);
    *v180++ = v183;
  }
  while ( (int)v181 < (int)&dword_FB5C1C );
  for ( ii = 0; ii < 24; ii += 8 )
  {
    v185 = *(double *)(ii + 16472600) * *(double *)(ii + 16476664);
    dbl_FB5A50 = dbl_FB5A50 - v185;
  }
  v186 = &dbl_FB6B98;
  v187 = &dword_FB5BC4;
  dbl_FB5A50 = (dbl_FB5A50 - dbl_FB5A48 * dbl_FB6A28) * v182;
  v188 = dbl_FB5A50;
  v189 = dbl_FB6AE8;
  do
  {
    v190 = *(double *)(*v187++ + 144);
    dbl_FB6AE8 = v189 - v190 * *(v186 - 27);
    v189 = dbl_FB6AE8;
    v191 = v190 * *v186++;
    dbl_FB6BC0 = dbl_FB6BC0 - v191;
  }
  while ( (int)v187 < (int)&dword_FB5BD0 );
  v192 = &dbl_FB7E00;
  v193 = &dword_FB5BC4;
  do
  {
    v194 = *(double *)(*v193++ + 144);
    dbl_FB7D50 = dbl_FB7D50 - v194 * *(v192 - 27);
    dbl_FB7E28 = dbl_FB7E28 - v194 * *v192;
    dbl_FB7F00 = dbl_FB7F00 - v194 * v192[27];
    dbl_FB7FD8 = dbl_FB7FD8 - v194 * v192[54];
    v195 = v194 * v192[81];
    ++v192;
    dbl_FB80B0 = dbl_FB80B0 - v195;
  }
  while ( (int)v193 < (int)&dword_FB5BD0 );
  v196 = (double *)&unk_FB6B70;
  v197 = 1.0 / dbl_FB6AE8;
  v198 = &dword_FB5C1C;
  dbl_FB6AF0 = dbl_FB6BC0 * (1.0 / dbl_FB6AE8);
  do
  {
    v199 = v197 * *(double *)(*v198++ + 144);
    *v196++ = v199;
  }
  while ( (int)v198 < (int)&dbl_FB5C30 );
  for ( jj = 0; jj < 24; jj += 8 )
  {
    v201 = *(double *)(jj + 16472624) * *(double *)(jj + 16476864);
    dbl_FB5A58 = dbl_FB5A58 - v201;
  }
  v202 = &dbl_FB6B98;
  v203 = &dword_FB5BC4;
  dbl_FB5A58 = dbl_FB5A58 * v197;
  do
  {
    v204 = *(double *)(*v203++ + 152);
    v205 = v204 * *v202++;
    dbl_FB6BC8 = dbl_FB6BC8 - v205;
  }
  while ( (int)v203 < (int)&dword_FB5BD0 );
  v206 = &dbl_FB7E00;
  v207 = &dword_FB5BC4;
  dbl_FB6BC8 = dbl_FB6BC8 - dbl_FB6BC0 * dbl_FB6AF0;
  do
  {
    v208 = *(double *)(*v207++ + 152);
    dbl_FB7D58 = dbl_FB7D58 - v208 * *(v206 - 27);
    dbl_FB7E30 = dbl_FB7E30 - v208 * *v206;
    dbl_FB7F08 = dbl_FB7F08 - v208 * v206[27];
    dbl_FB7FE0 = dbl_FB7FE0 - v208 * v206[54];
    v209 = v208 * v206[81];
    ++v206;
    dbl_FB80B8 = dbl_FB80B8 - v209;
  }
  while ( (int)v207 < (int)&dword_FB5BD0 );
  v210 = (double *)&unk_FB6C48;
  v211 = &dword_FB5C1C;
  dbl_FB7D58 = dbl_FB7D58 - dbl_FB7D50 * dbl_FB6AF0;
  dbl_FB7E30 = dbl_FB7E30 - dbl_FB7E28 * dbl_FB6AF0;
  dbl_FB7F08 = dbl_FB7F08 - dbl_FB7F00 * dbl_FB6AF0;
  dbl_FB7FE0 = dbl_FB7FE0 - dbl_FB7FD8 * dbl_FB6AF0;
  dbl_FB80B8 = dbl_FB80B8 - dbl_FB6AF0 * dbl_FB80B0;
  v212 = 1.0 / dbl_FB6BC8;
  do
  {
    v213 = v212 * *(double *)(*v211++ + 152);
    *v210++ = v213;
  }
  while ( (int)v211 < (int)&dbl_FB5C30 );
  for ( kk = 0; kk < 24; kk += 8 )
  {
    v215 = *(double *)(kk + 16472624) * *(double *)(kk + 16477080);
    dbl_FB5A60 = dbl_FB5A60 - v215;
  }
  v216 = &dbl_FB6DB0;
  v217 = &dword_FB5B90;
  dbl_FB5A60 = (dbl_FB5A60 - dbl_FB5A58 * dbl_FB6BC0) * v212;
  v218 = dbl_FB6D10;
  do
  {
    v219 = *(double *)(*v217++ + 160);
    dbl_FB6D10 = v218 - v219 * *(v216 - 40);
    v218 = dbl_FB6D10;
    dbl_FB6E50 = dbl_FB6E50 - v219 * *v216;
    dbl_FB6F90 = dbl_FB6F90 - v219 * v216[40];
    dbl_FB70D0 = dbl_FB70D0 - v219 * v216[80];
    v220 = v219 * v216[120];
    ++v216;
    dbl_FB7210 = dbl_FB7210 - v220;
  }
  while ( (int)v217 < (int)&dword_FB5B9C );
  v221 = &dbl_FB6DE0;
  v222 = &dword_FB5BA8;
  do
  {
    v223 = *(double *)(*v222++ + 160);
    dbl_FB6D10 = v218 - v223 * *(v221 - 40);
    v218 = dbl_FB6D10;
    dbl_FB6E50 = dbl_FB6E50 - v223 * *v221;
    dbl_FB6F90 = dbl_FB6F90 - v223 * v221[40];
    dbl_FB70D0 = dbl_FB70D0 - v223 * v221[80];
    v224 = v223 * v221[120];
    ++v221;
    dbl_FB7210 = dbl_FB7210 - v224;
  }
  while ( (int)v222 < (int)&dword_FB5BB0 );
  v225 = &dbl_FB6D18;
  v226 = &dword_FB5BE4;
  v719 = 1.0 / dbl_FB6D10;
  do
  {
    v227 = v719 * *(double *)(*v226++ + 160);
    *v225++ = v227;
  }
  while ( (int)v226 < (int)&dbl_FB5C30 );
  for ( mm = 0; mm < 24; mm += 8 )
  {
    v229 = *(double *)(mm + 16472520) * *(double *)(mm + 16477296);
    dbl_FB5A68 = dbl_FB5A68 - v229;
  }
  v230 = dbl_FB59F8;
  v231 = &dbl_FB6EF0;
  v232 = &dword_FB5B90;
  dbl_FB5A68 = (dbl_FB5A68 - (v80 * dbl_FB6CA8 + dbl_FB59F8 * dbl_FB6CA0)) * v719;
  do
  {
    v233 = *(double *)(*v232++ + 168);
    dbl_FB6E58 = dbl_FB6E58 - v233 * *(v231 - 40);
    dbl_FB6F98 = dbl_FB6F98 - v233 * *v231;
    dbl_FB70D8 = dbl_FB70D8 - v233 * v231[40];
    v234 = v233 * v231[80];
    ++v231;
    dbl_FB7218 = dbl_FB7218 - v234;
  }
  while ( (int)v232 < (int)&dword_FB5B9C );
  v235 = &dbl_FB6F20;
  v236 = &dword_FB5BA8;
  do
  {
    v237 = *(double *)(*v236++ + 168);
    dbl_FB6E58 = dbl_FB6E58 - v237 * *(v235 - 40);
    dbl_FB6F98 = dbl_FB6F98 - v237 * *v235;
    dbl_FB70D8 = dbl_FB70D8 - v237 * v235[40];
    v238 = v237 * v235[80];
    ++v235;
    dbl_FB7218 = dbl_FB7218 - v238;
  }
  while ( (int)v236 < (int)&dword_FB5BB0 );
  dbl_FB6E58 = dbl_FB6E58 - dbl_FB6E50 * dbl_FB6D18;
  dbl_FB6F98 = dbl_FB6F98 - dbl_FB6F90 * dbl_FB6D18;
  dbl_FB70D8 = dbl_FB70D8 - dbl_FB70D0 * dbl_FB6D18;
  dbl_FB7218 = dbl_FB7218 - dbl_FB7210 * dbl_FB6D18;
  dbl_FB7340 = dbl_FB7340 - dbl_FB7338 * dbl_FB6D18;
  dbl_FB7468 = dbl_FB7468 - dbl_FB7460 * dbl_FB6D18;
  dbl_FB7590 = dbl_FB7590 - dbl_FB7588 * dbl_FB6D18;
  dbl_FB76B8 = dbl_FB76B8 - dbl_FB76B0 * dbl_FB6D18;
  dbl_FB77E0 = dbl_FB77E0 - dbl_FB77D8 * dbl_FB6D18;
  dbl_FB78D0 = dbl_FB78D0 - dbl_FB78C8 * dbl_FB6D18;
  dbl_FB79C0 = dbl_FB79C0 - dbl_FB79B8 * dbl_FB6D18;
  dbl_FB7AB0 = dbl_FB7AB0 - dbl_FB7AA8 * dbl_FB6D18;
  dbl_FB7BA0 = dbl_FB7BA0 - dbl_FB7B98 * dbl_FB6D18;
  v239 = (double *)&unk_FB6E60;
  dbl_FB7C90 = dbl_FB7C90 - dbl_FB7C88 * dbl_FB6D18;
  v240 = &dword_FB5BE8;
  dbl_FB7D68 = dbl_FB7D68 - dbl_FB7D60 * dbl_FB6D18;
  dbl_FB7E40 = dbl_FB7E40 - dbl_FB7E38 * dbl_FB6D18;
  dbl_FB7F18 = dbl_FB7F18 - dbl_FB7F10 * dbl_FB6D18;
  dbl_FB7FF0 = dbl_FB7FF0 - dbl_FB7FE8 * dbl_FB6D18;
  dbl_FB80C8 = dbl_FB80C8 - dbl_FB80C0 * dbl_FB6D18;
  v720 = 1.0 / dbl_FB6E58;
  do
  {
    v241 = v720 * *(double *)(*v240++ + 168);
    *v239++ = v241;
  }
  while ( (int)v240 < (int)&dbl_FB5C30 );
  for ( nn = 0; nn < 24; nn += 8 )
  {
    v243 = *(double *)(nn + 16477616) * *(double *)(nn + 16472520);
    dbl_FB5A70 = dbl_FB5A70 - v243;
  }
  v244 = &dbl_FB7030;
  v245 = &dword_FB5B90;
  dbl_FB5A70 = (dbl_FB5A70 - (v80 * dbl_FB6DE8 + v230 * dbl_FB6DE0 + dbl_FB5A68 * dbl_FB6E50)) * v720;
  do
  {
    v246 = *(double *)(*v245++ + 176);
    dbl_FB6FA0 = dbl_FB6FA0 - v246 * *(v244 - 40);
    dbl_FB70E0 = dbl_FB70E0 - v246 * *v244;
    v247 = v246 * v244[40];
    ++v244;
    dbl_FB7220 = dbl_FB7220 - v247;
  }
  while ( (int)v245 < (int)&dword_FB5B9C );
  v248 = &dbl_FB7060;
  v249 = &dword_FB5BA8;
  do
  {
    v250 = *(double *)(*v249++ + 176);
    dbl_FB6FA0 = dbl_FB6FA0 - v250 * *(v248 - 40);
    dbl_FB70E0 = dbl_FB70E0 - v250 * *v248;
    v251 = v250 * v248[40];
    ++v248;
    dbl_FB7220 = dbl_FB7220 - v251;
  }
  while ( (int)v249 < (int)&dword_FB5BB0 );
  v252 = &dbl_FB70D0;
  v253 = &dword_FB5BE0;
  do
  {
    v254 = *(double *)(*v253++ + 176);
    dbl_FB6FA0 = dbl_FB6FA0 - v254 * *(v252 - 40);
    dbl_FB70E0 = dbl_FB70E0 - v254 * *v252;
    v255 = v254 * v252[40];
    ++v252;
    dbl_FB7220 = dbl_FB7220 - v255;
  }
  while ( (int)v253 < (int)&dword_FB5BE8 );
  v256 = &dbl_FB7460;
  v257 = &dword_FB5BE0;
  do
  {
    v258 = *(double *)(*v257++ + 176);
    dbl_FB7348 = dbl_FB7348 - v258 * *(v256 - 37);
    dbl_FB7470 = dbl_FB7470 - v258 * *v256;
    dbl_FB7598 = dbl_FB7598 - v258 * v256[37];
    dbl_FB76C0 = dbl_FB76C0 - v258 * v256[74];
    dbl_FB77E8 = dbl_FB77E8 - v258 * v256[111];
    dbl_FB78D8 = dbl_FB78D8 - v258 * v256[141];
    dbl_FB79C8 = dbl_FB79C8 - v258 * v256[171];
    dbl_FB7AB8 = dbl_FB7AB8 - v258 * v256[201];
    dbl_FB7BA8 = dbl_FB7BA8 - v258 * v256[231];
    dbl_FB7C98 = dbl_FB7C98 - v258 * v256[261];
    dbl_FB7D70 = dbl_FB7D70 - v258 * v256[288];
    dbl_FB7E48 = dbl_FB7E48 - v258 * v256[315];
    dbl_FB7F20 = dbl_FB7F20 - v258 * v256[342];
    dbl_FB7FF8 = dbl_FB7FF8 - v258 * v256[369];
    v259 = v258 * v256[396];
    ++v256;
    dbl_FB80D0 = dbl_FB80D0 - v259;
  }
  while ( (int)v257 < (int)&dword_FB5BE8 );
  v260 = (double *)&unk_FB6FA8;
  v261 = &dword_FB5BEC;
  v721 = 1.0 / dbl_FB6FA0;
  do
  {
    v262 = v721 * *(double *)(*v261++ + 176);
    *v260++ = v262;
  }
  while ( (int)v261 < (int)&dbl_FB5C30 );
  for ( i1 = 0; i1 < 24; i1 += 8 )
  {
    v264 = *(double *)(i1 + 16477936) * *(double *)(i1 + 16472520);
    dbl_FB5A78 = dbl_FB5A78 - v264;
  }
  v265 = &dbl_FB7170;
  v266 = &dword_FB5B90;
  dbl_FB5A78 = (dbl_FB5A78 - (v80 * dbl_FB6F28 + v230 * dbl_FB6F20 + dbl_FB5A70 * dbl_FB6F98 + dbl_FB5A68 * dbl_FB6F90))
             * v721;
  v267 = dbl_FB70E8;
  do
  {
    v268 = *(double *)(*v266++ + 184);
    dbl_FB70E8 = v267 - v268 * *(v265 - 40);
    v267 = dbl_FB70E8;
    v269 = v268 * *v265++;
    dbl_FB7228 = dbl_FB7228 - v269;
  }
  while ( (int)v266 < (int)&dword_FB5B9C );
  v270 = &dbl_FB71A0;
  v271 = &dword_FB5BA8;
  do
  {
    v272 = *(double *)(*v271++ + 184);
    dbl_FB70E8 = v267 - v272 * *(v270 - 40);
    v267 = dbl_FB70E8;
    v273 = v272 * *v270++;
    dbl_FB7228 = dbl_FB7228 - v273;
  }
  while ( (int)v271 < (int)&dword_FB5BB0 );
  v274 = &dbl_FB7210;
  v275 = &dword_FB5BE0;
  do
  {
    v276 = *(double *)(*v275++ + 184);
    dbl_FB70E8 = v267 - v276 * *(v274 - 40);
    v267 = dbl_FB70E8;
    v277 = v276 * *v274++;
    dbl_FB7228 = dbl_FB7228 - v277;
  }
  while ( (int)v275 < (int)&dword_FB5BEC );
  v278 = &dbl_FB7460;
  v279 = &dword_FB5BE0;
  do
  {
    v280 = *(double *)(*v279++ + 184);
    dbl_FB7350 = dbl_FB7350 - v280 * *(v278 - 37);
    dbl_FB7478 = dbl_FB7478 - v280 * *v278;
    dbl_FB75A0 = dbl_FB75A0 - v280 * v278[37];
    dbl_FB76C8 = dbl_FB76C8 - v280 * v278[74];
    dbl_FB77F0 = dbl_FB77F0 - v280 * v278[111];
    dbl_FB78E0 = dbl_FB78E0 - v280 * v278[141];
    dbl_FB79D0 = dbl_FB79D0 - v280 * v278[171];
    dbl_FB7AC0 = dbl_FB7AC0 - v280 * v278[201];
    dbl_FB7BB0 = dbl_FB7BB0 - v280 * v278[231];
    dbl_FB7CA0 = dbl_FB7CA0 - v280 * v278[261];
    dbl_FB7D78 = dbl_FB7D78 - v280 * v278[288];
    dbl_FB7E50 = dbl_FB7E50 - v280 * v278[315];
    dbl_FB7F28 = dbl_FB7F28 - v280 * v278[342];
    dbl_FB8000 = dbl_FB8000 - v280 * v278[369];
    v281 = v280 * v278[396];
    ++v278;
    dbl_FB80D8 = dbl_FB80D8 - v281;
  }
  while ( (int)v279 < (int)&dword_FB5BEC );
  v282 = (double *)&unk_FB70F0;
  v283 = &dword_FB5BF0;
  v722 = 1.0 / dbl_FB70E8;
  do
  {
    v284 = v722 * *(double *)(*v283++ + 184);
    *v282++ = v284;
  }
  while ( (int)v283 < (int)&dbl_FB5C30 );
  v285 = dbl_FB5A80;
  for ( i2 = 0; i2 < 24; i2 += 8 )
  {
    v287 = *(double *)(i2 + 16478256) * *(double *)(i2 + 16472520);
    dbl_FB5A80 = v285 - v287;
    v285 = dbl_FB5A80;
  }
  for ( i3 = 0; i3 < 24; i3 += 8 )
  {
    v289 = *(double *)(i3 + 16478416) * *(double *)(i3 + 16472680);
    dbl_FB5A80 = v285 - v289;
    v285 = dbl_FB5A80;
  }
  v290 = &dbl_FB7170;
  v291 = &dword_FB5B90;
  dbl_FB5A80 = (dbl_FB5A80 - (v80 * dbl_FB7068 + v230 * dbl_FB7060)) * v722;
  v292 = dbl_FB7230;
  do
  {
    v293 = *(double *)(*v291++ + 192);
    v294 = v293 * *v290++;
    dbl_FB7230 = v292 - v294;
    v292 = dbl_FB7230;
  }
  while ( (int)v291 < (int)&dword_FB5B9C );
  v295 = &dbl_FB7210;
  v296 = &dword_FB5BE0;
  do
  {
    v297 = *(double *)(*v296++ + 192);
    v298 = v297 * *v295++;
    dbl_FB7230 = v292 - v298;
    v292 = dbl_FB7230;
  }
  while ( (int)v296 < (int)&dword_FB5BF0 );
  v299 = &dbl_FB7460;
  v300 = &dword_FB5BE0;
  dbl_FB7230 = dbl_FB7230 - (dbl_FB6298 * dbl_FB71A8 + dbl_FB61D0 * dbl_FB71A0);
  do
  {
    v301 = *(double *)(*v300++ + 192);
    dbl_FB7358 = dbl_FB7358 - v301 * *(v299 - 37);
    dbl_FB7480 = dbl_FB7480 - v301 * *v299;
    dbl_FB75A8 = dbl_FB75A8 - v301 * v299[37];
    dbl_FB76D0 = dbl_FB76D0 - v301 * v299[74];
    dbl_FB77F8 = dbl_FB77F8 - v301 * v299[111];
    dbl_FB78E8 = dbl_FB78E8 - v301 * v299[141];
    dbl_FB79D8 = dbl_FB79D8 - v301 * v299[171];
    dbl_FB7AC8 = dbl_FB7AC8 - v301 * v299[201];
    dbl_FB7BB8 = dbl_FB7BB8 - v301 * v299[231];
    dbl_FB7CA8 = dbl_FB7CA8 - v301 * v299[261];
    dbl_FB7D80 = dbl_FB7D80 - v301 * v299[288];
    dbl_FB7E58 = dbl_FB7E58 - v301 * v299[315];
    dbl_FB7F30 = dbl_FB7F30 - v301 * v299[342];
    dbl_FB8008 = dbl_FB8008 - v301 * v299[369];
    v302 = v301 * v299[396];
    ++v299;
    dbl_FB80E0 = dbl_FB80E0 - v302;
  }
  while ( (int)v300 < (int)&dword_FB5BF0 );
  v303 = (double *)&unk_FB7238;
  v304 = &dword_FB5BF4;
  v723 = 1.0 / dbl_FB7230;
  do
  {
    v305 = v723 * *(double *)(*v304++ + 192);
    *v303++ = v305;
  }
  while ( (int)v304 < (int)&dbl_FB5C30 );
  v306 = dbl_FB5A88;
  for ( i4 = 0; i4 < 24; i4 += 8 )
  {
    v308 = *(double *)(i4 + 16478576) * *(double *)(i4 + 16472520);
    dbl_FB5A88 = v306 - v308;
    v306 = dbl_FB5A88;
  }
  for ( i5 = 0; i5 < 32; i5 += 8 )
  {
    v310 = *(double *)(i5 + 16472680) * *(double *)(i5 + 16478736);
    dbl_FB5A88 = v306 - v310;
    v306 = dbl_FB5A88;
  }
  v311 = &dbl_FB73D8;
  v312 = &dword_FB5B9C;
  dbl_FB5A88 = (dbl_FB5A88 - (v80 * dbl_FB71A8 + v230 * dbl_FB71A0)) * v723;
  v313 = dbl_FB7360;
  do
  {
    v314 = *(double *)(*v312++ + 200);
    dbl_FB7360 = v313 - v314 * *(v311 - 37);
    v313 = dbl_FB7360;
    dbl_FB7488 = dbl_FB7488 - v314 * *v311;
    dbl_FB75B0 = dbl_FB75B0 - v314 * v311[37];
    dbl_FB76D8 = dbl_FB76D8 - v314 * v311[74];
    v315 = v314 * v311[111];
    ++v311;
    dbl_FB7800 = dbl_FB7800 - v315;
  }
  while ( (int)v312 < (int)&dword_FB5BA8 );
  v316 = &dbl_FB7400;
  v317 = &dword_FB5BB0;
  do
  {
    v318 = *(double *)(*v317++ + 200);
    dbl_FB7360 = v313 - v318 * *(v316 - 37);
    v313 = dbl_FB7360;
    dbl_FB7488 = dbl_FB7488 - v318 * *v316;
    dbl_FB75B0 = dbl_FB75B0 - v318 * v316[37];
    dbl_FB76D8 = dbl_FB76D8 - v318 * v316[74];
    v319 = v318 * v316[111];
    ++v316;
    dbl_FB7800 = dbl_FB7800 - v319;
  }
  while ( (int)v317 < (int)&dword_FB5BB8 );
  v320 = &dbl_FB7460;
  v321 = &dword_FB5BE0;
  do
  {
    v322 = *(double *)(*v321++ + 200);
    dbl_FB7360 = v313 - v322 * *(v320 - 37);
    v313 = dbl_FB7360;
    dbl_FB7488 = dbl_FB7488 - v322 * *v320;
    dbl_FB75B0 = dbl_FB75B0 - v322 * v320[37];
    dbl_FB76D8 = dbl_FB76D8 - v322 * v320[74];
    v323 = v322 * v320[111];
    ++v320;
    dbl_FB7800 = dbl_FB7800 - v323;
  }
  while ( (int)v321 < (int)&dword_FB5BF4 );
  v324 = &dbl_FB79B8;
  v325 = &dword_FB5BE0;
  do
  {
    v326 = *(double *)(*v325++ + 200);
    dbl_FB78F0 = dbl_FB78F0 - v326 * *(v324 - 30);
    dbl_FB79E0 = dbl_FB79E0 - v326 * *v324;
    dbl_FB7AD0 = dbl_FB7AD0 - v326 * v324[30];
    dbl_FB7BC0 = dbl_FB7BC0 - v326 * v324[60];
    dbl_FB7CB0 = dbl_FB7CB0 - v326 * v324[90];
    dbl_FB7D88 = dbl_FB7D88 - v326 * v324[117];
    dbl_FB7E60 = dbl_FB7E60 - v326 * v324[144];
    dbl_FB7F38 = dbl_FB7F38 - v326 * v324[171];
    dbl_FB8010 = dbl_FB8010 - v326 * v324[198];
    v327 = v326 * v324[225];
    ++v324;
    dbl_FB80E8 = dbl_FB80E8 - v327;
  }
  while ( (int)v325 < (int)&dword_FB5BF4 );
  v328 = (double *)&unk_FB7368;
  v329 = &dword_FB5BF8;
  v724 = 1.0 / dbl_FB7360;
  do
  {
    v330 = v724 * *(double *)(*v329++ + 200);
    *v328++ = v330;
  }
  while ( (int)v329 < (int)&dbl_FB5C30 );
  v331 = dbl_FB5A90;
  for ( i6 = 0; i6 < 24; i6 += 8 )
  {
    v333 = *(double *)(i6 + 16472544) * *(double *)(i6 + 16478896);
    dbl_FB5A90 = v331 - v333;
    v331 = dbl_FB5A90;
  }
  for ( i7 = 0; i7 < 40; i7 += 8 )
  {
    v335 = *(double *)(i7 + 16472680) * *(double *)(i7 + 16479032);
    dbl_FB5A90 = v331 - v335;
    v331 = dbl_FB5A90;
  }
  v336 = &dbl_FB7500;
  v337 = dbl_FB5A08;
  v338 = &dword_FB5B9C;
  dbl_FB5A90 = (dbl_FB5A90 - (v113 * dbl_FB72E0 + dbl_FB5A08 * dbl_FB72D8)) * v724;
  do
  {
    v339 = *(double *)(*v338++ + 208);
    dbl_FB7490 = dbl_FB7490 - v339 * *(v336 - 37);
    dbl_FB75B8 = dbl_FB75B8 - v339 * *v336;
    dbl_FB76E0 = dbl_FB76E0 - v339 * v336[37];
    v340 = v339 * v336[74];
    ++v336;
    dbl_FB7808 = dbl_FB7808 - v340;
  }
  while ( (int)v338 < (int)&dword_FB5BA8 );
  v341 = &dbl_FB7528;
  v342 = &dword_FB5BB0;
  do
  {
    v343 = *(double *)(*v342++ + 208);
    dbl_FB7490 = dbl_FB7490 - v343 * *(v341 - 37);
    dbl_FB75B8 = dbl_FB75B8 - v343 * *v341;
    dbl_FB76E0 = dbl_FB76E0 - v343 * v341[37];
    v344 = v343 * v341[74];
    ++v341;
    dbl_FB7808 = dbl_FB7808 - v344;
  }
  while ( (int)v342 < (int)&dword_FB5BB8 );
  v345 = &dbl_FB7588;
  v346 = &dword_FB5BE0;
  do
  {
    v347 = *(double *)(*v346++ + 208);
    dbl_FB7490 = dbl_FB7490 - v347 * *(v345 - 37);
    dbl_FB75B8 = dbl_FB75B8 - v347 * *v345;
    dbl_FB76E0 = dbl_FB76E0 - v347 * v345[37];
    v348 = v347 * v345[74];
    ++v345;
    dbl_FB7808 = dbl_FB7808 - v348;
  }
  while ( (int)v346 < (int)&dword_FB5BF8 );
  v349 = &dbl_FB79B8;
  v350 = &dword_FB5BE0;
  do
  {
    v351 = *(double *)(*v350++ + 208);
    dbl_FB78F8 = dbl_FB78F8 - v351 * *(v349 - 30);
    dbl_FB79E8 = dbl_FB79E8 - v351 * *v349;
    dbl_FB7AD8 = dbl_FB7AD8 - v351 * v349[30];
    dbl_FB7BC8 = dbl_FB7BC8 - v351 * v349[60];
    dbl_FB7CB8 = dbl_FB7CB8 - v351 * v349[90];
    dbl_FB7D90 = dbl_FB7D90 - v351 * v349[117];
    dbl_FB7E68 = dbl_FB7E68 - v351 * v349[144];
    dbl_FB7F40 = dbl_FB7F40 - v351 * v349[171];
    dbl_FB8018 = dbl_FB8018 - v351 * v349[198];
    v352 = v351 * v349[225];
    ++v349;
    dbl_FB80F0 = dbl_FB80F0 - v352;
  }
  while ( (int)v350 < (int)&dword_FB5BF8 );
  v353 = (double *)&unk_FB7498;
  v354 = &dword_FB5BFC;
  v725 = 1.0 / dbl_FB7490;
  do
  {
    v355 = v725 * *(double *)(*v354++ + 208);
    *v353++ = v355;
  }
  while ( (int)v354 < (int)&dbl_FB5C30 );
  v356 = dbl_FB5A98;
  for ( i8 = 0; i8 < 24; i8 += 8 )
  {
    v358 = *(double *)(i8 + 16472544) * *(double *)(i8 + 16479192);
    dbl_FB5A98 = v356 - v358;
    v356 = dbl_FB5A98;
  }
  for ( i9 = 0; i9 < 48; i9 += 8 )
  {
    v360 = *(double *)(i9 + 16472680) * *(double *)(i9 + 16479328);
    dbl_FB5A98 = v356 - v360;
    v356 = dbl_FB5A98;
  }
  v361 = &dbl_FB7628;
  v362 = &dword_FB5B9C;
  dbl_FB5A98 = (dbl_FB5A98 - (v113 * dbl_FB7408 + v337 * dbl_FB7400)) * v725;
  do
  {
    v363 = *(double *)(*v362++ + 216);
    dbl_FB75C0 = dbl_FB75C0 - v363 * *(v361 - 37);
    dbl_FB76E8 = dbl_FB76E8 - v363 * *v361;
    v364 = v363 * v361[37];
    ++v361;
    dbl_FB7810 = dbl_FB7810 - v364;
  }
  while ( (int)v362 < (int)&dword_FB5BA8 );
  v365 = &dbl_FB7650;
  v366 = &dword_FB5BB0;
  do
  {
    v367 = *(double *)(*v366++ + 216);
    dbl_FB75C0 = dbl_FB75C0 - v367 * *(v365 - 37);
    dbl_FB76E8 = dbl_FB76E8 - v367 * *v365;
    v368 = v367 * v365[37];
    ++v365;
    dbl_FB7810 = dbl_FB7810 - v368;
  }
  while ( (int)v366 < (int)&dword_FB5BB8 );
  v369 = &dbl_FB76B0;
  v370 = &dword_FB5BE0;
  do
  {
    v371 = *(double *)(*v370++ + 216);
    dbl_FB75C0 = dbl_FB75C0 - v371 * *(v369 - 37);
    dbl_FB76E8 = dbl_FB76E8 - v371 * *v369;
    v372 = v371 * v369[37];
    ++v369;
    dbl_FB7810 = dbl_FB7810 - v372;
  }
  while ( (int)v370 < (int)&dword_FB5BFC );
  v373 = &dbl_FB79B8;
  v374 = &dword_FB5BE0;
  do
  {
    v375 = *(double *)(*v374++ + 216);
    dbl_FB7900 = dbl_FB7900 - v375 * *(v373 - 30);
    dbl_FB79F0 = dbl_FB79F0 - v375 * *v373;
    dbl_FB7AE0 = dbl_FB7AE0 - v375 * v373[30];
    dbl_FB7BD0 = dbl_FB7BD0 - v375 * v373[60];
    dbl_FB7CC0 = dbl_FB7CC0 - v375 * v373[90];
    dbl_FB7D98 = dbl_FB7D98 - v375 * v373[117];
    dbl_FB7E70 = dbl_FB7E70 - v375 * v373[144];
    dbl_FB7F48 = dbl_FB7F48 - v375 * v373[171];
    dbl_FB8020 = dbl_FB8020 - v375 * v373[198];
    v376 = v375 * v373[225];
    ++v373;
    dbl_FB80F8 = dbl_FB80F8 - v376;
  }
  while ( (int)v374 < (int)&dword_FB5BFC );
  v377 = (double *)&unk_FB75C8;
  v378 = &dword_FB5C00;
  v726 = 1.0 / dbl_FB75C0;
  do
  {
    v379 = v726 * *(double *)(*v378++ + 216);
    *v377++ = v379;
  }
  while ( (int)v378 < (int)&dbl_FB5C30 );
  v380 = dbl_FB5AA0;
  for ( i10 = 0; i10 < 24; i10 += 8 )
  {
    v382 = *(double *)(i10 + 16472544) * *(double *)(i10 + 16479488);
    dbl_FB5AA0 = v380 - v382;
    v380 = dbl_FB5AA0;
  }
  for ( i11 = 0; i11 < 56; i11 += 8 )
  {
    v384 = *(double *)(i11 + 16472680) * *(double *)(i11 + 16479624);
    dbl_FB5AA0 = v380 - v384;
    v380 = dbl_FB5AA0;
  }
  v385 = &dbl_FB7750;
  v386 = &dword_FB5B9C;
  dbl_FB5AA0 = (dbl_FB5AA0 - (v113 * dbl_FB7530 + v337 * dbl_FB7528)) * v726;
  v387 = dbl_FB76F0;
  do
  {
    v388 = *(double *)(*v386++ + 224);
    dbl_FB76F0 = v387 - v388 * *(v385 - 37);
    v387 = dbl_FB76F0;
    v389 = v388 * *v385++;
    dbl_FB7818 = dbl_FB7818 - v389;
  }
  while ( (int)v386 < (int)&dword_FB5BA8 );
  v390 = &dbl_FB7778;
  v391 = &dword_FB5BB0;
  do
  {
    v392 = *(double *)(*v391++ + 224);
    dbl_FB76F0 = v387 - v392 * *(v390 - 37);
    v387 = dbl_FB76F0;
    v393 = v392 * *v390++;
    dbl_FB7818 = dbl_FB7818 - v393;
  }
  while ( (int)v391 < (int)&dword_FB5BB8 );
  v394 = &dbl_FB77D8;
  v395 = &dword_FB5BE0;
  do
  {
    v396 = *(double *)(*v395++ + 224);
    dbl_FB76F0 = v387 - v396 * *(v394 - 37);
    v387 = dbl_FB76F0;
    v397 = v396 * *v394++;
    dbl_FB7818 = dbl_FB7818 - v397;
  }
  while ( (int)v395 < (int)&dword_FB5C00 );
  v398 = &dbl_FB79B8;
  v399 = &dword_FB5BE0;
  do
  {
    v400 = *(double *)(*v399++ + 224);
    dbl_FB7908 = dbl_FB7908 - v400 * *(v398 - 30);
    dbl_FB79F8 = dbl_FB79F8 - v400 * *v398;
    dbl_FB7AE8 = dbl_FB7AE8 - v400 * v398[30];
    dbl_FB7BD8 = dbl_FB7BD8 - v400 * v398[60];
    dbl_FB7CC8 = dbl_FB7CC8 - v400 * v398[90];
    dbl_FB7DA0 = dbl_FB7DA0 - v400 * v398[117];
    dbl_FB7E78 = dbl_FB7E78 - v400 * v398[144];
    dbl_FB7F50 = dbl_FB7F50 - v400 * v398[171];
    dbl_FB8028 = dbl_FB8028 - v400 * v398[198];
    v401 = v400 * v398[225];
    ++v398;
    dbl_FB8100 = dbl_FB8100 - v401;
  }
  while ( (int)v399 < (int)&dword_FB5C00 );
  v402 = (double *)&unk_FB76F8;
  v403 = &dword_FB5C04;
  v727 = 1.0 / dbl_FB76F0;
  do
  {
    v404 = v727 * *(double *)(*v403++ + 224);
    *v402++ = v404;
  }
  while ( (int)v403 < (int)&dbl_FB5C30 );
  v405 = dbl_FB5AA8;
  for ( i12 = 0; i12 < 24; i12 += 8 )
  {
    v407 = *(double *)(i12 + 16472544) * *(double *)(i12 + 16479784);
    dbl_FB5AA8 = v405 - v407;
    v405 = dbl_FB5AA8;
  }
  for ( i13 = 0; i13 < 64; i13 += 8 )
  {
    v409 = *(double *)(i13 + 16472680) * *(double *)(i13 + 16479920);
    dbl_FB5AA8 = v405 - v409;
    v405 = dbl_FB5AA8;
  }
  v410 = &dbl_FB7750;
  v411 = &dword_FB5B9C;
  dbl_FB5AA8 = (dbl_FB5AA8 - (v113 * dbl_FB7658 + v337 * dbl_FB7650)) * v727;
  v412 = dbl_FB7820;
  do
  {
    v413 = *(double *)(*v411++ + 232);
    v414 = v413 * *v410++;
    dbl_FB7820 = v412 - v414;
    v412 = dbl_FB7820;
  }
  while ( (int)v411 < (int)&dword_FB5BA8 );
  v415 = &dbl_FB77D8;
  v416 = &dword_FB5BE0;
  do
  {
    v417 = *(double *)(*v416++ + 232);
    v418 = v417 * *v415++;
    dbl_FB7820 = v412 - v418;
    v412 = dbl_FB7820;
  }
  while ( (int)v416 < (int)&dword_FB5C04 );
  v419 = &dbl_FB79B8;
  v420 = &dword_FB5BE0;
  dbl_FB7820 = dbl_FB7820 - (dbl_FB6448 * dbl_FB7780 + dbl_FB6370 * dbl_FB7778);
  do
  {
    v421 = *(double *)(*v420++ + 232);
    dbl_FB7910 = dbl_FB7910 - v421 * *(v419 - 30);
    dbl_FB7A00 = dbl_FB7A00 - v421 * *v419;
    dbl_FB7AF0 = dbl_FB7AF0 - v421 * v419[30];
    dbl_FB7BE0 = dbl_FB7BE0 - v421 * v419[60];
    dbl_FB7CD0 = dbl_FB7CD0 - v421 * v419[90];
    dbl_FB7DA8 = dbl_FB7DA8 - v421 * v419[117];
    dbl_FB7E80 = dbl_FB7E80 - v421 * v419[144];
    dbl_FB7F58 = dbl_FB7F58 - v421 * v419[171];
    dbl_FB8030 = dbl_FB8030 - v421 * v419[198];
    v422 = v421 * v419[225];
    ++v419;
    dbl_FB8108 = dbl_FB8108 - v422;
  }
  while ( (int)v420 < (int)&dword_FB5C04 );
  v423 = (double *)&unk_FB7828;
  v424 = &dword_FB5C08;
  v728 = 1.0 / dbl_FB7820;
  do
  {
    v425 = v728 * *(double *)(*v424++ + 232);
    *v423++ = v425;
  }
  while ( (int)v424 < (int)&dbl_FB5C30 );
  v426 = dbl_FB5AB0;
  for ( i14 = 0; i14 < 24; i14 += 8 )
  {
    v428 = *(double *)(i14 + 16472544) * *(double *)(i14 + 16480080);
    dbl_FB5AB0 = v426 - v428;
    v426 = dbl_FB5AB0;
  }
  for ( i15 = 0; i15 < 72; i15 += 8 )
  {
    v430 = *(double *)(i15 + 16472680) * *(double *)(i15 + 16480216);
    dbl_FB5AB0 = v426 - v430;
    v426 = dbl_FB5AB0;
  }
  v431 = &dbl_FB7968;
  v432 = &dword_FB5BB8;
  dbl_FB5AB0 = (dbl_FB5AB0 - (v113 * dbl_FB7780 + v337 * dbl_FB7778)) * v728;
  v433 = dbl_FB7918;
  do
  {
    v434 = *(double *)(*v432++ + 240);
    dbl_FB7918 = v433 - v434 * *(v431 - 30);
    v433 = dbl_FB7918;
    dbl_FB7A08 = dbl_FB7A08 - v434 * *v431;
    dbl_FB7AF8 = dbl_FB7AF8 - v434 * v431[30];
    dbl_FB7BE8 = dbl_FB7BE8 - v434 * v431[60];
    v435 = v434 * v431[90];
    ++v431;
    dbl_FB7CD8 = dbl_FB7CD8 - v435;
  }
  while ( (int)v432 < (int)&dword_FB5BC4 );
  v436 = &dbl_FB7998;
  v437 = &dword_FB5BD0;
  do
  {
    v438 = *(double *)(*v437++ + 240);
    dbl_FB7918 = v433 - v438 * *(v436 - 30);
    v433 = dbl_FB7918;
    dbl_FB7A08 = dbl_FB7A08 - v438 * *v436;
    dbl_FB7AF8 = dbl_FB7AF8 - v438 * v436[30];
    dbl_FB7BE8 = dbl_FB7BE8 - v438 * v436[60];
    v439 = v438 * v436[90];
    ++v436;
    dbl_FB7CD8 = dbl_FB7CD8 - v439;
  }
  while ( (int)v437 < (int)&dword_FB5BD8 );
  v440 = &dbl_FB79B8;
  v441 = &dword_FB5BE0;
  do
  {
    v442 = *(double *)(*v441++ + 240);
    dbl_FB7918 = v433 - v442 * *(v440 - 30);
    v433 = dbl_FB7918;
    dbl_FB7A08 = dbl_FB7A08 - v442 * *v440;
    dbl_FB7AF8 = dbl_FB7AF8 - v442 * v440[30];
    dbl_FB7BE8 = dbl_FB7BE8 - v442 * v440[60];
    v443 = v442 * v440[90];
    ++v440;
    dbl_FB7CD8 = dbl_FB7CD8 - v443;
  }
  while ( (int)v441 < (int)&dword_FB5C08 );
  v444 = &dbl_FB7E38;
  v445 = &dword_FB5BE0;
  do
  {
    v446 = *(double *)(*v445++ + 240);
    dbl_FB7DB0 = dbl_FB7DB0 - v446 * *(v444 - 27);
    dbl_FB7E88 = dbl_FB7E88 - v446 * *v444;
    dbl_FB7F60 = dbl_FB7F60 - v446 * v444[27];
    dbl_FB8038 = dbl_FB8038 - v446 * v444[54];
    v447 = v446 * v444[81];
    ++v444;
    dbl_FB8110 = dbl_FB8110 - v447;
  }
  while ( (int)v445 < (int)&dword_FB5C08 );
  v448 = (double *)&unk_FB7920;
  v449 = &dword_FB5C0C;
  v729 = 1.0 / dbl_FB7918;
  do
  {
    v450 = v729 * *(double *)(*v449++ + 240);
    *v448++ = v450;
  }
  while ( (int)v449 < (int)&dbl_FB5C30 );
  v451 = dbl_FB5AB8;
  for ( i16 = 0; i16 < 24; i16 += 8 )
  {
    v453 = *(double *)(i16 + 16472600) * *(double *)(i16 + 16480376);
    dbl_FB5AB8 = v451 - v453;
    v451 = dbl_FB5AB8;
  }
  for ( i17 = 0; i17 < 80; i17 += 8 )
  {
    v455 = *(double *)(i17 + 16472680) * *(double *)(i17 + 16480456);
    dbl_FB5AB8 = v451 - v455;
    v451 = dbl_FB5AB8;
  }
  v456 = &dbl_FB7A58;
  v457 = dbl_FB5A48;
  v458 = &dword_FB5BB8;
  dbl_FB5AB8 = (dbl_FB5AB8 - (v188 * dbl_FB78B0 + dbl_FB5A48 * dbl_FB78A8)) * v729;
  v459 = dbl_FB7A10;
  do
  {
    v460 = *(double *)(*v458++ + 248);
    dbl_FB7A10 = v459 - v460 * *(v456 - 30);
    v459 = dbl_FB7A10;
    dbl_FB7B00 = dbl_FB7B00 - v460 * *v456;
    dbl_FB7BF0 = dbl_FB7BF0 - v460 * v456[30];
    v461 = v460 * v456[60];
    ++v456;
    dbl_FB7CE0 = dbl_FB7CE0 - v461;
  }
  while ( (int)v458 < (int)&dword_FB5BC4 );
  v462 = &dbl_FB7A88;
  v463 = &dword_FB5BD0;
  do
  {
    v464 = *(double *)(*v463++ + 248);
    dbl_FB7A10 = v459 - v464 * *(v462 - 30);
    v459 = dbl_FB7A10;
    dbl_FB7B00 = dbl_FB7B00 - v464 * *v462;
    dbl_FB7BF0 = dbl_FB7BF0 - v464 * v462[30];
    v465 = v464 * v462[60];
    ++v462;
    dbl_FB7CE0 = dbl_FB7CE0 - v465;
  }
  while ( (int)v463 < (int)&dword_FB5BD8 );
  v466 = &dbl_FB7AA8;
  v467 = &dword_FB5BE0;
  do
  {
    v468 = *(double *)(*v467++ + 248);
    dbl_FB7A10 = v459 - v468 * *(v466 - 30);
    v459 = dbl_FB7A10;
    dbl_FB7B00 = dbl_FB7B00 - v468 * *v466;
    dbl_FB7BF0 = dbl_FB7BF0 - v468 * v466[30];
    v469 = v468 * v466[60];
    ++v466;
    dbl_FB7CE0 = dbl_FB7CE0 - v469;
  }
  while ( (int)v467 < (int)&dword_FB5C0C );
  v470 = &dbl_FB7E38;
  v471 = &dword_FB5BE0;
  do
  {
    v472 = *(double *)(*v471++ + 248);
    dbl_FB7DB8 = dbl_FB7DB8 - v472 * *(v470 - 27);
    dbl_FB7E90 = dbl_FB7E90 - v472 * *v470;
    dbl_FB7F68 = dbl_FB7F68 - v472 * v470[27];
    dbl_FB8040 = dbl_FB8040 - v472 * v470[54];
    v473 = v472 * v470[81];
    ++v470;
    dbl_FB8118 = dbl_FB8118 - v473;
  }
  while ( (int)v471 < (int)&dword_FB5C0C );
  v474 = (double *)&unk_FB7A18;
  v475 = &dword_FB5C10;
  v730 = 1.0 / dbl_FB7A10;
  do
  {
    v476 = v730 * *(double *)(*v475++ + 248);
    *v474++ = v476;
  }
  while ( (int)v475 < (int)&dbl_FB5C30 );
  v477 = dbl_FB5AC0;
  for ( i18 = 0; i18 < 24; i18 += 8 )
  {
    v479 = *(double *)(i18 + 16472600) * *(double *)(i18 + 16480616);
    dbl_FB5AC0 = v477 - v479;
    v477 = dbl_FB5AC0;
  }
  for ( i19 = 0; i19 < 88; i19 += 8 )
  {
    v481 = *(double *)(i19 + 16472680) * *(double *)(i19 + 16480696);
    dbl_FB5AC0 = v477 - v481;
    v477 = dbl_FB5AC0;
  }
  v482 = &dbl_FB7B48;
  v483 = &dword_FB5BB8;
  dbl_FB5AC0 = (dbl_FB5AC0 - (v188 * dbl_FB79A0 + v457 * dbl_FB7998)) * v730;
  v484 = dbl_FB7B08;
  do
  {
    v485 = *(double *)(*v483++ + 256);
    dbl_FB7B08 = v484 - v485 * *(v482 - 30);
    v484 = dbl_FB7B08;
    dbl_FB7BF8 = dbl_FB7BF8 - v485 * *v482;
    v486 = v485 * v482[30];
    ++v482;
    dbl_FB7CE8 = dbl_FB7CE8 - v486;
  }
  while ( (int)v483 < (int)&dword_FB5BC4 );
  v487 = &dbl_FB7B78;
  v488 = &dword_FB5BD0;
  do
  {
    v489 = *(double *)(*v488++ + 256);
    dbl_FB7B08 = v484 - v489 * *(v487 - 30);
    v484 = dbl_FB7B08;
    dbl_FB7BF8 = dbl_FB7BF8 - v489 * *v487;
    v490 = v489 * v487[30];
    ++v487;
    dbl_FB7CE8 = dbl_FB7CE8 - v490;
  }
  while ( (int)v488 < (int)&dword_FB5BD8 );
  v491 = &dbl_FB7B98;
  v492 = &dword_FB5BE0;
  do
  {
    v493 = *(double *)(*v492++ + 256);
    dbl_FB7B08 = v484 - v493 * *(v491 - 30);
    v484 = dbl_FB7B08;
    dbl_FB7BF8 = dbl_FB7BF8 - v493 * *v491;
    v494 = v493 * v491[30];
    ++v491;
    dbl_FB7CE8 = dbl_FB7CE8 - v494;
  }
  while ( (int)v492 < (int)&dword_FB5C10 );
  v495 = &dbl_FB7E38;
  v496 = &dword_FB5BE0;
  do
  {
    v497 = *(double *)(*v496++ + 256);
    dbl_FB7DC0 = dbl_FB7DC0 - v497 * *(v495 - 27);
    dbl_FB7E98 = dbl_FB7E98 - v497 * *v495;
    dbl_FB7F70 = dbl_FB7F70 - v497 * v495[27];
    dbl_FB8048 = dbl_FB8048 - v497 * v495[54];
    v498 = v497 * v495[81];
    ++v495;
    dbl_FB8120 = dbl_FB8120 - v498;
  }
  while ( (int)v496 < (int)&dword_FB5C10 );
  v499 = (double *)&unk_FB7B10;
  v500 = &dword_FB5C14;
  v731 = 1.0 / dbl_FB7B08;
  do
  {
    v501 = v731 * *(double *)(*v500++ + 256);
    *v499++ = v501;
  }
  while ( (int)v500 < (int)&dbl_FB5C30 );
  v502 = dbl_FB5AC8;
  for ( i20 = 0; i20 < 24; i20 += 8 )
  {
    v504 = *(double *)(i20 + 16472600) * *(double *)(i20 + 16480856);
    dbl_FB5AC8 = v502 - v504;
    v502 = dbl_FB5AC8;
  }
  for ( i21 = 0; i21 < 96; i21 += 8 )
  {
    v506 = *(double *)(i21 + 16472680) * *(double *)(i21 + 16480936);
    dbl_FB5AC8 = v502 - v506;
    v502 = dbl_FB5AC8;
  }
  v507 = &dbl_FB7C38;
  v508 = &dword_FB5BB8;
  dbl_FB5AC8 = (dbl_FB5AC8 - (v188 * dbl_FB7A90 + v457 * dbl_FB7A88)) * v731;
  v509 = dbl_FB7C00;
  do
  {
    v510 = *(double *)(*v508++ + 264);
    dbl_FB7C00 = v509 - v510 * *(v507 - 30);
    v509 = dbl_FB7C00;
    v511 = v510 * *v507++;
    dbl_FB7CF0 = dbl_FB7CF0 - v511;
  }
  while ( (int)v508 < (int)&dword_FB5BC4 );
  v512 = &dbl_FB7C68;
  v513 = &dword_FB5BD0;
  do
  {
    v514 = *(double *)(*v513++ + 264);
    dbl_FB7C00 = v509 - v514 * *(v512 - 30);
    v509 = dbl_FB7C00;
    v515 = v514 * *v512++;
    dbl_FB7CF0 = dbl_FB7CF0 - v515;
  }
  while ( (int)v513 < (int)&dword_FB5BD8 );
  v516 = &dbl_FB7C88;
  v517 = &dword_FB5BE0;
  do
  {
    v518 = *(double *)(*v517++ + 264);
    dbl_FB7C00 = v509 - v518 * *(v516 - 30);
    v509 = dbl_FB7C00;
    v519 = v518 * *v516++;
    dbl_FB7CF0 = dbl_FB7CF0 - v519;
  }
  while ( (int)v517 < (int)&dword_FB5C14 );
  v520 = &dbl_FB7E38;
  v521 = &dword_FB5BE0;
  do
  {
    v522 = *(double *)(*v521++ + 264);
    dbl_FB7DC8 = dbl_FB7DC8 - v522 * *(v520 - 27);
    dbl_FB7EA0 = dbl_FB7EA0 - v522 * *v520;
    dbl_FB7F78 = dbl_FB7F78 - v522 * v520[27];
    dbl_FB8050 = dbl_FB8050 - v522 * v520[54];
    v523 = v522 * v520[81];
    ++v520;
    dbl_FB8128 = dbl_FB8128 - v523;
  }
  while ( (int)v521 < (int)&dword_FB5C14 );
  v524 = (double *)&unk_FB7C08;
  v525 = &dword_FB5C18;
  v732 = 1.0 / dbl_FB7C00;
  do
  {
    v526 = v732 * *(double *)(*v525++ + 264);
    *v524++ = v526;
  }
  while ( (int)v525 < (int)&dbl_FB5C30 );
  v527 = dbl_FB5AD0;
  for ( i22 = 0; i22 < 24; i22 += 8 )
  {
    v529 = *(double *)(i22 + 16472600) * *(double *)(i22 + 16481096);
    dbl_FB5AD0 = v527 - v529;
    v527 = dbl_FB5AD0;
  }
  for ( i23 = 0; i23 < 104; i23 += 8 )
  {
    v531 = *(double *)(i23 + 16472680) * *(double *)(i23 + 16481176);
    dbl_FB5AD0 = v527 - v531;
    v527 = dbl_FB5AD0;
  }
  v532 = &dbl_FB7C38;
  v533 = &dword_FB5BB8;
  dbl_FB5AD0 = (dbl_FB5AD0 - (v188 * dbl_FB7B80 + v457 * dbl_FB7B78)) * v732;
  v534 = dbl_FB7CF8;
  do
  {
    v535 = *(double *)(*v533++ + 272);
    v536 = v535 * *v532++;
    dbl_FB7CF8 = v534 - v536;
    v534 = dbl_FB7CF8;
  }
  while ( (int)v533 < (int)&dword_FB5BC4 );
  v537 = &dbl_FB7C88;
  v538 = &dword_FB5BE0;
  do
  {
    v539 = *(double *)(*v538++ + 272);
    v540 = v539 * *v537++;
    dbl_FB7CF8 = v534 - v540;
    v534 = dbl_FB7CF8;
  }
  while ( (int)v538 < (int)&dword_FB5C18 );
  v541 = &dbl_FB7E38;
  v542 = &dword_FB5BE0;
  dbl_FB7CF8 = dbl_FB7CF8 - (dbl_FB7C70 * dbl_FB6AB8 + dbl_FB7C68 * dbl_FB69F0);
  do
  {
    v543 = *(double *)(*v542++ + 272);
    dbl_FB7DD0 = dbl_FB7DD0 - v543 * *(v541 - 27);
    dbl_FB7EA8 = dbl_FB7EA8 - v543 * *v541;
    dbl_FB7F80 = dbl_FB7F80 - v543 * v541[27];
    dbl_FB8058 = dbl_FB8058 - v543 * v541[54];
    v544 = v543 * v541[81];
    ++v541;
    dbl_FB8130 = dbl_FB8130 - v544;
  }
  while ( (int)v542 < (int)&dword_FB5C18 );
  v545 = (double *)&unk_FB7D00;
  v546 = &dword_FB5C1C;
  v733 = 1.0 / dbl_FB7CF8;
  do
  {
    v547 = v733 * *(double *)(*v546++ + 272);
    *v545++ = v547;
  }
  while ( (int)v546 < (int)&dbl_FB5C30 );
  v548 = dbl_FB5AD8;
  for ( i24 = 0; i24 < 24; i24 += 8 )
  {
    v550 = *(double *)(i24 + 16472600) * *(double *)(i24 + 16481336);
    dbl_FB5AD8 = v548 - v550;
    v548 = dbl_FB5AD8;
  }
  for ( i25 = 0; i25 < 112; i25 += 8 )
  {
    v552 = *(double *)(i25 + 16472680) * *(double *)(i25 + 16481416);
    dbl_FB5AD8 = v548 - v552;
    v548 = dbl_FB5AD8;
  }
  v553 = &dbl_FB7E00;
  v554 = &dword_FB5BC4;
  dbl_FB5AD8 = (dbl_FB5AD8 - (v188 * dbl_FB7C70 + v457 * dbl_FB7C68)) * v733;
  do
  {
    v555 = *(double *)(*v554++ + 280);
    dbl_FB7DD8 = dbl_FB7DD8 - v555 * *(v553 - 27);
    dbl_FB7EB0 = dbl_FB7EB0 - v555 * *v553;
    dbl_FB7F88 = dbl_FB7F88 - v555 * v553[27];
    dbl_FB8060 = dbl_FB8060 - v555 * v553[54];
    v556 = v555 * v553[81];
    ++v553;
    dbl_FB8138 = dbl_FB8138 - v556;
  }
  while ( (int)v554 < (int)&dword_FB5BD0 );
  v557 = &dbl_FB7E28;
  v558 = &dword_FB5BD8;
  do
  {
    v559 = *(double *)(*v558++ + 280);
    dbl_FB7DD8 = dbl_FB7DD8 - v559 * *(v557 - 27);
    dbl_FB7EB0 = dbl_FB7EB0 - v559 * *v557;
    dbl_FB7F88 = dbl_FB7F88 - v559 * v557[27];
    dbl_FB8060 = dbl_FB8060 - v559 * v557[54];
    v560 = v559 * v557[81];
    ++v557;
    dbl_FB8138 = dbl_FB8138 - v560;
  }
  while ( (int)v558 < (int)&dword_FB5C1C );
  v561 = 1.0 / dbl_FB7DD8;
  v562 = (double *)&unk_FB7DE0;
  v563 = &dword_FB5C20;
  do
  {
    v564 = v561 * *(double *)(*v563++ + 280);
    *v562++ = v564;
  }
  while ( (int)v563 < (int)&dbl_FB5C30 );
  for ( i26 = 0; i26 < 24; i26 += 8 )
  {
    v566 = *(double *)(i26 + 16472624) * *(double *)(i26 + 16481576);
    dbl_FB5AE0 = dbl_FB5AE0 - v566;
  }
  for ( i27 = 0; i27 < 136; i27 += 8 )
  {
    v568 = *(double *)(i27 + 16472664) * *(double *)(i27 + 16481616);
    dbl_FB5AE0 = dbl_FB5AE0 - v568;
  }
  v569 = &dbl_FB7ED8;
  v570 = &dword_FB5BC4;
  dbl_FB5AE0 = dbl_FB5AE0 * v561;
  do
  {
    v571 = *(double *)(*v570++ + 288);
    dbl_FB7EB8 = dbl_FB7EB8 - v571 * *(v569 - 27);
    dbl_FB7F90 = dbl_FB7F90 - v571 * *v569;
    dbl_FB8068 = dbl_FB8068 - v571 * v569[27];
    v572 = v571 * v569[54];
    ++v569;
    dbl_FB8140 = dbl_FB8140 - v572;
  }
  while ( (int)v570 < (int)&dword_FB5BD0 );
  v573 = &dbl_FB7F00;
  v574 = &dword_FB5BD8;
  do
  {
    v575 = *(double *)(*v574++ + 288);
    dbl_FB7EB8 = dbl_FB7EB8 - v575 * *(v573 - 27);
    dbl_FB7F90 = dbl_FB7F90 - v575 * *v573;
    dbl_FB8068 = dbl_FB8068 - v575 * v573[27];
    v576 = v575 * v573[54];
    ++v573;
    dbl_FB8140 = dbl_FB8140 - v576;
  }
  while ( (int)v574 < (int)&dword_FB5C20 );
  v577 = 1.0 / dbl_FB7EB8;
  v578 = (double *)&unk_FB7EC0;
  v579 = &dword_FB5C24;
  do
  {
    v580 = v577 * *(double *)(*v579++ + 288);
    *v578++ = v580;
  }
  while ( (int)v579 < (int)&dbl_FB5C30 );
  for ( i28 = 0; i28 < 24; i28 += 8 )
  {
    v582 = *(double *)(i28 + 16472624) * *(double *)(i28 + 16481792);
    dbl_FB5AE8 = dbl_FB5AE8 - v582;
  }
  for ( i29 = 0; i29 < 144; i29 += 8 )
  {
    v584 = *(double *)(i29 + 16472664) * *(double *)(i29 + 16481832);
    dbl_FB5AE8 = dbl_FB5AE8 - v584;
  }
  v585 = &dbl_FB7FB0;
  v586 = &dword_FB5BC4;
  dbl_FB5AE8 = dbl_FB5AE8 * v577;
  v587 = dbl_FB7F98;
  do
  {
    v588 = *(double *)(*v586++ + 296);
    dbl_FB7F98 = v587 - v588 * *(v585 - 27);
    v587 = dbl_FB7F98;
    dbl_FB8070 = dbl_FB8070 - v588 * *v585;
    v589 = v588 * v585[27];
    ++v585;
    dbl_FB8148 = dbl_FB8148 - v589;
  }
  while ( (int)v586 < (int)&dword_FB5BD0 );
  v590 = &dbl_FB7FD8;
  v591 = &dword_FB5BD8;
  do
  {
    v592 = *(double *)(*v591++ + 296);
    dbl_FB7F98 = v587 - v592 * *(v590 - 27);
    v587 = dbl_FB7F98;
    dbl_FB8070 = dbl_FB8070 - v592 * *v590;
    v593 = v592 * v590[27];
    ++v590;
    dbl_FB8148 = dbl_FB8148 - v593;
  }
  while ( (int)v591 < (int)&dword_FB5C24 );
  v594 = 0;
  dbl_FB7FA0 = dbl_FB8070 * (1.0 / dbl_FB7F98);
  dbl_FB7FA8 = dbl_FB8148 * (1.0 / dbl_FB7F98);
  do
  {
    v595 = *(double *)(v594 + 16472624) * *(double *)(v594 + 16482008);
    v594 += 8;
    dbl_FB5AF0 = dbl_FB5AF0 - v595;
  }
  while ( v594 < 24 );
  for ( i30 = 0; i30 < 152; i30 += 8 )
  {
    v597 = *(double *)(i30 + 16472664) * *(double *)(i30 + 16482048);
    dbl_FB5AF0 = dbl_FB5AF0 - v597;
  }
  v598 = &dbl_FB8088;
  v599 = &dword_FB5BC4;
  dbl_FB5AF0 = dbl_FB5AF0 * (1.0 / dbl_FB7F98);
  v600 = dbl_FB8078;
  do
  {
    v601 = *(double *)(*v599++ + 304);
    dbl_FB8078 = v600 - v601 * *(v598 - 27);
    v600 = dbl_FB8078;
    v602 = v601 * *v598++;
    dbl_FB8150 = dbl_FB8150 - v602;
  }
  while ( (int)v599 < (int)&dword_FB5BD0 );
  v603 = &dbl_FB80B0;
  v604 = &dword_FB5BD8;
  do
  {
    v605 = *(double *)(*v604++ + 304);
    dbl_FB8078 = v600 - v605 * *(v603 - 27);
    v600 = dbl_FB8078;
    v606 = v605 * *v603++;
    dbl_FB8150 = dbl_FB8150 - v606;
  }
  while ( (int)v604 < (int)&dword_FB5C28 );
  v607 = 0;
  v734 = 1.0 / dbl_FB8078;
  dbl_FB8080 = dbl_FB8150 * v734;
  v608 = dbl_FB5AF8;
  do
  {
    v609 = *(double *)(v607 + 16472624) * *(double *)(v607 + 16482224);
    v607 += 8;
    dbl_FB5AF8 = v608 - v609;
    v608 = dbl_FB5AF8;
  }
  while ( v607 < 24 );
  v610 = 0;
  do
  {
    v611 = *(double *)(v610 + 16472664) * *(double *)(v610 + 16482264);
    v610 += 8;
    v612 = v608 - v611;
    dbl_FB5AF8 = v612;
    v608 = v612;
  }
  while ( v610 < 160 );
  v613 = &dbl_FB8088;
  v614 = &dword_FB5BC4;
  dbl_FB5AF8 = v612 * v734;
  v615 = dbl_FB8158;
  do
  {
    v616 = *(double *)(*v614++ + 312);
    v617 = v616 * *v613++;
    dbl_FB8158 = v615 - v617;
    v615 = dbl_FB8158;
  }
  while ( (int)v614 < (int)&dword_FB5BD0 );
  v618 = &dbl_FB80B0;
  v619 = &dword_FB5BD8;
  do
  {
    v620 = *(double *)(*v619++ + 312);
    v621 = v620 * *v618++;
    dbl_FB8158 = v615 - v621;
    v615 = dbl_FB8158;
  }
  while ( (int)v619 < (int)&dword_FB5C2C );
  v622 = 0;
  v623 = dbl_FB5B00;
  do
  {
    v624 = *(double *)(v622 + 16472624) * *(double *)(v622 + 16482440);
    v622 += 8;
    dbl_FB5B00 = v623 - v624;
    v623 = dbl_FB5B00;
  }
  while ( v622 < 24 );
  v625 = 0;
  do
  {
    v626 = *(double *)(v625 + 16472664) * *(double *)(v625 + 16482480);
    v625 += 8;
    v627 = v623 - v626;
    dbl_FB5B00 = v627;
    v623 = v627;
  }
  while ( v625 < 168 );
  v628 = 0;
  dbl_FB5B00 = v627 * (1.0 / dbl_FB8158);
  dbl_FB5AF8 = dbl_FB5AF8 - dbl_FB5B00 * dbl_FB8080;
  dbl_FB5AF0 = dbl_FB5AF0 - (dbl_FB5B00 * dbl_FB7FA8 + dbl_FB5AF8 * dbl_FB7FA0);
  do
  {
    v629 = *(double *)(v628 + 16472816) * *(double *)(v628 + 16481984);
    v628 += 8;
    dbl_FB5AE8 = dbl_FB5AE8 - v629;
  }
  while ( v628 < 24 );
  for ( i31 = 0; i31 < 32; i31 += 8 )
  {
    v631 = *(double *)(i31 + 16472808) * *(double *)(i31 + 16481760);
    dbl_FB5AE0 = dbl_FB5AE0 - v631;
  }
  for ( i32 = 0; i32 < 40; i32 += 8 )
  {
    v633 = *(double *)(i32 + 16472800) * *(double *)(i32 + 16481536);
    dbl_FB5AD8 = dbl_FB5AD8 - v633;
  }
  for ( i33 = 0; i33 < 48; i33 += 8 )
  {
    v635 = *(double *)(i33 + 16472792) * *(double *)(i33 + 16481288);
    dbl_FB5AD0 = dbl_FB5AD0 - v635;
  }
  for ( i34 = 0; i34 < 56; i34 += 8 )
  {
    v637 = *(double *)(i34 + 16472784) * *(double *)(i34 + 16481040);
    dbl_FB5AC8 = dbl_FB5AC8 - v637;
  }
  for ( i35 = 0; i35 < 64; i35 += 8 )
  {
    v639 = *(double *)(i35 + 16472776) * *(double *)(i35 + 16480792);
    dbl_FB5AC0 = dbl_FB5AC0 - v639;
  }
  for ( i36 = 0; i36 < 72; i36 += 8 )
  {
    v641 = *(double *)(i36 + 16472768) * *(double *)(i36 + 16480544);
    dbl_FB5AB8 = dbl_FB5AB8 - v641;
  }
  for ( i37 = 0; i37 < 80; i37 += 8 )
  {
    v643 = *(double *)(i37 + 16480296) * *(double *)(i37 + 16472760);
    dbl_FB5AB0 = dbl_FB5AB0 - v643;
  }
  for ( i38 = 0; i38 < 88; i38 += 8 )
  {
    v645 = *(double *)(i38 + 16472752) * *(double *)(i38 + 16479992);
    dbl_FB5AA8 = dbl_FB5AA8 - v645;
  }
  for ( i39 = 0; i39 < 96; i39 += 8 )
  {
    v647 = *(double *)(i39 + 16472744) * *(double *)(i39 + 16479688);
    dbl_FB5AA0 = dbl_FB5AA0 - v647;
  }
  for ( i40 = 0; i40 < 104; i40 += 8 )
  {
    v649 = *(double *)(i40 + 16472736) * *(double *)(i40 + 16479384);
    dbl_FB5A98 = dbl_FB5A98 - v649;
  }
  for ( i41 = 0; i41 < 112; i41 += 8 )
  {
    v651 = *(double *)(i41 + 16472728) * *(double *)(i41 + 16479080);
    dbl_FB5A90 = dbl_FB5A90 - v651;
  }
  for ( i42 = 0; i42 < 120; i42 += 8 )
  {
    v653 = *(double *)(i42 + 16472720) * *(double *)(i42 + 16478776);
    dbl_FB5A88 = dbl_FB5A88 - v653;
  }
  for ( i43 = 0; i43 < 128; i43 += 8 )
  {
    v655 = *(double *)(i43 + 16478448) * *(double *)(i43 + 16472712);
    dbl_FB5A80 = dbl_FB5A80 - v655;
  }
  for ( i44 = 0; i44 < 136; i44 += 8 )
  {
    v657 = *(double *)(i44 + 16478120) * *(double *)(i44 + 16472704);
    dbl_FB5A78 = dbl_FB5A78 - v657;
  }
  for ( i45 = 0; i45 < 144; i45 += 8 )
  {
    v659 = *(double *)(i45 + 16477792) * *(double *)(i45 + 16472696);
    dbl_FB5A70 = dbl_FB5A70 - v659;
  }
  for ( i46 = 0; i46 < 152; i46 += 8 )
  {
    v661 = *(double *)(i46 + 16472688) * *(double *)(i46 + 16477464);
    dbl_FB5A68 = dbl_FB5A68 - v661;
  }
  for ( i47 = 0; i47 < 40; i47 += 8 )
  {
    v663 = *(double *)(i47 + 16472800) * *(double *)(i47 + 16477256);
    dbl_FB5A60 = dbl_FB5A60 - v663;
  }
  v664 = dbl_FB5A58;
  v665 = 0;
  do
  {
    v666 = *(double *)(v665 + 16472800) * *(double *)(v665 + 16477040);
    v665 += 8;
    v667 = v664 - v666;
    dbl_FB5A58 = v667;
    v664 = v667;
  }
  while ( v665 < 40 );
  v668 = 0;
  dbl_FB5A58 = v667 - dbl_FB5A60 * dbl_FB6AF0;
  do
  {
    v669 = *(double *)(v668 + 16472760) * *(double *)(v668 + 16476824);
    v668 += 8;
    dbl_FB5A50 = v188 - v669;
    v188 = dbl_FB5A50;
  }
  while ( v668 < 40 );
  v670 = 0;
  do
  {
    v671 = *(double *)(v670 + 16472760) * *(double *)(v670 + 16476624);
    v670 += 8;
    v672 = v457 - v671;
    dbl_FB5A48 = v672;
    v457 = v672;
  }
  while ( v670 < 40 );
  v673 = 0;
  dbl_FB5A48 = v672 - dbl_FB5A50 * dbl_FB6968;
  do
  {
    v674 = *(double *)(v673 + 16472800) * *(double *)(v673 + 16476424);
    v673 += 8;
    dbl_FB5A40 = dbl_FB5A40 - v674;
  }
  while ( v673 < 40 );
  v675 = 0;
  dbl_FB5A40 = dbl_FB5A40 - (dbl_FB5A60 * dbl_FB6888 + dbl_FB5A58 * dbl_FB6880);
  do
  {
    v676 = *(double *)(v675 + 16472800) * *(double *)(v675 + 16476208);
    v675 += 8;
    dbl_FB5A38 = dbl_FB5A38 - v676;
  }
  while ( v675 < 40 );
  v677 = 0;
  dbl_FB5A38 = dbl_FB5A38 - (dbl_FB5A60 * dbl_FB67B0 + dbl_FB5A58 * dbl_FB67A8 + dbl_FB5A40 * dbl_FB6790);
  do
  {
    v678 = *(double *)(v677 + 16472800) * *(double *)(v677 + 16475992);
    v677 += 8;
    dbl_FB5A30 = dbl_FB5A30 - v678;
  }
  while ( v677 < 40 );
  v679 = 0;
  dbl_FB5A30 = dbl_FB5A30
             - (dbl_FB5A40 * dbl_FB66B8
              + dbl_FB5A38 * dbl_FB66B0
              + dbl_FB5A60 * dbl_FB66D8
              + dbl_FB5A58 * dbl_FB66D0);
  do
  {
    v680 = *(double *)(v679 + 16475776) * *(double *)(v679 + 16472760);
    v679 += 8;
    dbl_FB5A28 = dbl_FB5A28 - v680;
  }
  while ( v679 < 40 );
  v681 = 0;
  dbl_FB5A28 = dbl_FB5A28 - (dbl_FB5A50 * dbl_FB6618 + dbl_FB5A48 * dbl_FB6610);
  do
  {
    v682 = *(double *)(v681 + 16475576) * *(double *)(v681 + 16472760);
    v681 += 8;
    dbl_FB5A20 = dbl_FB5A20 - v682;
  }
  while ( v681 < 40 );
  v683 = 0;
  dbl_FB5A20 = dbl_FB5A20 - (dbl_FB5A28 * dbl_FB6528 + dbl_FB5A50 * dbl_FB6550 + dbl_FB5A48 * dbl_FB6548);
  do
  {
    v684 = *(double *)(v683 + 16475376) * *(double *)(v683 + 16472760);
    v683 += 8;
    v685 = v118 - v684;
    dbl_FB5A18 = v685;
    v118 = v685;
  }
  while ( v683 < 40 );
  v686 = 0;
  dbl_FB5A18 = v685
             - (dbl_FB5A50 * dbl_FB6488
              + dbl_FB5A48 * dbl_FB6480
              + dbl_FB5A28 * dbl_FB6460
              + dbl_FB5A20 * dbl_FB6458);
  do
  {
    v687 = *(double *)(v686 + 16475176) * *(double *)(v686 + 16472720);
    v686 += 8;
    dbl_FB5A10 = v113 - v687;
    v113 = dbl_FB5A10;
  }
  while ( v686 < 40 );
  v688 = dbl_FB5A08;
  v689 = 0;
  do
  {
    v690 = *(double *)(v689 + 16472720) * *(double *)(v689 + 16474960);
    v689 += 8;
    v691 = v688 - v690;
    dbl_FB5A08 = v691;
    v688 = v691;
  }
  while ( v689 < 40 );
  v692 = 0;
  dbl_FB5A08 = v691 - dbl_FB5A10 * dbl_FB62D0;
  do
  {
    v693 = *(double *)(v692 + 16472680) * *(double *)(v692 + 16474744);
    v692 += 8;
    dbl_FB5A00 = v80 - v693;
    v80 = dbl_FB5A00;
  }
  while ( v692 < 40 );
  v694 = dbl_FB59F8;
  v695 = 0;
  do
  {
    v696 = *(double *)(v695 + 16472680) * *(double *)(v695 + 16474544);
    v695 += 8;
    v697 = v694 - v696;
    dbl_FB59F8 = v697;
    v694 = v697;
  }
  while ( v695 < 40 );
  v698 = 0;
  dbl_FB59F8 = v697 - dbl_FB5A00 * dbl_FB6148;
  v699 = dbl_FB59F0;
  do
  {
    v700 = *(double *)(v698 + 16472720) * *(double *)(v698 + 16474344);
    v698 += 8;
    v701 = v699 - v700;
    dbl_FB59F0 = v701;
    v699 = v701;
  }
  while ( v698 < 40 );
  v702 = 0;
  dbl_FB59F0 = v701 - (dbl_FB5A10 * dbl_FB6068 + dbl_FB5A08 * dbl_FB6060);
  v703 = dbl_FB59E8;
  do
  {
    v704 = *(double *)(v702 + 16472720) * *(double *)(v702 + 16474128);
    v702 += 8;
    v705 = v703 - v704;
    dbl_FB59E8 = v705;
    v703 = v705;
  }
  while ( v702 < 40 );
  v706 = 0;
  dbl_FB59E8 = v705 - (dbl_FB5A10 * dbl_FB5F90 + dbl_FB5A08 * dbl_FB5F88 + dbl_FB59F0 * dbl_FB5F70);
  do
  {
    v707 = *(double *)(v706 + 16472720) * *(double *)(v706 + 16473912);
    v706 += 8;
    dbl_FB59E0 = dbl_FB59E0 - v707;
  }
  while ( v706 < 40 );
  v708 = 0;
  dbl_FB59E0 = dbl_FB59E0
             - (dbl_FB5A10 * dbl_FB5EB8
              + dbl_FB5A08 * dbl_FB5EB0
              + dbl_FB59F0 * dbl_FB5E98
              + dbl_FB59E8 * dbl_FB5E90);
  v709 = dbl_FB59D8;
  do
  {
    v710 = *(double *)(v708 + 16472680) * *(double *)(v708 + 16473696);
    v708 += 8;
    v711 = v709 - v710;
    dbl_FB59D8 = v711;
    v709 = v711;
  }
  while ( v708 < 40 );
  v712 = 0;
  dbl_FB59D8 = v711 - (dbl_FB5A00 * dbl_FB5DF8 + dbl_FB59F8 * dbl_FB5DF0);
  v713 = dbl_FB59D0;
  do
  {
    v714 = *(double *)(v712 + 16472680) * *(double *)(v712 + 16473496);
    v712 += 8;
    v715 = v713 - v714;
    dbl_FB59D0 = v715;
    v713 = v715;
  }
  while ( v712 < 40 );
  result = 0;
  dbl_FB59D0 = v715 - (dbl_FB5A00 * dbl_FB5D30 + dbl_FB59F8 * dbl_FB5D28 + dbl_FB59D8 * dbl_FB5D08);
  do
  {
    v717 = *(double *)(result + 16473296) * *(double *)(result + 16472680);
    result += 8;
    v718 = v6 - v717;
    dbl_FB59C8 = v718;
    v6 = v718;
  }
  while ( result < 40 );
  dbl_FB59C8 = v718
             - (dbl_FB5A00 * dbl_FB5C68
              + dbl_FB59F8 * dbl_FB5C60
              + dbl_FB59D8 * dbl_FB5C40
              + dbl_FB59D0 * dbl_FB5C38);
  return result;
}
