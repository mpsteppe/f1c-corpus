int __thiscall sub_44B370(void *this, int *a2, char **a3)
{
  int v3; // esi
  int v4; // edi
  int v5; // ecx
  float **v6; // esi
  int i; // eax
  float *v8; // edx
  double v9; // st7
  double v10; // st6
  int v11; // edx
  double v12; // st7
  double v13; // st6
  int v14; // esi
  char *v15; // ebx
  int v16; // edi
  int v17; // eax
  _DWORD *v18; // edx
  int v19; // eax
  _DWORD *v20; // edi
  int v21; // eax
  int v22; // ecx
  _DWORD *v23; // eax
  int v24; // eax
  int v25; // edx
  int v26; // ecx
  int v27; // eax
  bool v28; // zf
  char **v29; // ebx
  int *v30; // edi
  int v31; // eax
  int v32; // ecx
  float *v33; // ecx
  int n; // eax
  int v35; // edx
  double v36; // st7
  double v37; // st6
  double v38; // st5
  int v39; // edx
  int k; // esi
  float *v41; // ecx
  int m; // eax
  int v43; // edx
  double v44; // st7
  double v45; // st6
  double v46; // st5
  int v47; // edx
  int v48; // eax
  int v49; // eax
  float *v50; // ecx
  char *v51; // esi
  int v52; // edi
  float *v53; // edx
  double v54; // st7
  double v55; // st6
  int v56; // edx
  int v58; // [esp-8h] [ebp-270h]
  int v59; // [esp-4h] [ebp-26Ch]
  int v60; // [esp+10h] [ebp-258h]
  int v61; // [esp+10h] [ebp-258h]
  int v62; // [esp+10h] [ebp-258h]
  int v63; // [esp+10h] [ebp-258h]
  int v64; // [esp+14h] [ebp-254h] BYREF
  LPVOID v65[2]; // [esp+18h] [ebp-250h] BYREF
  int v66; // [esp+20h] [ebp-248h] BYREF
  int *v67; // [esp+24h] [ebp-244h]
  int j; // [esp+28h] [ebp-240h]
  char *v69[2]; // [esp+2Ch] [ebp-23Ch] BYREF
  _DWORD v70[3]; // [esp+34h] [ebp-234h]
  _DWORD v71[4]; // [esp+40h] [ebp-228h] BYREF
  _DWORD v72[4]; // [esp+50h] [ebp-218h] BYREF
  _DWORD v73[4]; // [esp+60h] [ebp-208h] BYREF
  double v74; // [esp+70h] [ebp-1F8h] BYREF
  double v75; // [esp+78h] [ebp-1F0h] BYREF
  double v76; // [esp+80h] [ebp-1E8h] BYREF
  double v77; // [esp+88h] [ebp-1E0h]
  double v78; // [esp+90h] [ebp-1D8h] BYREF
  double v79; // [esp+98h] [ebp-1D0h]
  _DWORD v81[6]; // [esp+D0h] [ebp-198h] BYREF
  int v82[4]; // [esp+E8h] [ebp-180h] BYREF
  char v83; // [esp+F8h] [ebp-170h] BYREF

  v65[1] = this;
  sub_4492B0(v69);
  v59 = 4 * *a2;
  v64 = *a2;
  v3 = v64;
  sub_4492D0(v69, v59);
  if ( v64 > 0 )
  {
    v4 = 0;
    v60 = v64;
    do
    {
      v5 = v4 + a2[2];
      v6 = (float **)v5;
      for ( i = 0; i < 12; *(float *)&v70[i + 2] = v12 )
      {
        v8 = *v6;
        v9 = (*v6)[3];
        i += 4;
        v10 = *((double *)*v6 + 2);
        v6 += 2;
        *(float *)&v73[i] = *v8;
        *(double *)&v73[i + 1] = v10;
        *(float *)&v73[i + 3] = v9;
        v11 = (int)*(v6 - 1);
        v12 = *(float *)(v11 + 12);
        v13 = *(double *)(v11 + 16);
        v69[i + 1] = *(char **)v11;
        *(double *)&v70[i] = v13;
      }
      sub_448EE0(v5, v65);
      sub_4493A0(v69, &v74, (int)v71, (int)v73, (int)v65, 0);
      sub_4493A0(v69, v71, (int)&v76, (int)v72, (int)v65, 0);
      sub_4493A0(v69, v73, (int)v72, (int)&v78, (int)v65, 0);
      sub_4493A0(v69, v72, (int)v73, (int)v71, (int)v65, 0);
      v4 += 32;
      --v60;
    }
    while ( v60 );
    v3 = v64;
  }
  sub_449700((int *)v69);
  sub_449340(a2);
  v65[0] = (LPVOID)sub_587C03(4 * v3);
  v61 = 0;
  if ( v3 > 0 )
  {
    do
    {
      v14 = 0;
      v15 = &v83;
      v16 = v61 << 7;
      do
      {
        v58 = v70[0] + v16;
        v82[v14] = v70[0] + v16;
        sub_449A80(v15, v58, 0);
        ++v14;
        v16 += 32;
        v15 += 92;
      }
      while ( v14 < 4 );
      v17 = sub_44B110(v82);
      v18 = v65[0];
      *((_DWORD *)v65[0] + v61) = v17;
      v19 = v64;
      ++v61;
    }
    while ( v61 < v64 );
    v3 = v64;
    if ( v64 > 0 )
    {
      v64 = 0;
      v20 = v18;
      v62 = v19;
      do
      {
        if ( *v20 )
        {
          v21 = 0;
          v22 = v64 + v70[0];
          do
          {
            v82[v21++] = v22;
            v22 += 32;
          }
          while ( v21 < 4 );
          sub_44AF20(v81, (int)v82);
          v23 = sub_448EE0(v82[0], &v66);
          sub_44B040(v81, (int)v23, &v74);
          v24 = 0;
          do
          {
            v25 = v24 + 1;
            if ( *v20 != v24 + 1 )
            {
              v26 = *(_DWORD *)(v82[v24] + 8 * v24 + 4);
              *(double *)(v26 + 16) = (v76 * *(float *)(v26 + 12) + v74 * *(float *)v26 + v77) * *(float *)v26
                                    + (v75 * *(float *)(v26 + 12) + v78) * *(float *)(v26 + 12)
                                    + v79;
              v27 = *(_DWORD *)(v82[v24 == 2 ? 0 : v25] + 8 * v24 + 4);
              *(double *)(v27 + 16) = (v76 * *(float *)(v27 + 12) + *(float *)v27 * v74 + v77) * *(float *)v27
                                    + (v75 * *(float *)(v27 + 12) + v78) * *(float *)(v27 + 12)
                                    + v79;
            }
            v24 = v25;
          }
          while ( v25 < 3 );
        }
        ++v20;
        v28 = v62 == 1;
        v64 += 128;
        --v62;
      }
      while ( !v28 );
    }
  }
  v29 = a3;
  sub_4492D0(a3, v3);
  if ( v3 > 0 )
  {
    v30 = (int *)v65[0];
    v63 = 0;
    v67 = (int *)v65[0];
    v66 = v3;
    do
    {
      v31 = 0;
      v32 = v70[0] + v63;
      do
      {
        v82[v31++] = v32;
        v32 += 32;
      }
      while ( v31 < 4 );
      sub_448EE0(v82[0], &v64);
      switch ( *v30 )
      {
        case 0:
          v48 = 0;
          for ( j = 0; j < 4; ++j )
          {
            v49 = v82[v48];
            v50 = (float *)&v75 + 1;
            v51 = (char *)v71 - v49;
            v52 = 3;
            do
            {
              v53 = *(float **)v49;
              v54 = *(float *)(*(_DWORD *)v49 + 12);
              v50 += 4;
              v55 = *(double *)(*(_DWORD *)v49 + 16);
              v49 += 8;
              --v52;
              *(v50 - 7) = *v53;
              *((double *)v50 - 3) = v55;
              *(v50 - 4) = v54;
              v56 = *(_DWORD *)(v49 - 4);
              *(_DWORD *)&v51[v49 - 8] = *(_DWORD *)(v56 + 16);
              *(_DWORD *)&v51[v49 - 4] = *(_DWORD *)(v56 + 20);
            }
            while ( v52 );
            v29 = a3;
            sub_4493A0(a3, &v74, (int)&v76, (int)&v78, (int)&v64, (int)v71);
            v48 = j + 1;
          }
          v30 = v67;
          break;
        case 1:
        case 2:
        case 3:
          for ( k = 0; k < 2; ++k )
          {
            sub_44AF60(v81, (int)v82, *v30, k);
            v41 = (float *)&v75 + 1;
            for ( m = 0; m < 6; v70[m + 2] = *(_DWORD *)(v47 + 20) )
            {
              v43 = v81[m];
              v44 = *(float *)(v43 + 12);
              m += 2;
              v45 = *(double *)(v43 + 16);
              v41 += 4;
              v46 = *(float *)v43;
              v47 = v81[m - 1];
              *(v41 - 7) = v46;
              *((double *)v41 - 3) = v45;
              *(v41 - 4) = v44;
              v70[m + 1] = *(_DWORD *)(v47 + 16);
            }
            v29 = a3;
            sub_4493A0(a3, &v74, (int)&v76, (int)&v78, (int)&v64, (int)v71);
          }
          break;
        case 4:
          sub_44AF20(v81, (int)v82);
          v33 = (float *)&v75 + 1;
          for ( n = 0; n < 6; v70[n + 2] = *(_DWORD *)(v39 + 20) )
          {
            v35 = v81[n];
            v36 = *(float *)(v35 + 12);
            n += 2;
            v37 = *(double *)(v35 + 16);
            v33 += 4;
            v38 = *(float *)v35;
            v39 = v81[n - 1];
            *(v33 - 7) = v38;
            *((double *)v33 - 3) = v37;
            *(v33 - 4) = v36;
            v70[n + 1] = *(_DWORD *)(v39 + 16);
          }
          sub_4493A0(v29, &v74, (int)&v76, (int)&v78, (int)&v64, (int)v71);
          break;
        default:
          break;
      }
      ++v30;
      v28 = v66 == 1;
      v63 += 128;
      v67 = v30;
      --v66;
    }
    while ( !v28 );
  }
  sub_449340(v69);
  if ( v65[0] )
    sub_587BCF(v65[0]);
  return sub_449340(v69);
}
