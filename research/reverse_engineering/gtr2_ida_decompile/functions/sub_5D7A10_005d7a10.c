void __stdcall sub_5D7A10(double *a1, double *a2, int a3)
{
  _DWORD *v3; // eax
  double *v4; // ecx
  int v5; // edx
  double v6; // st6
  double v7; // st7
  double v8; // st7
  long double v9; // st7
  int v10; // esi
  int v11; // edx
  int v12; // ebx
  double *v13; // ecx
  unsigned int v14; // eax
  long double v15; // st6
  long double *v16; // ecx
  int v17; // eax
  long double v18; // st6
  long double v19; // st7
  long double *v20; // esi
  int v21; // ebx
  int v22; // edx
  long double *v23; // ecx
  char *v24; // ebx
  long double v25; // st6
  long double v26; // st6
  long double v27; // st4
  long double v28; // st6
  long double v29; // st5
  long double v30; // st6
  int v31; // ebx
  int v32; // esi
  double *v33; // ecx
  double *v34; // eax
  unsigned int v35; // edx
  double v36; // st6
  double v37; // st5
  double v38; // st6
  double v39; // st5
  double v40; // st6
  double v41; // st5
  double v42; // st6
  double v43; // st5
  double *v44; // ecx
  double *v45; // eax
  int v46; // ebx
  double v47; // st6
  double v48; // st5
  int v49; // eax
  int v50; // esi
  int v51; // eax
  int v52; // ecx
  unsigned int v53; // edx
  double *v54; // ecx
  double v55; // st6
  double v56; // st5
  double v57; // st6
  double v58; // st5
  double v59; // st6
  double v60; // st5
  double v61; // st6
  double v62; // st5
  double *v63; // ebx
  double *v64; // eax
  int v65; // ecx
  double v66; // st6
  double v67; // st5
  int v68; // esi
  int v69; // ecx
  long double *v70; // eax
  unsigned int v71; // edx
  double v72; // st6
  double v73; // st5
  double v74; // st6
  double v75; // st5
  double v76; // st6
  double v77; // st5
  double v78; // st6
  double v79; // st5
  int v80; // eax
  int v81; // ebx
  double *v82; // esi
  double *v83; // eax
  double v84; // st6
  double v85; // st5
  double v86; // st6
  double v87; // st5
  double v88; // st6
  double v89; // st5
  double v90; // st6
  double v91; // st5
  int i; // eax
  double *v93; // ecx
  double v94; // st7
  double v95; // [esp+10h] [ebp-88h]
  long double v96; // [esp+10h] [ebp-88h]
  double v97; // [esp+10h] [ebp-88h]
  double v98; // [esp+18h] [ebp-80h]
  int v99; // [esp+24h] [ebp-74h]
  int v100; // [esp+24h] [ebp-74h]
  long double *v101; // [esp+28h] [ebp-70h]
  int v102; // [esp+2Ch] [ebp-6Ch]
  int v103; // [esp+30h] [ebp-68h]
  long double *v104; // [esp+34h] [ebp-64h]
  int v105; // [esp+38h] [ebp-60h]
  int v106; // [esp+38h] [ebp-60h]
  int v107; // [esp+3Ch] [ebp-5Ch]
  double *v108; // [esp+40h] [ebp-58h]
  int v109; // [esp+44h] [ebp-54h]
  int v110; // [esp+48h] [ebp-50h]
  double *v111; // [esp+4Ch] [ebp-4Ch]
  int v112; // [esp+50h] [ebp-48h]
  int v113; // [esp+54h] [ebp-44h]
  long double *v114; // [esp+58h] [ebp-40h]
  char *v115; // [esp+5Ch] [ebp-3Ch]
  int v116; // [esp+60h] [ebp-38h]
  char *v117; // [esp+64h] [ebp-34h]
  double v118[3]; // [esp+68h] [ebp-30h] BYREF
  double v119[3]; // [esp+80h] [ebp-18h] BYREF

  v3 = (_DWORD *)a3;
  v4 = (double *)a3;
  v5 = 3;
  do
  {
    *v3 = 0;
    v3[1] = 0;
    v3[2] = 0;
    v3[3] = 0;
    v3[4] = 0;
    v3[5] = 0;
    *v4 = 1.0;
    v3 += 6;
    v4 += 4;
    --v5;
  }
  while ( v5 );
  v6 = *a1;
  v109 = 0;
  *a2 = v6;
  v119[0] = v6;
  v118[0] = 0.0;
  v7 = a1[4];
  a2[1] = v7;
  v119[1] = v7;
  v118[1] = 0.0;
  v8 = a1[8];
  a2[2] = v8;
  v119[2] = v8;
  v118[2] = 0.0;
  do
  {
    v9 = 0.0;
    v10 = 0;
    v11 = 1;
    v99 = 2;
    v105 = 2;
    do
    {
      v12 = v11;
      if ( v99 >= 4 )
      {
        v13 = &a1[v11 + v10];
        v14 = ((unsigned int)(-1 - v11) >> 2) + 1;
        v12 = v11 + 4 * v14;
        do
        {
          v15 = v13[1];
          v13 += 4;
          --v14;
          v9 = fabs(v15) + fabs(*(v13 - 4)) + v9 + fabs(*(v13 - 2)) + fabs(*(v13 - 1));
        }
        while ( v14 );
      }
      if ( v12 < 3 )
      {
        v16 = &a1[v10 + v12];
        v17 = 3 - v12;
        do
        {
          v18 = *v16++;
          --v17;
          v9 = v9 + fabs(v18);
        }
        while ( v17 );
      }
      --v99;
      ++v11;
      v10 += 3;
      --v105;
    }
    while ( v105 );
    if ( v9 == 0.0 )
      break;
    v19 = v109 >= 4 ? 0.0 : v9 * 0.02222222222222222;
    v20 = a2;
    v21 = 0;
    v22 = 1;
    v100 = 0;
    v107 = 1;
    v114 = a2;
    v108 = (double *)(a3 + 48);
    v113 = 2;
    do
    {
      v103 = v22;
      if ( v22 < 3 )
      {
        v102 = v22 + 1;
        v111 = v108 + 1;
        v106 = v113 - 1;
        v116 = v22 + v21;
        v101 = &a1[v22 + v21];
        v115 = (char *)a1 - a3;
        v112 = v21 + 3;
        v23 = v20 + 1;
        v24 = (char *)((char *)v118 - (char *)a2);
        v104 = v20 + 1;
        v117 = (char *)((char *)v118 - (char *)a2);
        do
        {
          v25 = fabs(*v101);
          v95 = 100.0 * v25;
          if ( v109 > 4 && fabs(*v20) == fabs(v95 + *v20) && fabs(*v23) == fabs(v95 + *v23) )
          {
            *v101 = 0.0;
          }
          else if ( v25 > v19 )
          {
            v26 = *v23 - *v20;
            v27 = fabs(v26);
            if ( v27 == v95 + v27 )
            {
              v28 = *v101 / v26;
            }
            else
            {
              v96 = v26 / *v101 * 0.5;
              v28 = 1.0 / (sqrt(v96 * v96 + 1.0) + fabs(v96));
              if ( v96 < 0.0 )
                v28 = -v28;
            }
            v29 = 1.0 / sqrt(v28 * v28 + 1.0);
            v98 = v29 * v28;
            v97 = v98 / (v29 + 1.0);
            v30 = v28 * *v101;
            *(long double *)&v24[(_DWORD)v20] = *(double *)&v24[(_DWORD)v20] - v30;
            *(long double *)&v24[(_DWORD)v23] = v30 + *(double *)&v24[(_DWORD)v23];
            v31 = v22 - 2;
            *v20 = *v20 - v30;
            v32 = 0;
            *v23 = v30 + *v23;
            *v101 = 0.0;
            if ( v22 - 2 >= 4 )
            {
              v33 = (double *)&v115[(_DWORD)v111];
              v34 = (double *)&v115[(_DWORD)v108];
              v35 = ((unsigned int)(v22 - 6) >> 2) + 1;
              v32 = 4 * v35;
              do
              {
                v36 = *(v34 - 6);
                v34 += 12;
                v37 = *(v33 - 6);
                v33 += 12;
                --v35;
                *(v34 - 18) = v36 - (v97 * v36 + v37) * v98;
                *(v33 - 18) = (v36 - v97 * v37) * v98 + v37;
                v38 = *(v34 - 15);
                v39 = *(v33 - 15);
                *(v34 - 15) = v38 - (v97 * v38 + v39) * v98;
                *(v33 - 15) = (v38 - v97 * v39) * v98 + v39;
                v40 = *(v34 - 12);
                v41 = *(v33 - 12);
                *(v34 - 12) = v40 - (v97 * v40 + v41) * v98;
                *(v33 - 12) = (v40 - v97 * v41) * v98 + v41;
                v42 = *(v34 - 9);
                v43 = *(v33 - 9);
                *(v34 - 9) = v42 - (v97 * v42 + v43) * v98;
                *(v33 - 9) = (v42 - v97 * v43) * v98 + v43;
              }
              while ( v35 );
              v22 = v107;
              v23 = v104;
            }
            if ( v32 < v31 )
            {
              v44 = &a1[3 * v32 + v103];
              v45 = &a1[3 * v32 - 1 + v22];
              v46 = v31 - v32;
              do
              {
                v47 = *v45;
                v45 += 3;
                v48 = *v44;
                v44 += 3;
                --v46;
                *(v45 - 3) = v47 - (v97 * v47 + v48) * v98;
                *(v44 - 3) = (v47 - v97 * v48) * v98 + v48;
              }
              while ( v46 );
              v23 = v104;
            }
            v49 = v102;
            v110 = v102 - 2;
            v50 = v22;
            if ( v102 + v113 - 5 >= 4 )
            {
              v51 = (int)&a1[v116 + 2];
              v52 = v22 + 2 + v103 + 2 * (v22 + 2);
              v53 = ((unsigned int)(v102 - v107 - 6) >> 2) + 1;
              v54 = &a1[v52];
              v50 = v107 + 4 * v53;
              do
              {
                v55 = *(double *)(v51 - 16);
                v51 += 32;
                v56 = *(v54 - 6);
                v54 += 12;
                --v53;
                *(double *)(v51 - 48) = v55 - (v97 * v55 + v56) * v98;
                *(v54 - 18) = (v55 - v97 * v56) * v98 + v56;
                v57 = *(double *)(v51 - 40);
                v58 = *(v54 - 15);
                *(double *)(v51 - 40) = v57 - (v97 * v57 + v58) * v98;
                *(v54 - 15) = (v57 - v97 * v58) * v98 + v58;
                v59 = *(double *)(v51 - 32);
                v60 = *(v54 - 12);
                *(double *)(v51 - 32) = v59 - (v97 * v59 + v60) * v98;
                *(v54 - 12) = (v59 - v97 * v60) * v98 + v60;
                v61 = *(double *)(v51 - 24);
                v62 = *(v54 - 9);
                *(double *)(v51 - 24) = v61 - (v97 * v61 + v62) * v98;
                *(v54 - 9) = (v61 - v97 * v62) * v98 + v62;
              }
              while ( v53 );
              v22 = v107;
              v23 = v104;
              v49 = v102;
            }
            if ( v50 < v110 )
            {
              v63 = &a1[2 * v50 + v50 + v103];
              v64 = &a1[v50 + v100];
              v65 = v110 - v50;
              do
              {
                v66 = *v64++;
                v67 = *v63;
                v63 += 3;
                --v65;
                *(v64 - 1) = v66 - (v97 * v66 + v67) * v98;
                *(v63 - 3) = (v66 - v97 * v67) * v98 + v67;
              }
              while ( v65 );
              v23 = v104;
              v49 = v102;
            }
            v68 = v49;
            if ( v106 >= 4 )
            {
              v69 = (int)&a1[v112 + 2 + v49];
              v70 = v101 + 3;
              v71 = ((unsigned int)(-1 - v102) >> 2) + 1;
              v68 = v102 + 4 * v71;
              do
              {
                v72 = *(v70 - 2);
                v70 += 4;
                v73 = *(double *)(v69 - 16);
                v69 += 32;
                --v71;
                *(v70 - 6) = v72 - (v97 * v72 + v73) * v98;
                *(double *)(v69 - 48) = (v72 - v97 * v73) * v98 + v73;
                v74 = *(v70 - 5);
                v75 = *(double *)(v69 - 40);
                *(v70 - 5) = v74 - (v97 * v74 + v75) * v98;
                *(double *)(v69 - 40) = (v74 - v97 * v75) * v98 + v75;
                v76 = *(v70 - 4);
                v77 = *(double *)(v69 - 32);
                *(v70 - 4) = v76 - (v97 * v76 + v77) * v98;
                *(double *)(v69 - 32) = (v76 - v97 * v77) * v98 + v77;
                v78 = *(v70 - 3);
                v79 = *(double *)(v69 - 24);
                *(v70 - 3) = v78 - (v97 * v78 + v79) * v98;
                *(double *)(v69 - 24) = (v78 - v97 * v79) * v98 + v79;
              }
              while ( v71 );
              v22 = v107;
              v23 = v104;
            }
            if ( v68 < 3 )
            {
              v80 = v68 + v100;
              v81 = 3 - v68;
              v82 = &a1[v68 + v112];
              v83 = &a1[v80];
              do
              {
                v84 = *v83++;
                v85 = *v82++;
                --v81;
                *(v83 - 1) = v84 - (v97 * v84 + v85) * v98;
                *(v82 - 1) = (v84 - v97 * v85) * v98 + v85;
              }
              while ( v81 );
            }
            v86 = *(v108 - 6);
            v87 = *(v111 - 6);
            v24 = v117;
            *(v108 - 6) = v86 - (v97 * v86 + v87) * v98;
            *(v111 - 6) = (v86 - v97 * v87) * v98 + v87;
            v88 = *(v108 - 3);
            v89 = *(v111 - 3);
            *(v108 - 3) = v88 - (v97 * v88 + v89) * v98;
            *(v111 - 3) = (v88 - v97 * v89) * v98 + v89;
            v90 = *v108;
            v91 = *v111;
            *v108 = v90 - (v97 * v90 + v91) * v98;
            *v111 = (v90 - v97 * v91) * v98 + v91;
            v20 = v114;
          }
          ++v103;
          --v106;
          ++v102;
          v112 += 3;
          ++v101;
          ++v111;
          v104 = ++v23;
        }
        while ( v103 < 3 );
        v21 = v100;
      }
      --v113;
      ++v22;
      ++v108;
      v21 += 3;
      ++v20;
      v107 = v22;
      v100 = v21;
      v114 = v20;
    }
    while ( v22 - 1 < 2 );
    for ( i = 0; i < 3; *(double *)((char *)&v116 + i * 8) = 0.0 )
    {
      v93 = &v119[i];
      v94 = v119[i] + v118[i];
      ++i;
      *v93 = v94;
      *(double *)((char *)v93 + (char *)a2 - (char *)v119) = v94;
    }
    ++v109;
  }
  while ( v109 < 50 );
}
