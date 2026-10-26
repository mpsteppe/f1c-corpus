UINT sub_592F2C()
{
  unsigned int v0; // esi
  unsigned int i; // eax
  int v2; // edi
  LPBYTE v3; // ebx
  unsigned int *v4; // esi
  unsigned int v5; // eax
  unsigned int j; // ecx
  int k; // esi
  int v8; // eax
  int m; // ebx
  int v10; // esi
  DWORD v11; // eax
  HANDLE StdHandle; // eax
  HANDLE v13; // edi
  DWORD FileType; // eax
  struct _STARTUPINFOA StartupInfo; // [esp+Ch] [ebp-48h] BYREF
  HANDLE *v17; // [esp+50h] [ebp-4h]

  v0 = MallocWrapperForNhMalloc(1152);
  if ( !v0 )
    CRTAmsgExit(0x1Bu);
  dword_8D4920[0] = v0;
  uNumber = 32;
  for ( i = v0 + 1152; v0 < i; i = dword_8D4920[0] + 1152 )
  {
    *(_BYTE *)(v0 + 4) = 0;
    *(_DWORD *)v0 = -1;
    *(_DWORD *)(v0 + 8) = 0;
    *(_BYTE *)(v0 + 5) = 10;
    v0 += 36;
  }
  GetStartupInfoA(&StartupInfo);
  if ( StartupInfo.cbReserved2 && StartupInfo.lpReserved2 )
  {
    v2 = *(_DWORD *)StartupInfo.lpReserved2;
    v3 = StartupInfo.lpReserved2 + 4;
    v17 = (HANDLE *)&StartupInfo.lpReserved2[*(_DWORD *)StartupInfo.lpReserved2 + 4];
    if ( v2 >= 2048 )
      v2 = 2048;
    if ( (int)uNumber < v2 )
    {
      v4 = (unsigned int *)&unk_8D4924;
      while ( 1 )
      {
        v5 = MallocWrapperForNhMalloc(1152);
        if ( !v5 )
          break;
        uNumber += 32;
        *v4 = v5;
        for ( j = v5 + 1152; v5 < j; j = *v4 + 1152 )
        {
          *(_BYTE *)(v5 + 4) = 0;
          *(_DWORD *)v5 = -1;
          *(_DWORD *)(v5 + 8) = 0;
          *(_BYTE *)(v5 + 5) = 10;
          v5 += 36;
        }
        ++v4;
        if ( (int)uNumber >= v2 )
          goto LABEL_19;
      }
      v2 = uNumber;
    }
LABEL_19:
    for ( k = 0; k < v2; ++v3 )
    {
      if ( *v17 != (HANDLE)-1 && (*v3 & 1) != 0 && ((*v3 & 8) != 0 || GetFileType(*v17)) )
      {
        v8 = dword_8D4920[k >> 5] + 36 * (k & 0x1F);
        *(_DWORD *)v8 = *v17;
        *(_BYTE *)(v8 + 4) = *v3;
      }
      ++v17;
      ++k;
    }
  }
  for ( m = 0; m < 3; ++m )
  {
    v10 = dword_8D4920[0] + 36 * m;
    if ( *(_DWORD *)v10 == -1 )
    {
      *(_BYTE *)(v10 + 4) = -127;
      if ( m )
        v11 = -(m != 1) - 11;
      else
        v11 = -10;
      StdHandle = GetStdHandle(v11);
      v13 = StdHandle;
      if ( StdHandle == (HANDLE)-1
        || (FileType = GetFileType(StdHandle)) == 0
        || (*(_DWORD *)v10 = v13, (unsigned __int8)FileType == 2) )
      {
        *(_BYTE *)(v10 + 4) |= 0x40u;
      }
      else if ( (unsigned __int8)FileType == 3 )
      {
        *(_BYTE *)(v10 + 4) |= 8u;
      }
    }
    else
    {
      *(_BYTE *)(v10 + 4) |= 0x80u;
    }
  }
  return SetHandleCount(uNumber);
}

