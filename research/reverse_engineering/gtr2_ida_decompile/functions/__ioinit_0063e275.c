int _ioinit()
{
  _DWORD *v0; // eax
  unsigned int i; // ecx
  signed int v3; // edi
  LPBYTE v4; // ebp
  _DWORD *v5; // esi
  _DWORD *v6; // eax
  unsigned int j; // ecx
  int k; // ebx
  int v9; // esi
  int m; // ebx
  int v11; // esi
  DWORD v12; // eax
  HANDLE StdHandle; // eax
  HANDLE v14; // edi
  DWORD FileType; // eax
  HANDLE *v16; // [esp+4h] [ebp-48h]
  _STARTUPINFOA StartupInfo; // [esp+8h] [ebp-44h] BYREF

  v0 = malloc(0x480u);
  if ( !v0 )
    return -1;
  dword_FBB4E0[0] = (int)v0;
  uNumber = 32;
  for ( i = (unsigned int)(v0 + 288); (unsigned int)v0 < i; i = dword_FBB4E0[0] + 1152 )
  {
    *v0 = -1;
    v0[2] = 0;
    *((_BYTE *)v0 + 4) = 0;
    *((_BYTE *)v0 + 5) = 10;
    v0 += 9;
  }
  GetStartupInfoA(&StartupInfo);
  if ( StartupInfo.cbReserved2 && StartupInfo.lpReserved2 )
  {
    v3 = *(_DWORD *)StartupInfo.lpReserved2;
    v4 = StartupInfo.lpReserved2 + 4;
    v16 = (HANDLE *)&StartupInfo.lpReserved2[*(_DWORD *)StartupInfo.lpReserved2 + 4];
    if ( *(int *)StartupInfo.lpReserved2 >= 2048 )
      v3 = 2048;
    if ( (int)uNumber < v3 )
    {
      v5 = &unk_FBB4E4;
      while ( 1 )
      {
        v6 = malloc(0x480u);
        if ( !v6 )
          break;
        uNumber += 32;
        *v5 = v6;
        for ( j = (unsigned int)(v6 + 288); (unsigned int)v6 < j; j = *v5 + 1152 )
        {
          *v6 = -1;
          v6[2] = 0;
          *((_BYTE *)v6 + 4) = 0;
          *((_BYTE *)v6 + 5) = 10;
          v6 += 9;
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
      if ( *v16 != (HANDLE)-1 && (*v4 & 1) != 0 && ((*v4 & 8) != 0 || GetFileType(*v16)) )
      {
        v9 = dword_FBB4E0[k >> 5] + 36 * (k & 0x1F);
        *(_DWORD *)v9 = *v16;
        *(_BYTE *)(v9 + 4) = *v4;
        if ( !__crtInitCritSecAndSpinCount(v9 + 12, 4000) )
          return -1;
        ++*(_DWORD *)(v9 + 8);
      }
      ++v16;
      ++k;
    }
  }
  for ( m = 0; m < 3; ++m )
  {
    v11 = dword_FBB4E0[0] + 36 * m;
    if ( *(_DWORD *)v11 == -1 )
    {
      *(_BYTE *)(v11 + 4) = -127;
      if ( m )
        v12 = -(m != 1) - 11;
      else
        v12 = -10;
      StdHandle = GetStdHandle(v12);
      v14 = StdHandle;
      if ( StdHandle == (HANDLE)-1 || (FileType = GetFileType(StdHandle)) == 0 )
      {
        *(_BYTE *)(v11 + 4) |= 0x40u;
      }
      else
      {
        *(_DWORD *)v11 = v14;
        if ( (unsigned __int8)FileType == 2 )
        {
          *(_BYTE *)(v11 + 4) |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          *(_BYTE *)(v11 + 4) |= 8u;
        }
        if ( !__crtInitCritSecAndSpinCount(v11 + 12, 4000) )
          return -1;
        ++*(_DWORD *)(v11 + 8);
      }
    }
    else
    {
      *(_BYTE *)(v11 + 4) |= 0x80u;
    }
  }
  SetHandleCount(uNumber);
  return 0;
}
