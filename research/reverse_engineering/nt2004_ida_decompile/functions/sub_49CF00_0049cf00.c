int __thiscall sub_49CF00(_DWORD *this, char *String2)
{
  int *v3; // eax
  int v4; // esi
  const char *v5; // eax
  int v6; // eax
  int *v7; // eax

  v3 = (int *)this[21];
  this[23] = v3;
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( !*v3 )
    return 0;
  while ( 1 )
  {
    v5 = *(const char **)(v4 + 4);
    if ( !v5 )
      v5 = &byte_629120;
    if ( !_strcmpi(v5, String2) )
      break;
    v6 = this[23];
    if ( v6 )
      this[23] = *(_DWORD *)(v6 + 4);
    v7 = (int *)this[23];
    if ( v7 )
    {
      v4 = *v7;
      if ( *v7 )
        continue;
    }
    return 0;
  }
  return v4;
}
