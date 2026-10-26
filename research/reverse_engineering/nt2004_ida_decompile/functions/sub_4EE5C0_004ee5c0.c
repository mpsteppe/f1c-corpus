int __thiscall sub_4EE5C0(int this, int a2, float a3)
{
  double v4; // st7
  __int16 *v5; // ebp
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  double v11; // st7
  double v12; // st7
  int v13; // esi
  int v14; // edx
  int v15; // eax
  int v16; // edx
  float v17; // edx
  float v18; // ecx
  int v19; // eax
  int v20; // esi
  int v21; // eax
  int v22; // ecx
  int i; // eax
  double v24; // st7
  long double v25; // st7
  int j; // esi
  int v27; // eax
  int k; // esi
  int m; // esi
  int v30; // eax
  char v31; // al
  int v32; // eax
  int v34; // [esp-14h] [ebp-ACh]
  float v35; // [esp+0h] [ebp-98h]
  float v36; // [esp+4h] [ebp-94h]
  float *v37; // [esp+8h] [ebp-90h]
  int v38; // [esp+Ch] [ebp-8Ch]
  float v39; // [esp+Ch] [ebp-8Ch]
  int v40; // [esp+10h] [ebp-88h] BYREF
  int v41; // [esp+14h] [ebp-84h]
  int v42; // [esp+18h] [ebp-80h]
  float v43; // [esp+1Ch] [ebp-7Ch]
  _DWORD v44[3]; // [esp+20h] [ebp-78h] BYREF
  float v45; // [esp+2Ch] [ebp-6Ch]
  float v46[3]; // [esp+30h] [ebp-68h] BYREF
  _BYTE v47[44]; // [esp+3Ch] [ebp-5Ch] BYREF
  float v48[3]; // [esp+68h] [ebp-30h] BYREF
  _BYTE v49[36]; // [esp+74h] [ebp-24h] BYREF

  v4 = a3 - *(float *)(this + 25284);
  *(float *)(this + 25284) = a3;
  v5 = (__int16 *)(a2 + 8);
  v45 = v4;
  v6 = *(_DWORD *)(a2 + 40);
  v7 = *(_DWORD *)(a2 + 44);
  v40 = *(_DWORD *)(a2 + 36);
  v41 = v6;
  v8 = *(_DWORD *)(a2 + 48);
  v42 = v7;
  v9 = *(_DWORD *)(a2 + 52);
  v10 = *(_DWORD *)(a2 + 56);
  v44[0] = v8;
  v44[1] = v9;
  v44[2] = v10;
  sub_579100(v44, v49);
  sub_50CAA0(&v40, v44, v49);
  v11 = sub_4D03F0((_DWORD *)(a2 + 8));
  v35 = v11;
  if ( v11 >= -1.0 )
  {
    if ( v35 <= 1.0 )
    {
      if ( v35 < -1.0 )
        goto LABEL_13;
      if ( v35 > 1.0 )
      {
        v12 = 1.0;
        goto LABEL_4;
      }
      if ( v35 < -1.0 )
      {
LABEL_13:
        v12 = -1.0;
        goto LABEL_4;
      }
    }
    else
    {
      v35 = 1.0;
    }
  }
  else
  {
    v35 = -1.0;
  }
  v12 = v35;
LABEL_4:
  *(float *)(this + 4712) = v12;
  v13 = 0;
  v37 = (float *)(this + 2372);
  v43 = *(float *)(this + 4720) * v35;
  do
  {
    sub_4D0130(v5, v13, (float *)&v47[4 * v13 + 12], (float *)&v47[4 * v13 + 28]);
    *(float *)&v38 = v45 * *(float *)&v47[4 * v13 + 28] + *v37;
    if ( v13 >= 2 )
      sub_50CB70(v13, *(float *)&v47[4 * v13 + 12], *(float *)&v38, 0.0);
    else
      sub_50CB70(v13, *(float *)&v47[4 * v13 + 12], *(float *)&v38, v43);
    ++v13;
    v37 += 76;
  }
  while ( v13 < 4 );
  sub_4CFBA0((_DWORD *)(a2 + 24), v46);
  sub_4CFD10(a2 + 24, v48);
  sub_4CFF40((int)v5, (int)v47);
  v36 = sub_4D0310(v5);
  v39 = sub_4D0370(v5);
  v14 = v40;
  *(float *)(this + 236) = v39;
  v15 = v41;
  *(_DWORD *)(this + 100) = v14;
  v16 = v42;
  *(_DWORD *)(this + 104) = v15;
  *(_DWORD *)(this + 108) = v16;
  v17 = v46[1];
  qmemcpy((void *)(this + 124), v49, 0x24u);
  *(float *)(this + 160) = v46[0];
  v18 = v46[2];
  *(float *)(this + 164) = v17;
  *(float *)(this + 168) = v18;
  *(float *)(this + 232) = v36;
  *(_BYTE *)(this + 20812) = *(_BYTE *)(a2 + 10) & 1;
  v19 = *(_DWORD *)(this + 16584);
  if ( v19 == 2 )
  {
    *(float *)(this + 17764) = v35;
    v20 = this + 84;
    v21 = sub_4D03B0(v5);
    sub_51E230(&v40, v44, v49, v46, v48, v47, v21);
    sub_51E380(SLODWORD(v36), 0.5, SLODWORD(v39));
    v22 = 0;
    for ( i = 0; i < 16; *(float *)(v22 + v20 + 17492) = *(float *)&v47[i + 24] )
    {
      v24 = *(float *)&v47[i + 12];
      i += 4;
      *(float *)(v22 + v20 + 17708) = v24;
      v22 += 248;
    }
    v25 = a3 - *(float *)(this + 25280);
    *(_BYTE *)(this + 17412) = (*(_DWORD *)(a2 + 12) & 0x2000000) != 0;
    if ( fabs(v25) > 15.0 )
    {
      *(float *)(this + 25280) = a3;
      for ( j = 0; j < 18; ++j )
      {
        v27 = sub_4D04F0(v5, j);
        sub_50BDD0(j, v27);
      }
    }
    *(_BYTE *)(this + 21121) = (*(_DWORD *)v5 & 0x80) != 0;
  }
  else if ( v19 == 3 )
  {
    sub_51E3B0(v49, v47);
    for ( k = 0; k < 4; ++k )
      sub_50C860(k, *(float *)&v47[4 * k + 28]);
    for ( m = 0; m < 18; ++m )
    {
      v30 = sub_4D04F0(v5, m);
      sub_50BDD0(m, v30);
    }
    sub_4EEC50(*(_BYTE *)(a2 + 15) & 1);
    sub_4EEC20(*(_BYTE *)(a2 + 15) & 1);
  }
  v31 = (*(_DWORD *)(a2 + 12) & 0x8000000) != 0;
  if ( *(_BYTE *)(this + 4769) != v31 )
  {
    v34 = *(_DWORD *)(this + 4760);
    *(_BYTE *)(this + 4769) = v31;
    sub_50B4E0(v34, 1);
  }
  *(_BYTE *)(this + 4777) = (*(_DWORD *)(a2 + 12) & 0x4000000) != 0;
  v32 = sub_4D0520(v5);
  sub_4EED80(v32);
  *(_WORD *)(this + 25276) = sub_4D0550(v5);
  return sub_4DEA70(this + 20836, *(int *)(a2 + 12) < 0);
}
