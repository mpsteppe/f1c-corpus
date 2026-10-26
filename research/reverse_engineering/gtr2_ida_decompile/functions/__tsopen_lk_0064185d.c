int __cdecl _tsopen_lk(_DWORD *a1, int *a2, LPCSTR lpFileName, __int16 a4, char a5)
{
  int v5; // ecx
  unsigned int v7; // eax
  DWORD v8; // esi
  int v9; // eax
  int v10; // edi
  HANDLE v11; // eax
  void *v12; // esi
  DWORD FileType; // eax
  DWORD LastError; // eax
  char v15; // al
  int v16; // ecx
  int v17; // esi
  bool v18; // zf
  _BYTE *v19; // eax
  DWORD v20; // [esp-10h] [ebp-34h]
  _SECURITY_ATTRIBUTES SecurityAttributes; // [esp+8h] [ebp-1Ch] BYREF
  DWORD dwDesiredAccess; // [esp+14h] [ebp-10h]
  DWORD dwCreationDisposition; // [esp+18h] [ebp-Ch]
  DWORD dwShareMode; // [esp+1Ch] [ebp-8h]
  char Buffer; // [esp+22h] [ebp-2h] BYREF
  char v26; // [esp+23h] [ebp-1h]

  SecurityAttributes.nLength = 12;
  SecurityAttributes.lpSecurityDescriptor = 0;
  if ( (a4 & 0x80u) == 0 )
  {
    SecurityAttributes.bInheritHandle = 1;
    v26 = 0;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    v26 = 16;
  }
  if ( (a4 & 0x8000) == 0 && ((a4 & 0x4000) != 0 || dword_FB8658 != 0x8000) )
    v26 |= 0x80u;
  if ( (a4 & 3) != 0 )
  {
    if ( (a4 & 3) == 1 )
    {
      dwDesiredAccess = 0x40000000;
    }
    else
    {
      if ( (a4 & 3) != 2 )
      {
LABEL_18:
        *_errno() = 22;
        *__doserrno() = 0;
        return -1;
      }
      dwDesiredAccess = -1073741824;
    }
  }
  else
  {
    dwDesiredAccess = 0x80000000;
  }
  switch ( v5 )
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
      goto LABEL_18;
  }
  v7 = a4 & 0x700;
  if ( v7 > 0x400 )
  {
    if ( v7 != 1280 )
    {
      if ( v7 == 1536 )
        goto LABEL_37;
      if ( v7 != 1792 )
        goto LABEL_35;
    }
    dwCreationDisposition = 1;
    goto LABEL_39;
  }
  if ( v7 == 1024 || (a4 & 0x700) == 0 )
  {
    dwCreationDisposition = 3;
    goto LABEL_39;
  }
  if ( v7 == 256 )
  {
    dwCreationDisposition = 4;
    goto LABEL_39;
  }
  if ( v7 == 512 )
  {
LABEL_37:
    dwCreationDisposition = 5;
    goto LABEL_39;
  }
  if ( v7 != 768 )
  {
LABEL_35:
    *_errno() = 22;
    *__doserrno() = 0;
    return -1;
  }
  dwCreationDisposition = 2;
LABEL_39:
  v8 = 128;
  if ( (a4 & 0x100) != 0 && (a5 & ~(_BYTE)dword_FB8190 & 0x80u) == 0 )
    v8 = 1;
  if ( (a4 & 0x40) != 0 )
  {
    BYTE2(dwDesiredAccess) |= 1u;
    v8 |= 0x4000000u;
    if ( dword_FB8194 == 2 )
      dwShareMode |= 4u;
  }
  if ( (a4 & 0x1000) != 0 )
    v8 |= 0x100u;
  if ( (a4 & 0x20) != 0 )
  {
    v8 |= 0x8000000u;
  }
  else if ( (a4 & 0x10) != 0 )
  {
    v8 |= 0x10000000u;
  }
  v9 = _alloc_osfhnd();
  v10 = v9;
  if ( v9 == -1 )
  {
    *_errno() = 24;
    *__doserrno() = 0;
    return -1;
  }
  v20 = dwCreationDisposition;
  *a1 = 1;
  *a2 = v9;
  v11 = CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, &SecurityAttributes, v20, v8, 0);
  v12 = v11;
  if ( v11 == (HANDLE)-1 )
  {
LABEL_57:
    LastError = GetLastError();
    _dosmaperr(LastError);
    return -1;
  }
  FileType = GetFileType(v11);
  switch ( FileType )
  {
    case 0u:
      CloseHandle(v12);
      goto LABEL_57;
    case 2u:
      v26 |= 0x40u;
      break;
    case 3u:
      v26 |= 8u;
      break;
  }
  _set_osfhnd(v10, v12);
  v26 |= 1u;
  v15 = v26;
  v16 = dword_FBB4E0[v10 >> 5];
  v17 = 36 * (v10 & 0x1F);
  v18 = (v26 & 0x48) == 0;
  v26 &= 0x48u;
  *(_BYTE *)(v17 + v16 + 4) = v15;
  if ( v18 && v15 < 0 && (a4 & 2) != 0 )
  {
    dwDesiredAccess = _lseek_lk(v10, -1, 2u);
    if ( dwDesiredAccess == -1 )
    {
      if ( *__doserrno() == 131 )
        goto LABEL_67;
      goto LABEL_76;
    }
    Buffer = 0;
    if ( !_read_lk(v10, &Buffer, 1u) && Buffer == 26 && _chsize_lk(v10, dwDesiredAccess) == -1
      || _lseek_lk(v10, 0, 0) == -1 )
    {
LABEL_76:
      _close_lk(v10);
      return -1;
    }
  }
LABEL_67:
  if ( !v26 && (a4 & 8) != 0 )
  {
    v19 = (_BYTE *)(v17 + dword_FBB4E0[v10 >> 5] + 4);
    *v19 |= 0x20u;
  }
  return v10;
}
