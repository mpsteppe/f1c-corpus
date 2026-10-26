int __cdecl _setmbcp_lk(UINT CodePage)
{
  int v1; // edx
  unsigned int i; // eax
  BYTE *v3; // ecx
  BYTE v4; // dl
  unsigned int k; // eax
  _BYTE *v6; // ebx
  unsigned int v7; // eax
  _BYTE *j; // esi
  unsigned __int8 v9; // dl
  unsigned int v10; // edi
  char v11; // dl
  int v12; // eax
  int v13; // ecx
  _DWORD *v14; // ecx
  unsigned int m; // eax
  int v16; // ecx
  unsigned int v18; // [esp+Ch] [ebp-1Ch]
  struct _cpinfo CPInfo; // [esp+10h] [ebp-18h] BYREF
  int v20; // [esp+24h] [ebp-4h]

  v20 = dword_912B08;
  if ( CodePage )
  {
    v1 = 0;
    for ( i = 0; i < 60; i += 12 )
    {
      if ( dword_9136E8[i] == CodePage )
      {
        memset(&byte_FBB280, 0, 0x100u);
        v18 = 0;
        unk_FBB380 = 0;
        v6 = (char *)&unk_9136F8 + 48 * v1;
        do
        {
          LOBYTE(v7) = *v6;
          for ( j = v6; (_BYTE)v7; LOBYTE(v7) = *j )
          {
            v9 = j[1];
            if ( !v9 )
              break;
            v7 = (unsigned __int8)v7;
            v10 = v9;
            if ( (unsigned __int8)v7 <= (unsigned int)v9 )
            {
              v11 = byte_9136E0[v18];
              do
                byte_FBB281[v7++] |= v11;
              while ( v7 <= v10 );
            }
            j += 2;
          }
          ++v18;
          v6 += 8;
        }
        while ( v18 < 4 );
        dword_FBB384 = CodePage;
        dword_FBB264 = 1;
        v12 = CPtoLCID(CodePage);
        v14 = (_DWORD *)((char *)&unk_9136EC + v13);
        *(_DWORD *)&word_FBB390 = *v14;
        *(_DWORD *)&algn_FBB392[2] = v14[1];
        dword_FBB25C = v12;
        *(_DWORD *)&algn_FBB392[6] = v14[2];
        goto LABEL_31;
      }
      ++v1;
    }
    if ( GetCPInfo(CodePage, &CPInfo) )
    {
      memset(&byte_FBB280, 0, 0x100u);
      unk_FBB380 = 0;
      dword_FBB384 = CodePage;
      dword_FBB25C = 0;
      if ( CPInfo.MaxCharSize <= 1 )
      {
        dword_FBB264 = 0;
      }
      else
      {
        if ( CPInfo.LeadByte[0] )
        {
          v3 = &CPInfo.LeadByte[1];
          do
          {
            v4 = *v3;
            if ( !*v3 )
              break;
            for ( k = *(v3 - 1); k <= v4; ++k )
              byte_FBB281[k] |= 4u;
            v3 += 2;
          }
          while ( *(v3 - 1) );
        }
        for ( m = 1; m < 0xFF; ++m )
          byte_FBB281[m] |= 8u;
        dword_FBB25C = CPtoLCID(CodePage);
        dword_FBB264 = v16;
      }
      *(_DWORD *)&word_FBB390 = 0;
      *(_DWORD *)&algn_FBB392[2] = 0;
      *(_DWORD *)&algn_FBB392[6] = 0;
      goto LABEL_31;
    }
    if ( dword_FB8620 )
      goto LABEL_30;
    return -1;
  }
  else
  {
LABEL_30:
    setSBCS();
LABEL_31:
    setSBUpLow();
    return 0;
  }
}
