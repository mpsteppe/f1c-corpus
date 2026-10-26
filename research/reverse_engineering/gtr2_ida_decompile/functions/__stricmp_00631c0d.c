int __cdecl _stricmp(const char *String1, const char *String2)
{
  _DWORD *v2; // ebx
  const char *v4; // esi
  const char *v5; // edi
  int v6; // ecx
  int v7; // [esp+4h] [ebp-4h]

  v2 = *(_DWORD **)(_getptd() + 100);
  if ( v2 != off_91290C )
    v2 = (_DWORD *)__updatetlocinfo();
  if ( !v2[5] )
    return __ascii_stricmp(String1, String2);
  v4 = String1;
  v5 = String2;
  do
  {
    v7 = ((int (__cdecl *)(_DWORD *, _DWORD))loc_63508D)(v2, *(unsigned __int8 *)v4++);
    v6 = ((int (__cdecl *)(_DWORD *, _DWORD))loc_63508D)(v2, *(unsigned __int8 *)v5++);
  }
  while ( v7 && v7 == v6 );
  return v7 - v6;
}
