char __thiscall sub_423870(int this)
{
  float *v2; // ebp
  _WORD *v3; // eax
  int v4; // ecx
  int v5; // eax
  long double v6; // st7
  double v7; // st5
  double v8; // st4
  double v9; // st2
  int v10; // eax
  double v11; // st7
  double v12; // st6
  int v13; // eax
  float *v14; // ecx
  double v15; // st7
  double v16; // st6
  int v17; // eax
  int v18; // ecx
  int v19; // ecx
  int v20; // edx
  float v21; // eax
  long double v22; // st7
  int v23; // eax
  _DWORD *v24; // ecx
  int v25; // eax
  int v26; // eax
  _DWORD *v27; // eax
  _DWORD *v28; // ebp
  _DWORD *v29; // eax
  int v30; // edi
  int v31; // edx
  int v32; // eax
  int v33; // ecx
  int v34; // ecx
  int v35; // edi
  int v36; // ecx
  int v37; // ebp
  int v38; // edx
  double v39; // st7
  double v40; // st7
  double v41; // st7
  double v42; // st7
  int v43; // eax
  int v44; // ecx
  double v45; // st7
  double v46; // st7
  int v47; // ecx
  int v48; // eax
  double v49; // st7
  double v50; // st7
  double v51; // st7
  double v52; // st7
  bool v53; // c0
  bool v54; // c3
  int v55; // eax
  double v56; // st7
  double v57; // st7
  int v58; // eax
  int v59; // eax
  int v60; // eax
  float v61; // ecx
  int v62; // edx
  double v63; // st7
  int v64; // eax
  double v65; // st7
  int v66; // edx
  double v67; // st7
  double v68; // st6
  float *v69; // ecx
  double v71; // st7
  int v72; // ecx
  double v73; // st7
  double v74; // st7
  double v75; // st7
  double v76; // st7
  long double v77; // st7
  float *v78; // eax
  float v79; // ecx
  float v80; // edx
  long double v81; // st7
  long double v82; // st6
  double v83; // st5
  double v84; // st4
  long double v85; // st3
  long double v86; // st7
  long double v87; // st6
  double v88; // st7
  long double v89; // st6
  double v90; // st7
  double v91; // st7
  int v92; // eax
  long double v93; // st6
  long double v94; // st6
  long double v95; // st6
  double v96; // st7
  long double v97; // st7
  float v98; // eax
  long double v99; // st7
  double v100; // st7
  double v102; // st7
  unsigned __int8 v103; // c0
  unsigned __int8 v104; // c2
  int v105; // eax
  double v106; // st7
  double v107; // st6
  double v108; // st5
  int v109; // ecx
  int v110; // edi
  long double v111; // st7
  double v112; // st7
  int v113; // [esp+0h] [ebp-84h]
  int v114; // [esp+0h] [ebp-84h]
  int v115; // [esp+4h] [ebp-80h]
  int v116; // [esp+4h] [ebp-80h]
  float v117; // [esp+18h] [ebp-6Ch]
  int v118; // [esp+18h] [ebp-6Ch]
  float v119; // [esp+18h] [ebp-6Ch]
  float v120; // [esp+18h] [ebp-6Ch]
  float v121; // [esp+18h] [ebp-6Ch]
  float v122; // [esp+18h] [ebp-6Ch]
  int v123; // [esp+1Ch] [ebp-68h]
  float v124; // [esp+1Ch] [ebp-68h]
  float v125; // [esp+1Ch] [ebp-68h]
  int v126; // [esp+24h] [ebp-60h] BYREF
  float v127; // [esp+28h] [ebp-5Ch]
  int v128; // [esp+2Ch] [ebp-58h]
  float v129[2]; // [esp+30h] [ebp-54h] BYREF
  float v130; // [esp+38h] [ebp-4Ch]
  float v131; // [esp+3Ch] [ebp-48h]
  int v132; // [esp+40h] [ebp-44h]
  float v133; // [esp+44h] [ebp-40h]
  float v134; // [esp+48h] [ebp-3Ch]
  float v135; // [esp+50h] [ebp-34h]
  float v136; // [esp+54h] [ebp-30h]
  float v137; // [esp+5Ch] [ebp-28h]
  float v138; // [esp+60h] [ebp-24h]
  float v139; // [esp+68h] [ebp-1Ch]
  float v140; // [esp+6Ch] [ebp-18h]
  float v141; // [esp+74h] [ebp-10h]
  float v142; // [esp+80h] [ebp-4h]

  v2 = *(float **)(this + 23432);
  *(float *)(this + 23852) = dbl_7DA9D0;
  v123 = (int)v2;
  sub_51C1E0(&v126, v129);
  if ( !*(_DWORD *)(*(_DWORD *)(this + 80) + 25300)
    && *(float *)(this + 23616) > 0.0
    && *(float *)(this + 23852) > (double)*(float *)(this + 23616)
    && dword_75CBB0 == 7 )
  {
    v3 = (_WORD *)(this + 24302);
    v4 = 48;
    do
    {
      *v3 = *(v3 - 1);
      v3 += 2;
      --v4;
    }
    while ( v4 );
  }
  v5 = *(_DWORD *)(this + 23432);
  *(float *)(this + 23876) = -sin(*(float *)(this + 17620));
  *(float *)(this + 23884) = -cos(*(float *)(this + 17620));
  *(float *)(this + 23880) = sin(*(float *)(this + 17616));
  v6 = sqrt(
         *(float *)(this + 17628) * *(float *)(this + 17628)
       + *(float *)(this + 17632) * *(float *)(this + 17632)
       + *(float *)(this + 17636) * *(float *)(this + 17636));
  *(float *)(this + 23764) = v6;
  v7 = *(float *)(this + 17632) + *(float *)(this + 17704);
  v8 = *(float *)(this + 17636) + *(float *)(this + 17708);
  v9 = *(float *)(this + 17700) + *(float *)(this + 17628);
  *(float *)(this + 23768) = (sqrt(v8 * v8 + v7 * v7 + v9 * v9) - v6) * 0.2;
  if ( !v5 )
  {
    v10 = sub_403FD0(&flt_628F60, (float *)&v126, *(_DWORD *)(this + 24244));
    *(_DWORD *)(this + 23432) = v10;
    if ( v10 )
    {
      v2 = (float *)v10;
LABEL_15:
      v123 = (int)v2;
      *(_BYTE *)(this + 23872) = 1;
      goto LABEL_16;
    }
    return 0;
  }
  v11 = *(float *)&v126 - *(float *)(v5 + 196);
  v12 = *(float *)&v128 - *(float *)(v5 + 204);
  if ( v12 * v12 + v11 * v11 > 3200.0 )
  {
    v13 = sub_403FD0(&flt_628F60, (float *)&v126, *(_DWORD *)(this + 24244));
    *(_DWORD *)(this + 23432) = v13;
    if ( !v13 )
      return 0;
    v2 = (float *)v13;
    v123 = v13;
    *(_BYTE *)(this + 23872) = 1;
  }
  v14 = *(float **)(this + 23432);
  v15 = v14[49] - *(float *)&v126;
  v16 = v14[51];
  v129[0] = v14[3];
  v130 = v14[5];
  if ( v130 * (v16 - *(float *)&v128) + v129[0] * v15 < 0.0 )
  {
    v2 = v14;
    goto LABEL_15;
  }
LABEL_16:
  v17 = *(_DWORD *)(this + 23432);
  v18 = *(_DWORD *)(this + 16584);
  *(float *)(this + 23760) = *(float *)(this + 17636) * *(float *)(v17 + 220)
                           + *(float *)(this + 17632) * *(float *)(v17 + 216)
                           + *(float *)(v17 + 212) * *(float *)(this + 17628);
  if ( !v18 )
  {
    v19 = *(_DWORD *)(this + 19084);
    if ( v19 && *(_DWORD *)(v17 + 328) != *(_DWORD *)(v19 + 328) )
      *(_DWORD *)(this + 23432) = v19;
    if ( *(_BYTE *)(this + 24208) )
    {
      v20 = *(_DWORD *)(*(_DWORD *)(this + 23432) + 216);
      v21 = *(float *)(*(_DWORD *)(this + 23432) + 220);
      v131 = *(float *)(*(_DWORD *)(this + 23432) + 212);
      v133 = v21;
      v132 = v20;
      v22 = atan2(-v131, -v21) - *(float *)(this + 17620);
      if ( fabs(v22) >= 3.141592653589793 )
      {
        if ( v22 >= 0.0 )
          v22 = v22 - 6.283185307179586;
        else
          v22 = v22 + 6.283185307179586;
      }
      v23 = sub_514EE0(this + 84);
      if ( v23 )
      {
        if ( !*(_DWORD *)(v23 + 328) )
        {
          if ( *(float *)(this + 23852) - *(float *)(this + 23784) > 1.0 || (v117 = v22, fabs(v117) > 0.699999988079071) )
          {
            if ( *(float *)(this + 24720) > (double)*(float *)(this + 23760) )
            {
              *(float *)&v115 = *(float *)(this + 23728) + 3.0;
              *(float *)&v113 = *(float *)(this + 23728) - 3.0;
              sub_529AC0(this + 23760, 0.30000001, v113, v115);
            }
          }
        }
      }
    }
  }
  if ( !*(_BYTE *)(this + 23872) )
  {
    if ( *(_BYTE *)(this + 76) )
      goto LABEL_155;
    goto LABEL_213;
  }
  v24 = *(_DWORD **)(this + 23432);
  if ( v24[82] == 1 && (v25 = v24[75]) != 0 && !*(_DWORD *)(v25 + 328) )
    *(float *)(this + 24200) = *(float *)(v25 + 116);
  else
    *(_DWORD *)(this + 24200) = v24[29];
  v26 = *(_DWORD *)(this + 80);
  if ( !*(_DWORD *)(v26 + 25300) )
    sub_41F3E0(flt_62BC28, *(_DWORD *)(v26 + 25248), *(float *)(this + 24200));
  v27 = *(_DWORD **)(this + 23436);
  v28 = (_DWORD *)(this + 23436);
  if ( v27 )
    *(_DWORD *)(this + 23432) = sub_4040B0(&flt_628F60, (float *)&v126, v27, v27[82], COERCE_FLOAT(1), 0);
  v29 = *(_DWORD **)(this + 23432);
  *(_DWORD *)(this + 23888) = v29[14];
  *(_DWORD *)(this + 23892) = v29[15];
  *(_DWORD *)(this + 23896) = v29[16];
  if ( *(_DWORD **)(this + 23600) == v29 )
  {
    *(_DWORD *)(this + 24732) = 1065353216;
    *(_DWORD *)(this + 24736) = -1082130432;
    *(_DWORD *)(this + 23600) = 0;
  }
  v118 = 5;
  do
  {
    v30 = *(v28 - 1);
    if ( (unsigned __int8)sub_4EED40(*(_DWORD *)(this + 80))
      && *(_DWORD *)(this + 16584) == 1
      && dword_7D7928 == 2
      && dword_6290F4 >= 2 )
    {
      v31 = *(_DWORD *)(this + 24240);
      if ( !v31 )
        goto LABEL_59;
      v32 = *(_DWORD *)(v30 + 300);
      if ( !v32 )
        goto LABEL_59;
      v33 = *(_DWORD *)(v32 + 328);
      if ( v31 != v33 && (v33 != 3 || dword_75CBB4 == 8) )
        goto LABEL_59;
    }
    else
    {
      v34 = *(_DWORD *)(this + 24240);
      if ( !v34 || (v32 = *(_DWORD *)(v30 + 300)) == 0 || v34 != *(_DWORD *)(v32 + 328) )
LABEL_59:
        v32 = *(_DWORD *)(v30 + 296);
    }
    *v28++ = v32;
    --v118;
  }
  while ( v118 );
  v35 = *(_DWORD *)(this + 23828);
  *(_DWORD *)(this + 23684) = *(_DWORD *)(*(_DWORD *)(this + 4 * v35 + 23432) + 128);
  *(float *)(this + 23688) = -*(float *)(*(_DWORD *)(this + 4 * v35 + 23432) + 124);
  *(_DWORD *)(this + 23692) = *(_DWORD *)(*(_DWORD *)(this + 4 * v35 + 23432) + 160);
  *(float *)(this + 23696) = -*(float *)(*(_DWORD *)(this + 4 * v35 + 23432) + 156);
  if ( v35 - 1 >= 0 )
  {
    v36 = this + 4 * (v35 - 1) + 23432;
    v37 = v35;
    do
    {
      v38 = *(_DWORD *)v36;
      if ( *(_DWORD *)(*(_DWORD *)v36 + 328) == *(_DWORD *)(*(_DWORD *)(this + 4 * v35 + 23432) + 328) )
      {
        if ( *(float *)(this + 23684) <= (double)*(float *)(v38 + 128) )
          v39 = *(float *)(this + 23684);
        else
          v39 = *(float *)(v38 + 128);
        *(float *)(this + 23684) = v39;
        v40 = -*(float *)(*(_DWORD *)v36 + 124);
        if ( v40 <= *(float *)(this + 23688) )
          v40 = *(float *)(this + 23688);
        *(float *)(this + 23688) = v40;
        if ( *(float *)(this + 23692) <= (double)*(float *)(*(_DWORD *)v36 + 160) )
          v41 = *(float *)(this + 23692);
        else
          v41 = *(float *)(*(_DWORD *)v36 + 160);
        *(float *)(this + 23692) = v41;
        v42 = -*(float *)(*(_DWORD *)v36 + 156);
        if ( v42 <= *(float *)(this + 23696) )
          v42 = *(float *)(this + 23696);
        *(float *)(this + 23696) = v42;
      }
      v36 -= 4;
      --v37;
    }
    while ( v37 );
  }
  v43 = *(_DWORD *)(this + 24244);
  if ( v43 || *(_DWORD *)(*(_DWORD *)(this + 23436) + 328) != 1 )
  {
    if ( v43 == 1 && !*(_DWORD *)(*(_DWORD *)(this + 23436) + 328) )
      sub_4BF840(this, 0, 0);
  }
  else
  {
    sub_421590(this, 14, 0);
    sub_4BF840(this, 1, 1);
  }
  v44 = *(_DWORD *)(this + 23432);
  *(_DWORD *)(this + 24248) = *(_DWORD *)(this + 24244);
  *(_DWORD *)(this + 24244) = *(_DWORD *)(v44 + 328);
  *(_BYTE *)(this + 24208) = *(float *)(v44 + 128) + 2.5 > *(float *)(this + 23728)
                          && -(*(float *)(v44 + 124) + 2.5) < *(float *)(this + 23728);
  v45 = *(float *)(v44 + 336);
  if ( v45 <= 0.0 )
  {
    sub_5143A0(*(float *)(v44 + 224), 1.0);
    v46 = v45 * *(float *)(this + 24168);
  }
  else
  {
    v46 = (*(float *)(this + 24176) + *(float *)(this + 24168)) * *(float *)(v44 + 336);
  }
  v119 = v46;
  if ( v119 > 70.0 )
    v119 = 70.0;
  v47 = *(_DWORD *)(this + 24244);
  v48 = *(_DWORD *)(this + 23612);
  *(float *)(this + 23772) = *(float *)(this + 23764) / v119;
  if ( v47 == v48 )
  {
    v49 = flt_7D74DC;
    goto LABEL_96;
  }
  if ( *(_DWORD *)(this + 20844) == 10 || dword_75CBB4 == 3 )
  {
    v49 = flt_7D74E0;
LABEL_96:
    v119 = v49 * 0.89999998;
  }
  if ( (unsigned __int8)sub_4EED40(*(_DWORD *)(this + 80)) )
  {
    if ( *(float *)(this + 23604) >= (double)v119 )
      v50 = v119;
    else
      v50 = *(float *)(this + 23604);
    if ( v50 >= 1.0 )
    {
      if ( *(float *)(this + 23604) < (double)v119 )
        v119 = *(float *)(this + 23604);
    }
    else
    {
      v119 = 1.0;
    }
  }
  v51 = *(float *)(this + 23764) / v119;
  *(float *)(this + 23780) = v51;
  *(float *)(this + 23776) = v51;
  if ( v51 > 1.0 )
    *(_DWORD *)(this + 23776) = 1065353216;
  v52 = *(float *)(this + 23776);
  v53 = v52 < 0.80000001;
  v54 = v52 == 0.80000001;
  if ( *(_DWORD *)(this + 16584) )
  {
    if ( !v53 && !v54 )
      *(_DWORD *)(this + 23784) = *(_DWORD *)(this + 23852);
  }
  else if ( !v53 && !v54 )
  {
    *(_DWORD *)(this + 23784) = *(_DWORD *)(this + 23852);
  }
  if ( *(float *)(this + 23764) >= 10.0 )
  {
    if ( *(float *)(this + 23764) >= 35.0 )
    {
      if ( *(float *)(this + 23764) >= 45.0 )
      {
        if ( *(float *)(this + 23764) >= 60.0 )
        {
          if ( *(float *)(this + 23764) >= 70.0 )
            *(_DWORD *)(this + 23828) = 5;
          else
            *(_DWORD *)(this + 23828) = 4;
        }
        else
        {
          *(_DWORD *)(this + 23828) = 3;
        }
      }
      else
      {
        *(_DWORD *)(this + 23828) = 2;
      }
    }
    else
    {
      *(_DWORD *)(this + 23828) = 1;
    }
  }
  else
  {
    *(_DWORD *)(this + 23828) = 0;
  }
  if ( *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 340) == 6
    && *(_DWORD *)(this + 24244) == 1 )
  {
    v55 = *(_DWORD *)(this + 24020);
    if ( v55 == 8 )
    {
      sub_42C150(17, 1000593162, 0.0);
    }
    else if ( v55 == 12 )
    {
      sub_42C150(16, 1000593162, 0.0);
    }
    else if ( v55 != 16 && v55 != 17 && v55 != 15 )
    {
      sub_42C150(15, 1000593162, 0.0);
    }
  }
  if ( *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 328) == 1
    && !*(_DWORD *)(this + 24244)
    && !*(_BYTE *)(this + 48) )
  {
    v56 = *(float *)(this + 24712);
    *(_BYTE *)(this + 48) = 1;
    if ( v56 > 0.0 )
    {
      v57 = *(float *)(this + 23716) - sub_42B090(7, *(_DWORD *)(this + 23432));
      *(_DWORD *)(this + 24196) = 15;
      *(float *)(this + 24188) = v57;
      sub_42C0F0(14);
      goto LABEL_144;
    }
    v58 = *(_DWORD *)(this + 24020);
    if ( v58 == 7 )
      goto LABEL_143;
    if ( v58 == 8 )
    {
      sub_42C0F0(17);
      goto LABEL_144;
    }
    if ( !*(_DWORD *)(*(_DWORD *)(this + 80) + 25300) )
LABEL_143:
      sub_42C0F0(15);
    else
      sub_42C0F0(16);
LABEL_144:
    sub_51F580(this + 84);
  }
  if ( !*(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 328) && *(_DWORD *)(this + 24244) == 1 )
  {
    v59 = *(_DWORD *)(this + 24020);
    switch ( v59 )
    {
      case 15:
        sub_42C0F0(7);
        break;
      case 17:
        sub_42C0F0(8);
        break;
      case 16:
        sub_42C0F0(12);
        break;
    }
    *(float *)(this + 23620) = sub_42B090(*(_DWORD *)(this + 24020), 0);
    *(float *)(this + 24696) = *(float *)(this + 23852) + 10.0;
  }
  v60 = *(_DWORD *)(this + 23432);
  v61 = *(float *)(this + 17604);
  v62 = *(_DWORD *)(this + 17612);
  v2 = (float *)v123;
  v129[0] = *(float *)(v60 + 196) - v61;
  v63 = *(float *)(v60 + 204);
  v64 = *(_DWORD *)(this + 17608);
  v65 = v63 - *(float *)(this + 17612);
  *(float *)(this + 23900) = v61;
  *(_DWORD *)(this + 23908) = v62;
  *(_DWORD *)(this + 23904) = v64;
  v130 = v65;
  *(float *)(this + 23592) = sqrt(v65 * v130 + v129[0] * v129[0]);
