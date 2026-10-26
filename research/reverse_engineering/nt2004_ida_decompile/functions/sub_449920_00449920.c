int __thiscall sub_449920(int this, float *a2)
{
  char *v3; // ebx
  float *v4; // esi
  double v5; // st7
  double v6; // st7
  int v7; // ecx
  double v8; // st7
  int v9; // ecx
  int v10; // eax
  double v11; // st7
  int v12; // edx
  double v13; // st6
  double v14; // st7
  double v15; // st6
  int v16; // esi
  double v17; // st7
  double v18; // st6
  double v19; // st7
  double v20; // st6
  float *v21; // ecx
  double v22; // st6
  double v23; // st6
  double v24; // st6
  double v25; // st7
  double v26; // st7
  int v27; // ebx
  double *v28; // esi
  int v29; // eax
  double v30; // st7
  double v31; // st6
  double v32; // st7
  double v33; // st6
  double v34; // st7
  double v35; // rt0
  double v36; // st7
  int result; // eax
  float *v38; // ecx
  double *v39; // edx
  int v40; // esi
  __int16 v41; // fps
  double v42; // st7
  bool v43; // c0
  char v44; // c2
  bool v45; // c3
  bool v46; // c0
  char v47; // c2
  bool v48; // c3
  float v49; // [esp+0h] [ebp-ACh]
  float v50; // [esp+4h] [ebp-A8h]
  int v51; // [esp+20h] [ebp-8Ch]
  double *v52; // [esp+20h] [ebp-8Ch]
  int v53; // [esp+24h] [ebp-88h]
  int v54; // [esp+28h] [ebp-84h] BYREF
  float v55; // [esp+2Ch] [ebp-80h]
  float v56; // [esp+30h] [ebp-7Ch]
  int v57; // [esp+34h] [ebp-78h] BYREF
  float v58; // [esp+38h] [ebp-74h]
  float v59; // [esp+3Ch] [ebp-70h]
  double v60; // [esp+48h] [ebp-64h]
  double v61; // [esp+50h] [ebp-5Ch]
  double v62; // [esp+58h] [ebp-54h] BYREF
  double v63; // [esp+60h] [ebp-4Ch]
  double v64; // [esp+68h] [ebp-44h]
  float v65[7]; // [esp+70h] [ebp-3Ch] BYREF
  double v66; // [esp+8Ch] [ebp-20h]
  double v67; // [esp+94h] [ebp-18h]

  v3 = (char *)&unk_75ED28;
  v4 = a2 + 63;
  v51 = 4;
  do
  {
    if ( *((double *)v3 - 4) <= 0.0 )
    {
      v5 = 0.0;
    }
    else
    {
      v5 = 1.0 - *((double *)v3 - 2);
      if ( v5 > 0.70999998 )
      {
        *(v4 - 1) = (v5 - 0.70999998) * 3.448275606924251;
        goto LABEL_7;
      }
    }
    *(v4 - 1) = 0.0;
LABEL_7:
    if ( v5 <= 0.41 )
      *v4 = 0.0;
    else
      *v4 = (v5 - 0.41) * 1.694915243963578;
    v6 = *v4;
    v7 = *((_DWORD *)v4 - 1);
    v4[3] = *v4;
    *((_DWORD *)v4 + 2) = v7;
    *((_DWORD *)v4 + 5) = (__int64)(v6 * 16.0);
    if ( *((double *)v3 - 4) <= 0.0 )
      v8 = 0.0;
    else
      v8 = *(double *)(v3 + 332);
    v4[1] = v8;
    v4[4] = 0.0;
    if ( v8 > 0.0 )
    {
      *(v4 - 1) = 0.0;
      v4[2] = 0.0;
      v4[3] = 0.0;
    }
    v9 = *((_DWORD *)v3 + 80);
    if ( v9 )
    {
      v10 = *(_DWORD *)v3;
      v11 = *(double *)(*(_DWORD *)v3 + 20);
      v12 = *(_DWORD *)(this + 8620);
      v13 = *(double *)(*(_DWORD *)v3 + 12);
      *(float *)&v57 = *(double *)(*(_DWORD *)v3 + 4);
      v58 = v13;
      v59 = v11;
      v14 = *(double *)(v10 + 116);
      v15 = *(double *)(v10 + 108);
      *(float *)&v54 = *(double *)(v10 + 100);
      v55 = v15;
      v56 = v14;
      v49 = *(double *)(this + 128);
      sub_4F5EE0((int)(v4 - 8), v49, (int)&v57, (int)&v54, v9, *(_DWORD *)(v12 + 25248));
    }
    v3 += 1256;
    v4 += 76;
    --v51;
  }
  while ( v51 );
  if ( *(double *)(this + 8328) == 0.0
    && *(double *)(this + 8336) == 0.0
    && *(double *)(this + 8344) == 0.0
    && *(double *)(this + 8176) <= *(double *)(this + 8320) )
  {
    a2[40] = 0.0;
    a2[45] = 0.0;
    a2[50] = 0.0;
  }
  else
  {
    v16 = *(_DWORD *)(this + 6164);
    sub_43D900((double *)(v16 + 28), (double *)(v16 + 4), (double *)(this + 8352), &v62);
    *(float *)&v57 = v62;
    v58 = v63;
    v59 = v64;
    v17 = *(double *)(v16 + 116);
    v18 = *(double *)(v16 + 108);
    *(float *)&v54 = *(double *)(v16 + 100);
    v55 = v18;
    v56 = v17;
    v19 = -1.0 / *(double *)(this + 8064) * *(double *)(this + 7936) * *(double *)(this + 8);
    if ( v19 >= -1.0 )
    {
      if ( v19 > 0.0 )
        v19 = 0.0;
    }
    else
    {
      v19 = -1.0;
    }
    if ( *(double *)(this + 8328) <= 0.0 )
      v20 = v19 * *(double *)(this + 8328);
    else
      v20 = *(double *)(this + 8328);
    v21 = a2 + 40;
    a2[40] = v20;
    if ( *(double *)(this + 8336) <= 0.0 )
      v22 = v19 * *(double *)(this + 8336);
    else
      v22 = *(double *)(this + 8336);
    a2[45] = v22;
    if ( *(double *)(this + 8344) <= 0.0 )
      v23 = v19 * *(double *)(this + 8344);
    else
      v23 = *(double *)(this + 8344);
    a2[50] = v23;
    if ( *(double *)(this + 8176) > *(double *)(this + 8320) )
    {
      v24 = v19;
      v25 = flt_7D3C54[(unsigned __int8)dword_7D3C50++] * 0.2;
      v26 = v25 - v24 * 0.2;
      if ( v26 > *v21 )
        *v21 = v26;
    }
    v50 = *(double *)(this + 128);
    sub_4F6430((int)v21, v50, (int)&v57, (int)&v54, *(_DWORD *)(*(_DWORD *)(this + 8620) + 25248));
  }
  v27 = 0;
  v53 = this + 6404;
  v52 = (double *)(this + 6420);
  v28 = (double *)(this + 6284);
  do
  {
    if ( *v52 < 0.0 )
    {
      if ( *(_DWORD *)v53 )
      {
        if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)v53 + 84) + 40) )
        {
          v29 = *(_DWORD *)(this + 6164);
          v30 = *(double *)(v29 + 36) * *v28 + *(double *)(v29 + 44) * v28[1] + *(v28 - 1) * *(double *)(v29 + 28);
          v31 = *(double *)(v29 + 60) * *v28 + *(double *)(v29 + 68) * v28[1] + *(double *)(v29 + 52) * *(v28 - 1);
          v66 = *(double *)(v29 + 84) * *v28 + *(double *)(v29 + 92) * v28[1] + *(double *)(v29 + 76) * *(v28 - 1);
          v67 = v30 + *(double *)(v29 + 4);
          v32 = v31 + *(double *)(v29 + 12);
          v33 = v66 + *(double *)(v29 + 20);
          v62 = v67 - *(double *)(v29 + 4);
          v63 = v32 - *(double *)(v29 + 12);
          v34 = v33 - *(double *)(v29 + 20);
          v35 = v34 * *(double *)(v29 + 132) - v63 * *(double *)(v29 + 140);
          v60 = v62 * *(double *)(v29 + 140) - v34 * *(double *)(v29 + 124);
          v61 = v63 * *(double *)(v29 + 124) - v62 * *(double *)(v29 + 132);
          v36 = v35 + *(double *)(v29 + 100);
          v60 = v60 + *(double *)(v29 + 108);
          v61 = v61 + *(double *)(v29 + 116);
          if ( v36 * v36 + v60 * v60 + v61 * v61 > 25.0 )
          {
            v65[0] = v36 * 0.5;
            v65[1] = v60 * 0.5 + 3.0;
            v65[2] = v61 * 0.5;
            sub_51BBE0(v27, 15, 10, v65);
          }
        }
      }
    }
    ++v27;
    v28 += 3;
    v53 += 4;
    ++v52;
  }
  while ( v27 < 4 );
  HIWORD(result) = HIWORD(a2);
  v38 = a2 + 126;
  v39 = (double *)(this + 1828);
  v40 = 4;
  do
  {
    v42 = (*v39 - 1023.16) * 0.004;
    v43 = v42 < 0.0;
    v44 = 0;
    v45 = v42 == 0.0;
    LOWORD(result) = v41;
    if ( v42 >= 0.0 )
    {
      v46 = v42 < 1.0;
      v47 = 0;
      v48 = v42 == 1.0;
      LOWORD(result) = v41;
      if ( v42 > 1.0 )
        v42 = 1.0;
    }
    else
    {
      v42 = 0.0;
    }
    *v38 = v42;
    v39 += 157;
    v38 += 76;
    --v40;
  }
  while ( v40 );
  return result;
}
