int __thiscall sub_4410C0(int *this, int a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  _BYTE *v5; // edi
  int v6; // esi
  int v7; // eax
  double *v8; // ecx
  _BYTE *v9; // edx
  _BYTE *v10; // edi
  double *v11; // eax
  double v12; // st7
  double v13; // st7
  double v14; // st6
  double v15; // st7
  double v16; // st6
  double v17; // st5
  double v18; // st4
  double *v19; // ecx
  double v20; // st7
  double *v21; // eax
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st6
  bool v26; // cc
  char *v27; // eax
  double *v28; // edx
  int v29; // esi
  int v30; // ecx
  double *v31; // ebx
  long double v32; // st7
  double v33; // st7
  char *v34; // eax
  int v35; // edi
  long double v36; // st7
  double *v37; // edx
  double *v38; // edx
  int v39; // esi
  double *v40; // eax
  double v41; // st7
  double *v42; // ecx
  double v43; // st6
  double v44; // st6
  double v45; // st5
  int result; // eax
  char v47; // [esp+0h] [ebp-370h]
  int v48; // [esp+Ch] [ebp-364h]
  int v49; // [esp+Ch] [ebp-364h]
  int v50; // [esp+10h] [ebp-360h]
  int v51; // [esp+14h] [ebp-35Ch]
  int v52; // [esp+14h] [ebp-35Ch]
  char *String2; // [esp+18h] [ebp-358h]
  char *String2a; // [esp+18h] [ebp-358h]
  int v55; // [esp+1Ch] [ebp-354h]
  char *v56; // [esp+1Ch] [ebp-354h]
  int v57; // [esp+20h] [ebp-350h]
  int v58; // [esp+24h] [ebp-34Ch]
  int *v59; // [esp+28h] [ebp-348h]
  int v60; // [esp+2Ch] [ebp-344h]
  double v61; // [esp+30h] [ebp-340h]
  double v62; // [esp+38h] [ebp-338h]
  int v63; // [esp+48h] [ebp-328h]
  int v64; // [esp+4Ch] [ebp-324h]
  double v65; // [esp+60h] [ebp-310h]
  double v66[14]; // [esp+B0h] [ebp-2C0h] BYREF
  double v67[16]; // [esp+120h] [ebp-250h] BYREF
  double v68; // [esp+1A0h] [ebp-1D0h]
  double v69; // [esp+1B8h] [ebp-1B8h]
  _BYTE v70[32]; // [esp+1C0h] [ebp-1B0h] BYREF
  double v71[36]; // [esp+1E0h] [ebp-190h] BYREF
  _BYTE v72[112]; // [esp+300h] [ebp-70h] BYREF

  v3 = 0;
  v59 = this;
  v58 = 0;
  while ( 1 )
  {
    v4 = 0;
    v55 = this[320 * v3 + 267];
    if ( v3 )
    {
      String2 = "fr_steering";
      v60 = 13;
    }
    else
    {
      String2 = "fl_steering";
      v60 = 12;
    }
    v57 = 0;
    v51 = 0;
    if ( this[1567] <= 0 )
      goto LABEL_45;
    v48 = 0;
    v5 = v70;
    do
    {
      v6 = v48 + this[1568];
      v7 = *(_DWORD *)(v6 + 4);
      if ( v7 == v55 && *(_DWORD *)(v6 + 12) == this[1578] || *(_DWORD *)(v6 + 12) == v55 && v7 == this[1578] )
      {
        if ( !*(_DWORD *)v6 || _stricmp(*(const char **)v6, String2) )
        {
          v8 = *(double **)(v6 + 8);
          v9 = v5;
          v10 = v5 + 40;
          v4 += 2;
          v11 = *(double **)(v6 + 4);
          v12 = v11[6];
          *((_DWORD *)v9 + 1) = v11;
          v13 = v12 * v8[2];
          *((_DWORD *)v9 + 2) = v8;
          v14 = v11[5];
          *(_DWORD *)v9 = v6;
          v15 = v13 + v14 * v8[1] + v11[4] * *v8;
          v16 = v11[7] * *v8 + v11[9] * v8[2] + v11[8] * v8[1];
          v17 = v11[10] * *v8 + v11[12] * v8[2];
          v18 = v11[11] * v8[1];
          v19 = *(double **)(v6 + 16);
          v68 = v17 + v18;
          *((double *)v9 + 2) = v15 + v11[1];
          *((double *)v9 + 3) = v16 + v11[2];
          v20 = v68 + v11[3];
          v21 = *(double **)(v6 + 12);
          *((double *)v9 + 4) = v20;
          *(_DWORD *)v10 = v6;
          v22 = v21[6];
          *((_DWORD *)v10 + 1) = v21;
          v23 = v22 * v19[2];
          *((_DWORD *)v10 + 2) = v19;
          v24 = v23 + v21[5] * v19[1] + v21[4] * *v19;
          v25 = v21[9] * v19[2] + v21[8] * v19[1] + v21[7] * *v19;
          v69 = v21[12] * v19[2] + v21[11] * v19[1] + v21[10] * *v19;
          *((double *)v10 + 2) = v24 + v21[1];
          *((double *)v10 + 3) = v25 + v21[2];
          *((double *)v10 + 4) = v69 + v21[3];
          v5 = v10 + 40;
        }
        this = v59;
      }
      v26 = ++v51 < this[1567];
      v48 += 80;
    }
    while ( v26 );
    v57 = v4;
    if ( v4 != 8 )
    {
LABEL_45:
      if ( dword_B640C0 != 5
        && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\hdvehicle.cpp", 3752) )
      {
        sub_561210((int)byte_FAE910, "Sorry, only support independent 5-link front suspensions right now", v47);
      }
    }
    v27 = &v70[40 * v4];
    v52 = 0;
    v56 = v27;
    do
    {
      v28 = v67;
      if ( v52 )
        v28 = v66;
      v29 = 0;
      v28[10] = 1.797693134862316e308;
      v50 = 0;
      if ( v4 > 0 )
      {
        v30 = 0;
        String2a = 0;
        do
        {
          v49 = 0;
          if ( v30 > 0 )
          {
            v31 = v71;
            do
            {
              v61 = *(double *)&v70[v30 + 16] - *(v31 - 2);
              v62 = *(double *)&v70[v30 + 24] - *(v31 - 1);
              v32 = sqrt(
                      (*(double *)((char *)v71 + v30) - *v31) * (*(double *)((char *)v71 + v30) - *v31)
                    + v62 * v62
                    + v61 * v61);
              if ( v32 < v28[10] )
              {
                v28[10] = v32;
                qmemcpy(v28, &v70[v30], 0x28u);
                qmemcpy(v28 + 5, v31 - 4, 0x28u);
                v63 = v50;
                v64 = v49;
                v29 = v50;
                v65 = v28[4] + v28[9];
                v33 = (v28[3] + v28[8]) * 0.5;
                v28[11] = (v28[7] + v28[2]) * 0.5;
                v28[12] = v33;
                v28[13] = v65 * 0.5;
                v30 = (int)String2a;
              }
              v31 += 5;
              ++v49;
            }
            while ( v49 < v29 );
            v4 = v57;
            v27 = v56;
          }
          ++v29;
          v30 += 40;
          v50 = v29;
          String2a = (char *)v30;
        }
        while ( v29 < v4 );
      }
      v34 = v27 - 40;
      qmemcpy(&v70[40 * v63], v34, 0x28u);
      v27 = v34 - 40;
      qmemcpy(&v70[40 * v64], v27, 0x28u);
      v4 -= 2;
      v26 = v52 + 1 < 2;
      v57 = v4;
      v56 = v27;
      ++v52;
    }
    while ( v26 );
    if ( v67[12] < v66[12] )
    {
      qmemcpy(v72, v67, sizeof(v72));
      qmemcpy(v67, v66, 0x70u);
      qmemcpy(v66, v72, sizeof(v66));
    }
    v35 = 0;
    v36 = (tan(
             (double)*(int *)((v60 << 6) + a2 + 3012) * *(double *)((v60 << 6) + a2 + 3000)
           + *(double *)((v60 << 6) + a2 + 2992))
         * (v67[12] - v66[12])
         - (v67[13]
          - v66[13]))
        * 0.5;
    v67[4] = v67[4] + v36;
    v67[9] = v67[9] + v36;
    v66[4] = v66[4] - v36;
    v66[9] = v66[9] - v36;
    do
    {
      v37 = v67;
      if ( v35 )
        v37 = v66;
      v38 = v37 + 1;
      v39 = 2;
      do
      {
        v40 = (double *)*((_DWORD *)v38 - 1);
        v41 = v38[1] - v40[1];
        v42 = *(double **)v38;
        v43 = v38[2];
        v38 += 5;
        v44 = v43 - v40[2];
        --v39;
        v45 = *(v38 - 2) - v40[3];
        *v42 = v45 * v40[10] + v44 * v40[7] + v41 * v40[4];
        v42[1] = v45 * v40[11] + v44 * v40[8] + v41 * v40[5];
        v42[2] = v45 * v40[12] + v44 * v40[9] + v41 * v40[6];
        v42[3] = v40[6] * v42[2] + v40[5] * v42[1] + v40[4] * *v42;
        v42[4] = v40[9] * v42[2] + v40[8] * v42[1] + v40[7] * *v42;
        v42[5] = v40[12] * v42[2] + v40[11] * v42[1] + v40[10] * *v42;
      }
      while ( v39 );
      ++v35;
    }
    while ( v35 < 2 );
    result = ++v58;
    if ( v58 > 1 )
      return result;
    v3 = v58;
    this = v59;
  }
}
