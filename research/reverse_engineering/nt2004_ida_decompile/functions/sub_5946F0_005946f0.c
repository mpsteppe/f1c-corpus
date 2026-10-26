float *__thiscall sub_5946F0(float *this)
{
  float *v1; // edi
  int v2; // ecx
  _DWORD *i; // ebp
  int v4; // esi
  int v5; // eax
  int v6; // ebx
  int v7; // edi
  float *v8; // eax
  double v9; // st7
  int v10; // edx
  int v11; // ebx
  bool v12; // cc
  double v13; // st7
  _BYTE *v14; // esi
  float *v15; // eax
  int v16; // ebx
  _DWORD *v17; // ecx
  int v18; // edx
  int v19; // ecx
  _DWORD *j; // edi
  int v21; // esi
  int v22; // eax
  int v23; // ebp
  int v24; // ebx
  _BYTE *v25; // eax
  int v26; // edx
  int v27; // esi
  _DWORD *v28; // ecx
  int v29; // eax
  int v30; // ebp
  int v31; // ebx
  float *v32; // eax
  double v33; // st5
  double v34; // st3
  double v35; // st4
  double v36; // st3
  long double v37; // st4
  int *v38; // esi
  float *result; // eax
  int v40; // edx
  int v41; // ecx
  int v42; // esi
  float *v43; // ebx
  double v44; // st7
  float *v45; // ebp
  double v46; // st6
  int v47; // edx
  float *v48; // ecx
  double v49; // st5
  double v50; // st4
  double v51; // st7
  long double v52; // st6
  long double v53; // st7
  bool v54; // zf
  int v55; // [esp+10h] [ebp-1F0h]
  int v56; // [esp+10h] [ebp-1F0h]
  float v57; // [esp+10h] [ebp-1F0h]
  int v58; // [esp+10h] [ebp-1F0h]
  float *v59; // [esp+14h] [ebp-1ECh]
  float v60; // [esp+14h] [ebp-1ECh]
  _DWORD *v61; // [esp+14h] [ebp-1ECh]
  float v62; // [esp+14h] [ebp-1ECh]
  float v63; // [esp+14h] [ebp-1ECh]
  int v64; // [esp+18h] [ebp-1E8h]
  int v65; // [esp+18h] [ebp-1E8h]
  float v66; // [esp+18h] [ebp-1E8h]
  int k; // [esp+18h] [ebp-1E8h]
  int v68; // [esp+18h] [ebp-1E8h]
  int v69; // [esp+1Ch] [ebp-1E4h]
  float v70; // [esp+1Ch] [ebp-1E4h]
  float v71; // [esp+1Ch] [ebp-1E4h]
  _DWORD *v72; // [esp+1Ch] [ebp-1E4h]
  float v73; // [esp+20h] [ebp-1E0h] BYREF
  float v74; // [esp+24h] [ebp-1DCh]
  float v75; // [esp+28h] [ebp-1D8h]
  double v76; // [esp+30h] [ebp-1D0h]
  double v77; // [esp+38h] [ebp-1C8h]
  double v78; // [esp+40h] [ebp-1C0h]
  double v79; // [esp+48h] [ebp-1B8h]
  double v80; // [esp+50h] [ebp-1B0h]
  double v81; // [esp+58h] [ebp-1A8h]
  double v82; // [esp+60h] [ebp-1A0h]
  long double v83; // [esp+68h] [ebp-198h]
  double v84; // [esp+78h] [ebp-188h]
  float v85[16]; // [esp+80h] [ebp-180h] BYREF
  _BYTE v86[16]; // [esp+C0h] [ebp-140h] BYREF
  int v87; // [esp+D0h] [ebp-130h]
  _DWORD v88[17]; // [esp+D4h] [ebp-12Ch] BYREF
  double v89; // [esp+118h] [ebp-E8h] BYREF
  double v90; // [esp+120h] [ebp-E0h]
  double v91; // [esp+128h] [ebp-D8h]
  double v92; // [esp+130h] [ebp-D0h]
  double v93; // [esp+138h] [ebp-C8h]
  double v94; // [esp+140h] [ebp-C0h]
  double v95; // [esp+148h] [ebp-B8h]
  double v96; // [esp+150h] [ebp-B0h]
  long double v97; // [esp+158h] [ebp-A8h]
  double v98[9]; // [esp+160h] [ebp-A0h] BYREF
  long double v99[3]; // [esp+1A8h] [ebp-58h] BYREF
  _BYTE v100[64]; // [esp+1C0h] [ebp-40h] BYREF

  v1 = this;
  v2 = *((_DWORD *)this + 59);
  v59 = v1;
  v69 = 0;
  v83 = 0.0;
  v77 = 0.0;
  v84 = 0.0;
  v78 = 0.0;
  v81 = 0.0;
  v80 = 0.0;
  v76 = 0.0;
  v82 = 0.0;
  v79 = 0.0;
  v55 = v2;
  if ( v2 )
  {
    while ( 1 )
    {
      for ( i = *(_DWORD **)(v2 + 516); i; i = (_DWORD *)i[4] )
      {
        v64 = 0;
        if ( (int)i[70] > 0 )
        {
          v4 = 0;
          do
          {
            v5 = i[71];
            v6 = 0;
            if ( *(int *)(v5 + v4 + 8) > 0 )
            {
              v7 = 0;
              do
              {
                v8 = (float *)(v7 + *(_DWORD *)(v5 + v4 + 12));
                if ( (*(_BYTE *)(v2 + 60) & 0x10) != 0 )
                {
                  (*(void (__cdecl **)(int, float *, _BYTE *, int))(*(_DWORD *)dword_7E8E58 + 4))(
                    dword_7E8E58,
                    v8,
                    v86,
                    v2 + 416);
                  v2 = v55;
                  v8 = (float *)v86;
                }
                ++v6;
                v7 += 48;
                v80 = *v8 * *v8 + v80;
                v84 = v8[1] * v8[1] + v84;
                v83 = v8[2] * v8[2] + v83;
                v81 = *v8 * v8[1] + v81;
                v78 = *v8 * v8[2] + v78;
                v77 = v8[1] * v8[2] + v77;
                v79 = *v8 + v79;
                v82 = v8[1] + v82;
                v9 = v8[2];
                v5 = i[71];
                v10 = *(_DWORD *)(v5 + v4 + 8);
                v76 = v9 + v76;
              }
              while ( v6 < v10 );
              v1 = v59;
            }
            v11 = *(_DWORD *)(i[71] + v4 + 8) + v69;
            v4 += 64;
            v12 = v64 + 1 < i[70];
            v69 = v11;
            ++v64;
          }
          while ( v12 );
        }
      }
      v55 = *(_DWORD *)(v2 + 76);
      if ( !v55 )
        break;
      v2 = *(_DWORD *)(v2 + 76);
    }
  }
  v13 = 1.0 / (double)v69;
  v76 = v13 * v76;
  v78 = v13 * v78 - v76 * (v79 * v13);
  v77 = v13 * v77 - v76 * (v13 * v82);
  v94 = v77;
  v89 = v13 * v80 - v79 * v13 * (v79 * v13);
  v90 = v13 * v81 - v13 * v82 * (v79 * v13);
  v91 = v78;
  v92 = v90;
  v93 = v13 * v84 - v13 * v82 * (v13 * v82);
  v95 = v78;
  v96 = v77;
  v97 = v13 * v83 - v76 * v76;
  sub_590A80(&v89, v99, v98);
  v85[0] = v98[0];
  v85[3] = 0.0;
  v85[7] = 0.0;
  v85[1] = v98[3];
  memset(&v85[11], 0, 16);
  v85[2] = v98[6];
  v85[4] = v98[1];
  v85[15] = 1.0;
  v14 = v100;
  v85[5] = v98[4];
  v15 = v85;
  v16 = 4;
  v85[6] = v98[7];
  v85[8] = v98[2];
  v85[9] = v98[5];
  v85[10] = v98[8];
  do
  {
    v17 = v14;
    v18 = 4;
    do
    {
      *v17 = *(_DWORD *)v15;
      v17 += 4;
      ++v15;
      --v18;
    }
    while ( v18 );
    v14 += 4;
    --v16;
  }
  while ( v16 );
  v19 = *((_DWORD *)v1 + 59);
  v79 = 9.99999995904e11;
  v81 = 9.99999995904e11;
  v77 = 9.99999995904e11;
  v82 = -9.99999995904e11;
  v80 = -9.99999995904e11;
  v78 = -9.99999995904e11;
  v83 = 0.0;
  v56 = v19;
  if ( v19 )
  {
    while ( 1 )
    {
      for ( j = *(_DWORD **)(v19 + 516); j; j = (_DWORD *)j[4] )
      {
        v65 = 0;
        if ( (int)j[70] > 0 )
        {
          v21 = 0;
          do
          {
            v22 = j[71];
            v23 = 0;
            if ( *(int *)(v21 + v22 + 8) > 0 )
            {
              v24 = 0;
              do
              {
                v25 = (_BYTE *)(v24 + *(_DWORD *)(v21 + v22 + 12));
                if ( (*(_BYTE *)(v19 + 60) & 0x10) != 0 )
                {
                  (*(void (__cdecl **)(int, _BYTE *, _BYTE *, int))(*(_DWORD *)dword_7E8E58 + 4))(
                    dword_7E8E58,
                    v25,
                    v86,
                    v19 + 416);
                  v25 = v86;
                }
                (*(void (__cdecl **)(int, _BYTE *, float *, _BYTE *))(*(_DWORD *)dword_7E8E58 + 4))(
                  dword_7E8E58,
                  v25,
                  &v73,
                  v100);
                if ( v73 < v77 )
                  v77 = v73;
                if ( v73 > v78 )
                  v78 = v73;
                if ( v74 < v81 )
                  v81 = v74;
                if ( v74 > v80 )
                  v80 = v74;
                if ( v75 < v79 )
                  v79 = v75;
                if ( v75 > v82 )
                  v82 = v75;
                v22 = j[71];
                ++v23;
                v24 += 48;
                v19 = v56;
              }
              while ( v23 < *(_DWORD *)(v21 + v22 + 8) );
            }
            v21 += 64;
            ++v65;
          }
          while ( v65 < j[70] );
        }
      }
      v56 = *(_DWORD *)(v19 + 76);
      if ( !v56 )
        break;
      v19 = *(_DWORD *)(v19 + 76);
    }
    v1 = v59;
  }
  v66 = v78;
  v73 = v66;
  v70 = v81;
  v74 = v70;
  v60 = v79;
  v75 = v60;
  (*(void (__cdecl **)(int, float *, _DWORD *, float *))(*(_DWORD *)dword_7E8E58 + 4))(
    dword_7E8E58,
    &v73,
    (_DWORD *)v1 + 7,
    v85);
  v57 = v82;
  v75 = v57;
  v74 = v70;
  v73 = v66;
  (*(void (__cdecl **)(int, float *, _DWORD *, float *))(*(_DWORD *)dword_7E8E58 + 4))(
    dword_7E8E58,
    &v73,
    (_DWORD *)v1 + 10,
    v85);
  *(float *)&v76 = v77;
  v73 = *(float *)&v76;
  v74 = v70;
  v75 = v57;
  (*(void (__cdecl **)(int, float *, _DWORD *, float *))(*(_DWORD *)dword_7E8E58 + 4))(
    dword_7E8E58,
    &v73,
    (_DWORD *)v1 + 13,
    v85);
  v75 = v60;
  v73 = *(float *)&v76;
  v74 = v70;
  (*(void (__cdecl **)(int, float *, _DWORD *, float *))(*(_DWORD *)dword_7E8E58 + 4))(
    dword_7E8E58,
    &v73,
    (_DWORD *)v1 + 16,
    v85);
  v71 = v80;
  v74 = v71;
  v73 = v66;
  v75 = v60;
  (*(void (__cdecl **)(int, float *, _DWORD *, float *))(*(_DWORD *)dword_7E8E58 + 4))(
    dword_7E8E58,
    &v73,
    (_DWORD *)v1 + 19,
    v85);
  v75 = v57;
  v74 = v71;
  v73 = v66;
  (*(void (__cdecl **)(int, float *, _DWORD *, float *))(*(_DWORD *)dword_7E8E58 + 4))(
    dword_7E8E58,
    &v73,
    (_DWORD *)v1 + 22,
    v85);
  v75 = v57;
  v74 = v71;
  v73 = *(float *)&v76;
  (*(void (__cdecl **)(int, float *, _DWORD *, float *))(*(_DWORD *)dword_7E8E58 + 4))(
    dword_7E8E58,
    &v73,
    (_DWORD *)v1 + 25,
    v85);
  v75 = v60;
  v74 = v71;
  v73 = *(float *)&v76;
  (*(void (__cdecl **)(int, float *, _DWORD *, float *))(*(_DWORD *)dword_7E8E58 + 4))(
    dword_7E8E58,
    &v73,
    (_DWORD *)v1 + 28,
    v85);
  v73 = (v78 + v77) * 0.5;
  v74 = (v80 + v81) * 0.5;
  v75 = (v82 + v79) * 0.5;
  (*(void (__cdecl **)(int, float *, _DWORD *, float *))(*(_DWORD *)dword_7E8E58 + 4))(
    dword_7E8E58,
    &v73,
    (_DWORD *)v1 + 31,
    v85);
  v26 = *((_DWORD *)v1 + 59);
  v27 = 0;
  v58 = v26;
  if ( v26 )
  {
    while ( 1 )
    {
      v28 = *(_DWORD **)(v26 + 516);
      v61 = v28;
      if ( v28 )
      {
        while ( 1 )
        {
          for ( k = 0; k < v28[70]; ++k )
          {
            v29 = v28[71];
            v30 = 0;
            if ( *(int *)(v27 + v29 + 8) > 0 )
            {
              v31 = 0;
              do
              {
                v32 = (float *)(v31 + *(_DWORD *)(v27 + v29 + 12));
                if ( (*(_BYTE *)(v26 + 60) & 0x10) != 0 )
                {
                  (*(void (__cdecl **)(int, float *, _BYTE *, int))(*(_DWORD *)dword_7E8E58 + 4))(
                    dword_7E8E58,
                    v32,
                    v86,
                    v26 + 416);
                  v28 = v61;
                  v32 = (float *)v86;
                }
                v33 = v1[33] - v32[2];
                v34 = v1[32] - v32[1];
                v35 = v33 * v33 + v34 * v34;
                v36 = v1[31] - *v32;
                v37 = v35 + v36 * v36;
                if ( v83 <= v37 )
                  v83 = v37;
                v29 = v28[71];
                ++v30;
                v31 += 48;
                v26 = v58;
              }
              while ( v30 < *(_DWORD *)(v27 + v29 + 8) );
            }
            v27 += 64;
          }
          v27 = 0;
          v61 = (_DWORD *)v28[4];
          if ( !v61 )
            break;
          v28 = (_DWORD *)v28[4];
        }
      }
      v58 = *(_DWORD *)(v26 + 76);
      if ( !v58 )
        break;
      v26 = *(_DWORD *)(v26 + 76);
    }
  }
  v87 = 0;
  v88[6] = 3;
  v88[8] = 3;
  v88[9] = 0;
  v88[16] = 0;
  v38 = v88;
  v88[3] = 2;
  v88[5] = 2;
  v88[14] = 2;
  v88[0] = 1;
  v88[1] = 5;
  v88[2] = 1;
  v88[4] = 6;
  v88[7] = 7;
  v88[10] = 4;
  v88[11] = 7;
  v88[12] = 4;
  v88[13] = 5;
  v88[15] = 1;
  v72 = v88;
  result = v1 + 35;
  v68 = 6;
  v1[6] = sqrt(v83);
  do
  {
    v40 = *v38;
    v41 = *(v38 - 1);
    v42 = v38[1];
    v43 = &v1[3 * v40];
    v44 = v43[7] - v1[3 * v41 + 7];
    v45 = &v1[3 * v41];
    v46 = v43[8] - v45[8];
    v47 = 3 * v40 + 9;
    v48 = &v1[3 * v41 + 9];
    v49 = v1[v47] - *v48;
    *(float *)&v83 = v1[3 * v42 + 7] - v43[7];
    *((float *)&v83 + 1) = v1[3 * v42 + 8] - v43[8];
    v50 = v1[3 * v42 + 9] - v1[v47];
    v62 = v50 * v46 - *((float *)&v83 + 1) * v49;
    *(float *)&v76 = *(float *)&v83 * v49 - v50 * v44;
    v51 = v44 * *((float *)&v83 + 1) - *(float *)&v83 * v46;
    v52 = 1.0 / sqrt(v51 * v51 + *(float *)&v76 * *(float *)&v76 + v62 * v62);
    v63 = v62 * v52;
    *(result - 1) = v63;
    *(float *)&v76 = *(float *)&v76 * v52;
    *result = *(float *)&v76;
    v53 = v51 * v52;
    result[1] = v53;
    v38 = v72 + 3;
    result += 4;
    v54 = v68 == 1;
    v72 += 3;
    --v68;
    *(result - 2) = -(v63 * v45[7]) - *(float *)&v76 * v45[8] - v53 * *v48;
  }
  while ( !v54 );
  return result;
}
