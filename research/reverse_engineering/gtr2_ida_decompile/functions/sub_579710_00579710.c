void __thiscall sub_579710(int this, int a2)
{
  double v2; // st7
  int v4; // ebx
  double v5; // st6
  double v6; // st6
  double v7; // st6
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c3
  double v11; // st5
  double v12; // st6
  double v13; // st5
  unsigned __int8 v15; // c0
  unsigned __int8 v16; // c3
  double v17; // st4
  double v18; // st6
  double v19; // st5
  unsigned __int8 v21; // c0
  unsigned __int8 v22; // c3
  double v23; // st4
  double v24; // st6
  double v25; // st5
  unsigned __int8 v27; // c0
  unsigned __int8 v28; // c3
  double v29; // st4
  double v30; // st6
  double v31; // st6
  double v32; // st5
  double v33; // st6
  double v34; // st5
  double v35; // st4
  double v36; // st6
  double v37; // st5
  double v38; // st4
  double v39; // st6
  double v40; // st5
  double v41; // st4
  int v42; // edi
  int v43; // ecx
  float *v44; // edx
  double v45; // st6
  double v46; // st5
  double v47; // st4
  double v48; // st4
  double v49; // st3
  double v50; // st3
  double v51; // st2
  double v52; // st3
  double v53; // st2
  double v54; // st1
  double v55; // st3
  double v56; // st2
  double v57; // st1
  double v58; // st3
  double v59; // st2
  double v60; // st1
  double v61; // st3
  double v62; // st2
  double v63; // st3
  double v64; // st2
  double v65; // st1
  double v66; // st3
  double v67; // st2
  double v68; // st1
  double v69; // st4
  double v70; // st3
  double v71; // st4
  bool v72; // cc
  int v73; // eax
  int v74; // eax
  double v75; // st7
  double v76; // st7
  double v77; // st7
  double v78; // st6
  double v79; // st5
  double v80; // st4
  double v81; // st3
  double v82; // st2
  int v83; // ecx
  float *v84; // eax
  double v85; // st7
  double v86; // st7
  double v87; // st6
  int v88; // edi
  float *v89; // ebx
  double v90; // st7
  double X; // st7
  int v92; // eax
  double v93; // st7
  double v94; // st7
  int v95; // eax
  double v96; // st7
  double v97; // st7
  double v98; // st7
  double v99; // st7
  double v100; // st7
  int v101; // edi
  double v102; // st7
  double v103; // st7
  int v104; // eax
  double v105; // st7
  int v106; // edx
  double v107; // st6
  float *v108; // eax
  double v109; // st7
  double v110; // st7
  float X_4; // [esp+8h] [ebp-44h]
  float X_4a; // [esp+8h] [ebp-44h]
  float v113; // [esp+18h] [ebp-34h]
  float v114; // [esp+18h] [ebp-34h]
  int v115; // [esp+1Ch] [ebp-30h]
  int v116; // [esp+1Ch] [ebp-30h]
  int v117; // [esp+1Ch] [ebp-30h]
  float v118; // [esp+20h] [ebp-2Ch]
  float i; // [esp+20h] [ebp-2Ch]
  float v120; // [esp+24h] [ebp-28h]
  float v121; // [esp+24h] [ebp-28h]
  float v122; // [esp+24h] [ebp-28h]
  float v123; // [esp+28h] [ebp-24h]
  float v124; // [esp+28h] [ebp-24h]
  float v125; // [esp+28h] [ebp-24h]
  float v126; // [esp+2Ch] [ebp-20h]
  float v127; // [esp+2Ch] [ebp-20h]
  float v128; // [esp+2Ch] [ebp-20h]
  float v129; // [esp+30h] [ebp-1Ch]
  float v130; // [esp+30h] [ebp-1Ch]
  float v131; // [esp+34h] [ebp-18h]
  float v132; // [esp+34h] [ebp-18h]
  float v133; // [esp+38h] [ebp-14h]
  float v134; // [esp+38h] [ebp-14h]
  int v135; // [esp+38h] [ebp-14h]
  int v136; // [esp+38h] [ebp-14h]
  float v137; // [esp+38h] [ebp-14h]
  float v138; // [esp+3Ch] [ebp-10h]
  float v139; // [esp+3Ch] [ebp-10h]
  float v140; // [esp+40h] [ebp-Ch]
  float v141; // [esp+40h] [ebp-Ch]
  float v142; // [esp+40h] [ebp-Ch]
  float v143; // [esp+44h] [ebp-8h]
  float v144; // [esp+44h] [ebp-8h]
  float v145; // [esp+48h] [ebp-4h]

  v2 = flt_B720B0;
  v115 = 0;
  v4 = this + 18248;
  v138 = 1.0 / flt_B720D4;
  v5 = 1.0 / (0.071428575 * flt_B720B0);
  *(float *)(this + 18052) = v5;
  *(float *)(this + 18116) = v5;
  *(float *)(this + 18180) = v5;
  *(float *)(this + 18244) = v5;
  *(float *)(this + 18308) = 1.0 / (v138 * 0.071428575);
  v140 = 1.0
       / (fabs(*(float *)(this + 16420) + *(float *)(this + 16168) - *(float *)(this + 16672) - *(float *)(this + 16924))
        * 0.5);
  v143 = 1.0
       / (fabs(*(float *)(this + 16160) - *(float *)(this + 16412) + *(float *)(this + 16664) - *(float *)(this + 16916))
        * 0.5);
  do
  {
    v6 = (double)v115 * v2 * 0.071428575;
    v113 = v6;
    v7 = v6 * *(float *)(this + 16396);
    v123 = v7;
    if ( v9 | v10 )
      v11 = v7;
    else
      v11 = *(float *)(this + 16320);
    v12 = v7 * ((v11 * *(float *)(this + 16316) + 1.0) * *(float *)(this + 16304));
    v13 = v113 * *(float *)(this + 16648);
    v126 = v13;
    if ( v15 | v16 )
      v17 = v13;
    else
      v17 = *(float *)(this + 16572);
    v18 = v12 + (v17 * *(float *)(this + 16568) + 1.0) * *(float *)(this + 16556) * v13;
    v19 = v113 * *(float *)(this + 16900);
    v129 = v19;
    if ( v21 | v22 )
      v23 = v19;
    else
      v23 = *(float *)(this + 16824);
    v24 = v18 + (v23 * *(float *)(this + 16820) + 1.0) * *(float *)(this + 16808) * v19;
    v25 = v113 * *(float *)(this + 17152);
    v131 = v25;
    if ( v27 | v28 )
      v29 = v25;
    else
      v29 = *(float *)(this + 17076);
    v30 = (v24 + (v29 * *(float *)(this + 17072) + 1.0) * v25 * *(float *)(this + 17060)) * *(float *)(this + 19236);
    v120 = v140 * v30 * 0.5;
    v118 = v30 * v143 * 0.5;
    v31 = v123 + v120;
    if ( v31 <= *(float *)(this + 16320) )
      v32 = v31;
    else
      v32 = *(float *)(this + 16320);
    v33 = v31 * ((v32 * *(float *)(this + 16316) + 1.0) * *(float *)(this + 16304));
    v34 = v126 + v120;
    if ( v34 <= *(float *)(this + 16572) )
      v35 = v34;
    else
      v35 = *(float *)(this + 16572);
    v36 = v33 + (v35 * *(float *)(this + 16568) + 1.0) * *(float *)(this + 16556) * v34;
    v133 = -v120;
    v37 = v129 - v120;
    if ( v37 <= *(float *)(this + 16824) )
      v38 = v37;
    else
      v38 = *(float *)(this + 16824);
    v39 = v36 + (v38 * *(float *)(this + 16820) + 1.0) * *(float *)(this + 16808) * v37;
    v40 = v133 + v131;
    if ( v40 <= *(float *)(this + 17076) )
      v41 = v40;
    else
      v41 = *(float *)(this + 17076);
    v42 = *(_DWORD *)(this + 17244);
    v43 = 0;
    v44 = (float *)(this + 16320);
    v45 = v39 + (v41 * *(float *)(this + 17072) + 1.0) * v40 * *(float *)(this + 17060);
    v46 = 0.0;
    do
    {
      if ( v42 )
      {
        if ( v42 == 2 && (unsigned int)v43 > 1 )
          goto LABEL_41;
      }
      else
      {
        if ( v43 == 2 )
          goto LABEL_35;
        if ( v43 != 3 )
          goto LABEL_41;
      }
      if ( v43 != 2 && v43 != 3 )
      {
        v47 = v133;
        goto LABEL_37;
      }
LABEL_35:
      v47 = v120;
LABEL_37:
      v48 = v47 + v113 * v44[19];
      if ( v48 <= *v44 )
        v49 = v48;
      else
        v49 = *v44;
      v46 = v46 + (v49 * *(v44 - 1) + 1.0) * *(v44 - 4) * v48;
LABEL_41:
      ++v43;
      v44 += 63;
    }
    while ( v43 < 4 );
    v50 = v123 - v118;
    if ( v50 <= *(float *)(this + 16320) )
      v51 = v50;
    else
      v51 = *(float *)(this + 16320);
    v52 = v50 * ((v51 * *(float *)(this + 16316) + 1.0) * *(float *)(this + 16304));
    v53 = v126 + v118;
    if ( v53 <= *(float *)(this + 16572) )
      v54 = v53;
    else
      v54 = *(float *)(this + 16572);
    v55 = v52 + (v54 * *(float *)(this + 16568) + 1.0) * *(float *)(this + 16556) * v53;
    v56 = v129 - v118;
    if ( v56 <= *(float *)(this + 16824) )
      v57 = v56;
    else
      v57 = *(float *)(this + 16824);
    v58 = v55 + (v57 * *(float *)(this + 16820) + 1.0) * *(float *)(this + 16808) * v56;
    v59 = v131 + v118;
    if ( v59 <= *(float *)(this + 17076) )
      v60 = v59;
    else
      v60 = *(float *)(this + 17076);
    v121 = (v60 * *(float *)(this + 17072) + 1.0) * v59 * *(float *)(this + 17060) + v58;
    v61 = v123 + v118;
    if ( v61 <= *(float *)(this + 16320) )
      v62 = v61;
    else
      v62 = *(float *)(this + 16320);
    v63 = v61 * ((v62 * *(float *)(this + 16316) + 1.0) * *(float *)(this + 16304));
    v64 = v126 - v118;
    if ( v64 <= *(float *)(this + 16572) )
      v65 = v64;
    else
      v65 = *(float *)(this + 16572);
    v66 = v63 + (v65 * *(float *)(this + 16568) + 1.0) * *(float *)(this + 16556) * v64;
    v67 = v129 + v118;
    if ( v67 <= *(float *)(this + 16824) )
      v68 = v67;
    else
      v68 = *(float *)(this + 16824);
    v134 = (v68 * *(float *)(this + 16820) + 1.0) * *(float *)(this + 16808) * v67 + v66;
    v69 = v131 - v118;
    if ( v69 <= *(float *)(this + 17076) )
      v70 = v69;
    else
      v70 = *(float *)(this + 17076);
    v4 += 4;
    v71 = v69 * (v70 * *(float *)(this + 17072) + 1.0) * *(float *)(this + 17060);
    *(float *)(v4 - 132) = v121;
    v72 = ++v115 < 15;
    *(float *)(v4 - 196) = v45;
    *(float *)(v4 - 4) = v46;
    *(float *)(v4 - 68) = v71 + v134;
  }
  while ( v72 );
  v73 = *(_DWORD *)(this + 17244);
  if ( !v73 )
  {
    v75 = *(float *)(this + 17048) + *(float *)(this + 16796);
LABEL_73:
    v76 = v75 * 0.5;
    goto LABEL_74;
  }
  v74 = v73 - 1;
  if ( !v74 )
  {
    v76 = (*(float *)(this + 17048) + *(float *)(this + 16796) + *(float *)(this + 16544) + *(float *)(this + 16292))
        * 0.25;
LABEL_74:
    *(float *)(this + 18376) = v76;
    goto LABEL_75;
  }
  if ( v74 == 1 )
  {
    v75 = *(float *)(this + 16544) + *(float *)(this + 16292);
    goto LABEL_73;
  }
LABEL_75:
  v77 = (*(float *)(this + 17368) / *(float *)(this + 16292)
       + *(float *)(this + 17368) / *(float *)(this + 16544)
       + *(float *)(this + 17388) / *(float *)(this + 16796)
       + *(float *)(this + 17388) / *(float *)(this + 17048))
      * *(float *)(this + 16040);
  *(float *)(this + 18372) = v77;
  v78 = *(float *)(this + 17428);
  *(float *)(this + 18380) = *(float *)(this + 17428);
  v124 = *(float *)(this + 17432) * 4096.0 - *(float *)(this + 16036) * -9.8100004;
  if ( *(float *)(this + 16292) <= 0.0 )
    v79 = 0.0;
  else
    v79 = *(float *)(this + 16332) / *(float *)(this + 16292) * v124;
  if ( *(float *)(this + 16544) <= 0.0 )
    v80 = 0.0;
  else
    v80 = *(float *)(this + 16584) / *(float *)(this + 16544) * v124;
  if ( *(float *)(this + 16796) <= 0.0 )
    v81 = 0.0;
  else
    v81 = *(float *)(this + 16836) / *(float *)(this + 16796) * v124;
  if ( *(float *)(this + 17048) <= 0.0 )
    v82 = 0.0;
  else
    v82 = *(float *)(this + 17088) / *(float *)(this + 17048) * v124;
  v83 = 3;
  v84 = (float *)(this + 18120);
  *(float *)(this + 18380) = ((v82 + v81) * 0.27500001 + (v80 + v79) * 0.22499999) * 0.00024414062 + v78;
  if ( (_BYTE)a2 )
  {
    *(float *)(this + 18372) = v77 * 0.93000001;
    v85 = 1.0 / *(float *)(this + 18044);
    do
    {
      v84 += 5;
      *(v84 - 21) = v85 * *(v84 - 21) * 0.93000001;
      *(v84 - 5) = v85 * *(v84 - 5) * 0.86000001;
      v84[11] = v85 * v84[11] * 0.86000001;
      v84[27] = v85 * v84[27] * 0.93000001;
      *(v84 - 20) = v85 * *(v84 - 20) * 0.93000001;
      *(v84 - 4) = v85 * *(v84 - 4) * 0.86000001;
      v84[12] = v85 * v84[12] * 0.86000001;
      v84[28] = v85 * v84[28] * 0.93000001;
      *(v84 - 19) = v85 * *(v84 - 19) * 0.93000001;
      *(v84 - 3) = v85 * *(v84 - 3) * 0.86000001;
      v84[13] = v85 * v84[13] * 0.86000001;
      v84[29] = v85 * v84[29] * 0.93000001;
      *(v84 - 18) = v85 * *(v84 - 18) * 0.93000001;
      *(v84 - 2) = v85 * *(v84 - 2) * 0.86000001;
      v84[14] = v85 * v84[14] * 0.86000001;
      v84[30] = v85 * v84[30] * 0.93000001;
      *(v84 - 17) = v85 * *(v84 - 17) * 0.93000001;
      *(v84 - 1) = v85 * *(v84 - 1) * 0.86000001;
      v84[15] = v85 * v84[15] * 0.86000001;
      v84[31] = v85 * v84[31] * 0.93000001;
      --v83;
    }
    while ( v83 );
  }
  else
  {
    *(float *)(this + 18372) = v77 * flt_B72044;
    v86 = flt_B72068;
    v87 = flt_B7208C;
    do
    {
      v84 += 5;
      --v83;
      *(v84 - 21) = v86 * *(v84 - 21);
      *(v84 - 5) = v87 * *(v84 - 5);
      v84[11] = v87 * v84[11];
      v84[27] = v84[27] * 0.97000003;
      *(v84 - 20) = v86 * *(v84 - 20);
      *(v84 - 4) = v87 * *(v84 - 4);
      v84[12] = v87 * v84[12];
      v84[28] = v84[28] * 0.97000003;
      *(v84 - 19) = v86 * *(v84 - 19);
      *(v84 - 3) = v87 * *(v84 - 3);
      v84[13] = v87 * v84[13];
      v84[29] = v84[29] * 0.97000003;
      *(v84 - 18) = v86 * *(v84 - 18);
      *(v84 - 2) = v87 * *(v84 - 2);
      v84[14] = v87 * v84[14];
      v84[30] = v84[30] * 0.97000003;
      *(v84 - 17) = v86 * *(v84 - 17);
      *(v84 - 1) = v87 * *(v84 - 1);
      v84[15] = v87 * v84[15];
      v84[31] = v84[31] * 0.97000003;
    }
    while ( v83 );
  }
  v88 = 0;
  v116 = 0;
  v89 = (float *)(this + 18312);
  do
  {
    v114 = 0.0;
    v122 = 0.0;
    v141 = 0.0;
    for ( i = 128.0; ; i = i * 0.5 )
    {
      v144 = (double)v116 * v138 * 0.071428575;
      v130 = v114 * *(float *)(this + 16036) * v114 * v144;
      v90 = v114 * v114 * *(float *)(this + 17432) - (v114 * v114 * 0.0 - 9.8100004) * *(float *)(this + 16036);
      v125 = v90;
      X = v90 * *(float *)(this + 18116);
      v127 = X;
      X_4 = floor(X);
      v92 = sub_4015C0(X_4);
      v135 = v92;
      if ( v92 < 0 )
      {
        off_16C96CC(a2);
        return;
      }
      if ( v92 >= 14 )
      {
        v92 = 13;
        v135 = 13;
      }
      v93 = *(float *)(this + 4 * v92 + 18120);
      v132 = (*(float *)(this + 4 * v92 + 18124) - v93) * (v127 - (double)v135) + v93;
      v94 = v125 * *(float *)(this + 18180);
      v128 = v94;
      X_4a = floor(v94);
      v95 = sub_4015C0(X_4a);
      v136 = v95;
      if ( v95 >= 0 )
      {
        if ( v95 >= 14 )
        {
          v95 = 13;
          v136 = 13;
        }
        v97 = *(float *)(this + 4 * v95 + 18184);
        v96 = v97 + (*(float *)(this + 4 * v95 + 18188) - v97) * (v128 - (double)v136);
      }
      else
      {
        v96 = *(float *)(this + 18184);
      }
      if ( v132 > v96 )
        v96 = v132;
      v145 = v122;
      v122 = v130 == 0.0 ? 1024.0 : v96 / v130;
      if ( i < 0.40000001 )
        break;
      v141 = v114;
      if ( v96 < v130 )
        v114 = v114 - i;
      else
        v114 = i + v114;
    }
    v98 = v122 - v145;
    if ( v98 == 0.0 )
    {
      v100 = v114;
    }
    else
    {
      v99 = (v122 - 1.0) / v98;
      if ( v99 >= -1.0 )
      {
        if ( v99 > 2.0 )
          v99 = 2.0;
        v100 = v99 * (v141 - v114) + v114;
      }
      else
      {
        v100 = -1.0 * (v141 - v114) + v114;
      }
    }
    if ( v100 < 0.0 )
      v100 = 0.0;
    ++v88;
    *v89++ = v100;
    v116 = v88;
  }
  while ( v88 < 15 );
  v101 = 0;
  *(_DWORD *)(this + 18384) = 0;
  v117 = 0;
  do
  {
    v102 = (double)v117 * *(float *)(this + 17216) * 0.0078125;
    v137 = v102;
    v103 = v102 * 0.03125;
    v142 = v103;
    v139 = floor(v103);
    v104 = sub_4015C0(v139);
    v105 = v142 - v139;
    v106 = *(_DWORD *)(this + 17228);
    v107 = *(float *)(v106 + 8 * v104 + 8);
    v108 = (float *)(v106 + 8 * v104);
    *(float *)(this + 17232) = (v107 - *v108) * v105 + *v108;
    v109 = v105 * (v108[3] - v108[1]) + v108[1];
    *(float *)(this + 17236) = v109;
    v110 = (v109 + *(float *)(this + 17232)) * *(float *)(this + 16040) * v137;
    if ( v110 > *(float *)(this + 18384) )
      *(float *)(this + 18384) = v110;
    v117 = ++v101;
  }
  while ( v101 < 128 );
}
