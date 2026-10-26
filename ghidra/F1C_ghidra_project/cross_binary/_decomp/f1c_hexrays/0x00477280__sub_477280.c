// f1c  0x00477280  size=273
int __thiscall sub_477280(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ecx
  const char *v5; // esi
  const char *v6; // eax
  int v7; // esi
  int i; // edx
  int v9; // ecx
  int *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // esi

  result = this[39];
  v4 = *(_DWORD *)(a2 + 156);
  if ( result && v4 )
  {
    v5 = *(const char **)(result + 52);
    if ( !v5 )
      v5 = byte_5EA438;
    v6 = *(const char **)(v4 + 52);
    if ( !v6 )
      v6 = byte_5EA438;
    result = strcmp(v6, v5);
    if ( !result )
    {
      v7 = this[63];
      for ( i = 0; i < v7; ++i )
      {
        v9 = i;
        if ( i >= 0 && i < this[63] )
        {
          v10 = (int *)this[60];
          if ( i <= 0 )
          {
LABEL_14:
            if ( v10 )
            {
              v11 = *v10;
              if ( v11 )
              {
                if ( *(_DWORD *)(v11 + 48) == a2 )
                  return sub_48FDB0(a2);
              }
            }
          }
          else
          {
            while ( v10 )
            {
              v10 = (int *)v10[1];
              if ( --v9 <= 0 )
                goto LABEL_14;
            }
          }
        }
      }
      v12 = sub_587C03(52);
      if ( v12 )
        v13 = sub_48FD60(v12);
      else
        v13 = 0;
      sub_48FDB0(a2);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v13 + 16))(v13, 0);
      sub_48F5D0(v13, 1);
      return sub_48F640(this);
    }
  }
  return result;
}
