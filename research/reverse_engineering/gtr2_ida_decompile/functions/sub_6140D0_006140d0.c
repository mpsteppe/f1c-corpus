int __thiscall sub_6140D0(int **this, char *String2)
{
  int *v3; // eax
  bool v4; // zf
  int v5; // esi
  const char *v6; // eax
  int *v7; // eax
  int *v8; // eax

  v3 = *this;
  v4 = *this == 0;
  this[2] = *this;
  if ( v4 )
    return 0;
  v5 = *v3;
  if ( !*v3 )
    return 0;
  while ( 1 )
  {
    v6 = *(const char **)(v5 + 4);
    if ( !v6 )
      v6 = WindowName;
    if ( !_stricmp(v6, String2) )
      break;
    v7 = this[2];
    if ( v7 )
    {
      v8 = (int *)v7[1];
      this[2] = v8;
      if ( v8 )
      {
        v5 = *v8;
        if ( *v8 )
          continue;
      }
    }
    return 0;
  }
  if ( *(_BYTE *)v5 )
    return 0;
  *(_BYTE *)v5 = 1;
  *(_DWORD *)(v5 + 24) = 0;
  return v5;
}
