double *__thiscall sub_4E5F60(int this, int a2, int a3)
{
  float v4; // edx
  float v5; // eax
  float *v6; // ecx
  float v7; // edx
  float v8; // eax
  float v9; // ecx
  float *v10; // edx
  float *v11; // eax
  int v12; // ecx
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  float *v19; // eax
  _DWORD *v20; // ecx
  int v21; // edx
  int v22; // edx
  bool v23; // zf
  _DWORD *v24; // ecx
  int v25; // eax
  double v26; // st7
  double v27; // st6
  double v28; // st7
  int v29; // ecx
  int v30; // eax
  double v31; // st7
  int v32; // eax
  float v33; // edx
  float v34; // eax
  int v35; // eax
  double v36; // st7
  double v37; // st6
  double v38; // st5
  int v39; // eax
  int v40; // ecx
  double v41; // st4
  double v42; // st4
  double v43; // st4
  double v44; // st4
  int v45; // esi
  double v46; // st7
  float v47; // ecx
  double v48; // st7
  double v49; // st7
  double v50; // st6
  double v51; // st5
  double v52; // st7
  double v53; // st7
  bool v54; // cc
  int v55; // ecx
  int v56; // eax
  double v57; // st7
  double v59; // st7
  double v60; // st7
  double v61; // st7
  double v62; // st7
  double v63; // st7
  double v64; // st7
  double v65; // st7
  double v66; // st7
  float v67; // eax
  double v68; // st7
  int v69; // esi
  int v70; // eax
  int v71; // esi
  int v72; // eax
  float *v73; // edi
  double v74; // st7
  int v75; // esi
  int v76; // edi
  double v77; // st7
  double *v78; // ecx
  double *v79; // eax
  float *v80; // esi
  double v81; // st7
  double v82; // st7
  double v83; // st6
  double v84; // st7
  double v85; // st7
  int v86; // eax
  int v87; // ecx
  double v88; // st6
  double v90; // st7
  double v91; // st6
  double v92; // st7
  double v93; // st6
  double v94; // st5
  int v95; // ecx
  double v96; // st7
  double v97; // st6
  float *v98; // esi
  double v99; // st7
  int v100; // eax
  int v101; // ecx
  double v102; // st7
  int v103; // esi
  double v104; // st7
  double v105; // st6
  void *v106; // ecx
  int v107; // edi
  void *v108; // ecx
  void *v109; // ecx
  double v110; // st7
  double v111; // st7
  int v112; // ecx
  double v113; // st7
  _DWORD *v114; // edx
  double v115; // st7
  double v116; // st7
  double v117; // st7
  double v118; // st7
  double v119; // st7
  double v120; // st7
  double v121; // st6
  double v122; // st5
  double v123; // st3
  long double v124; // st4
  double v125; // st7
  int v126; // eax
  double v127; // st7
  double v128; // st7
  double v129; // st7
  void *v130; // ecx
  void *v131; // ecx
  double v132; // st7
  float v133; // ecx
  float v134; // edx
  float v135; // eax
  double v136; // st7
  void *v137; // ecx
  float *v138; // ecx
  double v139; // st7
  double v140; // st7
  float *v141; // eax
  double v142; // st7
  double v143; // st7
  float *v144; // eax
  double v145; // st7
  int v146; // eax
  double v147; // st7
  double v148; // st7
  int v149; // eax
  float *v150; // eax
  int v151; // ecx
  int v152; // edx
  double v153; // st7
  double v154; // st6
  double v155; // st7
  double v156; // st6
  double v157; // st5
  double v158; // st4
  double v159; // st7
  double v160; // st6
  int v161; // ecx
  double v162; // st7
  int v163; // edx
  _DWORD *v164; // ecx
  _DWORD *v165; // eax
  int v166; // edx
  int v167; // edx
  float *v168; // ebx
  double *result; // eax
  float *v170; // ecx
  double v171; // st7
  float v172; // esi
  float v173; // ecx
  double v174; // st7
  float *v175; // ecx
  double v176; // st7
  double v177; // st7
  float *v178; // ecx
  double v179; // st7
  double v180; // st7
  int v181; // eax
  double v182; // st7
  float v183; // [esp+0h] [ebp-324h]
  float v184; // [esp+4h] [ebp-320h]
  float v185; // [esp+4h] [ebp-320h]
  float v186; // [esp+8h] [ebp-31Ch]
  float v187; // [esp+8h] [ebp-31Ch]
  float v188; // [esp+8h] [ebp-31Ch]
  int v189; // [esp+20h] [ebp-304h]
  int v190; // [esp+20h] [ebp-304h]
  float v191; // [esp+20h] [ebp-304h]
  float v192; // [esp+20h] [ebp-304h]
  float v193; // [esp+20h] [ebp-304h]
  float v194; // [esp+20h] [ebp-304h]
  _DWORD *v195; // [esp+20h] [ebp-304h]
  float v196; // [esp+24h] [ebp-300h]
  float v197; // [esp+24h] [ebp-300h]
  float v198; // [esp+24h] [ebp-300h]
  float v199; // [esp+24h] [ebp-300h]
  int v200; // [esp+24h] [ebp-300h]
  float v201; // [esp+28h] [ebp-2FCh]
  float v202; // [esp+2Ch] [ebp-2F8h]
  float v203; // [esp+30h] [ebp-2F4h]
  _DWORD *v204; // [esp+34h] [ebp-2F0h]
  float v205; // [esp+34h] [ebp-2F0h]
  double *v206; // [esp+34h] [ebp-2F0h]
  float v207; // [esp+38h] [ebp-2ECh]
  float v208; // [esp+38h] [ebp-2ECh]
  float v209; // [esp+38h] [ebp-2ECh]
  float v210; // [esp+38h] [ebp-2ECh]
  float v211; // [esp+3Ch] [ebp-2E8h]
  int v212; // [esp+3Ch] [ebp-2E8h]
  unsigned int v213; // [esp+40h] [ebp-2E4h]
  int v214; // [esp+40h] [ebp-2E4h]
  float v215; // [esp+44h] [ebp-2E0h]
  float v216; // [esp+44h] [ebp-2E0h]
  float v217; // [esp+44h] [ebp-2E0h]
  float v218; // [esp+48h] [ebp-2DCh] BYREF
  float v219; // [esp+4Ch] [ebp-2D8h]
  float v220; // [esp+50h] [ebp-2D4h]
  float v221; // [esp+54h] [ebp-2D0h] BYREF
  float v222; // [esp+58h] [ebp-2CCh]
  float v223; // [esp+5Ch] [ebp-2C8h]
  float v224; // [esp+60h] [ebp-2C4h]
  float v225; // [esp+64h] [ebp-2C0h]
  float v226; // [esp+68h] [ebp-2BCh]
  int v227; // [esp+6Ch] [ebp-2B8h] BYREF
  float v228; // [esp+70h] [ebp-2B4h]
  float v229; // [esp+74h] [ebp-2B0h]
  float v230; // [esp+78h] [ebp-2ACh]
  float v231; // [esp+80h] [ebp-2A4h]
  float v232; // [esp+84h] [ebp-2A0h]
  float v233; // [esp+88h] [ebp-29Ch]
  float v234; // [esp+8Ch] [ebp-298h] BYREF
  float v235; // [esp+90h] [ebp-294h]
  float v236; // [esp+94h] [ebp-290h]
  float v237; // [esp+98h] [ebp-28Ch] BYREF
  float v238; // [esp+9Ch] [ebp-288h]
  float v239; // [esp+A0h] [ebp-284h]
  float v240; // [esp+A4h] [ebp-280h] BYREF
  float v241; // [esp+A8h] [ebp-27Ch]
  float v242; // [esp+ACh] [ebp-278h]
  int v243; // [esp+B0h] [ebp-274h] BYREF
  float v244; // [esp+B4h] [ebp-270h] BYREF
  float v245; // [esp+B8h] [ebp-26Ch]
  float v246; // [esp+BCh] [ebp-268h]
  float v247; // [esp+C0h] [ebp-264h] BYREF
  float v248; // [esp+C4h] [ebp-260h]
  float v249; // [esp+C8h] [ebp-25Ch]
  float v250; // [esp+D0h] [ebp-254h]
  float v251; // [esp+D4h] [ebp-250h]
  float v252; // [esp+D8h] [ebp-24Ch]
  float v253; // [esp+DCh] [ebp-248h] BYREF
  float v254; // [esp+E0h] [ebp-244h]
  float v255; // [esp+E4h] [ebp-240h]
  float v256[2]; // [esp+ECh] [ebp-238h] BYREF
  float v257; // [esp+F4h] [ebp-230h]
  float v258; // [esp+F8h] [ebp-22Ch]
  float v259; // [esp+100h] [ebp-224h]
  float v260; // [esp+104h] [ebp-220h]
  float v261; // [esp+10Ch] [ebp-218h]
  float v262; // [esp+110h] [ebp-214h]
  float v263; // [esp+118h] [ebp-20Ch]
  float v264; // [esp+11Ch] [ebp-208h]
  int v265; // [esp+120h] [ebp-204h] BYREF
  int v266; // [esp+124h] [ebp-200h] BYREF
  int v267; // [esp+128h] [ebp-1FCh] BYREF
  float v268; // [esp+12Ch] [ebp-1F8h]
  float v269; // [esp+130h] [ebp-1F4h]
  float v270; // [esp+134h] [ebp-1F0h]
  float v271[2]; // [esp+138h] [ebp-1ECh] BYREF
  float v272; // [esp+140h] [ebp-1E4h]
  int v273; // [esp+148h] [ebp-1DCh] BYREF
  int v274; // [esp+14Ch] [ebp-1D8h] BYREF
  int v275; // [esp+150h] [ebp-1D4h] BYREF
  double *v276; // [esp+154h] [ebp-1D0h]
  int v277; // [esp+158h] [ebp-1CCh] BYREF
  int v278[2]; // [esp+15Ch] [ebp-1C8h] BYREF
  int v279[3]; // [esp+164h] [ebp-1C0h] BYREF
  int v280[3]; // [esp+170h] [ebp-1B4h] BYREF
  int v281[2]; // [esp+17Ch] [ebp-1A8h] BYREF
  char v282[4]; // [esp+184h] [ebp-1A0h] BYREF
  char v283; // [esp+188h] [ebp-19Ch] BYREF

  v4 = *(float *)(this + 1888);
  v5 = *(float *)(this + 1892);
  v224 = *(float *)(this + 1884);
  v6 = (float *)(this + 1896);
  v225 = v4;
  v7 = *v6;
  v226 = v5;
  v8 = v6[1];
  v9 = v6[2];
  v237 = v7;
  v238 = v8;
  *(_DWORD *)(this + 15348) = 1065353216;
  *(_DWORD *)(this + 15352) = -8388609;
  v239 = v9;
  v10 = v256;
  v11 = (float *)(this + 2232);
  v189 = 4;
  do
  {
    *v10 = *v11;
    v12 = *((_DWORD *)v11 + 2);
    v10[1] = v11[1];
    *((_DWORD *)v10 + 2) = v12;
    v11 += 74;
    v10 += 3;
    --v189;
  }
  while ( v189 );
  if ( *(_BYTE *)(a3 + 1354) )
  {
    v257 = (v259 + v257) * 0.5;
    v259 = v257;
    v13 = (v256[0] - v258) * 0.5;
    v256[0] = v13;
    v258 = -v13;
    v261 = (v263 + v261) * 0.5;
    v263 = v261;
    v14 = (v260 - v262) * 0.5;
    v260 = v14;
    v262 = -v14;
  }
  if ( *(double *)(a3 + 1356) != 0.0 )
  {
    v15 = (*(double *)(a3 + 1356) - (v256[0] - v258)) * 0.5;
    v256[0] = v256[0] + v15;
    v258 = v258 - v15;
  }
  if ( *(double *)(a3 + 1364) != 0.0 )
  {
    v16 = (*(double *)(a3 + 1364) - (v260 - v262)) * 0.5;
    v260 = v260 + v16;
    v262 = v262 - v16;
  }
  if ( *(double *)(a3 + 1372) != 0.0 )
  {
    v17 = (*(double *)(a3 + 1372) - (v261 - v257)) * 0.5;
    v257 = v257 - v17;
    v261 = v17 + v261;
  }
  if ( *(double *)(a3 + 1380) != 0.0 )
  {
    v18 = (*(double *)(a3 + 1380) - (v263 - v259)) * 0.5;
    v259 = v259 - v18;
    v263 = v18 + v263;
  }
  v204 = (_DWORD *)(this + 13708);
  v19 = v256;
  v20 = (_DWORD *)(this + 2232);
  v190 = 4;
  do
  {
    *v20 = *(_DWORD *)v19;
    v21 = *((_DWORD *)v19 + 2);
    v20[1] = *((_DWORD *)v19 + 1);
    v20[2] = v21;
    *v204 = *(_DWORD *)v19;
    v22 = *((_DWORD *)v19 + 2);
    v204[1] = *((_DWORD *)v19 + 1);
    v204[2] = v22;
    v20 += 74;
    v19 += 3;
    v23 = v190 == 1;
    v204 += 62;
    --v190;
  }
  while ( !v23 );
  v24 = (_DWORD *)(this + 13940);
  v25 = 0;
  v26 = (double)*(int *)(a2 + 3076) * *(double *)(a2 + 3064) + *(double *)(a2 + 3056);
  v27 = (*(float *)(this + 13708) + *(float *)(this + 14204)) * 0.5;
  *(float *)&v243 = ((*(float *)(this + 14452) + *(float *)(this + 13956)) * 0.5 - v27) * v26 + v27;
  *(float *)&v227 = *(double *)(a3 + 64) * 9.81;
  v211 = (double)*(int *)(a2 + 3140) * *(double *)(a2 + 3128) + *(double *)(a2 + 3120);
  v205 = 1.0 - v211;
  *(float *)&v267 = v205 * (1.0 - v26);
  v268 = v205 * v26;
  v269 = (1.0 - v26) * v211;
  v270 = v211 * v26;
  do
  {
    v28 = *(float *)&v227 * *(float *)((char *)&v267 + v25);
    *v24 = *(int *)((char *)&v267 + v25);
    v25 += 4;
    v24 += 62;
    *(float *)((char *)&v252 + v25) = v28;
  }
  while ( v25 < 16 );
  v29 = 0;
  *(float *)(this + 16420) = *(double *)(a3 + 96);
  v30 = a2 + 312;
  do
  {
    v31 = (double)*(int *)(v30 + 12);
    ++v29;
    v30 += 704;
    *(float *)(this + 16420) = (v31 * *(double *)(v30 - 704) + *(double *)(v30 - 712))
                             * (*((float *)&v266 + v29)
                              * 0.75)
                             + *(float *)(this + 16420);
  }
  while ( v29 < 4 );
  v32 = *(_DWORD *)(this + 12988);
  v201 = *(double *)(a3 + 112) - ((v224 + v237) * 0.5 + *(float *)&v243);
  v203 = *(double *)(a3 + 128)
       - ((*(float *)(this + 13964) + *(float *)(this + 13716)) * v205 * 0.5
        + (*(float *)(this + 14460) + *(float *)(this + 14212)) * v211 * 0.5);
  v264 = v225 - *(double *)(a3 + 120);
  v202 = -(*(double *)(a3 + 96) + v264);
  if ( !v32 )
  {
    v33 = *(float *)(this + 1840);
    v34 = *(float *)(this + 1844);
    v231 = *(float *)(this + 1836);
    v232 = v33;
    v201 = v231 - dbl_7C8A24;
    v233 = v34;
    v202 = v33 - dbl_7C8A2C;
    v203 = v34 - dbl_7C8A34;
  }
  *(float *)(this + 1836) = v201;
  *(float *)(this + 1840) = v202;
  *(float *)(this + 1844) = v203;
  *(_DWORD *)(this + 14700) = TireBrandLookup(&dword_8AD254, a3 + 136);
  LoopWithConditionalSubCall(*(_DWORD *)(a2 + 3012), 0);
  v35 = CompoundIndexLookup(*(_DWORD **)(this + 14700), *(_DWORD *)(this + 14704));
  v36 = 0.0;
  v37 = 0.0;
  v38 = 0.0;
  LODWORD(v252) = v35 + 24;
  v276 = (double *)(v35 + 352);
  v39 = a2 + 440;
  v40 = 0;
  do
  {
    v41 = (double)*(int *)(v39 + 12);
    ++v40;
    v39 += 704;
    v42 = v41 * *(double *)(v39 - 704) + *(double *)(v39 - 712);
    *(float *)((char *)&v227 + v40 * 4) = v42;
    v36 = v36 + v42;
    v43 = ((double)*(int *)(v39 - 500) * *(double *)(v39 - 512)
         + *(double *)(v39 - 520)
         + (double)*(int *)(v39 - 628) * *(double *)(v39 - 640)
         + *(double *)(v39 - 648))
        * 0.5;
    *(float *)((char *)&v246 + v40 * 4) = v43;
    v37 = v37 + v43;
    v44 = ((double)*(int *)(v39 - 436) * *(double *)(v39 - 448)
         + *(double *)(v39 - 456)
         + (double)*(int *)(v39 - 564) * *(double *)(v39 - 576)
         + *(double *)(v39 - 584))
        * 0.5;
    v271[v40 - 1] = v44;
    v38 = v38 + v44;
  }
  while ( v40 < 4 );
  v191 = v38;
  v206 = (double *)(a3 + 5120);
  v212 = a2 + 248;
  v250 = v36 * 0.25;
  v213 = 0;
  v45 = this + 13740;
  v251 = v37 * 0.25;
  v192 = v191 * 0.25;
  do
  {
    *(_DWORD *)(v45 - 8) = 0;
    *(_DWORD *)(v45 - 4) = 0;
    *(_DWORD *)v45 = 0;
    *(_DWORD *)(v45 + 4) = 0;
    *(_DWORD *)(v45 + 24) = 0;
    *(_DWORD *)(v45 + 12) = 0;
    *(_DWORD *)(v45 + 16) = 1065353216;
    *(_DWORD *)(v45 + 20) = 0;
    *(_DWORD *)(v45 + 40) = 0;
    *(_DWORD *)(v45 + 44) = 0;
    *(float *)(v45 + 48) = flt_8AFEF0 + 273.16;
    v46 = v206[12] + v206[12];
    *(float *)(v45 + 56) = v46;
    *(float *)(v45 + 60) = v46;
    *(float *)(v45 + 64) = 1.0 / v46;
    *(_DWORD *)(v45 + 68) = *(_DWORD *)(this + 13480);
    if ( !v213 || (v47 = *(float *)&v276, v213 == 1) )
      v47 = v252;
    v48 = v250;
    *(_DWORD *)(v45 + 148) = 0;
    *(_DWORD *)(v45 + 144) = 1065353216;
    *(_DWORD *)(v45 + 152) = 2096152002;
    *(_DWORD *)(v45 + 156) = 2096152002;
    *(_DWORD *)(v45 + 172) = 0;
    *(_DWORD *)(v45 + 176) = 0;
    *(_DWORD *)(v45 + 180) = 0;
    *(_DWORD *)(v45 + 184) = 0;
    *(_DWORD *)(v45 + 188) = 0;
    v215 = (v48 - *(&v228 + v213)) * *(double *)(a3 + 252) + *(&v228 + v213);
    v207 = (v251 - *(&v247 + v213)) * *(double *)(a3 + 252) + *(&v247 + v213);
    v196 = (v192 - v271[v213]) * *(double *)(a3 + 252) + v271[v213];
    v49 = VehicleSuspensionForceHelper(
            (double *)LODWORD(v47),
            (double)*(int *)(v212 + 12) * *(double *)v212 + *(double *)(v212 - 8));
    v50 = 1.0 / (v215 + v49);
    v51 = v49 * v215 * v50;
    v216 = v51;
    *(float *)(v45 + 192) = v51 * *(double *)(a3 + 260);
    *(float *)(v45 + 196) = v196 * *(double *)(a3 + 276) + v207 * *(double *)(a3 + 268);
    *(float *)(v45 + 76) = v50 * v49;
    *(float *)(v45 + 80) = fabs(*v206 - v206[1]) + 0.5;
    *(float *)(v45 - 28) = v264
                         - ((double)*(int *)(v212 + 76) * *(double *)(v212 + 64)
                          + *(double *)(v212 + 56))
                         + *(float *)(v45 + 100)
                         - *(&v253 + v213) / v216;
    *(float *)(v45 - 32) = v201 + *(float *)(v45 - 32);
    *(float *)(v45 - 28) = v202 + *(float *)(v45 - 28);
    *(float *)(v45 - 24) = v203 + *(float *)(v45 - 24);
    *(_DWORD *)(v45 + 52) = *(_DWORD *)(v45 - 28);
    if ( v213 > 1 )
      v52 = (double)*(int *)(a2 + 3524) * *(double *)(a2 + 3512) + *(double *)(a2 + 3504);
    else
      v52 = (double)*(int *)(a2 + 3460) * *(double *)(a2 + 3448) + *(double *)(a2 + 3440);
    v217 = v52;
    if ( v213 && v213 != 2 )
    {
      v217 = -v217;
      v53 = (double)*(int *)(v212 - 52) * *(double *)(v212 - 64) + *(double *)(v212 - 72);
    }
    else
    {
      v53 = -((double)*(int *)(v212 - 52) * *(double *)(v212 - 64) + *(double *)(v212 - 72));
    }
    v197 = v53;
    WheelSuspensionTireStateInit((float *)(this + 1764), v213, (float *)(v45 - 32), 0.0, v217, v197);
    v45 += 248;
    v54 = (int)++v213 < 4;
    v206 += 33;
    v212 += 704;
  }
  while ( v54 );
  v55 = 0;
  v56 = this + 13828;
  do
  {
    *(_DWORD *)(v56 - 4) = 0;
    if ( (unsigned int)v55 > 1 )
      v57 = *(float *)(this + 13716);
    else
      v57 = *(float *)(this + 14212);
    ++v55;
    v56 += 248;
    *(float *)(v56 - 248) = (1.0 - *(double *)(a3 + 260))
                          * fabs(v57 / (*(float *)(this + 13716) - *(float *)(this + 14212)))
                          * -0.5;
    *(float *)(v56 - 244) = (1.0 - *(double *)(a3 + 260)) * 0.25 / *(float *)(v56 - 360);
    *(float *)(v56 - 240) = (1.0 - *(double *)(a3 + 260)) * -0.25 / *(float *)(v56 - 368);
  }
  while ( v55 < 4 );
  *(float *)(this + 14712) = (double)*(int *)(a2 + 3268) * *(double *)(a2 + 3256) + *(double *)(a2 + 3248);
  v59 = (double)(*(_DWORD *)(a2 + 3264) - 1) * *(double *)(a2 + 3256) + *(double *)(a2 + 3248);
  *(float *)(this + 14716) = v59;
  *(float *)(this + 14720) = 1.0 / v59;
  *(float *)(this + 14724) = (double)dword_7D0B64 * *(double *)(a3 + 1652) * flt_7D01E8;
  PitPartStateCopy(this + 12992, a2);
  v60 = *(double *)(a3 + 64);
  *(float *)(this + 13584) = v60;
  v61 = v60 + *(float *)(this + 14712) * 0.75;
  *(float *)(this + 13588) = v61;
  *(float *)(this + 13592) = 1.0 / v61;
  *(float *)(this + 13596) = *(double *)(a3 + 72);
  *(float *)(this + 13600) = *(double *)(a3 + 80);
  *(float *)(this + 13604) = *(double *)(a3 + 88);
  *(float *)(this + 13608) = 1.0 / *(float *)(this + 13596);
  *(float *)(this + 13612) = 1.0 / *(float *)(this + 13600);
  *(float *)(this + 13616) = 1.0 / *(float *)(this + 13604);
  *(float *)(this + 13668) = *(double *)(a3 + 300);
  *(float *)(this + 13672) = *(double *)(a3 + 308);
  *(float *)(this + 13676) = *(double *)(a3 + 316);
  v62 = (double)(*(_DWORD *)(a2 + 5184) - 1) * *(double *)(a2 + 5176) + *(double *)(a2 + 5168);
  *(float *)(this + 14688) = v62;
  *(float *)(this + 4152) = v62;
  v63 = (double)*(int *)(a2 + 3332) * *(double *)(a2 + 3320) + *(double *)(a2 + 3312);
  RandomOffsetCalculator(v63);
  v208 = v63;
  v64 = (double)*(int *)(a2 + 3396) * *(double *)(a2 + 3384) + *(double *)(a2 + 3376);
  BiasValueComputation(v64);
  *(float *)(this + 14708) = (v64 + v208) * *(double *)(a3 + 260) * 0.25;
  v65 = *(double *)(a3 + 4980) + *(double *)(a3 + 1668);
  *(_DWORD *)(this + 14740) = 0;
  *(float *)(this + 14728) = v65;
  *(float *)(this + 14732) = 1.0 / v65;
  *(float *)(this + 14744) = (double)*(int *)(a2 + 5508) * *(double *)(a2 + 5496) + *(double *)(a2 + 5488);
  *(float *)(this + 14748) = (*(double *)(a3 + 1684) + *(double *)(a3 + 1676)) * 0.5;
  *(_DWORD *)(this + 14772) = *(_DWORD *)(a3 + 5056);
  *(_BYTE *)(this + 14828) = 0;
  *(_BYTE *)(this + 14829) = *(double *)(a3 + 1700) > 0.0;
  v66 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 0.0;
  v67 = *(float *)(this + 14744);
  *(float *)(this + 14736) = v66 + *(double *)(a3 + 1708);
  if ( *(float *)(this + 14748) <= (double)*(float *)(this + 14736) )
  {
    if ( *(float *)(this + 14736) > (double)v67 )
      *(float *)(this + 14736) = v67;
  }
  else
  {
    *(float *)(this + 14736) = *(float *)(this + 14748);
  }
  *(_DWORD *)(this + 14776) = 0;
  *(float *)(this + 14780) = *(double *)(a3 + 4956);
  *(float *)(this + 14784) = *(double *)(a3 + 4964);
  *(float *)(this + 14788) = *(double *)(a3 + 4972);
  v209 = *(double *)(a3 + 1676) * 0.94;
  *(float *)(this + 136) = *(float *)(this + 14744) * 1.02;
  ArithmeticComparison_8330(this + 8);
  *(float *)(this + 140) = v209;
  ArithmeticComparison_8330(this + 8);
  v68 = *(float *)(this + 14744) * -0.03125;
  v69 = 0;
  *(_DWORD *)(this + 14760) = 0;
  *(_DWORD *)(this + 14764) = 0;
  v70 = CRTFtol(v68);
  *(_DWORD *)(this + 14768) = 2 - v70;
  *(_DWORD *)(this + 14756) = OperatorNewNhMallocWrapper(8 * (2 - v70));
  v214 = 0;
  if ( *(int *)(this + 14768) > 0 )
  {
    do
    {
      ParameterizedCurveInterpolation((double)v214 * 32.0, (int)v278, (int)v281);
      ++v69;
      *(float *)(*(_DWORD *)(this + 14756) + 8 * v69 - 8) = *(double *)v278 - *(double *)(a3 + 5004);
      v214 = v69;
      *(float *)(*(_DWORD *)(this + 14756) + 8 * v69 - 4) = *(double *)v281 - *(double *)v278;
    }
    while ( v69 < *(_DWORD *)(this + 14768) );
  }
  v71 = 0;
  *(_DWORD *)(this + 14792) = 0;
  *(_BYTE *)(this + 14830) = 0;
  *(_DWORD *)(this + 14832) = 0;
  *(_DWORD *)(this + 14836) = -2;
  v72 = *(_DWORD *)(a3 + 5060);
  *(_DWORD *)(this + 14840) = v72;
  if ( v72 >= 0 )
  {
    v73 = (float *)(this + 14796);
    do
    {
      *v73 = SessionStateIndexedLookup((int *)a2, v71 + 43);
      if ( v71 == 7 )
        v73 += 918;
      else
        ++v73;
      ++v71;
    }
    while ( v71 <= *(_DWORD *)(this + 14840) );
  }
  *(float *)(this + 14844) = *(double *)(a3 + 5032) * 0.4000000059604645 + *(double *)(a3 + 5024);
  *(float *)(this + 14848) = *(double *)(a3 + 5048) * 0.4000000059604645 + *(double *)(a3 + 5040);
  *(_DWORD *)(this + 14852) = 0;
  v74 = *(float *)(this + 14744);
  *(_DWORD *)(this + 14856) = 0;
  *(float *)(this + 14860) = v74 * 0.97500002;
  v193 = *(float *)(this + 14748) * 1.03;
  *(float *)(this + 14864) = v193;
  qmemcpy((void *)(this + 14868), (const void *)(this + 14864), 0x1Cu);
  v75 = 2;
  if ( *(int *)(this + 14840) >= 2 )
  {
    v178 = (float *)(this + 14804);
    do
    {
      if ( v75 == 8 )
      {
        v178 += 917;
        v179 = *v178 / *(v178 - 918);
      }
      else
      {
        v179 = *v178 / *(v178 - 1);
      }
      v180 = v179 * *(float *)(this + 14860) * 0.82499999;
      if ( v180 < v193 )
        v180 = v193;
      v181 = *(_DWORD *)(this + 14840);
      if ( v75 < 8 )
        v178[17] = v180;
      else
        v178[10] = v180;
      ++v75;
      ++v178;
    }
    while ( v75 <= v181 );
  }
  v76 = 0;
  v77 = (double)*(int *)(a2 + 4932) * *(double *)(a2 + 4920) + *(double *)(a2 + 4912);
  do
  {
    if ( v76 )
    {
      v78 = (double *)(a3 + 5600);
      v79 = (double *)(a3 + 5864);
      v80 = (float *)(this + 14916);
    }
    else
    {
      v78 = (double *)(a3 + 5072);
      v79 = (double *)(a3 + 5336);
      v80 = (float *)(this + 14896);
    }
    ++v76;
    *v80 = (v79[22] + v78[22]) * 0.5;
    v80[1] = (v79[21] + v78[21]) * 0.5;
    v80[2] = (v79[25] + v78[25]) * 0.5600000023841858;
    v80[3] = (v79[26] + v78[26]) * 0.5600000023841858;
    v80[4] = (v77 * v79[28] + v79[27] + v77 * v78[28] + v78[27]) * 0.5600000023841858;
  }
  while ( v76 < 2 );
  v81 = (double)*(int *)(a2 + 4996) * *(double *)(a2 + 4984) + *(double *)(a2 + 4976);
  v198 = (1.0 - v81) * *(float *)(this + 14896);
  *(float *)(this + 14896) = v198;
  v82 = v81 * *(float *)(this + 14916);
  *(float *)(this + 14916) = v82;
  if ( v198 == 0.0 )
  {
    *(_DWORD *)(this + 13848) = 0;
    *(_DWORD *)(this + 14096) = 0;
  }
  else
  {
    v83 = 1.0 / v198;
    *(float *)(this + 13848) = v83;
    *(float *)(this + 14096) = v83;
  }
  if ( v82 == 0.0 )
  {
    *(_DWORD *)(this + 14344) = 0;
    *(_DWORD *)(this + 14592) = 0;
  }
  else
  {
    v84 = 1.0 / v82;
    *(float *)(this + 14344) = v84;
    *(float *)(this + 14592) = v84;
  }
  v85 = 0.0;
  v86 = a2 + 312;
  v87 = 4;
  do
  {
    v88 = (double)*(int *)(v86 + 12);
    v86 += 704;
    --v87;
    v85 = v85 + v88 * *(double *)(v86 - 704) + *(double *)(v86 - 712);
  }
  while ( v87 );
  v194 = v85 * 0.1;
  v249 = (*(float *)(this + 13716) + *(float *)(this + 13964)) * 0.5;
  v230 = (*(float *)(this + 14212) + *(float *)(this + 14460)) * 0.5;
  v186 = (double)*(int *)(a2 + 3588) * *(double *)(a2 + 3576) + *(double *)(a2 + 3568);
  QuadraticCubicPolynomialEvaluator(v186, (int)&v277, (int)&v273);
  v187 = (double)*(int *)(a2 + 3652) * *(double *)(a2 + 3640) + *(double *)(a2 + 3632);
  QuadraticCubicPolynomialEvaluator(v187, (int)&v274, (int)&v275);
  v251 = v249 + *(double *)(a3 + 752);
  v184 = (double)*(int *)(a2 + 4740) * *(double *)(a2 + 4728) + *(double *)(a2 + 4720);
  TireForceTorqueComputation(v184, v194, (int)v279, (int)&v265);
  v210 = v230 + *(double *)(a3 + 1004);
  v188 = (double)*(int *)(a2 + 4804) * *(double *)(a2 + 4792) + *(double *)(a2 + 4784);
  QuadraticForceModel(v188, (int)v280, (int)&v266);
  v252 = v230 + *(double *)(a3 + 1060);
  v185 = (double)*(int *)(a2 + 4868) * *(double *)(a2 + 4856) + *(double *)(a2 + 4848);
  v183 = (double)*(int *)(a2 + 4932) * *(double *)(a2 + 4920) + *(double *)(a2 + 4912);
  LinearVehicleParameterEvaluation(v183, v185, v194, (int)&v267, (int)&v227);
  v250 = v230 + *(double *)(a3 + 1296);
  QuadraticForceTorqueCurveEvaluation(v194, (int)&v243);
  v90 = *(float *)&v274 + *(float *)&v277;
  v91 = *(float *)v279;
  *(_DWORD *)(this + 14936) = 0;
  *(_DWORD *)(this + 14940) = 0;
  *(_DWORD *)(this + 14944) = 0;
  v229 = *(float *)&v279[1] + v90;
  v230 = *(float *)&v279[2] + v90;
  v92 = *(float *)v280 + v91 + v90;
  v93 = *(float *)&v280[1] + v229;
  v230 = *(float *)&v280[2] + v230;
  v231 = *(float *)&v267 + v92;
  v94 = v268;
  *(float *)(this + 14948) = v231;
  v232 = v94 + v93;
  *(float *)(this + 14952) = v232;
  v233 = v269 + v230;
  *(float *)(this + 14956) = v233;
  v95 = *(_DWORD *)(this + 14956);
  v96 = *(float *)&v243 + *(float *)&v227;
  *(_DWORD *)(this + 14964) = 0;
  v97 = *(float *)&v266;
  *(_DWORD *)(this + 14968) = v95;
  v199 = -(v97 + v96 + *(float *)&v265 + *(float *)&v275 + *(float *)&v273);
  *(float *)(this + 14960) = v199;
  *(float *)(this + 14972) = v199;
  *(float *)(this + 14976) = -v96;
  if ( v199 != 0.0 )
    *(float *)(this + 14964) = -((*(float *)&v266 * v210
                                + *(float *)&v265 * v251
                                + *(float *)&v243 * v250
                                + *(float *)&v227 * v252)
                               / v199);
  *(float *)(this + 14964) = (*(double *)(a3 + 284) - *(float *)(this + 14964)) * *(double *)(a3 + 292)
                           + *(float *)(this + 14964);
  qmemcpy((void *)(this + 15736), (const void *)(a3 + 6128), 0x278u);
  if ( *(_DWORD *)(this + 3272)
    && *(float *)(this + 15772) == 0.0
    && *(float *)(this + 15776) == 0.0
    && *(float *)(this + 15780) == 0.0 )
  {
    TripleFieldQuery(this + 15772, this + 15776, this + 15780);
  }
  *(float *)(this + 15772) = v201 + *(float *)(this + 15772);
  *(float *)(this + 15776) = v202 + *(float *)(this + 15776);
  *(float *)(this + 15780) = v203 + *(float *)(this + 15780);
  if ( *(_DWORD *)(this + 3340)
    && *(float *)(this + 15820) == 0.0
    && *(float *)(this + 15824) == 0.0
    && *(float *)(this + 15828) == 0.0 )
  {
    TripleFieldQuery(this + 15820, this + 15824, this + 15828);
  }
  v195 = (_DWORD *)(this + 3408);
  v98 = (float *)(this + 16056);
  v200 = 8;
  *(float *)(this + 15820) = v201 + *(float *)(this + 15820);
  *(float *)(this + 15824) = v202 + *(float *)(this + 15824);
  *(float *)(this + 15828) = v203 + *(float *)(this + 15828);
  do
  {
    if ( *v195 && *(v98 - 2) == 0.0 && *(v98 - 1) == 0.0 && *v98 == 0.0 )
      TripleFieldQuery(v98 - 2, v98 - 1, v98);
    v99 = v201 + *(v98 - 2);
    v98 += 3;
    *(v98 - 5) = v99;
    v195 += 17;
    --v200;
    *(v98 - 4) = v202 + *(v98 - 4);
    *(v98 - 3) = v203 + *(v98 - 3);
  }
  while ( v200 );
  *(_DWORD *)(this + 15004) = 0;
  *(_DWORD *)(this + 15188) = 0;
  *(_DWORD *)(this + 15192) = 0;
  *(_DWORD *)(this + 15196) = 0;
  F_3x3MatrixTransformWithTranslation(this);
  *(_DWORD *)(this + 15336) = 0;
  *(_DWORD *)(this + 15340) = 0;
  *(_DWORD *)(this + 15344) = 0;
  v100 = this + 13716;
  v101 = 4;
  do
  {
    v102 = *(float *)(v100 - 8);
    v100 += 248;
    --v101;
    *(float *)(this + 15336) = v102 + *(float *)(this + 15336);
    *(float *)(this + 15340) = *(float *)(v100 - 252) + *(float *)(this + 15340);
    *(float *)(this + 15344) = *(float *)(this + 15344) + *(float *)(v100 - 248);
  }
  while ( v101 );
  v103 = 0;
  *(float *)(this + 15336) = *(float *)(this + 15336) * 0.25;
  *(float *)(this + 15340) = *(float *)(this + 15340) * 0.25;
  *(float *)(this + 15344) = *(float *)(this + 15344) * 0.25;
  *(_DWORD *)(this + 15212) = 0;
  *(_BYTE *)(this + 15220) = 0;
  *(_BYTE *)(this + 15221) = 0;
  do
  {
    if ( v103 < 4 )
    {
      if ( (unsigned int)v103 > 1 )
        v104 = 1.0;
      else
        v104 = -1.0;
      if ( v103 && v103 != 2 )
        v105 = -1.0;
      else
        v105 = 1.0;
      v106 = *(void **)(this + 1768);
      v271[0] = v105;
      v272 = v104;
      v271[1] = 0.0;
      sub_4DD7C0(v106, v271, &v240);
      v221 = v240;
      v107 = 296 * v103 + this;
      v108 = *(void **)(v107 + 2088);
      v222 = v241;
      v223 = v242;
      if ( v108 )
      {
        sub_4DD7C0(v108, v271, &v221);
        v221 = v221 + *(float *)(v107 + 2092);
        v222 = v222 + *(float *)(v107 + 2096);
        v223 = v223 + *(float *)(v107 + 2100);
      }
      v218 = v240;
      v219 = v241;
      v220 = v242;
      if ( (unsigned int)v103 <= 1 )
      {
        v109 = *(void **)(this + 3272);
        if ( v109 )
        {
          sub_4DD7C0(v109, v271, &v218);
          v218 = v218 + *(float *)(this + 3276);
          v219 = v219 + *(float *)(this + 3280);
          v220 = v220 + *(float *)(this + 3284);
          v242 = v220;
        }
      }
      if ( v103 && v103 != 2 )
      {
        if ( v221 >= (double)v218 )
          v113 = v218;
        else
          v113 = v221;
        if ( v240 >= v113 )
        {
          if ( v221 >= (double)v218 )
            v111 = v218;
          else
            v111 = v221;
        }
        else
        {
          v111 = v240;
        }
        v112 = this + 12 * v103;
      }
      else
      {
        if ( v221 <= (double)v218 )
          v110 = v218;
        else
          v110 = v221;
        if ( v240 <= v110 )
        {
          if ( v221 <= (double)v218 )
            v111 = v218;
          else
            v111 = v221;
          v112 = this + 12 * v103;
        }
        else
        {
          v111 = v240;
          v112 = this + 12 * v103;
        }
      }
      v114 = (_DWORD *)(this + 4 * (3 * v103 + 3759));
      *(float *)(v112 + 15032) = v111 + v201;
      *v114 = 0;
      if ( (unsigned int)v103 > 1 )
      {
        if ( v223 <= (double)v220 )
          v117 = v220;
        else
          v117 = v223;
        if ( v242 > v117 )
        {
          v116 = v242;
          goto LABEL_137;
        }
        if ( v223 > (double)v220 )
        {
          v116 = v223;
          goto LABEL_137;
        }
      }
      else
      {
        if ( v223 >= (double)v220 )
          v115 = v220;
        else
          v115 = v223;
        if ( v242 < v115 )
        {
          v116 = v242;
          goto LABEL_137;
        }
        if ( v223 < (double)v220 )
        {
          v116 = v223;
          goto LABEL_137;
        }
      }
      v116 = v220;
LABEL_137:
      *(float *)(v112 + 15040) = v116 + v203;
      if ( (*(_BYTE *)(a3 + 60) & 1) == 0 )
      {
LABEL_149:
        if ( (*(_BYTE *)(a3 + 60) & 2) != 0 )
          *v114 = -1133133169;
        if ( (*(_BYTE *)(a3 + 60) & 4) != 0 )
        {
          if ( v103 && v103 != 2 )
            v120 = *(float *)(v112 + 15032) - 0.059999999;
          else
            v120 = *(float *)(v112 + 15032) + 0.059999999;
          *(float *)(v112 + 15032) = v120;
        }
        goto LABEL_156;
      }
      if ( v103 )
      {
        if ( v103 == 1 )
        {
          v231 = v201 + v224;
          v118 = v226;
        }
        else
        {
          if ( v103 == 2 )
          {
            v119 = v201 + v237;
          }
          else
          {
            if ( v103 != 3 )
            {
LABEL_148:
              *(float *)(v112 + 15032) = v231 * 0.62 + *(float *)(v112 + 15032) * 0.38;
              *(float *)(v112 + 15040) = v233 * 0.62 + *(float *)(v112 + 15040) * 0.38;
              goto LABEL_149;
            }
            v119 = v201 + v224;
          }
          v231 = v119;
          v118 = v239;
        }
      }
      else
      {
        v231 = v201 + v237;
        v118 = v226;
      }
      v233 = v118 + v203;
      goto LABEL_148;
    }
    if ( v103 >= 8 )
    {
      if ( v103 >= 12 )
      {
        v148 = v202 + v225;
        v149 = this + 12 * v103 + 15032;
        *(_DWORD *)v149 = 0;
        *(_DWORD *)(v149 + 8) = 0;
        *(float *)(v149 + 4) = v148 * 0.5;
      }
      else
      {
        if ( v103 == 8 || v103 == 9 )
        {
          if ( (*(_BYTE *)(a3 + 60) & 8) != 0 )
          {
            if ( v103 == 8 )
              v136 = -0.5;
            else
              v136 = 0.5;
            v236 = -0.1;
          }
          else
          {
            if ( v103 == 8 )
              v136 = -0.1;
            else
              v136 = 0.1;
            v236 = 0.0;
          }
          v137 = *(void **)(this + 1768);
          v234 = v136;
          v235 = 1.0;
          sub_4DD7C0(v137, &v234, &v244);
          v138 = (float *)(this + 12 * v103 + 15032);
          v247 = v244 + v201;
          v139 = v245;
          *v138 = v247;
          v248 = v139 + v202;
          v140 = v246;
          v138[1] = v248;
          v249 = v140 + v203;
          v138[2] = v249;
        }
        else
        {
          if ( (*(_BYTE *)(a3 + 60) & 8) != 0 )
          {
            if ( v103 == 10 )
              v129 = -0.5;
            else
              v129 = 0.5;
          }
          else if ( v103 == 10 )
          {
            v129 = -0.1;
          }
          else
          {
            v129 = 0.1;
          }
          v130 = *(void **)(this + 1768);
          v234 = v129;
          v235 = 1.0;
          v236 = 0.80000001;
          sub_4DD7C0(v130, &v234, &v244);
          v131 = *(void **)(this + 3340);
          if ( v131 )
          {
            sub_4DD7C0(v131, &v234, &v253);
            v253 = v253 + *(float *)(this + 3344);
            v254 = v254 + *(float *)(this + 3348);
            v132 = v255 + *(float *)(this + 3352);
            v255 = v132;
            if ( v246 * v236 + v245 * v235 + v244 * v234 < v132 * v236 + v254 * v235 + v253 * v234 )
            {
              v133 = v253;
              v134 = v254;
              v135 = v255;
              *(_BYTE *)(this + 15220) = 1;
              v244 = v133;
              v245 = v134;
              v246 = v135;
            }
          }
        }
        v141 = (float *)(this + 12 * v103);
        v228 = v244 + v201;
        v142 = v245;
        v141[3758] = v228;
        v229 = v142 + v202;
        v143 = v246;
        v141[3759] = v229;
        v230 = v143 + v203;
        v141[3760] = v230;
        if ( (*(_BYTE *)(a3 + 60) & 4) != 0 )
        {
          if ( v103 - 8 >= 2 )
          {
            v146 = 3 * v103 + 3759;
            v147 = *(float *)(this + 4 * v146);
            v144 = (float *)(this + 4 * v146);
            v145 = v147 + 0.40000001;
          }
          else
          {
            v141[3760] = v141[3760] - 0.25;
            v144 = (float *)(this + 4 * (3 * v103 + 3759));
            v145 = *v144 + 0.2;
          }
          *v144 = v145;
        }
      }
    }
    else
    {
      if ( v103 == 4 )
      {
        v125 = v226 + v203;
        v126 = this + 15080;
        *(_DWORD *)(this + 15080) = 0;
        *(float *)(this + 15088) = v125;
      }
      else if ( v103 == 5 )
      {
        v127 = v239 + v203;
        v126 = this + 15092;
        *(_DWORD *)(this + 15092) = 0;
        *(float *)(this + 15100) = v127;
      }
      else
      {
        if ( v103 == 6 )
        {
          v128 = v201 + v224;
          v126 = this + 15104;
        }
        else
        {
          v128 = v201 + v237;
          v126 = this + 15116;
        }
        *(float *)v126 = v128;
        *(_DWORD *)(v126 + 8) = 0;
      }
      *(_DWORD *)(v126 + 4) = 0;
      if ( (*(_BYTE *)(a3 + 60) & 2) != 0 )
        *(float *)(this + 4 * (3 * v103 + 3759)) = *(float *)(this + 4 * (3 * v103 + 3759)) - 0.015;
      if ( (*(_BYTE *)(a3 + 60) & 4) != 0 )
      {
        if ( v103 == 6 )
        {
          *(float *)(this + 15104) = *(float *)(this + 15104) - 0.07;
        }
        else if ( v103 == 7 )
        {
          *(float *)(this + 15116) = *(float *)(this + 15116) + 0.07;
        }
      }
    }
LABEL_156:
    v121 = *(float *)(this + 12 * v103 + 15036);
    v122 = *(float *)(this + 12 * v103 + 15032);
    v123 = *(float *)(this + 12 * v103 + 15040);
    v124 = sqrt(v122 * v122 + v121 * v121 + v123 * v123);
    if ( v124 > *(float *)(this + 15212) )
      *(float *)(this + 15212) = v124;
    ++v103;
  }
  while ( v103 < 13 );
  v150 = (float *)&v283;
  v151 = this + 15036;
  v152 = 13;
  *(float *)(this + 15216) = *(float *)(this + 15212) + 0.1;
  do
  {
    v151 += 12;
    *(v150 - 1) = -v201;
    v150 += 8;
    --v152;
    *(v150 - 8) = -v202;
    *(v150 - 7) = -v203;
    *(v150 - 6) = *(float *)(v151 - 16) - v201;
    *(v150 - 5) = *(float *)(v151 - 12) - v202;
    *(v150 - 4) = *(float *)(v151 - 8) - v203;
  }
  while ( v152 );
  VertexParticleBufferAllocator(v282, 13);
  *(_BYTE *)(this + 16368) = 0;
  *(_DWORD *)(this + 16372) = 0;
  *(_DWORD *)(this + 16376) = 0;
  *(_DWORD *)(this + 16380) = 0;
  *(_DWORD *)(this + 0x4000) = 0;
  *(_DWORD *)(this + 16388) = 0;
  *(_DWORD *)(this + 16392) = 0;
  *(_DWORD *)(this + 16396) = 0;
  *(_DWORD *)(this + 16400) = 0;
  v153 = *(float *)(this + 13708) + *(float *)(this + 13956);
  v154 = *(float *)(this + 13712) + *(float *)(this + 13960);
  v249 = *(float *)(this + 13716) + *(float *)(this + 13964);
  v228 = v153 * 0.5;
  v247 = v228;
  v229 = v154 * 0.5;
  v248 = v229;
  v230 = v249 * 0.5;
  v249 = v230;
  v155 = -*(double *)(a3 + 96);
  v248 = v155;
  v156 = *(float *)(this + 14204) + *(float *)(this + 14452);
  v157 = *(float *)(this + 14208) + *(float *)(this + 14456);
  v158 = *(float *)(this + 14212) + *(float *)(this + 14460);
  *(_DWORD *)(this + 15688) = 0;
  *(_DWORD *)(this + 15692) = 0;
  *(_DWORD *)(this + 15696) = 0;
  v272 = v158;
  v228 = v156 * 0.5;
  v237 = v228;
  v229 = v157 * 0.5;
  v230 = v272 * 0.5;
  v239 = v230;
  v238 = v155;
  v159 = v230 + *(double *)(a3 + 4944);
  v160 = v238 + *(double *)(a3 + 4936);
  *(float *)(this + 15700) = v228 + *(double *)(a3 + 4928);
  *(float *)(this + 15704) = v160;
  *(float *)(this + 15708) = v159;
  *(_DWORD *)(this + 28) = *(_DWORD *)(this + 15700);
  *(_DWORD *)(this + 32) = *(_DWORD *)(this + 15704);
  *(_DWORD *)(this + 36) = *(_DWORD *)(this + 15708);
  *(_DWORD *)(this + 15712) = 0;
  EngineWearFailureSimulation(a3);
  *(_DWORD *)(this + 16404) = 0;
  *(_BYTE *)(this + 16408) = 0;
  *(_DWORD *)(this + 16412) = 0;
  *(_DWORD *)(this + 16416) = RandLCGRandomNumberGenerator(v161);
  v162 = *(float *)(this + 14744);
  v163 = *(_DWORD *)(this + 14840);
  if ( v163 > 7 )
    v182 = v162 / *(float *)(this + 4 * v163 + 18464);
  else
    v182 = v162 / *(float *)(this + 4 * v163 + 14796);
  v164 = (_DWORD *)(this + 4216);
  v165 = (_DWORD *)(this + 15032);
  v227 = 13;
  *(float *)(this + 14696) = v182;
  do
  {
    *v164 = *v165;
    v166 = v165[2];
    v164[1] = v165[1];
    v164[2] = v166;
    v165 += 3;
    v164 += 7;
    --v227;
  }
  while ( *(float *)&v227 != 0.0 );
  v167 = 0;
  v168 = (float *)(this + 4580);
  result = (double *)(a3 + 5200);
  do
  {
    if ( (unsigned int)v167 > 1 )
      v170 = &v237;
    else
      v170 = &v247;
    v171 = *(result - 1);
    v224 = *v170;
    v172 = v170[1];
    v173 = v170[2];
    v224 = v171 + v224;
    v225 = v172;
    v174 = *result + v172;
    v226 = v173;
    v175 = v168;
    ++v167;
    v225 = v174;
    result += 33;
    v176 = *(result - 32);
    *v168 = v224;
    v177 = v176 + v226;
    v168[1] = v225;
    v168 += 7;
    v226 = v177;
    v175[2] = v226;
  }
  while ( v167 < 4 );
  return result;
}
