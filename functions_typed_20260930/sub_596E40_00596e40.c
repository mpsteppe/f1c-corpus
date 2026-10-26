int __cdecl sub_596E40(int a1)
{
  UINT v1; // eax
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
  UINT v22; // [esp+2Ch] [ebp+8h]

  CriticalSectionLazyInitEnter(25);
  v1 = sub_596FED(a1);
  v2 = v1;
  v22 = v1;
  if ( v1 == dword_8D46BC )
  {
LABEL_2:
    v3 = 0;
    goto LABEL_34;
  }
  if ( !v1 )
  {
LABEL_31:
    sub_59706A();
LABEL_32:
    sub_597093();
    goto LABEL_2;
  }
  v4 = 0;
  v5 = &unk_5E9B48;
  do
  {
    if ( *v5 == v2 )
    {
      v21 = 0;
      memset(&unk_8D47E0, 0, 0x100u);
      v9 = 48 * v4;
      unk_8D48E0 = 0;
      v10 = (char *)&unk_5E9B58 + 48 * v4;
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
              v15 = byte_5E9B40[v21];
              do
                byte_8D47E1[v13++] |= v15;
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
      dword_8D46CC = 1;
      dword_8D46BC = v22;
      v16 = ConstantMapper(v22);
      v17 = (_DWORD *)((char *)&unk_5E9B4C + v9);
      unk_8D46C0 = *v17++;
      unk_8D46C4 = *v17;
      dword_8D48E4 = v16;
      unk_8D46C8 = v17[1];
      goto LABEL_32;
    }
    v5 += 12;
    ++v4;
  }
  while ( (int)v5 < (int)dword_5E9C38 );
  if ( GetCPInfo(v2, &CPInfo) )
  {
    dword_8D48E4 = 0;
    memset(&unk_8D47E0, 0, 0x100u);
    unk_8D48E0 = 0;
    dword_8D46BC = v2;
    if ( CPInfo.MaxCharSize <= 1 )
    {
      dword_8D46CC = 0;
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
            byte_8D47E1[i] |= 4u;
          v6 += 2;
        }
        while ( *(v6 - 1) );
      }
      for ( j = 1; j < 0xFF; ++j )
        byte_8D47E1[j] |= 8u;
      dword_8D48E4 = ConstantMapper(v2);
      dword_8D46CC = 1;
    }
    unk_8D46C0 = 0;
    unk_8D46C4 = 0;
    unk_8D46C8 = 0;
    goto LABEL_32;
  }
  if ( dword_8D41D4 )
    goto LABEL_31;
  v3 = -1;
LABEL_34:
  CritSectLeave(25);
  return v3;
}

