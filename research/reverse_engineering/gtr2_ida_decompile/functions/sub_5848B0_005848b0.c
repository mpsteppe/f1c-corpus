void __thiscall sub_5848B0(int this)
{
  _BYTE *v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // ebp
  char v6; // bl
  char v7; // dl
  _DWORD *v8; // edi
  char v9; // bl
  char v10; // dl
  _DWORD *v11; // edi
  char v12; // bl
  char v13; // dl
  _DWORD *v14; // edi
  char v15; // bl
  char v16; // dl
  _DWORD *v17; // edi
  char v18; // bl
  char v19; // dl
  _DWORD *v20; // edi
  char v21; // bl
  char v22; // dl
  _DWORD *v23; // edi
  float *v24; // edi
  long double v25; // st7
  int v26; // ebx
  double v27; // st7
  int v28; // edi
  unsigned int v29; // edx
  float *v30; // ecx
  float *v31; // ecx
  int v32; // edx
  double v33; // st7
  int v34; // edx
  unsigned int v35; // ecx
  float *v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // ebp
  int v40; // edi
  int v41; // eax
  double v42; // st7
  int v43; // ecx
  double v44; // st7
  int v45; // eax
  int v46; // ebx
  double v47; // st7
  int v48; // ebx
  int v49; // eax
  double v50; // st7
  int v51; // eax
  int v52; // ecx
  double v53; // st7
  int v54; // ecx
  double v55; // st7
  double v56; // st7
  double v57; // st7
  unsigned __int16 *v58; // ebp
  long double v59; // st7
  float *v60; // eax
  float v61; // ecx
  float v62; // edx
  float v63; // eax
  float *v64; // eax
  float v65; // ecx
  float v66; // edx
  int v67; // ecx
  float *v68; // eax
  double v69; // st7
  float *v70; // eax
  float *v71; // eax
  double v72; // st6
  double v73; // st7
  double v74; // st6
  double v75; // st5
  double v76; // st5
  double v77; // st5
  double v78; // st5
  float v79; // edx
  float v80; // ecx
  double v81; // st7
  double v82; // st7
  double v83; // st6
  float *v84; // eax
  float *v85; // eax
  float v86; // ecx
  float v87; // edx
  float v88; // eax
  double v89; // st7
  float *v90; // eax
  float v91; // ecx
  float v92; // edx
  float *v93; // eax
  float v94; // ecx
  float v95; // edx
  int v96; // ebp
  char v97; // al
  unsigned __int8 v99; // c0
  unsigned __int8 v100; // c3
  double v101; // st7
  double v102; // st7
  double v103; // st6
  double v104; // st6
  int v105; // eax
  float v106; // ecx
  float v107; // edx
  double v108; // st6
  int v109; // eax
  float v110; // ecx
  double v111; // st7
  double v112; // st7
  int v113; // edi
  int v114; // ebx
  float *v115; // edi
  int v116; // eax
  int v117; // eax
  int v118; // eax
  _DWORD *v119; // ecx
  int v120; // eax
  double v121; // st7
  long double v122; // st7
  int v123; // edi
  int v124; // ebx
  unsigned int v125; // edx
  float *v126; // ecx
  float *v127; // ecx
  int v128; // edx
  int v129; // [esp+0h] [ebp-1BCh]
  float v130; // [esp+1Ch] [ebp-1A0h]
  float v131; // [esp+1Ch] [ebp-1A0h]
  int v132; // [esp+20h] [ebp-19Ch]
  float v133; // [esp+24h] [ebp-198h]
  float v134; // [esp+24h] [ebp-198h]
  float v135; // [esp+24h] [ebp-198h]
  float v136; // [esp+24h] [ebp-198h]
  float v137; // [esp+24h] [ebp-198h]
  float v138; // [esp+28h] [ebp-194h]
  float v139; // [esp+2Ch] [ebp-190h]
  float v140; // [esp+30h] [ebp-18Ch]
  float v141; // [esp+34h] [ebp-188h]
  float v142; // [esp+38h] [ebp-184h]
  float v143; // [esp+3Ch] [ebp-180h]
  float v144; // [esp+40h] [ebp-17Ch]
  float v145; // [esp+40h] [ebp-17Ch]
  float v146; // [esp+44h] [ebp-178h] BYREF
  float v147; // [esp+48h] [ebp-174h]
  float v148; // [esp+4Ch] [ebp-170h]
  float v149; // [esp+50h] [ebp-16Ch]
  char v150; // [esp+57h] [ebp-165h]
  float v151; // [esp+58h] [ebp-164h] BYREF
  float v152; // [esp+5Ch] [ebp-160h]
  float v153; // [esp+60h] [ebp-15Ch]
  float v154; // [esp+64h] [ebp-158h]
  float v155; // [esp+68h] [ebp-154h]
  float v156; // [esp+6Ch] [ebp-150h]
  float v157; // [esp+70h] [ebp-14Ch]
  float v158; // [esp+74h] [ebp-148h] BYREF
  float v159; // [esp+78h] [ebp-144h]
  float v160; // [esp+7Ch] [ebp-140h]
  int v161; // [esp+80h] [ebp-13Ch]
  float v162; // [esp+88h] [ebp-134h]
  float v163; // [esp+8Ch] [ebp-130h]
  float v164; // [esp+90h] [ebp-12Ch] BYREF
  float v165; // [esp+94h] [ebp-128h]
  float v166; // [esp+98h] [ebp-124h]
  float v167; // [esp+9Ch] [ebp-120h]
  float v168; // [esp+A0h] [ebp-11Ch]
  int v169; // [esp+A4h] [ebp-118h]
  float v170; // [esp+A8h] [ebp-114h]
  int v171; // [esp+ACh] [ebp-110h]
  float v172; // [esp+B0h] [ebp-10Ch]
  float v173; // [esp+BCh] [ebp-100h]
  float v174; // [esp+C0h] [ebp-FCh]
  float v175; // [esp+C4h] [ebp-F8h]
  float v176; // [esp+C8h] [ebp-F4h]
  float v177; // [esp+CCh] [ebp-F0h]
  int v178; // [esp+D0h] [ebp-ECh]
  float v179; // [esp+D4h] [ebp-E8h]
  float v180; // [esp+E0h] [ebp-DCh]
  float v181; // [esp+E4h] [ebp-D8h]
  float v182; // [esp+E8h] [ebp-D4h]
  float v183; // [esp+ECh] [ebp-D0h]
  float v184; // [esp+F0h] [ebp-CCh]
  float v185; // [esp+F4h] [ebp-C8h]
  float v186; // [esp+F8h] [ebp-C4h]
  float v187; // [esp+FCh] [ebp-C0h]
  float v188; // [esp+100h] [ebp-BCh]
  float v189; // [esp+104h] [ebp-B8h]
  float v190; // [esp+108h] [ebp-B4h]
  float v191; // [esp+10Ch] [ebp-B0h]
  float v192; // [esp+110h] [ebp-ACh]
  float v193; // [esp+114h] [ebp-A8h]
  float v194; // [esp+118h] [ebp-A4h]
  float v195; // [esp+11Ch] [ebp-A0h]
  float v196; // [esp+120h] [ebp-9Ch]
  float v197; // [esp+124h] [ebp-98h]
  float v198; // [esp+128h] [ebp-94h]
  float v199; // [esp+12Ch] [ebp-90h]
  float v200; // [esp+130h] [ebp-8Ch]
  float v201; // [esp+134h] [ebp-88h]
  float v202; // [esp+138h] [ebp-84h] BYREF
  float v203[4]; // [esp+150h] [ebp-6Ch] BYREF
  float v204[4]; // [esp+160h] [ebp-5Ch] BYREF
  float v205[4]; // [esp+170h] [ebp-4Ch] BYREF
  float v206[4]; // [esp+180h] [ebp-3Ch] BYREF
  float v207[4]; // [esp+190h] [ebp-2Ch] BYREF
  float v208[7]; // [esp+1A0h] [ebp-1Ch] BYREF

  *(_BYTE *)(this + 17693) = 0;
  v168 = 0.0;
  *(_DWORD *)(this + 184) = 0;
  v169 = 0;
  v170 = 0.0;
  *(_DWORD *)(this + 188) = 0;
  *(_DWORD *)(this + 176) = 0;
  *(_DWORD *)(this + 180) = 1065353216;
  *(_DWORD *)(this + 192) = 0;
  if ( *(_DWORD *)(this + 14804) <= 1u )
  {
    if ( *(_BYTE *)(this + 5780) )
    {
      *(_BYTE *)(this + 5780) = 0;
      v2 = (_BYTE *)(this + 5784);
      v3 = 25;
      do
      {
        *v2 = 0;
        v2 += 28;
        --v3;
      }
      while ( v3 );
    }
    v4 = this + 17712;
    v5 = 2;
    do
    {
      v6 = *(_BYTE *)(v4 - 16);
      if ( v6 )
      {
        v7 = *(_BYTE *)(v4 - 15);
        *(_BYTE *)(this + 5780) = 1;
        *(_BYTE *)(v4 - 17712 + 6149) = v7;
        *(_BYTE *)(v4 - 17712 + 6148) = v6;
        v8 = (_DWORD *)(v4 - 17712 + 6164);
        *v8 = *(_DWORD *)v4;
        v8[1] = *(_DWORD *)(v4 + 4);
        v8[2] = *(_DWORD *)(v4 + 8);
        *(_BYTE *)(v4 - 16) = 0;
      }
      v9 = *(_BYTE *)(v4 + 12);
      if ( v9 )
      {
        v10 = *(_BYTE *)(v4 + 13);
        *(_BYTE *)(this + 5780) = 1;
        *(_BYTE *)(v4 - 17712 + 6177) = v10;
        *(_BYTE *)(v4 - 17712 + 6176) = v9;
        v11 = (_DWORD *)(v4 - 17712 + 6192);
        *v11 = *(_DWORD *)(v4 + 28);
        v11[1] = *(_DWORD *)(v4 + 32);
        v11[2] = *(_DWORD *)(v4 + 36);
        *(_BYTE *)(v4 + 12) = 0;
      }
      v12 = *(_BYTE *)(v4 + 40);
      if ( v12 )
      {
        v13 = *(_BYTE *)(v4 + 41);
        *(_BYTE *)(this + 5780) = 1;
        *(_BYTE *)(v4 - 17712 + 6205) = v13;
        *(_BYTE *)(v4 - 17712 + 6204) = v12;
        v14 = (_DWORD *)(v4 - 17712 + 6220);
        *v14 = *(_DWORD *)(v4 + 56);
        v14[1] = *(_DWORD *)(v4 + 60);
        v14[2] = *(_DWORD *)(v4 + 64);
        *(_BYTE *)(v4 + 40) = 0;
      }
      v15 = *(_BYTE *)(v4 + 68);
      if ( v15 )
      {
        v16 = *(_BYTE *)(v4 + 69);
        *(_BYTE *)(this + 5780) = 1;
        *(_BYTE *)(v4 - 17712 + 6233) = v16;
        *(_BYTE *)(v4 - 17712 + 6232) = v15;
        v17 = (_DWORD *)(v4 - 17712 + 6248);
        *v17 = *(_DWORD *)(v4 + 84);
        v17[1] = *(_DWORD *)(v4 + 88);
        v17[2] = *(_DWORD *)(v4 + 92);
        *(_BYTE *)(v4 + 68) = 0;
      }
      v18 = *(_BYTE *)(v4 + 96);
      if ( v18 )
      {
        v19 = *(_BYTE *)(v4 + 97);
        *(_BYTE *)(this + 5780) = 1;
        *(_BYTE *)(v4 - 17712 + 6261) = v19;
        *(_BYTE *)(v4 - 17712 + 6260) = v18;
        v20 = (_DWORD *)(v4 - 17712 + 6276);
        *v20 = *(_DWORD *)(v4 + 112);
        v20[1] = *(_DWORD *)(v4 + 116);
        v20[2] = *(_DWORD *)(v4 + 120);
        *(_BYTE *)(v4 + 96) = 0;
      }
      v21 = *(_BYTE *)(v4 + 124);
      if ( v21 )
      {
        v22 = *(_BYTE *)(v4 + 125);
        *(_BYTE *)(this + 5780) = 1;
        *(_BYTE *)(v4 - 17712 + 6289) = v22;
        *(_BYTE *)(v4 - 17712 + 6288) = v21;
        v23 = (_DWORD *)(v4 - 17712 + 6304);
        *v23 = *(_DWORD *)(v4 + 140);
        v23[1] = *(_DWORD *)(v4 + 144);
        v23[2] = *(_DWORD *)(v4 + 148);
        *(_BYTE *)(v4 + 124) = 0;
      }
      v4 += 168;
      --v5;
    }
    while ( v5 );
    v24 = (float *)(this + 17672);
    dword_FAF5C0 = 0;
    sub_4F09D0((float *)(this + 15936), (float *)(this + 15972), (float *)(this + 17672), &v164);
    v25 = sqrt(v166 * v166 + v165 * v165 + v164 * v164) + 3.2;
    if ( v25 >= *(float *)(this + 17684) )
      v163 = v25;
    else
      v163 = *(float *)(this + 17684);
    if ( (*(_BYTE *)(*(_DWORD *)this + 22580) & 1) != 0 )
      sub_52FF30((int)dword_BE1258, this, (float *)(this + 15972), v163);
    if ( sub_5762D0(this) )
    {
      v140 = 0.0;
      sub_5767B0();
      v156 = v25;
      sub_5300D0((int)dword_BE1258, *(_DWORD *)(this + 2696), (float *)(this + 15972), v156);
    }
    *v24 = *(float *)(this + 15944) * *(float *)(this + 17668)
         + *(float *)(this + 15940) * *(float *)(this + 17664)
         + *(float *)(this + 17660) * *(float *)(this + 15936);
    *(float *)(this + 17676) = *(float *)(this + 15956) * *(float *)(this + 17668)
                             + *(float *)(this + 15952) * *(float *)(this + 17664)
                             + *(float *)(this + 15948) * *(float *)(this + 17660);
    *(float *)(this + 17680) = *(float *)(this + 15968) * *(float *)(this + 17668)
                             + *(float *)(this + 15964) * *(float *)(this + 17664)
                             + *(float *)(this + 15960) * *(float *)(this + 17660);
    *v24 = *(float *)(this + 15972) + *v24;
    *(float *)(this + 17676) = *(float *)(this + 15976) + *(float *)(this + 17676);
    *(float *)(this + 17680) = *(float *)(this + 15980) + *(float *)(this + 17680);
    ((void (__thiscall *)(int))loc_57AFF0)(this);
    if ( dword_FAF5C0 > 0 )
    {
      v26 = dword_FAF5C0;
      if ( dword_FAF5C0 > 1 )
      {
        v27 = 0.0;
        v28 = 0;
        v147 = 0.0;
        v146 = 0.0;
        v151 = 0.0;
        if ( dword_FAF5C0 >= 4 )
        {
          v29 = ((unsigned int)(dword_FAF5C0 - 4) >> 2) + 1;
          v30 = (float *)&unk_FAECC8;
          v28 = 4 * v29;
          do
          {
            if ( *(v30 - 1) > (double)v146 )
              v146 = *(v30 - 1);
            v151 = v151 + *(v30 - 1);
            if ( v27 < *v30 )
              v27 = *v30;
            v147 = v147 + *v30;
            if ( v30[17] > (double)v146 )
              v146 = v30[17];
            v151 = v151 + v30[17];
            if ( v27 < v30[18] )
              v27 = v30[18];
            v147 = v147 + v30[18];
            if ( v30[35] > (double)v146 )
              v146 = v30[35];
            v151 = v151 + v30[35];
            if ( v27 < v30[36] )
              v27 = v30[36];
            v147 = v147 + v30[36];
            if ( v30[53] > (double)v146 )
              v146 = v30[53];
            v151 = v151 + v30[53];
            if ( v27 < v30[54] )
              v27 = v30[54];
            v30 += 72;
            --v29;
            v147 = v147 + *(v30 - 18);
          }
          while ( v29 );
        }
        if ( v28 < dword_FAF5C0 )
        {
          v31 = (float *)(72 * v28 + 16444616);
          v32 = dword_FAF5C0 - v28;
          do
          {
            if ( *(v31 - 1) > (double)v146 )
              v146 = *(v31 - 1);
            v151 = v151 + *(v31 - 1);
            if ( v27 < *v31 )
              v27 = *v31;
            v31 += 18;
            --v32;
            v147 = v147 + *(v31 - 18);
          }
          while ( v32 );
        }
        if ( v151 <= 0.0 )
          v146 = 1.0;
        else
          v146 = v146 / v151;
        if ( v147 <= 0.0 )
          v33 = 1.0;
        else
          v33 = v27 / v147;
        v34 = 0;
        if ( dword_FAF5C0 >= 4 )
        {
          v35 = ((unsigned int)(dword_FAF5C0 - 4) >> 2) + 1;
          v36 = (float *)&unk_FAECC8;
          v34 = 4 * v35;
          do
          {
            v36 += 72;
            --v35;
            *(v36 - 73) = v146 * *(v36 - 73);
            *(v36 - 72) = v33 * *(v36 - 72);
            *(v36 - 55) = v146 * *(v36 - 55);
            *(v36 - 54) = v33 * *(v36 - 54);
            *(v36 - 37) = v146 * *(v36 - 37);
            *(v36 - 36) = v33 * *(v36 - 36);
            *(v36 - 19) = v146 * *(v36 - 19);
            *(v36 - 18) = v33 * *(v36 - 18);
          }
          while ( v35 );
        }
        if ( v34 < v26 )
        {
          v37 = 72 * v34 + 16444616;
          v38 = v26 - v34;
          do
          {
            v37 += 72;
            --v38;
            *(float *)(v37 - 76) = v146 * *(float *)(v37 - 76);
            *(float *)(v37 - 72) = v33 * *(float *)(v37 - 72);
          }
          while ( v38 );
        }
      }
      *(float *)&v39 = 0.0;
      v162 = 0.0;
      if ( v26 > 0 )
      {
        while ( 1 )
        {
          v40 = 72 * v39 + 16444608;
          if ( dword_FAECCC[18 * v39] != 7
            || (_UNKNOWN *)this != (_UNKNOWN *)((char *)off_757C18 + 16) && *(_DWORD *)(this + 15560) != 3 )
          {
            sub_584170(72 * v39 + 16444608);
          }
          v41 = dword_FAECCC[18 * v39];
          v144 = fabs(*((float *)&unk_FAECC4 + 18 * v39));
          v42 = *((float *)&unk_FAECC4 + 18 * v39);
          v150 = 0;
          *((float *)&unk_FAECC4 + 18 * v39) = -v42;
          switch ( v41 )
          {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
              sub_418830(*((_DWORD **)&unk_FAECD0 + 18 * v39), 72 * v39 + 16444608, *(float *)(this + 15932));
              v48 = 51;
              goto LABEL_154;
            case 7:
              v43 = *(_DWORD *)(*((_DWORD *)&unk_FAECD0 + 18 * v39) + 36);
              if ( (_UNKNOWN *)v43 != (_UNKNOWN *)((char *)off_757C18 + 16) && *(_DWORD *)(v43 + 15560) != 3 )
                sub_584170(72 * v39 + 16444608);
              v44 = (v142 - 1000.0) * 0.00025000001;
              v141 = v44;
              v131 = v44 * 3.0;
              v45 = sub_4015C0(v131);
              v46 = v45;
              if ( v45 >= 0 )
              {
                if ( v45 > 3 )
                  v46 = 3;
              }
              else
              {
                v46 = 0;
              }
              HIBYTE(v148) = byte_B71008;
              v47 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
              if ( v47 > 0.0 )
                ++v46;
              v48 = v46 + 46;
              goto LABEL_150;
            case 10:
              v49 = *((_DWORD *)&unk_FAECD0 + 18 * v39);
              if ( v49 )
              {
                v48 = *(_DWORD *)(v49 + 52);
                v50 = *(float *)(v49 + 12) * 0.0;
                v171 = v48;
                if ( 0.0 == *(float *)(v49 + 8) - v50 )
                  *(_BYTE *)(this + 17693) = 1;
              }
              else
              {
                v48 = 41;
                v171 = 41;
              }
              if ( v48 != -1 )
              {
                v143 = (v144 - 1000.0) * 0.00025000001;
                v133 = v143 * 3.0;
                v51 = sub_4015C0(v133);
                v52 = v51;
                if ( v51 >= 0 )
                {
                  if ( v51 > 3 )
                    v52 = 3;
                }
                else
                {
                  v52 = 0;
                }
                v53 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
                if ( v53 > 0.0 )
                  ++v52;
                v48 += v52;
                v171 = v48;
              }
              v54 = *((_DWORD *)&unk_FAECD0 + 18 * v39);
              if ( v54 && *(&dword_FAECC0 + 18 * v39) >= 0 && *(_BYTE *)(v54 + 40) )
                v150 = 1;
              if ( (unsigned int)*(&dword_FAECC0 + 18 * v39) >= 4
                || v144 <= (double)*(float *)(this + 19180)
                || !v54
                || !*(_BYTE *)(v54 + 42) )
              {
                goto LABEL_150;
              }
              v183 = flt_B715F0 * *((float *)&unk_FAECFC + 18 * v39);
              v173 = v183;
              v184 = flt_B715F0 * flt_FAED00[18 * v39];
              v174 = v184;
              v185 = flt_B715F0 * flt_FAED00[18 * v39 + 1];
              v175 = v185;
              v180 = v183 + *((float *)&unk_FAECD8 + 18 * v39);
              v146 = v180;
              v181 = v184 + *((float *)&unk_FAECDC + 18 * v39);
              v147 = v181;
              v182 = v185 + *((float *)&unk_FAECE0 + 18 * v39);
              v55 = *(float *)(this + 19180);
              v148 = v182;
              v56 = v55 + v55;
              if ( v56 < 1.0 )
                v56 = 1.0;
              v57 = (v144 - *(float *)(this + 19180)) / v56;
              if ( v57 <= 1.0 )
                v154 = v57;
              else
                v154 = 1.0;
              if ( !dword_BE2758 )
                goto LABEL_147;
              v58 = (unsigned __int16 *)*((_DWORD *)&unk_FAECD4 + 18 * v39);
              if ( !v58 )
                goto LABEL_147;
              v59 = *(float *)(v40 + 64);
              v151 = 0.0;
              v152 = 0.0;
              v153 = 0.0;
              if ( fabs(v59) <= 0.99000001 )
                v152 = 1.0;
              else
                v151 = 1.0;
              v60 = sub_401320(&v151, (float *)(v40 + 60), v207);
              v61 = *v60;
              v62 = v60[1];
              v63 = v60[2];
              v158 = v61;
              v159 = v62;
              v160 = v63;
              sub_409390(&v158);
              v64 = sub_401320((float *)(v40 + 60), &v158, v205);
              v65 = v64[1];
              v151 = *v64;
              v66 = v64[2];
              v152 = v65;
              v153 = v66;
              sub_409390(&v151);
              v67 = *(_DWORD *)(*((_DWORD *)v58 + 2) + 32);
              v68 = (float *)(v67 + 32 * *v58);
              v155 = v160 * v68[5] + v158 * v68[3] + v159 * v68[4];
              v69 = v153 * v68[5] + v151 * v68[3] + v152 * v68[4];
              v70 = (float *)(v67 + 32 * v58[1]);
              v156 = v160 * v70[5] + v158 * v70[3] + v159 * v70[4];
              v162 = v153 * v70[5] + v151 * v70[3] + v152 * v70[4];
              v71 = (float *)(v67 + 32 * v58[2]);
              v157 = v160 * v71[5] + v158 * v71[3] + v159 * v71[4];
              v163 = v153 * v71[5] + v151 * v71[3] + v152 * v71[4];
              v164 = v148 * v153 + v147 * v152 + v146 * v151;
              if ( v162 <= (double)v163 )
                v72 = v163;
              else
                v72 = v162;
              if ( v69 <= v72 )
              {
                if ( v162 <= (double)v163 )
                  v69 = v163;
                else
                  v69 = v162;
              }
              v73 = v69 - v164;
              v74 = v148 * v160 + v147 * v159 + v146 * v158;
              if ( v156 <= (double)v157 )
                v75 = v157;
              else
                v75 = v156;
              if ( v155 <= v75 )
              {
                if ( v156 <= (double)v157 )
                  v76 = v157;
                else
                  v76 = v156;
              }
              else
              {
                v76 = v155;
              }
              v149 = v76 - v74;
              if ( v156 >= (double)v157 )
                v77 = v157;
              else
                v77 = v156;
              if ( v155 >= v77 )
              {
                if ( v156 >= (double)v157 )
                  v78 = v157;
                else
                  v78 = v156;
              }
              else
              {
                v78 = v155;
              }
              v79 = *(float *)(dword_BE2758 + 12);
              v145 = v78 - v74;
              v80 = *(float *)(dword_BE2758 + 20);
              v166 = *(float *)(dword_BE2758 + 16);
              v165 = v79;
              v167 = v80;
              v81 = v166 * 0.5 - v73;
              if ( v81 > 0.0 )
              {
                v196 = v151 * v81;
                v186 = v196;
                v197 = v152 * v81;
                v187 = v197;
                v198 = v81 * v153;
                v188 = v198;
                v146 = v146 - v196;
                v147 = v147 - v197;
                v148 = v148 - v198;
              }
              v82 = v165 * 0.5;
              v83 = v145 + v82;
              v192 = v83;
              v164 = v82 - v149;
              if ( v83 <= 0.0 )
              {
                if ( v164 <= 0.0 )
                  goto LABEL_147;
                if ( v149 - v145 >= v165 )
                {
                  v93 = sub_4012D0(&v158, v208, v164);
                  v94 = v93[1];
                  v189 = *v93;
                  v95 = v93[2];
                  v190 = v94;
                  v146 = v146 - v189;
                  v191 = v95;
                  v147 = v147 - v94;
                  v89 = v148 - v95;
                }
                else
                {
                  v135 = (v145 + v149) * 0.5;
                  v90 = sub_4012D0(&v158, v206, v135);
                  v91 = v90[1];
                  v193 = *v90;
                  v92 = v90[2];
                  v194 = v91;
                  v195 = v92;
                  v146 = v193 + v146;
                  v147 = v91 + v147;
                  v89 = v92 + v148;
                }
              }
              else
              {
                if ( v149 - v145 < v165 )
                {
                  v134 = (v145 + v149) * 0.5;
                  v84 = sub_4012D0(&v158, v203, v134);
                  off_16C9518(*(_DWORD *)v84, *((_DWORD *)v84 + 1));
                  return;
                }
                v85 = sub_4012D0(&v158, v204, v192);
                v86 = *v85;
                v87 = v85[1];
                v88 = v85[2];
                v199 = v86;
                v200 = v87;
                v201 = v88;
                v146 = v86 + v146;
                v147 = v87 + v147;
                v89 = v88 + v148;
              }
              v148 = v89;
LABEL_147:
              v96 = off_9034A4;
              if ( dword_82F4A0 < 1023 )
              {
                ++dword_82F4A0;
                off_9034A4 += 848;
              }
              *(float *)&v132 = dbl_FB1D18;
              sub_51B2A0((_DWORD *)v96, 2, 9, 28, *(_DWORD *)(this + 4), v132, 0);
              sub_51A3B0((int *)(v96 + 8), &v146);
              sub_573990((char *)(v96 + 16), (float *)(v40 + 60));
              v136 = v154 * 255.0;
              v97 = sub_4015C0(v136);
              v48 = v171;
              *(_BYTE *)(v96 + 19) = v97;
              v39 = v161;
LABEL_150:
              if ( HIBYTE(v148) && !(v99 | v100) )
              {
                v174 = *(float *)(this + 15996) * 0.5;
                v101 = *(float *)(this + 16000);
                v166 = v174;
                v175 = v101 * 0.5;
                v102 = *(float *)(this + 16004);
                v167 = v175;
                v176 = v102 * 0.5;
                v168 = v176;
                v177 = *(float *)(v40 + 60) * 0.5;
                v103 = *(float *)(v40 + 64);
                v170 = v177;
                *(float *)&v178 = v103 * 0.5;
                v104 = *(float *)(v40 + 68);
                v171 = v178;
                v105 = 28 * *(_DWORD *)v40;
                v179 = v104 * 0.5;
                v166 = v177 + v174;
                v106 = v179;
                v107 = v166;
                v108 = *(float *)&v178 + v175 + 2.0;
                v109 = v105 + this + 5784;
                *(_BYTE *)(this + 5780) = 1;
                v167 = v108;
                v172 = v106;
                v110 = v167;
                *(_BYTE *)v109 = 8;
                v111 = v172;
                *(_BYTE *)(v109 + 1) = 8;
                v112 = v111 + v168;
                v109 += 16;
                *(float *)v109 = v107;
                *(float *)(v109 + 4) = v110;
                v168 = v112;
                *(float *)(v109 + 8) = v168;
              }
              if ( v48 != -1 )
              {
LABEL_154:
                if ( v141 > 0.0099999998 )
                {
                  if ( v141 > 1.0 )
                    v141 = 1.0;
                  if ( sub_58C190(v48) < v140 )
                  {
                    sub_4F09D0((float *)(this + 15936), (float *)(this + 15972), (float *)(v40 + 36), &v202);
                    sub_58C6C0(this + 8, v48, 2, LODWORD(v140), 1065353216, &v202);
                    v113 = off_9034A4;
                    if ( dword_82F4A0 < 1023 )
                    {
                      ++dword_82F4A0;
                      off_9034A4 += 848;
                    }
                    *(float *)&v129 = dbl_FB1D18;
                    sub_51B2A0((_DWORD *)v113, 3, 0, 3, *(_DWORD *)(this + 4), v129, 1);
                    sub_51AA40((_BYTE *)(v113 + 8), v48, 2, v140, 1.0);
                    *(float *)&v39 = v153;
                  }
                }
              }
LABEL_161:
              ++v39;
              v153 = *(float *)&v39;
              if ( v39 >= dword_FAF5C0 )
                goto LABEL_162;
              break;
            default:
              goto LABEL_161;
          }
        }
      }
LABEL_162:
      v114 = 0;
      if ( dword_FAF5C0 > 0 )
      {
        v115 = (float *)&unk_FAECD0;
        do
        {
          v116 = *((_DWORD *)v115 - 1);
          if ( v116 != 10 && v116 != 11 )
          {
            switch ( v116 )
            {
              case 0:
              case 1:
              case 2:
              case 3:
              case 4:
              case 5:
              case 6:
                v130 = *(double *)(*(_DWORD *)(*(_DWORD *)v115 + 36) + 400);
                break;
              case 7:
                v130 = *(float *)(*(_DWORD *)(*(_DWORD *)v115 + 36) + 16036);
                break;
              default:
                break;
            }
            v146 = *(float *)(this + 16036) * *(v115 - 2) / (v130 + *(float *)(this + 16036));
            *(v115 - 2) = *(v115 - 2) - v146;
          }
          if ( v116 != 7 || (_UNKNOWN *)this != (_UNKNOWN *)((char *)off_757C18 + 16) && *(_DWORD *)(this + 15560) != 3 )
            sub_5768E0((float *)this, v115 - 4);
          v117 = *((_DWORD *)v115 - 1);
          if ( v117 != 10 && v117 != 11 )
          {
            if ( v117 != 7
              || (v118 = *(_DWORD *)(*(_DWORD *)v115 + 36), (_UNKNOWN *)v118 != (_UNKNOWN *)((char *)off_757C18 + 16))
              && *(_DWORD *)(v118 + 15560) != 3 )
            {
              v119 = *(_DWORD **)v115;
              *(v115 - 2) = -v146;
              sub_416A70(v119, (int)(v115 - 4));
            }
          }
          ++v114;
          v115 += 18;
        }
        while ( v114 < dword_FAF5C0 );
      }
      if ( !*(_DWORD *)(this + 17476) )
        sub_5761B0(this);
      v120 = *(_DWORD *)(this + 17476);
      v121 = *(float *)(v120 + 4);
      v120 += 4;
      v164 = v121 - *(float *)(this + 15972);
      v137 = v164;
      v165 = *(float *)(v120 + 4) - *(float *)(this + 15976);
      v138 = v165;
      v166 = *(float *)(v120 + 8) - *(float *)(this + 15980);
      v139 = v166;
      if ( v164 != 0.0 || v165 != 0.0 || v166 != 0.0 )
      {
        v122 = 1.0 / sqrt(v166 * v166 + v165 * v165 + v164 * v164);
        v137 = v164 * v122;
        v138 = v165 * v122;
        v139 = v166 * v122;
      }
      v123 = 0;
      v124 = dword_FAF5C0;
      if ( dword_FAF5C0 >= 4 )
      {
        v125 = ((unsigned int)(dword_FAF5C0 - 4) >> 2) + 1;
        v126 = flt_FAED00;
        v123 = 4 * v125;
        do
        {
          if ( *((_DWORD *)v126 - 13) == 10 && v137 * *(v126 - 1) + v139 * v126[1] + v138 * *v126 < -0.70700002 )
            *(_BYTE *)(this + 19184) = 1;
          if ( *((_DWORD *)v126 + 5) == 10 && v137 * v126[17] + v139 * v126[19] + v138 * v126[18] < -0.70700002 )
            *(_BYTE *)(this + 19184) = 1;
          if ( *((_DWORD *)v126 + 23) == 10 && v137 * v126[35] + v139 * v126[37] + v138 * v126[36] < -0.70700002 )
            *(_BYTE *)(this + 19184) = 1;
          if ( *((_DWORD *)v126 + 41) == 10 && v139 * v126[55] + v138 * v126[54] + v137 * v126[53] < -0.70700002 )
            *(_BYTE *)(this + 19184) = 1;
          v126 += 72;
          --v125;
        }
        while ( v125 );
      }
      if ( v123 < v124 )
      {
        v127 = (float *)(72 * v123 + 16444672);
        v128 = v124 - v123;
        do
        {
          if ( *((_DWORD *)v127 - 13) == 10 && v139 * v127[1] + v137 * *(v127 - 1) + v138 * *v127 < -0.70700002 )
            *(_BYTE *)(this + 19184) = 1;
          v127 += 18;
          --v128;
        }
        while ( v128 );
      }
    }
  }
}
