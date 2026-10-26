void __thiscall sub_4EE2D0(int this)
{
  long double v2; // st7
  float *v3; // eax
  int v4; // ecx
  float v5; // edx
  int v6; // eax
  float v7; // ecx
  int v8; // ecx
  double v9; // st7
  double v10; // st6
  float *v11; // esi
  int v12; // edi
  double v13; // st7
  double v14; // st6
  double v15; // st6
  double v16; // st5
  int v17; // ecx
  double v18; // st7
  double v19; // st7
  double v20; // st6
  float *v21; // eax
  float v22; // ecx
  float v23; // edx
  float v24; // eax
  double v25; // st7
  double v26; // st6
  double v27; // st5
  double v28; // st7
  double v29; // st6
  double v30; // st7
  double v31; // st6
  unsigned int v32; // ebx
  int v33; // edx
  __int16 v34; // cx
  float v35; // eax
  float v36; // ecx
  float v37; // edx
  int v38; // eax
  float v39; // edx
  float v40; // eax
  float v41; // ecx
  float v42; // edx
  int v43; // ebx
  int v44; // edi
  float *v45; // esi
  double v46; // st7
  double v47; // st6
  int v48; // eax
  double v49; // st7
  double v50; // st6
  float *v51; // eax
  float v52; // ecx
  float v53; // edx
  float v54; // eax
  double v55; // st7
  double v56; // st6
  double v57; // st5
  float v58; // eax
  float v59; // ecx
  int v60; // eax
  double v61; // st6
  double v62; // st7
  double v63; // st7
  double v64; // st6
  double v65; // st7
  double v66; // st6
  int v67; // eax
  unsigned __int8 v68; // al
  int v69; // edx
  char v70; // al
  char v71; // cl
  bool v72; // zf
  float *v73; // edx
  __int16 v74; // bx
  int v75; // edi
  float *v76; // esi
  float v77; // ecx
  double v78; // st7
  int v79; // eax
  float v80; // [esp-10h] [ebp-114h]
  float v81; // [esp-Ch] [ebp-110h]
  float v82; // [esp-Ch] [ebp-110h]
  float v83; // [esp+0h] [ebp-104h]
  int v84; // [esp+0h] [ebp-104h]
  int v85; // [esp+0h] [ebp-104h]
  int v86; // [esp+18h] [ebp-ECh]
  int v87; // [esp+18h] [ebp-ECh]
  char v88; // [esp+1Fh] [ebp-E5h]
  int v89; // [esp+20h] [ebp-E4h]
  float v90; // [esp+20h] [ebp-E4h]
  int v91; // [esp+20h] [ebp-E4h]
  int v92; // [esp+24h] [ebp-E0h] BYREF
  float v93; // [esp+28h] [ebp-DCh]
  float v94; // [esp+2Ch] [ebp-D8h]
  int v95; // [esp+30h] [ebp-D4h] BYREF
  float v96; // [esp+34h] [ebp-D0h]
  float v97; // [esp+38h] [ebp-CCh]
  float v98; // [esp+3Ch] [ebp-C8h]
  float v99; // [esp+40h] [ebp-C4h]
  float v100; // [esp+44h] [ebp-C0h]
  float v101; // [esp+48h] [ebp-BCh]
  int v102; // [esp+4Ch] [ebp-B8h] BYREF
  float v103; // [esp+50h] [ebp-B4h]
  float v104; // [esp+54h] [ebp-B0h]
  int v105; // [esp+58h] [ebp-ACh]
  float v106; // [esp+5Ch] [ebp-A8h]
  float v107; // [esp+60h] [ebp-A4h]
  float v108; // [esp+64h] [ebp-A0h]
  float v109; // [esp+68h] [ebp-9Ch]
  float v110[9]; // [esp+6Ch] [ebp-98h] BYREF
  unsigned int v111; // [esp+90h] [ebp-74h]
  int v112; // [esp+94h] [ebp-70h]
  int v113; // [esp+98h] [ebp-6Ch]
  int v114; // [esp+9Ch] [ebp-68h]
  __int16 v115; // [esp+A0h] [ebp-64h]
  float v116; // [esp+A4h] [ebp-60h]
  float v117; // [esp+A8h] [ebp-5Ch] BYREF
  float v118; // [esp+ACh] [ebp-58h]
  float v119; // [esp+B0h] [ebp-54h]
  int v120; // [esp+B4h] [ebp-50h]
  int v121; // [esp+B8h] [ebp-4Ch] BYREF
  float v122; // [esp+BCh] [ebp-48h]
  float v123; // [esp+C0h] [ebp-44h]
  float v124[3]; // [esp+C4h] [ebp-40h] BYREF
  double v125; // [esp+D0h] [ebp-34h] BYREF
  double v126; // [esp+D8h] [ebp-2Ch]
  double v127; // [esp+E0h] [ebp-24h]
  int v128; // [esp+E8h] [ebp-1Ch]
  int v129; // [esp+ECh] [ebp-18h]
  int v130; // [esp+F0h] [ebp-14h]
  int v131; // [esp+F4h] [ebp-10h]
  double v132; // [esp+F8h] [ebp-Ch]
  int v133; // [esp+100h] [ebp-4h]

  if ( flt_8AFEEC == flt_8AFEE8 )
  {
    v2 = flt_8AFEE8;
  }
  else
  {
    v3 = (float *)sub_4E9630((_DWORD *)this);
    v2 = fabs(
           *(float *)(this + 13532) * v3[10]
         + *(float *)(this + 13528) * v3[9]
         + *(float *)(this + 13524) * v3[8]
         - (v3[10] * v3[2]
          + v3[9] * v3[1]
          + *v3 * v3[8]
          + v3[7]));
    v83 = v2;
    sub_4FD7E0(v83);
  }
  v4 = *(_DWORD *)(this + 13548);
  v5 = *(float *)(this + 13552);
  v123 = *(float *)(this + 13556);
  v6 = *(_DWORD *)(this + 12988);
  v121 = v4;
  v7 = *(float *)(this + 13484);
  v109 = v2;
  v89 = 0;
  *(float *)&v102 = 0.0;
  v103 = 0.0;
  v104 = 0.0;
  v122 = v5;
  v88 = 0;
  v116 = v7;
  switch ( v6 )
  {
    case 0:
      sub_4472B0((int)&dbl_7C7428, (float *)(this + 1764));
      if ( *(_BYTE *)(this + 4208) )
        sub_4E16F0((float *)(this + 1764), (float *)(this + 13488), (float *)(this + 13524), *(_DWORD *)(this + 13928));
      v89 = *(_DWORD *)(this + 13928);
      v8 = 0;
      v9 = *(float *)(this + 13496) * *(float *)(this + 15344)
         + *(float *)(this + 13492) * *(float *)(this + 15340)
         + *(float *)(this + 15336) * *(float *)(this + 13488);
      v10 = *(float *)(this + 13500) * *(float *)(this + 15336)
          + *(float *)(this + 13508) * *(float *)(this + 15344)
          + *(float *)(this + 13504) * *(float *)(this + 15340);
      v104 = *(float *)(this + 13512) * *(float *)(this + 15336)
           + *(float *)(this + 13520) * *(float *)(this + 15344)
           + *(float *)(this + 13516) * *(float *)(this + 15340);
      *(float *)&v102 = v9 + *(float *)(this + 13524);
      v103 = v10 + *(float *)(this + 13528);
      v104 = v104 + *(float *)(this + 13532);
      while ( *(float *)(this + 14020) <= 0.0 )
      {
        if ( ++v8 >= 4 )
          goto LABEL_64;
      }
      v88 = 1;
      break;
    case 1:
      v11 = (float *)(this + 2004);
      v12 = this + 13712;
      v105 = 4;
      do
      {
        v13 = *(float *)(v12 + 60);
        v14 = (1.0 - *(float *)(v12 + 64)) * v13;
        v90 = v14;
        if ( v14 <= 7500.0 )
        {
          *v11 = 0.0;
        }
        else if ( *v11 == 0.0 )
        {
          *v11 = 0.0000099999997;
        }
        else
        {
          if ( v90 <= 15000.0 )
            v15 = (v90 - 7500.0) * 0.00013333333;
          else
            v15 = 1.0;
          v16 = *v11 + 0.125;
          *v11 = v16;
          if ( v16 > v15 )
            *v11 = v15;
        }
        if ( v90 <= 1750.0 )
        {
          v11[1] = 0.0;
        }
        else if ( v90 <= 3500.0 )
        {
          v11[1] = (v90 - 1750.0) * 0.00057142857;
        }
        else
        {
          v11[1] = 1.0;
        }
        v17 = *((_DWORD *)v11 + 1);
        v11[3] = *v11;
        *((_DWORD *)v11 + 4) = v17;
        *((_DWORD *)v11 + 6) = 20;
        if ( v13 <= 0.0 )
        {
          v11[2] = 0.0;
        }
        else
        {
          v11[2] = v109;
          v88 = 1;
        }
        v18 = v11[2];
        v11[5] = 0.0;
        if ( v18 > 0.0 )
        {
          *v11 = 0.0;
          v11[3] = 0.0;
          v11[4] = 0.0;
        }
        v101 = *(float *)(v12 + 216);
        if ( v101 != 0.0 && sub_4CE380(*(_DWORD **)(LODWORD(v101) + 84), v11 - 7) )
        {
          v19 = *(float *)(this + 13496) * *(float *)(v12 + 4)
              + *(float *)(this + 13492) * *(float *)v12
              + *(float *)(v12 - 4) * *(float *)(this + 13488);
          v20 = *(float *)(this + 13508) * *(float *)(v12 + 4)
              + *(float *)(this + 13500) * *(float *)(v12 - 4)
              + *(float *)(this + 13504) * *(float *)v12;
          v94 = *(float *)(this + 13520) * *(float *)(v12 + 4)
              + *(float *)(this + 13512) * *(float *)(v12 - 4)
              + *(float *)(this + 13516) * *(float *)v12;
          *(float *)&v92 = v19 + *(float *)(this + 13524);
          v93 = v20 + *(float *)(this + 13528);
          v94 = v94 + *(float *)(this + 13532);
          v21 = sub_4ED750((float *)(this + 13572), (float *)(v12 - 4), v124);
          v22 = *v21;
          v23 = v21[1];
          v24 = v21[2];
          v98 = v22;
          v25 = v22 + *(float *)(this + 13560);
          v99 = v23;
          v100 = v24;
          v26 = v23 + *(float *)(this + 13564);
          v27 = v24 + *(float *)(this + 13568);
          *(float *)&v95 = v27 * *(float *)(this + 13496)
                         + v26 * *(float *)(this + 13492)
                         + v25 * *(float *)(this + 13488);
          v84 = *(_DWORD *)(this + 4);
          v96 = v27 * *(float *)(this + 13508) + v26 * *(float *)(this + 13504) + v25 * *(float *)(this + 13500);
          v80 = *(float *)(this + 13484);
          v97 = v27 * *(float *)(this + 13520) + v26 * *(float *)(this + 13516) + v25 * *(float *)(this + 13512);
          sub_4CE3E0(*(int **)(LODWORD(v101) + 84), (int)(v11 - 7), v80, (int)&v92, (float *)&v95, SLODWORD(v101), v84);
        }
        v12 += 248;
        v11 += 74;
        --v105;
      }
      while ( v105 );
      v89 = *(_DWORD *)(this + 14176);
      v28 = *(float *)(this + 13496) * *(float *)(this + 15344)
          + *(float *)(this + 13492) * *(float *)(this + 15340)
          + *(float *)(this + 13488) * *(float *)(this + 15336);
      v29 = *(float *)(this + 13500) * *(float *)(this + 15336)
          + *(float *)(this + 13508) * *(float *)(this + 15344)
          + *(float *)(this + 13504) * *(float *)(this + 15340);
      v104 = *(float *)(this + 13512) * *(float *)(this + 15336)
           + *(float *)(this + 13520) * *(float *)(this + 15344)
           + *(float *)(this + 13516) * *(float *)(this + 15340);
      *(float *)&v102 = v28 + *(float *)(this + 13524);
      v103 = v29 + *(float *)(this + 13528);
      v104 = v104 + *(float *)(this + 13532);
      sub_4EE230(this);
      if ( sub_4CE8F0((float *)(this + 1916)) )
      {
        v85 = *(_DWORD *)(this + 4);
        v81 = *(float *)(this + 13484);
        v30 = *(float *)(this + 13496) * *(float *)(this + 15708)
            + *(float *)(this + 13492) * *(float *)(this + 15704)
            + *(float *)(this + 15700) * *(float *)(this + 13488);
        v31 = *(float *)(this + 13508) * *(float *)(this + 15708)
            + *(float *)(this + 13504) * *(float *)(this + 15704)
            + *(float *)(this + 13500) * *(float *)(this + 15700);
        v94 = *(float *)(this + 13520) * *(float *)(this + 15708)
            + *(float *)(this + 13516) * *(float *)(this + 15704)
            + *(float *)(this + 13512) * *(float *)(this + 15700);
        *(float *)&v92 = v30 + *(float *)(this + 13524);
        v93 = v31 + *(float *)(this + 13528);
        v94 = v94 + *(float *)(this + 13532);
        v95 = *(int *)(this + 13548);
        v96 = *(float *)(this + 13552);
        v97 = *(float *)(this + 13556);
        sub_4CE930(&dword_8ACEA0, this + 1916, v81, (float *)&v92, (float *)&v95, v85);
      }
      if ( *(_BYTE *)(this + 4208) )
        sub_4E16F0((float *)(this + 1764), (float *)(this + 13488), (float *)(this + 13524), *(_DWORD *)(this + 13928));
      break;
    case 2:
    case 3:
      v32 = *(_DWORD *)(this + 4124);
      v112 = *(_DWORD *)(this + 4128);
      v113 = *(_DWORD *)(this + 4132);
      v33 = *(_DWORD *)(this + 4136);
      v34 = *(_WORD *)(this + 4140);
      v111 = v32;
      v114 = v33;
      v115 = v34;
      if ( v6 == 3 )
      {
        sub_4B9CE0(&dword_8AB6EC);
        v101 = v2;
        v116 = v2;
        v35 = *(float *)(this + 1848);
        qmemcpy(v110, (const void *)(this + 1796), sizeof(v110));
        v36 = *(float *)(this + 1852);
        v37 = *(float *)(this + 1856);
        v106 = v35;
        v107 = v36;
        v108 = v37;
      }
      else
      {
        v38 = *(int *)(this + 13484);
        qmemcpy(v110, (const void *)(this + 13488), sizeof(v110));
        v39 = *(float *)(this + 13524);
        v101 = *(float *)&v38;
        v40 = *(float *)(this + 13528);
        v41 = *(float *)(this + 13532);
        v106 = v39;
        v107 = v40;
        v108 = v41;
      }
      LODWORD(v42) = HIBYTE(v32);
      v120 = (unsigned __int8)v32;
      v43 = 0;
      v117 = v42;
      LODWORD(v118) = BYTE2(v111);
      LODWORD(v119) = BYTE1(v111);
      v105 = 0;
      v44 = this + 2012;
      v45 = (float *)(this + 13712);
      do
      {
        v91 = *(_DWORD *)(&v117 + v43) & 7;
        v46 = (double)((*((int *)&v117 + v43) >> 3) & 7) * 0.14285715;
        *(_DWORD *)(v44 + 16) = (*((int *)&v117 + v43) >> 3) & 0xFFFFFFF8;
        *(float *)(v44 - 8) = v46;
        v47 = (double)v91 * 0.14285715;
        *(float *)(v44 - 4) = v47;
        *(float *)(v44 + 4) = v46;
        *(float *)(v44 + 8) = v47;
        v48 = *(_DWORD *)(this + 12988);
        v49 = v110[2] * v45[1] + v110[0] * *(v45 - 1) + v110[1] * *v45;
        v50 = v110[3] * *(v45 - 1) + v110[5] * v45[1] + v110[4] * *v45;
        v94 = v110[6] * *(v45 - 1) + v110[8] * v45[1] + v110[7] * *v45;
        *(float *)&v92 = v106 + v49;
        v93 = v107 + v50;
        v94 = v108 + v94;
        if ( v48 == 2 )
        {
          v51 = sub_4ED750((float *)(this + 13572), v45 - 1, v124);
          v52 = *v51;
          v53 = v51[1];
          v54 = v51[2];
          v98 = v52;
          v55 = v52 + *(float *)(this + 13560);
          v99 = v53;
          v100 = v54;
          v56 = v53 + *(float *)(this + 13564);
          v57 = v54 + *(float *)(this + 13568);
          *(float *)&v95 = v110[2] * v57 + v110[1] * v56 + v55 * v110[0];
          v96 = v110[5] * v57 + v110[4] * v56 + v110[3] * v55;
          v97 = v110[8] * v57 + v110[7] * v56 + v110[6] * v55;
        }
        else
        {
          v58 = *(float *)(this + 80);
          v59 = *(float *)(this + 84);
          v95 = *(int *)(this + 76);
          v96 = v58;
          v97 = v59;
        }
        v125 = *(float *)&v92;
        v126 = v93;
        v127 = v94;
        v128 = 0x40000000;
        v129 = 1072902963;
        v130 = 0x40000000;
        v131 = 1201543096;
        v133 = v105;
        v60 = sub_44C4C0(dbl_7C9360, (int)&v125);
        v61 = v93 - v45[32];
        v105 = v60;
        v89 = v60;
        if ( v61 >= v132 )
        {
          *(_DWORD *)v44 = 0;
        }
        else
        {
          *(float *)v44 = v109;
          v88 = 1;
        }
        v62 = *(float *)v44;
        *(_DWORD *)(v44 + 12) = 0;
        if ( v62 > 0.0 )
        {
          *(_DWORD *)(v44 - 8) = 0;
          *(_DWORD *)(v44 + 4) = 0;
          *(_DWORD *)(v44 + 8) = 0;
        }
        if ( v60 )
          sub_4CE3E0(*(int **)(v60 + 84), v44 - 36, v101, (int)&v92, (float *)&v95, v60, *(_DWORD *)(this + 4));
        ++v43;
        v45 += 62;
        v44 += 296;
      }
      while ( v43 < 4 );
      v63 = v110[0] * *(float *)(this + 15336) + v110[1] * *(float *)(this + 15340) + v110[2] * *(float *)(this + 15344);
      v64 = v110[3] * *(float *)(this + 15336) + v110[4] * *(float *)(this + 15340) + v110[5] * *(float *)(this + 15344);
      v104 = v110[6] * *(float *)(this + 15336)
           + v110[7] * *(float *)(this + 15340)
           + v110[8] * *(float *)(this + 15344);
      *(float *)&v102 = v106 + v63;
      v103 = v107 + v64;
      v104 = v108 + v104;
      v65 = v110[2] * *(float *)(this + 15708) + v110[0] * *(float *)(this + 15700) + v110[1] * *(float *)(this + 15704);
      v66 = v110[5] * *(float *)(this + 15708) + v110[3] * *(float *)(this + 15700) + v110[4] * *(float *)(this + 15704);
      v94 = v110[8] * *(float *)(this + 15708) + v110[6] * *(float *)(this + 15700) + v110[7] * *(float *)(this + 15704);
      v67 = *(_DWORD *)(this + 12988);
      *(float *)&v92 = v106 + v65;
      v93 = v107 + v66;
      v94 = v108 + v94;
      if ( v67 == 2 )
      {
        v95 = *(int *)(this + 13548);
        v96 = *(float *)(this + 13552);
        v97 = *(float *)(this + 13556);
      }
      else
      {
        v95 = *(int *)(this + 76);
        v96 = *(float *)(this + 80);
        v97 = *(float *)(this + 84);
        v121 = v95;
        v122 = v96;
        v123 = v97;
      }
      v68 = BYTE2(v112);
      v86 = (BYTE2(v112) >> 2) & 7;
      v69 = *(_DWORD *)(this + 4);
      *(float *)(this + 1916) = (double)(BYTE2(v112) & 3) * 0.33333334;
      *(float *)(this + 1936) = (double)v86 * 0.14285715;
      v82 = v101;
      *(float *)(this + 1956) = (double)(v68 >> 5) * 0.14285715;
      sub_4CE930(&dword_8ACEA0, this + 1916, v82, (float *)&v92, (float *)&v95, v69);
      v87 = BYTE1(v112) & 0xF;
      v70 = v112;
      v71 = (unsigned __int8)v112 >> 4;
      *(float *)(this + 2252) = (double)((unsigned __int16)v112 >> 12) * 0.06666667;
      *(float *)(this + 2548) = (double)v87 * 0.06666667;
      v72 = v113 == 0;
      *(float *)(this + 2844) = (double)(v71 & 0xF) * 0.06666667;
      *(float *)(this + 3140) = (double)(v70 & 0xF) * 0.06666667;
      if ( !v72 )
      {
        v73 = (float *)dword_8ACEB8;
        v101 = *(float *)&dword_8ACEB8;
        if ( dword_8ACEB8 )
        {
          v74 = HIWORD(v114);
          v75 = 0;
          v76 = (float *)(this + 4216);
          do
          {
            if ( ((1 << v75) & v113) != 0 )
            {
              v98 = *v76;
              v77 = v76[1];
              v100 = v76[2];
              v99 = v77;
              v119 = v110[8] * v100 + v110[7] * v77 + v110[6] * v98;
              v117 = v110[2] * v100 + v110[1] * v77 + v98 * v110[0] + v106;
              v118 = v110[5] * v100 + v110[4] * v77 + v110[3] * v98 + v107;
              v119 = v119 + v108;
              v124[0] = (double)(__int16)v114 * 0.015625;
              v124[1] = (double)v74 * 0.015625;
              v124[2] = (double)v115 * 0.015625;
              sub_4CCE90(v73, &v117, HIBYTE(v112) >> 4, v124, HIBYTE(v112) & 0xF, v105);
              v73 = (float *)LODWORD(v101);
            }
            ++v75;
            v76 += 7;
          }
          while ( v75 < 17 );
        }
      }
      break;
    default:
      break;
  }
LABEL_64:
  if ( v109 > 0.0 && v88 )
  {
    v125 = *(float *)&v102;
    v126 = v103;
    v78 = v104;
    *(float *)(this + 3208) = v109;
    v127 = v78;
    *(_DWORD *)(this + 3188) = 0;
    *(_DWORD *)(this + 3192) = 0;
    *(_DWORD *)(this + 3196) = 0;
    *(_DWORD *)(this + 3200) = 0;
    *(_DWORD *)(this + 3204) = 0;
    v128 = 0x40000000;
    v129 = 1072902963;
    v130 = 0x40000000;
    v131 = 1201543096;
    v133 = v89;
    v79 = sub_44C4C0(dbl_7C9360, (int)&v125);
    if ( v79 )
      sub_4CE3E0(*(int **)(v79 + 84), this + 3160, v116, (int)&v102, (float *)&v121, v79, *(_DWORD *)(this + 4));
  }
}
