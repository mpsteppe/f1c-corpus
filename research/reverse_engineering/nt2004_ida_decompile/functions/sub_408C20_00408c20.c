int __thiscall sub_408C20(_DWORD *this, char *String2, int a3)
{
  int v4; // esi
  int *v5; // eax
  int v6; // eax
  int *v7; // eax
  int *v9; // eax
  const char *v10; // eax
  int v11; // eax
  int *v12; // eax

  v4 = 0;
  if ( a3 != -1 )
  {
    v5 = (int *)this[14];
    this[16] = v5;
    if ( v5 )
    {
      v4 = *v5;
      if ( *v5 )
      {
        while ( *(_DWORD *)(v4 + 16) != a3 )
        {
          v6 = this[16];
          if ( v6 )
            this[16] = *(_DWORD *)(v6 + 4);
          v7 = (int *)this[16];
          if ( !v7 )
            return 0;
          v4 = *v7;
          if ( !*v7 )
            return 0;
        }
      }
      return v4;
    }
    return 0;
  }
  if ( String2 )
  {
    v9 = (int *)this[14];
    this[16] = v9;
    if ( !v9 )
      return 0;
    v4 = *v9;
    if ( *v9 )
    {
      while ( 1 )
      {
        v10 = *(const char **)(v4 + 4);
        if ( !v10 )
          v10 = &byte_629120;
        if ( !_strcmpi(v10, String2) )
          break;
        v11 = this[16];
        if ( v11 )
          this[16] = *(_DWORD *)(v11 + 4);
        v12 = (int *)this[16];
        if ( !v12 )
          return 0;
        v4 = *v12;
        if ( !*v12 )
          return 0;
      }
    }
  }
  return v4;
}
