// f1c  0x0058f939  size=581
int sub_58F939()
{
  int v0; // ebx
  WORD *v1; // edi
  const WCHAR *v2; // eax
  int i; // eax
  BYTE *v4; // eax
  int j; // edx
  int v6; // ecx
  WCHAR *v7; // ecx
  int k; // eax
  __int16 *v9; // edi
  BYTE *v10; // eax
  int v11; // esi
  _WORD *v12; // ecx
  struct _cpinfo CPInfo; // [esp+4h] [ebp-24h] BYREF
  LPVOID lpMem; // [esp+18h] [ebp-10h]
  LPVOID v16; // [esp+1Ch] [ebp-Ch]
  LPCWCH v17; // [esp+20h] [ebp-8h]
  LPCSTR lpSrcStr; // [esp+24h] [ebp-4h]

  v0 = 0;
  lpSrcStr = 0;
  v17 = 0;
  if ( dword_8D3F38 )
  {
    if ( !CodePage && sub_5968F6(0, (unsigned __int16)word_8D3F80, 0x1004u, (int)&CodePage) )
      goto LABEL_38;
    v1 = (WORD *)sub_58A935(514);
    lpMem = v1;
    v16 = (LPVOID)sub_58A935(514);
    lpSrcStr = (LPCSTR)sub_58A935(257);
    v2 = (const WCHAR *)sub_58A935(514);
    v17 = v2;
    if ( !v1 )
      goto LABEL_38;
    if ( !v16 )
      goto LABEL_38;
    if ( !lpSrcStr )
      goto LABEL_38;
    if ( !v2 )
      goto LABEL_38;
    for ( i = 0; i < 256; ++i )
      lpSrcStr[i] = i;
    if ( !GetCPInfo(CodePage, &CPInfo) || CPInfo.MaxCharSize > 2 )
      goto LABEL_38;
    cbMultiByte = LOWORD(CPInfo.MaxCharSize);
    if ( LOWORD(CPInfo.MaxCharSize) > 1u && CPInfo.LeadByte[0] )
    {
      v4 = &CPInfo.LeadByte[1];
      do
      {
        LOBYTE(j) = *v4;
        if ( !*v4 )
          break;
        v6 = *(v4 - 1);
        for ( j = (unsigned __int8)j; v6 <= j; j = *v4 )
          lpSrcStr[v6++] = 0;
        v4 += 2;
      }
      while ( *(v4 - 1) );
    }
    if ( !sub_595DC8(1u, lpSrcStr, 256, v1 + 1, 0, 0, 0) )
      goto LABEL_38;
    v7 = (WCHAR *)v17;
    *v1 = 0;
    for ( k = 0; k < 256; ++k )
      *v7++ = k;
    v9 = (__int16 *)((char *)v16 + 2);
    if ( sub_596A2E(1u, v17, 256, (LPWORD)v16 + 1, 0, 0) )
    {
      *(_WORD *)v16 = 0;
      if ( cbMultiByte > 1 && CPInfo.LeadByte[0] )
      {
        v10 = &CPInfo.LeadByte[1];
        do
        {
          if ( !*v10 )
            break;
          v11 = *(v10 - 1);
          if ( v11 <= *v10 )
          {
            v12 = (char *)lpMem + 2 * v11 + 2;
            do
            {
              *v12 = 0x8000;
              ++v11;
              ++v12;
            }
            while ( v11 <= *v10 );
          }
          v10 += 2;
        }
        while ( *(v10 - 1) );
      }
      off_5E69CC = v9;
      off_5E69C8[0] = (__int16 *)((char *)lpMem + 2);
      if ( dword_8D3F6C )
        sub_58AA6F(dword_8D3F6C);
      dword_8D3F6C = lpMem;
      if ( dword_8D3F70 )
        sub_58AA6F(dword_8D3F70);
      dword_8D3F70 = v16;
    }
    else
    {
LABEL_38:
      sub_58AA6F(lpMem);
      sub_58AA6F(v16);
      v0 = 1;
    }
    sub_58AA6F((LPVOID)lpSrcStr);
    sub_58AA6F((LPVOID)v17);
    return v0;
  }
  else
  {
    off_5E69C8[0] = &word_5E69D2;
    off_5E69CC = &word_5E69D2;
    sub_58AA6F(dword_8D3F6C);
    sub_58AA6F(dword_8D3F70);
    dword_8D3F6C = 0;
    dword_8D3F70 = 0;
    return 0;
  }
}
