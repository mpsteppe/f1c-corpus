int __thiscall sub_5429B0(_DWORD *this, const char *a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  _DWORD *v9; // eax
  _DWORD *v10; // ebp
  unsigned int v12; // ecx
  char v13; // dl
  unsigned int v14; // ecx
  char v15; // dl
  const char *v16; // ecx
  int v17; // eax
  int v18; // edi
  int v19; // edi
  int v20; // ebp
  int v21; // edx
  int v22; // eax
  int v23; // eax
  int v24; // edi
  int v25; // [esp-4h] [ebp-62Ch]
  char v26[16]; // [esp+18h] [ebp-610h] BYREF
  CHAR SrcStr[768]; // [esp+28h] [ebp-600h] BYREF
  _BYTE v28[768]; // [esp+328h] [ebp-300h] BYREF

  if ( (a6 & 0xF) != 0 )
  {
    v7 = (_DWORD *)OperatorNewNhMallocWrapper(60);
    if ( v7 )
      v8 = AudioEmitterCreate(v7);
    else
      v8 = 0;
    if ( (a6 & 0x800) != 0 )
    {
      v8[6] |= 0x800u;
      sub_5435C0(this[13]);
    }
    if ( ((unsigned int)&unk_800000 & a6) != 0 )
      v8[6] |= (unsigned int)&unk_800000;
    if ( (a6 & 0x4000) != 0 )
    {
      strcpy(SrcStr, a2);
      sub_589901(SrcStr);
      v9 = (_DWORD *)OperatorNewNhMallocWrapper(60);
      if ( v9 )
        v10 = AudioEmitterCreate(v9);
      else
        v10 = 0;
      if ( (a6 & 0x800) != 0 )
      {
        v10[6] |= 0x800u;
        sub_5435C0(this[13]);
      }
      if ( ((unsigned int)&unk_800000 & a6) != 0 )
        v10[6] |= (unsigned int)&unk_800000;
      v10[6] |= 1u;
      if ( sub_542EC0(SrcStr) )
      {
LABEL_18:
        EmptyStub_7470(v10);
        FreeWrapper_7bcf(v10);
        return -1;
      }
      v8[6] |= 4u;
      v8[7] = v10[7];
      v8[8] = v10[8];
      v8[12] = v10[12];
      v25 = this[11];
      v8[11] = v25;
      if ( sub_53F720((int)dword_8B78A0, v8, v25) || sub_53FC30(dword_8B78A0, v10, v8, 0) )
        return -1;
      sub_542E50(v10);
      v12 = strlen(SrcStr) + 1;
      v13 = v26[v12 + 14];
      v14 = v12 - 2;
      if ( v13 != 46 )
      {
        do
        {
          if ( !v14 )
            break;
          v15 = v26[v14-- + 15];
        }
        while ( v15 != 46 );
      }
      v16 = &SrcStr[v14];
      strcpy(v26, v16);
      v17 = this[11];
      v18 = 1;
      *v16 = 0;
      if ( v17 > 1 )
      {
        do
        {
          if ( (a6 & 0x800) != 0 )
          {
            v10[6] |= 0x800u;
            sub_5435C0(this[13]);
          }
          if ( ((unsigned int)&unk_800000 & a6) != 0 )
            v10[6] |= (unsigned int)&unk_800000;
          v10[6] |= 1u;
          StringFormatWithBufferOverflowCheck(v28, "%s_MIP%.2d%s", SrcStr, v18, v26);
          if ( sub_542EC0(v28) )
            goto LABEL_18;
          if ( sub_53FC30(dword_8B78A0, v10, v8, v18) )
            return -1;
          sub_542E50(v10);
        }
        while ( ++v18 < this[11] );
      }
      EmptyStub_7470(v10);
      FreeWrapper_7bcf(v10);
      v19 = a4;
      v20 = a3;
    }
    else
    {
      v20 = a3;
      v19 = a4;
      v21 = v8[6] | 1;
      v8[7] = a3;
      v8[8] = a4;
      v8[6] = v21;
      if ( (a6 & 0x1000000) == 0 && sub_542EC0(a2) )
        goto LABEL_61;
    }
    if ( (a6 & 0x800) != 0 )
      sub_5435C0(0);
    v22 = 8;
    if ( v8[12] == 8 )
      this[6] |= (unsigned int)&unk_800000;
    else
      v22 = a5;
    if ( sub_5426E0(this, v22, a6) )
      goto LABEL_56;
    if ( v20 )
      this[7] = v20;
    else
      this[7] = v8[7];
    if ( v19 )
      this[8] = v19;
    else
      this[8] = v8[8];
    v23 = a6;
    this[6] = a6;
    v24 = v8[6] & 0xF;
    if ( (a6 & 1) != 0 )
    {
      if ( DirectXDeviceSurfaceCreationWithFormatCapability(dword_8B78A0, v8, v24, this, 1, a6 & 0x1000000) )
        goto LABEL_56;
      v23 = a6;
    }
    if ( (this[6] & 2) != 0 )
    {
      if ( DirectXDeviceSurfaceCreationWithFormatCapability(dword_8B78A0, v8, v24, this, 2, v23 & 0x1000000) )
      {
LABEL_56:
        sub_542E50(v8);
        EmptyStub_7470(v8);
        FreeWrapper_7bcf(v8);
        return -1;
      }
      v23 = a6;
    }
    if ( (this[6] & 4) != 0 )
    {
      if ( DirectXDeviceSurfaceCreationWithFormatCapability(dword_8B78A0, v8, v24, this, 4, v23 & 0x1000000) )
        goto LABEL_56;
      v23 = a6;
    }
    if ( (this[6] & 8) != 0
      && DirectXDeviceSurfaceCreationWithFormatCapability(dword_8B78A0, v8, v24, this, 8, v23 & 0x1000000) )
    {
      sub_542E50(v8);
LABEL_61:
      EmptyStub_7470(v8);
      FreeWrapper_7bcf(v8);
      return -1;
    }
    sub_542E50(v8);
    EmptyStub_7470(v8);
    FreeWrapper_7bcf(v8);
  }
  return 0;
}
