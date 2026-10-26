int __thiscall sub_5F4640(int this, const char *a2, char a3, int a4)
{
  int v4; // esi
  char *v6; // edi
  char Error; // al
  char v10; // al
  unsigned int v11; // esi
  int v12; // eax
  _DWORD *v13; // eax
  int v14; // eax
  char v15; // [esp+Fh] [ebp-17Dh] BYREF
  char Str[256]; // [esp+10h] [ebp-17Ch] BYREF
  _BYTE v17[124]; // [esp+110h] [ebp-7Ch] BYREF

  v4 = 0;
  strcpy(Str, a2);
  _strupr(Str);
  if ( !strstr(Str, ".BIK") )
  {
    v6 = &v15;
    while ( *++v6 )
      ;
    strcpy(v6, ".BIK");
  }
  if ( (a3 & 1) != 0 && a4 )
  {
    if ( !BinkSetSoundSystem(BinkOpenMiles, a4) )
    {
      Error = BinkGetError();
      sub_5D8C80(this, (char *)0xFFFFFFFF, "Error: %s while setting Miles sound", Error);
      return -1;
    }
  }
  else if ( (a3 & 2) != 0 && a4 )
  {
    if ( !BinkSetSoundSystem(BinkOpenDirectSound, a4) )
    {
      v10 = BinkGetError();
      sub_5D8C80(this, (char *)0xFFFFFFFF, "Error: %s while setting DirectSound", v10);
      return -1;
    }
  }
  else
  {
    BinkSetSoundTrack(0, 0);
    v4 = 0x4000;
  }
  if ( (a3 & 0x10) != 0 )
  {
    v4 |= 0x60000000u;
    if ( (a3 & 4) != 0 )
      v4 |= 0x30000000u;
    if ( (a3 & 8) != 0 )
    {
      v11 = v4 & 0x9FFFFFFF;
      if ( (a3 & 4) != 0 )
        v4 = v11 & 0x8FFFFFFF | 0x50000000;
      else
        v4 = v11 | 0x20000000;
    }
  }
  else
  {
    if ( (a3 & 4) != 0 )
      v4 |= 0x30000000u;
    if ( (a3 & 8) != 0 )
    {
      if ( (a3 & 4) != 0 )
        v4 = v4 & 0x8FFFFFFF | 0x40000000;
      else
        v4 |= 0x10000000u;
    }
  }
  v12 = BinkOpen(Str, v4);
  *(_DWORD *)(this + 4) = v12;
  if ( v12 )
    goto LABEL_32;
  v13 = (_DWORD *)sub_5E0740((void *)this, Str, 0);
  if ( !v13 )
  {
    sub_5D8C80(this, (char *)0xFFFFFFFF, "Error locating BINK file %s", (char)Str);
    return -1;
  }
  v14 = BinkOpen(*v13, v4 | 0x4000000);
  *(_DWORD *)(this + 4) = v14;
  if ( v14 )
  {
LABEL_32:
    BinkGetSummary(*(_DWORD *)(this + 4), v17);
    strcpy((char *)(this + 20), Str);
    _strupr((char *)(this + 20));
    return 0;
  }
  else
  {
    sub_5D8C80(this, (char *)0xFFFFFFFF, "Error opening BINK file %s", (char)Str);
    return -1;
  }
}
