char __thiscall sub_4BC280(_DWORD *this, int a2)
{
  char v3; // bl
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  const char *v7; // ecx
  char *v8; // eax
  const char *v9; // esi
  char *v10; // eax
  const char *v11; // ecx
  int v13; // [esp+10h] [ebp-188h]
  int Offset; // [esp+14h] [ebp-184h]
  char Str[384]; // [esp+18h] [ebp-180h] BYREF

  v3 = 0;
  Offset = sub_57A620(a2);
  v13 = 0;
  Str[0] = 0;
  if ( !sub_57A490(Str, 384) )
    goto LABEL_26;
  while ( 1 )
  {
    if ( _strnicmp(Str, asc_5FD0CC, 2u) )
    {
      v4 = strstr(Str, asc_5FB9D8);
      if ( v4 )
        *v4 = 0;
      v5 = strstr(Str, asc_5FD0C8);
      if ( v5 )
        *v5 = 0;
      if ( strlen(Str) )
      {
        ++v13;
        v6 = strtok(Str, Delimiter);
        v7 = (const char *)this[1];
        if ( !v7 )
          v7 = &byte_629120;
        if ( !_strcmpi(v6, v7) )
          break;
      }
    }
    if ( !sub_57A490(Str, 384) )
      goto LABEL_26;
  }
  v8 = strtok(0, &byte_629120);
  v9 = v8;
  if ( v8 )
  {
    v10 = strstr(v8, asc_5FD0CC);
    if ( v10 )
      *v10 = 0;
    if ( *v9 == 34 )
      ++v9;
    v11 = &v9[strlen(v9)];
    if ( v11 >= v9 )
    {
      while ( *v11 != 34 )
      {
        if ( --v11 < v9 )
          goto LABEL_21;
      }
      *v11 = 0;
    }
LABEL_21:
    (*(void (__thiscall **)(_DWORD *, const char *))(*this + 4))(this, v9);
  }
  else
  {
    (*(void (__thiscall **)(_DWORD *, CHAR *))(*this + 4))(this, &byte_629120);
  }
  v3 = 1;
  if ( v13 != 1 )
LABEL_26:
    sub_57A5B0(Offset);
  return v3;
}
