int __cdecl _strnicmp(const char *String1, const char *String2, size_t MaxCount)
{
  _DWORD *v3; // ebx
  const char *v5; // esi
  const char *v6; // edi
  int v7; // eax
  int v8; // [esp+4h] [ebp-4h]

  v3 = (_DWORD *)_getptd()[25];
  if ( v3 != off_91290C )
    v3 = (_DWORD *)__updatetlocinfo();
  if ( !MaxCount )
    return 0;
  if ( !v3[5] )
    return __ascii_strnicmp(String1, String2, MaxCount);
  v5 = String1;
  v6 = String2;
  do
  {
    v8 = ((int (__cdecl *)(_DWORD *, _DWORD))loc_63508D)(v3, *(unsigned __int8 *)v5++);
    v7 = ((int (__cdecl *)(_DWORD *, _DWORD))loc_63508D)(v3, *(unsigned __int8 *)v6++);
    --MaxCount;
  }
  while ( MaxCount && v8 && v8 == v7 );
  return v8 - v7;
}
