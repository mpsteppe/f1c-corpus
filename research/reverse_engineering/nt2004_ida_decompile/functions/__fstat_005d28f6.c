int __cdecl _fstat(const int FileHandle, struct _stat32 *const Stat)
{
  DWORD FileType; // eax
  struct _stat32 *v4; // esi
  struct _stat32 *v5; // esi
  DWORD LastError; // eax
  int v7; // eax
  bool v8; // zf
  int st_mtime; // eax
  DWORD nFileSizeLow; // eax
  _BY_HANDLE_FILE_INFORMATION FileInformation; // [esp+8h] [ebp-50h] BYREF
  struct _SYSTEMTIME SystemTime; // [esp+3Ch] [ebp-1Ch] BYREF
  struct _FILETIME LocalFileTime; // [esp+4Ch] [ebp-Ch] BYREF
  int v14; // [esp+54h] [ebp-4h]

  v14 = 0;
  if ( FileHandle < uNumber && (*(_BYTE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F) + 4) & 1) != 0 )
  {
    _lock_fhandle(FileHandle);
    FileType = GetFileType(*(HANDLE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F)));
    BYTE1(FileType) &= ~0x80u;
    if ( FileType != 1 )
    {
      switch ( FileType )
      {
        case 2u:
          v4 = Stat;
          Stat->st_mode = 0x2000;
          break;
        case 3u:
          v4 = Stat;
          Stat->st_mode = 4096;
          break;
        case 0u:
          *_errno() = 9;
LABEL_8:
          v14 = -1;
LABEL_9:
          _unlock_fhandle(FileHandle);
          return v14;
        default:
LABEL_18:
          LastError = GetLastError();
          _dosmaperr(LastError);
          goto LABEL_8;
      }
      v4->st_nlink = 1;
      v4->st_dev = FileHandle;
      v4->st_rdev = FileHandle;
      v4->st_ino = 0;
      v4->st_gid = 0;
      v4->st_uid = 0;
      v4->st_ctime = 0;
      v4->st_mtime = 0;
      v4->st_atime = 0;
      if ( FileType == 2 )
      {
        v4->st_size = 0;
      }
      else if ( PeekNamedPipe(
                  *(HANDLE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F)),
                  0,
                  0,
                  0,
                  (LPDWORD)&Stat,
                  0) )
      {
        v4->st_size = (_off_t)Stat;
      }
      else
      {
        v4->st_size = 0;
      }
      goto LABEL_9;
    }
    v5 = Stat;
    Stat->st_mode = 0;
    v5->st_gid = 0;
    v5->st_uid = 0;
    v5->st_ino = 0;
    v5->st_nlink = 1;
    if ( !GetFileInformationByHandle(
            *(HANDLE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F)),
            &FileInformation) )
      goto LABEL_18;
    if ( (FileInformation.dwFileAttributes & 1) != 0 )
      v5->st_mode |= 0x124u;
    else
      v5->st_mode |= 0x1B6u;
    if ( !FileTimeToLocalFileTime(&FileInformation.ftLastWriteTime, &LocalFileTime)
      || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
    {
      goto LABEL_8;
    }
    v7 = __loctotime_t(
           SystemTime.wYear,
           SystemTime.wMonth,
           SystemTime.wDay,
           SystemTime.wHour,
           SystemTime.wMinute,
           SystemTime.wSecond,
           -1);
    v8 = FileInformation.ftLastAccessTime.dwLowDateTime == 0;
    v5->st_mtime = v7;
    if ( !v8 || FileInformation.ftLastAccessTime.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&FileInformation.ftLastAccessTime, &LocalFileTime)
        || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
      {
        goto LABEL_36;
      }
      v7 = __loctotime_t(
             SystemTime.wYear,
             SystemTime.wMonth,
             SystemTime.wDay,
             SystemTime.wHour,
             SystemTime.wMinute,
             SystemTime.wSecond,
             -1);
    }
    v8 = FileInformation.ftCreationTime.dwLowDateTime == 0;
    v5->st_atime = v7;
    if ( v8 && !FileInformation.ftCreationTime.dwHighDateTime )
    {
      st_mtime = v5->st_mtime;
LABEL_35:
      HIBYTE(v5->st_mode) |= 0x80u;
      v5->st_ctime = st_mtime;
      nFileSizeLow = FileInformation.nFileSizeLow;
      v5->st_dev = 0;
      v5->st_size = nFileSizeLow;
      v5->st_rdev = 0;
      goto LABEL_9;
    }
    if ( FileTimeToLocalFileTime(&FileInformation.ftCreationTime, &LocalFileTime)
      && FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
    {
      st_mtime = __loctotime_t(
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
  *_errno() = 9;
  return -1;
}
