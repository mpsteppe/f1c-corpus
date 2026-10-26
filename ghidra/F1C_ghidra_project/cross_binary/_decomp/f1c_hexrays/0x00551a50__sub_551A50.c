// f1c  0x00551a50  size=644
int __thiscall sub_551A50(int *this, const char *a2, char a3, int a4)
{
  int *v4; // esi
  int v5; // ebp
  char v6; // al
  CHAR *v7; // edi
  const char *Error; // eax
  const char *v10; // eax
  unsigned int v11; // ebp
  int v12; // eax
  int v13; // edi
  const char *v14; // esi
  int v15; // eax
  const char *v16; // eax
  int v17; // edx
  CHAR SrcStr[256]; // [esp+14h] [ebp-37Ch] BYREF
  _DWORD v20[31]; // [esp+114h] [ebp-27Ch] BYREF
  char v21[256]; // [esp+190h] [ebp-200h] BYREF
  char v22[256]; // [esp+290h] [ebp-100h] BYREF

  v4 = this;
  v5 = 0;
  strcpy(SrcStr, a2);
  sub_589901(SrcStr);
  if ( !sub_587C20(SrcStr, aBik) )
  {
    v6 = aBik[4];
    v7 = &SrcStr[strlen(SrcStr)];
    *(_DWORD *)v7 = *(_DWORD *)aBik;
    v7[4] = v6;
  }
  if ( (a3 & 1) != 0 && a4 )
  {
    if ( !BinkSetSoundSystem(BinkOpenMiles, a4) )
    {
      Error = (const char *)BinkGetError();
      sub_58815F(v21, "Error: %s while setting Miles sound", Error);
      sub_53C590(-1, v21);
      return -1;
    }
  }
  else if ( (a3 & 2) != 0 && a4 )
  {
    if ( !BinkSetSoundSystem(BinkOpenDirectSound, a4) )
    {
      v10 = (const char *)BinkGetError();
      sub_58815F(v21, "Error: %s while setting DirectSound", v10);
      sub_53C590(-1, v21);
      return -1;
    }
  }
  else
  {
    BinkSetSoundTrack(0, 0);
    v5 = 0x4000;
  }
  if ( (a3 & 0x10) != 0 )
  {
    v5 |= 0x60000000u;
    if ( (a3 & 4) != 0 )
      v5 |= 0x30000000u;
    if ( (a3 & 8) != 0 )
    {
      v11 = v5 & 0x9FFFFFFF;
      if ( (a3 & 4) != 0 )
        v5 = v11 & 0x8FFFFFFF | 0x50000000;
      else
        v5 = v11 | 0x20000000;
    }
  }
  else
  {
    if ( (a3 & 4) != 0 )
      v5 |= 0x30000000u;
    if ( (a3 & 8) != 0 )
    {
      if ( (a3 & 4) != 0 )
        v5 = v5 & 0x8FFFFFFF | 0x40000000;
      else
        v5 |= 0x10000000u;
    }
  }
  v12 = BinkOpen(SrcStr, v5);
  *v4 = v12;
  if ( v12 )
    goto LABEL_33;
  v13 = 0;
  if ( dword_8B8E30 > 0 )
  {
    v14 = byte_8B5A3C;
    do
    {
      sub_58815F(v22, "%s\\%s", v14, SrcStr);
      v15 = BinkOpen(v22, v5);
      *this = v15;
      if ( v15 )
        break;
      ++v13;
      v14 += 132;
    }
    while ( v13 < dword_8B8E30 );
    v4 = this;
  }
  if ( v13 != dword_8B8E30 )
  {
LABEL_33:
    BinkGetSummary(*v4, v20);
    v17 = v20[0];
    v4[3] = v20[1];
    v4[2] = v17;
    return 0;
  }
  else
  {
    v16 = (const char *)BinkGetError();
    sub_58815F(v22, "Error: %s for BINK file %s", v16, SrcStr);
    sub_53C590(-1, v22);
    return -1;
  }
}