LABEL_155:
  v66 = *(_DWORD *)(this + 23828);
  if ( *(_DWORD *)(this + 4 * v66 + 23432) )
  {
    *(float *)(this + 21892) = v2[82];
    v67 = *(float *)&v126 - v2[49];
    v68 = v2[51];
    v129[0] = v2[11];
    v130 = v2[13];
    v120 = v130 * (*(float *)&v128 - v68) + v129[0] * v67;
    *(float *)(this + 23728) = v120;
    if ( *(_DWORD *)(this + 24244) == 1 )
    {
      v69 = *(float **)(this + 23432);
      if ( (v69[34] - v69[52] + 1.0 < v120 || -(v69[33] + v69[52] + 1.0) > v120)
        && (v69[32] + 1.0 < v120 || -(v69[31] + 1.0) > v120) )
      {
        *(_BYTE *)(this + 23872) = 1;
        *(_DWORD *)(this + 24244) = 0;
        *(_DWORD *)(this + 23436) = sub_403FD0(&flt_628F60, (float *)&v126, 0);
        sub_42C0F0(6);
        return sub_423870(this);
      }
    }
    v71 = *(float *)(this + 23772);
    v72 = *(_DWORD *)(this + 23432);
    *(_DWORD *)(this + 24220) = 0;
    *(_DWORD *)(this + 24216) = 0;
    if ( v71 >= 0.1 )
      v73 = *(float *)(this + 23772);
    else
      v73 = 0.1;
    if ( *(float *)(v72 + 280) / v73 <= 1.3 )
    {
      if ( *(float *)(this + 23772) >= 0.1 )
        v75 = *(float *)(this + 23772);
      else
        v75 = 0.1;
      v74 = *(float *)(v72 + 280) / v75;
    }
    else
    {
      v74 = 1.3;
    }
    v76 = v74 * 1.2;
    v121 = v76 + *(float *)(this + 17620);
    v124 = *(float *)(this + 17620) - v76;
    if ( ((double)v66 + 1.0) * 0.02421 < *(float *)(v72 + 280) )
    {
      v77 = *(float *)(*(_DWORD *)(this + 23448) + 260) - *(float *)(v72 + 260);
      if ( fabs(v77) >= 3.141592653589793 )
      {
        if ( v77 >= 0.0 )
          v77 = v77 - 6.283185307179586;
        else
          v77 = v77 + 6.283185307179586;
      }
      if ( v77 <= 0.0 )
        *(_DWORD *)(this + 24220) = 0;
      else
        *(_DWORD *)(this + 24216) = 0;
    }
    if ( *(_DWORD *)(*(_DWORD *)(this + 80) + 16584) != 1 )
      return 1;
    v78 = *(float **)(this + 4 * v66 + 23432);
    v79 = *(float *)(this + 17604);
    v136 = v78[49];
    v80 = *(float *)(this + 17612);
    v134 = v79;
    v135 = v80;
    v81 = -sin(v121);
    v82 = -cos(v121);
    v83 = v78[11];
    v84 = v78[13];
    v137 = v78[51];
    v85 = 1.0 / sqrt(v84 * v84 + v83 * v83);
    v138 = v85 * v83;
    v139 = v85 * v84;
    if ( v81 == 0.0 )
      *(_DWORD *)(this + 23676) = 0;
    else
      *(float *)(this + 23676) = (v136 * (v82 / v81) + v135 - v134 * (v82 / v81) - v137) / (v139 - v138 * (v82 / v81));
    v86 = -sin(v124);
    v87 = -cos(v124);
    if ( v86 == 0.0 )
      *(_DWORD *)(this + 23680) = 0;
    else
      *(float *)(this + 23680) = (v136 * (v87 / v86) + v135 - v134 * (v87 / v86) - v137) / (v139 - v138 * (v87 / v86));
    v88 = *(float *)(this + 23776) + 0.25;
    if ( v88 > 1.0 )
      v88 = 1.0;
    v89 = fabs(*(float *)(this + 23680) - *(float *)(this + 23676)) * 0.5;
    v122 = v89 / v88;
    *(float *)(this + 24060) = v122;
    v90 = *(float *)(this + 23776) + 0.25;
    if ( v90 > 1.0 )
      v90 = 1.0;
    v125 = v89;
    v91 = v125 / v90;
    v92 = *(_DWORD *)(this + 52);
    *(float *)(this + 24056) = v91;
    if ( v92 < 0 )
    {
      v93 = fabs((double)v92);
      *(float *)(this + 24060) = (0.03333333333333333 * v93 + 1.0) * v122;
      v94 = v93 * 0.025 + 0.5;
      goto LABEL_195;
    }
    if ( v92 > 0 )
    {
      v95 = fabs((double)v92);
      *(float *)(this + 24060) = (0.025 * v95 + 0.5) * v122;
      v94 = v95 * 0.03333333333333333 + 1.0;
LABEL_195:
      *(float *)(this + 24056) = v94 * v91;
    }
    dword_62BF50 = 0;
    flt_62BF4C = -(*(float *)(*(_DWORD *)(this + 23432) + 64) * *(float *)(this + 17632)
                 - *(float *)(*(_DWORD *)(this + 23432) + 60) * *(float *)(this + 17636));
    flt_62BBEC = *(float *)(*(_DWORD *)(this + 23432) + 64) * *(float *)(this + 17628)
               - *(float *)(*(_DWORD *)(this + 23432) + 56) * *(float *)(this + 17636);
    flt_62BBD0 = -(*(float *)(*(_DWORD *)(this + 23432) + 60) * *(float *)(this + 17628)
                 - *(float *)(*(_DWORD *)(this + 23432) + 56) * *(float *)(this + 17632));
    dword_62BC14 = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 196);
    dword_62BC04 = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 200);
    dword_62A380 = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 204);
    dword_62A39C = v126;
    dword_62BF5C = LODWORD(v127);
    dword_62A3A8 = v128;
    dword_62BBCC = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 44);
    dword_62BC1C = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 48);
    dword_62BBD4 = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 52);
    if ( *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 328)
      || !*(_BYTE *)(this + 24208)
      || (v96 = *(float *)&dword_62BBD4 * flt_62BBD0
              + *(float *)&dword_62BC1C * flt_62BBEC
              + *(float *)&dword_62BBCC * flt_62BF4C,
          *(float *)&dword_62BF50 = v96,
          v96 <= 0.1) )
    {
      v97 = sin(*(float *)(this + 17620));
      v98 = *(float *)(this + 17636);
      v140 = *(float *)(this + 17628);
      v141 = v98;
      v99 = -v97;
      v142 = -cos(*(float *)(this + 17620));
      if ( v140 == 0.0 )
      {
        *(_DWORD *)(this + 23700) = 0;
      }
      else
      {
        if ( v99 == 0.0 )
          v99 = 1.0e-10;
        if ( sqrt(
               *(float *)(this + 17628) * *(float *)(this + 17628)
             + *(float *)(this + 17632) * *(float *)(this + 17632)
             + *(float *)(this + 17636) * *(float *)(this + 17636)) >= 1.0 )
          v100 = v141 / v140;
        else
          v100 = v142 / v99;
        *(float *)(this + 23700) = (v136 * v100 + v135 - v134 * v100 - v137) / (v139 - v138 * v100);
      }
    }
    else
    {
      *(float *)(this + 23700) = ((v127 - *(float *)&dword_62BC04) * flt_62BBEC
                                + (*(float *)&v128 - *(float *)&dword_62A380) * flt_62BBD0
                                + (*(float *)&v126 - *(float *)&dword_62BC14) * flt_62BF4C)
                               / *(float *)&dword_62BF50;
    }
    v102 = *(float *)(this + 23700);
    if ( v103 | v104 )
    {
      *(float *)(this + 23680) = v102 - 2.0;
    }
    else if ( v102 > *(float *)(this + 23676) )
    {
      *(float *)(this + 23676) = *(float *)(this + 23700) + 2.0;
    }
    *(_BYTE *)(this + 76) = 0;
  }
