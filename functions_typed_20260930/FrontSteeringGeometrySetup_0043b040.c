int __thiscall sub_43B040(int *this, int a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  _BYTE *v5; // edi
  _DWORD *v6; // esi
  int v7; // eax
  double *v8; // edx
  _BYTE *v9; // eax
  _BYTE *v10; // edi
  int v11; // ecx
  int v12; // eax
  double *v13; // ecx
  double v14; // st7
  double v15; // st6
  double v16; // st6
  double v17; // st7
  double v18; // st6
  bool v19; // cc
  char *v20; // eax
  double *v21; // edx
  int v22; // esi
  int v23; // ecx
  double *v24; // ebx
  double v25; // st6
  long double v26; // st4
  double v27; // st7
  double v28; // st6
  char *v29; // eax
  int v30; // edi
  long double v31; // st7
  double *v32; // edx
  double *v33; // edx
  int v34; // esi
  int v35; // eax
  double v36; // st7
  double *v37; // ecx
  double v38; // st6
  double v39; // st6
  double v40; // st5
  int result; // eax
  int v42; // [esp+Ch] [ebp-2CCh]
  int v43; // [esp+Ch] [ebp-2CCh]
  int v44; // [esp+10h] [ebp-2C8h]
  int v45; // [esp+14h] [ebp-2C4h]
  int v46; // [esp+14h] [ebp-2C4h]
  char *v47; // [esp+18h] [ebp-2C0h]
  int v48; // [esp+18h] [ebp-2C0h]
  int v49; // [esp+1Ch] [ebp-2BCh]
  char *v50; // [esp+1Ch] [ebp-2BCh]
  int v51; // [esp+20h] [ebp-2B8h]
  int *v52; // [esp+24h] [ebp-2B4h]
  int v53; // [esp+28h] [ebp-2B0h]
  int v54; // [esp+2Ch] [ebp-2ACh]
  int v55; // [esp+30h] [ebp-2A8h]
  int v56; // [esp+34h] [ebp-2A4h]
  double v57[3]; // [esp+38h] [ebp-2A0h] BYREF
  double v58[13]; // [esp+50h] [ebp-288h] BYREF
  double v59[15]; // [esp+B8h] [ebp-220h] BYREF
  double v60; // [esp+130h] [ebp-1A8h]
  double v61; // [esp+148h] [ebp-190h]
  _BYTE v62[28]; // [esp+150h] [ebp-188h] BYREF
  double v63[32]; // [esp+16Ch] [ebp-16Ch] BYREF
  _BYTE v64[104]; // [esp+270h] [ebp-68h] BYREF

  v3 = 0;
  v52 = this;
  v53 = 0;
  while ( 1 )
  {
    v4 = 0;
    v49 = this[281 * v3 + 251];
    if ( v3 )
    {
      v47 = aFrSteering;
      v54 = 12;
    }
    else
    {
      v47 = aFlSteering;
      v54 = 11;
    }
    v51 = 0;
    v45 = 0;
    if ( this[1393] <= 0 )
      goto LABEL_45;
    v42 = 0;
    v5 = v62;
    do
    {
      v6 = (_DWORD *)(v42 + this[1394]);
      v7 = v6[1];
      if ( v7 == v49 && v6[3] == this[1404] || v6[3] == v49 && v7 == this[1404] )
      {
        if ( !*v6 || sub_588410(*v6, v47) )
        {
          v8 = (double *)v6[2];
          v9 = v5;
          v10 = v5 + 36;
          v11 = v6[1];
          *((_DWORD *)v9 + 1) = v11;
          *((_DWORD *)v9 + 2) = v8;
          *(_DWORD *)v9 = v6;
          v4 += 2;
          TransformApply3D((double *)(v11 + 28), (double *)(v11 + 4), v8, (double *)(v9 + 12));
          v12 = v6[3];
          v13 = (double *)v6[4];
          v14 = *(double *)(v12 + 44) * v13[2];
          *(_DWORD *)v10 = v6;
          v15 = *(double *)(v12 + 36);
          *((_DWORD *)v10 + 1) = v12;
          v16 = v15 * v13[1];
          *((_DWORD *)v10 + 2) = v13;
          v17 = v14 + v16 + *(double *)(v12 + 28) * *v13;
          v18 = *(double *)(v12 + 68) * v13[2] + *(double *)(v12 + 60) * v13[1] + *(double *)(v12 + 52) * *v13;
          v61 = *(double *)(v12 + 92) * v13[2] + *(double *)(v12 + 84) * v13[1] + *(double *)(v12 + 76) * *v13;
          *(double *)(v10 + 12) = v17 + *(double *)(v12 + 4);
          *(double *)(v10 + 20) = v18 + *(double *)(v12 + 12);
          *(double *)(v10 + 28) = v61 + *(double *)(v12 + 20);
          v5 = v10 + 36;
        }
        this = v52;
      }
      v19 = ++v45 < this[1393];
      v42 += 72;
    }
    while ( v19 );
    v51 = v4;
    if ( v4 != 8 )
    {
LABEL_45:
      if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002, 2807) )
        DebugLogWrite(&dword_8AD25C, aSorryOnlySuppo);
    }
    v20 = &v62[36 * v4];
    v46 = 0;
    v50 = v20;
    do
    {
      v21 = v59;
      if ( v46 )
        v21 = v58;
      v22 = 0;
      *((_DWORD *)v21 + 18) = -1;
      *((_DWORD *)v21 + 19) = 2146435071;
      v44 = 0;
      if ( v4 > 0 )
      {
        v23 = 0;
        v48 = 0;
        do
        {
          v43 = 0;
          if ( v23 > 0 )
          {
            v24 = v63;
            do
            {
              v25 = *(double *)&v62[v23 + 20] - *(v24 - 1);
              v26 = sqrt(
                      (*(double *)((char *)v63 + v23) - *v24) * (*(double *)((char *)v63 + v23) - *v24)
                    + v25 * v25
                    + (*(double *)&v62[v23 + 12] - *(v24 - 2)) * (*(double *)&v62[v23 + 12] - *(v24 - 2)));
              if ( v26 < v21[9] )
              {
                v21[9] = v26;
                qmemcpy(v21, &v62[v23], 0x24u);
                qmemcpy((char *)v21 + 36, (char *)v24 - 28, 0x24u);
                v27 = *(double *)((char *)v21 + 12) + v21[6];
                v28 = *(double *)((char *)v21 + 20) + v21[7];
                v55 = v44;
                v60 = *(double *)((char *)v21 + 28) + v21[8];
                v56 = v43;
                v57[0] = v27 * 0.5;
                v57[1] = v28 * 0.5;
                v57[2] = v60 * 0.5;
                qmemcpy(v21 + 10, v57, 0x18u);
                v22 = v44;
                v23 = v48;
              }
              v24 = (double *)((char *)v24 + 36);
              ++v43;
            }
            while ( v43 < v22 );
            v4 = v51;
            v20 = v50;
          }
          ++v22;
          v23 += 36;
          v44 = v22;
          v48 = v23;
        }
        while ( v22 < v4 );
      }
      v29 = v20 - 36;
      qmemcpy(&v62[36 * v55], v29, 0x24u);
      v20 = v29 - 36;
      qmemcpy(&v62[36 * v56], v20, 0x24u);
      v4 -= 2;
      v19 = v46 + 1 < 2;
      v51 = v4;
      v50 = v20;
      ++v46;
    }
    while ( v19 );
    if ( v59[11] < v58[11] )
    {
      qmemcpy(v64, v59, sizeof(v64));
      qmemcpy(v59, v58, 0x68u);
      qmemcpy(v58, v64, sizeof(v58));
    }
    v30 = 0;
    v31 = (tan(
             (double)*(int *)((v54 << 6) + a2 + 3012) * *(double *)((v54 << 6) + a2 + 3000)
           + *(double *)((v54 << 6) + a2 + 2992))
         * (v59[11] - v58[11])
         - (v59[12]
          - v58[12]))
        * 0.5;
    *(double *)((char *)&v59[3] + 4) = *(double *)((char *)&v59[3] + 4) + v31;
    v59[8] = v59[8] + v31;
    *(double *)((char *)&v58[3] + 4) = *(double *)((char *)&v58[3] + 4) - v31;
    v58[8] = v58[8] - v31;
    do
    {
      v32 = v59;
      if ( v30 )
        v32 = v58;
      v33 = v32 + 1;
      v34 = 2;
      do
      {
        v35 = *((_DWORD *)v33 - 1);
        v36 = *(double *)((char *)v33 + 4) - *(double *)(v35 + 4);
        v37 = *(double **)v33;
        v38 = *(double *)((char *)v33 + 12);
        v33 = (double *)((char *)v33 + 36);
        v39 = v38 - *(double *)(v35 + 12);
        --v34;
        v40 = *(v33 - 2) - *(double *)(v35 + 20);
        *v37 = v40 * *(double *)(v35 + 76) + v39 * *(double *)(v35 + 52) + v36 * *(double *)(v35 + 28);
        v37[1] = v40 * *(double *)(v35 + 84) + v39 * *(double *)(v35 + 60) + v36 * *(double *)(v35 + 36);
        v37[2] = v40 * *(double *)(v35 + 92) + v39 * *(double *)(v35 + 68) + v36 * *(double *)(v35 + 44);
        v37[3] = *(double *)(v35 + 44) * v37[2] + *(double *)(v35 + 36) * v37[1] + *(double *)(v35 + 28) * *v37;
        v37[4] = *(double *)(v35 + 52) * *v37 + *(double *)(v35 + 68) * v37[2] + *(double *)(v35 + 60) * v37[1];
        v37[5] = *(double *)(v35 + 76) * *v37 + *(double *)(v35 + 92) * v37[2] + *(double *)(v35 + 84) * v37[1];
      }
      while ( v34 );
      ++v30;
    }
    while ( v30 < 2 );
    result = ++v53;
    if ( v53 > 1 )
      return result;
    v3 = v53;
    this = v52;
  }
}

