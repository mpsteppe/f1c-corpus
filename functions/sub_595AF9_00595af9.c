int __cdecl sub_595AF9(LPCSTR lpFileName, __int16 a2, int Buffer, char a4)
{
  unsigned int v4; // ecx
  DWORD v6; // esi
  int v7; // ebx
  HANDLE v8; // eax
  void *v9; // esi
  DWORD LastError; // eax
  int v11; // esi
  DWORD FileType; // eax
  char v13; // cl
  int v14; // esi
  bool v15; // zf
  struct _SECURITY_ATTRIBUTES SecurityAttributes; // [esp+Ch] [ebp-1Ch] BYREF
  DWORD dwShareMode; // [esp+18h] [ebp-10h]
  DWORD dwDesiredAccess; // [esp+1Ch] [ebp-Ch]
  DWORD dwCreationDisposition; // [esp+20h] [ebp-8h]
  char v20; // [esp+27h] [ebp-1h]
  char lpFileName_3; // [esp+33h] [ebp+Bh]

  SecurityAttributes.nLength = 12;
  SecurityAttributes.lpSecurityDescriptor = 0;
  if ( (a2 & 0x80u) == 0 )
  {
    v20 = 0;
    SecurityAttributes.bInheritHandle = 1;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    v20 = 16;
  }
  if ( (a2 & 0x8000) == 0 && ((a2 & 0x4000) != 0 || dword_8D41FC != 0x8000) )
    v20 |= 0x80u;
  if ( (a2 & 3) != 0 )
  {
    if ( (a2 & 3) == 1 )
    {
      dwDesiredAccess = 0x40000000;
    }
    else
    {
      if ( (a2 & 3) != 2 )
        goto LABEL_34;
      dwDesiredAccess = -1073741824;
    }
  }
  else
  {
    dwDesiredAccess = 0x80000000;
  }
  switch ( Buffer )
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
      *(_DWORD *)TLSOffsetGetter() = 22;
      *(_DWORD *)TLSOffsetGetter_afd8() = 0;
      return -1;
  }
  v4 = a2 & 0x700;
  if ( v4 > 0x400 )
  {
    if ( v4 != 1280 )
    {
      if ( v4 == 1536 )
        goto LABEL_35;
      if ( v4 != 1792 )
        goto LABEL_34;
    }
    dwCreationDisposition = 1;
    goto LABEL_37;
  }
  if ( v4 == 1024 || (a2 & 0x700) == 0 )
  {
    dwCreationDisposition = 3;
    goto LABEL_37;
  }
  if ( v4 == 256 )
  {
    dwCreationDisposition = 4;
    goto LABEL_37;
  }
  if ( v4 == 512 )
  {
LABEL_35:
    dwCreationDisposition = 5;
    goto LABEL_37;
  }
  if ( v4 != 768 )
    goto LABEL_34;
  dwCreationDisposition = 2;
LABEL_37:
  v6 = 128;
  if ( (a2 & 0x100) != 0 && (a4 & ~(_BYTE)dword_8D3E70 & 0x80u) == 0 )
    v6 = 1;
  if ( (a2 & 0x40) != 0 )
  {
    v6 |= 0x4000000u;
    BYTE2(dwDesiredAccess) |= 1u;
  }
  if ( (a2 & 0x1000) != 0 )
    v6 |= 0x100u;
  if ( (a2 & 0x20) != 0 )
  {
    v6 |= 0x8000000u;
  }
  else if ( (a2 & 0x10) != 0 )
  {
    v6 |= 0x10000000u;
  }
  v7 = sub_595801();
  if ( v7 == -1 )
  {
    *(_DWORD *)TLSOffsetGetter() = 24;
    *(_DWORD *)TLSOffsetGetter_afd8() = 0;
    return -1;
  }
  v8 = CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, &SecurityAttributes, dwCreationDisposition, v6, 0);
  v9 = v8;
  if ( v8 == (HANDLE)-1 )
    goto LABEL_51;
  FileType = GetFileType(v8);
  if ( FileType )
  {
    if ( FileType == 2 )
    {
      v20 |= 0x40u;
    }
    else if ( FileType == 3 )
    {
      v20 |= 8u;
    }
    sub_595924(v7, v9);
    v13 = v20 | 1;
    v14 = 36 * (v7 & 0x1F);
    v15 = (v20 & 0x48) == 0;
    lpFileName_3 = v20 & 0x48;
    *(_BYTE *)(dword_8D4920[v7 >> 5] + v14 + 4) = v20 | 1;
    if ( v15 && v13 < 0 && (a2 & 2) != 0 )
    {
      dwShareMode = FileSeekViaSetFilePointer(v7, -1, 2u);
      if ( dwShareMode == -1 )
      {
        if ( *(_DWORD *)TLSOffsetGetter_afd8() != 131 )
        {
LABEL_63:
          sub_58C331(v7);
          v11 = -1;
          goto LABEL_72;
        }
      }
      else
      {
        HIBYTE(Buffer) = 0;
        if ( !sub_58CA19(v7, (char *)&Buffer + 3, 1u) && HIBYTE(Buffer) == 26 && sub_59797B(v7, dwShareMode) == -1
          || FileSeekViaSetFilePointer(v7, 0, 0) == -1 )
        {
          goto LABEL_63;
        }
      }
    }
    if ( !lpFileName_3 && (a2 & 8) != 0 )
      *(_BYTE *)(dword_8D4920[v7 >> 5] + v14 + 4) |= 0x20u;
    v11 = v7;
    goto LABEL_72;
  }
  CloseHandle(v9);
LABEL_51:
  LastError = GetLastError();
  ErrorIDLookupTable(LastError);
  v11 = -1;
LABEL_72:
  FileCriticalSectionLeave(v7);
  return v11;
}
