int __cdecl _setmbcp(int CodePage)
{
  UINT SystemCP; // eax
  UINT v2; // ebx
  int v3; // esi
  int v4; // edx
  _DWORD *v5; // eax
  BYTE *v6; // ecx
  BYTE v7; // dl
  unsigned int i; // eax
  int v9; // esi
  char *v10; // ebx
  unsigned __int8 *v11; // ecx
  unsigned __int8 v12; // dl
  unsigned int v13; // eax
  unsigned int v14; // edi
  char v15; // dl
  LCID v16; // eax
  _DWORD *v17; // esi
  unsigned int j; // eax
  _cpinfo CPInfo; // [esp+Ch] [ebp-18h] BYREF
  unsigned int v21; // [esp+20h] [ebp-4h]
  int CodePagea; // [esp+2Ch] [ebp+8h]

  _lock(25);
  SystemCP = getSystemCP(CodePage);
  v2 = SystemCP;
  CodePagea = SystemCP;
  if ( SystemCP == dword_800180 )
  {
LABEL_2:
    v3 = 0;
    goto LABEL_34;
  }
  if ( !SystemCP )
  {
LABEL_31:
    setSBCS();
LABEL_32:
    setSBUpLow();
    goto LABEL_2;
  }
  v4 = 0;
  v5 = &unk_6287E8;
  do
  {
    if ( *v5 == v2 )
    {
      v21 = 0;
      memset(&unk_8002A0, 0, 0x100u);
      v9 = 48 * v4;
      unk_8003A0 = 0;
      v10 = (char *)&unk_6287F8 + 48 * v4;
      do
      {
        v11 = (unsigned __int8 *)v10;
        if ( *v10 )
        {
          do
          {
            v12 = v11[1];
            if ( !v12 )
              break;
            v13 = *v11;
            v14 = v12;
            if ( v13 <= v12 )
            {
              v15 = byte_6287E0[v21];
              do
                byte_8002A1[v13++] |= v15;
              while ( v13 <= v14 );
            }
            v11 += 2;
          }
          while ( *v11 );
        }
        ++v21;
        v10 += 8;
      }
      while ( v21 < 4 );
      dword_80019C = 1;
      dword_800180 = CodePagea;
      v16 = CPtoLCID(CodePagea);
      v17 = (_DWORD *)((char *)&unk_6287EC + v9);
      unk_800190 = *v17++;
      unk_800194 = *v17;
      dword_8003A4 = v16;
      unk_800198 = v17[1];
      goto LABEL_32;
    }
    v5 += 12;
    ++v4;
  }
  while ( (int)v5 < (int)dword_6288D8 );
  if ( GetCPInfo(v2, &CPInfo) )
  {
    dword_8003A4 = 0;
    memset(&unk_8002A0, 0, 0x100u);
    unk_8003A0 = 0;
    dword_800180 = v2;
    if ( CPInfo.MaxCharSize <= 1 )
    {
      dword_80019C = 0;
    }
    else
    {
      if ( CPInfo.LeadByte[0] )
      {
        v6 = &CPInfo.LeadByte[1];
        do
        {
          v7 = *v6;
          if ( !*v6 )
            break;
          for ( i = *(v6 - 1); i <= v7; ++i )
            byte_8002A1[i] |= 4u;
          v6 += 2;
        }
        while ( *(v6 - 1) );
      }
      for ( j = 1; j < 0xFF; ++j )
        byte_8002A1[j] |= 8u;
      dword_8003A4 = CPtoLCID(v2);
      dword_80019C = 1;
    }
    unk_800190 = 0;
    unk_800194 = 0;
    unk_800198 = 0;
    goto LABEL_32;
  }
  if ( dword_7FF484 )
    goto LABEL_31;
  v3 = -1;
LABEL_34:
  _unlock(25);
  return v3;
}
