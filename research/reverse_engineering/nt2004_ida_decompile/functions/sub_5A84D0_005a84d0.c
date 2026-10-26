int __thiscall sub_5A84D0(int *this, const char *a2, char a3, int a4)
{
  int v4; // ebx
  int v5; // ebp
  char v6; // al
  char *v7; // edi
  unsigned int v9; // ebp
  int v10; // eax
  const char *v11; // esi
  int v12; // eax
  int v13; // eax
  char v14; // cl
  size_t v15; // edi
  int v16; // ebx
  int v17; // esi
  unsigned int v18; // eax
  int v19; // esi
  unsigned int v20; // ebx
  void *v21; // ebp
  void *v22; // eax
  int v23; // eax
  const char *v24; // eax
  int v25; // eax
  int Error; // [esp-4h] [ebp-3A4h]
  int v27; // [esp-4h] [ebp-3A4h]
  int v28; // [esp+10h] [ebp-390h]
  int i; // [esp+10h] [ebp-390h]
  int v30; // [esp+14h] [ebp-38Ch]
  size_t ElementCount; // [esp+1Ch] [ebp-384h]
  void *v33; // [esp+20h] [ebp-380h]
  char Str[256]; // [esp+24h] [ebp-37Ch] BYREF
  _DWORD v35[31]; // [esp+124h] [ebp-27Ch] BYREF
  char Format[256]; // [esp+1A0h] [ebp-200h] BYREF
  char Buffer[256]; // [esp+2A0h] [ebp-100h] BYREF

  v4 = (int)this;
  v5 = 0;
  strcpy(Str, a2);
  _strupr(Str);
  if ( !strstr(Str, aBik_1) )
  {
    v6 = aBik_1[4];
    v7 = &Str[strlen(Str)];
    *(_DWORD *)v7 = *(_DWORD *)aBik_1;
    v7[4] = v6;
  }
  if ( (a3 & 1) != 0 && a4 )
  {
    if ( !BinkSetSoundSystem(BinkOpenMiles, a4) )
    {
      Error = BinkGetError();
      sprintf(Buffer, "Error: %s while setting Miles sound", Error);
LABEL_11:
      sub_591C60(v4, -1, Buffer);
      return -1;
    }
  }
  else if ( (a3 & 2) != 0 && a4 )
  {
    if ( !BinkSetSoundSystem(BinkOpenDirectSound, a4) )
    {
      v27 = BinkGetError();
      sprintf(Buffer, "Error: %s while setting DirectSound", v27);
      goto LABEL_11;
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
      v9 = v5 & 0x9FFFFFFF;
      if ( (a3 & 4) != 0 )
        v5 = v9 & 0x8FFFFFFF | 0x50000000;
      else
        v5 = v9 | 0x20000000;
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
  v10 = BinkOpen(Str, v5);
  *(_DWORD *)v4 = v10;
  if ( v10 )
    goto LABEL_50;
  v28 = 0;
  if ( dword_7E8D58 > 0 )
  {
    v11 = byte_7E4CCC;
    while ( 1 )
    {
      sprintf(Format, "%s\\%s", v11, Str);
      v12 = BinkOpen(Format, v5);
      *(_DWORD *)v4 = v12;
      if ( v12 )
        break;
      v11 += 132;
      if ( ++v28 >= dword_7E8D58 )
        goto LABEL_34;
    }
    v13 = 0;
    do
    {
      v14 = Format[v13];
      Str[v13++] = v14;
    }
    while ( v14 );
  }
LABEL_34:
  if ( v28 == dword_7E8D58 )
  {
    v15 = ::ElementCount;
    v30 = v5 | 0x4000000;
    for ( i = 0; v15; ++i )
    {
      if ( !sub_5AF100(Str) )
      {
        v16 = *(_DWORD *)(v15 + 296);
        v17 = *(_DWORD *)(v15 + 292) << 8;
        v18 = *(_DWORD *)(v17 + v16 + 8);
        v19 = v16 + v17;
        ElementCount = v18;
        v20 = *(_DWORD *)(v19 + 12);
        v21 = operator new(v18);
        v22 = operator new(v20);
        v33 = v22;
        if ( (*(_BYTE *)v19 & 0x10) != 0 )
        {
          if ( sub_5BED6F(v22, 1u, v20, *(FILE **)(v15 + 16)) != v20 || sub_5D2750(v33, v20) )
          {
LABEL_40:
            sub_5BE8AE();
            sub_5BE8AE();
            return -1;
          }
        }
        else if ( sub_5BED6F(v21, 1u, ElementCount, *(FILE **)(v15 + 16)) != ElementCount )
        {
          goto LABEL_40;
        }
        v23 = BinkOpen(v21, v30);
        *this = v23;
        v4 = (int)this;
        if ( v23 )
          break;
      }
      v15 = *(_DWORD *)(v15 + 304);
    }
  }
  else
  {
    i = -1;
  }
  if ( i != dword_7E5D54 )
  {
LABEL_50:
    BinkGetSummary(*(_DWORD *)v4, v35);
    v25 = v35[1];
    *(_DWORD *)(v4 + 268) = v35[0];
    *(_DWORD *)(v4 + 272) = v25;
    strcpy((char *)(v4 + 12), Str);
    _strupr((char *)(v4 + 12));
    return 0;
  }
  else
  {
    v24 = (const char *)BinkGetError();
    sprintf(Format, "Error: %s for BINK file %s", v24, Str);
    sub_591C60(v4, -1, Format);
    return -1;
  }
}
