int __userpurge sub_67D6C7@<eax>(float *a1@<eax>, int a2, int a3, int a4)
{
  int v5; // edx
  float *v6; // ecx
  int v7; // edi
  char *v8; // edx
  char *v9; // edi
  float *v10; // eax
  unsigned int v11; // ecx
  double v12; // st7
  double v13; // st6
  double v14; // st5
  double v15; // st4
  bool v16; // zf
  float v17; // esi
  unsigned int v18; // esi
  int v19; // eax
  unsigned int v20; // edi
  float *v21; // esi
  float *v22; // esi
  double v23; // st7
  double v24; // st6
  double v25; // st4
  double v26; // st5
  double v27; // st4
  double v28; // st7
  double v29; // st6
  double v30; // st5
  char *v31; // esi
  _BYTE *v32; // edx
  float *v33; // ecx
  double v34; // st7
  int v35; // eax
  int v36; // eax
  int v37; // esi
  double v38; // st7
  double v39; // st6
  float v41[4]; // [esp+0h] [ebp-2ECh]
  float v42; // [esp+10h] [ebp-2DCh] BYREF
  float v43; // [esp+14h] [ebp-2D8h] BYREF
  _BYTE v44[248]; // [esp+18h] [ebp-2D4h] BYREF
  float v45[64]; // [esp+110h] [ebp-1DCh] BYREF
  char *v46; // [esp+210h] [ebp-DCh]
  float v47; // [esp+214h] [ebp-D8h] BYREF
  float v48; // [esp+218h] [ebp-D4h]
  float v49; // [esp+21Ch] [ebp-D0h]
  int v50; // [esp+224h] [ebp-C8h]
  char *v51; // [esp+228h] [ebp-C4h]
  int v52; // [esp+22Ch] [ebp-C0h]
  char *v53; // [esp+230h] [ebp-BCh]
  char *v54; // [esp+234h] [ebp-B8h]
  char *v55; // [esp+238h] [ebp-B4h]
  char *v56; // [esp+23Ch] [ebp-B0h]
  char *v57; // [esp+240h] [ebp-ACh]
  char *v58; // [esp+244h] [ebp-A8h]
  float v59; // [esp+248h] [ebp-A4h]
  float v60; // [esp+24Ch] [ebp-A0h]
  float v61; // [esp+250h] [ebp-9Ch]
  float v62; // [esp+254h] [ebp-98h]
  float v63; // [esp+258h] [ebp-94h]
  float v64; // [esp+25Ch] [ebp-90h]
  float v65; // [esp+260h] [ebp-8Ch]
  float v66; // [esp+264h] [ebp-88h]
  float v67; // [esp+268h] [ebp-84h]
  float v68; // [esp+26Ch] [ebp-80h]
  float v69; // [esp+270h] [ebp-7Ch]
  float v70; // [esp+274h] [ebp-78h]
  float v71; // [esp+278h] [ebp-74h]
  float v72; // [esp+27Ch] [ebp-70h]
  float v73; // [esp+280h] [ebp-6Ch]
  float v74; // [esp+284h] [ebp-68h]
  char *v75; // [esp+288h] [ebp-64h]
  char *v76; // [esp+28Ch] [ebp-60h]
  int v77; // [esp+290h] [ebp-5Ch]
  int v78; // [esp+294h] [ebp-58h]
  char *v79; // [esp+298h] [ebp-54h]
  float v80; // [esp+29Ch] [ebp-50h] BYREF
  float v81; // [esp+2A0h] [ebp-4Ch]
  float v82; // [esp+2A4h] [ebp-48h]
  float v83; // [esp+2A8h] [ebp-44h]
  float v84; // [esp+2ACh] [ebp-40h] BYREF
  float v85; // [esp+2B0h] [ebp-3Ch]
  float v86; // [esp+2B4h] [ebp-38h]
  char *v87; // [esp+2BCh] [ebp-30h]
  float v88; // [esp+2C0h] [ebp-2Ch]
  float v89; // [esp+2C4h] [ebp-28h]
  int v90; // [esp+2C8h] [ebp-24h]
  char *v91; // [esp+2CCh] [ebp-20h]
  float v92; // [esp+2D0h] [ebp-1Ch]
  float v93; // [esp+2D4h] [ebp-18h] BYREF
  float v94; // [esp+2D8h] [ebp-14h]
  float v95; // [esp+2DCh] [ebp-10h]
  float v96; // [esp+2E0h] [ebp-Ch]
  int v97; // [esp+2E4h] [ebp-8h]
  float v98; // [esp+2E8h] [ebp-4h]
  char v99; // [esp+2F8h] [ebp+Ch]
  float v100; // [esp+2F8h] [ebp+Ch]
  unsigned int v101; // [esp+2F8h] [ebp+Ch]

  if ( a3 )
  {
    v5 = 0;
    v6 = a1 + 3;
    v7 = 16;
    do
    {
      if ( *v6 < 0.5 )
        ++v5;
      v6 += 4;
      --v7;
    }
    while ( v7 );
    if ( v5 == 16 )
    {
      *(_WORD *)(a2 + 2) = -1;
      *(_DWORD *)(a2 + 4) = -1;
      *(_WORD *)a2 = 0;
      return 0;
    }
    v90 = 4 - (v5 != 0);
  }
  else
  {
    v90 = 4;
  }
  if ( a4 )
    memset(v45, 0, sizeof(v45));
  v55 = (char *)((char *)v45 - (char *)a1);
  v76 = (char *)((char *)&v43 - (char *)a1);
  v79 = (char *)((char *)&v45[2] - (char *)a1);
  v53 = (char *)((char *)&v45[3] - (char *)a1);
  v56 = (char *)((char *)&v45[4] - (char *)a1);
  v77 = (char *)&v45[10] - (char *)a1;
  v54 = (char *)((char *)&v45[11] - (char *)a1);
  v57 = (char *)((char *)&v45[12] - (char *)a1);
  LODWORD(v89) = (char *)&v45[14] - (char *)a1;
  v91 = (char *)((char *)&v45[18] - (char *)a1);
  v58 = (char *)((char *)&v45[19] - (char *)a1);
  v87 = (char *)((char *)&v45[20] - (char *)a1);
  v8 = (char *)((char *)&v45[15] - (char *)a1);
  v9 = (char *)((char *)&v45[16] - (char *)a1);
  v78 = a3;
  LODWORD(v88) = (char *)&v42 - (char *)a1;
  v99 = 0;
  v10 = a1 + 2;
  v46 = (char *)((char *)&v45[15] - (char *)a1);
  v51 = (char *)((char *)&v45[16] - (char *)a1);
  v11 = 0;
  do
  {
    v93 = *(v10 - 2);
    v94 = *(v10 - 1);
    v95 = *v10;
    if ( a4 )
    {
      v93 = v93 + v45[v11];
      v94 = v94 + v45[v11 + 1];
      v95 = v95 + *(float *)((char *)v10 + (_DWORD)v55);
    }
    v98 = v93 * 31.0 + 0.5;
    v50 = (int)v98;
    v92 = (double)v50 * 0.032258064;
    *(float *)((char *)&v42 + v11 * 4) = v92;
    v98 = v94 * 63.0 + 0.5;
    v52 = (int)v98;
    v98 = (double)v52 * 0.015873017;
    *(float *)&v44[v11 * 4 - 4] = v98;
    *(float *)&v97 = v95 * 31.0 + 0.5;
    v75 = (char *)(int)*(float *)&v97;
    v97 = (int)v75;
    v12 = (double)(int)v75 * 0.032258064;
    *(float *)((char *)v10 + LODWORD(v88)) = v12;
    *(float *)((char *)v10 + (_DWORD)v76) = 1.0;
    if ( a4 )
    {
      v13 = v93 - v92;
      v14 = v94 - v98;
      v97 = v99 & 3;
      v85 = v14;
      v15 = v95 - v12;
      v86 = v15;
      if ( v97 != 3 )
      {
        *(float *)&v79[(_DWORD)v10] = v13 * 0.4375 + *(float *)&v79[(_DWORD)v10];
        *(float *)&v53[(_DWORD)v10] = v14 * 0.4375 + *(float *)&v53[(_DWORD)v10];
        *(float *)&v56[(_DWORD)v10] = v15 * 0.4375 + *(float *)&v56[(_DWORD)v10];
      }
      if ( v11 < 48 )
      {
        if ( *(float *)&v97 != 0.0 )
        {
          *(float *)((char *)v10 + v77) = v13 * 0.1875 + *(float *)((char *)v10 + v77);
          *(float *)&v54[(_DWORD)v10] = v14 * 0.1875 + *(float *)&v54[(_DWORD)v10];
          *(float *)&v57[(_DWORD)v10] = v15 * 0.1875 + *(float *)&v57[(_DWORD)v10];
        }
        v16 = v97 == 3;
        *(float *)((char *)v10 + LODWORD(v89)) = v13 * 0.3125 + *(float *)((char *)v10 + LODWORD(v89));
        *(float *)((char *)v10 + (_DWORD)v8) = v14 * 0.3125 + *(float *)((char *)v10 + (_DWORD)v8);
        *(float *)((char *)v10 + (_DWORD)v9) = v15 * 0.3125 + *(float *)((char *)v10 + (_DWORD)v9);
        if ( !v16 )
        {
          *(float *)&v91[(_DWORD)v10] = v13 * 0.0625 + *(float *)&v91[(_DWORD)v10];
          *(float *)&v58[(_DWORD)v10] = v85 * 0.0625 + *(float *)&v58[(_DWORD)v10];
          *(float *)&v87[(_DWORD)v10] = v86 * 0.0625 + *(float *)&v87[(_DWORD)v10];
        }
      }
    }
    v17 = v88;
    ++v99;
    v11 += 4;
    v41[v11] = v92 * flt_915650;
    v41[v11 + 1] = v98 * flt_915654;
    *(float *)((char *)v10 + LODWORD(v17)) = v12 * flt_915658;
    v10 += 4;
  }
  while ( v11 < 64 );
  sub_67D147(&v93, &v80, (int)&v42, v90);
  v47 = v93 * flt_915660;
  v48 = v94 * flt_915664;
  v49 = v95 * flt_915668;
  v84 = v80 * flt_915660;
  v85 = v81 * flt_915664;
  v86 = v82 * flt_915668;
  *(float *)&v18 = COERCE_FLOAT(sub_67CD1D(&v47));
  v89 = *(float *)&v18;
  v19 = sub_67CD1D(&v84);
  v20 = v19;
  v91 = (char *)v19;
  if ( v90 == 4 && (_WORD)v18 == (_WORD)v19 )
  {
    *(_DWORD *)(a2 + 4) = 0;
    *(_WORD *)a2 = v18;
    *(_WORD *)(a2 + 2) = v19;
  }
  else
  {
    sub_67CC1B(&v47, v18);
    sub_67CC1B(&v84, v20);
    v93 = v47 * flt_915650;
    v94 = v48 * flt_915654;
    v95 = v49 * flt_915658;
    v80 = v84 * flt_915650;
    v81 = v85 * flt_915654;
    v82 = v86 * flt_915658;
    if ( (v90 == 3) == (unsigned __int16)v20 >= (unsigned __int16)v18 )
    {
      *(_WORD *)a2 = v18;
      *(_WORD *)(a2 + 2) = v20;
      v59 = v93;
      v60 = v94;
      v61 = v95;
      v62 = v96;
      v21 = &v80;
    }
    else
    {
      *(_WORD *)(a2 + 2) = v18;
      *(_WORD *)a2 = v20;
      v59 = v80;
      v60 = v81;
      v61 = v82;
      v62 = v83;
      v21 = &v93;
    }
    v63 = *v21;
    v22 = v21 + 1;
    v64 = *v22++;
    v65 = *v22;
    v66 = v22[1];
    v23 = v63 - v59;
    if ( v90 == 3 )
    {
      v98 = COERCE_FLOAT(&unk_73CD8C);
      v67 = 0.5 * v23 + v59;
      v24 = v64 - v60;
      v68 = v24 * 0.5 + v60;
      v25 = v65 - v61;
      v100 = v25;
      v69 = v25 * 0.5 + v61;
      v70 = (v66 - v62) * 0.5 + v62;
    }
    else
    {
      v98 = COERCE_FLOAT(&unk_73CD7C);
      v67 = 0.33333334 * v23 + v59;
      v24 = v64 - v60;
      v68 = 0.33333334 * v24 + v60;
      v26 = v65 - v61;
      v100 = v26;
      v69 = 0.33333334 * v26 + v61;
      v27 = v66 - v62;
      v70 = 0.33333334 * v27 + v62;
      v71 = v23 * 0.66666669 + v59;
      v72 = v24 * 0.66666669 + v60;
      v73 = v26 * 0.66666669 + v61;
      v74 = v27 * 0.66666669 + v62;
    }
    v80 = v23;
    v28 = v24;
    v29 = v100;
    v88 = (float)(unsigned int)(v90 - 1);
    if ( LOWORD(v89) == (_WORD)v91 )
      v30 = 0.0;
    else
      v30 = v88 / (v29 * v29 + v28 * v28 + v80 * v80);
    v92 = 0.0;
    v80 = v80 * v30;
    v81 = v30 * v28;
    v82 = v30 * v29;
    if ( a4 )
      memset(v45, 0, sizeof(v45));
    v78 = v90 - 1;
    *(float *)&v97 = COERCE_FLOAT(v45);
    v79 = (char *)((char *)&v45[5] - (char *)a1);
    v101 = 0;
    v76 = (char *)((char *)&v45[13] - (char *)a1);
    v31 = (char *)((char *)&v45[1] - (char *)a1);
    v32 = (_BYTE *)(v44 - (_BYTE *)a1);
    v33 = a1 + 1;
    v91 = (char *)((char *)&v45[1] - (char *)a1);
    v75 = (char *)((char *)&v45[21] - (char *)a1);
    while ( 1 )
    {
      if ( v90 == 3 && v33[2] < 0.5 )
      {
        LODWORD(v92) = (LODWORD(v92) >> 2) | 0xC0000000;
      }
      else
      {
        v93 = flt_915650 * *(v33 - 1);
        v94 = flt_915654 * *v33;
        v95 = flt_915658 * v33[1];
        if ( a4 )
        {
          v93 = v93 + *(float *)v97;
          v94 = v94 + *(float *)&v55[(_DWORD)v33];
          v95 = v95 + *(float *)((char *)v33 + (_DWORD)v31);
        }
        v34 = (v95 - v61) * v82 + (v94 - v60) * v81 + (v93 - v59) * v80;
        if ( v34 > 0.0 )
        {
          if ( v34 < v88 )
          {
            v89 = v34 + 0.5;
            v77 = (int)v89;
            v35 = *(_DWORD *)(LODWORD(v98) + 4 * v77);
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
        LODWORD(v92) = (LODWORD(v92) >> 2) | (v35 << 30);
        if ( a4 )
        {
          v36 = 16 * v35;
          v37 = v101 & 3;
          v38 = (v93 - *(float *)((char *)&v59 + v36)) * *(float *)((char *)v33 + (_DWORD)v32);
          v39 = (v94 - *(float *)((char *)&v60 + v36)) * *(float *)((char *)v33 + (_DWORD)v32);
          v85 = v39;
          v86 = (v95 - *(float *)((char *)&v61 + v36)) * *(float *)((char *)v33 + (_DWORD)v32);
          if ( v37 != 3 )
          {
            *(float *)&v53[(_DWORD)v33] = v38 * 0.4375 + *(float *)&v53[(_DWORD)v33];
            *(float *)&v56[(_DWORD)v33] = 0.4375 * v39 + *(float *)&v56[(_DWORD)v33];
            *(float *)&v79[(_DWORD)v33] = v86 * 0.4375 + *(float *)&v79[(_DWORD)v33];
          }
          if ( v101 < 0xC )
          {
            if ( (v101 & 3) != 0 )
            {
              *(float *)&v54[(_DWORD)v33] = v38 * 0.1875 + *(float *)&v54[(_DWORD)v33];
              *(float *)&v57[(_DWORD)v33] = 0.1875 * v39 + *(float *)&v57[(_DWORD)v33];
              *(float *)&v76[(_DWORD)v33] = v86 * 0.1875 + *(float *)&v76[(_DWORD)v33];
            }
            *(float *)&v46[(_DWORD)v33] = v38 * 0.3125 + *(float *)&v46[(_DWORD)v33];
            *(float *)&v51[(_DWORD)v33] = v39 * 0.3125 + *(float *)&v51[(_DWORD)v33];
            *(float *)((char *)v33 + (char *)&v45[17] - (char *)a1) = v86 * 0.3125
                                                                    + *(float *)((char *)v33
                                                                               + (char *)&v45[17]
                                                                               - (char *)a1);
            if ( v37 != 3 )
            {
              *(float *)&v58[(_DWORD)v33] = v38 * 0.0625 + *(float *)&v58[(_DWORD)v33];
              *(float *)&v87[(_DWORD)v33] = v85 * 0.0625 + *(float *)&v87[(_DWORD)v33];
              *(float *)&v75[(_DWORD)v33] = v86 * 0.0625 + *(float *)&v75[(_DWORD)v33];
            }
          }
        }
      }
      ++v101;
      v97 += 16;
      v33 += 4;
      if ( v101 >= 0x10 )
        break;
      v31 = v91;
    }
    *(float *)(a2 + 4) = v92;
  }
  return 0;
}
