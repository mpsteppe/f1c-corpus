CHAR *__thiscall sub_4EC510(_DWORD *this, int a2)
{
  int **v3; // eax
  int v4; // ebx
  int *v5; // edi
  const char *v6; // eax
  const char *v7; // ecx
  int v8; // eax
  int **v9; // eax
  int v11; // [esp+10h] [ebp-4h]

  v11 = 0;
  if ( this[24] )
  {
    if ( a2 >= 0 && a2 < sub_4EC4A0(this) )
    {
      v3 = (int **)this[8];
      v4 = -1;
      this[10] = v3;
      if ( v3 )
      {
        v5 = *v3;
        if ( *v3 )
        {
          while ( 1 )
          {
            v6 = *(const char **)(this[24] + 20);
            if ( !v6 )
              v6 = &byte_629120;
            v7 = (const char *)v5[7];
            if ( !v7 )
              v7 = &byte_629120;
            if ( !_strcmpi(v7, v6) && ++v4 == a2 )
              break;
            v8 = this[10];
            if ( v8 )
              this[10] = *(_DWORD *)(v8 + 4);
            v9 = (int **)this[10];
            if ( !v9 )
              return (CHAR *)v11;
            v5 = *v9;
            if ( !*v9 )
              return 0;
          }
          v11 = *v5;
          if ( !*v5 )
            return &byte_629120;
        }
      }
    }
  }
  return (CHAR *)v11;
}
