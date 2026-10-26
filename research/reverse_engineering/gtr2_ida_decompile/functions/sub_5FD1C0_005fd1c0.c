int __thiscall sub_5FD1C0(int *this, int a2, int a3)
{
  int *v4; // eax
  _DWORD *v5; // ebx
  int *v6; // esi
  _DWORD **v8; // eax
  char *v9; // eax
  char v10; // cl
  int v11; // esi
  int *v12; // eax
  _DWORD *v13; // edi
  _DWORD *v14; // eax
  _DWORD *v15; // eax
  _DWORD *v16; // edx
  int v17; // esi
  int v18; // ecx
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // edx
  int v25; // ebx
  int v26; // eax
  char *v27; // esi
  char *v28; // edi
  unsigned int v29; // eax
  char *v30; // edi
  unsigned int v31; // ecx
  int v32; // edi
  int v33; // ecx
  int v34; // eax
  int v35; // edx
  char *v36; // edi
  char *v37; // esi
  unsigned int v38; // ebx
  char *v39; // edi
  unsigned int v40; // ecx
  char v41; // [esp-4h] [ebp-24h]
  char v42; // [esp-4h] [ebp-24h]
  char v43; // [esp-4h] [ebp-24h]
  int *Block; // [esp+10h] [ebp-10h]

  if ( (*(_DWORD *)a2 & 8) != 0 )
  {
    v4 = (int *)operator new(0x28Cu);
    v5 = 0;
    if ( v4 )
    {
      v6 = sub_5DB7E0(v4);
      Block = v6;
    }
    else
    {
      Block = 0;
      v6 = 0;
    }
    v6[155] = a3;
    if ( sub_5DCC20((char *)v6, (int)this, "PTEMP", (const char *)(a2 + 56), 0, 0) )
    {
      sub_5DBA90(v6);
      j__free(v6);
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error initializing GMT particle", v41);
      return -1;
    }
    if ( v6[136] > 0 )
    {
      v8 = (_DWORD **)v6[133];
      if ( v8 )
        v5 = *v8;
    }
    if ( (*v5 & 0x20) == 0 )
    {
      sub_5DBB20();
      sub_5DBA90(v6);
      j__free(v6);
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "GMT particle must be a trilist", v42);
      return -1;
    }
    if ( (int)v5[90] > 1 )
    {
      sub_5DBB20();
      sub_5DBA90(v6);
      j__free(v6);
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "GMT particle must have only 1 trilist", v43);
      return -1;
    }
    v9 = (char *)(a2 + 4);
    do
    {
      v10 = *v9;
      v9[(_DWORD)this - a2] = *v9;
      ++v9;
    }
    while ( v10 );
    v11 = *(_DWORD *)(a2 + 36);
    this[11] = v11;
    v12 = (int *)operator new(132 * v11 + 4);
    if ( v12 )
    {
      v13 = v12 + 1;
      *v12 = v11;
      sub_630A11(v12 + 1, 132, v11, sub_5FC790, j_nullsub_7);
      v14 = v13;
    }
    else
    {
      v14 = 0;
    }
    this[13] = (int)v14;
    this[15] = 1;
    v15 = operator new(0x6Cu);
    if ( v15 )
      v16 = sub_5FC740(v15);
    else
      v16 = 0;
    this[16] = (int)v16;
    memset(v16, 0, 0x6Cu);
    if ( (*(_BYTE *)a2 & 0x10) != 0 )
      *this = 16;
    if ( (*(_BYTE *)a2 & 0x20) != 0 )
      *this = 32;
    v17 = *this | 8;
    *this = v17;
    if ( (*(_DWORD *)a2 & 0x200) != 0 )
      *this = v17 | 0x600;
    if ( (*(_DWORD *)a2 & 0x1000) != 0 )
      *this |= 0x1000u;
    v18 = this[16];
    this[9] = 0;
    this[10] = 0;
    *(_DWORD *)(v18 + 4) = *(_DWORD *)(v5[91] + 4);
    sub_5E8E90(*(_DWORD **)(this[16] + 4));
    this[9] = *(_DWORD *)(v5[91] + 8);
    v19 = this[9] * this[11];
    v20 = this[16];
    this[10] = *(_DWORD *)(v5[91] + 36);
    *(_DWORD *)(v20 + 8) = v19;
    *(_DWORD *)(this[16] + 36) = this[10] * this[11];
    v21 = this[9];
    this[19] = v21;
    this[20] = (int)operator new(v21 << 6);
    v22 = this[10];
    this[21] = v22;
    this[22] = (int)operator new(2 * v22);
    v23 = this[11] * this[19];
    this[23] = v23;
    this[24] = (int)operator new(v23 << 6);
    *(_DWORD *)this[16] |= 0x4040u;
    v24 = v5[91];
    v25 = 0;
    if ( this[19] > 0 )
    {
      v26 = 0;
      do
      {
        if ( (*(_BYTE *)v24 & 8) == 0 )
          qmemcpy((void *)(v26 + this[20]), (const void *)(v26 + *(_DWORD *)(v24 + 32)), 0x40u);
        ++v25;
        v26 += 64;
      }
      while ( v25 < this[19] );
    }
    v27 = *(char **)(v24 + 40);
    v28 = (char *)this[22];
    v29 = 2 * this[21];
    qmemcpy(v28, v27, 4 * (v29 >> 2));
    v30 = &v28[4 * (v29 >> 2)];
    v31 = v29 & 3;
    qmemcpy(v30, &v27[4 * (v29 >> 2)], v31);
    v32 = (int)&v30[v31];
    if ( *(float *)(v24 + 100) > 0.0 )
      *(_DWORD *)v24 |= 0x2000u;
    this[18] = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
                 dword_FB27A4,
                 "L0NOLIGHTING",
                 0);
    sub_5DBB20();
    sub_5DBA90(Block);
    j__free(Block);
    if ( (*(_DWORD *)a2 & 0x400) != 0 )
    {
      v33 = this[11];
      v34 = 0;
      *this |= 0x400u;
      if ( v33 > 0 )
      {
        v35 = 0;
        do
        {
          *(_DWORD *)(v35 + this[13] + 128) = this[24] + ((v34 * this[9]) << 6);
          v36 = *(char **)(v35 + this[13] + 128);
          v37 = (char *)this[20];
          v38 = this[9] << 6;
          qmemcpy(v36, v37, 4 * (v38 >> 2));
          v39 = &v36[4 * (v38 >> 2)];
          v40 = v38 & 3;
          qmemcpy(v39, &v37[4 * (v38 >> 2)], v40);
          v32 = (int)&v39[v40];
          ++v34;
          v35 += 132;
        }
        while ( v34 < this[11] );
      }
    }
    this[14] = (int)operator new(4 * this[11]);
    if ( sub_5FC840(this, (int)this, v32, 0) )
      return -1;
  }
  return 0;
}
