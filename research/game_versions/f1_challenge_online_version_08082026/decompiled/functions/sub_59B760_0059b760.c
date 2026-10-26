int __cdecl sub_59B760(int a1, DWORD TotalBytesAvail)
{
  DWORD FileType; // eax
  DWORD v4; // esi
  DWORD v5; // esi
  DWORD LastError; // eax
  int v7; // eax
  bool v8; // zf
  int v9; // eax
  DWORD nFileSizeLow; // eax
  _BY_HANDLE_FILE_INFORMATION FileInformation; // [esp+8h] [ebp-50h] BYREF
  struct _SYSTEMTIME SystemTime; // [esp+3Ch] [ebp-1Ch] BYREF
  struct _FILETIME LocalFileTime; // [esp+4Ch] [ebp-Ch] BYREF
  int v14; // [esp+54h] [ebp-4h]

  v14 = 0;
  if ( a1 < uNumber && (*(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) & 1) != 0 )
  {
    sub_595A61(a1);
    FileType = GetFileType(*(HANDLE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F)));
    BYTE1(FileType) &= ~0x80u;
    if ( FileType != 1 )
    {
      switch ( FileType )
      {
        case 2u:
          v4 = TotalBytesAvail;
          *(_WORD *)(TotalBytesAvail + 6) = 0x2000;
          break;
        case 3u:
          v4 = TotalBytesAvail;
          *(_WORD *)(TotalBytesAvail + 6) = 4096;
          break;
        case 0u:
          *(_DWORD *)sub_58AFCF() = 9;
LABEL_8:
          v14 = -1;
LABEL_9:
          sub_595AC0(a1);
          return v14;
        default:
LABEL_18:
          LastError = GetLastError();
          sub_58AF5C(LastError);
          goto LABEL_8;
      }
      *(_WORD *)(v4 + 8) = 1;
      *(_DWORD *)v4 = a1;
      *(_DWORD *)(v4 + 16) = a1;
      *(_WORD *)(v4 + 4) = 0;
      *(_WORD *)(v4 + 12) = 0;
      *(_WORD *)(v4 + 10) = 0;
      *(_DWORD *)(v4 + 32) = 0;
      *(_DWORD *)(v4 + 28) = 0;
      *(_DWORD *)(v4 + 24) = 0;
      if ( FileType == 2 )
      {
        *(_DWORD *)(v4 + 20) = 0;
      }
      else if ( PeekNamedPipe(*(HANDLE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F)), 0, 0, 0, &TotalBytesAvail, 0) )
      {
        *(_DWORD *)(v4 + 20) = TotalBytesAvail;
      }
      else
      {
        *(_DWORD *)(v4 + 20) = 0;
      }
      goto LABEL_9;
    }
    v5 = TotalBytesAvail;
    *(_WORD *)(TotalBytesAvail + 6) = 0;
    *(_WORD *)(v5 + 12) = 0;
    *(_WORD *)(v5 + 10) = 0;
    *(_WORD *)(v5 + 4) = 0;
    *(_WORD *)(v5 + 8) = 1;
    if ( !GetFileInformationByHandle(*(HANDLE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F)), &FileInformation) )
      goto LABEL_18;
    if ( (FileInformation.dwFileAttributes & 1) != 0 )
      *(_WORD *)(v5 + 6) |= 0x124u;
    else
      *(_WORD *)(v5 + 6) |= 0x1B6u;
    if ( !FileTimeToLocalFileTime(&FileInformation.ftLastWriteTime, &LocalFileTime)
      || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
    {
      goto LABEL_8;
    }
    v7 = sub_591EDF(
           SystemTime.wYear,
           SystemTime.wMonth,
           SystemTime.wDay,
           SystemTime.wHour,
           SystemTime.wMinute,
           SystemTime.wSecond,
           -1);
    v8 = FileInformation.ftLastAccessTime.dwLowDateTime == 0;
    *(_DWORD *)(v5 + 28) = v7;
    if ( !v8 || FileInformation.ftLastAccessTime.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&FileInformation.ftLastAccessTime, &LocalFileTime)
        || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
      {
        goto LABEL_36;
      }
      v7 = sub_591EDF(
             SystemTime.wYear,
             SystemTime.wMonth,
             SystemTime.wDay,
             SystemTime.wHour,
             SystemTime.wMinute,
             SystemTime.wSecond,
             -1);
    }
    v8 = FileInformation.ftCreationTime.dwLowDateTime == 0;
    *(_DWORD *)(v5 + 24) = v7;
    if ( v8 && !FileInformation.ftCreationTime.dwHighDateTime )
    {
      v9 = *(_DWORD *)(v5 + 28);
LABEL_35:
      *(_BYTE *)(v5 + 7) |= 0x80u;
      *(_DWORD *)(v5 + 32) = v9;
      nFileSizeLow = FileInformation.nFileSizeLow;
      *(_DWORD *)v5 = 0;
      *(_DWORD *)(v5 + 20) = nFileSizeLow;
      *(_DWORD *)(v5 + 16) = 0;
      goto LABEL_9;
    }
    if ( FileTimeToLocalFileTime(&FileInformation.ftCreationTime, &LocalFileTime)
      && FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
    {
      v9 = sub_591EDF(
             SystemTime.wYear,
             SystemTime.wMonth,
             SystemTime.wDay,
             SystemTime.wHour,
             SystemTime.wMinute,
             SystemTime.wSecond,
             -1);
      goto LABEL_35;
    }
LABEL_36:
    v14 = -1;
    goto LABEL_9;
  }
  *(_DWORD *)sub_58AFCF() = 9;
  return -1;
}
