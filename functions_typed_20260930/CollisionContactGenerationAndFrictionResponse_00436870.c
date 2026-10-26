void __thiscall sub_436870(int this, double a2)
{
  char v3; // al
  int v4; // ecx
  long double v5; // st7
  long double v6; // st7
  long double v7; // st6
  int v8; // eax
  long double v9; // st5
  double v10; // st5
  long double v11; // st7
  long double v12; // st6
  long double v13; // st5
  int v14; // eax
  double *v15; // esi
  double *v16; // edi
  double v17; // st7
  double v18; // st7
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // edx
  long double v24; // st7
  long double v25; // st7
  bool v26; // zf
  int v27; // edx
  int v28; // eax
  int v29; // esi
  int v30; // ecx
  char *v31; // eax
  double v32; // st7
  double *v33; // edx
  double v35; // st7
  unsigned __int8 v36; // c0
  unsigned __int8 v37; // c3
  long double v38; // st7
  long double v39; // st7
  double v40; // st6
  long double v41; // st7
  long double v42; // st6
  int v43; // eax
  long double v44; // st7
  long double v45; // st7
  long double v46; // st6
  int v47; // edx
  double *v48; // ecx
  long double v49; // st7
  int v50; // eax
  double v51; // st7
  int v52; // ecx
  long double v53; // st6
  long double v54; // st7
  double v55; // st7
  double v56; // st7
  double v57; // st6
  double v58; // st5
  long double v59; // st4
  long double v60; // st3
  long double v61; // st4
  long double v62; // st6
  double v63; // st5
  long double v64; // st7
  long double v65; // st7
  int v66; // eax
  double v67; // st7
  long double v68; // st7
  long double v69; // st6
  long double v70; // rt2
  long double v71; // st7
  double v72; // st6
  long double v73; // st7
  long double v74; // st6
  long double v75; // st6
  long double v76; // st7
  long double v77; // st7
  double v78; // st7
  long double v79; // st7
  double v80; // st6
  long double v81; // st6
  double v82; // rdi
  long double v83; // st7
  long double v84; // st7
  long double v85; // st7
  long double v86; // st6
  int v87; // eax
  double v88; // st6
  double v89; // st5
  long double v90; // st6
  double v91; // st5
  int v92; // eax
  long double v93; // st6
  long double v94; // st7
  long double v95; // st7
  long double v96; // st6
  long double v97; // st6
  double v98; // st6
  long double v99; // st5
  long double v100; // st5
  int v101; // eax
  double v102; // st7
  int v103; // edx
  long double v104; // st7
  long double v105; // st7
  long double v106; // st6
  long double v107; // st5
  int v108; // ecx
  long double v109; // [esp+10h] [ebp-258h] BYREF
  double v110; // [esp+18h] [ebp-250h]
  double v111; // [esp+20h] [ebp-248h] BYREF
  long double v112; // [esp+28h] [ebp-240h]
  long double v113; // [esp+30h] [ebp-238h]
  long double v114; // [esp+38h] [ebp-230h]
  long double v115; // [esp+40h] [ebp-228h]
  long double v116; // [esp+48h] [ebp-220h]
  double v117[3]; // [esp+50h] [ebp-218h] BYREF
  double v118; // [esp+68h] [ebp-200h]
  double v119; // [esp+70h] [ebp-1F8h]
  long double v120; // [esp+78h] [ebp-1F0h]
  long double v121; // [esp+80h] [ebp-1E8h]
  long double v122; // [esp+88h] [ebp-1E0h] BYREF
  double v123; // [esp+90h] [ebp-1D8h]
  double v124; // [esp+98h] [ebp-1D0h]
  long double v125; // [esp+A0h] [ebp-1C8h]
  long double v126; // [esp+A8h] [ebp-1C0h]
  long double v127; // [esp+B0h] [ebp-1B8h]
  long double v128; // [esp+B8h] [ebp-1B0h]
  long double v129; // [esp+C0h] [ebp-1A8h]
  long double v130; // [esp+C8h] [ebp-1A0h]
  long double v131; // [esp+D0h] [ebp-198h]
  int v132; // [esp+DCh] [ebp-18Ch]
  long double v133; // [esp+E0h] [ebp-188h]
  double v134; // [esp+E8h] [ebp-180h]
  long double v135; // [esp+F0h] [ebp-178h]
  long double v136; // [esp+F8h] [ebp-170h]
  long double v137; // [esp+108h] [ebp-160h]
  double v138; // [esp+110h] [ebp-158h] BYREF
  double v139; // [esp+118h] [ebp-150h] BYREF
  double v140; // [esp+120h] [ebp-148h] BYREF
  int v141; // [esp+128h] [ebp-140h]
  double v142; // [esp+12Ch] [ebp-13Ch]
  long double v143; // [esp+134h] [ebp-134h]
  double v144; // [esp+13Ch] [ebp-12Ch]
  int v145; // [esp+144h] [ebp-124h]
  char v146[92]; // [esp+148h] [ebp-120h] BYREF
  double v147[3]; // [esp+1A4h] [ebp-C4h] BYREF
  int v148; // [esp+1BCh] [ebp-ACh]
  int v149; // [esp+1C0h] [ebp-A8h]
  int v150; // [esp+1C4h] [ebp-A4h]
  int v151; // [esp+1C8h] [ebp-A0h]
  double v152; // [esp+1CCh] [ebp-9Ch]
  int v153; // [esp+1D4h] [ebp-94h]
  long double v154; // [esp+1D8h] [ebp-90h]
  long double v155; // [esp+1E0h] [ebp-88h]
  double v156[10]; // [esp+1E8h] [ebp-80h] BYREF
  _BYTE v157[24]; // [esp+238h] [ebp-30h] BYREF
  _BYTE v158[24]; // [esp+250h] [ebp-18h] BYREF

  v3 = *(_BYTE *)(this + 452);
  *(_DWORD *)(this + 796) = 0;
  *(_DWORD *)(this + 800) = 0;
  *(_DWORD *)(this + 308) = 0;
  *(_DWORD *)(this + 312) = 0;
  *(_DWORD *)(this + 324) = 0;
  *(_DWORD *)(this + 328) = 0;
  *(_DWORD *)(this + 332) = 0;
  *(_DWORD *)(this + 336) = 0;
  *(_DWORD *)(this + 616) = 0;
  *(_DWORD *)(this + 620) = 1072693248;
  *(_DWORD *)(this + 316) = 0;
  *(_DWORD *)(this + 320) = 0;
  *(_DWORD *)(this + 340) = 0;
  *(_DWORD *)(this + 344) = 0;
  *(_DWORD *)(this + 804) = 0;
  *(_DWORD *)(this + 808) = 0;
  if ( v3 )
  {
    *(_DWORD *)(this + 612) = 0;
    *(_DWORD *)(this + 252) = -1;
    *(_DWORD *)(this + 256) = -1048577;
    return;
  }
  v4 = *(_DWORD *)(this + 348);
  v114 = *(double *)(v4 + 28);
  v115 = *(double *)(v4 + 52);
  v116 = *(double *)(v4 + 76);
  v122 = v116 - v115 * 0.0;
  v123 = v114 * 0.0 - v116 * 0.0;
  v124 = v115 * 0.0 - v114;
  v5 = sqrt(v123 * v123 + v124 * v124 + v122 * v122);
  if ( v5 == 0.0 )
  {
    v124 = 0.0;
    v6 = 1.0;
    v7 = 0.0;
    v114 = 0.0;
    v115 = 1.0;
    v116 = 0.0;
    v118 = 0.0;
    v119 = 0.0;
    v120 = 1.0;
  }
  else
  {
    v109 = 1.0 / v5;
    v6 = v109 * v122;
    v7 = v123 * v109;
    v124 = v124 * v109;
    v118 = v124 * v115 - v123 * v109 * v116;
    v119 = v109 * v122 * v116 - v124 * v114;
    v120 = v114 * (v123 * v109) - v109 * v122 * v115;
    if ( v119 < 0.0 )
    {
      v118 = -v118;
      v119 = -v119;
      v120 = -v120;
    }
    if ( v115 < 0.0 )
    {
      v114 = -v114;
      v115 = -v115;
      v116 = -v116;
    }
  }
  v8 = *(_DWORD *)(this + 548);
  v9 = fabs(*(double *)(this + 188)) * *(double *)(this + 532);
  HIDWORD(v121) = *(_DWORD *)(this + 552);
  LODWORD(v121) = v8;
  v131 = v9 + *(double *)(this + 524);
  v128 = v131 * v118;
  v129 = v131 * v119;
  v130 = v131 * v120;
  v10 = *(double *)(this + 540);
  v111 = v114 * v10;
  v112 = v115 * v10;
  v113 = v10 * v116;
  v117[0] = v121 * v6;
  v11 = v7 * v121;
  v117[2] = v124 * v121;
  v12 = *(double *)(v4 + 4) - v128;
  v13 = *(double *)(v4 + 12) - v129;
  v137 = *(double *)(v4 + 20) - v130;
  v122 = v12 - v111;
  v123 = v13 - v112;
  v124 = v137 - v113;
  v128 = v12 + v111;
  v130 = v113 + v137;
  v154 = v122 - v117[0];
  v155 = v123 - v11;
  v156[0] = v124 - v117[2];
  v156[1] = v122 + v117[0];
  v156[2] = v11 + v123;
  v156[3] = v117[2] + v124;
  v156[4] = v128 - v117[0];
  v14 = 3;
  v156[5] = v13 + v112 - v11;
  v156[6] = v130 - v117[2];
  if ( byte_7CE994 )
  {
    v14 = 5;
    v156[7] = v128 + v117[0];
    v156[8] = v13 + v112 + v11;
    v156[9] = v117[2] + v130;
    qmemcpy(v157, (const void *)(v4 + 4), sizeof(v157));
  }
  LODWORD(v110) = *(_DWORD *)(this + 612);
  LODWORD(v125) = 0;
  v15 = v156;
  v16 = &v139;
  v132 = v14;
  do
  {
    v147[0] = *(v15 - 2);
    v17 = *(v15 - 1) + 0.2;
    v148 = 858993459;
    v147[1] = v17;
    v18 = *v15;
    v149 = 1070805811;
    v147[2] = v18;
    v150 = 0x40000000;
    v151 = 1201543096;
    v153 = LODWORD(v110);
    v19 = SpatialGridQuery(v147);
    *((_DWORD *)v16 + 4) = v19;
    if ( v19 )
    {
      v20 = *((_DWORD *)v15 - 4);
      *((_DWORD *)v16 - 1) = *((_DWORD *)v15 - 3);
      *((_DWORD *)v16 - 2) = v20;
      LODWORD(v110) = v19;
      v21 = *(_DWORD *)(v19 + 84);
      v22 = *((_DWORD *)v15 + 1);
      v23 = LODWORD(v125) + 1;
      v24 = sin(*(float *)(v21 + 24) * *v15);
      ++LODWORD(v125);
      v16 = (double *)((char *)v16 + 28);
      v25 = (v24 + sin(*(v15 - 2) * *(float *)(v21 + 24))) * *(float *)(v21 + 20);
      *((_DWORD *)v16 - 5) = *(_DWORD *)v15;
      *((_DWORD *)v16 - 4) = v22;
      *(double *)((char *)v16 - 28) = v25 + v152;
    }
    else
    {
      v23 = LODWORD(v125);
    }
    v15 += 3;
    --v132;
  }
  while ( v132 );
  v26 = v23 == 3;
  if ( v23 < 3 )
  {
    if ( !v23 )
    {
      *(_DWORD *)(this + 612) = 0;
      *(_DWORD *)(this + 252) = -1;
      *(_DWORD *)(this + 256) = -1048577;
      return;
    }
    v27 = LODWORD(v125);
    if ( LODWORD(v125) == 1 )
    {
      v145 = v141;
      v144 = v140;
      v142 = v138 + 0.01;
      v27 = 2;
      v143 = (sin(*(float *)(*(_DWORD *)(v141 + 84) + 24) * v140) + sin(*(float *)(*(_DWORD *)(v141 + 84) + 24) * v142))
           * *(float *)(*(_DWORD *)(v141 + 84) + 20)
           + (v140 * *(double *)(v141 + 16) + v142 * *(double *)v141 + *(double *)(v141 + 24)) * v142
           + (v140 * *(double *)(v141 + 8) + *(double *)(v141 + 32)) * v140
           + *(double *)(v141 + 40);
    }
    v28 = 28 * v27;
    *(int *)((char *)&v141 + v28) = v141;
    v29 = HIDWORD(v138);
    *(_DWORD *)((char *)&v138 + v28) = LODWORD(v138);
    v30 = *(&v141 + 7 * v27);
    v31 = (char *)&v138 + 28 * v27;
    *((_DWORD *)v31 + 1) = v29;
    LODWORD(v125) = v27 + 1;
    v32 = v140 + 0.01;
    v26 = v27 == 2;
    *((double *)v31 + 2) = v140 + 0.01;
    *((long double *)v31 + 1) = (sin(*(double *)v31 * *(float *)(*(_DWORD *)(v30 + 84) + 24))
                               + sin(*(float *)(*(_DWORD *)(v30 + 84) + 24) * v32))
                              * *(float *)(*(_DWORD *)(v30 + 84) + 20)
                              + (v32 * *(double *)(v30 + 16) + *(double *)v31 * *(double *)v30 + *(double *)(v30 + 24))
                              * *(double *)v31
                              + (v32 * *(double *)(v30 + 8) + *(double *)(v30 + 32)) * v32
                              + *(double *)(v30 + 40);
  }
  if ( v26 )
  {
    if ( sub_56C640(v146, &v111) )
    {
      v111 = 0.0;
      v112 = 1.0;
      v113 = 0.0;
    }
    else if ( v112 < 0.0 )
    {
      v111 = -v111;
      v112 = -v112;
      v113 = -v113;
    }
    v109 = v113 * v140 + v111 * v138 + v112 * v139;
  }
  else
  {
    BestFitPlaneFitting((int)&v138, SLODWORD(v125), &v111, &v109);
  }
  v33 = (double *)(*(_DWORD *)(this + 348) + 4);
  v35 = *(double *)(this + 540);
  v127 = v131;
  qmemcpy(v117, v33, sizeof(v117));
  if ( v36 | v37 )
  {
    v38 = v35 - v131;
    v127 = v131 + v38;
    v129 = v38 * v119;
    v130 = v38 * v120;
    v117[0] = v118 * v38 + v117[0];
    v117[1] = v129 + v117[1];
    v117[2] = v130 + v117[2];
    v39 = 0.0;
  }
  else
  {
    v39 = sqrt(v131 * v131 - v35 * v35);
  }
  v121 = v109 - (v117[0] * v111 + v113 * v117[2] + v112 * v117[1]) + v127;
  v40 = *(double *)(this + 540) + 1.0;
  v126 = sqrt((v40 + *(double *)(this + 540)) * (v40 + *(double *)(this + 540)) + v39 * v39);
  v118 = v114 * v40;
  v119 = v115 * v40;
  v118 = v118 + *v33;
  v119 = v119 + v33[1];
  v41 = v40 * v116 + v33[2];
  v42 = v109 - (v118 * v111 + v113 * v41 + v112 * v119) + v126;
  if ( v121 >= v42 )
  {
    *(long double *)(this + 804) = v42;
    v46 = v42 - v126;
    v123 = v46 * v112;
    v124 = v46 * v113;
    v122 = v118 + v111 * v46;
    v123 = v123 + v119;
    v124 = v124 + v41;
  }
  else
  {
    v43 = HIDWORD(v121);
    v44 = v121;
    *(_DWORD *)(this + 804) = LODWORD(v121);
    v45 = v44 - v127;
    *(_DWORD *)(this + 808) = v43;
    v123 = v45 * v112;
    v124 = v45 * v113;
    v122 = v117[0] + v111 * v45;
    v123 = v123 + v117[1];
    v124 = v124 + v117[2];
  }
  v47 = LODWORD(v125);
  v109 = 1.797693134862316e308;
  if ( SLODWORD(v125) > 0 )
  {
    v48 = &v140;
    do
    {
      v49 = (v122 - *(v48 - 2)) * (v122 - *(v48 - 2))
          + (v124 - *v48) * (v124 - *v48)
          + (v123 - *(v48 - 1)) * (v123 - *(v48 - 1));
      if ( v49 < v109 )
      {
        v50 = *((_DWORD *)v48 + 2);
        v109 = v49;
        *(_DWORD *)(this + 612) = v50;
      }
      v48 = (double *)((char *)v48 + 28);
      --v47;
    }
    while ( v47 );
  }
  if ( *(double *)(this + 804) < 0.0 )
  {
    *(_DWORD *)(this + 804) = 0;
    *(_DWORD *)(this + 808) = 0;
    *(_DWORD *)(this + 252) = -1;
    *(_DWORD *)(this + 256) = -1048577;
    return;
  }
  v51 = *(double *)(this + 556) * *(double *)(this + 804);
  v52 = *(_DWORD *)(this + 348);
  v53 = v113 * *(double *)(v52 + 116);
  v132 = *(_DWORD *)(*(_DWORD *)(this + 612) + 84);
  v54 = v51 - (v53 + v112 * *(double *)(v52 + 108) + v111 * *(double *)(v52 + 100)) * *(double *)(this + 564);
  *(long double *)(this + 796) = v54;
  if ( v54 < 0.0 )
  {
    *(_DWORD *)(this + 796) = 0;
    *(_DWORD *)(this + 800) = 0;
    *(_DWORD *)(this + 252) = -1;
    *(_DWORD *)(this + 256) = -1048577;
    return;
  }
  v55 = *(double *)(v52 + 28);
  v115 = *(double *)(v52 + 52);
  v116 = *(double *)(v52 + 76);
  v121 = v111 * v55 + v113 * v116 + v112 * v115;
  if ( fabs(v121) <= 0.99609375 )
  {
    v62 = v113 * v115 - v112 * v116;
    v63 = v55;
    v64 = v111 * v116 - v55 * v113;
    v120 = v63 * v112 - v111 * v115;
    v109 = 1.0 / sqrt(v62 * v62 + v64 * v64 + v120 * v120);
    v118 = v109 * v62;
    v119 = v109 * v64;
    v120 = v109 * v120;
    v114 = v112 * v120 - v113 * v119;
    v115 = v118 * v113 - v111 * v120;
    v116 = v111 * v119 - v118 * v112;
  }
  else
  {
    v56 = *(double *)(v52 + 44);
    v57 = *(double *)(v52 + 68);
    v58 = *(double *)(v52 + 92);
    v59 = v112 * v58 - v113 * v57;
    v60 = v56 * v113 - v111 * v58;
    v116 = v111 * v57 - v56 * v112;
    v109 = 1.0 / sqrt(v59 * v59 + v116 * v116 + v60 * v60);
    v114 = v109 * v59;
    v115 = v109 * v60;
    v116 = v109 * v116;
    v128 = v57 * v116 - v58 * v115;
    v129 = v114 * v58 - v56 * v116;
    v61 = v56 * v115 - v114 * v57;
    v117[0] = v129 * v58 - v61 * v57;
    v117[1] = v56 * v61 - v128 * v58;
    v121 = v117[0] * v111 + v113 * (v128 * v57 - v56 * v129) + v112 * v117[1];
    v118 = v113 * v115 - v112 * v116;
    v119 = v111 * v116 - v114 * v113;
    v120 = v114 * v112 - v111 * v115;
  }
  v65 = v121;
  FloatConvertWrapper();
  *(long double *)(this + 788) = v65;
  v66 = *(_DWORD *)(this + 348);
  v67 = *(double *)(this + 804) * 0.5;
  v129 = v67 * v112;
  v130 = v67 * v113;
  v130 = v124 - v130;
  v136 = v122 - v111 * v67 - *(double *)(v66 + 4);
  v68 = v123 - v129 - *(double *)(v66 + 12);
  v69 = v130 - *(double *)(v66 + 20);
  v117[0] = v69 * *(double *)(v66 + 132) - v68 * *(double *)(v66 + 140);
  v70 = v136 * *(double *)(v66 + 140) - v69 * *(double *)(v66 + 124);
  v117[2] = v68 * *(double *)(v66 + 124) - v136 * *(double *)(v66 + 132);
  v117[0] = v117[0] + *(double *)(v66 + 100);
  v71 = v70 + *(double *)(v66 + 108);
  v72 = v117[2] + *(double *)(v66 + 116);
  v109 = v117[0] * v114 + v72 * v116 + v71 * v115;
  v73 = v117[0] * v118 + v71 * v119 + v72 * v120;
  *(long double *)(this + 308) = sqrt(v73 * v73 + v109 * v109);
  v74 = v116 * *(double *)(v66 + 116) + v115 * *(double *)(v66 + 108) + v114 * *(double *)(v66 + 100);
  v127 = v119 * *(double *)(v66 + 108) + v120 * *(double *)(v66 + 116) + v118 * *(double *)(v66 + 100);
  v126 = sqrt(v127 * v127 + v74 * v74);
  if ( v126 >= *(double *)(this + 292) )
  {
    *(_DWORD *)(this + 252) = -1;
    v75 = 1.0 / v126;
    *(_DWORD *)(this + 256) = -1048577;
  }
  else
  {
    v75 = *(double *)(this + 300);
  }
  v109 = v109 * v75;
  v125 = v75 * v73;
  v76 = v125 * v125 + v109 * v109;
  v134 = sqrt(v76);
  if ( v76 <= 0.0 )
  {
    v133 = 0.0;
    v121 = 0.0;
  }
  else
  {
    v133 = 1.0 / v134;
    v77 = fabs(v125);
    v121 = 1.0 / (fabs(v109) + v77) * v77;
  }
  v78 = *(double *)(this + 796);
  if ( v78 <= *(double *)(this + 680) )
    v79 = cos(v78 * *(double *)(this + 688) * 3.141592653589793) * *(double *)(this + 672) + *(double *)(this + 664);
  else
    v79 = *(double *)(this + 664) - *(double *)(this + 672);
  v80 = *(double *)(this + 796);
  if ( v80 <= *(double *)(this + 712) )
    v81 = cos(v80 * *(double *)(this + 720) * 3.141592653589793) * *(double *)(this + 704) + *(double *)(this + 696);
  else
    v81 = *(double *)(this + 696) - *(double *)(this + 704);
  v82 = v134;
  v110 = (v81 - v79) * v121 + v79;
  CubicHermiteInterpolation(v110, v134);
  v135 = v79;
  v83 = fabs(v127);
  if ( v83 >= 1.0 )
  {
    v84 = v125 * v127;
    CubicHermiteInterpolation(v110, v82);
  }
  else
  {
    if ( v125 * v127 <= 0.0 )
    {
      v83 = (v83 + 1.0) * 0.5;
      v134 = v83;
    }
    else
    {
      v134 = (1.0 - v83) * 0.5;
    }
    CubicHermiteInterpolation(v110, v82);
    v127 = v83;
    CubicHermiteInterpolation(v110, v82);
    v84 = (v83 - v127) * v134 + v127;
  }
  v85 = ((v84 - v135) * v121 + v135) * v133;
  v86 = v85 * *(double *)(this + 740) * v110;
  *(long double *)(this + 324) = v86;
  if ( v86 > 1.0 )
  {
    *(_DWORD *)(this + 324) = 0;
    *(_DWORD *)(this + 328) = 1072693248;
  }
  v87 = v132;
  *(long double *)(this + 332) = sqrt(*(double *)(this + 324));
  v88 = *(double *)(this + 632) - *(double *)(this + 640) * *(double *)(this + 624);
  v89 = *(float *)(v87 + 8) - *(double *)(this + 624) * *(float *)(v87 + 12);
  *(double *)(this + 616) = v89;
  v90 = (v88 + (*(double *)(this + 648) - *(double *)(this + 656) * *(double *)(this + 624) - v88) * v121)
      * v89
      * *(double *)(this + 924);
  v91 = *(double *)(this + 796);
  if ( v91 > *(double *)(this + 604) )
    v91 = *(double *)(this + 604);
  v92 = *(_DWORD *)(this + 252);
  v93 = v90
      * ((((v91 * *(double *)(this + 572) + *(double *)(this + 580)) * v91 + *(double *)(this + 588)) * v91
        + *(double *)(this + 596))
       * *(double *)(this + 796));
  *(long double *)(this + 316) = v93;
  v94 = -(v85 * v93);
  v110 = v109 * v94;
  v95 = v94 * v125;
  if ( v92 != -1 || *(_DWORD *)(this + 256) != -1048577 )
  {
    if ( *(double *)(this + 188) != 0.0 )
    {
      v96 = (v131 - *(double *)(this + 804) * 0.5) * (a2 - *(double *)(this + 252)) * *(double *)(this + 188);
      v129 = v96 * v119;
      v130 = v96 * v120;
      *(long double *)(this + 228) = v118 * v96 + *(double *)(this + 228);
      *(long double *)(this + 236) = v129 + *(double *)(this + 236);
      *(long double *)(this + 244) = v130 + *(double *)(this + 244);
    }
    *(double *)(this + 252) = a2;
    v117[0] = *(double *)(this + 228) - v122;
    v117[1] = *(double *)(this + 236) - v123;
    v117[2] = *(double *)(this + 244) - v124;
    v133 = sqrt(v117[0] * v117[0] + v117[2] * v117[2] + v117[1] * v117[1]);
    if ( v133 >= 0.022 || *(double *)(this + 308) >= 5.0 )
      goto LABEL_79;
    v97 = (1.0 - v126 * *(double *)(this + 300)) * (1.0 - *(double *)(this + 308) * 0.2) * 55000.0;
    if ( v133 > 0.011 )
      v97 = v97 * (2.0 - v133 * 90.90909090909092);
    v109 = (v117[0] * v114 + v117[2] * v116 + v117[1] * v115) * v97 + v110;
    v126 = (v117[0] * v118 + v117[1] * v119 + v117[2] * v120) * v97 + v95;
    if ( *(double *)(this + 316) * *(double *)(this + 316) < v126 * v126 + v109 * v109 )
    {
LABEL_79:
      *(_DWORD *)(this + 252) = -1;
      *(_DWORD *)(this + 256) = -1048577;
    }
    else
    {
      v95 = v126;
      v110 = v109;
    }
  }
  if ( *(_DWORD *)(this + 252) == -1 && *(_DWORD *)(this + 256) == -1048577 )
  {
    *(long double *)(this + 228) = v122;
    *(double *)(this + 236) = v123;
    *(double *)(this + 244) = v124;
    *(double *)(this + 252) = a2;
  }
  v135 = *(double *)(this + 748) * *(double *)(this + 316) * *(double *)(this + 324);
  v98 = fabs(*(double *)(this + 788));
  if ( v98 < *(double *)(this + 756) )
  {
    v99 = v110 - sin(*(double *)(this + 772) * *(double *)(this + 788)) * v135;
LABEL_89:
    v110 = v99;
    goto LABEL_90;
  }
  if ( v98 < 1.570796326794897 )
  {
    v100 = (cos((v98 - *(double *)(this + 756)) * *(double *)(this + 780)) + 1.0) * 0.5 * v135;
    if ( *(double *)(this + 788) <= 0.0 )
    {
      v99 = v100 + v110;
      goto LABEL_89;
    }
    v110 = v110 - v100;
  }
LABEL_90:
  v101 = *(_DWORD *)(this + 348) + 308;
  v133 = (1.0 - v98 * *(double *)(this + 764)) * v95;
  v102 = *(double *)(this + 796);
  v129 = v102 * v112;
  v130 = v102 * v113;
  *(double *)v101 = v111 * v102 + *(double *)v101;
  *(long double *)(v101 + 8) = v129 + *(double *)(v101 + 8);
  *(long double *)(v101 + 16) = v130 + *(double *)(v101 + 16);
  v103 = *(_DWORD *)(this + 348);
  qmemcpy(v117, (const void *)(v103 + 124), sizeof(v117));
  v104 = v117[0] * v117[0] + v117[2] * v117[2] + v117[1] * v117[1];
  v109 = (*(float *)(v132 + 16) + *(double *)(this + 812)) * *(double *)(this + 804);
  if ( v104 <= 1.0 )
  {
    v105 = v117[0] * v109;
    v106 = v109 * v117[1];
    v107 = v109;
  }
  else
  {
    v126 = 1.0 / sqrt(v104) * v109;
    v105 = v126 * v117[0];
    v106 = v126 * v117[1];
    v107 = v126;
  }
  v117[2] = v107 * v117[2];
  *(long double *)(v103 + 332) = *(double *)(v103 + 332) - v105;
  *(long double *)(v103 + 340) = *(double *)(v103 + 340) - v106;
  *(double *)(v103 + 348) = *(double *)(v103 + 348) - v117[2];
  v137 = v133 * v120;
  v129 = v110 * v115;
  v130 = v110 * v116;
  v117[0] = v114 * v110 + v118 * v133;
  v117[1] = v133 * v119 + v129;
  v117[2] = v137 + v130;
  qmemcpy(v158, v117, sizeof(v158));
  ApplyImpulseToRigidBodyWithTorque(&v122, v158);
  v108 = HIDWORD(v110);
  *(_DWORD *)(this + 340) = LODWORD(v110);
  *(_DWORD *)(this + 344) = v108;
}

