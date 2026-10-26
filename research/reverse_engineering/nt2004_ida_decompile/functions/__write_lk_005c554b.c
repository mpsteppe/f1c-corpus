int __cdecl _write_lk(int FileHandle, _BYTE *lpBuffer, DWORD nNumberOfBytesToWrite)
{
  _DWORD *v4; // ebx
  int v5; // esi
  int v6; // eax
  _BYTE *v7; // eax
  char *v8; // ecx
  char v9; // cl
  signed int v10; // edi
  _BYTE Buffer[1028]; // [esp+Ch] [ebp-414h] BYREF
  int v12; // [esp+410h] [ebp-10h]
  DWORD NumberOfBytesWritten; // [esp+414h] [ebp-Ch] BYREF
  DWORD v14; // [esp+418h] [ebp-8h]
  char *v15; // [esp+41Ch] [ebp-4h]
  DWORD FileHandlea; // [esp+428h] [ebp+8h]

  v14 = 0;
  v12 = 0;
  if ( !nNumberOfBytesToWrite )
    return 0;
  v4 = (_DWORD *)(4 * (FileHandle >> 5) + 8389600);
  v5 = 36 * (FileHandle & 0x1F);
  if ( (*(_BYTE *)(dword_8003E0[FileHandle >> 5] + v5 + 4) & 0x20) != 0 )
    _lseek_lk(FileHandle, 0, 2u);
  v6 = v5 + dword_8003E0[FileHandle >> 5];
  if ( *(char *)(v6 + 4) >= 0 )
  {
    if ( WriteFile(*(HANDLE *)v6, lpBuffer, nNumberOfBytesToWrite, &NumberOfBytesWritten, 0) )
    {
      FileHandlea = 0;
      v14 = NumberOfBytesWritten;
    }
    else
    {
      FileHandlea = GetLastError();
    }
  }
  else
  {
    v15 = lpBuffer;
    FileHandlea = 0;
    while ( 1 )
    {
      v7 = Buffer;
      do
      {
        if ( v15 - lpBuffer >= nNumberOfBytesToWrite )
          break;
        v8 = v15++;
        v9 = *v8;
        if ( v9 == 10 )
        {
          ++v12;
          *v7++ = 13;
        }
        *v7++ = v9;
      }
      while ( v7 - Buffer < 1024 );
      v10 = v7 - Buffer;
      if ( !WriteFile(*(HANDLE *)(*v4 + v5), Buffer, v7 - Buffer, &NumberOfBytesWritten, 0) )
        break;
      v14 += NumberOfBytesWritten;
      if ( (int)NumberOfBytesWritten < v10 || v15 - lpBuffer >= nNumberOfBytesToWrite )
        goto LABEL_15;
    }
    FileHandlea = GetLastError();
  }
LABEL_15:
  if ( v14 )
    return v14 - v12;
  if ( FileHandlea )
  {
    if ( FileHandlea == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
    }
    else
    {
      _dosmaperr(FileHandlea);
    }
  }
  else
  {
    if ( (*(_BYTE *)(*v4 + v5 + 4) & 0x40) != 0 && *lpBuffer == 26 )
      return 0;
    *_errno() = 28;
    *__doserrno() = 0;
  }
  return -1;
}
