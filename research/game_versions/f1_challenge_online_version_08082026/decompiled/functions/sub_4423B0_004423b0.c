char __thiscall sub_4423B0(int this)
{
  int v2; // eax
  int v3; // ecx
  float *v4; // esi
  double *v5; // edi
  int v6; // ebx
  double v7; // st7
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  double *v11; // eax
  double v12; // st7
  double *v13; // ecx
  double v14; // st7
  int v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // edi
  double *v19; // esi
  double **v20; // ebx
  double *v21; // eax
  int v22; // eax
  long double v23; // st7
  int v24; // edx
  double v25; // st7
  double *v26; // eax
  double v27; // st7
  double v28; // st6
  long double v29; // st7
  double v30; // st6
  double v31; // st5
  double v32; // st6
  long double v33; // st7
  long double v34; // st6
  long double v35; // st7
  long double v36; // st7
  int v37; // ecx
  float *v38; // ecx
  float v39; // eax
  float v40; // edx
  float v41; // eax
  bool v42; // zf
  char result; // al
  double *v44; // ebx
  int v45; // eax
  double v46; // st7
  double v47; // st6
  double v48; // st7
  double v49; // st6
  double v50; // st5
  double v51; // st4
  float v52; // [esp+0h] [ebp-1ACh]
  float v53; // [esp+18h] [ebp-194h]
  int v54; // [esp+18h] [ebp-194h]
  int v55; // [esp+18h] [ebp-194h]
  int v56; // [esp+1Ch] [ebp-190h]
  float v57; // [esp+1Ch] [ebp-190h]
  double v58; // [esp+20h] [ebp-18Ch] BYREF
  double v59; // [esp+28h] [ebp-184h]
  double v60; // [esp+30h] [ebp-17Ch]
  double *v61; // [esp+38h] [ebp-174h]
  long double v62; // [esp+3Ch] [ebp-170h]
  double *v63; // [esp+48h] [ebp-164h]
  long double v64; // [esp+4Ch] [ebp-160h]
  long double v65; // [esp+54h] [ebp-158h]
  double v66; // [esp+5Ch] [ebp-150h]
  double v67; // [esp+64h] [ebp-148h]
  double v68; // [esp+6Ch] [ebp-140h]
  float v69; // [esp+74h] [ebp-138h]
  float v70; // [esp+78h] [ebp-134h]
  float v71; // [esp+7Ch] [ebp-130h]
  double v72; // [esp+80h] [ebp-12Ch]
  double v73[3]; // [esp+88h] [ebp-124h] BYREF
  double v74; // [esp+A0h] [ebp-10Ch] BYREF
  double v75; // [esp+A8h] [ebp-104h]
  double v76; // [esp+B0h] [ebp-FCh]
  double v77; // [esp+B8h] [ebp-F4h] BYREF
  double v78; // [esp+C0h] [ebp-ECh]
  double v79; // [esp+C8h] [ebp-E4h]
  int v80; // [esp+D0h] [ebp-DCh]
  int v81; // [esp+D4h] [ebp-D8h]
  int v82; // [esp+D8h] [ebp-D4h]
  int v83; // [esp+DCh] [ebp-D0h]
  double v84; // [esp+E0h] [ebp-CCh]
  double *v85; // [esp+E8h] [ebp-C4h]
  double v86[3]; // [esp+ECh] [ebp-C0h] BYREF
  double v87[3]; // [esp+104h] [ebp-A8h] BYREF
  double v88; // [esp+11Ch] [ebp-90h]
  long double v89; // [esp+124h] [ebp-88h]
  double v90[3]; // [esp+134h] [ebp-78h] BYREF
  double v91[3]; // [esp+14Ch] [ebp-60h] BYREF
  double v92[3]; // [esp+164h] [ebp-48h] BYREF
  double v93; // [esp+17Ch] [ebp-30h]
  double v94; // [esp+18Ch] [ebp-20h]
  long double v95; // [esp+1A4h] [ebp-8h]

  if ( flt_8AFEEC == flt_8AFEE8 )
  {
    v2 = this + 1276;
    v3 = 4;
    do
    {
      v2 += 1124;
      --v3;
      *(double *)(v2 - 1124) = flt_8AFEE8;
    }
    while ( v3 );
  }
  else
  {
    v4 = (float *)sub_4E9630(*(_DWORD *)(this + 7936) + 12);
    v5 = (double *)(this + 1276);
    v6 = 4;
    v53 = v4[10] * v4[2] + v4[9] * v4[1] + v4[8] * *v4 + v4[7];
    do
    {
      v7 = fabs(
             *(double *)(*((_DWORD *)v5 - 69) + 20) * v4[10]
           + *(double *)(*((_DWORD *)v5 - 69) + 4) * v4[8]
           + *(double *)(*((_DWORD *)v5 - 69) + 12) * v4[9]
           - v53);
      v52 = v7;
      sub_4FD7E0(v52);
      *v5 = v7;
      v5 = (double *)((char *)v5 + 1124);
      --v6;
    }
    while ( v6 );
  }
  v8 = *(_DWORD *)(this + 7936);
  v9 = *(_DWORD *)(v8 + 3284);
  v10 = v8 + 3284;
  if ( v9 && *(_BYTE *)(v10 + 64) )
  {
    sub_435E00((double *)(*(_DWORD *)(this + 5616) + 28), (double *)(this + 6472), (double *)(this + 6424));
    v11 = *(double **)(this + 5616);
    v12 = *(double *)(this + 6424) + *(double *)((char *)v11 + 4);
    v11 = (double *)((char *)v11 + 4);
    v13 = *(double **)(this + 6404);
    v58 = v12;
    v59 = *(double *)(this + 6432) + v11[1];
    v14 = *(double *)(this + 6440) + v11[2];
    v85 = v13;
    v80 = 1717986918;
    v60 = v14;
    v81 = 1071015526;
    v82 = 0x40000000;
    v77 = v58;
    v83 = 1201543096;
    v78 = v59 + 0.15;
    v79 = v14;
    v15 = sub_44C4C0(&v77);
    *(_DWORD *)(this + 6404) = v15;
    if ( v15 )
    {
      *(double *)(this + 6408) = v59 - v84;
    }
    else
    {
      v16 = *(_DWORD *)(this + 6420);
      *(_DWORD *)(this + 6408) = *(_DWORD *)(this + 6416);
      *(_DWORD *)(this + 6412) = v16;
    }
  }
  v17 = this + 652;
  v18 = 4;
  do
  {
    sub_436870(v17, *(double *)(this + 96));
    v17 += 1124;
    --v18;
  }
  while ( v18 );
  v19 = (double *)(this + 5872);
  v63 = (double *)(this + 5728);
  v61 = (double *)(this + 5872);
  v20 = (double **)(this + 5856);
  v54 = 4;
  do
  {
    sub_43AEE0((double *)(*(_DWORD *)(this + 5616) + 28), (double *)(*(_DWORD *)(this + 5616) + 4), v63, &v58);
    v21 = *v20;
    v77 = v58;
    v80 = 1717986918;
    v78 = v59 + 0.15;
    v81 = 1071015526;
    v79 = v60;
    v82 = 0x40000000;
    v83 = 1201543096;
    v85 = v21;
    v22 = sub_44C4C0(&v77);
    *v20 = (double *)v22;
    if ( v22 )
    {
      v56 = *(_DWORD *)(v22 + 84);
      v23 = v59 - ((sin(*(float *)(v56 + 24) * v58) + sin(*(float *)(v56 + 24) * v60)) * *(float *)(v56 + 20) + v84);
      *v19 = v23;
      if ( dword_7CE958 )
        *v19 = v23 + 0.01;
      if ( *v19 < 0.0 )
      {
        v24 = *(_DWORD *)(this + 5616);
        v25 = v58;
        *(_BYTE *)(this + 5912) = 1;
        v26 = *v20;
        v74 = v25 - *(double *)(v24 + 4);
        v75 = v59 - *(double *)(v24 + 12);
        v76 = v60 - *(double *)(v24 + 20);
        v27 = v60 * v26[2] + v58 * *v26 + v58 * *v26 + v26[3];
        v28 = v60 * v26[1] + v60 * v26[1] + v58 * v26[2] + v26[4];
        v65 = 1.0 / sqrt(v28 * v28 + v27 * v27 + 1.0);
        v90[0] = -(v65 * v27);
        v29 = -(v65 * v28);
        v30 = v76 * *(double *)(v24 + 132) - v75 * *(double *)(v24 + 140);
        v31 = v74 * *(double *)(v24 + 140) - v76 * *(double *)(v24 + 124);
        v68 = v75 * *(double *)(v24 + 124) - v74 * *(double *)(v24 + 132);
        v66 = v30 + *(double *)(v24 + 100);
        v32 = v31 + *(double *)(v24 + 108);
        v68 = v68 + *(double *)(v24 + 116);
        v62 = v65 * v32 + v66 * v90[0] + v29 * v68;
        v64 = *v19 * -385000.0 - v62 * 17500.0;
        if ( v64 > 0.0 )
        {
          v95 = v29 * v62;
          v73[0] = v66 - v90[0] * v62;
          v73[1] = v32 - v65 * v62;
          v73[2] = v68 - v95;
          qmemcpy(v86, v73, sizeof(v86));
          v62 = sqrt(v73[0] * v73[0] + v73[2] * v73[2] + v73[1] * v73[1]);
          if ( v62 > 1.0 )
          {
            v86[0] = v73[0] * (1.0 / v62);
            v86[1] = v86[1] * (1.0 / v62);
            v86[2] = v86[2] * (1.0 / v62);
          }
          v91[2] = v86[2] + v86[2];
          v72 = *(float *)(v56 + 36);
          v93 = (v86[0] + v86[0]) * v72;
          v88 = v90[0] - v93;
          v89 = v65 - (v86[1] + v86[1]) * v72;
          v87[0] = v88 * v64;
          v87[1] = v89 * v64;
          v87[2] = (v29 - v91[2] * v72) * v64;
          qmemcpy(v92, v87, sizeof(v92));
          sub_569AD0(&v74, v92);
          if ( v64 > *(double *)(this + 5916) && *(_BYTE *)(v56 + 44) )
          {
            v33 = v62 * 0.0078125;
            v34 = v64;
            *(long double *)(this + 5916) = v64;
            v35 = v33 * (v34 * 0.00048828125);
            v57 = v35;
            if ( v35 > 1.0 )
              v57 = 1.0;
            v36 = v62 * 0.01 + 0.5;
            if ( v36 > 2.0 )
              v36 = 2.0;
            v37 = *(_DWORD *)(this + 7936);
            v19 = v61;
            if ( *(float *)(v37 + 176) < (double)v57 )
            {
              v69 = *v63;
              v38 = (float *)(v37 + 184);
              v70 = v63[1];
              v39 = v69;
              v71 = v63[2];
              *(v38 - 2) = v57;
              v40 = v70;
              *(v38 - 1) = v36;
              *v38 = v39;
              v41 = v71;
              v38[1] = v40;
              v38[2] = v41;
            }
          }
          else
          {
            v19 = v61;
          }
        }
      }
    }
    ++v19;
    ++v20;
    v42 = v54 == 1;
    v61 = v19;
    v63 += 3;
    --v54;
  }
  while ( !v42 );
  result = *(_BYTE *)(this + 5924);
  if ( result )
  {
    v44 = (double *)(this + 5736);
    v55 = 4;
    do
    {
      v45 = *(_DWORD *)(this + 5616);
      v58 = *(double *)(v45 + 44) * v44[1] + *(double *)(v45 + 36) * *v44 + *(double *)(v45 + 28) * *(v44 - 1);
      v59 = *(double *)(v45 + 68) * v44[1] + *(double *)(v45 + 52) * *(v44 - 1) + *(double *)(v45 + 60) * *v44;
      v60 = *(double *)(v45 + 92) * v44[1] + *(double *)(v45 + 76) * *(v44 - 1) + *(double *)(v45 + 84) * *v44;
      v46 = v60 * *(double *)(v45 + 132) - v59 * *(double *)(v45 + 140);
      v47 = v58 * *(double *)(v45 + 140) - v60 * *(double *)(v45 + 124);
      v87[2] = v59 * *(double *)(v45 + 124) - v58 * *(double *)(v45 + 132);
      v87[0] = v46 + *(double *)(v45 + 100);
      v48 = v47 + *(double *)(v45 + 108);
      v49 = v87[2] + *(double *)(v45 + 116);
      v50 = v58 + *(double *)(v45 + 4);
      v51 = v59 + *(double *)(v45 + 12);
      v92[2] = v60 + *(double *)(v45 + 20);
      v66 = v44[28] - v50;
      v67 = v44[29] - v51;
      v68 = v44[30] - v92[2];
      v88 = v87[0] * 6500.0;
      v89 = v48 * 6500.0;
      v94 = v68 * 160000.0;
      v90[0] = v66 * 160000.0 - v88;
      v90[1] = v67 * 160000.0 - v89;
      v90[2] = v94 - v49 * 6500.0;
      qmemcpy(v91, v90, sizeof(v91));
      sub_569AD0(&v58, v91);
      v44 += 3;
      result = --v55;
    }
    while ( v55 );
  }
  return result;
}
