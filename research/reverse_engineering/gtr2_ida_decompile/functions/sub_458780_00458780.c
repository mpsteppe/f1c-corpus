void __fastcall sub_458780(int a1)
{
  int v1; // ebp
  unsigned int v2; // eax
  unsigned int v3; // ebx
  int v4; // eax
  unsigned int *v5; // ecx
  unsigned int v6; // edx
  float v7; // esi
  unsigned int v8; // esi
  double v9; // st7
  double v10; // st5
  unsigned int v11; // edi
  int v12; // ebp
  int v13; // eax
  double v14; // st4
  long double v15; // st7
  int v16; // eax
  unsigned int i; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // edx
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // edx
  int v26; // edi
  _DWORD *v27; // ebp
  unsigned int v28; // eax
  _DWORD *v29; // ecx
  int v30; // eax
  int v31; // ecx
  unsigned int v32; // ecx
  _DWORD *v33; // eax
  bool v34; // zf
  long double v35; // st7
  int *v36; // edx
  unsigned int v37; // edi
  int v38; // eax
  int v39; // esi
  int v40; // ecx
  double v41; // st6
  double v42; // st5
  double v43; // st6
  long double v44; // st5
  long double v45; // st4
  long double v46; // st3
  long double v47; // st2
  long double v48; // st0
  long double v49; // st1
  long double v50; // st1
  long double v51; // st6
  long double v52; // [esp+10h] [ebp-370h]
  double v53; // [esp+18h] [ebp-368h]
  double v54; // [esp+20h] [ebp-360h]
  double v55; // [esp+28h] [ebp-358h]
  long double v56; // [esp+30h] [ebp-350h]
  long double v57; // [esp+38h] [ebp-348h]
  long double v58; // [esp+40h] [ebp-340h]
  float v59; // [esp+48h] [ebp-338h]
  int v60; // [esp+4Ch] [ebp-334h]
  long double v61; // [esp+50h] [ebp-330h]
  long double v62; // [esp+58h] [ebp-328h]
  long double v63; // [esp+60h] [ebp-320h]
  unsigned int **v64; // [esp+6Ch] [ebp-314h]
  double v65; // [esp+70h] [ebp-310h]
  double v66; // [esp+78h] [ebp-308h]
  double v67; // [esp+80h] [ebp-300h]
  float v68; // [esp+88h] [ebp-2F8h]
  int v69; // [esp+8Ch] [ebp-2F4h]
  long double v70; // [esp+90h] [ebp-2F0h]
  float v71; // [esp+98h] [ebp-2E8h]
  int v72; // [esp+9Ch] [ebp-2E4h]
  double v73; // [esp+A0h] [ebp-2E0h]
  double v74; // [esp+A8h] [ebp-2D8h]
  double v75; // [esp+B0h] [ebp-2D0h]
  _DWORD v76[3]; // [esp+C0h] [ebp-2C0h] BYREF
  _DWORD v77[173]; // [esp+CCh] [ebp-2B4h] BYREF

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 32);
  LODWORD(v58) = a1;
  if ( v2 <= 0xB && v2 > 1 )
  {
    v3 = 0;
    sub_41D1B0((int)v76, 16, 44, (int)sub_458470);
    v4 = *(_DWORD *)(v1 + 32);
    if ( v4 )
    {
      v64 = (unsigned int **)(v1 + 36);
      LODWORD(v63) = v4;
      do
      {
        v5 = *v64;
        v6 = **v64;
        v68 = *(float *)v6;
        v69 = *(_DWORD *)(v6 + 4);
        v70 = *(double *)(v6 + 8);
        v7 = *(float *)(v6 + 16);
        v72 = *(_DWORD *)(v6 + 20);
        v71 = v7;
        v8 = v5[2];
        v59 = *(float *)v8;
        v9 = v68 - v59;
        v60 = *(_DWORD *)(v8 + 4);
        v61 = *(double *)(v8 + 8);
        v62 = *(double *)(v8 + 16);
        v10 = v71 - *(float *)&v62;
        v11 = v5[4];
        v65 = *(double *)v11;
        v12 = *(_DWORD *)(v11 + 8);
        v73 = *(float *)&v65 - v59;
        LODWORD(v66) = v12;
        HIDWORD(v66) = *(_DWORD *)(v11 + 12);
        LODWORD(v67) = *(_DWORD *)(v11 + 16);
        v13 = *(_DWORD *)(v11 + 20);
        v57 = v66 - v61;
        HIDWORD(v67) = v13;
        v14 = *(float *)&v67 - *(float *)&v62;
        v52 = v14 * (v70 - v61) - v57 * v10;
        v56 = v73 * v10 - v14 * v9;
        v15 = sqrt((v9 * v57 - v73 * (v70 - v61)) * (v9 * v57 - v73 * (v70 - v61)) + v56 * v56 + v52 * v52);
        if ( v15 > 0.0 && v56 / v15 >= 0.7 )
        {
          LOBYTE(v16) = *((_BYTE *)v5 + 25);
          if ( (_BYTE)v16 == 0xFF )
            v16 = *((unsigned __int16 *)v5 + 13);
          else
            v16 = (unsigned __int8)v16;
          LODWORD(v56) = v16;
          for ( i = 0; i < 6; ++i )
          {
            if ( v5[i] == LODWORD(v58) )
              break;
          }
          LODWORD(v57) = 4;
          switch ( i )
          {
            case 0u:
              v18 = v5[5];
              LODWORD(v53) = v5[1];
              HIDWORD(v53) = v18;
              LODWORD(v57) = 2;
              break;
            case 1u:
              v19 = v5[3];
              v20 = v5[5];
              v53 = COERCE_DOUBLE(__PAIR64__(v19, v8));
              v54 = COERCE_DOUBLE(__PAIR64__(v6, v20));
              break;
            case 2u:
              v21 = v5[1];
              LODWORD(v53) = v5[3];
              HIDWORD(v53) = v21;
              LODWORD(v57) = 2;
              break;
            case 3u:
              v22 = v5[5];
              v23 = v5[1];
              LODWORD(v53) = v11;
              HIDWORD(v54) = v8;
              goto LABEL_20;
            case 4u:
              v24 = v5[3];
              LODWORD(v53) = v5[5];
              HIDWORD(v53) = v24;
              LODWORD(v57) = 2;
              break;
            case 5u:
              v23 = v5[3];
              LODWORD(v53) = v6;
              v22 = v5[1];
              HIDWORD(v54) = v11;
LABEL_20:
              HIDWORD(v53) = v22;
              LODWORD(v54) = v23;
              break;
            default:
              break;
          }
          v25 = 0;
          v26 = LODWORD(v56);
          v27 = &v76[4 * v3 + 1];
          do
          {
            v28 = 0;
            if ( v3 )
            {
              v29 = v76;
              do
              {
                if ( v29[1] == *((_DWORD *)&v53 + v25) && *v29 == v26 )
                  break;
                ++v28;
                v29 += 4;
              }
              while ( v28 < v3 );
            }
            if ( v28 == v3 )
            {
              *v27 = *((_DWORD *)&v53 + v25);
              ++v3;
              v27 += 4;
            }
            v30 = 4 * v28;
            v31 = v76[v30 + 2];
            v76[v30] = v26;
            if ( !v31 && v25 )
              v76[v30 + 2] = *((_DWORD *)&v52 + v25 + 1);
            v32 = v77[v30];
            v33 = &v77[v30];
            if ( __PAIR64__(v32, v25) < (unsigned int)(LODWORD(v57) - 1) )
              *v33 = *((_DWORD *)&v53 + v25 + 1);
            ++v25;
          }
          while ( v25 < LODWORD(v57) );
        }
        v34 = LODWORD(v63) == 1;
        ++v64;
        --LODWORD(v63);
      }
      while ( !v34 );
      v1 = LODWORD(v58);
    }
    v35 = 0.0;
    if ( v3 )
    {
      v36 = v77;
      v37 = v3;
      do
      {
        v38 = *v36;
        v39 = *(v36 - 2);
        v40 = *(v36 - 1);
        if ( *v36 && v40 )
        {
          v41 = *(float *)v1;
          v53 = *(float *)v39 - v41;
          v54 = *(double *)(v39 + 8) - *(double *)(v1 + 8);
          v42 = *(float *)(v1 + 16);
          v55 = *(float *)(v39 + 16) - v42;
          v65 = *(float *)v38 - v41;
          v66 = *(double *)(v38 + 8) - *(double *)(v1 + 8);
          v67 = *(float *)(v38 + 16) - v42;
          v74 = *(float *)v40 - v41;
          v75 = *(double *)(v40 + 8) - *(double *)(v1 + 8);
          v43 = *(float *)(v40 + 16) - v42;
          v52 = v54 * 0.0;
          v44 = v52 - v55;
          v61 = v55 * 0.0 - v53 * 0.0;
          v62 = v53 - v52;
          v45 = v61 * v55 - v62 * v54;
          v70 = v62 * v53 - v55 * (v52 - v55);
          v46 = v54 * (v52 - v55) - v61 * v53;
          v47 = v61;
          v52 = v62 * v62 + v61 * v61 + v44 * v44;
          if ( v52 > 0.0 )
          {
            v48 = 1.0 / sqrt(v52);
            v44 = v44 * v48;
            v47 = v61 * v48;
            v62 = v62 * v48;
          }
          v49 = v46 * v46 + v45 * v45 + v70 * v70;
          if ( v49 > 0.0 )
          {
            v50 = 1.0 / sqrt(v49);
            v45 = v45 * v50;
            v70 = v70 * v50;
            v46 = v46 * v50;
          }
          v58 = v62 * v67 + v47 * v66 + v44 * v65;
          v56 = v46 * v67 + v66 * v70 + v45 * v65;
          v63 = v62 * v43 + v47 * v75 + v44 * v74;
          v52 = v46 * v43 + v75 * v70 + v45 * v74;
          if ( (v58 > 0.0 || v63 > 0.0) && (v58 < 0.0 || v63 < 0.0) )
          {
            v51 = fabs(atan2(v56 / v58, 1.0) - atan2(v52 / v63, 1.0));
            if ( v51 <= 0.15 )
              v35 = v35 + (v58 / (v58 - v63) * (v52 - v56) + v56) / v70 * (1.0 - v51 * 6.666666666666667) * 0.5;
          }
        }
        v36 += 4;
        --v37;
      }
      while ( v37 );
      if ( v35 > 0.025 )
      {
        *(double *)(v1 + 24) = *(double *)(v1 + 8) + 0.025;
        return;
      }
      if ( v35 < -0.025 )
        v35 = -0.025;
    }
    *(long double *)(v1 + 24) = v35 + *(double *)(v1 + 8);
  }
}
