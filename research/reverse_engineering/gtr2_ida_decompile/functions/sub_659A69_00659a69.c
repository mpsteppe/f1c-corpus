int __thiscall sub_659A69(_DWORD *this, LPCWCH lpWideCharStr, int cbMultiByte)
{
  _DWORD *v3; // edi
  void *v5; // eax
  HANDLE FileW; // eax
  void *v7; // [esp-8h] [ebp-ACh]
  struct _OSVERSIONINFOA VersionInformation; // [esp+8h] [ebp-9Ch] BYREF
  _DWORD *v9; // [esp+9Ch] [ebp-8h]
  void *Block; // [esp+A0h] [ebp-4h]
  size_t cbMultiBytea; // [esp+B0h] [ebp+Ch]

  v3 = this;
  v9 = this;
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
    v3 = v9;
    lpWideCharStr = (LPCWCH)Block;
    cbMultiByte = 0;
  }
  if ( cbMultiByte )
    FileW = CreateFileW(lpWideCharStr, 0x40000000u, 0, 0, 2u, 0, 0);
  else
LABEL_10:
    FileW = CreateFileA((LPCSTR)lpWideCharStr, 0x40000000u, 0, 0, 2u, 0, 0);
  v7 = Block;
  *v3 = FileW;
  j__free(v7);
  if ( *v3 != -1 )
    return 0;
  GetLastError();
  return -2005529767;
}
