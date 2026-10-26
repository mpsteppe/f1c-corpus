int __thiscall sub_4592E0(double **this, int a2, int a3, int a4, int a5, int a6)
{
  double **v6; // ebp
  double *v7; // eax
  double *v8; // esi
  double **v9; // eax
  int v10; // ebx
  double *v11; // edi
  double *v12; // ebp
  double **v13; // esi
  bool v14; // cc
  unsigned int v15; // eax
  double *v16; // ecx
  double *v17; // ecx
  double *v18; // eax
  char *v19; // edi
  int v20; // ecx
  double *v21; // eax
  double *v22; // eax
  double *v23; // eax
  double v24; // st7
  float v25; // ecx
  float v26; // edx
  double **v27; // esi
  double *v28; // eax
  int v29; // edx
  double *v30; // ebp
  int v31; // eax
  double *v32; // edi
  int v33; // eax
  double *v34; // ecx
  int v35; // esi
  int v36; // eax
  _DWORD *v37; // ebx
  int i; // eax
  int v39; // edx
  int v40; // ecx
  int v41; // edx
  bool v42; // zf
  float *v43; // eax
  int v44; // esi
  int v45; // eax
  int j; // edx
  int result; // eax
  unsigned int v48; // ecx
  _DWORD *v49; // ecx
  double v50; // st7
  double **v52; // [esp+14h] [ebp-70h]
  float v53; // [esp+18h] [ebp-6Ch] BYREF
  double v54; // [esp+20h] [ebp-64h]
  float v55; // [esp+28h] [ebp-5Ch]
  _DWORD v56[6]; // [esp+30h] [ebp-54h] BYREF
  float v57; // [esp+48h] [ebp-3Ch] BYREF
  double v58; // [esp+50h] [ebp-34h]
  float v59; // [esp+58h] [ebp-2Ch]
  float v60; // [esp+60h] [ebp-24h] BYREF
  double v61; // [esp+68h] [ebp-1Ch]
  float v62; // [esp+70h] [ebp-14h]
  int v63; // [esp+80h] [ebp-4h]
  int *v64; // [esp+88h] [ebp+4h]
  int v65; // [esp+8Ch] [ebp+8h]
  int v66; // [esp+90h] [ebp+Ch]
  int v67; // [esp+94h] [ebp+10h]

  v6 = this;
  v7 = this[1];
  if ( (int)*this >= (int)v7 )
  {
    v8 = v7 + 1024;
    this[1] = v7 + 1024;
    v9 = (double **)operator new(32 * (_DWORD)(v7 + 1024) + 4);
    v10 = 0;
    v63 = 0;
    if ( v9 )
    {
      v11 = (double *)(v9 + 1);
      *v9 = v8;
      sub_630A11(v9 + 1, 32, v8, sub_458700, nullsub_7);
      v12 = v11;
    }
    else
    {
      v12 = 0;
    }
    v13 = this;
    v14 = (int)*this <= 0;
    v63 = -1;
    if ( !v14 )
    {
      v15 = 0;
      do
      {
        qmemcpy(&v12[v15], &v13[2][v15], 0x20u);
        HIDWORD(this[2][v15 + 3]) = &v12[v15];
        ++v10;
        v15 += 4;
        v13 = this;
      }
      while ( v10 < (int)*this );
    }
    v16 = v13[3];
    if ( v16 )
      sub_4586A0(v16);
    v17 = v13[4];
    if ( v17 )
      sub_4586A0(v17);
    v18 = v13[2];
    if ( v18 )
    {
      v19 = (char *)v18 - 4;
      `eh vector destructor iterator'(v18, 0x20u, *((_DWORD *)v18 - 1), nullsub_7);
      j_j__free(v19);
    }
    v13[2] = v12;
    v6 = this;
  }
  v20 = (int)&v6[2][4 * (int)*v6];
  *v6 = (double *)((char *)*v6 + 1);
  *(_BYTE *)(v20 + 25) = *(_BYTE *)a5;
  *(_WORD *)(v20 + 26) = *(_WORD *)(a5 + 2);
  v21 = v6[3];
  v52 = (double **)v20;
  v53 = (*(float *)a2 + *(float *)a3) * 0.5;
  v54 = (*(double *)(a3 + 8) + *(double *)(a2 + 8)) * 0.5;
  v55 = (*(float *)(a3 + 16) + *(float *)(a2 + 16)) * 0.5;
  v57 = (*(float *)a3 + *(float *)a4) * 0.5;
  v58 = (*(double *)(a4 + 8) + *(double *)(a3 + 8)) * 0.5;
  v59 = (*(float *)(a3 + 16) + *(float *)(a4 + 16)) * 0.5;
  v60 = (*(float *)a2 + *(float *)a4) * 0.5;
  v61 = (*(double *)(a4 + 8) + *(double *)(a2 + 8)) * 0.5;
  v62 = (*(float *)(a2 + 16) + *(float *)(a4 + 16)) * 0.5;
  if ( !v21 )
  {
    v22 = (double *)operator new(0x68u);
    v6[3] = v22;
    *(_DWORD *)v22 = *(_DWORD *)a2;
    v22[1] = *(double *)(a2 + 8);
    *((_DWORD *)v22 + 4) = *(_DWORD *)(a2 + 16);
    v22[3] = *(double *)(a2 + 8);
    *((_DWORD *)v22 + 8) = 0;
    *((_DWORD *)v22 + 9) = 0;
    *((_DWORD *)v22 + 10) = 0;
    *((_DWORD *)v22 + 11) = 0;
    *((_DWORD *)v22 + 12) = 0;
    *((_DWORD *)v22 + 13) = 0;
    *((_DWORD *)v22 + 14) = 0;
    *((_DWORD *)v22 + 15) = 0;
    *((_DWORD *)v22 + 16) = 0;
    *((_DWORD *)v22 + 17) = 0;
    *((_DWORD *)v22 + 18) = 0;
    *((_DWORD *)v22 + 19) = 0;
    *((_DWORD *)v22 + 20) = -1;
    *((_DWORD *)v22 + 21) = 0;
    *((_DWORD *)v22 + 22) = 0;
    *((_DWORD *)v22 + 23) = 0;
    *((_DWORD *)v22 + 24) = 0;
    *((_DWORD *)v22 + 25) = 0;
  }
  if ( !v6[4] )
  {
    v23 = (double *)operator new(0x68u);
    v24 = v54;
    v25 = v53;
    v26 = v55;
    v6[4] = v23;
    v23[1] = v24;
    *(float *)v23 = v25;
    v23[3] = v24;
    *((float *)v23 + 4) = v26;
    *((_DWORD *)v23 + 8) = 0;
    *((_DWORD *)v23 + 9) = 0;
    *((_DWORD *)v23 + 10) = 0;
    *((_DWORD *)v23 + 11) = 0;
    *((_DWORD *)v23 + 12) = 0;
    *((_DWORD *)v23 + 13) = 0;
    *((_DWORD *)v23 + 14) = 0;
    *((_DWORD *)v23 + 15) = 0;
    *((_DWORD *)v23 + 16) = 0;
    *((_DWORD *)v23 + 17) = 0;
    *((_DWORD *)v23 + 18) = 0;
    *((_DWORD *)v23 + 19) = 0;
    *((_DWORD *)v23 + 20) = -1;
    *((_DWORD *)v23 + 21) = 0;
    *((_DWORD *)v23 + 22) = 0;
    *((_DWORD *)v23 + 23) = 0;
    *((_DWORD *)v23 + 24) = 0;
    *((_DWORD *)v23 + 25) = 0;
  }
  v27 = v52;
  *v52 = sub_458540(v6[3], a2);
  v52[2] = sub_458540(v6[3], a3);
  v28 = sub_458540(v6[3], a4);
  v29 = 1;
  v52[4] = v28;
  v67 = 1;
  while ( 2 )
  {
    v30 = v27[v29 - 1];
    if ( v29 == 5 )
      v31 = 0;
    else
      v31 = v29 + 1;
    v32 = v52[v31];
    v33 = *((_DWORD *)v30 + 8);
    v34 = 0;
    if ( (unsigned int)v33 < 0xB )
    {
      if ( v33 <= 0 )
        goto LABEL_52;
    }
    else
    {
      v33 = 11;
    }
    v64 = (int *)v30 + 9;
    v66 = v33;
    do
    {
      v35 = *v64;
      v36 = *((_DWORD *)v32 + 8);
      if ( (unsigned int)v36 < 0xB )
      {
        if ( v36 <= 0 )
          goto LABEL_51;
      }
      else
      {
        v36 = 11;
      }
      v37 = (_DWORD *)v32 + 9;
      v65 = v36;
      do
      {
        if ( v35 != *v37 )
          goto LABEL_50;
        for ( i = 0; i < 6; i += 2 )
        {
          if ( *(double **)(v35 + 4 * i) != v30 )
            continue;
          v39 = 4;
          if ( i )
            v39 = i - 2;
          if ( *(double **)(v35 + 4 * v39) == v32 )
          {
            v40 = 5;
            if ( i )
              v40 = i - 1;
            goto LABEL_47;
          }
          if ( i == 4 )
            v41 = 0;
          else
            v41 = i + 2;
          if ( *(double **)(v35 + 4 * v41) == v32 )
          {
            if ( i == 5 )
              v40 = 0;
            else
              v40 = i + 1;
LABEL_47:
            v34 = *(double **)(v35 + 4 * v40);
            continue;
          }
        }
        v29 = v67;
LABEL_50:
        ++v37;
        --v65;
      }
      while ( v65 );
LABEL_51:
      v42 = v66 == 1;
      ++v64;
      --v66;
    }
    while ( !v42 );
LABEL_52:
    if ( v29 == 1 )
    {
      v43 = &v53;
    }
    else
    {
      v43 = &v57;
      if ( v29 != 3 )
        v43 = &v60;
    }
    *(float *)v56 = *v43;
    *(float *)&v56[1] = v43[1];
    *(float *)&v56[2] = v43[2];
    *(float *)&v56[3] = v43[3];
    v44 = *((_DWORD *)v43 + 4);
    v45 = *((_DWORD *)v43 + 5);
    v56[4] = v44;
    v56[5] = v45;
    if ( v34 )
      v52[v29] = v34;
    else
      v52[v67] = sub_458540(this[4], (int)v56);
    v29 = v67 + 2;
    v67 += 2;
    if ( v67 < 6 )
    {
      v27 = v52;
      continue;
    }
    break;
  }
  for ( j = 0; j < 6; ++j )
  {
    result = (int)v52[j];
    v48 = *(_DWORD *)(result + 32);
    if ( v48 < 0xB )
      *(_DWORD *)(result + 4 * v48 + 36) = v52;
    ++*(_DWORD *)(result + 32);
  }
  if ( a6 )
  {
    result = 0;
    v49 = v52 + 1;
    do
    {
      v50 = *(double *)(a6 + 8 * result++);
      *(double *)(*v49 + 24) = v50;
      v49 += 2;
    }
    while ( result < 3 );
  }
  return result;
}
