int __userpurge sub_456A10@<eax>(int a1@<ecx>, int a2@<edi>, int a3@<esi>, double *a4)
{
  int v5; // eax
  _DWORD *v6; // ecx
  bool v7; // cc
  double *v8; // eax
  double v9; // st7
  double *v10; // edx
  int v11; // ecx
  double v12; // st7
  double v13; // st6
  int v14; // eax
  double v15; // st7
  double v16; // st6
  int v17; // eax
  int v18; // eax
  long double v19; // st6
  int v20; // ecx
  int v21; // edx
  long double v22; // st6
  double *v23; // esi
  long double v24; // st5
  int v25; // eax
  int v26; // eax
  int v27; // ecx
  double v28; // st7
  int v29; // ecx
  double v30; // st7
  int result; // eax
  char v32; // cl
  int v33; // eax
  int v34; // edx
  _DWORD *v35; // eax
  bool v36; // zf
  int v38; // [esp+10h] [ebp-88h]
  int v39; // [esp+10h] [ebp-88h]
  int v40; // [esp+14h] [ebp-84h]
  int v41; // [esp+14h] [ebp-84h]
  double v42; // [esp+18h] [ebp-80h]
  _DWORD *v43; // [esp+18h] [ebp-80h]
  int v44; // [esp+20h] [ebp-78h]
  int v45; // [esp+24h] [ebp-74h]
  int v46; // [esp+28h] [ebp-70h]
  int v47; // [esp+2Ch] [ebp-6Ch]
  int v48; // [esp+30h] [ebp-68h]
  int v49; // [esp+34h] [ebp-64h]
  double v50[3]; // [esp+38h] [ebp-60h] BYREF
  _BYTE v51[72]; // [esp+50h] [ebp-48h] BYREF

  v50[0] = 0.0;
  v50[1] = 0.0;
  v5 = *(_DWORD *)(a1 + 6244);
  v50[2] = 0.0;
  v40 = 0;
  if ( v5 > 0 )
  {
    v38 = 0;
    do
    {
      v6 = (_DWORD *)(v38 + *(_DWORD *)(a1 + 6248));
      v6[26] = *(_DWORD *)a4;
      v6[27] = *((_DWORD *)a4 + 1);
      v6[28] = *((_DWORD *)a4 + 2);
      v6[29] = *((_DWORD *)a4 + 3);
      v6[30] = *((_DWORD *)a4 + 4);
      v6[31] = *((_DWORD *)a4 + 5);
      sub_61B710(v50);
      v7 = ++v40 < *(_DWORD *)(a1 + 6244);
      v38 += 584;
    }
    while ( v7 );
  }
  v8 = *(double **)(a1 + 6312);
  v9 = v8[12];
  v8 += 4;
  v10 = (double *)(a1 + 904);
  v11 = 4;
  v12 = v9 * a4[2] + v8[5] * a4[1];
  v13 = v8[2];
  v14 = a1 + 904;
  v15 = -(v12 + v13 * *a4);
  v42 = v15;
  do
  {
    v14 += 1280;
    --v11;
    v16 = -(v15 / *(double *)(v14 - 936));
    *(double *)(v14 - 1280) = v16;
    *(double *)(v14 - 1272) = v16;
  }
  while ( v11 );
  v17 = *(_DWORD *)(a1 + 9104);
  if ( v17 )
  {
    v18 = v17 - 1;
    if ( v18 )
    {
      if ( v18 == 1 )
        v15 = (*(double *)(a1 + 2184) + *v10) * 0.5;
    }
    else
    {
      v15 = (*(double *)(a1 + 4744) + *(double *)(a1 + 3464) + *(double *)(a1 + 2184) + *v10) * 0.25;
    }
  }
  else
  {
    v15 = (*(double *)(a1 + 4744) + *(double *)(a1 + 3464)) * 0.5;
  }
  v19 = fabs(v42) * 0.018 + 0.2;
  if ( v19 >= 0.0 )
  {
    if ( v19 > 0.8 )
      v19 = 0.8;
  }
  else
  {
    v19 = 0.0;
  }
  v20 = *(_DWORD *)(a1 + 9304);
  v21 = v20;
  *(double *)(a1 + 8656) = -(v15 * *(double *)(a1 + 8 * v20 + 9312));
  if ( v20 > 0 )
  {
    v22 = v19 * *(double *)(a1 + 8784);
    v23 = (double *)(a1 + 8 * v20 + 9312);
    do
    {
      v24 = -(v15 * *v23);
      if ( v24 < v22 )
      {
        *(long double *)(a1 + 8656) = v24;
        v20 = v21;
      }
      --v21;
      --v23;
    }
    while ( v21 > 0 );
  }
  v25 = *(_DWORD *)(a1 + 9380);
  if ( *(double *)(a1 + 8656) < *(double *)(a1 + 8696) )
  {
    if ( v25 )
    {
      v29 = *(_DWORD *)(a1 + 9392) + 24;
      *(double *)(a1 + 9224) = *(double *)(a1 + 9256);
      *(_DWORD *)(a1 + 9384) = 0;
      *(_DWORD *)(a1 + 9380) = 0;
      *(_DWORD *)(a1 + 9376) = 0;
      sub_58C790(v29);
      *(double *)(a1 + 56) = *(double *)(a1 + 128);
      *(_DWORD *)(a1 + 52) = 5;
    }
    *(double *)(a1 + 8656) = *(double *)(a1 + 8696);
  }
  else if ( v20 != v25 )
  {
    if ( v20 == -1 )
    {
      *(_DWORD *)(a1 + 9384) = 1;
    }
    else if ( v20 )
    {
      *(_DWORD *)(a1 + 9384) = 2 * (v20 > *(_DWORD *)(a1 + 9376)) - 1;
    }
    else
    {
      *(_DWORD *)(a1 + 9384) = 0;
    }
    v26 = *(_DWORD *)(a1 + 9384);
    *(_DWORD *)(a1 + 9380) = v20;
    v27 = *(_DWORD *)(a1 + 9392) + 24;
    *(_DWORD *)(a1 + 9376) = 0;
    if ( v26 <= 0 )
    {
      *(double *)(a1 + 9224) = *(double *)(a1 + 9256);
      sub_58C790(v27);
      v28 = *(double *)(a1 + 128);
      *(_DWORD *)(a1 + 52) = 5;
    }
    else
    {
      *(double *)(a1 + 9224) = *(double *)(a1 + 9232);
      sub_58EC30(v27, a2, a3);
      v28 = *(double *)(a1 + 128);
      *(_DWORD *)(a1 + 52) = 6;
    }
    *(double *)(a1 + 56) = v28;
  }
  *(double *)(a1 + 8664) = *(double *)(a1 + 8656);
  *(double *)(a1 + 9144) = *(double *)(a1 + 8656);
  *(double *)(a1 + 9152) = *(double *)(a1 + 8656);
  if ( *(double *)(a1 + 8656) <= 0.5 )
  {
    v30 = *(double *)(a1 + 8656);
    *(_BYTE *)(a1 + 8650) = 1;
    if ( v30 < *(double *)(a1 + 8696) )
      *(double *)(a1 + 8656) = *(double *)(a1 + 8696);
  }
  result = a1 + 1068;
  *(_DWORD *)(a1 + 232) = 0;
  v39 = a1 + 1068;
  v41 = 2;
  do
  {
    if ( *(_DWORD *)result )
    {
      v32 = *(_BYTE *)(result + 100);
      v33 = result - 204;
      if ( !v32 )
      {
        qmemcpy(v51, (const void *)(*(_DWORD *)(a1 + 6312) + 32), sizeof(v51));
        sub_61B900(v33, 0);
        v44 = *(_DWORD *)(*(_DWORD *)(a1 + 6312) + 128);
        v45 = *(_DWORD *)(*(_DWORD *)(a1 + 6312) + 132);
        v46 = *(_DWORD *)(*(_DWORD *)(a1 + 6312) + 136);
        v47 = *(_DWORD *)(*(_DWORD *)(a1 + 6312) + 140);
        v34 = *(_DWORD *)(*(_DWORD *)(a1 + 6312) + 148);
        v35 = *(_DWORD **)v39;
        v48 = *(_DWORD *)(*(_DWORD *)(a1 + 6312) + 144);
        qmemcpy((void *)(*(_DWORD *)v39 + 32), v51, 0x48u);
        v49 = v34;
        v43 = v35;
        sub_618D20(v35);
        v43[32] = v44;
        v43[33] = v45;
        v43[34] = v46;
        v43[35] = v47;
        v43[36] = v48;
        v43[37] = v49;
        sub_618E60(v43);
        sub_440A20();
        sub_440A20();
        sub_440A20();
        sub_440A20();
      }
    }
    result = v39 + 1280;
    v36 = v41 == 1;
    v39 += 1280;
    --v41;
  }
  while ( !v36 );
  return result;
}
