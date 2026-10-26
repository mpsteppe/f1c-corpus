int __thiscall sub_659D87(
        int this,
        LPCWCH lpWideCharStr,
        LPSTR FilePart,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  int v9; // esi
  bool v10; // zf
  unsigned int v12; // kr04_4
  WCHAR *v13; // eax
  _DWORD *v14; // edi
  _DWORD *v15; // esi
  int result; // eax
  DWORD FullPathNameA; // esi
  int v18; // eax
  int v19; // eax
  unsigned int v20; // ecx
  int v21; // esi
  CHAR MultiByteStr[260]; // [esp+Ch] [ebp-104h] BYREF

  v9 = a7;
  v10 = FilePart == 0;
  *(_DWORD *)(this + 88) = a7;
  if ( !v10 )
  {
    WideCharToMultiByte(0xFDE9u, 0, lpWideCharStr, -1, MultiByteStr, 260, 0, 0);
    lpWideCharStr = (LPCWCH)MultiByteStr;
  }
  if ( v9 )
  {
    v12 = strlen((const char *)lpWideCharStr);
    v13 = (WCHAR *)sub_67EB7E(v12 + 1, 1u);
    *(_DWORD *)(this + 92) = v13;
    if ( v13 )
    {
      qmemcpy(v13, lpWideCharStr, v12 + 1);
      v14 = (_DWORD *)(this + 104);
      v15 = (_DWORD *)(this + 100);
      a7 = (***(int (__stdcall ****)(_DWORD, int, _DWORD, int, int, int))(this + 88))(
             *(_DWORD *)(this + 88),
             a8,
             *(_DWORD *)(this + 92),
             a9,
             this + 100,
             this + 104);
      if ( a7 < 0 )
      {
        sub_65DD1F(a6, a5, 1507, "failed to open source file: '%s'", (char)lpWideCharStr);
        return a7;
      }
      goto LABEL_15;
    }
    return -2147024882;
  }
  FullPathNameA = GetFullPathNameA((LPCSTR)lpWideCharStr, 0, 0, 0);
  a7 = FullPathNameA + 1;
  v18 = sub_67EB7E(FullPathNameA + 1, 1u);
  *(_DWORD *)(this + 96) = v18;
  if ( !v18 )
    return -2147024882;
  v19 = sub_67EB7E(a7, 1u);
  *(_DWORD *)(this + 92) = v19;
  if ( !v19 )
    return -2147024882;
  GetFullPathNameA((LPCSTR)lpWideCharStr, FullPathNameA, *(LPSTR *)(this + 96), &FilePart);
  v20 = a7;
  *(_BYTE *)(FullPathNameA + *(_DWORD *)(this + 96)) = 0;
  qmemcpy(*(void **)(this + 92), *(const void **)(this + 96), v20);
  if ( FilePart )
    *FilePart = 0;
  v21 = sub_65992B(this + 60, *(LPCWCH *)(this + 92), 0);
  if ( v21 < 0 )
  {
    sub_65DD1F(a6, a5, 1507, "failed to open source file: '%s'", (char)lpWideCharStr);
    return v21;
  }
  v15 = (_DWORD *)(this + 100);
  *(_DWORD *)(this + 100) = *(_DWORD *)(this + 68);
  v14 = (_DWORD *)(this + 104);
  *(_DWORD *)(this + 104) = *(_DWORD *)(this + 72);
LABEL_15:
  result = sub_65D800(*v15, *v14, *(_DWORD *)(this + 92), 1, a4, a6);
  if ( result >= 0 )
    return 0;
  return result;
}
