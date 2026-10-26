char __thiscall sub_4EABE0(_DWORD *this, char *String1)
{
  int v3; // eax
  const char *v4; // eax
  int v6; // ebp
  int v7; // esi
  CHAR ***v8; // eax
  CHAR **v9; // eax
  CHAR *v10; // eax

  v3 = this[24];
  if ( v3 )
  {
    v4 = *(const char **)(v3 + 12);
    if ( !v4 )
      v4 = &byte_629120;
    if ( !_strcmpi(String1, v4) )
      return 1;
  }
  v6 = sub_4EB6C0(String1);
  if ( !v6 )
    return 0;
  v7 = this[24];
  if ( v7 )
  {
    sub_4EACE0(v7 + 100);
    sub_40D5B0((LPVOID *)(v7 + 128));
    sub_40D5B0((LPVOID *)(v7 + 112));
    sub_40D5B0((LPVOID *)(v7 + 100));
    sub_4EDBE0(v7 + 84);
    sub_4EDAD0(v7 + 68);
    sub_4EDAD0(v7 + 52);
    sub_4667A0((_DWORD *)(v7 + 36));
    if ( *(_DWORD *)(v7 + 28) )
      sub_5BE8AE(*(LPVOID *)(v7 + 28));
    sub_40D5B0((LPVOID *)(v7 + 20));
    sub_40D5B0((LPVOID *)(v7 + 12));
    sub_40D5B0((LPVOID *)(v7 + 4));
    sub_5BE8AE((LPVOID)v7);
  }
  this[24] = v6;
  v8 = *(CHAR ****)(v6 + 84);
  *(_DWORD *)(v6 + 92) = v8;
  if ( v8 )
  {
    v9 = *v8;
    if ( v9 )
    {
      v10 = *v9;
      if ( !v10 )
        v10 = &byte_629120;
      sub_46DF90(v10);
    }
  }
  return 1;
}
