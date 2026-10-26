void __thiscall sub_51A8C0(int this)
{
  long double v2; // st7
  float *v3; // eax
  float v4; // ecx
  float v5; // edx
  int v6; // eax
  int v7; // ecx
  double v8; // st7
  double v9; // st6
  float *v10; // esi
  float *v11; // edi
  double v12; // st7
  double v13; // st6
  double v14; // st6
  double v15; // st5
  float v16; // edx
  double v17; // st7
  double v18; // st7
  double v19; // st6
  float *v20; // eax
  float v21; // ecx
  float v22; // edx
  float v23; // eax
  double v24; // st7
  double v25; // st6
  double v26; // st5
  double v27; // st7
  double v28; // st6
  double v29; // st7
  double v30; // st6
  unsigned int v31; // ebx
  int v32; // edx
  __int16 v33; // cx
  float v34; // eax
  float v35; // ecx
  float v36; // edx
  float v37; // eax
  float v38; // edx
  float v39; // eax
  float v40; // ecx
  int v41; // edx
  int v42; // ebx
  int v43; // edi
  float *v44; // esi
  double v45; // st7
  double v46; // st6
  int v47; // eax
  double v48; // st7
  double v49; // st6
  float *v50; // eax
  float v51; // ecx
  float v52; // edx
  float v53; // eax
  double v54; // st7
  double v55; // st6
  double v56; // st5
  float v57; // eax
  float v58; // ecx
  int v59; // eax
  double v60; // st6
  double v61; // st7
  double v62; // st7
  double v63; // st6
  double v64; // st7
  double v65; // st6
  int v66; // eax
  unsigned __int8 v67; // al
  int v68; // edx
  char v69; // al
  char v70; // cl
  bool v71; // zf
  __int16 v72; // di
  __int16 v73; // bx
  float v74; // ecx
  float *v75; // esi
  float v76; // edx
  float v77; // eax
  double v78; // st7
  int v79; // eax
  float v80; // [esp-10h] [ebp-114h]
  float v81; // [esp-Ch] [ebp-110h]
  float v82; // [esp-Ch] [ebp-110h]
  float v83; // [esp+0h] [ebp-104h]
  int v84; // [esp+0h] [ebp-104h]
  int v85; // [esp+0h] [ebp-104h]
  int v86; // [esp+14h] [ebp-F0h]
  int v87; // [esp+14h] [ebp-F0h]
  char v88; // [esp+1Bh] [ebp-E9h]
  int v89; // [esp+1Ch] [ebp-E8h]
  float v90; // [esp+1Ch] [ebp-E8h]
  int v91; // [esp+1Ch] [ebp-E8h]
  int v92; // [esp+20h] [ebp-E4h] BYREF
  float v93; // [esp+24h] [ebp-E0h]
  float v94; // [esp+28h] [ebp-DCh]
  float v95; // [esp+2Ch] [ebp-D8h]
  int v96; // [esp+30h] [ebp-D4h] BYREF
  float v97; // [esp+34h] [ebp-D0h]
  float v98; // [esp+38h] [ebp-CCh]
  float v99; // [esp+3Ch] [ebp-C8h]
  float v100; // [esp+40h] [ebp-C4h]
  float v101; // [esp+44h] [ebp-C0h]
  int v102; // [esp+48h] [ebp-BCh] BYREF
  float v103; // [esp+4Ch] [ebp-B8h]
  float v104; // [esp+50h] [ebp-B4h]
  int v105; // [esp+54h] [ebp-B0h]
  float v106; // [esp+58h] [ebp-ACh]
  float v107; // [esp+5Ch] [ebp-A8h]
  float v108; // [esp+60h] [ebp-A4h]
  float v109; // [esp+64h] [ebp-A0h]
  float v110[9]; // [esp+68h] [ebp-9Ch] BYREF
  unsigned int v111; // [esp+8Ch] [ebp-78h]
  int v112; // [esp+90h] [ebp-74h]
  int v113; // [esp+94h] [ebp-70h]
  int v114; // [esp+98h] [ebp-6Ch]
  __int16 v115; // [esp+9Ch] [ebp-68h]
  float v116; // [esp+A0h] [ebp-64h]
  int v117; // [esp+A4h] [ebp-60h] BYREF
  float v118; // [esp+A8h] [ebp-5Ch]
  float v119; // [esp+ACh] [ebp-58h]
  int v120; // [esp+B0h] [ebp-54h]
  int v121; // [esp+B4h] [ebp-50h] BYREF
  float v122; // [esp+B8h] [ebp-4Ch]
  float v123; // [esp+BCh] [ebp-48h]
  float *v124; // [esp+C0h] [ebp-44h]
  int v125[3]; // [esp+C4h] [ebp-40h] BYREF
  double v126; // [esp+D0h] [ebp-34h] BYREF
  double v127; // [esp+D8h] [ebp-2Ch]
  double v128; // [esp+E0h] [ebp-24h]
  int v129; // [esp+E8h] [ebp-1Ch]
  int v130; // [esp+ECh] [ebp-18h]
  int v131; // [esp+F0h] [ebp-14h]
  int v132; // [esp+F4h] [ebp-10h]
  double v133; // [esp+F8h] [ebp-Ch]
  int v134; // [esp+100h] [ebp-4h]

  if ( (*(_DWORD *)(*(_DWORD *)this + 25296) & 2) != 0 )
  {
    if ( flt_7DAB08 == flt_7DAB04 )
    {
      v2 = flt_7DAB04;
    }
    else
    {
      v3 = (float *)sub_514EE0((_DWORD *)this);
      v2 = fabs(
             *(float *)(this + 17528) * v3[13]
           + *(float *)(this + 17524) * v3[12]
           + *(float *)(this + 17520) * v3[11]
           - (v3[13] * v3[2]
            + v3[12] * v3[1]
            + *v3 * v3[11]
            + v3[10]));
      v83 = v2;
      sub_52B8D0(v83);
    }
    v4 = *(float *)(this + 17548);
    v121 = *(_DWORD *)(this + 17544);
    v5 = *(float *)(this + 17552);
    v116 = *(float *)(this + 17480);
    v6 = *(_DWORD *)(this + 16500);
    v106 = v2;
    v89 = 0;
    *(float *)&v102 = 0.0;
    v103 = 0.0;
    v104 = 0.0;
    v122 = v4;
    v123 = v5;
    v88 = 0;
    switch ( v6 )
    {
      case 0:
        sub_449920((int)&dbl_75E930, (float *)(this + 1808));
        if ( *(_BYTE *)(this + 4720) )
          sub_50BCF0(
            (float *)(this + 1808),
            (float *)(this + 17484),
            (float *)(this + 17520),
            *(_DWORD *)(this + 17924));
        v89 = *(_DWORD *)(this + 17924);
        v7 = 0;
        v8 = *(float *)(this + 17492) * *(float *)(this + 19352)
           + *(float *)(this + 17488) * *(float *)(this + 19348)
           + *(float *)(this + 19344) * *(float *)(this + 17484);
        v9 = *(float *)(this + 17496) * *(float *)(this + 19344)
           + *(float *)(this + 17504) * *(float *)(this + 19352)
           + *(float *)(this + 17500) * *(float *)(this + 19348);
        v104 = *(float *)(this + 17508) * *(float *)(this + 19344)
             + *(float *)(this + 17516) * *(float *)(this + 19352)
             + *(float *)(this + 17512) * *(float *)(this + 19348);
        *(float *)&v102 = v8 + *(float *)(this + 17520);
        v103 = v9 + *(float *)(this + 17524);
        v104 = v104 + *(float *)(this + 17528);
        while ( *(float *)(this + 18016) <= 0.0 )
        {
          if ( ++v7 >= 4 )
            goto LABEL_65;
        }
        v88 = 1;
        break;
      case 1:
        v10 = (float *)(this + 2056);
        v11 = (float *)(this + 17708);
        v105 = 4;
        do
        {
          v12 = v11[15];
          v13 = (1.0 - v11[16]) * v12;
          v90 = v13;
          if ( v13 <= 8500.0 )
          {
            *v10 = 0.0;
          }
          else if ( *v10 == 0.0 )
          {
            *v10 = 0.0000099999997;
          }
          else
          {
            if ( v90 <= 15500.0 )
              v14 = (v90 - 8500.0) * 0.00014285714;
            else
              v14 = 1.0;
            v15 = *v10 + 0.125;
            *v10 = v15;
            if ( v15 > v14 )
              *v10 = v14;
          }
          if ( v90 <= 1750.0 )
          {
            v10[1] = 0.0;
          }
          else if ( v90 <= 3500.0 )
          {
            v10[1] = (v90 - 1750.0) * 0.00057142857;
          }
          else
          {
            v10[1] = 1.0;
          }
          v16 = *v10;
          v10[4] = v10[1];
          v10[3] = v16;
          *((_DWORD *)v10 + 6) = 20;
          if ( v12 <= 0.0 )
          {
            v10[2] = 0.0;
          }
          else
          {
            v10[2] = v106;
            v88 = 1;
          }
          v17 = v10[2];
          v10[5] = 0.0;
          if ( v17 > 0.0 )
          {
            *v10 = 0.0;
            v10[3] = 0.0;
            v10[4] = 0.0;
          }
          v95 = v11[54];
          if ( v95 != 0.0 && sub_4F5E80(*(_DWORD **)(LODWORD(v95) + 84), v10 - 7) )
          {
            v18 = *(float *)(this + 17488) * *v11
                + *(float *)(this + 17492) * v11[1]
                + *(float *)(this + 17484) * *(v11 - 1);
            v19 = *(float *)(this + 17500) * *v11
                + *(float *)(this + 17504) * v11[1]
                + *(float *)(this + 17496) * *(v11 - 1);
            v94 = *(float *)(this + 17512) * *v11
                + *(float *)(this + 17516) * v11[1]
                + *(float *)(this + 17508) * *(v11 - 1);
            *(float *)&v92 = v18 + *(float *)(this + 17520);
            v93 = v19 + *(float *)(this + 17524);
            v94 = v94 + *(float *)(this + 17528);
            v20 = (float *)sub_51B790(v125);
            v21 = *v20;
            v22 = v20[1];
            v23 = v20[2];
            v99 = v21;
            v24 = v21 + *(float *)(this + 17556);
            v100 = v22;
            v101 = v23;
            v25 = v22 + *(float *)(this + 17560);
            v26 = v23 + *(float *)(this + 17564);
            *(float *)&v96 = v26 * *(float *)(this + 17492)
                           + v25 * *(float *)(this + 17488)
                           + v24 * *(float *)(this + 17484);
            v84 = *(_DWORD *)(this + 4);
            v97 = v26 * *(float *)(this + 17504) + v25 * *(float *)(this + 17500) + v24 * *(float *)(this + 17496);
            v80 = *(float *)(this + 17480);
            v98 = v26 * *(float *)(this + 17516) + v25 * *(float *)(this + 17512) + v24 * *(float *)(this + 17508);
            sub_4F5EE0(*(int **)(LODWORD(v95) + 84), (int)(v10 - 7), v80, (int)&v92, (float *)&v96, SLODWORD(v95), v84);
          }
          v11 += 62;
          v10 += 76;
          --v105;
        }
        while ( v105 );
        v89 = *(_DWORD *)(this + 18172);
        v27 = *(float *)(this + 17492) * *(float *)(this + 19352)
            + *(float *)(this + 17488) * *(float *)(this + 19348)
            + *(float *)(this + 17484) * *(float *)(this + 19344);
        v28 = *(float *)(this + 17496) * *(float *)(this + 19344)
            + *(float *)(this + 17504) * *(float *)(this + 19352)
            + *(float *)(this + 17500) * *(float *)(this + 19348);
        v104 = *(float *)(this + 17508) * *(float *)(this + 19344)
             + *(float *)(this + 17516) * *(float *)(this + 19352)
             + *(float *)(this + 17512) * *(float *)(this + 19348);
        *(float *)&v102 = v27 + *(float *)(this + 17520);
        v103 = v28 + *(float *)(this + 17524);
        v104 = v104 + *(float *)(this + 17528);
        sub_51A820(this);
        if ( sub_4F63F0((float *)(this + 1968)) )
        {
          v85 = *(_DWORD *)(this + 4);
          v81 = *(float *)(this + 17480);
          v29 = *(float *)(this + 17492) * *(float *)(this + 19716)
              + *(float *)(this + 17488) * *(float *)(this + 19712)
              + *(float *)(this + 19708) * *(float *)(this + 17484);
          v30 = *(float *)(this + 17504) * *(float *)(this + 19716)
              + *(float *)(this + 17500) * *(float *)(this + 19712)
              + *(float *)(this + 17496) * *(float *)(this + 19708);
          v94 = *(float *)(this + 17516) * *(float *)(this + 19716)
              + *(float *)(this + 17512) * *(float *)(this + 19712)
              + *(float *)(this + 17508) * *(float *)(this + 19708);
          *(float *)&v92 = v29 + *(float *)(this + 17520);
          v93 = v30 + *(float *)(this + 17524);
          v94 = v94 + *(float *)(this + 17528);
          v96 = *(int *)(this + 17544);
          v97 = *(float *)(this + 17548);
          v98 = *(float *)(this + 17552);
          sub_4F6430(&dword_7D73D0, (float *)(this + 1968), v81, (float *)&v92, (float *)&v96, v85);
        }
        if ( *(_BYTE *)(this + 4720) )
          sub_50BCF0(
            (float *)(this + 1808),
            (float *)(this + 17484),
            (float *)(this + 17520),
            *(_DWORD *)(this + 17924));
        break;
      case 2:
      case 3:
        v31 = *(_DWORD *)(this + 4604);
        v112 = *(_DWORD *)(this + 4608);
        v113 = *(_DWORD *)(this + 4612);
        v32 = *(_DWORD *)(this + 4616);
        v33 = *(_WORD *)(this + 4620);
        v111 = v31;
        v114 = v32;
        v115 = v33;
        if ( v6 == 3 )
        {
          v95 = sub_4D9E20(&dword_7D5DAC);
          v116 = v95;
          v34 = *(float *)(this + 1892);
          qmemcpy(v110, (const void *)(this + 1840), sizeof(v110));
          v35 = *(float *)(this + 1896);
          v36 = *(float *)(this + 1900);
          v107 = v34;
          v108 = v35;
          v109 = v36;
        }
        else
        {
          v37 = *(float *)(this + 17480);
          qmemcpy(v110, (const void *)(this + 17484), sizeof(v110));
          v38 = *(float *)(this + 17520);
          v95 = v37;
          v39 = *(float *)(this + 17524);
          v40 = *(float *)(this + 17528);
          v107 = v38;
          v108 = v39;
          v109 = v40;
        }
        v41 = HIBYTE(v31);
        v120 = (unsigned __int8)v31;
        v42 = 0;
        v117 = v41;
        LODWORD(v118) = BYTE2(v111);
        LODWORD(v119) = BYTE1(v111);
        v105 = 0;
        v43 = this + 2064;
        v44 = (float *)(this + 17708);
        do
        {
          v91 = *(&v117 + v42) & 7;
          v45 = (double)((*(&v117 + v42) >> 3) & 7) * 0.14285715;
          *(_DWORD *)(v43 + 16) = (*(&v117 + v42) >> 3) & 0xFFFFFFF8;
          *(float *)(v43 - 8) = v45;
          v46 = (double)v91 * 0.14285715;
          *(float *)(v43 - 4) = v46;
          *(float *)(v43 + 4) = v45;
          *(float *)(v43 + 8) = v46;
          v47 = *(_DWORD *)(this + 16500);
          v48 = v110[1] * *v44 + v110[0] * *(v44 - 1) + v110[2] * v44[1];
          v49 = v110[4] * *v44 + v110[3] * *(v44 - 1) + v110[5] * v44[1];
          v94 = v110[7] * *v44 + v110[6] * *(v44 - 1) + v110[8] * v44[1];
          *(float *)&v92 = v107 + v48;
          v93 = v108 + v49;
          v94 = v109 + v94;
          if ( v47 == 2 )
          {
            v50 = (float *)sub_51B790(v125);
            v51 = *v50;
            v52 = v50[1];
            v53 = v50[2];
            v99 = v51;
            v54 = v51 + *(float *)(this + 17556);
            v100 = v52;
            v101 = v53;
            v55 = v52 + *(float *)(this + 17560);
            v56 = v53 + *(float *)(this + 17564);
            *(float *)&v96 = v110[2] * v56 + v110[1] * v55 + v54 * v110[0];
            v97 = v110[5] * v56 + v110[4] * v55 + v110[3] * v54;
            v98 = v110[8] * v56 + v110[7] * v55 + v110[6] * v54;
          }
          else
          {
            v57 = *(float *)(this + 80);
            v58 = *(float *)(this + 84);
            v96 = *(int *)(this + 76);
            v97 = v57;
            v98 = v58;
          }
          v126 = *(float *)&v92;
          v127 = v93;
          v128 = v94;
          v129 = 0x40000000;
          v130 = 1072902963;
          v131 = 0x40000000;
          v132 = 1201543096;
          v134 = v105;
          v59 = sub_44E900(dbl_760B48, (int)&v126);
          v60 = v93 - v44[32];
          v105 = v59;
          v89 = v59;
          if ( v60 >= v133 )
          {
            *(_DWORD *)v43 = 0;
          }
          else
          {
            *(float *)v43 = v106;
            v88 = 1;
          }
          v61 = *(float *)v43;
          *(_DWORD *)(v43 + 12) = 0;
          if ( v61 > 0.0 )
          {
            *(_DWORD *)(v43 - 8) = 0;
            *(_DWORD *)(v43 + 4) = 0;
            *(_DWORD *)(v43 + 8) = 0;
          }
          if ( v59 )
            sub_4F5EE0(*(int **)(v59 + 84), v43 - 36, v95, (int)&v92, (float *)&v96, v59, *(_DWORD *)(this + 4));
          ++v42;
          v44 += 62;
          v43 += 304;
        }
        while ( v42 < 4 );
        v62 = v110[0] * *(float *)(this + 19344)
            + v110[1] * *(float *)(this + 19348)
            + v110[2] * *(float *)(this + 19352);
        v63 = v110[3] * *(float *)(this + 19344)
            + v110[4] * *(float *)(this + 19348)
            + v110[5] * *(float *)(this + 19352);
        v104 = v110[6] * *(float *)(this + 19344)
             + v110[7] * *(float *)(this + 19348)
             + v110[8] * *(float *)(this + 19352);
        *(float *)&v102 = v107 + v62;
        v103 = v108 + v63;
        v104 = v109 + v104;
        v64 = v110[2] * *(float *)(this + 19716)
            + v110[0] * *(float *)(this + 19708)
            + v110[1] * *(float *)(this + 19712);
        v65 = v110[5] * *(float *)(this + 19716)
            + v110[3] * *(float *)(this + 19708)
            + v110[4] * *(float *)(this + 19712);
        v94 = v110[8] * *(float *)(this + 19716)
            + v110[6] * *(float *)(this + 19708)
            + v110[7] * *(float *)(this + 19712);
        v66 = *(_DWORD *)(this + 16500);
        *(float *)&v92 = v107 + v64;
        v93 = v108 + v65;
        v94 = v109 + v94;
        if ( v66 == 2 )
        {
          v96 = *(int *)(this + 17544);
          v97 = *(float *)(this + 17548);
          v98 = *(float *)(this + 17552);
        }
        else
        {
          v96 = *(int *)(this + 76);
          v97 = *(float *)(this + 80);
          v98 = *(float *)(this + 84);
          v121 = v96;
          v122 = v97;
          v123 = v98;
        }
        v67 = BYTE2(v112);
        v86 = (BYTE2(v112) >> 2) & 7;
        v68 = *(_DWORD *)(this + 4);
        *(float *)(this + 1968) = (double)(BYTE2(v112) & 3) * 0.33333334;
        *(float *)(this + 1988) = (double)v86 * 0.14285715;
        v82 = v95;
        *(float *)(this + 2008) = (double)(v67 >> 5) * 0.14285715;
        sub_4F6430(&dword_7D73D0, (float *)(this + 1968), v82, (float *)&v92, (float *)&v96, v68);
        v87 = BYTE1(v112) & 0xF;
        v69 = v112;
        v70 = (unsigned __int8)v112 >> 4;
        *(float *)(this + 2312) = (double)((unsigned __int16)v112 >> 12) * 0.06666667;
        *(float *)(this + 2616) = (double)v87 * 0.06666667;
        v71 = v113 == 0;
        *(float *)(this + 2920) = (double)(v70 & 0xF) * 0.06666667;
        *(float *)(this + 3224) = (double)(v69 & 0xF) * 0.06666667;
        if ( !v71 )
        {
          v124 = (float *)dword_7D73E8;
          if ( dword_7D73E8 )
          {
            v72 = HIWORD(v114);
            v73 = v114;
            v74 = 0.0;
            v95 = 0.0;
            v75 = (float *)(this + 4728);
            do
            {
              if ( ((1 << SLOBYTE(v74)) & v113) != 0 )
              {
                v76 = *v75;
                v77 = v75[1];
                v101 = v75[2];
                v100 = v77;
                v99 = v76;
                v119 = v110[8] * v101 + v110[7] * v77 + v110[6] * v76;
                *(float *)&v117 = v110[2] * v101 + v110[1] * v77 + v76 * v110[0] + v107;
                v118 = v110[5] * v101 + v110[4] * v77 + v110[3] * v76 + v108;
                v119 = v119 + v109;
                *(float *)v125 = (double)v73 * 0.015625;
                *(float *)&v125[1] = (double)v72 * 0.015625;
                *(float *)&v125[2] = (double)v115 * 0.015625;
                sub_4F44B0(
                  v124,
                  (float *)&v117,
                  HIBYTE(v112) >> 4,
                  (float *)v125,
                  HIBYTE(v112) & 0xF,
                  v105,
                  0xFFFFFF,
                  -1.0);
                v74 = v95;
              }
              ++LODWORD(v74);
              v75 += 7;
              v95 = v74;
            }
            while ( SLODWORD(v74) < 17 );
          }
        }
        break;
      default:
        break;
    }
LABEL_65:
    if ( v106 > 0.0 && v88 )
    {
      v126 = *(float *)&v102;
      v127 = v103;
      v78 = v104;
      *(float *)(this + 3292) = v106;
      v128 = v78;
      *(_DWORD *)(this + 3272) = 0;
      *(_DWORD *)(this + 3276) = 0;
      *(_DWORD *)(this + 3280) = 0;
      *(_DWORD *)(this + 3284) = 0;
      *(_DWORD *)(this + 3288) = 0;
      v129 = 0x40000000;
      v130 = 1072902963;
      v131 = 0x40000000;
      v132 = 1201543096;
      v134 = v89;
      v79 = sub_44E900(dbl_760B48, (int)&v126);
      if ( v79 )
        sub_4F5EE0(*(int **)(v79 + 84), this + 3244, v116, (int)&v102, (float *)&v121, v79, *(_DWORD *)(this + 4));
    }
  }
}
