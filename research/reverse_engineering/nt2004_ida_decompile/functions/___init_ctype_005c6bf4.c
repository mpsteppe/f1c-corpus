int __init_ctype()
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
  char *v9; // edi
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
  if ( dword_7FF1E8 )
  {
    if ( !CodePage && __getlocaleinfo(0, (unsigned __int16)word_7FF230, 0x1004u, (int)&CodePage) )
      goto LABEL_38;
    v1 = (WORD *)malloc(0x202u);
    lpMem = v1;
    v16 = malloc(0x202u);
    lpSrcStr = (LPCSTR)malloc(0x101u);
    v2 = (const WCHAR *)malloc(0x202u);
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
    SrcSizeInBytes = LOWORD(CPInfo.MaxCharSize);
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
    if ( !__crtGetStringTypeA(1u, lpSrcStr, 256, v1 + 1, 0, 0, 0) )
      goto LABEL_38;
    v7 = (WCHAR *)v17;
    *v1 = 0;
    for ( k = 0; k < 256; ++k )
      *v7++ = k;
    v9 = (char *)v16 + 2;
    if ( __crtGetStringTypeW(1u, v17, 256, (LPWORD)v16 + 1, 0, 0) )
    {
      *(_WORD *)v16 = 0;
      if ( (int)SrcSizeInBytes > 1 && CPInfo.LeadByte[0] )
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
      off_625684 = v9;
      off_625680 = (char *)lpMem + 2;
      if ( dword_7FF21C )
        sub_5C1B88(dword_7FF21C);
      dword_7FF21C = lpMem;
      if ( dword_7FF220 )
        sub_5C1B88(dword_7FF220);
      dword_7FF220 = v16;
    }
    else
    {
LABEL_38:
      sub_5C1B88(lpMem);
      sub_5C1B88(v16);
      v0 = 1;
    }
    sub_5C1B88((LPVOID)lpSrcStr);
    sub_5C1B88((LPVOID)v17);
    return v0;
  }
  else
  {
    off_625680 = &_ctype[1];
    off_625684 = &_ctype[1];
    sub_5C1B88(dword_7FF21C);
    sub_5C1B88(dword_7FF220);
    dword_7FF21C = 0;
    dword_7FF220 = 0;
    return 0;
  }
}