LABEL_213:
  v105 = *(_DWORD *)(this + 24024);
  v106 = *(float *)&v126 - *(float *)(this + 23900);
  v107 = *(float *)&v128 - *(float *)(this + 23908);
  v108 = v127 - *(float *)(this + 23904);
  *(float *)(this + 23912) = sqrt(v108 * v108 + v107 * v107 + v106 * v106);
  if ( v105 == 3 || !v105 )
    return 0;
  if ( !*(_BYTE *)(this + 24208) || *(_DWORD *)(*(_DWORD *)(this + 80) + 25300) )
    return 1;
  v109 = *(_DWORD *)(this + 23432);
  v131 = *(float *)(v109 + 212);
  v110 = *(_DWORD *)(v109 + 216);
  v133 = *(float *)(v109 + 220);
  v132 = v110;
  v111 = atan2(-v131, -v133) - *(float *)(this + 17620);
  if ( fabs(v111) >= 3.141592653589793 )
  {
    if ( v111 >= 0.0 )
      v111 = v111 - 6.283185307179586;
    else
      v111 = v111 + 6.283185307179586;
  }
  if ( *(_DWORD *)(v109 + 328)
    || *(float *)(this + 23852) - *(float *)(this + 23784) <= 1.0 && fabs(v111) <= 0.699999988079071 )
  {
    return 1;
  }
  v112 = *(float *)(this + 17636) * *(float *)(v109 + 220)
       + *(float *)(this + 17632) * *(float *)(v109 + 216)
       + *(float *)(this + 17628) * *(float *)(v109 + 212);
  *(float *)(this + 23760) = v112;
  if ( v112 >= *(float *)(this + 24720) )
    return 1;
  *(float *)&v116 = *(float *)(this + 23728) + 3.0;
  *(float *)&v114 = *(float *)(this + 23728) - 3.0;
  sub_529AC0(this + 23760, 0.30000001, v114, v116);
  return 1;
}
