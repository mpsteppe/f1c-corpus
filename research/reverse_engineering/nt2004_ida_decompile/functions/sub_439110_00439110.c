void __thiscall sub_439110(int this, double a2)
{
  char v3; // al
  int v4; // ecx
  long double v5; // st7
  long double v6; // st7
  long double v7; // st6
  long double v8; // st5
  double v9; // st5
  long double v10; // st7
  long double v11; // st6
  long double v12; // st5
  int v13; // eax
  double *v14; // esi
  double *v15; // edi
  double v16; // st7
  double v17; // st7
  int v18; // eax
  double v19; // st7
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
  long double v49; // st4
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
  int v65; // eax
  double v66; // st7
  long double v67; // st7
  long double v68; // st6
  long double v69; // rt2
  long double v70; // st7
  double v71; // st6
  long double v72; // st7
  long double v73; // st6
  long double v74; // st6
  long double v75; // st7
  long double v76; // st7
  long double v77; // st7
  long double v78; // st6
  double v79; // rdi
  long double v80; // st7
  long double v81; // st7
  long double v82; // st7
  long double v83; // st6
  int v84; // eax
  double v85; // st6
  double v86; // st5
  long double v87; // st6
  double v88; // st5
  long double v89; // st6
  int v90; // eax
  long double v91; // st7
  long double v92; // st7
  long double v93; // st6
  long double v94; // st6
  double v95; // st6
  long double v96; // st5
  long double v97; // st5
  int v98; // eax
  double v99; // st7
  int v100; // edx
  long double v101; // st7
  long double v102; // st7
  long double v103; // st6
  long double v104; // st5
  int v105; // ecx
  long double v106; // [esp+10h] [ebp-258h] BYREF
  double v107; // [esp+18h] [ebp-250h]
  double v108; // [esp+20h] [ebp-248h] BYREF
  long double v109; // [esp+28h] [ebp-240h]
  long double v110; // [esp+30h] [ebp-238h]
  long double v111; // [esp+38h] [ebp-230h]
  long double v112; // [esp+40h] [ebp-228h]
  long double v113; // [esp+48h] [ebp-220h]
  double v114[3]; // [esp+50h] [ebp-218h] BYREF
  double v115; // [esp+68h] [ebp-200h]
  double v116; // [esp+70h] [ebp-1F8h]
  long double v117; // [esp+78h] [ebp-1F0h]
  long double v118; // [esp+80h] [ebp-1E8h]
  long double v119; // [esp+88h] [ebp-1E0h]
  long double v120; // [esp+90h] [ebp-1D8h] BYREF
  double v121; // [esp+98h] [ebp-1D0h]
  double v122; // [esp+A0h] [ebp-1C8h]
  long double v123; // [esp+A8h] [ebp-1C0h]
  long double v124; // [esp+B0h] [ebp-1B8h]
  long double v125; // [esp+BCh] [ebp-1ACh]
  long double v126; // [esp+C4h] [ebp-1A4h]
  long double v127; // [esp+CCh] [ebp-19Ch]
  int v128; // [esp+D4h] [ebp-194h]
  double v129; // [esp+D8h] [ebp-190h]
  long double v130; // [esp+E0h] [ebp-188h]
  long double v131; // [esp+E8h] [ebp-180h]
  long double v132; // [esp+F0h] [ebp-178h]
  long double v133; // [esp+F8h] [ebp-170h]
  long double v134; // [esp+108h] [ebp-160h]
  double v135; // [esp+110h] [ebp-158h] BYREF
  double v136; // [esp+118h] [ebp-150h] BYREF
  double v137; // [esp+120h] [ebp-148h] BYREF
  int v138; // [esp+128h] [ebp-140h]
  double v139; // [esp+12Ch] [ebp-13Ch]
  long double v140; // [esp+134h] [ebp-134h]
  double v141; // [esp+13Ch] [ebp-12Ch]
  int v142; // [esp+144h] [ebp-124h]
  char v143[92]; // [esp+148h] [ebp-120h] BYREF
  double v144[3]; // [esp+1A4h] [ebp-C4h] BYREF
  int v145; // [esp+1BCh] [ebp-ACh]
  int v146; // [esp+1C0h] [ebp-A8h]
  int v147; // [esp+1C4h] [ebp-A4h]
  int v148; // [esp+1C8h] [ebp-A0h]
  double v149; // [esp+1CCh] [ebp-9Ch]
  int v150; // [esp+1D4h] [ebp-94h]
  long double v151; // [esp+1D8h] [ebp-90h]
  long double v152; // [esp+1E0h] [ebp-88h]
  double v153[10]; // [esp+1E8h] [ebp-80h] BYREF
  _BYTE v154[24]; // [esp+238h] [ebp-30h] BYREF
  _BYTE v155[24]; // [esp+250h] [ebp-18h] BYREF

  v3 = *(_BYTE *)(this + 452);
  *(_DWORD *)(this + 852) = 0;
  *(_DWORD *)(this + 856) = 0;
  *(_DWORD *)(this + 308) = 0;
  *(_DWORD *)(this + 312) = 0;
  *(_DWORD *)(this + 324) = 0;
  *(_DWORD *)(this + 328) = 0;
  *(_DWORD *)(this + 332) = 0;
  *(_DWORD *)(this + 336) = 0;
  *(_DWORD *)(this + 672) = 0;
  *(_DWORD *)(this + 676) = 1072693248;
  *(_DWORD *)(this + 316) = 0;
  *(_DWORD *)(this + 320) = 0;
  *(_DWORD *)(this + 340) = 0;
  *(_DWORD *)(this + 344) = 0;
  *(_DWORD *)(this + 860) = 0;
  *(_DWORD *)(this + 864) = 0;
  if ( v3 )
  {
    *(_DWORD *)(this + 668) = 0;
    *(_DWORD *)(this + 252) = -1;
    *(_DWORD *)(this + 256) = -1048577;
    return;
  }
  v4 = *(_DWORD *)(this + 348);
  v111 = *(double *)(v4 + 28);
  v112 = *(double *)(v4 + 52);
  v113 = *(double *)(v4 + 76);
  v120 = v113 - v112 * 0.0;
  v121 = v111 * 0.0 - v113 * 0.0;
  v122 = v112 * 0.0 - v111;
  v5 = sqrt(v122 * v122 + v120 * v120 + v121 * v121);
  if ( v5 == 0.0 )
  {
    v122 = 0.0;
    v6 = 1.0;
    v7 = 0.0;
    v111 = 0.0;
    v112 = 1.0;
    v113 = 0.0;
    v115 = 0.0;
    v116 = 0.0;
    v117 = 1.0;
  }
  else
  {
    v106 = 1.0 / v5;
    v6 = v106 * v120;
    v7 = v106 * v121;
    v122 = v122 * v106;
    v115 = v122 * v112 - v113 * (v106 * v121);
    v116 = v106 * v120 * v113 - v122 * v111;
    v117 = v111 * (v106 * v121) - v106 * v120 * v112;
    if ( v116 < 0.0 )
    {
      v115 = -v115;
      v116 = -v116;
      v117 = -v117;
    }
    if ( v112 < 0.0 )
    {
      v111 = -v111;
      v112 = -v112;
      v113 = -v113;
    }
  }
  v106 = fabs(*(double *)(this + 188));
  v124 = v106 * *(double *)(this + 532) + *(double *)(this + 524);
  if ( *(double *)(this + 572) != 0.0 )
  {
    if ( *(double *)(this + 596) > 0.0 )
    {
      if ( v106 < *(double *)(this + 596) )
        v8 = 1.0 - v106 / *(double *)(this + 596);
      else
        v8 = 0.0;
    }
    else
    {
      v8 = 1.0;
    }
    v124 = (cos((*(double *)(this + 580) + *(double *)(this + 172) + 3.141592653589793) * *(double *)(this + 604))
          * -1.0
          + 1.0)
         * 0.5
         * *(double *)(this + 572)
         * v8
         + v124;
  }
  v118 = *(double *)(this + 548);
  v125 = v124 * v115;
  v126 = v124 * v116;
  v127 = v124 * v117;
  v9 = *(double *)(this + 540);
  v108 = v111 * v9;
  v109 = v112 * v9;
  v110 = v9 * v113;
  v114[0] = v118 * v6;
  v10 = v118 * v7;
  v114[2] = v122 * v118;
  v11 = *(double *)(v4 + 4) - v125;
  v12 = *(double *)(v4 + 12) - v126;
  v134 = *(double *)(v4 + 20) - v127;
  v120 = v11 - v108;
  v121 = v12 - v109;
  v122 = v134 - v110;
  v125 = v11 + v108;
  v127 = v110 + v134;
  v151 = v120 - v114[0];
  v152 = v121 - v10;
  v153[0] = v122 - v114[2];
  v153[1] = v120 + v114[0];
  v153[2] = v10 + v121;
  v153[3] = v114[2] + v122;
  v153[4] = v125 - v114[0];
  v153[5] = v12 + v109 - v10;
  v13 = 3;
  v153[6] = v127 - v114[2];
  if ( byte_766AC8 )
  {
    v13 = 5;
    v153[7] = v125 + v114[0];
    v153[8] = v12 + v109 + v10;
    v153[9] = v127 + v114[2];
    qmemcpy(v154, (const void *)(v4 + 4), sizeof(v154));
  }
  LODWORD(v107) = *(_DWORD *)(this + 668);
  LODWORD(v123) = 0;
  v14 = v153;
  v15 = &v136;
  v128 = v13;
  do
  {
    v144[0] = *(v14 - 2);
    v16 = *(v14 - 1) + 0.2;
    v145 = 858993459;
    v144[1] = v16;
    v17 = *v14;
    v146 = 1070805811;
    v144[2] = v17;
    v147 = 0x40000000;
    v148 = 1201543096;
    v150 = LODWORD(v107);
    v18 = sub_44E900(v144);
    *((_DWORD *)v15 + 4) = v18;
    if ( v18 )
    {
      v19 = *(v14 - 2);
      v20 = *((_DWORD *)v14 - 4);
      *((_DWORD *)v15 - 1) = *((_DWORD *)v14 - 3);
      *((_DWORD *)v15 - 2) = v20;
      LODWORD(v107) = v18;
      v21 = *(_DWORD *)(v18 + 84);
      v22 = *((_DWORD *)v14 + 1);
      v23 = LODWORD(v123) + 1;
      v24 = sin(v19 * *(float *)(v21 + 24));
      ++LODWORD(v123);
      v15 = (double *)((char *)v15 + 28);
      v25 = (v24 + sin(*v14 * *(float *)(v21 + 24))) * *(float *)(v21 + 20);
      *((_DWORD *)v15 - 5) = *(_DWORD *)v14;
      *((_DWORD *)v15 - 4) = v22;
      *(double *)((char *)v15 - 28) = v25 + v149;
    }
    else
    {
      v23 = LODWORD(v123);
    }
    v14 += 3;
    --v128;
  }
  while ( v128 );
  v26 = v23 == 3;
  if ( v23 < 3 )
  {
    if ( !v23 )
    {
      *(_DWORD *)(this + 668) = 0;
      *(_DWORD *)(this + 252) = -1;
      *(_DWORD *)(this + 256) = -1048577;
      return;
    }
    v27 = LODWORD(v123);
    if ( LODWORD(v123) == 1 )
    {
      v142 = v138;
      v141 = v137;
      v139 = v135 + 0.01;
      v27 = 2;
      v140 = (sin(*(float *)(*(_DWORD *)(v138 + 84) + 24) * v137) + sin(*(float *)(*(_DWORD *)(v138 + 84) + 24) * v139))
           * *(float *)(*(_DWORD *)(v138 + 84) + 20)
           + (v137 * *(double *)(v138 + 16) + v139 * *(double *)v138 + *(double *)(v138 + 24)) * v139
           + (v137 * *(double *)(v138 + 8) + *(double *)(v138 + 32)) * v137
           + *(double *)(v138 + 40);
    }
    v28 = 28 * v27;
    *(int *)((char *)&v138 + v28) = v138;
    v29 = HIDWORD(v135);
    *(_DWORD *)((char *)&v135 + v28) = LODWORD(v135);
    v30 = *(&v138 + 7 * v27);
    v31 = (char *)&v135 + 28 * v27;
    *((_DWORD *)v31 + 1) = v29;
    LODWORD(v123) = v27 + 1;
    v32 = v137 + 0.01;
    v26 = v27 == 2;
    *((double *)v31 + 2) = v137 + 0.01;
    *((long double *)v31 + 1) = (sin(*(float *)(*(_DWORD *)(v30 + 84) + 24) * *(double *)v31)
                               + sin(*(float *)(*(_DWORD *)(v30 + 84) + 24) * v32))
                              * *(float *)(*(_DWORD *)(v30 + 84) + 20)
                              + (v32 * *(double *)(v30 + 16) + *(double *)v31 * *(double *)v30 + *(double *)(v30 + 24))
                              * *(double *)v31
                              + (v32 * *(double *)(v30 + 8) + *(double *)(v30 + 32)) * v32
                              + *(double *)(v30 + 40);
  }
  if ( v26 )
  {
    if ( sub_57F3D0(v143, &v108) )
    {
      v108 = 0.0;
      v109 = 1.0;
      v110 = 0.0;
    }
    else if ( v109 < 0.0 )
    {
      v108 = -v108;
      v109 = -v109;
      v110 = -v110;
    }
    v106 = v110 * v137 + v108 * v135 + v109 * v136;
  }
  else
  {
    sub_438F80((int)&v135, SLODWORD(v123), &v108, &v106);
  }
  v33 = (double *)(*(_DWORD *)(this + 348) + 4);
  v35 = *(double *)(this + 540);
  v130 = v124;
  qmemcpy(v114, v33, sizeof(v114));
  if ( v36 | v37 )
  {
    v38 = v35 - v124;
    v130 = v124 + v38;
    v126 = v38 * v116;
    v127 = v38 * v117;
    v114[0] = v115 * v38 + v114[0];
    v114[1] = v126 + v114[1];
    v114[2] = v127 + v114[2];
    v39 = 0.0;
  }
  else
  {
    v39 = sqrt(v124 * v124 - v35 * v35);
  }
  v118 = v106 - (v110 * v114[2] + v109 * v114[1] + v114[0] * v108) + v130;
  v40 = *(double *)(this + 540) + 1.0;
  v119 = sqrt((v40 + *(double *)(this + 540)) * (v40 + *(double *)(this + 540)) + v39 * v39);
  v115 = v111 * v40;
  v116 = v112 * v40;
  v115 = v115 + *v33;
  v116 = v116 + v33[1];
  v41 = v40 * v113 + v33[2];
  v42 = v106 - (v110 * v41 + v109 * v116 + v115 * v108) + v119;
  if ( v118 >= v42 )
  {
    *(long double *)(this + 860) = v42;
    v46 = v42 - v119;
    v121 = v46 * v109;
    v122 = v46 * v110;
    v120 = v115 + v108 * v46;
    v121 = v121 + v116;
    v122 = v122 + v41;
  }
  else
  {
    v43 = HIDWORD(v118);
    v44 = v118;
    *(_DWORD *)(this + 860) = LODWORD(v118);
    v45 = v44 - v130;
    *(_DWORD *)(this + 864) = v43;
    v121 = v45 * v109;
    v122 = v45 * v110;
    v120 = v114[0] + v108 * v45;
    v121 = v121 + v114[1];
    v122 = v122 + v114[2];
  }
  v47 = LODWORD(v123);
  v106 = 1.797693134862316e308;
  if ( SLODWORD(v123) > 0 )
  {
    v48 = &v137;
    do
    {
      v49 = (v122 - *v48) * (v122 - *v48)
          + (v121 - *(v48 - 1)) * (v121 - *(v48 - 1))
          + (v120 - *(v48 - 2)) * (v120 - *(v48 - 2));
      if ( v49 < v106 )
      {
        v50 = *((_DWORD *)v48 + 2);
        v106 = v49;
        *(_DWORD *)(this + 668) = v50;
      }
      v48 = (double *)((char *)v48 + 28);
      --v47;
    }
    while ( v47 );
  }
  if ( *(double *)(this + 860) < 0.0 )
  {
    *(_DWORD *)(this + 860) = 0;
    *(_DWORD *)(this + 864) = 0;
    *(_DWORD *)(this + 252) = -1;
    *(_DWORD *)(this + 256) = -1048577;
    return;
  }
  v51 = *(double *)(this + 556) * *(double *)(this + 860);
  v52 = *(_DWORD *)(this + 348);
  v53 = v109 * *(double *)(v52 + 108);
  v128 = *(_DWORD *)(*(_DWORD *)(this + 668) + 84);
  v54 = v51 - (v53 + v110 * *(double *)(v52 + 116) + v108 * *(double *)(v52 + 100)) * *(double *)(this + 564);
  *(long double *)(this + 852) = v54;
  if ( v54 < 0.0 )
  {
    *(_DWORD *)(this + 852) = 0;
    *(_DWORD *)(this + 856) = 0;
    *(_DWORD *)(this + 252) = -1;
    *(_DWORD *)(this + 256) = -1048577;
    return;
  }
  v55 = *(double *)(v52 + 28);
  v112 = *(double *)(v52 + 52);
  v113 = *(double *)(v52 + 76);
  v118 = v110 * v113 + v109 * v112 + v55 * v108;
  if ( fabs(v118) <= 0.99609375 )
  {
    v62 = v110 * v112 - v109 * v113;
    v63 = v55;
    v64 = v108 * v113 - v55 * v110;
    v117 = v63 * v109 - v108 * v112;
    v106 = 1.0 / sqrt(v62 * v62 + v64 * v64 + v117 * v117);
    v115 = v106 * v62;
    v116 = v106 * v64;
    v117 = v106 * v117;
    v111 = v109 * v117 - v110 * v116;
    v112 = v115 * v110 - v108 * v117;
    v113 = v108 * v116 - v115 * v109;
  }
  else
  {
    v56 = *(double *)(v52 + 44);
    v57 = *(double *)(v52 + 68);
    v58 = *(double *)(v52 + 92);
    v59 = v109 * v58 - v110 * v57;
    v60 = v56 * v110 - v108 * v58;
    v113 = v108 * v57 - v56 * v109;
    v106 = 1.0 / sqrt(v59 * v59 + v113 * v113 + v60 * v60);
    v111 = v106 * v59;
    v112 = v106 * v60;
    v113 = v106 * v113;
    v125 = v57 * v113 - v58 * v112;
    v126 = v111 * v58 - v56 * v113;
    v61 = v56 * v112 - v111 * v57;
    v114[0] = v126 * v58 - v61 * v57;
    v114[1] = v56 * v61 - v125 * v58;
    v118 = v110 * (v125 * v57 - v56 * v126) + v109 * v114[1] + v114[0] * v108;
    v115 = v110 * v112 - v109 * v113;
    v116 = v108 * v113 - v111 * v110;
    v117 = v111 * v109 - v108 * v112;
  }
  *(long double *)(this + 844) = asin(v118);
  v65 = *(_DWORD *)(this + 348);
  v66 = *(double *)(this + 860) * 0.5;
  v126 = v66 * v109;
  v127 = v66 * v110;
  v127 = v122 - v127;
  v133 = v120 - v108 * v66 - *(double *)(v65 + 4);
  v67 = v121 - v126 - *(double *)(v65 + 12);
  v68 = v127 - *(double *)(v65 + 20);
  v114[0] = v68 * *(double *)(v65 + 132) - v67 * *(double *)(v65 + 140);
  v69 = v133 * *(double *)(v65 + 140) - v68 * *(double *)(v65 + 124);
  v114[2] = v67 * *(double *)(v65 + 124) - v133 * *(double *)(v65 + 132);
  v114[0] = v114[0] + *(double *)(v65 + 100);
  v70 = v69 + *(double *)(v65 + 108);
  v71 = v114[2] + *(double *)(v65 + 116);
  v106 = v114[0] * v111 + v71 * v113 + v70 * v112;
  v72 = v114[0] * v115 + v70 * v116 + v71 * v117;
  *(long double *)(this + 308) = sqrt(v72 * v72 + v106 * v106);
  v73 = v113 * *(double *)(v65 + 116) + v112 * *(double *)(v65 + 108) + v111 * *(double *)(v65 + 100);
  v131 = v116 * *(double *)(v65 + 108) + v117 * *(double *)(v65 + 116) + v115 * *(double *)(v65 + 100);
  v118 = sqrt(v131 * v131 + v73 * v73);
  if ( v118 >= *(double *)(this + 292) )
  {
    *(_DWORD *)(this + 252) = -1;
    v74 = 1.0 / v118;
    *(_DWORD *)(this + 256) = -1048577;
  }
  else
  {
    v74 = *(double *)(this + 300);
  }
  v106 = v106 * v74;
  v123 = v74 * v72;
  v75 = v123 * v123 + v106 * v106;
  v129 = sqrt(v75);
  if ( v75 <= 0.0 )
  {
    v119 = 0.0;
    v130 = 0.0;
  }
  else
  {
    v119 = 1.0 / v129;
    v76 = fabs(v123);
    v130 = 1.0 / (fabs(v106) + v76) * v76;
  }
  v107 = v118 * *(double *)(this + 620) + *(double *)(this + 852);
  if ( v107 <= *(double *)(this + 736) )
    v77 = cos(v107 * *(double *)(this + 744) * 3.141592653589793) * *(double *)(this + 728) + *(double *)(this + 720);
  else
    v77 = *(double *)(this + 720) - *(double *)(this + 728);
  if ( v107 <= *(double *)(this + 768) )
    v78 = cos(v107 * *(double *)(this + 776) * 3.141592653589793) * *(double *)(this + 760) + *(double *)(this + 752);
  else
    v78 = *(double *)(this + 752) - *(double *)(this + 760);
  v79 = v129;
  v107 = (v78 - v77) * v130 + v77;
  sub_4FF6C0(v107, v129);
  v132 = v77;
  v80 = fabs(v131);
  if ( v80 >= 1.0 )
  {
    v81 = v123 * v131;
    sub_4FF6C0(v107, v79);
  }
  else
  {
    if ( v123 * v131 <= 0.0 )
    {
      v80 = (v80 + 1.0) * 0.5;
      v129 = v80;
    }
    else
    {
      v129 = (1.0 - v80) * 0.5;
    }
    sub_4FF6C0(v107, v79);
    v131 = v80;
    sub_4FF6C0(v107, v79);
    v81 = (v80 - v131) * v129 + v131;
  }
  v82 = ((v81 - v132) * v130 + v132) * v119;
  v83 = v82 * *(double *)(this + 796) * v107;
  *(long double *)(this + 324) = v83;
  if ( v83 > 1.0 )
  {
    *(_DWORD *)(this + 324) = 0;
    *(_DWORD *)(this + 328) = 1072693248;
  }
  v84 = v128;
  *(long double *)(this + 332) = sqrt(*(double *)(this + 324));
  v85 = *(double *)(this + 688) - *(double *)(this + 696) * *(double *)(this + 680);
  v86 = *(float *)(v84 + 8) - *(double *)(this + 680) * *(float *)(v84 + 12);
  *(double *)(this + 672) = v86;
  v87 = (v85 + (*(double *)(this + 704) - *(double *)(this + 712) * *(double *)(this + 680) - v85) * v130)
      * v86
      * *(double *)(this + 1032);
  v88 = *(double *)(this + 852);
  if ( v88 > *(double *)(this + 660) )
    v88 = *(double *)(this + 660);
  v89 = v87
      * ((((v88 * *(double *)(this + 628) + *(double *)(this + 636)) * v88 + *(double *)(this + 644)) * v88
        + *(double *)(this + 652))
       * *(double *)(this + 852));
  if ( *(double *)(this + 612) > 0.0 )
    v89 = v89 * (*(double *)(this + 612) / (v118 + *(double *)(this + 612)));
  v90 = *(_DWORD *)(this + 252);
  *(long double *)(this + 316) = v89;
  v91 = -(v82 * v89);
  v107 = v106 * v91;
  v92 = v91 * v123;
  if ( v90 != -1 || *(_DWORD *)(this + 256) != -1048577 )
  {
    if ( *(double *)(this + 188) != 0.0 )
    {
      v93 = (v124 - *(double *)(this + 860) * 0.5) * (a2 - *(double *)(this + 252)) * *(double *)(this + 188);
      v126 = v93 * v116;
      v127 = v93 * v117;
      *(long double *)(this + 228) = v115 * v93 + *(double *)(this + 228);
      *(long double *)(this + 236) = v126 + *(double *)(this + 236);
      *(long double *)(this + 244) = v127 + *(double *)(this + 244);
    }
    *(double *)(this + 252) = a2;
    v114[0] = *(double *)(this + 228) - v120;
    v114[1] = *(double *)(this + 236) - v121;
    v114[2] = *(double *)(this + 244) - v122;
    v119 = sqrt(v114[0] * v114[0] + v114[2] * v114[2] + v114[1] * v114[1]);
    if ( v119 >= 0.038 || *(double *)(this + 308) >= 5.0 )
      goto LABEL_88;
    v94 = (1.0 - v118 * *(double *)(this + 300)) * (1.0 - *(double *)(this + 308) * 0.2) * 190000.0;
    if ( v119 > 0.019 )
      v94 = v94 * (2.0 - v119 * 52.63157894736842);
    v106 = (v114[0] * v111 + v114[2] * v113 + v114[1] * v112) * v94 + v107;
    v119 = (v114[0] * v115 + v114[1] * v116 + v114[2] * v117) * v94 + v92;
    if ( *(double *)(this + 316) * *(double *)(this + 316) < v119 * v119 + v106 * v106 )
    {
LABEL_88:
      *(_DWORD *)(this + 252) = -1;
      *(_DWORD *)(this + 256) = -1048577;
    }
    else
    {
      v92 = v119;
      v107 = v106;
    }
  }
  if ( *(_DWORD *)(this + 252) == -1 && *(_DWORD *)(this + 256) == -1048577 )
  {
    *(long double *)(this + 228) = v120;
    *(double *)(this + 236) = v121;
    *(double *)(this + 244) = v122;
    *(double *)(this + 252) = a2;
  }
  v132 = *(double *)(this + 804) * *(double *)(this + 316) * *(double *)(this + 324);
  v95 = fabs(*(double *)(this + 844));
  if ( v95 < *(double *)(this + 812) )
  {
    v96 = v107 - sin(*(double *)(this + 828) * *(double *)(this + 844)) * v132;
LABEL_98:
    v107 = v96;
    goto LABEL_99;
  }
  if ( v95 < 1.570796326794897 )
  {
    v97 = (cos((v95 - *(double *)(this + 812)) * *(double *)(this + 836)) + 1.0) * 0.5 * v132;
    if ( *(double *)(this + 844) <= 0.0 )
    {
      v96 = v97 + v107;
      goto LABEL_98;
    }
    v107 = v107 - v97;
  }
LABEL_99:
  v98 = *(_DWORD *)(this + 348) + 308;
  v129 = (1.0 - v95 * *(double *)(this + 820)) * v92;
  v99 = *(double *)(this + 852);
  v126 = v99 * v109;
  v127 = v99 * v110;
  *(double *)v98 = v108 * v99 + *(double *)v98;
  *(long double *)(v98 + 8) = v126 + *(double *)(v98 + 8);
  *(long double *)(v98 + 16) = v127 + *(double *)(v98 + 16);
  v100 = *(_DWORD *)(this + 348);
  qmemcpy(v114, (const void *)(v100 + 124), sizeof(v114));
  v101 = v114[0] * v114[0] + v114[2] * v114[2] + v114[1] * v114[1];
  v106 = (*(float *)(v128 + 16) + *(double *)(this + 868)) * *(double *)(this + 860);
  if ( v101 <= 1.0 )
  {
    v102 = v114[0] * v106;
    v103 = v106 * v114[1];
    v104 = v106;
  }
  else
  {
    v119 = 1.0 / sqrt(v101) * v106;
    v102 = v119 * v114[0];
    v103 = v119 * v114[1];
    v104 = v119;
  }
  v114[2] = v104 * v114[2];
  *(long double *)(v100 + 332) = *(double *)(v100 + 332) - v102;
  *(long double *)(v100 + 340) = *(double *)(v100 + 340) - v103;
  *(double *)(v100 + 348) = *(double *)(v100 + 348) - v114[2];
  v134 = v129 * v117;
  v126 = v107 * v112;
  v127 = v107 * v113;
  v114[0] = v115 * v129 + v111 * v107;
  v114[1] = v129 * v116 + v126;
  v114[2] = v134 + v127;
  qmemcpy(v155, v114, sizeof(v155));
  sub_57C7B0(&v120, v155);
  v105 = HIDWORD(v107);
  *(_DWORD *)(this + 340) = LODWORD(v107);
  *(_DWORD *)(this + 344) = v105;
}
