// f1c  0x0053b6f0  size=1068
void __stdcall sub_53B6F0(double *a1, long double *a2, _DWORD *a3)
{
  _DWORD *v3; // edx
  char *v4; // esi
  int v5; // ebx
  double *v6; // edx
  long double *v7; // ecx
  double *v8; // ebx
  int v9; // eax
  double v10; // st7
  double *v11; // esi
  long double v12; // st7
  int v13; // ebx
  int v14; // esi
  long double *v15; // edi
  int v16; // eax
  long double v17; // st6
  long double v18; // st7
  int v19; // eax
  long double *v20; // ebx
  int v21; // esi
  double *v22; // edx
  int v23; // eax
  char *v24; // ecx
  long double *v25; // edi
  long double v26; // st6
  long double v27; // st6
  long double v28; // st5
  long double v29; // st6
  long double v30; // st5
  long double v31; // st6
  double *v32; // ecx
  double *v33; // eax
  int v34; // edx
  double v35; // st6
  double v36; // st5
  int v37; // eax
  double *v38; // ecx
  double *v39; // edx
  int v40; // eax
  double v41; // st6
  double v42; // st5
  double *v43; // ecx
  double *v44; // eax
  int v45; // edx
  double v46; // st6
  double v47; // st5
  double *v48; // ecx
  double *v49; // eax
  int v50; // edx
  double v51; // st6
  double v52; // st5
  int j; // eax
  double v54; // st7
  double *v55; // esi
  int v56; // [esp+10h] [ebp-70h]
  double *v57; // [esp+14h] [ebp-6Ch]
  int i; // [esp+18h] [ebp-68h]
  int v59; // [esp+1Ch] [ebp-64h]
  int v60; // [esp+20h] [ebp-60h]
  int v61; // [esp+24h] [ebp-5Ch]
  char *v62; // [esp+28h] [ebp-58h]
  int v63; // [esp+2Ch] [ebp-54h]
  long double *v64; // [esp+30h] [ebp-50h]
  int v65; // [esp+34h] [ebp-4Ch]
  double *v66; // [esp+38h] [ebp-48h]
  double v67; // [esp+40h] [ebp-40h]
  double v68; // [esp+48h] [ebp-38h]
  long double v69; // [esp+48h] [ebp-38h]
  double v70; // [esp+48h] [ebp-38h]
  double v71[3]; // [esp+50h] [ebp-30h] BYREF
  double v72[3]; // [esp+68h] [ebp-18h] BYREF

  v3 = a3;
  v4 = (char *)a3;
  v5 = 3;
  do
  {
    memset(v4, 0, 0x18u);
    *v3 = 0;
    v3[1] = 1072693248;
    v4 += 24;
    v3 += 8;
    --v5;
  }
  while ( v5 );
  v6 = a1;
  memset(v71, 0, sizeof(v71));
  v7 = a2;
  v8 = a1;
  v9 = 0;
  do
  {
    v10 = *v8;
    v11 = &v72[v9++];
    *(double *)((char *)v11 + (char *)a2 - (char *)v72) = v10;
    v8 += 4;
    *v11 = v10;
  }
  while ( v9 < 3 );
  for ( i = 0; i < 50; ++i )
  {
    v12 = 0.0;
    v13 = 0;
    v14 = 1;
    do
    {
      if ( v14 < 3 )
      {
        v15 = &v6[v14 + v13];
        v16 = 3 - v14;
        do
        {
          v17 = *v15++;
          --v16;
          v12 = v12 + fabs(v17);
        }
        while ( v16 );
      }
      ++v14;
      v13 += 3;
    }
    while ( v14 - 1 < 2 );
    if ( v12 == 0.0 )
      break;
    v18 = i >= 4 ? 0.0 : v12 * 0.02222222222222222;
    v19 = 0;
    v20 = v7;
    v63 = 0;
    v21 = 1;
    v64 = v7;
    do
    {
      v59 = v21;
      if ( v21 < 3 )
      {
        v22 = &v6[v21 + v19];
        v62 = (char *)((char *)v71 - (char *)v7);
        v65 = (char *)a1 - (char *)v7;
        v60 = v19 + 3;
        v23 = (char *)a3 - (char *)v7;
        v24 = (char *)((char *)v71 - (char *)v7);
        v56 = v21 + 1;
        v25 = v20 + 1;
        v66 = v22;
        v57 = v22;
        v61 = v23;
        do
        {
          v26 = fabs(*v22);
          v68 = 100.0 * v26;
          if ( i > 4 && fabs(*v20) == fabs(v68 + *v20) && fabs(*v25) == fabs(v68 + *v25) )
          {
            *(_DWORD *)v22 = 0;
            *((_DWORD *)v22 + 1) = 0;
          }
          else if ( v26 > v18 )
          {
            v27 = *v25 - *v20;
            v28 = fabs(v27);
            if ( v68 + v28 == v28 )
            {
              v29 = *v22 / v27;
            }
            else
            {
              v69 = 0.5 / *v22 * v27;
              v29 = 1.0 / (sqrt(v69 * v69 + 1.0) + fabs(v69));
              if ( v69 < 0.0 )
                v29 = -v29;
            }
            v30 = 1.0 / sqrt(v29 * v29 + 1.0);
            v67 = v30 * v29;
            v70 = v67 / (v30 + 1.0);
            v31 = v29 * *v22;
            *(long double *)((char *)v20 + (_DWORD)v24) = *(double *)((char *)v20 + (_DWORD)v24) - v31;
            *(long double *)((char *)v25 + (_DWORD)v24) = v31 + *(double *)((char *)v25 + (_DWORD)v24);
            *v20 = *v20 - v31;
            *v25 = v31 + *v25;
            *(_DWORD *)v22 = 0;
            *((_DWORD *)v22 + 1) = 0;
            if ( v21 - 2 > 0 )
            {
              v32 = (long double *)((char *)v25 + v65);
              v33 = (long double *)((char *)v20 + v65);
              v34 = v21 - 2;
              do
              {
                v35 = *v33;
                v33 += 3;
                v36 = *v32;
                v32 += 3;
                --v34;
                *(v33 - 3) = v35 - (v70 * v35 + v36) * v67;
                *(v32 - 3) = (v35 - v70 * v36) * v67 + v36;
              }
              while ( v34 );
              v22 = v57;
            }
            v37 = v56;
            if ( v21 < v56 - 2 )
            {
              v38 = v66;
              v39 = &a1[2 * v21 + v59 + v21];
              v40 = v56 - v21 - 2;
              do
              {
                v41 = *v38++;
                v42 = *v39;
                v39 += 3;
                --v40;
                *(v38 - 1) = v41 - (v70 * v41 + v42) * v67;
                *(v39 - 3) = (v41 - v70 * v42) * v67 + v42;
              }
              while ( v40 );
              v22 = v57;
              v37 = v56;
            }
            if ( v37 < 3 )
            {
              v43 = &a1[v60 + v37];
              v44 = v22 + 1;
              v45 = 3 - v56;
              do
              {
                v46 = *v44++;
                v47 = *v43++;
                --v45;
                *(v44 - 1) = v46 - (v70 * v46 + v47) * v67;
                *(v43 - 1) = (v46 - v70 * v47) * v67 + v47;
              }
              while ( v45 );
              v20 = v64;
            }
            v48 = (long double *)((char *)v25 + v61);
            v49 = (long double *)((char *)v20 + v61);
            v50 = 3;
            do
            {
              v51 = *v49;
              v49 += 3;
              v52 = *v48;
              v48 += 3;
              --v50;
              *(v49 - 3) = v51 - (v70 * v51 + v52) * v67;
              *(v48 - 3) = (v51 - v70 * v52) * v67 + v52;
            }
            while ( v50 );
            v22 = v57;
            v24 = v62;
          }
          ++v59;
          ++v56;
          v60 += 3;
          ++v22;
          ++v25;
          v57 = v22;
        }
        while ( v56 < 4 );
        v6 = a1;
        v19 = v63;
        v7 = a2;
      }
      ++v21;
      v19 += 3;
      ++v20;
      v63 = v19;
      v64 = v20;
    }
    while ( v21 - 1 < 2 );
    for ( j = 0; j < 3; ++j )
    {
      v54 = v71[j] + v72[j];
      v55 = &v72[j];
      LODWORD(v71[j]) = 0;
      HIDWORD(v71[j]) = 0;
      *v55 = v54;
      *(double *)((char *)v55 + (char *)a2 - (char *)v72) = v54;
    }
  }
}
