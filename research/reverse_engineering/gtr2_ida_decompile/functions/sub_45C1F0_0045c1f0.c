void __fastcall sub_45C1F0(int a1, int a2, int *a3, double **a4)
{
  int v4; // ebx
  int v5; // esi
  int v6; // ecx
  float *v7; // eax
  double v8; // st7
  _DWORD *v9; // ecx
  double v10; // st6
  float v11; // eax
  int v12; // eax
  double v13; // st7
  double v14; // st6
  float *v15; // eax
  double v16; // st7
  double v17; // st6
  float v18; // eax
  int v19; // eax
  double v20; // st7
  double v21; // st6
  float *v22; // eax
  double v23; // st7
  double v24; // st6
  float v25; // eax
  float *v26; // eax
  double v27; // st7
  float v28; // edx
  int v29; // esi
  char *v30; // ebx
  int v31; // edi
  char *v32; // eax
  int v33; // edi
  unsigned int v34; // ecx
  int v35; // edx
  int v36; // ebx
  _DWORD *v37; // esi
  float *v38; // edi
  unsigned int v39; // eax
  float v40; // edx
  float v41; // eax
  _DWORD *v42; // edx
  void *v43; // ecx
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // edi
  int v49; // esi
  bool v50; // cc
  int v51; // eax
  float **v52; // esi
  int v53; // ebx
  float *v54; // ecx
  float *v55; // eax
  double v56; // st7
  double v57; // st6
  double *v58; // esi
  int v59; // edx
  int v60; // ebx
  float v61; // eax
  double v62; // st7
  double v63; // st7
  double v64; // st6
  float v65; // ecx
  float v66; // ecx
  double v67; // st7
  int j; // esi
  double v69; // st7
  int v70; // edx
  int v71; // ecx
  double v72; // st7
  double v73; // st7
  int v74; // eax
  int i; // esi
  int v76; // eax
  double v77; // st7
  float v78; // ecx
  int v79; // ecx
  double v80; // st7
  double v81; // st6
  float v82; // ecx
  int v83; // ecx
  double v84; // st7
  double v85; // st6
  float v86; // ecx
  bool v87; // zf
  _DWORD v88[4]; // [esp+0h] [ebp-2E0h] BYREF
  int v89; // [esp+10h] [ebp-2D0h] BYREF
  void *Block; // [esp+14h] [ebp-2CCh]
  _DWORD *v91; // [esp+18h] [ebp-2C8h]
  int v92; // [esp+1Ch] [ebp-2C4h]
  int v93; // [esp+20h] [ebp-2C0h]
  int v94; // [esp+24h] [ebp-2BCh]
  double *v95; // [esp+28h] [ebp-2B8h] BYREF
  _DWORD *v96; // [esp+2Ch] [ebp-2B4h]
  int v97; // [esp+30h] [ebp-2B0h] BYREF
  int v98; // [esp+34h] [ebp-2ACh]
  double v99; // [esp+38h] [ebp-2A8h]
  float v100; // [esp+40h] [ebp-2A0h] BYREF
  float v101; // [esp+44h] [ebp-29Ch]
  double v102; // [esp+48h] [ebp-298h] BYREF
  double v103; // [esp+50h] [ebp-290h] BYREF
  float v104; // [esp+58h] [ebp-288h] BYREF
  _BYTE v105[12]; // [esp+5Ch] [ebp-284h] BYREF
  double v106; // [esp+68h] [ebp-278h] BYREF
  float v107; // [esp+70h] [ebp-270h] BYREF
  _BYTE v108[12]; // [esp+74h] [ebp-26Ch] BYREF
  double v109; // [esp+80h] [ebp-260h] BYREF
  __int128 v110; // [esp+88h] [ebp-258h] BYREF
  _BYTE v111[12]; // [esp+98h] [ebp-248h]
  float v112; // [esp+A4h] [ebp-23Ch]
  float v113; // [esp+A8h] [ebp-238h]
  _BYTE v114[8]; // [esp+ACh] [ebp-234h] BYREF
  int v115; // [esp+B4h] [ebp-22Ch]
  double *v116; // [esp+C0h] [ebp-220h] BYREF
  double v117; // [esp+C4h] [ebp-21Ch] BYREF
  double v118; // [esp+CCh] [ebp-214h]
  double v119; // [esp+D4h] [ebp-20Ch] BYREF
  double v120; // [esp+DCh] [ebp-204h]
  double v121; // [esp+E4h] [ebp-1FCh]
  double v122[2]; // [esp+ECh] [ebp-1F4h] BYREF
  float v123; // [esp+FCh] [ebp-1E4h]
  float v124[2]; // [esp+104h] [ebp-1DCh] BYREF
  double v125; // [esp+10Ch] [ebp-1D4h]
  float v126; // [esp+114h] [ebp-1CCh]
  _DWORD v127[2]; // [esp+128h] [ebp-1B8h]
  int *v128; // [esp+130h] [ebp-1B0h] BYREF
  int v129[6]; // [esp+134h] [ebp-1ACh] BYREF
  char v130; // [esp+14Ch] [ebp-194h] BYREF
  int v131; // [esp+2C4h] [ebp-1Ch]
  int v132; // [esp+2DCh] [ebp-4h]
  int savedregs; // [esp+2E0h] [ebp+0h] BYREF

  HIDWORD(v103) = a1;
  sub_459C50((int)&v117, (void (__thiscall *)(void *))&savedregs);
  v4 = *a3;
  v5 = 0;
  Block = (void *)(4 * *a3);
  v132 = 0;
  v97 = v4;
  sub_459BD0();
  if ( v4 > 0 )
  {
    v97 = v4;
    do
    {
      v6 = a3[2];
      v7 = *(float **)(v6 + v5);
      v8 = v7[4];
      v9 = (_DWORD *)(v5 + v6);
      v10 = *((double *)v7 + 3);
      v11 = *v7;
      v120 = v10;
      *(float *)&v119 = v11;
      *(float *)&v121 = v8;
      v12 = v9[1];
      v13 = *(float *)(v12 + 16);
      v14 = *(double *)(v12 + 24);
      HIDWORD(v103) = *(_DWORD *)v12;
      *(double *)v105 = v14;
      *(float *)&v105[8] = v13;
      v15 = (float *)v9[2];
      v16 = v15[4];
      v17 = *((double *)v15 + 3);
      v18 = *v15;
      v122[1] = v17;
      *(float *)v122 = v18;
      v123 = v16;
      v19 = v9[3];
      v20 = *(float *)(v19 + 16);
      v21 = *(double *)(v19 + 24);
      HIDWORD(v106) = *(_DWORD *)v19;
      *(double *)v108 = v21;
      *(float *)&v108[8] = v20;
      v22 = (float *)v9[4];
      v23 = v22[4];
      v24 = *((double *)v22 + 3);
      v25 = *v22;
      v125 = v24;
      v124[0] = v25;
      v126 = v23;
      v26 = (float *)v9[5];
      v27 = v26[4];
      v28 = *v26;
      *(double *)((char *)&v110 + 4) = *((double *)v26 + 3);
      *((float *)&v109 + 1) = v28;
      *((float *)&v110 + 3) = v27;
      sub_458E90((int)v9, &v95);
      sub_4592E0(&v116, (int)&v119, (int)&v103 + 4, (int)&v109 + 4, (int)&v95, 0);
      sub_4592E0(&v116, (int)&v103 + 4, (int)v122, (int)&v106 + 4, (int)&v95, 0);
      sub_4592E0(&v116, (int)&v109 + 4, (int)&v106 + 4, (int)v124, (int)&v95, 0);
      sub_4592E0(&v116, (int)&v106 + 4, (int)&v109 + 4, (int)&v103 + 4, (int)&v95, 0);
      v5 += 32;
      --v97;
    }
    while ( v97 );
  }
  sub_4597A0((int *)&v116);
  sub_459270((int)a3, (void (__thiscall *)(void *))&savedregs);
  v95 = (double *)operator new(4 * v4);
  v94 = 0;
  if ( v4 > 0 )
  {
    do
    {
      v29 = 0;
      v30 = &v130;
      v31 = v94 << 7;
      while ( 1 )
      {
        v89 = 0;
        v88[3] = v31 + HIDWORD(v117);
        v129[v29 + 2] = v31 + HIDWORD(v117);
        if ( sub_45A530() )
          break;
        ++v29;
        v31 += 32;
        v30 += 96;
        if ( v29 >= 4 )
        {
          *(_DWORD *)(v93 + 4 * v92) = sub_45BD30((void *)LODWORD(v102), v129);
          goto LABEL_9;
        }
      }
      *(_DWORD *)(v93 + 4 * v92) = 4;
LABEL_9:
      ++v92;
    }
    while ( v92 < v94 );
    v4 = v94;
  }
  v32 = 0;
  v92 = 0;
  if ( v4 > 0 )
  {
    v33 = 0;
    v95 = 0;
    do
    {
      if ( *(_DWORD *)(v93 + 4 * (_DWORD)v32) )
      {
        v34 = *(_DWORD *)((char *)v116 + v33 + 48);
        v35 = *(_DWORD *)((char *)v116 + v33 + 8);
        v36 = *(_DWORD *)((char *)v116 + v33);
        v37 = (_DWORD *)((char *)v116 + v33);
        v38 = (float *)((char *)v116 + v33 + 64);
        v39 = v37[10];
        v98 = v35;
        v40 = v38[4];
        v99 = COERCE_DOUBLE(__PAIR64__(v34, v39));
        v41 = *v38;
        v97 = v36;
        v100 = v40;
        v101 = v41;
        v96 = sub_458E90((int)v37, &v128);
        sub_458700();
        *(_DWORD *)v111 = v98;
        *(double *)&v111[4] = v99;
        HIDWORD(v110) = v36;
        v112 = v100;
        v113 = v101;
        sub_458730((int)&v110 + 12, (int)v96);
        v88[2] = 0;
        v88[1] = (char *)&v110 + 12;
        sub_45A530();
        v42 = v91;
        v43 = Block;
        if ( v91[(_DWORD)Block] != 1 )
        {
          v44 = v37[1];
          *(double *)(v44 + 24) = (v119 * *(float *)(v44 + 16) + v117 * *(float *)v44 + v120) * *(float *)v44
                                + (v118 * *(float *)(v44 + 16) + v121) * *(float *)(v44 + 16)
                                + v122[0];
          v45 = v37[9];
          *(double *)(v45 + 24) = (v119 * *(float *)(v45 + 16) + *(float *)v45 * v117 + v120) * *(float *)v45
                                + (v118 * *(float *)(v45 + 16) + v121) * *(float *)(v45 + 16)
                                + v122[0];
        }
        if ( v42[(_DWORD)v43] != 2 )
        {
          v46 = v37[11];
          *(double *)(v46 + 24) = (v119 * *(float *)(v46 + 16) + v117 * *(float *)v46 + v120) * *(float *)v46
                                + (v118 * *(float *)(v46 + 16) + v121) * *(float *)(v46 + 16)
                                + v122[0];
          v47 = *((_DWORD *)v38 + 3);
          *(double *)(v47 + 24) = (v119 * *(float *)(v47 + 16) + *(float *)v47 * v117 + v120) * *(float *)v47
                                + (v118 * *(float *)(v47 + 16) + v121) * *(float *)(v47 + 16)
                                + v122[0];
        }
        if ( v42[(_DWORD)v43] != 3 )
        {
          v48 = *((_DWORD *)v38 + 5);
          *(double *)(v48 + 24) = (v119 * *(float *)(v48 + 16) + v117 * *(float *)v48 + v120) * *(float *)v48
                                + (v118 * *(float *)(v48 + 16) + v121) * *(float *)(v48 + 16)
                                + v122[0];
          v49 = v37[5];
          *(double *)(v49 + 24) = (v119 * *(float *)(v49 + 16) + *(float *)v49 * v117 + v120) * *(float *)v49
                                + (v118 * *(float *)(v49 + 16) + v121) * *(float *)(v49 + 16)
                                + v122[0];
        }
        v4 = v92;
      }
      v32 = (char *)Block + 1;
      v33 = v93 + 128;
      v50 = (int)Block + 1 < v4;
      Block = (char *)Block + 1;
      v93 += 128;
    }
    while ( v50 );
  }
  v88[0] = v4;
  sub_459BD0();
  if ( v4 > 0 )
  {
    v91 = Block;
    v51 = 0;
    v92 = 0;
    v93 = v4;
    while ( 1 )
    {
      v52 = (float **)(v51 + v115);
      v53 = v51 + v115 + 32;
      v127[0] = v51 + v115;
      v127[1] = v53;
      v128 = (int *)(v51 + v115 + 64);
      v129[0] = v51 + v115 + 96;
      sub_458E90(v51 + v115, &v89);
      switch ( *v91 )
      {
        case 0:
          for ( i = 0; i < 4; ++i )
          {
            v76 = v127[i];
            v77 = *(float *)(*(_DWORD *)v76 + 16);
            v78 = **(float **)v76;
            v102 = *(double *)(*(_DWORD *)v76 + 24);
            v100 = v78;
            *(float *)&v103 = v77;
            *(double *)&v110 = *(double *)(*(_DWORD *)(v76 + 4) + 24);
            v79 = *(_DWORD *)(v76 + 8);
            v80 = *(float *)(v79 + 16);
            v81 = *(double *)(v79 + 24);
            v82 = *(float *)v79;
            *(double *)&v105[4] = v81;
            v104 = v82;
            *(float *)&v106 = v80;
            *((double *)&v110 + 1) = *(double *)(*(_DWORD *)(v76 + 12) + 24);
            v83 = *(_DWORD *)(v76 + 16);
            v84 = *(float *)(v83 + 16);
            v85 = *(double *)(v83 + 24);
            v86 = *(float *)v83;
            *(double *)&v108[4] = v85;
            v107 = v86;
            *(float *)&v109 = v84;
            *(double *)v111 = *(double *)(*(_DWORD *)(v76 + 20) + 24);
            sub_4592E0(a4, (int)&v100, (int)&v104, (int)&v107, (int)&v89, (int)&v110);
          }
          break;
        case 1:
        case 2:
        case 3:
          for ( j = 0; j < 2; ++j )
          {
            sub_45BB70();
            v69 = *((float *)Block + 4);
            v70 = *(_DWORD *)Block;
            v99 = *((double *)Block + 3);
            v97 = v70;
            v100 = v69;
            *(double *)&v108[4] = *((double *)v91 + 3);
            v71 = *(_DWORD *)v92;
            v72 = *(float *)(v92 + 16);
            v103 = *(double *)(v92 + 24);
            LODWORD(v102) = v71;
            v104 = v72;
            v109 = *(double *)(v93 + 24);
            v73 = *(float *)(v94 + 16);
            v74 = *(_DWORD *)v94;
            v106 = *(double *)(v94 + 24);
            *(_DWORD *)&v105[4] = v74;
            v107 = v73;
            *(double *)&v110 = v95[3];
            sub_4592E0(a4, (int)&v97, (int)&v102, (int)&v105[4], (int)v88, (int)&v108[4]);
          }
          break;
        case 4:
          v54 = v52[10];
          v55 = *v52;
          v56 = (*v52)[4];
          v57 = *((double *)*v52 + 3);
          v58 = (double *)v52[2];
          v97 = *(_DWORD *)(v53 + 16);
          v59 = v128[4];
          v60 = *v128;
          v94 = (int)v55;
          v61 = *v55;
          v102 = v57;
          v100 = v61;
          *(float *)&v103 = v56;
          v62 = v58[3];
          v96 = v54;
          *(double *)&v110 = v62;
          v98 = v59;
          v63 = v54[4];
          v95 = v58;
          v64 = *((double *)v54 + 3);
          v65 = *v54;
          *(double *)&v105[4] = v64;
          v104 = v65;
          LODWORD(v99) = v60;
          *(float *)&v106 = v63;
          *((double *)&v110 + 1) = *(double *)(v97 + 24);
          v66 = *(float *)v59;
          v67 = *(float *)(v59 + 16);
          *(double *)&v108[4] = *(double *)(v59 + 24);
          v107 = v66;
          *(float *)&v109 = v67;
          *(double *)v111 = *(double *)(v60 + 24);
          sub_4592E0(a4, (int)&v100, (int)&v104, (int)&v107, (int)&v89, (int)&v110);
          break;
        default:
          break;
      }
      v87 = v93 == 1;
      v92 += 128;
      ++v91;
      --v93;
      if ( v87 )
        break;
      v51 = v92;
    }
  }
  sub_459270((int)v114, (void (__thiscall *)(void *))&savedregs);
  if ( Block )
    j_j__free(Block);
  v131 = -1;
  sub_459270((int)v114, (void (__thiscall *)(void *))&savedregs);
}
