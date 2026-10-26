void __thiscall sub_4C73F0(int this, int a2, float a3)
{
  double v4; // st7
  char *v5; // ebp
  double v6; // st7
  double v7; // st7
  int v8; // esi
  float *v9; // edi
  int v10; // edx
  int v11; // eax
  int v12; // edx
  float v13; // edx
  float v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  float *v18; // ecx
  double v19; // st7
  long double v20; // st7
  int i; // esi
  int v22; // eax
  int j; // esi
  int k; // esi
  int v25; // eax
  char v26; // al
  bool v27; // al
  int v28; // eax
  int v29; // [esp-10h] [ebp-9Ch]
  float v30; // [esp+0h] [ebp-8Ch]
  float v31; // [esp+4h] [ebp-88h]
  int v32; // [esp+8h] [ebp-84h] BYREF
  float *v33; // [esp+Ch] [ebp-80h]
  int v34; // [esp+10h] [ebp-7Ch]
  float v35; // [esp+14h] [ebp-78h]
  float v36; // [esp+18h] [ebp-74h]
  _DWORD v37[3]; // [esp+1Ch] [ebp-70h] BYREF
  float v38[3]; // [esp+28h] [ebp-64h] BYREF
  float v39[3]; // [esp+34h] [ebp-58h] BYREF
  _BYTE v40[12]; // [esp+40h] [ebp-4Ch] BYREF
  float v41[4]; // [esp+4Ch] [ebp-40h] BYREF
  float v42[3]; // [esp+5Ch] [ebp-30h] BYREF
  _BYTE v43[36]; // [esp+68h] [ebp-24h] BYREF

  v4 = a3 - *(float *)(this + 18616);
  *(float *)(this + 18616) = a3;
  v36 = v4;
  v5 = (char *)(a2 + 8);
  sub_4B2420((_DWORD *)(a2 + 8), v37, v39);
  sub_566E40(v39, v43);
  sub_4E23D0(v37, v39, v43);
  v6 = sub_4B2A80((_DWORD *)(a2 + 8));
  v30 = v6;
  if ( v6 >= -1.0 )
  {
    if ( v30 <= 1.0 )
    {
      if ( v30 < -1.0 )
        goto LABEL_13;
      if ( v30 > 1.0 )
      {
        v7 = 1.0;
        goto LABEL_4;
      }
      if ( v30 < -1.0 )
      {
LABEL_13:
        v7 = -1.0;
        goto LABEL_4;
      }
    }
    else
    {
      v30 = 1.0;
    }
  }
  else
  {
    v30 = -1.0;
  }
  v7 = v30;
LABEL_4:
  *(float *)(this + 4160) = v7;
  v8 = 0;
  v9 = v41;
  v35 = *(float *)(this + 4164) * v30;
  v33 = (float *)(this + 2240);
  do
  {
    sub_4B28F0(v5, v8, (float *)&v32, v9);
    *(float *)&v34 = v36 * *v9 + *v33;
    if ( v8 >= 2 )
      sub_4E24A0(v8, *(float *)&v32, v34, 0.0);
    else
      sub_4E24A0(v8, *(float *)&v32, v34, v35);
    ++v8;
    ++v9;
    v33 += 74;
  }
  while ( v8 < 4 );
  sub_4B2580((__int16 *)v5, v38);
  sub_4B26D0((int)v5, v42);
  sub_4B2800((__int16 *)v5, (int)v40);
  v31 = sub_4B2980(v5);
  *(float *)&v32 = sub_4B29F0(v5);
  v10 = v37[0];
  *(float *)(this + 164) = *(float *)&v32;
  v11 = v37[1];
  *(_DWORD *)(this + 28) = v10;
  v12 = v37[2];
  *(_DWORD *)(this + 32) = v11;
  *(_DWORD *)(this + 36) = v12;
  v13 = v38[1];
  qmemcpy((void *)(this + 52), v43, 0x24u);
  *(float *)(this + 88) = v38[0];
  v14 = v38[2];
  *(float *)(this + 92) = v13;
  *(float *)(this + 96) = v14;
  *(float *)(this + 160) = v31;
  *(_BYTE *)(this + 4201) = (*(_DWORD *)(a2 + 52) & 0x80) != 0;
  v15 = *(_DWORD *)(this + 13000);
  if ( v15 == 2 )
  {
    *(float *)(this + 13696) = v30;
    v16 = sub_4B2A30(v5);
    sub_4F1650(v37, v39, v43, v38, v42, v40, v16);
    sub_4F17A0(SLODWORD(v31), 0.5, v32);
    v17 = 0;
    v18 = (float *)(this + 13756);
    do
    {
      v19 = v41[v17++];
      *v18 = v19;
      v18 += 62;
    }
    while ( v17 < 4 );
    v20 = a3 - *(float *)(this + 18612);
    *(_BYTE *)(this + 13388) = *(int *)(a2 + 56) < 0;
    if ( fabs(v20) > 15.0 )
    {
      *(float *)(this + 18612) = a3;
      for ( i = 0; i < 14; ++i )
      {
        v22 = sub_4B2AD0(v5, i);
        sub_4E17C0(i, v22);
      }
    }
  }
  else if ( v15 == 3 )
  {
    sub_4F17D0(v43, v40);
    for ( j = 0; j < 4; ++j )
      sub_4E2230(j, v41[j]);
    for ( k = 0; k < 14; ++k )
    {
      v25 = sub_4B2AD0(v5, k);
      sub_4E17C0(k, v25);
    }
  }
  v26 = (*(_DWORD *)(a2 + 56) & 0x8000000) != 0;
  if ( *(_BYTE *)(this + 4189) != v26 )
  {
    v29 = *(_DWORD *)(this + 4180);
    *(_BYTE *)(this + 4189) = v26;
    sub_4E0ED0(v29);
  }
  v27 = (*(_DWORD *)(a2 + 56) & 0x4000000) != 0;
  *(_BYTE *)(this + 4197) = v27;
  if ( v27 )
    *(_DWORD *)(this + 13700) = 1065353216;
  else
    *(_DWORD *)(this + 13700) = 0;
  *(_BYTE *)(this + 4199) = (*(_DWORD *)(a2 + 56) & 0x2000000) != 0;
  v28 = sub_4B2B00(v5);
  sub_4C7BF0(v28);
  *(_WORD *)(this + 18608) = sub_4B2B80(v5);
  *(_BYTE *)(this + 16420) = *(_BYTE *)(a2 + 59) & 1;
  *(float *)(this + 16424) = sub_4B2B40(v5);
}
