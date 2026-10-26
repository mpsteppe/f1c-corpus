int __thiscall sub_45B470(int this, int *a2, _DWORD *a3)
{
  _DWORD *v3; // edi
  int *v5; // ebx
  int v6; // ebp
  int *v7; // eax
  int v8; // edx
  int *v9; // ebp
  int v10; // ebx
  int v12; // ecx
  int v13; // ecx
  int v14; // ebp
  float *v15; // ebx
  float v16; // eax
  double v17; // st7
  float v18; // ecx
  char v19; // cl
  char v20; // al
  char v21; // cl
  int v22; // edx
  int v23; // edx
  float v24; // eax
  float v25; // eax
  float v26; // edx
  int v27; // [esp+16h] [ebp-38h] BYREF
  float v28; // [esp+1Ah] [ebp-34h]
  float v29; // [esp+1Eh] [ebp-30h]
  int v30; // [esp+22h] [ebp-2Ch]
  int v31; // [esp+26h] [ebp-28h]
  float v32; // [esp+2Ah] [ebp-24h]
  int v33; // [esp+2Eh] [ebp-20h]
  float v34[6]; // [esp+32h] [ebp-1Ch] BYREF
  float v35; // [esp+4Ah] [ebp-4h]

  v3 = a3;
  (*(void (__thiscall **)(_DWORD *, int, int))(*a3 + 24))(a3, this, 4);
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 24))(v3, this + 4, 4);
  v5 = a2;
  v6 = 0;
  v7 = a2;
  if ( !a2 )
  {
LABEL_8:
    v8 = *v3;
    LOBYTE(a2) = *(_BYTE *)(this + 8);
    (*(void (__thiscall **)(_DWORD *, int **, int))(v8 + 24))(v3, &a2, 1);
    *(_BYTE *)(this + 10) = -1;
    *(_BYTE *)(this + 11) = -1;
    *(_DWORD *)(this + 12) = v3[25] + 96 * v3[23];
    v3[23] += v6;
    v9 = v5;
    if ( v5 )
    {
      v10 = 0;
      do
      {
        v10 += 96;
        sub_45ABD0(v9, (int)v3);
        v9 = (int *)v9[7];
      }
      while ( v9 );
    }
    return 0;
  }
  do
  {
    v7 = (int *)v7[7];
    ++v6;
  }
  while ( v7 );
  if ( v6 < 3 )
  {
    if ( v6 == 1 )
    {
      *(_WORD *)(this + 8) = -1;
    }
    else if ( v6 == 2 )
    {
      *(_WORD *)(this + 8) = -2;
    }
    goto LABEL_8;
  }
  if ( v6 <= 100 )
    v12 = v6 <= 10 ? 15 : 6;
  else
    v12 = 3;
  if ( 14 / v12 >= 1 )
  {
    v31 = 14 / v12;
    v13 = 14 / v12;
  }
  else
  {
    v13 = 1;
    v31 = 1;
  }
  v30 = -1;
  v32 = 3.4028235e38;
  v14 = v6 % v13;
  if ( v14 >= 14 )
    goto LABEL_27;
  v33 = -4 * v13;
  v15 = &flt_B68608[-v14];
  do
  {
    if ( v14 > 7 )
    {
      v17 = -flt_B685B4[v14];
      v29 = *v15;
      v28 = v17;
    }
    else
    {
      v16 = *(v15 - 7);
      v29 = flt_B685D0[v14];
      v28 = v16;
    }
    sub_45B2A0(v34, a2, v3[29], v29, v28, 0);
    if ( v35 < (double)v32 )
    {
      v32 = v35;
      v30 = v14;
    }
    v14 += v31;
    v15 = (float *)((char *)v15 + v33);
  }
  while ( v14 < 14 );
  v5 = a2;
  if ( v30 > 7 )
  {
    v28 = -flt_B685B4[v30];
    v18 = flt_B68608[-v30];
  }
  else
  {
LABEL_27:
    v18 = flt_B685D0[v30];
    v28 = *((float *)&unk_B685EC - v30);
  }
  v29 = v18;
  sub_45B2A0(v34, v5, v3[29], v18, v28, 1);
  v19 = v30;
  if ( v30 > 7 )
  {
    v20 = 14 - v30;
    v21 = 15 - (14 - v30);
    *(_WORD *)(this + 8) = 1;
    *(_BYTE *)(this + 10) = v20;
    *(_BYTE *)(this + 11) = v21;
    if ( v21 == 15 )
      *(_BYTE *)(this + 11) = 0;
  }
  else
  {
    *(_WORD *)(this + 8) = 0;
    *(_BYTE *)(this + 10) = v19;
    *(_BYTE *)(this + 11) = 7 - v19;
  }
  v22 = *v3;
  LOBYTE(a3) = *(_BYTE *)(this + 8);
  (*(void (__thiscall **)(_DWORD *, _DWORD **, int))(v22 + 24))(v3, &a3, 1);
  v23 = *v3;
  HIBYTE(v27) = *(_BYTE *)(this + 10) + 16 * *(_BYTE *)(this + 11);
  (*(void (__thiscall **)(_DWORD *, char *, int))(v23 + 24))(v3, (char *)&v27 + 3, 1);
  v24 = v34[1];
  *(_DWORD *)(this + 12) = v3[28] + 16 * v3[26];
  v3[26] += 2;
  **(float **)(this + 12) = v24;
  v25 = v34[0];
  *(float *)(*(_DWORD *)(this + 12) + 4) = v34[2];
  if ( sub_45B470(LODWORD(v25), v3) )
    return -1;
  *(float *)(*(_DWORD *)(this + 12) + 16) = v34[4];
  v26 = v34[3];
  *(float *)(*(_DWORD *)(this + 12) + 20) = v34[5];
  return -(sub_45B470(LODWORD(v26), v3) != 0);
}
