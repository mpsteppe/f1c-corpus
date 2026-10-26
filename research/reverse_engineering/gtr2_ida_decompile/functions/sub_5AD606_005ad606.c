int __stdcall sub_5AD606(float *a1, int a2, int a3, int a4)
{
  int v4; // edx
  int v5; // edx
  long double v6; // st7
  long double v7; // st6
  int v8; // esi
  int v9; // ecx
  double v10; // st7
  _DWORD *v11; // edi
  float *v12; // esi
  char *v13; // ebx
  int v14; // edx
  float *v15; // ecx
  long double v16; // st7
  long double v17; // st6
  int v18; // eax
  float *v19; // eax
  float *v20; // edi
  char *v21; // esi
  double v22; // st7
  float *v23; // eax
  float *v24; // ecx
  float *v25; // edi
  float *v26; // ebx
  int result; // eax
  float v28[9]; // [esp+4h] [ebp-84h] BYREF
  float v29; // [esp+28h] [ebp-60h]
  float *v30; // [esp+2Ch] [ebp-5Ch]
  float v31; // [esp+30h] [ebp-58h] BYREF
  float v32; // [esp+34h] [ebp-54h]
  float v33; // [esp+38h] [ebp-50h]
  float v34; // [esp+3Ch] [ebp-4Ch]
  float v35; // [esp+40h] [ebp-48h] BYREF
  float v36; // [esp+44h] [ebp-44h]
  float v37; // [esp+48h] [ebp-40h]
  float v38; // [esp+4Ch] [ebp-3Ch]
  float v39; // [esp+50h] [ebp-38h] BYREF
  float v40; // [esp+54h] [ebp-34h]
  float v41; // [esp+58h] [ebp-30h]
  float v42; // [esp+5Ch] [ebp-2Ch]
  float v43; // [esp+60h] [ebp-28h]
  float v44; // [esp+64h] [ebp-24h]
  float v45; // [esp+68h] [ebp-20h]
  float v46; // [esp+6Ch] [ebp-1Ch]
  float v47; // [esp+70h] [ebp-18h]
  float v48; // [esp+74h] [ebp-14h]
  float v49; // [esp+78h] [ebp-10h]
  float v50; // [esp+7Ch] [ebp-Ch] BYREF
  float v51; // [esp+80h] [ebp-8h]
  float v52; // [esp+84h] [ebp-4h]
  float v53; // [esp+98h] [ebp+10h]
  int v54; // [esp+98h] [ebp+10h]
  float v55; // [esp+9Ch] [ebp+14h]
  int v56; // [esp+9Ch] [ebp+14h]
  float v57; // [esp+9Ch] [ebp+14h]

  v28[0] = 1.0;
  v28[1] = 0.0;
  v28[2] = 0.0;
  v28[3] = 0.0;
  v28[4] = 1.0;
  v28[5] = 0.0;
  v50 = 0.0;
  v51 = 0.0;
  v52 = 1.0;
  v28[6] = 0.0;
  *(float *)a3 = *(float *)(a4 + 48);
  v4 = *(_DWORD *)(a4 + 52);
  v45 = 0.0;
  v28[7] = v51;
  v44 = 0.0;
  v28[8] = v52;
  v43 = 0.0;
  *(_DWORD *)(a3 + 4) = v4;
  v5 = *(_DWORD *)(a4 + 56);
  v42 = 0.0;
  *(_DWORD *)(a3 + 8) = v5;
  v38 = 0.0;
  v50 = COERCE_FLOAT(&v31);
  v34 = 0.0;
  v51 = COERCE_FLOAT(&v35);
  v46 = 1.0;
  v31 = *(float *)a4;
  v32 = *(float *)(a4 + 4);
  v33 = *(float *)(a4 + 8);
  v35 = *(float *)(a4 + 16);
  v36 = *(float *)(a4 + 20);
  v37 = *(float *)(a4 + 24);
  v39 = *(float *)(a4 + 32);
  v40 = *(float *)(a4 + 36);
  v41 = *(float *)(a4 + 40);
  v52 = COERCE_FLOAT(&v39);
  v6 = sqrt(v33 * v33 + v32 * v32 + v31 * v31);
  *a1 = v6;
  v7 = sqrt(v37 * v37 + v36 * v36 + v35 * v35);
  a1[1] = v7;
  v55 = sqrt(v41 * v41 + v40 * v40 + v39 * v39);
  a1[2] = v55;
  if ( v6 >= v7 )
  {
    if ( v6 >= v55 )
    {
      v8 = 0;
      v53 = v7;
      if ( v53 >= (double)v55 )
      {
        v54 = 2;
        goto LABEL_13;
      }
      v56 = 2;
    }
    else
    {
      v56 = 0;
      v8 = 2;
    }
    v54 = 1;
    goto LABEL_14;
  }
  if ( v7 < v55 )
  {
    v54 = 0;
    v8 = 2;
LABEL_13:
    v56 = 1;
    goto LABEL_14;
  }
  v8 = 1;
  if ( v6 >= v55 )
  {
    v56 = 0;
    v54 = 2;
  }
  else
  {
    v54 = 0;
    v56 = 2;
  }
LABEL_14:
  v9 = 4 * v8;
  v10 = a1[v8];
  v30 = &a1[v8];
  if ( v10 < 0.000099999997 )
  {
    v11 = (_DWORD *)*((_DWORD *)&v50 + v8);
    v12 = &v28[3 * v8];
    *v11 = *(_DWORD *)v12++;
    *++v11 = *(_DWORD *)v12;
    v11[1] = *((_DWORD *)v12 + 1);
  }
  v13 = (char *)&v50 + v9;
  sub_5A9859();
  v14 = 4 * v56;
  if ( a1[v56] < 0.000099999997 )
  {
    v15 = *(float **)v13;
    v16 = fabs(**(float **)v13);
    v17 = fabs(*(float *)(*(_DWORD *)v13 + 4));
    v29 = v17;
    v57 = fabs(v15[2]);
    if ( v16 >= v17 )
    {
      if ( v16 < v57 || v29 < (double)v57 )
      {
        v18 = 1;
        goto LABEL_25;
      }
    }
    else if ( v17 < v57 || v16 < v57 )
    {
      v18 = 0;
LABEL_25:
      v19 = &v28[3 * v18];
      v20 = *(float **)((char *)&v50 + v14);
      v47 = v19[2] * v15[1] - v15[2] * v19[1];
      v48 = v15[2] * *v19 - *v15 * v19[2];
      v49 = *v15 * v19[1] - *v19 * v15[1];
      *v20++ = v47;
      *v20 = v48;
      v20[1] = v49;
      goto LABEL_26;
    }
    v18 = 2;
    goto LABEL_25;
  }
LABEL_26:
  v21 = (char *)&v50 + v14;
  sub_5A9859();
  v22 = a1[v54];
  if ( v22 < 0.000099999997 )
  {
    v23 = *(float **)v21;
    v24 = *(float **)v13;
    v25 = (float *)*((_DWORD *)&v50 + v54);
    v47 = *(float *)(*(_DWORD *)v21 + 8) * *(float *)(*(_DWORD *)v13 + 4)
        - *(float *)(*(_DWORD *)v13 + 8) * *(float *)(*(_DWORD *)v21 + 4);
    v48 = *v23 * v24[2] - v23[2] * *v24;
    v22 = v23[1] * *v24 - *v23 * v24[1];
    v49 = v22;
    *v25++ = v47;
    *v25 = v48;
    v25[1] = v49;
  }
  sub_5A9859();
  sub_5AA41C();
  if ( v22 < 0.0 )
  {
    v26 = *(float **)v13;
    *v30 = -*v30;
    v47 = -*v26;
    v48 = -v26[1];
    v49 = -v26[2];
    *v26 = v47;
    v26[1] = v48;
    v22 = -v22;
    v26[2] = v49;
  }
  if ( (v22 - 1.0) * (v22 - 1.0) > 0.000099999997 )
    return -2005530516;
  sub_5ABDE2();
  result = 0;
  *(float *)(a2 + 12) = -*(float *)(a2 + 12);
  return result;
}
