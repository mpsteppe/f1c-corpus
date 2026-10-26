char __thiscall sub_447810(int this)
{
  char v2; // bl
  int v3; // eax
  float *v4; // edi
  double *v5; // ebp
  long double v6; // st7
  int v7; // eax
  double v8; // st7
  double v9; // st7
  double v10; // st7
  long double v11; // st7
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  double *v15; // eax
  double v16; // st7
  double *v17; // eax
  double v18; // st7
  double v19; // rt2
  int v20; // eax
  double v21; // st7
  int v22; // edi
  int v23; // ebx
  double **v24; // ebp
  double *v25; // edi
  double *v26; // eax
  double v27; // st7
  double v28; // st6
  double v29; // st7
  int v30; // eax
  int v31; // ebx
  long double v32; // st7
  double *v33; // ecx
  double v34; // st7
  double *v35; // eax
  double v36; // st7
  double v37; // st6
  long double v38; // st7
  double v39; // st6
  double v40; // st5
  double v41; // st6
  long double v42; // st5
  double v43; // st6
  double v44; // st6
  long double v45; // st7
  long double v46; // st7
  int v47; // ecx
  float v48; // edx
  float *v49; // ecx
  double v50; // st6
  float v51; // eax
  float v52; // edx
  bool v53; // zf
  char result; // al
  double *v55; // edi
  int v56; // ebx
  double *v57; // ecx
  double v58; // st7
  double v59; // st6
  double v60; // st7
  double v61; // st6
  long double v62; // st5
  long double v63; // rax
  long double v64; // st5
  long double v65; // st5
  long double v66; // rax
  long double v67; // st5
  long double v68; // rax
  long double v69; // st5
  float v70; // [esp+4h] [ebp-224h]
  float v71; // [esp+4h] [ebp-224h]
  float v72; // [esp+4h] [ebp-224h]
  float v73; // [esp+1Ch] [ebp-20Ch]
  double *v74; // [esp+1Ch] [ebp-20Ch]
  int v75; // [esp+20h] [ebp-208h]
  int v76; // [esp+20h] [ebp-208h]
  double v77; // [esp+20h] [ebp-208h]
  float v78; // [esp+20h] [ebp-208h]
  float v79; // [esp+2Ch] [ebp-1FCh]
  float v80; // [esp+2Ch] [ebp-1FCh]
  int v81; // [esp+2Ch] [ebp-1FCh]
  double v82; // [esp+30h] [ebp-1F8h] BYREF
  double v83; // [esp+38h] [ebp-1F0h]
  double v84; // [esp+40h] [ebp-1E8h]
  long double v85; // [esp+48h] [ebp-1E0h]
  float v86; // [esp+50h] [ebp-1D8h]
  long double v87; // [esp+58h] [ebp-1D0h]
  long double v88; // [esp+60h] [ebp-1C8h]
  long double v89; // [esp+68h] [ebp-1C0h]
  long double v90; // [esp+70h] [ebp-1B8h]
  long double v91; // [esp+78h] [ebp-1B0h]
  long double v92; // [esp+80h] [ebp-1A8h]
  long double v93; // [esp+88h] [ebp-1A0h]
  long double v94; // [esp+90h] [ebp-198h]
  long double v95; // [esp+98h] [ebp-190h]
  long double v96; // [esp+A0h] [ebp-188h]
  long double v97; // [esp+A8h] [ebp-180h]
  long double v98; // [esp+B0h] [ebp-178h]
  long double v99; // [esp+B8h] [ebp-170h]
  long double v100; // [esp+C0h] [ebp-168h]
  long double v101; // [esp+C8h] [ebp-160h]
  long double v102; // [esp+D0h] [ebp-158h]
  long double v103; // [esp+D8h] [ebp-150h]
  long double v104; // [esp+E0h] [ebp-148h]
  long double v105; // [esp+E8h] [ebp-140h]
  long double v106; // [esp+F0h] [ebp-138h]
  long double v107; // [esp+F8h] [ebp-130h]
  long double v108; // [esp+100h] [ebp-128h]
  long double v109; // [esp+108h] [ebp-120h]
  long double v110; // [esp+110h] [ebp-118h]
  long double v111; // [esp+118h] [ebp-110h]
  long double v112; // [esp+120h] [ebp-108h]
  long double v113; // [esp+128h] [ebp-100h]
  long double v114; // [esp+130h] [ebp-F8h]
  long double v115; // [esp+138h] [ebp-F0h]
  long double v116; // [esp+140h] [ebp-E8h]
  long double v117; // [esp+148h] [ebp-E0h]
  long double v118; // [esp+150h] [ebp-D8h] BYREF
  long double v119; // [esp+158h] [ebp-D0h]
  long double v120; // [esp+160h] [ebp-C8h]
  float v121; // [esp+16Ch] [ebp-BCh]
  float v122; // [esp+170h] [ebp-B8h]
  float v123; // [esp+174h] [ebp-B4h]
  double v124; // [esp+178h] [ebp-B0h] BYREF
  double v125; // [esp+180h] [ebp-A8h]
  double v126; // [esp+188h] [ebp-A0h]
  long double v127; // [esp+190h] [ebp-98h]
  long double v128; // [esp+198h] [ebp-90h]
  long double v129; // [esp+1A0h] [ebp-88h]
  double v130; // [esp+1A8h] [ebp-80h]
  double v131; // [esp+1B8h] [ebp-70h]
  double v132; // [esp+1C0h] [ebp-68h]
  double v133; // [esp+1D0h] [ebp-58h]
  double v134; // [esp+1D8h] [ebp-50h] BYREF
  double v135; // [esp+1E0h] [ebp-48h]
  double v136; // [esp+1E8h] [ebp-40h]
  double v137; // [esp+1F0h] [ebp-38h]
  double v138; // [esp+1F8h] [ebp-30h]
  double v139; // [esp+200h] [ebp-28h]
  double *v140; // [esp+208h] [ebp-20h]
  double v141; // [esp+220h] [ebp-8h]

  v2 = 0;
  v73 = 0.0;
  v3 = sub_5761B0(*(_DWORD *)(this + 9392) + 16);
  v4 = (float *)v3;
  if ( v3 && *(_DWORD *)(v3 + 304) != 1 )
  {
    v2 = 1;
    v73 = *(float *)(v3 + 12) * *(float *)(v3 + 44)
        + *(float *)(v3 + 8) * *(float *)(v3 + 40)
        + *(float *)(v3 + 4) * *(float *)(v3 + 36)
        + *(float *)(v3 + 28);
  }
  v79 = sub_592970(&dword_FB1EF8);
  v5 = (double *)(this + 1376);
  if ( v79 == sub_592980(&dword_FB1EF8) )
  {
    v75 = 4;
    do
    {
      *(v5 - 1) = sub_592970(&dword_FB1EF8);
      if ( v2 == 1 )
      {
        v70 = *(double *)(*((_DWORD *)v5 - 78) + 24) * v4[11]
            + *(double *)(*((_DWORD *)v5 - 78) + 16) * v4[10]
            + *(double *)(*((_DWORD *)v5 - 78) + 8) * v4[9]
            - v73;
        v6 = sub_4477B0(v70);
      }
      else
      {
        v6 = 1.0;
      }
      *v5 = v6;
      v5 += 160;
      --v75;
    }
    while ( v75 );
  }
  else
  {
    v76 = 4;
    v80 = v4[3] * v4[11] + v4[2] * v4[10] + v4[1] * v4[9] + v4[8];
    do
    {
      v7 = *((_DWORD *)v5 - 78);
      v8 = *(double *)(v7 + 8);
      v7 += 8;
      *(float *)&v85 = v8;
      *((float *)&v85 + 1) = *(double *)(v7 + 8);
      v9 = *(double *)(v7 + 16);
      v86 = v9;
      v10 = fabs(v9 * v4[11] + *((float *)&v85 + 1) * v4[10] + *(float *)&v85 * v4[9] - v80);
      v71 = v10;
      sub_592A80(v71);
      *(v5 - 1) = v10;
      if ( v2 == 1 )
      {
        v72 = v86 * v4[11] + *((float *)&v85 + 1) * v4[10] + *(float *)&v85 * v4[9] - v73;
        v11 = sub_4477B0(v72);
      }
      else
      {
        v11 = 1.0;
      }
      *v5 = v11;
      v5 += 160;
      --v76;
    }
    while ( v76 );
  }
  v12 = *(_DWORD *)(this + 9392);
  v13 = *(_DWORD *)(v12 + 4352);
  v14 = v12 + 4352;
  if ( !v13 || *(_BYTE *)(v14 + 64) )
  {
    v15 = *(double **)(this + 6312);
    v16 = v15[6];
    v15 += 4;
    *(double *)(this + 7656) = v16 * *(double *)(this + 7744)
                             + v15[1] * *(double *)(this + 7736)
                             + *v15 * *(double *)(this + 7728);
    *(double *)(this + 7664) = v15[5] * *(double *)(this + 7744)
                             + v15[4] * *(double *)(this + 7736)
                             + v15[3] * *(double *)(this + 7728);
    *(double *)(this + 7672) = v15[8] * *(double *)(this + 7744)
                             + v15[7] * *(double *)(this + 7736)
                             + v15[6] * *(double *)(this + 7728);
    v17 = (double *)(*(_DWORD *)(this + 6312) + 8);
    v18 = *(double *)(this + 7656) + *v17;
    v83 = *(double *)(this + 7664) + *(double *)(*(_DWORD *)(this + 6312) + 16);
    v19 = *(double *)(this + 7672) + v17[2];
    v140 = *(double **)(this + 7636);
    v134 = v18;
    v135 = v83 + 0.15;
    v136 = v19;
    v137 = 0.35;
    v138 = 9.999999933815813e36;
    v20 = sub_45D190(&v134);
    *(_DWORD *)(this + 7636) = v20;
    if ( v20 )
      v21 = v83 - v139;
    else
      v21 = *(double *)(this + 7648);
    *(double *)(this + 7640) = v21;
  }
  v22 = this + 712;
  v23 = 4;
  do
  {
    sub_43BBD0(v22, *(double *)(this + 128));
    v22 += 1280;
    --v23;
  }
  while ( v23 );
  v74 = (double *)(this + 6904);
  v24 = (double **)(this + 6856);
  v25 = (double *)(this + 6456);
  v81 = 12;
  do
  {
    v26 = *(double **)(this + 6312);
    v27 = v26[5] * *v25 + v26[6] * v25[1] + v26[4] * *(v25 - 1);
    v28 = v26[8] * *v25 + v26[9] * v25[1] + v26[7] * *(v25 - 1);
    v141 = v26[11] * *v25 + v26[12] * v25[1] + v26[10] * *(v25 - 1);
    v82 = v27 + v26[1];
    v83 = v28 + v26[2];
    v29 = v141 + v26[3];
    v140 = *v24;
    v84 = v29;
    v134 = v82;
    v135 = v83 + 0.15;
    v136 = v29;
    v137 = 0.35;
    v138 = 9.999999933815813e36;
    v30 = sub_45D190(&v134);
    *v24 = (double *)v30;
    if ( v30 )
    {
      v31 = *(_DWORD *)(v30 + 84);
      v32 = v83 - ((sin(*(float *)(v31 + 24) * v84) + sin(*(float *)(v31 + 24) * v82)) * *(float *)(v31 + 20) + v139);
      *v74 = v32;
      if ( dword_B6FC28 )
        *v74 = v32 + 0.01;
      if ( *v74 < 0.0 )
      {
        v33 = *(double **)(this + 6312);
        v34 = v82;
        *(_BYTE *)(this + 7008) = 1;
        v35 = *v24;
        v124 = v34 - v33[1];
        v125 = v83 - v33[2];
        v126 = v84 - v33[3];
        v36 = v84 * v35[2] + v82 * *v35 + v82 * *v35 + v35[3];
        v37 = v84 * v35[1] + v84 * v35[1] + v82 * v35[2] + v35[4];
        v114 = 1.0 / sqrt(v37 * v37 + v36 * v36 + 1.0);
        v130 = -(v114 * v36);
        v38 = -(v114 * v37);
        v39 = v126 * v33[17] - v125 * v33[18];
        v40 = v124 * v33[18] - v126 * v33[16];
        v133 = v125 * v33[16] - v124 * v33[17];
        v132 = v39 + v33[13];
        v41 = v40 + v33[14];
        v133 = v133 + v33[15];
        v42 = v38 * v133 + v41 * v114 + v132 * v130;
        v77 = v42 * *(double *)(this + 6744) + *(double *)(this + 6736) * *v74;
        if ( v77 > 0.0 )
        {
          v127 = v130 * v42;
          v99 = v127;
          v128 = v114 * v42;
          v100 = v128;
          v129 = v38 * v42;
          v101 = v129;
          v90 = v132 - v127;
          v87 = v90;
          v91 = v41 - v128;
          v88 = v91;
          v92 = v133 - v129;
          v89 = v92;
          v85 = sqrt(v89 * v89 + v88 * v88 + v87 * v87);
          if ( v85 > 1.0 )
          {
            v87 = v87 * (1.0 / v85);
            v88 = v88 * (1.0 / v85);
            v89 = v89 * (1.0 / v85);
          }
          v43 = *(double *)(this + 6752);
          v108 = v87 * v43;
          v96 = v108;
          v109 = v88 * v43;
          v97 = v109;
          v110 = v89 * v43;
          v98 = v110;
          v44 = *(float *)(v31 + 36);
          v105 = v108 * v44;
          v93 = v105;
          v106 = v109 * v44;
          v94 = v106;
          v107 = v110 * v44;
          v95 = v107;
          v111 = v130 - v105;
          v115 = v111;
          v112 = v114 - v106;
          v116 = v112;
          v113 = v38 - v107;
          v117 = v113;
          v102 = v111 * v77;
          v118 = v102;
          v103 = v112 * v77;
          v119 = v103;
          v104 = v113 * v77;
          v120 = v104;
          sub_619450(&v124, &v118);
          if ( v77 > *(double *)(this + 7016) && *(_BYTE *)(v31 + 41) )
          {
            *(double *)(this + 7016) = v77;
            v45 = v85 * 0.0078125 * (v77 * 0.00048828125);
            v78 = v45;
            if ( v45 > 1.0 )
              v78 = 1.0;
            v46 = v85 * 0.01 + 0.5;
            if ( v46 > 2.0 )
              v46 = 2.0;
            v47 = *(_DWORD *)(this + 9392);
            if ( v78 > (double)*(float *)(v47 + 192) )
            {
              v121 = *(v25 - 1);
              v48 = v121;
              v49 = (float *)(v47 + 200);
              v122 = *v25;
              v50 = v25[1];
              *(v49 - 2) = v78;
              v51 = v122;
              v123 = v50;
              *(v49 - 1) = v46;
              *v49 = v48;
              v52 = v123;
              v49[1] = v51;
              v49[2] = v52;
            }
          }
        }
      }
    }
    ++v24;
    v25 += 3;
    v53 = v81 == 1;
    ++v74;
    --v81;
  }
  while ( !v53 );
  result = *(_BYTE *)(this + 7024);
  if ( result )
  {
    v55 = (double *)(this + 6456);
    v56 = 4;
    do
    {
      v57 = *(double **)(this + 6312);
      v82 = v57[5] * *v55 + v57[6] * v55[1] + *(v55 - 1) * v57[4];
      v83 = v57[8] * *v55 + v57[9] * v55[1] + v57[7] * *(v55 - 1);
      v84 = v57[11] * *v55 + v57[12] * v55[1] + v57[10] * *(v55 - 1);
      v58 = v84 * v57[17] - v83 * v57[18];
      v59 = v82 * v57[18] - v84 * v57[16];
      v131 = v83 * v57[16] - v82 * v57[17];
      v130 = v58 + v57[13];
      v60 = v59 + v57[14];
      v61 = v131 + v57[15];
      v102 = v82 + v57[1];
      v62 = v83 + v57[2];
      v115 = v102;
      v103 = v62;
      v63 = v62;
      v64 = v84 + v57[3];
      v116 = v63;
      v104 = v64;
      v65 = v55[84] - v102;
      v117 = v104;
      v111 = v65;
      v66 = v65;
      v67 = v55[85] - v116;
      v105 = v66;
      v112 = v67;
      v68 = v67;
      v69 = v55[86] - v104;
      v106 = v68;
      v113 = v69;
      v107 = v69;
      v93 = v130 * 6500.0;
      v90 = v93;
      v94 = v60 * 6500.0;
      v91 = v94;
      v95 = v61 * 6500.0;
      v92 = v95;
      v96 = v105 * 160000.0;
      v108 = v96;
      v97 = v68 * 160000.0;
      v109 = v97;
      v98 = v69 * 160000.0;
      v110 = v98;
      v99 = v96 - v93;
      v118 = v99;
      v100 = v97 - v94;
      v119 = v100;
      v101 = v98 - v95;
      v120 = v101;
      result = sub_619450(&v82, &v118);
      v55 += 3;
      --v56;
    }
    while ( v56 );
  }
  return result;
}
