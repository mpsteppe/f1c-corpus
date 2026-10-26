int __usercall sub_5147EA@<eax>(float *a1@<eax>, int a2, int a3)
{
  int v4; // esi
  float *v5; // ecx
  int v6; // edi
  char v7; // dl
  char *v8; // esi
  char *v9; // edi
  float *v10; // eax
  unsigned int v11; // ecx
  double v12; // st7
  double v13; // st6
  double v14; // st5
  double v15; // st4
  bool v16; // zf
  unsigned int v17; // esi
  int v18; // eax
  unsigned int v19; // edi
  float *v20; // esi
  float *v21; // esi
  double v22; // st7
  double v23; // st6
  double v24; // st4
  double v25; // st5
  double v26; // st4
  double v27; // st7
  double v28; // st6
  double v29; // st5
  unsigned int v30; // edx
  _BYTE *v31; // esi
  char *v32; // edi
  float *v33; // ecx
  double v34; // st7
  int v35; // eax
  int v36; // ebx
  int v37; // eax
  double v38; // st7
  int v39; // ebx
  double v40; // st6
  float v42[4]; // [esp+0h] [ebp-270h]
  float v43; // [esp+10h] [ebp-260h] BYREF
  float v44; // [esp+14h] [ebp-25Ch] BYREF
  _BYTE v45[248]; // [esp+18h] [ebp-258h] BYREF
  float v46[64]; // [esp+110h] [ebp-160h] BYREF
  float v47; // [esp+210h] [ebp-60h] BYREF
  float v48; // [esp+214h] [ebp-5Ch]
  float v49; // [esp+218h] [ebp-58h]
  int v50; // [esp+220h] [ebp-50h]
  char *v51; // [esp+224h] [ebp-4Ch]
  char *v52; // [esp+228h] [ebp-48h]
  char *v53; // [esp+22Ch] [ebp-44h]
  char *v54; // [esp+230h] [ebp-40h]
  char *v55; // [esp+234h] [ebp-3Ch]
  char *v56; // [esp+238h] [ebp-38h]
  char *v57; // [esp+23Ch] [ebp-34h]
  char *v58; // [esp+240h] [ebp-30h]
  char *v59; // [esp+244h] [ebp-2Ch]
  float v60; // [esp+248h] [ebp-28h]
  float v61; // [esp+24Ch] [ebp-24h]
  float v62; // [esp+250h] [ebp-20h]
  float v63; // [esp+254h] [ebp-1Ch]
  float v64; // [esp+258h] [ebp-18h]
  float v65; // [esp+25Ch] [ebp-14h]
  float v66; // [esp+260h] [ebp-10h]
  float v67; // [esp+264h] [ebp-Ch]
  float v68; // [esp+268h] [ebp-8h]
  float v69; // [esp+26Ch] [ebp-4h]
  float v70; // [esp+270h] [ebp+0h]
  float v71; // [esp+274h] [ebp+4h]
  float v72; // [esp+278h] [ebp+8h]
  float v73; // [esp+27Ch] [ebp+Ch]
  float v74; // [esp+280h] [ebp+10h]
  float v75; // [esp+284h] [ebp+14h]
  int v76; // [esp+288h] [ebp+18h]
  char *v77; // [esp+28Ch] [ebp+1Ch]
  char *v78; // [esp+290h] [ebp+20h]
  char *v79; // [esp+294h] [ebp+24h]
  float v80; // [esp+298h] [ebp+28h] BYREF
  float v81; // [esp+29Ch] [ebp+2Ch]
  float v82; // [esp+2A0h] [ebp+30h]
  float v83; // [esp+2A4h] [ebp+34h]
  float v84; // [esp+2A8h] [ebp+38h] BYREF
  float v85; // [esp+2ACh] [ebp+3Ch]
  float v86; // [esp+2B0h] [ebp+40h]
  char *v87; // [esp+2B8h] [ebp+48h]
  float v88; // [esp+2BCh] [ebp+4Ch]
  float v89; // [esp+2C0h] [ebp+50h]
  float v90; // [esp+2C4h] [ebp+54h] BYREF
  float v91; // [esp+2C8h] [ebp+58h]
  float v92; // [esp+2CCh] [ebp+5Ch]
  float v93; // [esp+2D0h] [ebp+60h]
  int v94; // [esp+2D4h] [ebp+64h]
  int v95; // [esp+2D8h] [ebp+68h]
  float v96; // [esp+2DCh] [ebp+6Ch]
  char v97; // [esp+2ECh] [ebp+7Ch]
  float v98; // [esp+2ECh] [ebp+7Ch]
  unsigned int v99; // [esp+2ECh] [ebp+7Ch]

  if ( a3 )
  {
    v4 = 0;
    v5 = a1 + 3;
    v6 = 16;
    do
    {
      if ( *v5 < 0.5 )
        ++v4;
      v5 += 4;
      --v6;
    }
    while ( v6 );
    if ( v4 == 16 )
    {
      *(_WORD *)(a2 + 2) = -1;
      *(_DWORD *)(a2 + 4) = -1;
      *(_WORD *)a2 = 0;
      return 0;
    }
    v94 = 4 - (v4 != 0);
  }
  else
  {
    v94 = 4;
  }
  memset(v46, 0, sizeof(v46));
  FPUControlWordMerger();
  v77 = (char *)((char *)&v46[2] - (char *)a1);
  v53 = (char *)((char *)&v46[3] - (char *)a1);
  v51 = (char *)((char *)&v46[4] - (char *)a1);
  v76 = (char *)&v46[10] - (char *)a1;
  v54 = (char *)((char *)&v46[11] - (char *)a1);
  v56 = (char *)((char *)&v46[12] - (char *)a1);
  LODWORD(v88) = (char *)&v46[14] - (char *)a1;
  v52 = (char *)((char *)&v46[15] - (char *)a1);
  v58 = (char *)((char *)&v46[16] - (char *)a1);
  v87 = (char *)((char *)&v46[18] - (char *)a1);
  v59 = (char *)((char *)&v46[19] - (char *)a1);
  v97 = v7;
  v8 = (char *)((char *)v46 - (char *)a1);
  v55 = (char *)((char *)&v46[20] - (char *)a1);
  v9 = (char *)((char *)&v43 - (char *)a1);
  v10 = a1 + 2;
  v57 = (char *)((char *)v46 - (char *)a1);
  v11 = 0;
  while ( 1 )
  {
    v90 = v46[v11] + *(v10 - 2);
    v91 = *(v10 - 1) + v46[v11 + 1];
    v92 = *(float *)((char *)v10 + (_DWORD)v8) + *v10;
    v96 = v90 * 31.0 + 0.5;
    v50 = (int)v96;
    v89 = (double)v50 * 0.032258064;
    *(float *)((char *)&v43 + v11 * 4) = v89;
    v96 = v91 * 63.0 + 0.5;
    v79 = (char *)(int)v96;
    v96 = (double)(int)v79 * 0.015873017;
    *(float *)&v45[v11 * 4 - 4] = v96;
    *(float *)&v95 = v92 * 31.0 + 0.5;
    v78 = (char *)(int)*(float *)&v95;
    v12 = (double)(int)v78 * 0.032258064;
    v95 = v97 & 3;
    *(float *)((char *)v10 + (_DWORD)v9) = v12;
    *(float *)((char *)v10 + (char *)&v44 - (char *)a1) = 1.0;
    v13 = v90 - v89;
    v14 = v91 - v96;
    v85 = v14;
    v15 = v92 - v12;
    v86 = v15;
    if ( (v97 & 3) != 3 )
    {
      *(float *)&v77[(_DWORD)v10] = v13 * 0.4375 + *(float *)&v77[(_DWORD)v10];
      *(float *)&v53[(_DWORD)v10] = v14 * 0.4375 + *(float *)&v53[(_DWORD)v10];
      *(float *)&v51[(_DWORD)v10] = v15 * 0.4375 + *(float *)&v51[(_DWORD)v10];
    }
    if ( v11 < 48 )
    {
      if ( *(float *)&v95 != 0.0 )
      {
        *(float *)((char *)v10 + v76) = v13 * 0.1875 + *(float *)((char *)v10 + v76);
        *(float *)&v54[(_DWORD)v10] = v14 * 0.1875 + *(float *)&v54[(_DWORD)v10];
        *(float *)&v56[(_DWORD)v10] = v15 * 0.1875 + *(float *)&v56[(_DWORD)v10];
      }
      *(float *)((char *)v10 + LODWORD(v88)) = v13 * 0.3125 + *(float *)((char *)v10 + LODWORD(v88));
      *(float *)&v52[(_DWORD)v10] = v14 * 0.3125 + *(float *)&v52[(_DWORD)v10];
      v16 = v95 == 3;
      *(float *)&v58[(_DWORD)v10] = v15 * 0.3125 + *(float *)&v58[(_DWORD)v10];
      if ( !v16 )
      {
        *(float *)&v87[(_DWORD)v10] = v13 * 0.0625 + *(float *)&v87[(_DWORD)v10];
        *(float *)&v59[(_DWORD)v10] = v85 * 0.0625 + *(float *)&v59[(_DWORD)v10];
        *(float *)&v55[(_DWORD)v10] = v86 * 0.0625 + *(float *)&v55[(_DWORD)v10];
      }
    }
    ++v97;
    v11 += 4;
    v42[v11] = v89 * flt_5D79BC;
    v42[v11 + 1] = v96 * flt_5D79C0;
    *(float *)((char *)v10 + (_DWORD)v9) = v12 * flt_5D79C4;
    v10 += 4;
    if ( v11 >= 64 )
      break;
    v8 = v57;
  }
  OBBFittingAndProjection(&v80, &v90, (int)&v43, v94);
  v47 = v80 * flt_5D79CC;
  v48 = v81 * flt_5D79D0;
  v49 = v82 * flt_5D79D4;
  v84 = v90 * flt_5D79CC;
  v85 = v91 * flt_5D79D0;
  v86 = v92 * flt_5D79D4;
  *(float *)&v17 = COERCE_FLOAT(sub_513E80(&v47));
  v88 = *(float *)&v17;
  v18 = sub_513E80(&v84);
  v19 = v18;
  v87 = (char *)v18;
  if ( v94 == 4 && (_WORD)v17 == (_WORD)v18 )
  {
    *(_DWORD *)(a2 + 4) = 0;
    *(_WORD *)a2 = v17;
    *(_WORD *)(a2 + 2) = v18;
  }
  else
  {
    F_16BitColorToFloat4Decoder(&v47, v17);
    F_16BitColorToFloat4Decoder(&v84, v19);
    v80 = v47 * flt_5D79BC;
    v81 = v48 * flt_5D79C0;
    v82 = v49 * flt_5D79C4;
    v90 = v84 * flt_5D79BC;
    v91 = v85 * flt_5D79C0;
    v92 = v86 * flt_5D79C4;
    if ( (v94 == 3) == (unsigned __int16)v19 >= (unsigned __int16)v17 )
    {
      *(_WORD *)a2 = v17;
      *(_WORD *)(a2 + 2) = v19;
      v60 = v80;
      v61 = v81;
      v62 = v82;
      v63 = v83;
      v20 = &v90;
    }
    else
    {
      *(_WORD *)(a2 + 2) = v17;
      *(_WORD *)a2 = v19;
      v60 = v90;
      v61 = v91;
      v62 = v92;
      v63 = v93;
      v20 = &v80;
    }
    v64 = *v20;
    v21 = v20 + 1;
    v65 = *v21++;
    v66 = *v21;
    v67 = v21[1];
    v22 = v64 - v60;
    if ( v94 == 3 )
    {
      v89 = COERCE_FLOAT(&unk_5AF628);
      v68 = 0.5 * v22 + v60;
      v23 = v65 - v61;
      v69 = v23 * 0.5 + v61;
      v24 = v66 - v62;
      v98 = v24;
      v70 = v24 * 0.5 + v62;
      v71 = (v67 - v63) * 0.5 + v63;
    }
    else
    {
      v89 = COERCE_FLOAT(&unk_5AF618);
      v68 = 0.33333334 * v22 + v60;
      v23 = v65 - v61;
      v69 = 0.33333334 * v23 + v61;
      v25 = v66 - v62;
      v98 = v25;
      v70 = 0.33333334 * v25 + v62;
      v26 = v67 - v63;
      v71 = 0.33333334 * v26 + v63;
      v72 = v22 * 0.66666669 + v60;
      v73 = v23 * 0.66666669 + v61;
      v74 = v25 * 0.66666669 + v62;
      v75 = v26 * 0.66666669 + v63;
    }
    v90 = v22;
    v27 = v23;
    v28 = v98;
    v96 = (float)(unsigned int)(v94 - 1);
    if ( LOWORD(v88) == (_WORD)v87 )
      v29 = 0.0;
    else
      v29 = v96 / (v28 * v28 + v27 * v27 + v90 * v90);
    v90 = v90 * v29;
    memset(v46, 0, sizeof(v46));
    v91 = v29 * v27;
    v92 = v29 * v28;
    FPUControlWordMerger();
    *(float *)&v95 = COERCE_FLOAT(v46);
    v87 = (char *)((char *)&v46[1] - (char *)a1);
    v77 = (char *)((char *)&v46[5] - (char *)a1);
    v78 = (char *)((char *)&v46[13] - (char *)a1);
    v31 = (_BYTE *)(v45 - (_BYTE *)a1);
    v32 = (char *)((char *)&v46[17] - (char *)a1);
    v99 = v30;
    v33 = a1 + 1;
    v79 = (char *)((char *)&v46[21] - (char *)a1);
    do
    {
      if ( v94 == 3 && v33[2] < 0.5 )
      {
        v30 = (v30 >> 2) | 0xC0000000;
      }
      else
      {
        v80 = flt_5D79BC * *(v33 - 1) + *(float *)v95;
        v81 = flt_5D79C0 * *v33 + *(float *)&v57[(_DWORD)v33];
        v82 = flt_5D79C4 * v33[1] + *(float *)((char *)v33 + (_DWORD)v87);
        v34 = (v80 - v60) * v90 + (v82 - v62) * v92 + (v81 - v61) * v91;
        if ( v34 > 0.0 )
        {
          if ( v34 < v96 )
          {
            v88 = v34 + 0.5;
            v76 = (int)v88;
            v35 = *(_DWORD *)(LODWORD(v89) + 4 * v76);
          }
          else
          {
            v35 = 1;
          }
        }
        else
        {
          v35 = 0;
        }
        v36 = v35;
        v37 = 16 * v35;
        v30 = (v36 << 30) | (v30 >> 2);
        v38 = (v80 - *(float *)((char *)&v60 + v37)) * *(float *)((char *)v33 + (_DWORD)v31);
        v39 = v99 & 3;
        v40 = (v81 - *(float *)((char *)&v61 + v37)) * *(float *)((char *)v33 + (_DWORD)v31);
        v85 = v40;
        v86 = (v82 - *(float *)((char *)&v62 + v37)) * *(float *)((char *)v33 + (_DWORD)v31);
        if ( v39 != 3 )
        {
          *(float *)&v53[(_DWORD)v33] = v38 * 0.4375 + *(float *)&v53[(_DWORD)v33];
          *(float *)&v51[(_DWORD)v33] = 0.4375 * v40 + *(float *)&v51[(_DWORD)v33];
          *(float *)&v77[(_DWORD)v33] = v86 * 0.4375 + *(float *)&v77[(_DWORD)v33];
        }
        if ( v99 < 0xC )
        {
          if ( (v99 & 3) != 0 )
          {
            *(float *)&v54[(_DWORD)v33] = v38 * 0.1875 + *(float *)&v54[(_DWORD)v33];
            *(float *)&v56[(_DWORD)v33] = 0.1875 * v40 + *(float *)&v56[(_DWORD)v33];
            *(float *)&v78[(_DWORD)v33] = v86 * 0.1875 + *(float *)&v78[(_DWORD)v33];
          }
          *(float *)&v52[(_DWORD)v33] = v38 * 0.3125 + *(float *)&v52[(_DWORD)v33];
          *(float *)&v58[(_DWORD)v33] = v40 * 0.3125 + *(float *)&v58[(_DWORD)v33];
          *(float *)((char *)v33 + (_DWORD)v32) = v86 * 0.3125 + *(float *)((char *)v33 + (_DWORD)v32);
          if ( v39 != 3 )
          {
            *(float *)&v59[(_DWORD)v33] = v38 * 0.0625 + *(float *)&v59[(_DWORD)v33];
            *(float *)&v55[(_DWORD)v33] = v85 * 0.0625 + *(float *)&v55[(_DWORD)v33];
            *(float *)&v79[(_DWORD)v33] = v86 * 0.0625 + *(float *)&v79[(_DWORD)v33];
          }
        }
      }
      ++v99;
      v95 += 16;
      v33 += 4;
    }
    while ( v99 < 0x10 );
    *(_DWORD *)(a2 + 4) = v30;
  }
  return 0;
}
