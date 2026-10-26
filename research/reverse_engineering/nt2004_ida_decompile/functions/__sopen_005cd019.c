int _sopen(const char *FileName, int OpenFlag, int ShareFlag, ...)
{
  unsigned int v3; // ecx
  DWORD v5; // esi
  int v6; // ebx
  HANDLE v7; // eax
  void *v8; // esi
  DWORD LastError; // eax
  int v10; // esi
  DWORD FileType; // eax
  char v12; // cl
  int v13; // esi
  bool v14; // zf
  struct _SECURITY_ATTRIBUTES SecurityAttributes; // [esp+Ch] [ebp-1Ch] BYREF
  DWORD dwShareMode; // [esp+18h] [ebp-10h]
  DWORD dwDesiredAccess; // [esp+1Ch] [ebp-Ch]
  DWORD dwCreationDisposition; // [esp+20h] [ebp-8h]
  char v19; // [esp+27h] [ebp-1h]
  char lpFileName_3; // [esp+33h] [ebp+Bh]
  int v21; // [esp+3Ch] [ebp+14h]
  va_list va; // [esp+40h] [ebp+18h] BYREF

  va_start(va, ShareFlag);
  v21 = va_arg(va, _DWORD);
  SecurityAttributes.nLength = 12;
  SecurityAttributes.lpSecurityDescriptor = 0;
  if ( (OpenFlag & 0x80u) == 0 )
  {
    v19 = 0;
    SecurityAttributes.bInheritHandle = 1;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    v19 = 16;
  }
  if ( (OpenFlag & 0x8000) == 0 && ((OpenFlag & 0x4000) != 0 || dword_7FF4AC != 0x8000) )
    v19 |= 0x80u;
  if ( (OpenFlag & 3) != 0 )
  {
    if ( (OpenFlag & 3) == 1 )
    {
      dwDesiredAccess = 0x40000000;
    }
    else
    {
      if ( (OpenFlag & 3) != 2 )
        goto LABEL_34;
      dwDesiredAccess = -1073741824;
    }
  }
  else
  {
    dwDesiredAccess = 0x80000000;
  }
  switch ( ShareFlag )
  {
    case 16:
      dwShareMode = 0;
      break;
    case 32:
      dwShareMode = 1;
      break;
    case 48:
      dwShareMode = 2;
      break;
    case 64:
      dwShareMode = 3;
      break;
    default:
LABEL_34:
      *_errno() = 22;
      *__doserrno() = 0;
      return -1;
  }
  v3 = OpenFlag & 0x700;
  if ( v3 > 0x400 )
  {
    if ( v3 != 1280 )
    {
      if ( v3 == 1536 )
        goto LABEL_35;
      if ( v3 != 1792 )
        goto LABEL_34;
    }
    dwCreationDisposition = 1;
    goto LABEL_37;
  }
  if ( v3 == 1024 || (OpenFlag & 0x700) == 0 )
  {
    dwCreationDisposition = 3;
    goto LABEL_37;
  }
  if ( v3 == 256 )
  {
    dwCreationDisposition = 4;
    goto LABEL_37;
  }
  if ( v3 == 512 )
  {
LABEL_35:
    dwCreationDisposition = 5;
    goto LABEL_37;
  }
  if ( v3 != 768 )
    goto LABEL_34;
  dwCreationDisposition = 2;
LABEL_37:
  v5 = 128;
  if ( (OpenFlag & 0x100) != 0 && (v21 & ~(_BYTE)dword_7FF118 & 0x80u) == 0 )
    v5 = 1;
  if ( (OpenFlag & 0x40) != 0 )
  {
    v5 |= 0x4000000u;
    BYTE2(dwDesiredAccess) |= 1u;
  }
  if ( (OpenFlag & 0x1000) != 0 )
    v5 |= 0x100u;
  if ( (OpenFlag & 0x20) != 0 )
  {
    v5 |= 0x8000000u;
  }
  else if ( (OpenFlag & 0x10) != 0 )
  {
    v5 |= 0x10000000u;
  }
  v6 = _alloc_osfhnd();
  if ( v6 == -1 )
  {
    *_errno() = 24;
    *__doserrno() = 0;
    return -1;
  }
  v7 = CreateFileA(FileName, dwDesiredAccess, dwShareMode, &SecurityAttributes, dwCreationDisposition, v5, 0);
  v8 = v7;
  if ( v7 == (HANDLE)-1 )
    goto LABEL_51;
  FileType = GetFileType(v7);
  if ( FileType )
  {
    if ( FileType == 2 )
    {
      v19 |= 0x40u;
    }
    else if ( FileType == 3 )
    {
      v19 |= 8u;
    }
    _set_osfhnd(v6, v8);
    v12 = v19 | 1;
    v13 = 36 * (v6 & 0x1F);
    v14 = (v19 & 0x48) == 0;
    lpFileName_3 = v19 & 0x48;
    *(_BYTE *)(dword_8003E0[v6 >> 5] + v13 + 4) = v19 | 1;
    if ( v14 && v12 < 0 && (OpenFlag & 2) != 0 )
    {
      dwShareMode = _lseek_lk(v6, -1, 2u);
      if ( dwShareMode == -1 )
      {
        if ( *__doserrno() != 131 )
        {
LABEL_63:
          _close(v6);
          v10 = -1;
          goto LABEL_72;
        }
      }
      else
      {
        HIBYTE(ShareFlag) = 0;
        if ( !_read_lk(v6, (char *)&ShareFlag + 3, 1u) && HIBYTE(ShareFlag) == 26 && _chsize_lk(v6, dwShareMode) == -1
          || _lseek_lk(v6, 0, 0) == -1 )
        {
          goto LABEL_63;
        }
      }
    }
    if ( !lpFileName_3 && (OpenFlag & 8) != 0 )
      *(_BYTE *)(dword_8003E0[v6 >> 5] + v13 + 4) |= 0x20u;
    v10 = v6;
    goto LABEL_72;
  }
  CloseHandle(v8);
LABEL_51:
  LastError = GetLastError();
  _dosmaperr(LastError);
  v10 = -1;
LABEL_72:
  _unlock_fhandle(v6);
  return v10;
}
