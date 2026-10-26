int __cdecl _write_lk(int FileHandle, char *lpBuffer, DWORD nNumberOfBytesToWrite)
{
  int v4; // esi
  int v5; // eax
  DWORD v6; // ecx
  _BYTE *v7; // eax
  char *v8; // edx
  char v9; // dl
  signed int v10; // edi
  DWORD NumberOfBytesWritten; // [esp+4h] [ebp-80h] BYREF
  int v12; // [esp+8h] [ebp-7Ch]
  DWORD v13; // [esp+Ch] [ebp-78h]
  char *v14; // [esp+10h] [ebp-74h]
  int i; // [esp+14h] [ebp-70h]
  DWORD LastError; // [esp+18h] [ebp-6Ch]
  _BYTE Buffer[1028]; // [esp+1Ch] [ebp-68h] BYREF
  int v18; // [esp+420h] [ebp+39Ch]

  v18 = dword_912B08;
  v13 = 0;
  v12 = 0;
  if ( !nNumberOfBytesToWrite )
    return 0;
  v4 = 36 * (FileHandle & 0x1F);
  if ( (*(_BYTE *)(dword_FBB4E0[FileHandle >> 5] + v4 + 4) & 0x20) != 0 )
    _lseeki64_lk(FileHandle, 0, 0, 2u);
  v5 = v4 + dword_FBB4E0[FileHandle >> 5];
  if ( *(char *)(v5 + 4) < 0 )
  {
    v14 = lpBuffer;
    LastError = 0;
    while ( 1 )
    {
      v6 = v14 - lpBuffer;
      v7 = Buffer;
      for ( i = 0; i < 1024; ++i )
      {
        if ( v6 >= nNumberOfBytesToWrite )
          break;
        v8 = v14++;
        v9 = *v8;
        ++v6;
        if ( v9 == 10 )
        {
          ++v12;
          *v7++ = 13;
          ++i;
        }
        *v7++ = v9;
      }
      v10 = v7 - Buffer;
      if ( !WriteFile(
              *(HANDLE *)(dword_FBB4E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F)),
              Buffer,
              v7 - Buffer,
              &NumberOfBytesWritten,
              0) )
        goto LABEL_16;
      v13 += NumberOfBytesWritten;
      if ( (int)NumberOfBytesWritten < v10 || v14 - lpBuffer >= nNumberOfBytesToWrite )
        goto LABEL_17;
    }
  }
  if ( !WriteFile(*(HANDLE *)v5, lpBuffer, nNumberOfBytesToWrite, &NumberOfBytesWritten, 0) )
  {
LABEL_16:
    LastError = GetLastError();
    goto LABEL_17;
  }
  LastError = 0;
  v13 = NumberOfBytesWritten;
LABEL_17:
  if ( v13 )
    return v13 - v12;
  if ( LastError )
  {
    if ( LastError == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
    }
    else
    {
      _dosmaperr(LastError);
    }
  }
  else
  {
    if ( (*(_BYTE *)(dword_FBB4E0[FileHandle >> 5] + v4 + 4) & 0x40) != 0 && *lpBuffer == 26 )
      return 0;
    *_errno() = 28;
    *__doserrno() = 0;
  }
  return -1;
}
