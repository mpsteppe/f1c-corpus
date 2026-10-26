int __thiscall sub_436AB0(_DWORD *this, char *String1)
{
  int *v3; // eax
  int v4; // ebx
  const char *v5; // eax
  int v6; // eax
  _DWORD *v7; // esi
  int *v8; // eax
  int v9; // eax
  const char *v10; // eax
  int result; // eax

  v3 = (int *)this[7];
  this[9] = v3;
  if ( v3 )
  {
    v4 = *v3;
    if ( *v3 )
    {
      do
      {
        v5 = *(const char **)(v4 + 20);
        if ( !v5 )
          v5 = &byte_629120;
        v6 = _strcmpi(String1, v5);
        if ( v6 )
        {
          v9 = this[9];
          if ( v9 )
            this[9] = *(_DWORD *)(v9 + 4);
          v8 = (int *)this[9];
        }
        else
        {
          v7 = (_DWORD *)this[7];
          if ( v7 )
          {
            while ( *v7 != v4 )
            {
              v6 = (int)v7;
              v7 = (_DWORD *)v7[1];
              if ( !v7 )
              {
                v8 = (int *)this[7];
                this[9] = v8;
                goto LABEL_25;
              }
            }
            if ( v7 == (_DWORD *)this[9] )
              this[9] = v7[1];
            if ( v6 )
              *(_DWORD *)(v6 + 4) = v7[1];
            else
              this[7] = v7[1];
            if ( (_DWORD *)this[8] == v7 )
              this[8] = v6;
            --this[10];
            if ( *((_BYTE *)v7 + 8) && *v7 )
              sub_436BB0(1);
            sub_5BE8AE(v7);
          }
          v8 = (int *)this[7];
          this[9] = v8;
        }
LABEL_25:
        if ( !v8 )
          break;
        v4 = *v8;
      }
      while ( *v8 );
    }
  }
  v10 = (const char *)this[4];
  if ( !v10 )
    v10 = &byte_629120;
  result = _strcmpi(String1, v10);
  if ( !result )
    return sub_578600(&byte_629120);
  return result;
}
