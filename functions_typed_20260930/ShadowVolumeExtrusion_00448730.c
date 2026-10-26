void __fastcall sub_448730(int a1)
{
  unsigned int v1; // eax
  unsigned int v2; // ebp
  int *v3; // eax
  int v4; // edx
  int v5; // eax
  int *v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // ebx
  float v10; // ecx
  double v11; // st7
  float v12; // eax
  double v13; // st5
  int v14; // eax
  float v15; // ecx
  double v16; // st4
  long double v17; // st7
  unsigned __int8 v18; // al
  unsigned int i; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  unsigned int v25; // esi
  _DWORD *v26; // ecx
  unsigned int v27; // eax
  _DWORD *v28; // edx
  int v29; // eax
  int v30; // edx
  int v31; // edx
  _DWORD *v32; // eax
  bool v33; // zf
  long double v34; // st7
  int *v35; // esi
  unsigned int v36; // ebx
  int v37; // eax
  int v38; // edi
  int v39; // edx
  double v40; // st6
  double v41; // st5
  double v42; // st4
  double v43; // st3
  double v44; // st2
  long double v45; // st1
  long double v46; // st1
  long double v47; // st6
  double v48; // [esp+10h] [ebp-370h]
  double v49; // [esp+10h] [ebp-370h]
  double v50; // [esp+10h] [ebp-370h]
  double v51; // [esp+10h] [ebp-370h]
  double v52; // [esp+10h] [ebp-370h]
  double v53; // [esp+18h] [ebp-368h]
  int v54; // [esp+18h] [ebp-368h]
  double v55; // [esp+18h] [ebp-368h]
  double v56; // [esp+20h] [ebp-360h]
  int v57; // [esp+28h] [ebp-358h]
  int v58; // [esp+2Ch] [ebp-354h]
  double v59; // [esp+30h] [ebp-350h]
  double v60; // [esp+38h] [ebp-348h]
  double v61; // [esp+40h] [ebp-340h]
  float v62; // [esp+48h] [ebp-338h]
  _BYTE v63[12]; // [esp+4Ch] [ebp-334h]
  double v64; // [esp+58h] [ebp-328h]
  double v65; // [esp+60h] [ebp-320h]
  int **v66; // [esp+6Ch] [ebp-314h]
  __int128 v67; // [esp+70h] [ebp-310h]
  double v68; // [esp+80h] [ebp-300h]
  float v69; // [esp+88h] [ebp-2F8h]
  _BYTE v70[12]; // [esp+8Ch] [ebp-2F4h]
  double v71; // [esp+A0h] [ebp-2E0h]
  double v72; // [esp+B0h] [ebp-2D0h]
  double v73; // [esp+B8h] [ebp-2C8h]
  _DWORD v74[2]; // [esp+C0h] [ebp-2C0h] BYREF
  int v75; // [esp+C8h] [ebp-2B8h] BYREF
  _DWORD v76[173]; // [esp+CCh] [ebp-2B4h] BYREF

  v1 = *(_DWORD *)(a1 + 24);
  LODWORD(v61) = a1;
  if ( v1 <= 0xB && v1 > 1 )
  {
    v2 = 0;
    v3 = &v75;
    v4 = 44;
    do
    {
      *(v3 - 2) = 0;
      *(v3 - 1) = 0;
      *v3 = 0;
      v3[1] = 0;
      v3 += 4;
      --v4;
    }
    while ( v4 );
    v5 = *(_DWORD *)(a1 + 24);
    if ( v5 )
    {
      v66 = (int **)(a1 + 28);
      LODWORD(v65) = v5;
      do
      {
        v6 = *v66;
        v7 = **v66;
        v8 = (*v66)[2];
        v9 = (*v66)[4];
        *(_QWORD *)&v67 = *(_QWORD *)v7;
        v10 = *(float *)(v7 + 12);
        DWORD2(v67) = *(_DWORD *)(v7 + 8);
        *((float *)&v67 + 3) = v10;
        v69 = *(float *)v8;
        v11 = *(float *)&v67 - v69;
        *(_DWORD *)v70 = *(_DWORD *)(v8 + 4);
        v12 = *(float *)(v8 + 12);
        *(_DWORD *)&v70[4] = *(_DWORD *)(v8 + 8);
        *(float *)&v70[8] = v12;
        v13 = v10 - v12;
        v62 = *(float *)v9;
        *(_DWORD *)v63 = *(_DWORD *)(v9 + 4);
        v14 = *(_DWORD *)(v9 + 8);
        v71 = v62 - v69;
        v15 = *(float *)(v9 + 12);
        *(_DWORD *)&v63[4] = v14;
        *(float *)&v63[8] = v15;
        v56 = *(double *)v63 - *(double *)v70;
        v16 = v15 - *(float *)&v70[8];
        v48 = v16 * (*(double *)((char *)&v67 + 4) - *(double *)v70) - v56 * v13;
        v53 = v71 * v13 - v16 * v11;
        v17 = sqrt(
                (v11 * v56 - v71 * (*(double *)((char *)&v67 + 4) - *(double *)v70))
              * (v11 * v56 - v71 * (*(double *)((char *)&v67 + 4) - *(double *)v70))
              + v53 * v53
              + v48 * v48);
        if ( v17 > 0.0 && v53 / v17 >= 0.7 )
        {
          v18 = *((_BYTE *)v6 + 25);
          if ( v18 == 0xFF )
            v54 = *((unsigned __int16 *)v6 + 13);
          else
            v54 = v18;
          for ( i = 0; i < 6; ++i )
          {
            if ( v6[i] == LODWORD(v61) )
              break;
          }
          LODWORD(v56) = 4;
          switch ( i )
          {
            case 0u:
              v20 = v6[5];
              v57 = v6[1];
              v58 = v20;
              LODWORD(v56) = 2;
              break;
            case 1u:
              v21 = v6[3];
              v22 = v6[5];
              v57 = v8;
              HIDWORD(v59) = v7;
              goto LABEL_22;
            case 2u:
              v23 = v6[1];
              v57 = v6[3];
              v58 = v23;
              LODWORD(v56) = 2;
              break;
            case 3u:
              v21 = v6[5];
              v22 = v6[1];
              v57 = v9;
              HIDWORD(v59) = v8;
              goto LABEL_22;
            case 4u:
              v24 = v6[3];
              v57 = v6[5];
              v58 = v24;
              LODWORD(v56) = 2;
              break;
            case 5u:
              v21 = v6[1];
              v22 = v6[3];
              v57 = v7;
              HIDWORD(v59) = v9;
LABEL_22:
              v58 = v21;
              LODWORD(v59) = v22;
              break;
            default:
              break;
          }
          v25 = 0;
          v26 = &v74[4 * v2 + 1];
          do
          {
            v27 = 0;
            if ( v2 )
            {
              v28 = v74;
              do
              {
                if ( v28[1] == *(&v57 + v25) && *v28 == v54 )
                  break;
                ++v27;
                v28 += 4;
              }
              while ( v27 < v2 );
            }
            if ( v27 == v2 )
            {
              *v26 = *(&v57 + v25);
              ++v2;
              v26 += 4;
            }
            v29 = 4 * v27;
            v30 = v76[v29 - 1];
            v74[v29] = v54;
            if ( !v30 && v25 )
              v76[v29 - 1] = *((_DWORD *)&v56 + v25 + 1);
            v31 = v76[v29];
            v32 = &v76[v29];
            if ( !v31 && v25 < LODWORD(v56) - 1 )
              *v32 = *(&v58 + v25);
            ++v25;
          }
          while ( v25 < LODWORD(v56) );
        }
        v33 = LODWORD(v65) == 1;
        ++v66;
        --LODWORD(v65);
      }
      while ( !v33 );
      a1 = LODWORD(v61);
    }
    v34 = 0.0;
    if ( v2 )
    {
      v35 = v76;
      v36 = v2;
      do
      {
        v37 = *v35;
        v38 = *(v35 - 2);
        v39 = *(v35 - 1);
        if ( *v35 && v39 )
        {
          *(double *)&v67 = *(float *)v38 - *(float *)a1;
          *((double *)&v67 + 1) = *(double *)(v38 + 4) - *(double *)(a1 + 4);
          v68 = *(float *)(v38 + 12) - *(float *)(a1 + 12);
          v40 = *(float *)v37 - *(float *)a1;
          v59 = *(double *)(v37 + 4) - *(double *)(a1 + 4);
          v60 = *(float *)(v37 + 12) - *(float *)(a1 + 12);
          v41 = *(float *)v39 - *(float *)a1;
          v72 = *(double *)(v39 + 4) - *(double *)(a1 + 4);
          v73 = *(float *)(v39 + 12) - *(float *)(a1 + 12);
          v49 = *((double *)&v67 + 1) * 0.0;
          v42 = v49 - v68;
          *(double *)&v63[4] = v68 * 0.0 - *(double *)&v67 * 0.0;
          v64 = *(double *)&v67 - v49;
          v43 = *(double *)&v63[4] * v68 - v64 * *((double *)&v67 + 1);
          *(double *)&v70[4] = v64 * *(double *)&v67 - v68 * (v49 - v68);
          v44 = *((double *)&v67 + 1) * (v49 - v68) - *(double *)&v63[4] * *(double *)&v67;
          v50 = v64 * v64 + *(double *)&v63[4] * *(double *)&v63[4] + v42 * v42;
          if ( v50 > 0.0 )
          {
            v45 = 1.0 / sqrt(v50);
            v42 = v42 * v45;
            *(double *)&v63[4] = *(double *)&v63[4] * v45;
            v64 = v64 * v45;
          }
          v51 = v44 * v44 + v43 * v43 + *(double *)&v70[4] * *(double *)&v70[4];
          if ( v51 > 0.0 )
          {
            v46 = 1.0 / sqrt(v51);
            v43 = v43 * v46;
            *(double *)&v70[4] = *(double *)&v70[4] * v46;
            v44 = v44 * v46;
          }
          v61 = v60 * v64 + v59 * *(double *)&v63[4] + v40 * v42;
          v55 = v60 * v44 + v59 * *(double *)&v70[4] + v43 * v40;
          v65 = v73 * v64 + v72 * *(double *)&v63[4] + v41 * v42;
          v52 = v73 * v44 + v72 * *(double *)&v70[4] + v43 * v41;
          if ( (v61 > 0.0 || v65 > 0.0) && (v61 < 0.0 || v65 < 0.0) )
          {
            v47 = fabs(atan2(v55 / v61, 1.0) - atan2(v52 / v65, 1.0));
            if ( v47 <= 0.15 )
              v34 = v34
                  + (v61 / (v61 - v65) * (v52 - v55) + v55) / *(double *)&v70[4] * (1.0 - v47 * 6.666666666666667) * 0.5;
          }
        }
        v35 += 4;
        --v36;
      }
      while ( v36 );
      if ( v34 > 0.025 )
      {
        *(double *)(a1 + 16) = *(double *)(a1 + 4) + 0.025;
        return;
      }
      if ( v34 < -0.025 )
        v34 = -0.025;
    }
    *(long double *)(a1 + 16) = v34 + *(double *)(a1 + 4);
  }
}

