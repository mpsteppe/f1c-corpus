int __thiscall sub_4EA970(int this)
{
  int v2; // edi
  float *v3; // ebx
  int result; // eax
  char *v5; // eax
  double v6; // st7
  double v7; // st6
  char *v8; // ebp
  double v9; // st5
  float *v10; // edi
  double v11; // st7
  double v12; // st6
  float v13; // edx
  float v14; // ecx
  double v15; // st7
  double v16; // st6
  float *v17; // ebx
  int v18; // ecx
  int v19; // eax
  float *v20; // ecx
  double v21; // st7
  double v22; // st6
  double v23; // st7
  double v24; // st6
  double v25; // st7
  double v26; // st6
  double v27; // st5
  double v28; // st6
  unsigned __int8 v30; // c0
  unsigned __int8 v31; // c3
  double v32; // st4
  double v33; // st6
  double v34; // st6
  float *v35; // eax
  double v36; // st7
  double v37; // st7
  long double v38; // st7
  long double v39; // st7
  long double v40; // st4
  double v41; // st7
  double v42; // st6
  int v43; // ecx
  int v44; // eax
  double v45; // st7
  double v46; // st7
  double v47; // st6
  double v48; // st7
  double v49; // st6
  double v50; // st7
  int v51; // eax
  int v52; // eax
  double v53; // st7
  double v54; // st6
  double v55; // st5
  double v56; // st4
  float v57; // edx
  double v58; // rt2
  double v59; // st4
  double v60; // st5
  double v61; // st7
  double v62; // st6
  double v63; // st7
  double v64; // st6
  long double v65; // st5
  long double v66; // st5
  double v67; // st4
  int v68; // [esp+14h] [ebp-194h]
  float v69; // [esp+14h] [ebp-194h]
  float *v70; // [esp+18h] [ebp-190h]
  float v71; // [esp+18h] [ebp-190h]
  float v72; // [esp+1Ch] [ebp-18Ch] BYREF
  float v73; // [esp+20h] [ebp-188h]
  float v74; // [esp+24h] [ebp-184h]
  float v75; // [esp+28h] [ebp-180h] BYREF
  int v76; // [esp+2Ch] [ebp-17Ch] BYREF
  float v77; // [esp+30h] [ebp-178h] BYREF
  float *v78; // [esp+34h] [ebp-174h]
  float v79; // [esp+38h] [ebp-170h]
  float v80; // [esp+3Ch] [ebp-16Ch]
  float v81; // [esp+40h] [ebp-168h]
  unsigned int v82; // [esp+44h] [ebp-164h]
  int v83; // [esp+48h] [ebp-160h]
  float *v84; // [esp+4Ch] [ebp-15Ch]
  float v85; // [esp+50h] [ebp-158h]
  float v86; // [esp+54h] [ebp-154h]
  float v87; // [esp+58h] [ebp-150h]
  float v88; // [esp+5Ch] [ebp-14Ch]
  float v89; // [esp+60h] [ebp-148h]
  float v90; // [esp+64h] [ebp-144h]
  float v91; // [esp+68h] [ebp-140h]
  float v92; // [esp+6Ch] [ebp-13Ch]
  float v93; // [esp+74h] [ebp-134h]
  float v94; // [esp+78h] [ebp-130h]
  float v95; // [esp+7Ch] [ebp-12Ch]
  float v96; // [esp+80h] [ebp-128h]
  float v97; // [esp+84h] [ebp-124h]
  float v98; // [esp+88h] [ebp-120h]
  float v99; // [esp+8Ch] [ebp-11Ch]
  float v100; // [esp+90h] [ebp-118h] BYREF
  float v101; // [esp+94h] [ebp-114h]
  float v102; // [esp+98h] [ebp-110h]
  float v103; // [esp+9Ch] [ebp-10Ch]
  float v104; // [esp+A0h] [ebp-108h] BYREF
  float v105; // [esp+A4h] [ebp-104h]
  float v106; // [esp+A8h] [ebp-100h]
  float v107; // [esp+ACh] [ebp-FCh]
  float v108[4]; // [esp+B0h] [ebp-F8h] BYREF
  float v109; // [esp+C0h] [ebp-E8h]
  float v110; // [esp+C4h] [ebp-E4h]
  float v111; // [esp+CCh] [ebp-DCh]
  float v112; // [esp+D0h] [ebp-D8h]
  float v113; // [esp+D8h] [ebp-D0h]
  float v114; // [esp+E4h] [ebp-C4h]
  float v115; // [esp+E8h] [ebp-C0h]
  float v116; // [esp+F4h] [ebp-B4h]
  double v117; // [esp+F8h] [ebp-B0h] BYREF
  double v118[2]; // [esp+100h] [ebp-A8h] BYREF
  float v119; // [esp+110h] [ebp-98h]
  double v120[3]; // [esp+114h] [ebp-94h] BYREF
  float v121; // [esp+12Ch] [ebp-7Ch]
  double v122[3]; // [esp+138h] [ebp-70h] BYREF
  double v123[3]; // [esp+150h] [ebp-58h] BYREF
  _BYTE v124[8]; // [esp+168h] [ebp-40h] BYREF
  int v125; // [esp+170h] [ebp-38h]
  int v126; // [esp+178h] [ebp-30h]
  float v127; // [esp+18Ch] [ebp-1Ch]
  float v128; // [esp+190h] [ebp-18h]
  float v129; // [esp+194h] [ebp-14h]
  float v130; // [esp+198h] [ebp-10h]
  float v131; // [esp+19Ch] [ebp-Ch]
  float v132; // [esp+1A0h] [ebp-8h]

  v2 = 0;
  v3 = (float *)(this + 15036);
  v82 = 0;
  v78 = (float *)(this + 13712);
  v84 = (float *)(this + 15036);
  do
  {
    result = NetworkPacketDataReader(v2, v124);
    if ( !result )
      goto LABEL_64;
    if ( v2 >= 10 && v2 < 12 && *(_BYTE *)(this + 15220) && (!*(_DWORD *)(this + 3340) || !*(_BYTE *)(this + 3404)) )
    {
      result = BufferEntryClear(v2);
      goto LABEL_64;
    }
    v5 = ArithmeticComparison_a010();
    v6 = v130;
    v7 = v131;
    v8 = v5;
    v9 = v132;
    *(_DWORD *)v5 = v2;
    v116 = v9;
    v10 = (float *)(v5 + 20);
    *((float *)v5 + 5) = *(float *)(this + 13496) * v3[1]
                       + *(float *)(this + 13492) * *v3
                       + *(v3 - 1) * *(float *)(this + 13488);
    *((float *)v5 + 6) = *(float *)(this + 13508) * v3[1]
                       + *(float *)(this + 13504) * *v3
                       + *(float *)(this + 13500) * *(v3 - 1);
    *((float *)v5 + 7) = *(float *)(this + 13520) * v3[1]
                       + *(float *)(this + 13516) * *v3
                       + *(float *)(this + 13512) * *(v3 - 1);
    *((float *)v5 + 5) = *(float *)(this + 13524) + *((float *)v5 + 5);
    *((float *)v5 + 6) = *(float *)(this + 13528) + *((float *)v5 + 6);
    *((float *)v5 + 7) = *(float *)(this + 13532) + *((float *)v5 + 7);
    v86 = v6 - *((float *)v5 + 5);
    v87 = v7 - *((float *)v5 + 6);
    v88 = v116 - *((float *)v5 + 7);
    v121 = v6 + *((float *)v5 + 5);
    v11 = v7 + *((float *)v5 + 6);
    v12 = v116 + *((float *)v5 + 7);
    v94 = v121 * 0.5;
    v95 = v11 * 0.5;
    v96 = v12 * 0.5;
    v13 = v95;
    *((float *)v5 + 5) = v94;
    v14 = v96;
    *((float *)v5 + 6) = v13;
    *((float *)v5 + 7) = v14;
    v15 = v129;
    v16 = v128;
    v17 = (float *)(v5 + 44);
    v18 = 0;
    *((float *)v5 + 11) = v127;
    v85 = 0.25;
    *((float *)v5 + 12) = v16;
    *((float *)v5 + 13) = v15;
    *((float *)v5 + 2) = v88 * *((float *)v5 + 13) + v87 * *((float *)v5 + 12) + v86 * *((float *)v5 + 11);
    v83 = dword_5C329C;
    if ( dword_5C329C <= 0 )
      goto LABEL_12;
    while ( v125 != *(_DWORD *)(dword_7C54F0[v18] + 1780) )
    {
      if ( ++v18 >= dword_5C329C )
        goto LABEL_12;
    }
    v68 = v18;
    v83 = v18;
    if ( v82 < 4 )
    {
      v20 = (float *)(dword_7C54F0[v18] + 12);
      v70 = v20 + 3428;
      v21 = *(float *)(this + 13496) * v78[1] + *(float *)(this + 13492) * *v78;
      v22 = *(float *)(this + 13488);
      v76 = 4;
      v23 = v21 + v22 * *(v78 - 1);
      v24 = *(float *)(this + 13508) * v78[1] + *(float *)(this + 13504) * *v78 + *(float *)(this + 13500) * *(v78 - 1);
      v93 = *(float *)(this + 13520) * v78[1] + *(float *)(this + 13516) * *v78 + *(float *)(this + 13512) * *(v78 - 1);
      v92 = v23 + *(float *)(this + 13524);
      v25 = v24 + *(float *)(this + 13528);
      v93 = v93 + *(float *)(this + 13532);
      do
      {
        v26 = v20[3373] * *v70 + v20[3372] * *(v70 - 1) + v20[3374] * v70[1];
        v27 = v20[3376] * *v70 + v20[3375] * *(v70 - 1) + v20[3377] * v70[1];
        v91 = v20[3380] * v70[1] + v20[3379] * *v70 + v20[3378] * *(v70 - 1);
        v89 = v26 + v20[3381];
        v90 = v27 + v20[3382];
        v28 = v91 + v20[3383];
        if ( !(v30 | v31) )
        {
          v85 = 0.34999999;
          v32 = v28;
          v33 = v90 + v25;
          v119 = v32 + v93;
          v97 = (v89 + v92) * 0.5;
          *v10 = v97;
          v98 = v33 * 0.5;
          v34 = v119;
          *((float *)v5 + 6) = v98;
          v99 = v34 * 0.5;
          *((float *)v5 + 7) = v99;
        }
        v70 += 62;
        --v76;
      }
      while ( v76 );
      v18 = v68;
    }
    if ( v18 >= dword_5C329C )
    {
LABEL_12:
      v19 = ArrayOfStructLinearSearchByID(dword_5EA560, v125);
      if ( v19 )
      {
        *((_DWORD *)v8 + 3) = 2;
        *((_DWORD *)v8 + 4) = v19;
        goto LABEL_30;
      }
      *((_DWORD *)v8 + 3) = 9;
      v76 = 0;
      if ( v126 )
        ArithmeticComparison_7390(&v76, 4096);
      v43 = v76;
    }
    else
    {
      v35 = (float *)dword_7C54F0[v18];
      v36 = *(float *)(this + 13524) - v35[3384];
      v35 += 3384;
      v79 = v36;
      v80 = *(float *)(this + 13528) - v35[1];
      v37 = *(float *)(this + 13532) - v35[2];
      v81 = v37;
      v38 = sqrt(v37 * v81 + v80 * v80 + v79 * v79);
      if ( v38 > 0.0 )
      {
        v39 = 6.0 / v38;
        v109 = v39 * v80;
        v110 = v39 * v81;
        *v17 = v79 * v39 + *v17;
        v17[1] = v109 + v17[1];
        v17[2] = v110 + v17[2];
        v40 = sqrt(*v17 * *v17 + v17[1] * v17[1] + v17[2] * v17[2]);
        if ( v40 <= 0.0 )
        {
          *v17 = v79;
          v17[1] = v80;
          v17[2] = v81;
        }
        else
        {
          *v17 = 1.0 / v40 * *v17;
          v17[1] = 1.0 / v40 * v17[1];
          v17[2] = 1.0 / v40 * v17[2];
        }
      }
      v41 = v88 * v17[2] + v87 * v17[1];
      v42 = v86 * *v17;
      *((_DWORD *)v8 + 3) = 6;
      *((float *)v8 + 2) = v41 + v42;
      v43 = dword_5EA570 + 36 * *(_DWORD *)(dword_7C54F0[v18] + 16);
    }
    *((_DWORD *)v8 + 4) = v43;
LABEL_30:
    VehicleGeometryProximityTest(v10, v17, &v75, &v77, &v72);
    v44 = *((_DWORD *)v8 + 3);
    if ( v44 == 6 )
    {
      VehicleGeometryProximityTest(v10, v17, &v104, &v100, v108);
      v75 = v75 - v104;
      v77 = v100 + v77;
      v72 = v72 - v108[0];
      v73 = v73 - v108[1];
      v45 = v74 - v108[2];
LABEL_34:
      v74 = v45;
      goto LABEL_35;
    }
    if ( v44 == 2 )
    {
      v120[0] = *v10;
      v120[1] = *((float *)v8 + 6);
      v120[2] = *((float *)v8 + 7);
      v123[0] = *v17;
      v123[1] = *((float *)v8 + 12);
      v123[2] = *((float *)v8 + 13);
      VehicleProjectedPosition(v120, v123, v118, &v117, v122);
      v75 = v75 - v118[0];
      v77 = v117 + v77;
      v45 = v74 - v122[2];
      v72 = v72 - v122[0];
      v73 = v73 - v122[1];
      goto LABEL_34;
    }
LABEL_35:
    if ( v75 < 0.0 )
    {
      v46 = -1.0 / v75;
    }
    else
    {
      v46 = 0.0;
      v75 = 0.0;
    }
    v71 = -(v75 / v77);
    v69 = sqrt(v72 * v72 + v73 * v73 + v74 * v74);
    if ( v69 <= 8.0 )
      v47 = v69;
    else
      v47 = 8.0;
    if ( v47 * v46 <= 1.0 )
    {
      if ( v69 <= 8.0 )
        v49 = v69;
      else
        v49 = 8.0;
      v48 = v46 * v49;
    }
    else
    {
      v48 = 1.0;
    }
    if ( v69 > v48 )
    {
      v50 = v48 / v69;
      v72 = v72 * v50;
      v73 = v73 * v50;
      v74 = v50 * v74;
    }
    v51 = *((_DWORD *)v8 + 3);
    if ( v51 == 6 || v51 == 9 && (v52 = *((_DWORD *)v8 + 4)) != 0 && *(_BYTE *)(v52 + 44) )
    {
      v53 = v69 * 0.0078125 + v71 * 0.00048828125 - 0.1;
      if ( v53 > 0.0 )
      {
        if ( v53 > 1.0 )
          v53 = 1.0;
        if ( v53 > *(float *)(this + 164) )
        {
          v54 = *v10 - *(float *)(this + 13524);
          v55 = v10[1] - *(float *)(this + 13528);
          v56 = v10[2] - *(float *)(this + 13532);
          v101 = v56 * *(float *)(this + 13512) + v55 * *(float *)(this + 13500) + v54 * *(float *)(this + 13488);
          v102 = v56 * *(float *)(this + 13516) + v55 * *(float *)(this + 13504) + v54 * *(float *)(this + 13492);
          v57 = v102;
          v58 = v56 * *(float *)(this + 13520);
          v59 = v55 * *(float *)(this + 13508);
          v60 = v54 * *(float *)(this + 13496);
          *(float *)(this + 172) = v101;
          *(float *)(this + 176) = v57;
          v103 = v58 + v59 + v60;
          *(float *)(this + 180) = v103;
          *(float *)(this + 164) = v53;
          *(float *)(this + 168) = v69 * 0.00390625 + 0.875;
        }
      }
    }
    v61 = v71 * v85;
    v114 = v61 * v73;
    v115 = v61 * v74;
    v62 = v71 * *v17;
    v111 = v71 * v17[1];
    v112 = v71 * v17[2];
    v63 = v62 - v72 * v61;
    v113 = v111 - v114;
    v64 = v112 - v115;
    v65 = sqrt(v64 * v64 + v113 * v113 + v63 * v63);
    *((float *)v8 + 1) = v65;
    if ( v65 <= 0.0 )
    {
      *((_DWORD *)v8 + 8) = 0;
      *((_DWORD *)v8 + 9) = 0;
      *((_DWORD *)v8 + 10) = 0;
    }
    else
    {
      v66 = 1.0 / v65;
      v105 = v66 * v63;
      v67 = v113;
      *((float *)v8 + 8) = v105;
      v106 = v67 * v66;
      *((float *)v8 + 9) = v106;
      v107 = v66 * v64;
      *((float *)v8 + 10) = v107;
    }
    if ( v83 < dword_5C329C )
      sub_41AD80((float *)dword_5EB978, *(_DWORD *)this, dword_7C54F0[v83], *((float *)v8 + 1));
    result = BufferEntryClear(v82);
    v3 = v84;
    v2 = v82;
LABEL_64:
    ++v2;
    v3 += 3;
    v82 = v2;
    v84 = v3;
    v78 += 62;
  }
  while ( v2 < 13 );
  return result;
}
