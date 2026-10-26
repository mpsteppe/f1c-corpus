int __thiscall sub_54C44A(int this, LPCWCH lpWideCharStr, LPSTR lpMultiByteStr)
{
  void *v5; // esp
  HANDLE FileW; // eax
  HANDLE FileMappingA; // eax
  LPVOID v8; // eax
  DWORD FileSize; // eax
  CHAR v10[12]; // [esp+0h] [ebp-34h] BYREF
  struct _OSVERSIONINFOA VersionInformation; // [esp+Ch] [ebp-28h] BYREF
  int cbMultiByte; // [esp+A0h] [ebp+6Ch]

  if ( !lpWideCharStr )
    return -2005530516;
  if ( !lpMultiByteStr )
    goto LABEL_8;
  VersionInformation.dwOSVersionInfoSize = 148;
  GetVersionExA(&VersionInformation);
  if ( VersionInformation.dwPlatformId != 2 )
  {
    cbMultiByte = WideCharToMultiByte(0, 0, lpWideCharStr, -1, 0, 0, 0, 0);
    v5 = alloca(cbMultiByte);
    WideCharToMultiByte(0, 0, lpWideCharStr, -1, v10, cbMultiByte, 0, 0);
    lpWideCharStr = (LPCWCH)v10;
    lpMultiByteStr = 0;
  }
  if ( lpMultiByteStr )
    FileW = CreateFileW(lpWideCharStr, 0x80000000, 1u, 0, 3u, 0x10000000u, 0);
  else
LABEL_8:
    FileW = CreateFileA((LPCSTR)lpWideCharStr, 0x80000000, 1u, 0, 3u, 0x10000000u, 0);
  *(_DWORD *)this = FileW;
  if ( FileW != (HANDLE)-1 )
  {
    FileMappingA = CreateFileMappingA(FileW, 0, 2u, 0, 0, 0);
    *(_DWORD *)(this + 4) = FileMappingA;
    if ( FileMappingA != (HANDLE)-1 )
    {
      v8 = MapViewOfFile(FileMappingA, 4u, 0, 0, 0);
      *(_DWORD *)(this + 8) = v8;
      if ( v8 )
      {
        FileSize = GetFileSize(*(HANDLE *)this, 0);
        *(_DWORD *)(this + 12) = FileSize;
        if ( FileSize != -1 )
          return 0;
      }
    }
  }
  GetLastError();
  return -2005529767;
}
