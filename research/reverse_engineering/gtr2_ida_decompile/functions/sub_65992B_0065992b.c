int __thiscall sub_65992B(int this, LPCWCH lpWideCharStr, int cbMultiByte)
{
  void *v5; // eax
  HANDLE FileW; // eax
  HANDLE FileMappingA; // eax
  DWORD FileSize; // eax
  LPVOID v9; // eax
  void *v10; // [esp-8h] [ebp-A8h]
  struct _OSVERSIONINFOA VersionInformation; // [esp+8h] [ebp-98h] BYREF
  void *Block; // [esp+9Ch] [ebp-4h]
  size_t cbMultiBytea; // [esp+ACh] [ebp+Ch]

  Block = 0;
  if ( !lpWideCharStr )
    return -2005530516;
  if ( !cbMultiByte )
    goto LABEL_10;
  VersionInformation.dwOSVersionInfoSize = 148;
  GetVersionExA(&VersionInformation);
  if ( VersionInformation.dwPlatformId != 2 )
  {
    cbMultiBytea = WideCharToMultiByte(0xFDE9u, 0, lpWideCharStr, -1, 0, 0, 0, 0);
    v5 = operator new(cbMultiBytea);
    Block = v5;
    if ( !v5 )
      return -2147024882;
    WideCharToMultiByte(0xFDE9u, 0, lpWideCharStr, -1, (LPSTR)v5, cbMultiBytea, 0, 0);
    lpWideCharStr = (LPCWCH)Block;
    cbMultiByte = 0;
  }
  if ( cbMultiByte )
    FileW = CreateFileW(lpWideCharStr, 0x80000000, 1u, 0, 3u, 0x10000000u, 0);
  else
LABEL_10:
    FileW = CreateFileA((LPCSTR)lpWideCharStr, 0x80000000, 1u, 0, 3u, 0x10000000u, 0);
  v10 = Block;
  *(_DWORD *)this = FileW;
  j__free(v10);
  if ( *(_DWORD *)this == -1 )
    goto LABEL_16;
  FileMappingA = CreateFileMappingA(*(HANDLE *)this, 0, 2u, 0, 0, 0);
  *(_DWORD *)(this + 4) = FileMappingA;
  if ( FileMappingA == (HANDLE)-1 )
    goto LABEL_16;
  FileSize = GetFileSize(*(HANDLE *)this, 0);
  *(_DWORD *)(this + 12) = FileSize;
  if ( FileSize == -1 )
    goto LABEL_16;
  if ( FileSize )
  {
    v9 = MapViewOfFile(*(HANDLE *)(this + 4), 4u, 0, 0, 0);
    *(_DWORD *)(this + 8) = v9;
    if ( !v9 )
    {
LABEL_16:
      GetLastError();
      return -2005529767;
    }
  }
  else
  {
    *(_DWORD *)(this + 8) = 0;
  }
  return 0;
}
