int __thiscall sub_447780(int this, double *a2)
{
  int v3; // ecx
  bool v4; // cc
  double *v5; // eax
  double v6; // st7
  int v7; // edx
  double v8; // st7
  double v9; // st6
  double *v10; // ecx
  int v11; // eax
  double v12; // st7
  double v13; // st6
  int v14; // eax
  int v15; // eax
  long double v16; // st6
  int v17; // edx
  int v18; // ecx
  long double v19; // st6
  double *v20; // esi
  long double v21; // st5
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  bool v27; // zf
  int result; // eax
  int v29; // [esp+10h] [ebp-88h]
  int v30; // [esp+10h] [ebp-88h]
  int v31; // [esp+14h] [ebp-84h]
  int v32; // [esp+14h] [ebp-84h]
  double v33; // [esp+18h] [ebp-80h]
  int v34; // [esp+18h] [ebp-80h]
  _DWORD v35[6]; // [esp+20h] [ebp-78h] BYREF
  _BYTE v36[24]; // [esp+38h] [ebp-60h] BYREF
  _BYTE v37[72]; // [esp+50h] [ebp-48h] BYREF

  v3 = *(_DWORD *)(this + 5548);
  memset(v35, 0, sizeof(v35));
  v31 = 0;
  if ( v3 > 0 )
  {
    v29 = 0;
    do
    {
      qmemcpy((void *)(v29 + *(_DWORD *)(this + 5552) + 100), a2, 0x18u);
      sub_569280(v35);
      v4 = ++v31 < *(_DWORD *)(this + 5548);
      v29 += 580;
    }
    while ( v4 );
  }
  v5 = *(double **)(this + 5616);
  v6 = *(double *)((char *)v5 + 92) * a2[2];
  v5 = (double *)((char *)v5 + 28);
  v7 = 4;
  v8 = v6 + v5[5] * a2[1];
  v9 = v5[2] * *a2;
  v10 = (double *)(this + 840);
  v11 = this + 840;
  v12 = -(v8 + v9);
  v33 = v12;
  do
  {
    v11 += 1124;
    --v7;
    v13 = -(v12 / *(double *)(v11 - 788));
    *(double *)(v11 - 1124) = v13;
    *(double *)(v11 - 1116) = v13;
  }
  while ( v7 );
  v14 = *(_DWORD *)(this + 7700);
  if ( v14 )
  {
    v15 = v14 - 1;
    if ( v15 )
    {
      if ( v15 == 1 )
        v12 = (*(double *)(this + 1964) + *v10) * 0.5;
    }
    else
    {
      v12 = (*(double *)(this + 4212) + *(double *)(this + 3088) + *(double *)(this + 1964) + *v10) * 0.25;
    }
  }
  else
  {
    v12 = (*(double *)(this + 4212) + *(double *)(this + 3088)) * 0.5;
  }
  v16 = fabs(v33) * 0.018 + 0.2;
  if ( v16 >= 0.0 )
  {
    if ( v16 > 0.8 )
      v16 = 0.8;
  }
  else
  {
    v16 = 0.0;
  }
  v17 = *(_DWORD *)(this + 7852);
  v18 = v17;
  *(double *)(this + 7260) = -(v12 * *(double *)(this + 8 * v17 + 7856));
  if ( v17 > 0 )
  {
    v19 = v16 * *(double *)(this + 7388);
    v20 = (double *)(this + 8 * v17 + 7856);
    do
    {
      v21 = -(v12 * *v20);
      if ( v21 < v19 )
      {
        *(long double *)(this + 7260) = v21;
        v17 = v18;
      }
      --v18;
      --v20;
    }
    while ( v18 > 0 );
  }
  if ( *(double *)(this + 7260) < *(double *)(this + 7300) )
  {
    sub_447E00(0, 4);
    v22 = *(_DWORD *)(this + 7304);
    *(_DWORD *)(this + 7260) = *(_DWORD *)(this + 7300);
    *(_DWORD *)(this + 7264) = v22;
  }
  else
  {
    sub_447E00(v17, 4);
  }
  v23 = *(_DWORD *)(this + 7264);
  v24 = *(_DWORD *)(this + 7260);
  *(_DWORD *)(this + 7268) = v24;
  *(_DWORD *)(this + 7272) = v23;
  *(_DWORD *)(this + 7736) = v24;
  *(_DWORD *)(this + 7740) = v23;
  *(_DWORD *)(this + 7744) = v24;
  *(_DWORD *)(this + 7748) = v23;
  sub_4471F0(this, 1);
  v25 = this + 1004;
  *(_DWORD *)(this + 208) = 0;
  v30 = this + 1004;
  v32 = 2;
  do
  {
    if ( *(_DWORD *)v25 )
    {
      if ( !*(_BYTE *)(v25 + 100) )
      {
        qmemcpy(v37, (const void *)(*(_DWORD *)(this + 5616) + 28), sizeof(v37));
        sub_56BDE0(v25 - 204, 0);
        qmemcpy(v36, (const void *)(*(_DWORD *)(this + 5616) + 124), sizeof(v36));
        v26 = *(_DWORD *)v30;
        qmemcpy((void *)(*(_DWORD *)v30 + 28), v37, 0x48u);
        v34 = v26;
        sub_5692A0(v26);
        qmemcpy((void *)(v34 + 124), v36, 0x18u);
        sub_569410(v34);
        sub_441450((int *)this);
        v25 = v30;
      }
    }
    v25 += 1124;
    result = v32 - 1;
    v27 = v32 == 1;
    v30 = v25;
    --v32;
  }
  while ( !v27 );
  return result;
}
