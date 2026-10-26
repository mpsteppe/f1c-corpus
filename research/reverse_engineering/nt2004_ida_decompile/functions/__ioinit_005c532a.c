UINT _ioinit()
{
  char *v0; // eax
  char *v1; // esi
  unsigned int i; // eax
  int v3; // edi
  LPBYTE v4; // ebx
  _DWORD *v5; // esi
  char *v6; // eax
  unsigned int j; // ecx
  int k; // esi
  int v9; // eax
  int m; // ebx
  int v11; // esi
  DWORD v12; // eax
  HANDLE StdHandle; // eax
  HANDLE v14; // edi
  DWORD FileType; // eax
  struct _STARTUPINFOA StartupInfo; // [esp+Ch] [ebp-48h] BYREF
  HANDLE *v18; // [esp+50h] [ebp-4h]

  v0 = (char *)malloc(0x480u);
  v1 = v0;
  if ( !v0 )
    _amsg_exit(0x1Bu);
  dword_8003E0[0] = (int)v0;
  uNumber = 32;
  for ( i = (unsigned int)(v0 + 1152); (unsigned int)v1 < i; i = dword_8003E0[0] + 1152 )
  {
    v1[4] = 0;
    *(_DWORD *)v1 = -1;
    *((_DWORD *)v1 + 2) = 0;
    v1[5] = 10;
    v1 += 36;
  }
  GetStartupInfoA(&StartupInfo);
  if ( StartupInfo.cbReserved2 && StartupInfo.lpReserved2 )
  {
    v3 = *(_DWORD *)StartupInfo.lpReserved2;
    v4 = StartupInfo.lpReserved2 + 4;
    v18 = (HANDLE *)&StartupInfo.lpReserved2[*(_DWORD *)StartupInfo.lpReserved2 + 4];
    if ( v3 >= 2048 )
      v3 = 2048;
    if ( (int)uNumber < v3 )
    {
      v5 = &unk_8003E4;
      while ( 1 )
      {
        v6 = (char *)malloc(0x480u);
        if ( !v6 )
          break;
        uNumber += 32;
        *v5 = v6;
        for ( j = (unsigned int)(v6 + 1152); (unsigned int)v6 < j; j = *v5 + 1152 )
        {
          v6[4] = 0;
          *(_DWORD *)v6 = -1;
          *((_DWORD *)v6 + 2) = 0;
          v6[5] = 10;
          v6 += 36;
        }
        ++v5;
        if ( (int)uNumber >= v3 )
          goto LABEL_19;
      }
      v3 = uNumber;
    }
LABEL_19:
    for ( k = 0; k < v3; ++v4 )
    {
      if ( *v18 != (HANDLE)-1 && (*v4 & 1) != 0 && ((*v4 & 8) != 0 || GetFileType(*v18)) )
      {
        v9 = dword_8003E0[k >> 5] + 36 * (k & 0x1F);
        *(_DWORD *)v9 = *v18;
        *(_BYTE *)(v9 + 4) = *v4;
      }
      ++v18;
      ++k;
    }
  }
  for ( m = 0; m < 3; ++m )
  {
    v11 = dword_8003E0[0] + 36 * m;
    if ( *(_DWORD *)v11 == -1 )
    {
      *(_BYTE *)(v11 + 4) = -127;
      if ( m )
        v12 = -(m != 1) - 11;
      else
        v12 = -10;
      StdHandle = GetStdHandle(v12);
      v14 = StdHandle;
      if ( StdHandle == (HANDLE)-1
        || (FileType = GetFileType(StdHandle)) == 0
        || (*(_DWORD *)v11 = v14, (unsigned __int8)FileType == 2) )
      {
        *(_BYTE *)(v11 + 4) |= 0x40u;
      }
      else if ( (unsigned __int8)FileType == 3 )
      {
        *(_BYTE *)(v11 + 4) |= 8u;
      }
    }
    else
    {
      *(_BYTE *)(v11 + 4) |= 0x80u;
    }
  }
  return SetHandleCount(uNumber);
}
