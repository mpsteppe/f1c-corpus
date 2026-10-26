unsigned int __thiscall sub_66963D(int this, unsigned int a2, unsigned int i12)
{
  unsigned int result; // eax
  bool v5; // zf
  int v6; // ecx
  unsigned int v7; // ecx
  int v8; // ecx
  int v9; // eax
  unsigned int v10; // edi
  int *v11; // esi
  void *v12; // eax
  unsigned int v13; // edi
  int v14; // esi
  int v15; // eax
  _DWORD *v16; // ecx
  int v17; // edx
  unsigned int v18; // eax
  unsigned int v19; // edx
  _DWORD *v20; // eax
  int v21; // eax
  int v22; // eax
  unsigned int v23; // esi
  int v24; // eax
  unsigned int *v25; // eax
  char *v26; // eax
  unsigned int i; // ecx
  _DWORD *v28; // eax
  void *v29; // edx
  int v30; // eax
  _DWORD *v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // esi
  char *v35; // eax
  unsigned int j; // ecx
  int *v37; // eax
  int v38; // ecx
  int v39; // edx
  int v40; // edx
  int v41; // edx
  int v42; // edx
  int v43; // edx
  int v44; // edx
  double v45; // st7
  int v46; // eax
  int v47; // edx
  int v48; // edx
  int v49; // edx
  int v50; // edx
  int v51; // edx
  int v52; // edx
  unsigned int v53; // esi
  char *v54; // eax
  unsigned int k; // ecx
  int v56; // eax
  int v57; // edx
  int v58; // eax
  int v59; // esi
  char *v60; // eax
  unsigned int m; // ecx
  int v62; // edx
  int v63; // esi
  char *v64; // eax
  unsigned int n; // ecx
  unsigned int ii; // eax
  _DWORD *v67; // eax
  void *v68; // edx
  int v69; // esi
  char *v70; // eax
  unsigned int jj; // ecx
  unsigned int v72; // edx
  int v73; // edx
  int v74; // edx
  int v75; // esi
  char *v76; // eax
  unsigned int kk; // ecx
  int v78; // esi
  char *v79; // eax
  unsigned int mm; // ecx
  int v81; // esi
  char *v82; // eax
  unsigned int i1; // ecx
  int v84; // eax
  unsigned int nn; // eax
  int v86; // esi
  char *v87; // eax
  unsigned int i3; // ecx
  int v89; // eax
  unsigned int i2; // eax
  int v91; // esi
  char *v92; // eax
  unsigned int i5; // ecx
  unsigned int i4; // eax
  _DWORD *v95; // eax
  int v96; // eax
  int v97; // edx
  int v98; // edx
  _BYTE *v99; // eax
  unsigned int i6; // ecx
  int v101; // eax
  int v102; // esi
  char *v103; // eax
  unsigned int i7; // ecx
  int v105; // eax
  char *v106; // eax
  unsigned int i8; // ecx
  int v108; // edx
  int v109; // edx
  int v110; // edx
  int v111; // esi
  char *v112; // eax
  unsigned int i9; // ecx
  _DWORD *v114; // edx
  unsigned int i10; // eax
  _DWORD *v116; // edx
  _DWORD *v117; // edx
  unsigned int i11; // eax
  int v119; // eax
  unsigned int v120; // ecx
  _DWORD *v121; // eax
  unsigned int v122; // ecx
  unsigned int v123; // eax
  unsigned int v124; // esi
  char *v125; // eax
  unsigned int i13; // ecx
  int *v127; // eax
  _DWORD *v128; // ecx
  char *v129; // edx
  int v130; // esi
  const void *v131; // esi
  unsigned int v132; // eax
  _DWORD *v133; // ecx
  int v134; // edx
  unsigned int v135; // esi
  unsigned int v136; // eax
  unsigned int v137; // edx
  _DWORD *v138; // ecx
  _DWORD *v139; // esi
  int v140; // eax
  char *v141; // eax
  unsigned int v142; // ecx
  int v143; // edx
  _DWORD *v144; // eax
  _DWORD *v145; // ecx
  char *v146; // edx
  const void *v147; // esi
  unsigned int v148; // edx
  unsigned int v149; // eax
  _DWORD *v150; // ecx
  _BYTE *v151; // eax
  unsigned int v152; // ecx
  int v153; // eax
  _DWORD *v154; // edx
  unsigned int i14; // eax
  unsigned int v156; // edx
  int v157; // esi
  void *v158; // edx
  unsigned int v159; // edx
  unsigned int v160; // eax
  char *v161; // eax
  unsigned int v162; // esi
  unsigned int v163; // ecx
  int v164; // edx
  int v165; // edx
  unsigned int i15; // eax
  unsigned int v167; // edx
  int v168; // esi
  char *v169; // eax
  unsigned int i16; // ecx
  int *v171; // eax
  int v172; // ecx
  int v173; // eax
  int v174; // esi
  char *v175; // eax
  unsigned int i17; // ecx
  int v177; // edx
  int v178; // esi
  char *v179; // eax
  unsigned int i18; // ecx
  _DWORD *v181; // eax
  int v182; // ecx
  int v183; // esi
  char *v184; // eax
  unsigned int i19; // ecx
  size_t v186; // esi
  void *v187; // edx
  void *v188; // edx
  int v189; // eax
  int v190; // eax
  int v191; // esi
  char *v192; // eax
  unsigned int i20; // ecx
  int *v194; // eax
  int v195; // ecx
  int v196; // eax
  int v197; // eax
  int v198; // esi
  char *v199; // eax
  unsigned int i21; // ecx
  unsigned int v201; // edx
  int v202; // edx
  _DWORD *v203; // eax
  unsigned int v204; // ecx
  int v205; // esi
  _DWORD *v206; // eax
  int v207; // edx
  int v208; // esi
  char *v209; // eax
  unsigned int i22; // ecx
  int v211; // eax
  int v212; // esi
  char *v213; // eax
  unsigned int i23; // ecx
  int v215; // edx
  int v216; // edx
  int v217; // edx
  int v218; // edx
  int v219; // edx
  int v220; // edx
  int v221; // edx
  int v222; // edx
  int v223; // edx
  int *v224; // eax
  unsigned int i24; // ecx
  _DWORD *v226; // eax
  _DWORD *v227; // ecx
  _DWORD *v228; // edx
  int v229; // edx
  unsigned int i25; // ecx
  int v231; // eax
  unsigned int i26; // eax
  unsigned int i27; // eax
  unsigned int i28; // eax
  unsigned int i29; // eax
  _DWORD *v236; // eax
  int v237; // ecx
  int v238; // esi
  unsigned int i30; // eax
  unsigned int i31; // eax
  unsigned int i32; // eax
  unsigned int i33; // eax
  _DWORD *v243; // eax
  int v244; // ecx
  int v245; // esi
  unsigned int i34; // eax
  unsigned int i35; // eax
  unsigned int i36; // eax
  unsigned int i37; // eax
  _DWORD *v250; // eax
  int v251; // ecx
  int v252; // esi
  unsigned int i38; // eax
  unsigned int i39; // eax
  unsigned int i40; // eax
  int v256; // eax
  unsigned int v257; // ecx
  unsigned int v258; // edx
  int v259; // ecx
  int v260; // eax
  int v261; // [esp-8h] [ebp-214h]
  int v262; // [esp-8h] [ebp-214h]
  int v263; // [esp-8h] [ebp-214h]
  _DWORD *v264; // [esp+0h] [ebp-20Ch]
  _DWORD *v265; // [esp+0h] [ebp-20Ch]
  _DWORD *v266; // [esp+0h] [ebp-20Ch]
  void **v267; // [esp+0h] [ebp-20Ch]
  _DWORD *v268; // [esp+0h] [ebp-20Ch]
  __int64 v269; // [esp+4h] [ebp-208h]
  __int64 v270; // [esp+4h] [ebp-208h]
  __int64 v271; // [esp+4h] [ebp-208h]
  __int64 v272; // [esp+4h] [ebp-208h]
  __int64 v273; // [esp+4h] [ebp-208h]
  __int64 v274; // [esp+4h] [ebp-208h]
  __int64 v275; // [esp+4h] [ebp-208h]
  __int64 v276; // [esp+4h] [ebp-208h]
  __int64 v277; // [esp+4h] [ebp-208h]
  __int64 v278; // [esp+4h] [ebp-208h]
  __int64 v279; // [esp+4h] [ebp-208h]
  __int64 v280; // [esp+4h] [ebp-208h]
  __int64 v281; // [esp+4h] [ebp-208h]
  __int64 v282; // [esp+4h] [ebp-208h]
  _BYTE v283[12]; // [esp+18h] [ebp-1F4h] BYREF
  _BYTE v284[12]; // [esp+24h] [ebp-1E8h] BYREF
  _BYTE v285[12]; // [esp+30h] [ebp-1DCh] BYREF
  _BYTE v286[12]; // [esp+3Ch] [ebp-1D0h] BYREF
  _DWORD v287[3]; // [esp+48h] [ebp-1C4h] BYREF
  _DWORD v288[3]; // [esp+54h] [ebp-1B8h] BYREF
  _DWORD v289[3]; // [esp+60h] [ebp-1ACh] BYREF
  _DWORD v290[3]; // [esp+6Ch] [ebp-1A0h] BYREF
  _DWORD v291[3]; // [esp+78h] [ebp-194h] BYREF
  _DWORD v292[3]; // [esp+84h] [ebp-188h] BYREF
  _DWORD v293[3]; // [esp+90h] [ebp-17Ch] BYREF
  _DWORD v294[4]; // [esp+9Ch] [ebp-170h] BYREF
  int v295; // [esp+ACh] [ebp-160h]
  int v296; // [esp+B0h] [ebp-15Ch]
  _DWORD v297[3]; // [esp+B4h] [ebp-158h] BYREF
  _DWORD v298[3]; // [esp+C0h] [ebp-14Ch] BYREF
  int v299; // [esp+CCh] [ebp-140h] BYREF
  int v300; // [esp+D0h] [ebp-13Ch]
  int v301; // [esp+D4h] [ebp-138h]
  int v302; // [esp+D8h] [ebp-134h] BYREF
  int v303; // [esp+DCh] [ebp-130h]
  int v304; // [esp+E0h] [ebp-12Ch]
  int v305; // [esp+E4h] [ebp-128h] BYREF
  int v306; // [esp+E8h] [ebp-124h]
  int v307; // [esp+ECh] [ebp-120h]
  int v308; // [esp+F0h] [ebp-11Ch] BYREF
  int v309; // [esp+F4h] [ebp-118h]
  int v310; // [esp+F8h] [ebp-114h]
  int v311; // [esp+FCh] [ebp-110h] BYREF
  int v312; // [esp+100h] [ebp-10Ch] BYREF
  char v313[4]; // [esp+104h] [ebp-108h] BYREF
  int v314; // [esp+108h] [ebp-104h]
  _DWORD *v315; // [esp+10Ch] [ebp-100h]
  _DWORD *v316; // [esp+110h] [ebp-FCh] BYREF
  int v317; // [esp+114h] [ebp-F8h]
  _DWORD *v318; // [esp+118h] [ebp-F4h]
  _DWORD *v319; // [esp+11Ch] [ebp-F0h] BYREF
  int v320; // [esp+120h] [ebp-ECh]
  _DWORD *v321; // [esp+124h] [ebp-E8h]
  _DWORD *v322; // [esp+128h] [ebp-E4h] BYREF
  int v323; // [esp+12Ch] [ebp-E0h]
  unsigned int v324; // [esp+130h] [ebp-DCh]
  unsigned int v325; // [esp+134h] [ebp-D8h] BYREF
  unsigned int v326; // [esp+138h] [ebp-D4h]
  unsigned int v327; // [esp+13Ch] [ebp-D0h]
  unsigned int v328; // [esp+140h] [ebp-CCh] BYREF
  void *v329; // [esp+144h] [ebp-C8h] BYREF
  _DWORD *v330; // [esp+148h] [ebp-C4h] BYREF
  int v331; // [esp+14Ch] [ebp-C0h] BYREF
  unsigned int v332; // [esp+150h] [ebp-BCh] BYREF
  unsigned int v333; // [esp+154h] [ebp-B8h] BYREF
  int v334; // [esp+158h] [ebp-B4h]
  int v335; // [esp+15Ch] [ebp-B0h]
  int v336; // [esp+160h] [ebp-ACh] BYREF
  int v337; // [esp+164h] [ebp-A8h]
  int v338; // [esp+168h] [ebp-A4h]
  int v339; // [esp+16Ch] [ebp-A0h] BYREF
  _DWORD *v340; // [esp+170h] [ebp-9Ch]
  _DWORD *v341; // [esp+174h] [ebp-98h]
  int v342; // [esp+178h] [ebp-94h] BYREF
  _DWORD *v343; // [esp+17Ch] [ebp-90h]
  _DWORD *v344; // [esp+180h] [ebp-8Ch]
  int v345; // [esp+184h] [ebp-88h] BYREF
  int v346; // [esp+188h] [ebp-84h]
  int v347; // [esp+18Ch] [ebp-80h]
  int v348; // [esp+190h] [ebp-7Ch] BYREF
  int v349; // [esp+194h] [ebp-78h] BYREF
  int v350; // [esp+198h] [ebp-74h] BYREF
  void *v351; // [esp+19Ch] [ebp-70h] BYREF
  int v352; // [esp+1A0h] [ebp-6Ch] BYREF
  unsigned int v353; // [esp+1A4h] [ebp-68h] BYREF
  unsigned int v354; // [esp+1A8h] [ebp-64h] BYREF
  unsigned int v355; // [esp+1ACh] [ebp-60h]
  unsigned int v356; // [esp+1B0h] [ebp-5Ch] BYREF
  int v357; // [esp+1B4h] [ebp-58h] BYREF
  int v358; // [esp+1B8h] [ebp-54h] BYREF
  int v359; // [esp+1BCh] [ebp-50h] BYREF
  unsigned int v360; // [esp+1C0h] [ebp-4Ch] BYREF
  void *Block; // [esp+1C4h] [ebp-48h]
  int v362; // [esp+1C8h] [ebp-44h]
  int *v363; // [esp+1CCh] [ebp-40h]
  _DWORD *v364; // [esp+1D0h] [ebp-3Ch]
  _DWORD *v365; // [esp+1D4h] [ebp-38h]
  _DWORD *v366; // [esp+1D8h] [ebp-34h] BYREF
  _DWORD *v367; // [esp+1DCh] [ebp-30h]
  int v368; // [esp+1E0h] [ebp-2Ch] BYREF
  _DWORD *v369; // [esp+1E4h] [ebp-28h]
  double v370; // [esp+1E8h] [ebp-24h] BYREF
  double v371; // [esp+1F0h] [ebp-1Ch] BYREF
  unsigned int v372; // [esp+1F8h] [ebp-14h] BYREF
  int v373; // [esp+1FCh] [ebp-10h] BYREF
  unsigned int i41; // [esp+200h] [ebp-Ch] BYREF
  unsigned int v375; // [esp+204h] [ebp-8h]
  int v376; // [esp+208h] [ebp-4h]

  result = a2;
  if ( !a2 )
  {
    if ( !i12 )
      return result;
    return -2147467259;
  }
  if ( *(_DWORD *)(a2 + 4) != 13 )
    return -2147467259;
  v5 = *(_DWORD *)(a2 + 28) == 26;
  v376 = *(_DWORD *)(a2 + 24) * *(_DWORD *)(a2 + 20);
  v6 = *(_DWORD *)(a2 + 36);
  v294[3] = v6;
  if ( !v5 )
    return -2147467259;
  v296 = *(_DWORD *)(this + 28);
  v370 = 0.0;
  v371 = 0.0;
  v7 = *(_DWORD *)(v6 + 8);
  v332 = 0;
  v333 = 0;
  v334 = 0;
  v335 = 0;
  Block = 0;
  v362 = 0;
  v363 = 0;
  v364 = 0;
  v295 = *(_DWORD *)(this + 100);
  v356 = 234881024;
  v354 = v7;
  if ( !v7 )
    goto LABEL_16;
  i41 = 0;
  do
  {
    v8 = *(_DWORD *)(v354 + 8);
    if ( v8 )
    {
      v9 = *(_DWORD *)(v8 + 20) * *(_DWORD *)(v8 + 24);
      v10 = i41;
      *(unsigned int *)((char *)&v332 + i41) = v9;
      v11 = (int *)((char *)&v370 + v10);
      *(_DWORD *)((char *)&v370 + v10) = v8;
      v12 = operator new(4 * v9);
      *(void **)((char *)&Block + v10) = v12;
      v13 = 0;
      v372 = (unsigned int)v12;
      if ( !v12 )
        goto LABEL_895;
      v14 = sub_6714D6(*v11, (int)v12, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      if ( *(unsigned int *)((char *)&v332 + i41) )
      {
        v15 = *(_DWORD *)(*(_DWORD *)(this + 8) + 20);
        v16 = (_DWORD *)v372;
        v17 = *(unsigned int *)((char *)&v332 + i41);
        do
        {
          v356 &= **(_DWORD **)(v15 + 4 * *v16++);
          --v17;
        }
        while ( v17 );
      }
    }
    v18 = *(_DWORD *)(v354 + 12);
    i41 += 4;
    v354 = v18;
  }
  while ( v18 );
  if ( v356 == 234881024 )
LABEL_16:
    v356 = 0;
  v19 = a2;
  *(_DWORD *)(this + 100) = v356;
  switch ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 32) + 8) + 24) )
  {
    case 0:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v20 = sub_6623AF(this, v376);
      v373 = (int)v20;
      if ( !v20 )
        goto LABEL_895;
      v14 = sub_6624CC(v20, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10100000, v373, Block, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = (unsigned int)v373 | 0x400000000LL;
      v21 = v375 | 0x20100000;
      goto LABEL_25;
    case 1:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_665561((_DWORD *)this, a2, Block, 0, i12, v376);
      goto LABEL_27;
    case 2:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v23 = v332;
      if ( v332 == 1 )
      {
        v14 = sub_6624CC(&v372, 1);
        if ( v14 >= 0 )
        {
          v14 = sub_6624CC(&v360, 1);
          if ( v14 >= 0 )
          {
            v14 = sub_6624CC((void *)i12, 1);
            if ( v14 >= 0 )
            {
              v24 = sub_666C0F((_DWORD *)this, a2, &v372, &v360, (unsigned int)Block, 1u);
LABEL_40:
              v14 = v24;
              if ( v24 < 0 )
                goto LABEL_1094;
              HIDWORD(v270) = 23;
              LODWORD(v270) = &v372;
              v25 = &v360;
              goto LABEL_42;
            }
          }
        }
        goto LABEL_1094;
      }
      if ( v332 == 2 )
      {
        v14 = sub_6624CC(&v372, 1);
        if ( v14 >= 0 )
        {
          v14 = sub_6624CC(&v360, 1);
          if ( v14 >= 0 )
          {
            v14 = sub_6624CC(&v353, 1);
            if ( v14 >= 0 )
            {
              v14 = sub_6624CC((void *)i12, 1);
              if ( v14 >= 0 )
              {
                v14 = sub_6641F3((_DWORD *)this, a2, 542113793, (int)&v372, Block, (unsigned int)Block + 4);
                if ( v14 >= 0 )
                {
                  v14 = sub_666C0F((_DWORD *)this, a2, &v360, &v353, (unsigned int)&v372, 1u);
                  if ( v14 >= 0 )
                  {
                    HIDWORD(v270) = 23;
                    LODWORD(v270) = &v360;
                    v25 = &v353;
LABEL_42:
                    v22 = sub_6641F3((_DWORD *)this, a2, 538968065, i12, v25, v270);
                    goto LABEL_27;
                  }
                }
              }
            }
          }
        }
        goto LABEL_1094;
      }
      if ( v332 != 3 )
      {
        v26 = (char *)sub_6623AF(this, 3 * v332);
        if ( !v26 )
        {
LABEL_895:
          v14 = -2147024882;
          goto LABEL_1094;
        }
        for ( i = 0; i < 3; ++i )
        {
          *(&v357 + i) = (int)v26;
          v26 += 4 * v23;
        }
        v14 = sub_6624CC((void *)v357, v332);
        if ( v14 < 0 )
          goto LABEL_1094;
        v14 = sub_6624CC((void *)v358, v332);
        if ( v14 < 0 )
          goto LABEL_1094;
        v14 = sub_6624CC((void *)v359, v332);
        if ( v14 < 0 )
          goto LABEL_1094;
        v14 = sub_6624CC(&i41, 1);
        if ( v14 < 0 )
          goto LABEL_1094;
        v14 = sub_6624CC(&v372, 1);
        if ( v14 < 0 )
          goto LABEL_1094;
        v14 = sub_6624CC((void *)i12, 1);
        if ( v14 < 0 )
          goto LABEL_1094;
        v356 = v332 & 0xFFFFF;
        v14 = sub_6641F3(
                (_DWORD *)this,
                a2,
                v332 & 0xFFFFF | 0x20500000,
                v357,
                Block,
                (unsigned int)Block | 0x400000000LL);
        if ( v14 < 0 )
          goto LABEL_1094;
        v14 = sub_6641F3((_DWORD *)this, a2, v356 | 0x10100000, v358, (_DWORD *)v357, 0x800000000LL);
        if ( v14 < 0 )
          goto LABEL_1094;
        v14 = sub_6641F3(
                (_DWORD *)this,
                a2,
                v356 | 0x20300000,
                v359,
                (_DWORD *)v358,
                (unsigned int)v357 | 0x1700000000LL);
        if ( v14 < 0 )
          goto LABEL_1094;
        v14 = sub_6641F3(
                (_DWORD *)this,
                a2,
                v356 | 0x50000000,
                (int)&i41,
                (_DWORD *)v359,
                (unsigned int)v359 | 0x600000000LL);
        if ( v14 < 0 )
          goto LABEL_1094;
        v14 = sub_6641F3((_DWORD *)this, a2, 269484033, (int)&v372, &i41, 0xA00000000LL);
        if ( v14 < 0 )
          goto LABEL_1094;
        HIDWORD(v271) = 23;
        LODWORD(v271) = &i41;
        v22 = sub_6641F3((_DWORD *)this, a2, 540016641, i12, &v372, v271);
LABEL_27:
        v14 = v22;
        if ( v22 < 0 )
          goto LABEL_1094;
        return off_16C96E0(a2, i12);
      }
      v14 = sub_6624CC(&v358, 2);
      if ( v14 >= 0 )
      {
        v14 = sub_6624CC(&v372, 1);
        if ( v14 >= 0 )
        {
          v14 = sub_6624CC(&v360, 1);
          if ( v14 >= 0 )
          {
            v14 = sub_6624CC((void *)i12, 1);
            if ( v14 >= 0 )
            {
              v14 = sub_6641F3((_DWORD *)this, a2, 542113793, (int)&v358, Block, (unsigned int)Block + 4);
              if ( v14 >= 0 )
              {
                v14 = sub_6641F3((_DWORD *)this, a2, 542113793, (int)&v359, &v358, (unsigned int)Block + 8);
                if ( v14 >= 0 )
                {
                  v24 = sub_666C0F((_DWORD *)this, a2, &v372, &v360, (unsigned int)&v359, 1u);
                  goto LABEL_40;
                }
              }
            }
          }
        }
      }
LABEL_1094:
      *(_DWORD *)(this + 28) = v296;
      *(_DWORD *)(this + 100) = v295;
      do
        j__free(*(&Block + v13++));
      while ( v13 < 4 );
      return v14;
    case 3:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC(&i41, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v372, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3(
              (_DWORD *)this,
              a2,
              v332 & 0xFFFFF | 0x50000000,
              (int)&i41,
              Block,
              (unsigned int)Block | 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 269484033, (int)&v372, &i41, 0x800000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v270) = 23;
      LODWORD(v270) = &i41;
      v25 = &v372;
      goto LABEL_42;
    case 4:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_665561((_DWORD *)this, a2, Block, i12, 0, v376);
      goto LABEL_27;
    case 5:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_665ADF((_DWORD *)this, a2, Block, 0, i12, v376);
      goto LABEL_27;
    case 6:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_665ADF((_DWORD *)this, a2, Block, (char *)v362, i12, v376);
      goto LABEL_27;
    case 7:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v28 = sub_6623AF(this, 2 * v376);
      v373 = (int)v28;
      if ( !v28 )
        goto LABEL_895;
      i41 = (unsigned int)&v28[v376];
      v14 = sub_6624CC(v28, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v29, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10100000, v373, Block, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v272) = 20;
      v30 = v375 | 0x10400000;
      goto LABEL_103;
    case 8:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) || !LODWORD(v371) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v31 = sub_6623AF(this, v376);
      v373 = (int)v31;
      if ( !v31 )
        goto LABEL_895;
      v14 = sub_6624CC(v31, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x20100000, v373, Block, (unsigned int)v362);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = (unsigned int)v363;
      v264 = (_DWORD *)v373;
      goto LABEL_793;
    case 9:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      v22 = sub_666ADA((_DWORD *)this, a2, Block, v332);
      goto LABEL_27;
    case 0xA:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_664CBF((_DWORD *)this, a2, (int *)Block, 0, (void *)i12, v376);
      goto LABEL_27;
    case 0xB:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v32 = sub_681AAA(*(_DWORD *)(*(_DWORD *)(this + 8) + 120), 0, 0, 1.0 / __FYL2X__(2.0, 0.6931471805599453094));
      v261 = *(_DWORD *)(*(_DWORD *)(this + 8) + 120);
      v359 = v32;
      v33 = sub_681AAA(v261, 0, 0, 0.5);
      v34 = v376;
      v352 = v33;
      v35 = (char *)sub_6623AF(this, 7 * v376);
      if ( !v35 )
        goto LABEL_895;
      for ( j = 0; j < 7; ++j )
      {
        (&v367)[j] = v35;
        v35 += 4 * v34;
      }
      if ( v34 )
      {
        v37 = (int *)HIDWORD(v371);
        v38 = LODWORD(v371) - HIDWORD(v371);
        do
        {
          *(int *)((char *)v37 + v38) = v359;
          *v37++ = v352;
          --v34;
        }
        while ( v34 );
      }
      v14 = sub_6624CC(v367, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v368, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v369, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v355 = v376 & 0xFFFFF | 0x20500000;
      v14 = sub_6641F3((_DWORD *)this, a2, v355, (int)v367, Block, LODWORD(v371));
      if ( v14 < 0 )
        goto LABEL_1094;
      i41 = v375 | 0x10500000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10500000, v368, v367, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, (int)v369, v367, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, i41, SLODWORD(v370), v369, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3(
              (_DWORD *)this,
              a2,
              v375 | 0x20400000,
              SHIDWORD(v370),
              (_DWORD *)v368,
              LODWORD(v370) | 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v273) = 4;
      goto LABEL_141;
    case 0xC:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v357 = *((_DWORD *)Block + 1);
      v358 = *((_DWORD *)Block + 2);
      v359 = *(_DWORD *)Block;
      v329 = *(void **)(v362 + 8);
      v330 = *(_DWORD **)v362;
      v331 = *(_DWORD *)(v362 + 4);
      v298[0] = *((_DWORD *)Block + 2);
      v298[1] = *(_DWORD *)Block;
      v298[2] = *((_DWORD *)Block + 1);
      v350 = *(_DWORD *)(v362 + 4);
      v351 = *(void **)(v362 + 8);
      v352 = *(_DWORD *)v362;
      v14 = sub_6624CC((char *)&v370 + 4, 3);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v297, v39);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v333, v40);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v41);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v355 = v376 & 0xFFFFF | 0x20500000;
      v14 = sub_6641F3((_DWORD *)this, a2, v355, (int)&v370 + 4, &v357, (unsigned int)&v329);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v355, (int)v297, v298, (unsigned int)&v350);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, (int)&v333, v297, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v269) = 0;
      LODWORD(v269) = &v333;
      v264 = (_DWORD *)&v370 + 1;
      goto LABEL_105;
    case 0xD:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v274 = 0;
      v266 = Block;
      v43 = v42 & 0xFFFFF | 0x10D00000;
      goto LABEL_878;
    case 0xE:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v274 = 0;
      v266 = Block;
      v43 = v44 & 0xFFFFF | 0x10E00000;
      goto LABEL_878;
    case 0xF:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v45 = 57.29577791868205;
      goto LABEL_690;
    case 0x10:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      if ( v332 == 1 )
      {
        *(_DWORD *)i12 = *(_DWORD *)Block;
        return off_16C96E0(a2, i12);
      }
      v46 = *(_DWORD *)(LODWORD(v370) + 20);
      switch ( v46 )
      {
        case 2:
          v14 = sub_6624CC(&v329, 3);
          if ( v14 >= 0 )
          {
            v14 = sub_6624CC((void *)i12, v376);
            if ( v14 >= 0 )
            {
              v351 = *(void **)Block;
              v358 = *((_DWORD *)Block + 3);
              v352 = *((_DWORD *)Block + 1);
              v359 = *((_DWORD *)Block + 2);
              v14 = sub_6641F3((_DWORD *)this, a2, 542113794, (int)&v329, &v351, (unsigned int)&v358);
              if ( v14 >= 0 )
              {
                v14 = sub_6641F3((_DWORD *)this, a2, 269484033, (int)&v331, &v330, 0);
                if ( v14 >= 0 )
                {
                  HIDWORD(v275) = 0;
                  LODWORD(v275) = &v331;
                  v267 = &v329;
                  goto LABEL_174;
                }
              }
            }
          }
          break;
        case 3:
          v14 = sub_6624CC(v297, 3);
          if ( v14 >= 0 )
          {
            v14 = sub_6624CC((char *)&v370 + 4, v47);
            if ( v14 >= 0 )
            {
              v14 = sub_6624CC(&v333, v48);
              if ( v14 >= 0 )
              {
                v14 = sub_6624CC(v298, v49);
                if ( v14 >= 0 )
                {
                  v14 = sub_6624CC((void *)i12, v376);
                  if ( v14 >= 0 )
                  {
                    v357 = *((_DWORD *)Block + 4);
                    v358 = *((_DWORD *)Block + 7);
                    v359 = *((_DWORD *)Block + 1);
                    v350 = *((_DWORD *)Block + 8);
                    v351 = (void *)*((_DWORD *)Block + 2);
                    v352 = *((_DWORD *)Block + 5);
                    v14 = sub_6641F3((_DWORD *)this, a2, 542113795, (int)v297, &v357, (unsigned int)&v350);
                    if ( v14 >= 0 )
                    {
                      v357 = *((_DWORD *)Block + 7);
                      v358 = *((_DWORD *)Block + 1);
                      v359 = *((_DWORD *)Block + 4);
                      v350 = *((_DWORD *)Block + 5);
                      v351 = (void *)*((_DWORD *)Block + 8);
                      v352 = *((_DWORD *)Block + 2);
                      v14 = sub_6641F3((_DWORD *)this, a2, 542113795, (int)&v370 + 4, &v357, (unsigned int)&v350);
                      if ( v14 >= 0 )
                      {
                        v14 = sub_6641F3((_DWORD *)this, a2, 269484035, (int)&v333, (_DWORD *)&v370 + 1, 0);
                        if ( v14 >= 0 )
                        {
                          v14 = sub_6641F3((_DWORD *)this, a2, 541065219, (int)v298, v297, (unsigned int)&v333);
                          if ( v14 >= 0 )
                          {
                            v357 = *(_DWORD *)Block;
                            v358 = *((_DWORD *)Block + 3);
                            v359 = *((_DWORD *)Block + 6);
                            v22 = sub_6641F3((_DWORD *)this, a2, 1342177283, i12, v298, (unsigned int)&v357);
                            goto LABEL_27;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          break;
        case 4:
          v14 = sub_6624CC(v287, 12);
          if ( v14 >= 0 )
          {
            v14 = sub_6624CC(v291, v50);
            if ( v14 >= 0 )
            {
              v14 = sub_6624CC(v283, v51);
              if ( v14 >= 0 )
              {
                v14 = sub_6624CC(&v316, v52);
                if ( v14 >= 0 )
                {
                  v14 = sub_6624CC(&v370, 4);
                  if ( v14 >= 0 )
                  {
                    v14 = sub_6624CC((void *)i12, v376);
                    if ( v14 >= 0 )
                    {
                      v336 = *((_DWORD *)Block + 10);
                      v337 = *((_DWORD *)Block + 14);
                      v338 = *((_DWORD *)Block + 6);
                      v339 = *((_DWORD *)Block + 14);
                      v340 = (_DWORD *)*((_DWORD *)Block + 2);
                      v341 = (_DWORD *)*((_DWORD *)Block + 10);
                      v342 = *((_DWORD *)Block + 6);
                      v343 = (_DWORD *)*((_DWORD *)Block + 14);
                      v344 = (_DWORD *)*((_DWORD *)Block + 2);
                      v345 = *((_DWORD *)Block + 10);
                      v346 = *((_DWORD *)Block + 2);
                      v347 = *((_DWORD *)Block + 6);
                      v299 = *((_DWORD *)Block + 15);
                      v300 = *((_DWORD *)Block + 7);
                      v301 = *((_DWORD *)Block + 11);
                      v302 = *((_DWORD *)Block + 11);
                      v303 = *((_DWORD *)Block + 15);
                      v304 = *((_DWORD *)Block + 3);
                      v305 = *((_DWORD *)Block + 15);
                      v306 = *((_DWORD *)Block + 3);
                      v307 = *((_DWORD *)Block + 7);
                      v308 = *((_DWORD *)Block + 7);
                      v309 = *((_DWORD *)Block + 11);
                      v310 = *((_DWORD *)Block + 3);
                      v14 = sub_6641F3((_DWORD *)this, a2, 542113795, (int)v287, &v336, (unsigned int)&v299);
                      if ( v14 >= 0 )
                      {
                        v14 = sub_6641F3((_DWORD *)this, a2, 542113795, (int)v288, &v339, (unsigned int)&v302);
                        if ( v14 >= 0 )
                        {
                          v14 = sub_6641F3((_DWORD *)this, a2, 542113795, (int)v289, &v342, (unsigned int)&v305);
                          if ( v14 >= 0 )
                          {
                            v14 = sub_6641F3((_DWORD *)this, a2, 542113795, (int)v290, &v345, (unsigned int)&v308);
                            if ( v14 >= 0 )
                            {
                              v336 = *((_DWORD *)Block + 14);
                              v337 = *((_DWORD *)Block + 6);
                              v338 = *((_DWORD *)Block + 10);
                              v339 = *((_DWORD *)Block + 10);
                              v340 = (_DWORD *)*((_DWORD *)Block + 14);
                              v341 = (_DWORD *)*((_DWORD *)Block + 2);
                              v342 = *((_DWORD *)Block + 14);
                              v343 = (_DWORD *)*((_DWORD *)Block + 2);
                              v344 = (_DWORD *)*((_DWORD *)Block + 6);
                              v345 = *((_DWORD *)Block + 6);
                              v346 = *((_DWORD *)Block + 10);
                              v347 = *((_DWORD *)Block + 2);
                              v299 = *((_DWORD *)Block + 11);
                              v300 = *((_DWORD *)Block + 15);
                              v301 = *((_DWORD *)Block + 7);
                              v302 = *((_DWORD *)Block + 15);
                              v303 = *((_DWORD *)Block + 3);
                              v304 = *((_DWORD *)Block + 11);
                              v305 = *((_DWORD *)Block + 7);
                              v306 = *((_DWORD *)Block + 15);
                              v307 = *((_DWORD *)Block + 3);
                              v308 = *((_DWORD *)Block + 11);
                              v309 = *((_DWORD *)Block + 3);
                              v310 = *((_DWORD *)Block + 7);
                              v14 = sub_6641F3((_DWORD *)this, a2, 542113795, (int)v291, &v336, (unsigned int)&v299);
                              if ( v14 >= 0 )
                              {
                                v14 = sub_6641F3((_DWORD *)this, a2, 542113795, (int)v292, &v339, (unsigned int)&v302);
                                if ( v14 >= 0 )
                                {
                                  v14 = sub_6641F3((_DWORD *)this, a2, 542113795, (int)v293, &v342, (unsigned int)&v305);
                                  if ( v14 >= 0 )
                                  {
                                    v14 = sub_6641F3(
                                            (_DWORD *)this,
                                            a2,
                                            542113795,
                                            (int)v294,
                                            &v345,
                                            (unsigned int)&v308);
                                    if ( v14 >= 0 )
                                    {
                                      v14 = sub_6641F3((_DWORD *)this, a2, 269484035, (int)v283, v291, 0);
                                      if ( v14 >= 0 )
                                      {
                                        v14 = sub_6641F3((_DWORD *)this, a2, 269484035, (int)v284, v292, 0);
                                        if ( v14 >= 0 )
                                        {
                                          v14 = sub_6641F3((_DWORD *)this, a2, 269484035, (int)v285, v293, 0);
                                          if ( v14 >= 0 )
                                          {
                                            v14 = sub_6641F3((_DWORD *)this, a2, 269484035, (int)v286, v294, 0);
                                            if ( v14 >= 0 )
                                            {
                                              v14 = sub_6641F3(
                                                      (_DWORD *)this,
                                                      a2,
                                                      541065219,
                                                      (int)&v316,
                                                      v287,
                                                      (unsigned int)v283);
                                              if ( v14 >= 0 )
                                              {
                                                v14 = sub_6641F3(
                                                        (_DWORD *)this,
                                                        a2,
                                                        541065219,
                                                        (int)&v319,
                                                        v288,
                                                        (unsigned int)v284);
                                                if ( v14 >= 0 )
                                                {
                                                  v14 = sub_6641F3(
                                                          (_DWORD *)this,
                                                          a2,
                                                          541065219,
                                                          (int)&v322,
                                                          v289,
                                                          (unsigned int)v285);
                                                  if ( v14 >= 0 )
                                                  {
                                                    v14 = sub_6641F3(
                                                            (_DWORD *)this,
                                                            a2,
                                                            541065219,
                                                            (int)&v325,
                                                            v290,
                                                            (unsigned int)v286);
                                                    if ( v14 >= 0 )
                                                    {
                                                      v336 = *((_DWORD *)Block + 5);
                                                      v337 = *((_DWORD *)Block + 9);
                                                      v338 = *((_DWORD *)Block + 13);
                                                      v339 = *((_DWORD *)Block + 1);
                                                      v340 = (_DWORD *)*((_DWORD *)Block + 9);
                                                      v341 = (_DWORD *)*((_DWORD *)Block + 13);
                                                      v342 = *((_DWORD *)Block + 1);
                                                      v343 = (_DWORD *)*((_DWORD *)Block + 5);
                                                      v344 = (_DWORD *)*((_DWORD *)Block + 13);
                                                      v345 = *((_DWORD *)Block + 1);
                                                      v346 = *((_DWORD *)Block + 5);
                                                      v347 = *((_DWORD *)Block + 9);
                                                      v14 = sub_6641F3(
                                                              (_DWORD *)this,
                                                              a2,
                                                              1342177283,
                                                              (int)&v370,
                                                              &v316,
                                                              (unsigned int)&v336);
                                                      if ( v14 >= 0 )
                                                      {
                                                        v14 = sub_6641F3(
                                                                (_DWORD *)this,
                                                                a2,
                                                                1342177283,
                                                                (int)&v370 + 4,
                                                                &v319,
                                                                (unsigned int)&v339);
                                                        if ( v14 >= 0 )
                                                        {
                                                          v14 = sub_6641F3(
                                                                  (_DWORD *)this,
                                                                  a2,
                                                                  1342177283,
                                                                  (int)&v371,
                                                                  &v322,
                                                                  (unsigned int)&v342);
                                                          if ( v14 >= 0 )
                                                          {
                                                            v14 = sub_6641F3(
                                                                    (_DWORD *)this,
                                                                    a2,
                                                                    1342177283,
                                                                    (int)&v371 + 4,
                                                                    &v325,
                                                                    (unsigned int)&v345);
                                                            if ( v14 >= 0 )
                                                            {
                                                              v336 = *(_DWORD *)Block;
                                                              v337 = *((_DWORD *)Block + 4);
                                                              v338 = *((_DWORD *)Block + 8);
                                                              v339 = *((_DWORD *)Block + 12);
                                                              v22 = sub_6641F3(
                                                                      (_DWORD *)this,
                                                                      a2,
                                                                      1342177284,
                                                                      i12,
                                                                      &v370,
                                                                      (unsigned int)&v336);
                                                              goto LABEL_27;
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          break;
        default:
          return off_16C96E0(a2, i12);
      }
      goto LABEL_1094;
    case 0x11:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v53 = v332;
      v54 = (char *)sub_6623AF(this, 2 * v332);
      if ( !v54 )
        goto LABEL_895;
      for ( k = 0; k < 2; ++k )
      {
        *(&v358 + k) = (int)v54;
        v54 += 4 * v53;
      }
      v14 = sub_6624CC((void *)v358, v332);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v359, v332);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v372, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v360, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v356 = v332 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v332 & 0xFFFFF | 0x10100000, v358, (_DWORD *)v362, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v356 | 0x20400000, v359, Block, (unsigned int)v358);
      if ( v14 < 0 )
        goto LABEL_1094;
      v56 = sub_6641F3(
              (_DWORD *)this,
              a2,
              v356 | 0x50000000,
              (int)&v372,
              (_DWORD *)v359,
              (unsigned int)v359 | 0x400000000LL);
      goto LABEL_228;
    case 0x12:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = (unsigned int)v362;
      v21 = v332 & 0xFFFFF | 0x50000000;
      goto LABEL_25;
    case 0x13:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v366 = *(_DWORD **)(this + 32);
      v367 = (_DWORD *)*((_DWORD *)Block + 1);
      v368 = *((_DWORD *)Block + 2);
      v369 = v366;
      LODWORD(v370) = v366;
      HIDWORD(v370) = *(_DWORD *)(v362 + 4);
      LODWORD(v371) = v366;
      HIDWORD(v371) = *(_DWORD *)(v362 + 12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v274) = 0;
      LODWORD(v274) = &v370;
      v266 = &v366;
      v43 = v57 & 0xFFFFF | 0x20500000;
      goto LABEL_878;
    case 0x14:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v58 = sub_681AAA(*(_DWORD *)(*(_DWORD *)(this + 8) + 120), 0, 0, 1.0 / __FYL2X__(2.0, 0.6931471805599453094));
      v59 = v376;
      v359 = v58;
      v60 = (char *)sub_6623AF(this, 3 * v376);
      if ( !v60 )
        goto LABEL_895;
      for ( m = 0; m < 3; ++m )
      {
        *(&v329 + m) = v60;
        v60 += 4 * v59;
      }
      if ( v59 )
      {
        memset32(v329, v359, v376);
        v13 = 0;
      }
      v14 = sub_6624CC(v330, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x20500000, (int)v330, Block, (unsigned int)v329);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10500000, i12, v330, 0x400000000LL);
      goto LABEL_27;
    case 0x15:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v274 = 0x400000000LL;
      v266 = Block;
      v43 = v62 & 0xFFFFF | 0x10500000;
      goto LABEL_878;
    case 0x16:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) || !LODWORD(v371) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC(&v372, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v360, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x50000000, (int)&v372, (_DWORD *)v362, (unsigned int)v363);
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v276) = 23;
      LODWORD(v276) = this + 36;
      v14 = sub_6641F3((_DWORD *)this, a2, 540016641, (int)&v360, &v372, v276);
      if ( v14 < 0 )
        goto LABEL_1094;
      v63 = 4 * v376;
      v64 = (char *)sub_6623AF(this, 4 * v376);
      if ( !v64 )
        goto LABEL_895;
      for ( n = 0; n < 4; ++n )
      {
        *((_DWORD *)&v370 + n) = v64;
        v64 += v63;
      }
      for ( ii = 0; ii < v376; ++ii )
        *(_DWORD *)(HIDWORD(v371) + 4 * ii) = v360;
      v14 = sub_6624CC((void *)LODWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, SLODWORD(v370), Block, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v354 = v375 | 0x20400000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20400000, SHIDWORD(v370), (_DWORD *)LODWORD(v370), LODWORD(v370));
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20500000, SLODWORD(v371), (_DWORD *)HIDWORD(v370), HIDWORD(v371));
      if ( v14 < 0 )
        goto LABEL_1094;
      v277 = LODWORD(v371);
      goto LABEL_277;
    case 0x17:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v67 = sub_6623AF(this, 2 * v376);
      v373 = (int)v67;
      if ( !v67 )
        goto LABEL_895;
      i41 = (unsigned int)&v67[v376];
      v14 = sub_6624CC(v67, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v68, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10400000, v373, Block, 0x1400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v272) = 24;
      v30 = v375 | 0x10100000;
LABEL_103:
      LODWORD(v272) = 0;
      v14 = sub_6641F3((_DWORD *)this, a2, v30, i41, (_DWORD *)v373, v272);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = i41 | 0x200000000LL;
      v264 = Block;
      goto LABEL_105;
    case 0x18:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v69 = v376;
      v70 = (char *)sub_6623AF(this, 8 * v376);
      if ( !v70 )
        goto LABEL_895;
      for ( jj = 0; jj < 8; ++jj )
      {
        (&v366)[jj] = v70;
        v70 += 4 * v69;
      }
      v72 = 0;
      while ( 1 )
      {
        v14 = sub_6624CC((&v366)[v72], v376);
        if ( v14 < 0 )
          goto LABEL_1094;
        v72 = v73 + 1;
        if ( v72 >= 8 )
        {
          v14 = sub_6624CC((void *)i12, v376);
          if ( v14 >= 0 )
          {
            v375 = v376 & 0xFFFFF;
            v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10300000, (int)v366, (_DWORD *)v362, 0);
            if ( v14 >= 0 )
            {
              v355 = v375 | 0x20500000;
              v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20500000, (int)v367, Block, (unsigned int)v366);
              if ( v14 >= 0 )
              {
                v373 = v375 | 0x10100000;
                v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, v368, v367, 0);
                if ( v14 >= 0 )
                {
                  v14 = sub_6641F3(
                          (_DWORD *)this,
                          a2,
                          v375 | 0x20100000,
                          (int)v369,
                          v367,
                          (unsigned int)v368 | 0x400000000LL);
                  if ( v14 >= 0 )
                  {
                    v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10400000, SLODWORD(v370), v369, 0x1400000000LL);
                    if ( v14 >= 0 )
                    {
                      v14 = sub_6641F3(
                              (_DWORD *)this,
                              a2,
                              v375 | 0x20300000,
                              SHIDWORD(v370),
                              v367,
                              (unsigned int)v368 | 0x1700000000LL);
                      if ( v14 >= 0 )
                      {
                        v14 = sub_6641F3((_DWORD *)this, a2, v373, SLODWORD(v371), (_DWORD *)LODWORD(v370), 0);
                        if ( v14 >= 0 )
                        {
                          v14 = sub_666305(
                                  (_DWORD *)this,
                                  a2,
                                  (void *)HIDWORD(v371),
                                  (char *)LODWORD(v371),
                                  (char *)LODWORD(v370),
                                  (_DWORD *)HIDWORD(v370),
                                  v376);
                          if ( v14 >= 0 )
                          {
                            v273 = (unsigned int)v362;
                            v265 = (_DWORD *)HIDWORD(v371);
                            goto LABEL_918;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          goto LABEL_1094;
        }
      }
    case 0x19:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v274 = 0;
      v266 = Block;
      v43 = v74 & 0xFFFFF | 0x10400000;
      goto LABEL_878;
    case 0x1A:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      v75 = v376;
      i41 = 4 * v376;
      v362 = (int)operator new(4 * v376);
      if ( !v362 )
        goto LABEL_895;
      v76 = (char *)sub_6623AF(this, 10 * v75);
      if ( !v76 )
        goto LABEL_895;
      for ( kk = 0; kk < 0xA; ++kk )
      {
        *(&v338 + kk) = (int)v76;
        v76 += i41;
      }
      v14 = sub_6624CC((void *)v338, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v339, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v340, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v341, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v342, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v343, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v344, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v345, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v362, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v373 = v376 & 0xFFFFF | 0x10100000;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, v338, Block, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20100000, v339, (_DWORD *)v338, (unsigned int)Block | 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, (int)v340, (_DWORD *)v339, 0x800000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20300000, (int)v341, v340, (unsigned int)v339 | 0x1700000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v354 = v375 | 0x20400000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20400000, v342, v341, (unsigned int)v339 | 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10600000, (int)v343, (_DWORD *)v342, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, (int)v344, v343, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10400000, v345, v344, 0x1400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v354, v362, v343, (unsigned int)v345 | 0x200000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)v346, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v347, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10500000, v346, (_DWORD *)v362, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10300000, v347, (_DWORD *)v346, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = (unsigned int)v347;
      goto LABEL_340;
    case 0x1B:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v78 = v376;
      v79 = (char *)sub_6623AF(this, 6 * v376);
      if ( !v79 )
        goto LABEL_895;
      for ( mm = 0; mm < 6; ++mm )
      {
        *(&v368 + mm) = (int)v79;
        v79 += 4 * v78;
      }
      v14 = sub_6624CC((void *)v368, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v369, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10D00000, v368, Block, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v373 = v375 | 0x10100000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, (int)v369, (_DWORD *)v368, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v359 = v375 | 0x20100000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20100000, SLODWORD(v370), v369, (unsigned int)v368 | 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10E00000, SHIDWORD(v370), Block, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, SLODWORD(v371), (_DWORD *)HIDWORD(v370), 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v359, SHIDWORD(v371), (_DWORD *)LODWORD(v371), HIDWORD(v370) | 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = HIDWORD(v371) | 0x400000000LL;
      v264 = (_DWORD *)LODWORD(v370);
      goto LABEL_105;
    case 0x1C:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      if ( (*(_BYTE *)(*(_DWORD *)(this + 8) + 110) & 0x10) != 0 )
      {
        for ( nn = 0; nn < v376; ++nn )
          *(_DWORD *)(i12 + 4 * nn) = *(_DWORD *)(this + 32);
        return off_16C96E0(a2, i12);
      }
      v81 = 4 * v376;
      v82 = (char *)sub_6623AF(this, 4 * v376);
      if ( !v82 )
        goto LABEL_895;
      for ( i1 = 0; i1 < 4; ++i1 )
      {
        *((_DWORD *)&v370 + i1) = v82;
        v82 += v81;
      }
      v14 = sub_6624CC((void *)LODWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v373 = v376 & 0xFFFFF | 0x10100000;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, SLODWORD(v370), Block, 0x4000000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20400000, SHIDWORD(v370), Block, LODWORD(v370) | 0x4000000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3(
              (_DWORD *)this,
              a2,
              v375 | 0x20500000,
              SLODWORD(v371),
              (_DWORD *)HIDWORD(v370),
              HIDWORD(v370) | 0x4000000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, SHIDWORD(v371), (_DWORD *)LODWORD(v371), 0x4000000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3(
              (_DWORD *)this,
              a2,
              v375 | 0x20300000,
              i12,
              (_DWORD *)HIDWORD(v371),
              LODWORD(v371) | 0x5700000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      i41 = 0;
      if ( !v376 )
        return off_16C96E0(a2, i12);
      a2 = i12;
      i12 = (unsigned int)Block - i12;
      while ( 1 )
      {
        v14 = sub_662830(this, *(_DWORD *)(i12 + a2), &v370);
        if ( v14 < 0 )
          goto LABEL_1094;
        if ( v370 <= *(double *)(this + 168) || v371 >= *(double *)(this + 160) )
        {
          if ( v370 != *(double *)(this + 160) && v371 != *(double *)(this + 168) )
            goto LABEL_386;
          v84 = *(_DWORD *)(this + 36);
        }
        else
        {
          v84 = *(_DWORD *)(this + 32);
        }
        *(_DWORD *)a2 = v84;
LABEL_386:
        ++i41;
        a2 += 4;
        if ( i41 >= v376 )
          return off_16C96E0(a2, i12);
      }
    case 0x1D:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      if ( (*(_BYTE *)(*(_DWORD *)(this + 8) + 110) & 0x10) != 0 )
      {
        for ( i2 = 0; i2 < v376; ++i2 )
          *(_DWORD *)(i12 + 4 * i2) = *(_DWORD *)(this + 36);
        return off_16C96E0(a2, i12);
      }
      v86 = 4 * v376;
      v87 = (char *)sub_6623AF(this, 4 * v376);
      if ( !v87 )
        goto LABEL_895;
      for ( i3 = 0; i3 < 4; ++i3 )
      {
        *((_DWORD *)&v370 + i3) = v87;
        v87 += v86;
      }
      v14 = sub_6624CC((void *)LODWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10300000, SLODWORD(v370), Block, 0x4000000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3(
              (_DWORD *)this,
              a2,
              v375 | 0x20500000,
              SHIDWORD(v370),
              (_DWORD *)LODWORD(v370),
              LODWORD(v370) | 0x4000000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, SLODWORD(v371), (_DWORD *)HIDWORD(v370), 0x4000000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3(
              (_DWORD *)this,
              a2,
              v375 | 0x20300000,
              i12,
              (_DWORD *)LODWORD(v371),
              HIDWORD(v370) | 0x5700000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      i41 = 0;
      if ( !v376 )
        return off_16C96E0(a2, i12);
      a2 = i12;
      i12 = (unsigned int)Block - i12;
      break;
    case 0x1E:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      if ( (*(_BYTE *)(*(_DWORD *)(this + 8) + 110) & 0x10) != 0 )
      {
        for ( i4 = 0; i4 < v376; ++i4 )
          *(_DWORD *)(i12 + 4 * i4) = *(_DWORD *)(this + 36);
        return off_16C96E0(a2, i12);
      }
      v91 = 4 * v376;
      v92 = (char *)sub_6623AF(this, 4 * v376);
      if ( !v92 )
        goto LABEL_895;
      for ( i5 = 0; i5 < 4; ++i5 )
      {
        *((_DWORD *)&v370 + i5) = v92;
        v92 += v91;
      }
      v14 = sub_6624CC((void *)LODWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3(
              (_DWORD *)this,
              a2,
              v376 & 0xFFFFF | 0x20500000,
              SLODWORD(v370),
              Block,
              (unsigned int)Block | 0x4000000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v373 = v375 | 0x10100000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, SHIDWORD(v370), (_DWORD *)LODWORD(v370), 0x4000000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v359 = v375 | 0x20300000;
      v14 = sub_6641F3(
              (_DWORD *)this,
              a2,
              v375 | 0x20300000,
              SLODWORD(v371),
              (_DWORD *)LODWORD(v370),
              HIDWORD(v370) | 0x5700000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, SHIDWORD(v371), (_DWORD *)LODWORD(v371), 0x5A00000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v359, i12, (_DWORD *)HIDWORD(v371), LODWORD(v371) | 0x5700000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      i41 = 0;
      if ( !v376 )
        return off_16C96E0(a2, i12);
      a2 = i12;
      i12 = (unsigned int)Block - i12;
      do
      {
        v14 = sub_662830(this, *(_DWORD *)(a2 + i12), &v370);
        if ( v14 < 0 )
          goto LABEL_1094;
        if ( v370 > *(double *)(this + 168)
          || v371 < *(double *)(this + 160)
          || v370 == *(double *)(this + 160)
          || v371 == *(double *)(this + 168) )
        {
          *(_DWORD *)a2 = *(_DWORD *)(this + 36);
        }
        ++i41;
        a2 += 4;
      }
      while ( i41 < v376 );
      return off_16C96E0(a2, i12);
    case 0x1F:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v95 = sub_6623AF(this, v376);
      v373 = (int)v95;
      if ( !v95 )
        goto LABEL_895;
      v14 = sub_6624CC(v95, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10500000, v373, (_DWORD *)v362, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = (unsigned int)v373;
      goto LABEL_340;
    case 0x20:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v96 = sub_6624CC(&v372, 1);
      v14 = v96;
      if ( v97 == 1 )
      {
        if ( v96 >= 0 )
        {
          v14 = sub_6624CC((void *)i12, 1);
          if ( v14 >= 0 )
          {
            v14 = sub_6641F3((_DWORD *)this, a2, 269484033, (int)&v372, Block, 0);
            if ( v14 >= 0 )
            {
              HIDWORD(v278) = 4;
              LODWORD(v278) = &v372;
              v22 = sub_6641F3((_DWORD *)this, a2, 537919489, i12, Block, v278);
              goto LABEL_27;
            }
          }
        }
      }
      else if ( v96 >= 0 )
      {
        v14 = sub_6624CC(&v360, 1);
        if ( v14 >= 0 )
        {
          v14 = sub_6624CC((void *)i12, v376);
          if ( v14 >= 0 )
          {
            v56 = sub_6641F3(
                    (_DWORD *)this,
                    a2,
                    v98 & 0xFFFFF | 0x50000000,
                    (int)&v372,
                    Block,
                    (unsigned int)Block | 0x400000000LL);
LABEL_228:
            v14 = v56;
            if ( v56 >= 0 )
            {
              v14 = sub_6641F3((_DWORD *)this, a2, 275775489, (int)&v360, &v372, 0x400000000LL);
              if ( v14 >= 0 )
              {
                v22 = sub_6641F3((_DWORD *)this, a2, 271581185, i12, &v360, 0x400000000LL);
                goto LABEL_27;
              }
            }
          }
        }
      }
      goto LABEL_1094;
    case 0x21:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) || !LODWORD(v371) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v22 = sub_666305((_DWORD *)this, a2, (void *)i12, (char *)Block, (char *)v362, v363, v376);
      goto LABEL_27;
    case 0x22:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) || !LODWORD(v371) || v376 != 4 )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      if ( (*(_BYTE *)(*(_DWORD *)(this + 8) + 108) & 0x40) != 0 )
      {
        v370 = *(double *)Block;
        LODWORD(v371) = *v363;
        HIDWORD(v371) = *v363;
        v14 = sub_6624CC((void *)i12, 4);
        if ( v14 < 0 )
          goto LABEL_1094;
        v22 = sub_6641F3((_DWORD *)this, a2, 1343225860, i12, &v370, 0);
        goto LABEL_27;
      }
      v99 = sub_6623AF(this, 6u);
      if ( !v99 )
        goto LABEL_895;
      for ( i6 = 0; i6 < 6; ++i6 )
        *(&v368 + i6) = (int)&v368 + 4 * i6 + v99 - (_BYTE *)&v368;
      v14 = sub_6624CC(v99, 6);
      if ( v14 >= 0 )
      {
        v14 = sub_6624CC((void *)i12, 4);
        if ( v14 >= 0 )
        {
          v14 = sub_6641F3((_DWORD *)this, a2, 269484033, v368, Block, 0);
          if ( v14 >= 0 )
          {
            v14 = sub_6641F3(
                    (_DWORD *)this,
                    a2,
                    538968065,
                    (int)v369,
                    (_DWORD *)v368,
                    (unsigned int)Block | 0x1700000000LL);
            if ( v14 >= 0 )
            {
              v14 = sub_6641F3((_DWORD *)this, a2, 542113793, i12 + 4, v369, (unsigned int)Block);
              if ( v14 >= 0 )
              {
                v14 = sub_6641F3((_DWORD *)this, a2, 269484033, SLODWORD(v370), (_DWORD *)v362, 0);
                if ( v14 >= 0 )
                {
                  v14 = sub_6641F3(
                          (_DWORD *)this,
                          a2,
                          538968065,
                          SHIDWORD(v370),
                          (_DWORD *)LODWORD(v370),
                          (unsigned int)v362 | 0x1700000000LL);
                  if ( v14 >= 0 )
                  {
                    v14 = sub_6641F3(
                            (_DWORD *)this,
                            a2,
                            542113793,
                            SLODWORD(v371),
                            v369,
                            HIDWORD(v370) | 0x1700000000LL);
                    if ( v14 >= 0 )
                    {
                      v14 = sub_6666AE(this, a2, (_DWORD *)HIDWORD(v371), (_DWORD *)v362, v363, 1u);
                      if ( v14 >= 0 )
                      {
                        v14 = sub_6641F3(
                                (_DWORD *)this,
                                a2,
                                542113793,
                                i12 + 8,
                                (_DWORD *)LODWORD(v371),
                                HIDWORD(v371) | 0x400000000LL);
                        if ( v14 >= 0 )
                        {
                          v14 = sub_6641F3((_DWORD *)this, a2, 268435457, i12, (_DWORD *)(this + 32), 0x1700000000LL);
                          if ( v14 >= 0 )
                          {
                            v22 = sub_6641F3(
                                    (_DWORD *)this,
                                    a2,
                                    268435457,
                                    i12 + 12,
                                    (_DWORD *)(this + 32),
                                    0x1700000000LL);
                            goto LABEL_27;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      goto LABEL_1094;
    case 0x23:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v101 = sub_681AAA(*(_DWORD *)(*(_DWORD *)(this + 8) + 120), 0, 0, __FYL2X__(2.0, 0.6931471805599453094));
      v102 = v376;
      v359 = v101;
      v103 = (char *)sub_6623AF(this, 2 * v376);
      if ( !v103 )
        goto LABEL_895;
      for ( i7 = 0; i7 < 2; ++i7 )
      {
        *(&v351 + i7) = v103;
        v103 += 4 * v102;
      }
      goto LABEL_501;
    case 0x24:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v105 = sub_681AAA(
               *(_DWORD *)(*(_DWORD *)(this + 8) + 120),
               0,
               0,
               __FYL2X__(2.0, 0.6931471805599453094) / __FYL2X__(10.0, 0.6931471805599453094));
      v102 = v376;
      v359 = v105;
      v106 = (char *)sub_6623AF(this, 2 * v376);
      if ( !v106 )
        goto LABEL_895;
      for ( i8 = 0; i8 < 2; ++i8 )
      {
        *(&v351 + i8) = v106;
        v106 += 4 * v102;
      }
LABEL_501:
      if ( v102 )
      {
        memset32(v351, v359, v376);
        v13 = 0;
      }
      v14 = sub_6624CC((void *)v352, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10600000, v352, Block, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = (unsigned int)v352;
      v264 = v351;
      goto LABEL_890;
    case 0x25:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v274 = 0;
      v266 = Block;
      v43 = v108 & 0xFFFFF | 0x10600000;
      goto LABEL_878;
    case 0x26:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v274 = (unsigned int)v362;
      v266 = Block;
      v43 = v109 & 0xFFFFF | 0x20100000;
      goto LABEL_878;
    case 0x27:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v274 = (unsigned int)v362;
      v266 = Block;
      v43 = v110 & 0xFFFFF | 0x20000000;
      goto LABEL_878;
    case 0x28:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      v111 = v376;
      i41 = 4 * v376;
      v362 = (int)operator new(4 * v376);
      if ( !v362 )
        goto LABEL_895;
      v112 = (char *)sub_6623AF(this, 10 * v111);
      if ( !v112 )
        goto LABEL_895;
      for ( i9 = 0; i9 < 0xA; ++i9 )
      {
        *(&v338 + i9) = (int)v112;
        v112 += i41;
      }
      v14 = sub_6624CC((void *)v338, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v339, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v340, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v341, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v342, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v343, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v344, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v345, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v346, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v362, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10200000, v338, Block, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10400000, v339, (_DWORD *)v338, 0x1400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v373 = v375 | 0x10100000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, (int)v340, (_DWORD *)v339, 0x1800000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v354 = v375 | 0x20400000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20400000, (int)v341, v340, (unsigned int)v338 | 0x200000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, v342, Block, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v372 = v375 | 0x20200000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20200000, (int)v343, Block, (unsigned int)v342 | 0x1700000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, (int)v344, (_DWORD *)v339, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v372, v345, v344, (unsigned int)v339 | 0x1700000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20500000, v346, v343, (unsigned int)v345 | 0x1700000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v354, v362, v341, (unsigned int)v346 | 0x200000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)v347, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, v347, (_DWORD *)v362, 0x200000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v277 = (unsigned int)v347 | 0x1000000000LL;
LABEL_277:
      v268 = Block;
      goto LABEL_278;
    case 0x29:
    case 0x2A:
    case 0x2B:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v114 = sub_6623AF(this, v376);
      if ( !v114 )
        goto LABEL_895;
      for ( i10 = 0; i10 < v376; ++i10 )
        v114[i10] = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = (unsigned int)v362;
      v264 = v116;
      goto LABEL_695;
    case 0x2C:
    case 0x2F:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v117 = sub_6623AF(this, v376);
      if ( !v117 )
        goto LABEL_895;
      for ( i11 = 0; i11 < v376; ++i11 )
        v117[i11] = *(_DWORD *)v362;
      goto LABEL_693;
    case 0x2D:
    case 0x2E:
    case 0x30:
    case 0x31:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      i41 = *(_DWORD *)(LODWORD(v370) + 16);
      if ( !i41 || *(_DWORD *)(i41 + 4) != 9 )
        goto LABEL_1093;
      if ( *(_DWORD *)(i41 + 16) == 1 )
      {
        v119 = sub_666F65((_DWORD *)this, (_DWORD *)i41, (unsigned int *)Block, v332);
      }
      else
      {
        sub_67F2D4(2, *(_DWORD *)(i41 + 20), *(_DWORD *)(i41 + 24), *(_DWORD *)(i41 + 28), 1024);
        v119 = sub_666F65((_DWORD *)this, &v302, (unsigned int *)Block, v332);
      }
      v14 = v119;
      if ( v119 < 0 )
        goto LABEL_1094;
      v120 = *(_DWORD *)(i41 + 24);
      v354 = *(_DWORD *)(i41 + 28);
      v121 = *(_DWORD **)(HIDWORD(v370) + 16);
      v355 = v120;
      v373 = (int)v121;
      if ( !v121 || v121[1] != 9 )
        goto LABEL_1093;
      if ( v121[4] == 1 )
      {
        v14 = sub_666F65((_DWORD *)this, v121, (unsigned int *)v362, v333);
        if ( v14 < 0 )
          goto LABEL_1094;
        v122 = *(_DWORD *)(v373 + 28);
        v123 = *(_DWORD *)(v373 + 24);
      }
      else
      {
        sub_67F2D4(2, *(_DWORD *)(v373 + 20), *(_DWORD *)(v373 + 24), *(_DWORD *)(v373 + 28), 2048);
        v14 = sub_666F65((_DWORD *)this, &v339, (unsigned int *)v362, v333);
        if ( v14 < 0 )
          goto LABEL_1094;
        v122 = *(_DWORD *)(v373 + 24);
        v123 = *(_DWORD *)(v373 + 28);
      }
      v375 = v123;
      v356 = v122;
      if ( v354 != v122 || v376 != v355 * v375 )
      {
LABEL_1093:
        v14 = -2147467259;
        goto LABEL_1094;
      }
      v124 = v355;
      if ( sub_66353F((_DWORD *)this, Block, *(_DWORD *)(i41 + 16), v355, v354) )
      {
        v135 = v375;
        if ( sub_6636D3((_DWORD *)this, (_DWORD *)v362, *(_DWORD *)(v373 + 16), v356, v375) )
        {
          v373 = (int)sub_6623AF(this, v333);
          if ( !v373 )
            goto LABEL_895;
          v136 = v356;
          if ( v356 )
          {
            v353 = v373;
            v137 = v135;
            i41 = v362;
            v360 = v356;
            while ( 1 )
            {
              if ( v137 )
              {
                v138 = (_DWORD *)i41;
                v139 = (_DWORD *)v353;
                v140 = 4 * v136;
                v372 = v137;
                do
                {
                  *v139 = *v138++;
                  v139 = (_DWORD *)((char *)v139 + v140);
                  --v372;
                }
                while ( v372 );
                v137 = v375;
              }
              v353 += 4;
              i41 += 4 * v137;
              if ( !--v360 )
                break;
              v136 = v356;
            }
          }
          v14 = sub_6624CC((void *)i12, v376);
          if ( v14 < 0 )
            goto LABEL_1094;
          v372 = 0;
          if ( !v355 )
            return off_16C96E0(a2, i12);
          v360 = i12;
          v376 = (int)Block;
          do
          {
            i41 = 0;
            if ( v375 )
            {
              v359 = v354 & 0xFFFFF | 0x50000000;
              i12 = v360;
              v353 = v373;
              do
              {
                v14 = sub_6641F3((_DWORD *)this, a2, v359, i12, (_DWORD *)v376, v353);
                if ( v14 < 0 )
                  goto LABEL_1094;
                ++i41;
                i12 += 4;
                v353 += 4 * v356;
              }
              while ( i41 < v375 );
            }
            ++v372;
            v376 += 4 * v354;
            v360 += 4 * v375;
          }
          while ( v372 < v355 );
        }
        else
        {
          v141 = (char *)sub_6623AF(this, 5 * v135);
          if ( !v141 )
            goto LABEL_895;
          v142 = 0;
          v143 = 4 * v375;
          do
          {
            (&v369)[v142++] = v141;
            v141 += v143;
          }
          while ( v142 < 5 );
          v353 = 0;
          if ( v355 )
          {
            v372 = 0;
            v360 = i12;
            while ( 1 )
            {
              for ( i12 = 0; i12 < v354; v13 = 0 )
              {
                if ( v375 )
                {
                  v144 = (_DWORD *)(v362 + 4 * i12 * v375);
                  v359 = (int)Block + 4 * i12 + 4 * v372;
                  v145 = (_DWORD *)LODWORD(v370);
                  v146 = (char *)v369 - LODWORD(v370);
                  i41 = v375;
                  do
                  {
                    *(_DWORD *)((char *)v145 + (_DWORD)v146) = *(_DWORD *)v359;
                    *v145++ = *v144++;
                    --i41;
                  }
                  while ( i41 );
                }
                v14 = sub_6624CC((void *)LODWORD(v371), v375);
                if ( v14 < 0 )
                  goto LABEL_1094;
                v359 = v375 & 0xFFFFF;
                v14 = sub_6641F3((_DWORD *)this, a2, v375 & 0xFFFFF | 0x20500000, SLODWORD(v371), v369, LODWORD(v370));
                if ( v14 < 0 )
                  goto LABEL_1094;
                if ( i12 )
                {
                  v14 = sub_6624CC((void *)HIDWORD(v371), v375);
                  if ( v14 < 0 )
                    goto LABEL_1094;
                  v14 = sub_6641F3(
                          (_DWORD *)this,
                          a2,
                          v359 | 0x20400000,
                          SHIDWORD(v371),
                          (_DWORD *)HIDWORD(v370),
                          LODWORD(v371));
                  if ( v14 < 0 )
                    goto LABEL_1094;
                  v147 = (const void *)HIDWORD(v371);
                }
                else
                {
                  v147 = (const void *)LODWORD(v371);
                }
                qmemcpy((void *)HIDWORD(v370), v147, 4 * v375);
                ++i12;
              }
              v148 = v375;
              v149 = 0;
              if ( v375 )
              {
                v150 = (_DWORD *)v360;
                do
                  *v150++ = *(_DWORD *)(HIDWORD(v370) + 4 * v149++);
                while ( v149 < v148 );
              }
              v372 += v354;
              ++v353;
              v360 += 4 * v148;
              if ( v353 >= v355 )
                return off_16C96E0(a2, i12);
            }
          }
        }
      }
      else
      {
        v125 = (char *)sub_6623AF(this, 5 * v124);
        if ( !v125 )
          goto LABEL_895;
        for ( i13 = 0; i13 < 5; ++i13 )
        {
          (&v369)[i13] = v125;
          v125 += 4 * v124;
        }
        i41 = 0;
        if ( v375 )
        {
          v373 = i12;
          while ( 1 )
          {
            for ( i12 = 0; i12 < v356; v13 = 0 )
            {
              if ( v355 )
              {
                v372 = v355;
                v352 = 4 * v354;
                v127 = (int *)((char *)Block + 4 * i12);
                v359 = v362 + 4 * (i41 + v375 * i12);
                v128 = (_DWORD *)LODWORD(v370);
                v129 = (char *)v369 - LODWORD(v370);
                do
                {
                  v130 = *v127;
                  v127 = (int *)((char *)v127 + v352);
                  *(_DWORD *)((char *)v128 + (_DWORD)v129) = v130;
                  *v128++ = *(_DWORD *)v359;
                  --v372;
                }
                while ( v372 );
              }
              v14 = sub_6624CC((void *)LODWORD(v371), v355);
              if ( v14 < 0 )
                goto LABEL_1094;
              v359 = v355 & 0xFFFFF;
              v14 = sub_6641F3((_DWORD *)this, a2, v355 & 0xFFFFF | 0x20500000, SLODWORD(v371), v369, LODWORD(v370));
              if ( v14 < 0 )
                goto LABEL_1094;
              if ( i12 )
              {
                v14 = sub_6624CC((void *)HIDWORD(v371), v355);
                if ( v14 < 0 )
                  goto LABEL_1094;
                v14 = sub_6641F3(
                        (_DWORD *)this,
                        a2,
                        v359 | 0x20400000,
                        SHIDWORD(v371),
                        (_DWORD *)HIDWORD(v370),
                        LODWORD(v371));
                if ( v14 < 0 )
                  goto LABEL_1094;
                v131 = (const void *)HIDWORD(v371);
              }
              else
              {
                v131 = (const void *)LODWORD(v371);
              }
              qmemcpy((void *)HIDWORD(v370), v131, 4 * v355);
              ++i12;
            }
            v132 = 0;
            if ( v355 )
            {
              v133 = (_DWORD *)v373;
              v134 = 4 * v375;
              do
              {
                *v133 = *(_DWORD *)(HIDWORD(v370) + 4 * v132++);
                v133 = (_DWORD *)((char *)v133 + v134);
              }
              while ( v132 < v355 );
            }
            ++i41;
            v373 += 4;
            if ( i41 >= v375 )
              return off_16C96E0(a2, i12);
          }
        }
      }
      return off_16C96E0(a2, i12);
    case 0x32:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = 0x1000000000LL;
      v21 = v332 & 0xFFFFF | 0x50200000;
LABEL_25:
      v264 = Block;
      goto LABEL_26;
    case 0x33:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      if ( v376 == 1 )
      {
        v151 = sub_6623AF(this, 4u);
        if ( !v151 )
          goto LABEL_895;
        v152 = 0;
        v153 = v151 - (_BYTE *)&v370;
        do
        {
          *((_DWORD *)&v370 + v152) = (char *)&v370 + 4 * v152 + v153;
          ++v152;
        }
        while ( v152 < 4 );
        v14 = sub_6624CC((void *)LODWORD(v370), 1);
        if ( v14 >= 0 )
        {
          v14 = sub_6624CC((void *)HIDWORD(v370), 1);
          if ( v14 >= 0 )
          {
            v14 = sub_6624CC((void *)LODWORD(v371), 1);
            if ( v14 >= 0 )
            {
              v14 = sub_6624CC((void *)HIDWORD(v371), 1);
              if ( v14 >= 0 )
              {
                v14 = sub_6624CC((void *)i12, 1);
                if ( v14 >= 0 )
                {
                  v14 = sub_6641F3((_DWORD *)this, a2, 269484033, SLODWORD(v370), Block, 0);
                  if ( v14 >= 0 )
                  {
                    v14 = sub_6641F3(
                            (_DWORD *)this,
                            a2,
                            538968065,
                            SHIDWORD(v370),
                            (_DWORD *)LODWORD(v370),
                            (unsigned int)Block | 0x1700000000LL);
                    if ( v14 >= 0 )
                    {
                      v14 = sub_6641F3(
                              (_DWORD *)this,
                              a2,
                              538968065,
                              SLODWORD(v371),
                              Block,
                              LODWORD(v370) | 0x1700000000LL);
                      if ( v14 >= 0 )
                      {
                        v14 = sub_6641F3(
                                (_DWORD *)this,
                                a2,
                                269484033,
                                SHIDWORD(v371),
                                (_DWORD *)LODWORD(v371),
                                0x1A00000000LL);
                        if ( v14 >= 0 )
                        {
                          v275 = HIDWORD(v371) | 0x1200000000LL;
                          v267 = (void **)HIDWORD(v370);
LABEL_174:
                          v22 = sub_6641F3((_DWORD *)this, a2, 541065217, i12, v267, v275);
                          goto LABEL_27;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v14 = sub_6624CC(&v372, 1);
        if ( v14 >= 0 )
        {
          v14 = sub_6624CC(&v360, 1);
          if ( v14 >= 0 )
          {
            v375 = v376 & 0xFFFFF;
            v14 = sub_6641F3(
                    (_DWORD *)this,
                    a2,
                    v376 & 0xFFFFF | 0x50000000,
                    (int)&v372,
                    Block,
                    (unsigned int)Block | 0x400000000LL);
            if ( v14 >= 0 )
            {
              v14 = sub_6641F3((_DWORD *)this, a2, 275775489, (int)&v360, &v372, 0x400000000LL);
              if ( v14 >= 0 )
              {
                v154 = sub_6623AF(this, v376);
                if ( !v154 )
                  goto LABEL_895;
                for ( i14 = 0; i14 < v376; ++i14 )
                  v154[i14] = v360;
                v14 = sub_6624CC((void *)i12, v376);
                if ( v14 >= 0 )
                {
                  v269 = v156;
LABEL_340:
                  v264 = Block;
LABEL_890:
                  v160 = v375;
LABEL_891:
                  v21 = v160 | 0x20500000;
LABEL_26:
                  v22 = sub_6641F3((_DWORD *)this, a2, v21, i12, v264, v269);
                  goto LABEL_27;
                }
              }
            }
          }
        }
      }
      goto LABEL_1094;
    case 0x34:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v22 = sub_6666AE(this, a2, (_DWORD *)i12, Block, (int *)v362, v376);
      goto LABEL_27;
    case 0x35:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v45 = 0.01745329300562541;
LABEL_690:
      v157 = sub_681AAA(*(_DWORD *)(*(_DWORD *)(this + 8) + 120), 0, 0, v45);
      v158 = sub_6623AF(this, v376);
      if ( !v158 )
        goto LABEL_895;
      if ( v376 )
      {
        memset32(v158, v157, v376);
        v13 = 0;
      }
LABEL_693:
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = v159;
      v264 = Block;
LABEL_695:
      v160 = v376 & 0xFFFFF;
      goto LABEL_891;
    case 0x36:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC(&v372, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v360, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v353, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x50000000, (int)&v372, Block, (unsigned int)v362);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 541065217, (int)&v360, &v372, (unsigned int)&v372);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 269484033, (int)&v353, &v360, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v161 = (char *)sub_6623AF(this, 2 * v376);
      if ( !v161 )
        goto LABEL_895;
      v162 = v376;
      v163 = 0;
      v164 = 4 * v376;
      do
      {
        *(&v358 + v163++) = (int)v161;
        v161 += v164;
      }
      while ( v163 < 2 );
      v165 = v358;
      for ( i15 = 0; i15 < v162; ++i15 )
        *(_DWORD *)(v165 + 4 * i15) = v353;
      v14 = sub_6624CC((void *)v359, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20500000, v359, (_DWORD *)v362, v167);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = (unsigned int)Block;
      v264 = (_DWORD *)v359;
      goto LABEL_105;
    case 0x37:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) || !LODWORD(v371) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC(&i41, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v356, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v312, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v354, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v373, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v311, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v313, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v372, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v360, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v328, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v353, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v352, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v348, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v349, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(&v359, 1);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x50000000, (int)&i41, Block, (unsigned int)v362);
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v279) = 4;
      LODWORD(v279) = &i41;
      v14 = sub_6641F3((_DWORD *)this, a2, 542113793, (int)&v356, &i41, v279);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 542113793, (int)&v312, v363, (unsigned int)v363 | 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 269484033, (int)&v354, &v356, 0x800000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 541065217, (int)&v373, (_DWORD *)(this + 32), (unsigned int)&v354);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 542113793, (int)&v311, &v312, (unsigned int)&v373);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 269484033, (int)v313, &v311, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 541065217, (int)&v372, (_DWORD *)(this + 32), (unsigned int)v313);
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v280) = 23;
      LODWORD(v280) = this + 36;
      v14 = sub_6641F3((_DWORD *)this, a2, 540016641, (int)&v360, &v372, v280);
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v281) = 4;
      LODWORD(v281) = &v360;
      v14 = sub_6641F3((_DWORD *)this, a2, 542113793, (int)&v328, &v372, v281);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 542113793, (int)&v353, v363, (unsigned int)&v360);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 542113793, (int)&v352, &v353, (unsigned int)&i41);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 275775489, (int)&v348, &v328, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 271581185, (int)&v349, &v348, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, 541065217, (int)&v359, &v352, (unsigned int)&v349);
      if ( v14 < 0 )
        goto LABEL_1094;
      v168 = v376;
      v169 = (char *)sub_6623AF(this, 5 * v376);
      if ( !v169 )
        goto LABEL_895;
      for ( i16 = 0; i16 < 5; ++i16 )
      {
        (&v369)[i16] = v169;
        v169 += 4 * v168;
      }
      v171 = (int *)HIDWORD(v371);
      if ( v168 )
      {
        v172 = LODWORD(v371) - HIDWORD(v371);
        do
        {
          *(int *)((char *)v171 + v172) = v353;
          *v171++ = v359;
          --v168;
        }
        while ( v168 );
      }
      v14 = sub_6624CC(v369, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v355 = v375 | 0x20500000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20500000, (int)v369, (_DWORD *)LODWORD(v371), (unsigned int)Block);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v355, SLODWORD(v370), (_DWORD *)HIDWORD(v371), (unsigned int)v362);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, SHIDWORD(v370), (_DWORD *)LODWORD(v370), 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = HIDWORD(v370);
      v264 = v369;
      goto LABEL_105;
    case 0x38:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v173 = sub_681AAA(*(_DWORD *)(*(_DWORD *)(this + 8) + 120), 0, 0, 0.5);
      v174 = 4 * v376;
      v359 = v173;
      v175 = (char *)sub_6623AF(this, 4 * v376);
      if ( !v175 )
        goto LABEL_895;
      for ( i17 = 0; i17 < 4; ++i17 )
      {
        *((_DWORD *)&v370 + i17) = v175;
        v175 += v174;
      }
      if ( v376 )
      {
        memset32((void *)HIDWORD(v371), v359, v376);
        v13 = 0;
      }
      v14 = sub_6624CC((void *)LODWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v354 = v376 & 0xFFFFF | 0x20400000;
      v14 = sub_6641F3((_DWORD *)this, a2, v354, SLODWORD(v370), Block, HIDWORD(v371));
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10400000, SHIDWORD(v370), (_DWORD *)LODWORD(v370), 0x1400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, SLODWORD(v371), (_DWORD *)HIDWORD(v370), 0x1800000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v277 = LODWORD(v371) | 0x200000000LL;
      v268 = (_DWORD *)LODWORD(v370);
LABEL_278:
      v22 = sub_6641F3((_DWORD *)this, a2, v354, i12, v268, v277);
      goto LABEL_27;
    case 0x39:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v274 = 0x400000000LL;
      v266 = Block;
      v43 = v177 & 0xFFFFF | 0x10700000;
      goto LABEL_878;
    case 0x3A:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v178 = v376;
      v179 = (char *)sub_6623AF(this, 3 * v376);
      if ( !v179 )
        goto LABEL_895;
      for ( i18 = 0; i18 < 3; ++i18 )
      {
        *(&v357 + i18) = (int)v179;
        v179 += 4 * v178;
      }
      v181 = (_DWORD *)v358;
      if ( v178 )
      {
        v182 = v357 - v358;
        do
        {
          *(_DWORD *)((char *)v181 + v182) = *(_DWORD *)(this + 36);
          *v181++ = *(_DWORD *)(this + 32);
          --v178;
        }
        while ( v178 );
      }
      v14 = sub_6624CC((void *)v359, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x20100000, v359, Block, (unsigned int)v357 | 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = (unsigned int)v358 | 0x1400000000LL;
      v264 = (_DWORD *)v359;
LABEL_793:
      v21 = v375 | 0x20000000;
      goto LABEL_26;
    case 0x3B:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v183 = 4 * v376;
      v184 = (char *)sub_6623AF(this, 4 * v376);
      if ( !v184 )
        goto LABEL_895;
      for ( i19 = 0; i19 < 4; ++i19 )
      {
        *((_DWORD *)&v370 + i19) = v184;
        v184 += v183;
      }
      v14 = sub_6624CC((void *)LODWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v371), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v373 = v376 & 0xFFFFF | 0x10100000;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, SLODWORD(v370), Block, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v372 = v375 | 0x20200000;
      v14 = sub_6641F3(
              (_DWORD *)this,
              a2,
              v375 | 0x20200000,
              SHIDWORD(v370),
              (_DWORD *)LODWORD(v370),
              (unsigned int)Block | 0x1700000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v372, SLODWORD(v371), Block, LODWORD(v370) | 0x1700000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, SHIDWORD(v371), (_DWORD *)LODWORD(v371), 0x1A00000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = HIDWORD(v371) | 0x1200000000LL;
      v264 = (_DWORD *)HIDWORD(v370);
LABEL_105:
      v21 = dword_16C9AD4 | v375;
      goto LABEL_26;
    case 0x3C:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_664CBF((_DWORD *)this, a2, (int *)Block, (void *)i12, 0, v376);
      goto LABEL_27;
    case 0x3D:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      v186 = 4 * v332;
      v362 = (int)operator new(4 * v332);
      if ( !v362 )
        goto LABEL_895;
      v363 = (int *)operator new(v186);
      if ( !v363 )
        goto LABEL_895;
      v14 = sub_6624CC((void *)v362, v332);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v187, v332);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_664CBF((_DWORD *)this, a2, (int *)Block, (void *)v362, v188, v332);
      goto LABEL_27;
    case 0x3E:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v189 = sub_681AAA(*(_DWORD *)(*(_DWORD *)(this + 8) + 120), 0, 0, 1.0 / __FYL2X__(2.0, 0.6931471805599453094));
      v262 = *(_DWORD *)(*(_DWORD *)(this + 8) + 120);
      v359 = v189;
      v190 = sub_681AAA(v262, 0, 0, 0.5);
      v191 = v376;
      v352 = v190;
      v192 = (char *)sub_6623AF(this, 8 * v376);
      if ( !v192 )
        goto LABEL_895;
      for ( i20 = 0; i20 < 8; ++i20 )
      {
        (&v366)[i20] = v192;
        v192 += 4 * v191;
      }
      if ( v191 )
      {
        v194 = (int *)HIDWORD(v371);
        v195 = LODWORD(v371) - HIDWORD(v371);
        do
        {
          *(int *)((char *)v194 + v195) = v359;
          *v194++ = v352;
          --v191;
        }
        while ( v191 );
      }
      v14 = sub_6624CC(v366, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v367, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v368, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v369, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v370), v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v355 = v376 & 0xFFFFF | 0x20500000;
      v14 = sub_6641F3((_DWORD *)this, a2, v355, (int)v366, Block, LODWORD(v371));
      if ( v14 < 0 )
        goto LABEL_1094;
      i41 = v375 | 0x10500000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10500000, (int)v367, v366, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v373 = v375 | 0x10100000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, v368, v366, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, i41, (int)v369, (_DWORD *)v368, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, SLODWORD(v370), v369, 0x800000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20400000, SHIDWORD(v370), v367, LODWORD(v370));
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v273) = 0;
LABEL_141:
      LODWORD(v273) = HIDWORD(v371);
      v265 = (_DWORD *)HIDWORD(v370);
      goto LABEL_918;
    case 0x3F:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) || !LODWORD(v371) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v196 = sub_681AAA(*(_DWORD *)(*(_DWORD *)(this + 8) + 120), 0, 0, -2.0);
      v263 = *(_DWORD *)(*(_DWORD *)(this + 8) + 120);
      v352 = v196;
      v197 = sub_681AAA(v263, 0, 0, 3.0);
      v198 = v376;
      v348 = v197;
      v199 = (char *)sub_6623AF(this, 14 * v376);
      if ( !v199 )
        goto LABEL_895;
      for ( i21 = 0; i21 < 0xE; ++i21 )
      {
        *(&v314 + i21) = (int)v199;
        v199 += 4 * v198;
      }
      v201 = 0;
      while ( 1 )
      {
        v14 = sub_6624CC((void *)*(&v314 + v201), v376);
        if ( v14 < 0 )
          goto LABEL_1094;
        v201 = v202 + 1;
        if ( v201 >= 0xA )
        {
          v203 = (_DWORD *)v325;
          if ( v376 )
          {
            v349 = v326 - v325;
            v204 = v324 - v325;
            v328 = v327 - v325;
            v359 = v376;
            do
            {
              v205 = v349;
              *(_DWORD *)((char *)v203 + v204) = *(_DWORD *)(this + 36);
              *v203 = *(_DWORD *)(this + 32);
              *(_DWORD *)((char *)v203 + v205) = v352;
              *(_DWORD *)((char *)v203++ + v328) = v348;
              --v359;
            }
            while ( v359 );
          }
          v14 = sub_6624CC((void *)i12, v376);
          if ( v14 < 0 )
            goto LABEL_1094;
          v375 = v376 & 0xFFFFF;
          v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10100000, v314, Block, 0);
          if ( v14 < 0 )
            goto LABEL_1094;
          v354 = v375 | 0x20400000;
          v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20400000, (int)v315, (_DWORD *)v362, (unsigned int)v314);
          if ( v14 < 0 )
            goto LABEL_1094;
          v14 = sub_6641F3((_DWORD *)this, a2, v354, (int)v316, v363, (unsigned int)v314);
          if ( v14 < 0 )
            goto LABEL_1094;
          v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10300000, v317, v315, 0);
          if ( v14 < 0 )
            goto LABEL_1094;
          v355 = v375 | 0x20500000;
          v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20500000, (int)v318, v316, (unsigned int)v317);
          if ( v14 < 0 )
            goto LABEL_1094;
          v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20100000, (int)v319, v318, v324 | 0x400000000LL);
          if ( v14 < 0 )
            goto LABEL_1094;
          v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20000000, v320, v319, v325 | 0x1400000000LL);
          if ( v14 < 0 )
            goto LABEL_1094;
          v14 = sub_6641F3((_DWORD *)this, a2, v355, (int)v321, (_DWORD *)v320, v326 | 0x800000000LL);
          if ( v14 < 0 )
            goto LABEL_1094;
          v14 = sub_6641F3((_DWORD *)this, a2, v354, (int)v322, v321, v327);
          if ( v14 < 0 )
            goto LABEL_1094;
          v14 = sub_6641F3((_DWORD *)this, a2, v355, v323, (_DWORD *)v320, (unsigned int)v320 | 0x1400000000LL);
          if ( v14 < 0 )
            goto LABEL_1094;
          v273 = (unsigned int)v323;
          v265 = v322;
LABEL_918:
          v22 = sub_6641F3((_DWORD *)this, a2, v355, i12, v265, v273);
          goto LABEL_27;
        }
      }
    case 0x40:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v206 = sub_6623AF(this, v376);
      v373 = (int)v206;
      if ( !v206 )
        goto LABEL_895;
      v14 = sub_6624CC(v206, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10700000, v373, Block, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10300000, i12, (_DWORD *)v373, 0x400000000LL);
      goto LABEL_27;
    case 0x41:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v274 = (unsigned int)Block | 0x1700000000LL;
      v266 = (_DWORD *)v362;
      v43 = v207 & 0xFFFFF | 0x20300000;
LABEL_878:
      v22 = sub_6641F3((_DWORD *)this, a2, v43, i12, v266, v274);
      goto LABEL_27;
    case 0x42:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      v208 = v376;
      v209 = (char *)sub_6623AF(this, 3 * v376);
      if ( !v209 )
        goto LABEL_895;
      for ( i22 = 0; i22 < 3; ++i22 )
      {
        *(&v357 + i22) = (int)v209;
        v209 += 4 * v208;
      }
      v14 = sub_6624CC((void *)v357, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v358, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v359, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_664CBF((_DWORD *)this, a2, (int *)Block, (void *)v357, (void *)v358, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v376 & 0xFFFFF;
      v14 = sub_6641F3((_DWORD *)this, a2, v376 & 0xFFFFF | 0x10300000, v359, (_DWORD *)v358, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v269 = (unsigned int)v359;
      v264 = (_DWORD *)v357;
      goto LABEL_890;
    case 0x43:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v211 = sub_681AAA(*(_DWORD *)(*(_DWORD *)(this + 8) + 120), 0, 0, 1.0 / __FYL2X__(2.0, 0.6931471805599453094));
      v212 = v376;
      v359 = v211;
      v213 = (char *)sub_6623AF(this, 9 * v376);
      if ( !v213 )
        goto LABEL_895;
      for ( i23 = 0; i23 < 9; ++i23 )
      {
        (&v365)[i23] = v213;
        v213 += 4 * v212;
      }
      if ( v212 )
      {
        memset32((void *)HIDWORD(v371), v359, v376);
        v13 = 0;
      }
      v14 = sub_6624CC(v365, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v366, v215);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v367, v216);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)v368, v217);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC(v369, v218);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v370), v219);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)HIDWORD(v370), v220);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)LODWORD(v371), v221);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6624CC((void *)i12, v222);
      if ( v14 < 0 )
        goto LABEL_1094;
      v375 = v223 & 0xFFFFF;
      v355 = v223 & 0xFFFFF | 0x20500000;
      v14 = sub_6641F3((_DWORD *)this, a2, v355, (int)v365, Block, HIDWORD(v371));
      if ( v14 < 0 )
        goto LABEL_1094;
      i41 = v375 | 0x10500000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10500000, (int)v366, v365, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v373 = v375 | 0x10100000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10100000, (int)v367, v365, 0);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, i41, v368, v367, 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v373, (int)v369, (_DWORD *)v368, 0x800000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v354 = v375 | 0x20400000;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x20400000, SLODWORD(v370), v366, (unsigned int)v369);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v354, SHIDWORD(v370), v366, (unsigned int)v368 | 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v14 = sub_6641F3((_DWORD *)this, a2, v375 | 0x10300000, SLODWORD(v371), (_DWORD *)HIDWORD(v370), 0x400000000LL);
      if ( v14 < 0 )
        goto LABEL_1094;
      v273 = LODWORD(v371);
      v265 = (_DWORD *)LODWORD(v370);
      goto LABEL_918;
    case 0x44:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v224 = (int *)v362;
      for ( i24 = 0; i24 < 2; ++i24 )
      {
        *((_DWORD *)&v370 + i24) = *(_DWORD *)Block;
        *((_DWORD *)&v371 + i24) = *v224;
      }
      v359 = *v224;
      sub_666F65((_DWORD *)this, 0, (unsigned int *)&v359, 1u);
      v226 = *(_DWORD **)(this + 8);
      v227 = *(_DWORD **)(v226[5] + 4 * LODWORD(v371));
      if ( (*(_BYTE *)(*(_DWORD *)(v226[4] + 4 * v227[1]) + 4) & 0x10) == 0 || v227[4] )
        goto LABEL_937;
      v5 = v226[2] == 0;
      i41 = 0;
      if ( v5 )
        goto LABEL_935;
      v372 = v226[5];
      while ( 1 )
      {
        v228 = *(_DWORD **)v372;
        if ( v227[1] == *(_DWORD *)(*(_DWORD *)v372 + 4) && v227[2] == v228[2] && v227[3] == v228[3] && v228[4] == 1 )
          break;
        ++i41;
        v229 = *(_DWORD *)(this + 8);
        v372 += 4;
        if ( i41 >= *(_DWORD *)(v229 + 8) )
          goto LABEL_935;
      }
      HIDWORD(v371) = i41;
LABEL_935:
      if ( i41 == v226[2] )
        sub_663C69(
          this,
          (_DWORD *)a2,
          (const char *)0xDB5,
          "tex1D will considered dependent since texcoord was not declared as at least float2");
LABEL_937:
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1610612738, i12, &v370, (unsigned int)&v371);
      goto LABEL_27;
    case 0x45:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) || !LODWORD(v371) || !HIDWORD(v371) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i25 = 0; i25 < 2; ++i25 )
      {
        v231 = 4 * i25;
        (&v366)[v231 / 4u] = *(_DWORD **)Block;
        *(int *)((char *)&v368 + v231) = *(_DWORD *)v362;
        *(_DWORD *)((char *)&v370 + v231) = *v363;
        *(_DWORD *)((char *)&v371 + v231) = *v364;
      }
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1611661314, i12, &v366, (unsigned int)&v368);
      goto LABEL_27;
    case 0x46:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i26 = 0; i26 < 4; ++i26 )
        *((_DWORD *)&v370 + i26) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1612709892, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x47:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i27 = 0; i27 < 4; ++i27 )
        *((_DWORD *)&v370 + i27) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1613758468, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x48:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i28 = 0; i28 < 4; ++i28 )
        *((_DWORD *)&v370 + i28) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1614807044, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x49:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i29 = 0; i29 < 2; ++i29 )
        *(&v358 + i29) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1615855618, i12, &v358, (unsigned int)v362);
      goto LABEL_27;
    case 0x4A:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) || !LODWORD(v371) || !HIDWORD(v371) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v236 = (_DWORD *)v362;
      v352 = (int)&v368 - v362;
      i41 = (unsigned int)v363 - v362;
      v349 = (int)&v370 - v362;
      v356 = (unsigned int)v364 - v362;
      v237 = (int)&v366 - v362;
      v348 = (int)&v371 - v362;
      v359 = 2;
      do
      {
        v238 = v352;
        *(_DWORD *)((char *)v236 + v237) = *(_DWORD *)Block;
        *(_DWORD *)((char *)v236 + v238) = *v236;
        *(_DWORD *)((char *)v236 + v349) = *(_DWORD *)((char *)v236 + i41);
        *(_DWORD *)((char *)v236 + v348) = *(_DWORD *)((char *)v236 + v356);
        ++v236;
        --v359;
      }
      while ( v359 );
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1616904194, i12, &v366, (unsigned int)&v368);
      goto LABEL_27;
    case 0x4B:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i30 = 0; i30 < 4; ++i30 )
        *((_DWORD *)&v370 + i30) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1617952772, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x4C:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i31 = 0; i31 < 4; ++i31 )
        *((_DWORD *)&v370 + i31) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1619001348, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x4D:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i32 = 0; i32 < 4; ++i32 )
        *((_DWORD *)&v370 + i32) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1620049924, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x4E:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i33 = 0; i33 < 3; ++i33 )
        *((_DWORD *)&v370 + i33 + 1) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1621098499, i12, (_DWORD *)&v370 + 1, (unsigned int)v362);
      goto LABEL_27;
    case 0x4F:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) || !LODWORD(v371) || !HIDWORD(v371) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v243 = (_DWORD *)v362;
      v352 = (int)&v319 - v362;
      i41 = (unsigned int)v363 - v362;
      v349 = (int)&v322 - v362;
      v356 = (unsigned int)v364 - v362;
      v244 = (int)&v316 - v362;
      v348 = (int)&v325 - v362;
      v359 = 3;
      do
      {
        v245 = v352;
        *(_DWORD *)((char *)v243 + v244) = *(_DWORD *)Block;
        *(_DWORD *)((char *)v243 + v245) = *v243;
        *(_DWORD *)((char *)v243 + v349) = *(_DWORD *)((char *)v243 + i41);
        *(_DWORD *)((char *)v243 + v348) = *(_DWORD *)((char *)v243 + v356);
        ++v243;
        --v359;
      }
      while ( v359 );
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1622147075, i12, &v316, (unsigned int)&v319);
      goto LABEL_27;
    case 0x50:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i34 = 0; i34 < 4; ++i34 )
        *((_DWORD *)&v370 + i34) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1623195652, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x51:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i35 = 0; i35 < 4; ++i35 )
        *((_DWORD *)&v370 + i35) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1624244228, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x52:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i36 = 0; i36 < 4; ++i36 )
        *((_DWORD *)&v370 + i36) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1625292804, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x53:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i37 = 0; i37 < 3; ++i37 )
        *((_DWORD *)&v370 + i37 + 1) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1626341379, i12, (_DWORD *)&v370 + 1, (unsigned int)v362);
      goto LABEL_27;
    case 0x54:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) || !LODWORD(v371) || !HIDWORD(v371) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v250 = (_DWORD *)v362;
      v352 = (int)&v319 - v362;
      i41 = (unsigned int)v363 - v362;
      v349 = (int)&v322 - v362;
      v356 = (unsigned int)v364 - v362;
      v251 = (int)&v316 - v362;
      v348 = (int)&v325 - v362;
      v359 = 3;
      do
      {
        v252 = v352;
        *(_DWORD *)((char *)v250 + v251) = *(_DWORD *)Block;
        *(_DWORD *)((char *)v250 + v252) = *v250;
        *(_DWORD *)((char *)v250 + v349) = *(_DWORD *)((char *)v250 + i41);
        *(_DWORD *)((char *)v250 + v348) = *(_DWORD *)((char *)v250 + v356);
        ++v250;
        --v359;
      }
      while ( v359 );
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1627389955, i12, &v316, (unsigned int)&v319);
      goto LABEL_27;
    case 0x55:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i38 = 0; i38 < 4; ++i38 )
        *((_DWORD *)&v370 + i38) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1628438532, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x56:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i39 = 0; i39 < 4; ++i39 )
        *((_DWORD *)&v370 + i39) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1629487108, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x57:
      v13 = 0;
      if ( !LODWORD(v370) || !HIDWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      for ( i40 = 0; i40 < 4; ++i40 )
        *((_DWORD *)&v370 + i40) = *(_DWORD *)Block;
      v14 = sub_6624CC((void *)i12, v376);
      if ( v14 < 0 )
        goto LABEL_1094;
      v22 = sub_6641F3((_DWORD *)this, a2, 1630535684, i12, &v370, (unsigned int)v362);
      goto LABEL_27;
    case 0x58:
      v256 = LODWORD(v370);
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( i12 )
      {
        v5 = *(_DWORD *)(LODWORD(v370) + 24) == 0;
        v356 = 0;
        if ( !v5 )
        {
          v257 = *(_DWORD *)(LODWORD(v370) + 20);
          do
          {
            for ( i41 = 0; i41 < v257; v19 = a2 )
            {
              v258 = i41 + v356 * *(_DWORD *)(v19 + 24);
              v259 = *((_DWORD *)Block + v356 + i41 * *(_DWORD *)(v256 + 24));
              ++i41;
              *(_DWORD *)(i12 + 4 * v258) = v259;
              v257 = *(_DWORD *)(v256 + 20);
            }
            ++v356;
          }
          while ( v356 < *(_DWORD *)(v256 + 24) );
        }
      }
      return off_16C96E0(a2, i12);
    case 0x59:
      v13 = 0;
      if ( !LODWORD(v370) )
        goto LABEL_1093;
      if ( !i12 )
        return off_16C96E0(a2, i12);
      v260 = sub_681AAA(*(_DWORD *)(*(_DWORD *)(this + 8) + 120), 0, 0, 255.001953125);
      v332 = *((_DWORD *)Block + 2);
      v333 = *((_DWORD *)Block + 1);
      v334 = *(_DWORD *)Block;
      v335 = *((_DWORD *)Block + 3);
      LODWORD(v370) = v260;
      HIDWORD(v370) = v260;
      LODWORD(v371) = v260;
      HIDWORD(v371) = v260;
      v14 = sub_6624CC((void *)i12, 4);
      if ( v14 < 0 )
        goto LABEL_1094;
      HIDWORD(v282) = 6;
      LODWORD(v282) = &v370;
      v22 = sub_6641F3((_DWORD *)this, a2, 542113796, i12, &v332, v282);
      goto LABEL_27;
    default:
      sub_663C07(
        (_DWORD *)this,
        (_DWORD *)a2,
        3500,
        "intrinsic function '%s' is not yet implemented",
        *(const char **)(a2 + 56));
      v13 = 0;
      goto LABEL_1093;
  }
  while ( 1 )
  {
    v14 = sub_662830(this, *(_DWORD *)(a2 + i12), &v370);
    if ( v14 < 0 )
      goto LABEL_1094;
    if ( v370 <= *(double *)(this + 168) || v371 >= *(double *)(this + 160) )
    {
      if ( v370 != *(double *)(this + 160) && v371 != *(double *)(this + 168) )
        goto LABEL_416;
      v89 = *(_DWORD *)(this + 32);
    }
    else
    {
      v89 = *(_DWORD *)(this + 36);
    }
    *(_DWORD *)a2 = v89;
LABEL_416:
    ++i41;
    a2 += 4;
    if ( i41 >= v376 )
      return off_16C96E0(a2, i12);
  }
}
