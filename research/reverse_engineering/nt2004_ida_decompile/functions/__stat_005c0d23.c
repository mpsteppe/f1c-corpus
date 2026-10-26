int __cdecl _stat(const char *const FileName, struct _stat32 *const Stat)
{
  int v3; // eax
  char *v4; // eax
  char *v5; // esi
  __time32_t v6; // eax
  struct _stat32 *v7; // esi
  __time32_t v8; // eax
  bool v9; // zf
  __time32_t st_mtime; // eax
  _dev_t v11; // eax
  DWORD LastError; // eax
  HANDLE v13; // [esp-4h] [ebp-274h]
  char Buffer[260]; // [esp+Ch] [ebp-264h] BYREF
  struct _WIN32_FIND_DATAA FindFileData; // [esp+110h] [ebp-160h] BYREF
  int v16; // [esp+250h] [ebp-20h]
  struct _FILETIME LocalFileTime; // [esp+254h] [ebp-1Ch] BYREF
  HANDLE hFindFile; // [esp+25Ch] [ebp-14h]
  struct _SYSTEMTIME SystemTime; // [esp+260h] [ebp-10h] BYREF

  if ( _mbspbrk((const unsigned __int8 *)FileName, &byte_5F65F4) )
    goto LABEL_5;
  if ( FileName[1] == 58 )
  {
    if ( *FileName && !FileName[2] )
    {
LABEL_5:
      *_errno() = 2;
      *__doserrno() = 2;
      return -1;
    }
    v3 = _mbctolower(*FileName) - 96;
  }
  else
  {
    v3 = _getdrive();
  }
  v16 = v3;
  hFindFile = FindFirstFileA(FileName, &FindFileData);
  if ( hFindFile != (HANDLE)-1 )
  {
    if ( !FileTimeToLocalFileTime(&FindFileData.ftLastWriteTime, &LocalFileTime)
      || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
    {
      goto LABEL_31;
    }
    v8 = __loctotime_t(
           SystemTime.wYear,
           SystemTime.wMonth,
           SystemTime.wDay,
           SystemTime.wHour,
           SystemTime.wMinute,
           SystemTime.wSecond,
           -1);
    v7 = Stat;
    v9 = FindFileData.ftLastAccessTime.dwLowDateTime == 0;
    Stat->st_mtime = v8;
    if ( !v9 || FindFileData.ftLastAccessTime.dwHighDateTime )
    {
      if ( !FileTimeToLocalFileTime(&FindFileData.ftLastAccessTime, &LocalFileTime)
        || !FileTimeToSystemTime(&LocalFileTime, &SystemTime) )
      {
        goto LABEL_31;
      }
      v8 = __loctotime_t(
             SystemTime.wYear,
             SystemTime.wMonth,
             SystemTime.wDay,
             SystemTime.wHour,
             SystemTime.wMinute,
             SystemTime.wSecond,
             -1);
    }
    v9 = FindFileData.ftCreationTime.dwLowDateTime == 0;
    Stat->st_atime = v8;
    if ( v9 && !FindFileData.ftCreationTime.dwHighDateTime )
    {
      st_mtime = Stat->st_mtime;
LABEL_29:
      v13 = hFindFile;
      Stat->st_ctime = st_mtime;
      FindClose(v13);
      goto LABEL_30;
    }
    if ( FileTimeToLocalFileTime(&FindFileData.ftCreationTime, &LocalFileTime)
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
      goto LABEL_29;
    }
LABEL_31:
    LastError = GetLastError();
    _dosmaperr(LastError);
    FindClose(hFindFile);
    return -1;
  }
  if ( _mbspbrk((const unsigned __int8 *)FileName, &off_5F65F0) )
  {
    v4 = _fullpath(Buffer, FileName, 0x104u);
    v5 = v4;
    if ( v4 )
    {
      if ( (strlen(v4) == 3 || IsRootUNCName(v5)) && GetDriveTypeA(v5) > 1 )
      {
        FindFileData.dwFileAttributes = 16;
        FindFileData.nFileSizeHigh = 0;
        FindFileData.nFileSizeLow = 0;
        FindFileData.cFileName[0] = 0;
        v6 = __loctotime_t(1980, 1, 1, 0, 0, 0, -1);
        v7 = Stat;
        Stat->st_mtime = v6;
        Stat->st_atime = v6;
        Stat->st_ctime = v6;
LABEL_30:
        v7->st_mode = __dtoxmode(FindFileData.dwFileAttributes, (unsigned __int8 *)FileName);
        v7->st_size = FindFileData.nFileSizeLow;
        v11 = v16 - 1;
        v7->st_dev = v16 - 1;
        v7->st_rdev = v11;
        v7->st_nlink = 1;
        v7->st_ino = 0;
        v7->st_gid = 0;
        v7->st_uid = 0;
        return 0;
      }
    }
  }
  *_errno() = 2;
  *__doserrno() = 2;
  return -1;
}
