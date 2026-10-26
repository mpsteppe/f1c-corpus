int __thiscall sub_4E5DB0(_DWORD *this, char *String2)
{
  int *v3; // eax
  int v4; // esi
  const char *v5; // eax
  int v6; // eax
  int *v7; // eax

  v3 = (int *)this[4];
  this[6] = v3;
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( *v3 )
  {
    do
    {
      v5 = *(const char **)(v4 + 8);
      if ( !v5 )
        v5 = &byte_629120;
      if ( !_strcmpi(v5, String2) )
        break;
      v6 = this[6];
      if ( v6 )
        this[6] = *(_DWORD *)(v6 + 4);
      v7 = (int *)this[6];
      if ( !v7 )
        return 0;
      v4 = *v7;
    }
    while ( *v7 );
  }
  return v4;
}
