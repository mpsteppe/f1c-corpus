void __thiscall sub_4840E0(_DWORD *this)
{
  const char *v2; // ebx
  int i; // edi
  int v4; // ecx
  int *v5; // eax
  int v6; // eax
  const char **v7; // eax
  const char *v8; // eax
  int v9; // eax
  int v10; // ecx

  v2 = dword_7665D8;
  if ( !dword_7665D8 )
    v2 = &byte_629120;
  for ( i = 0; i < this[220]; ++i )
  {
    v4 = i;
    if ( i >= 0 && i < this[220] )
    {
      v5 = (int *)this[217];
      if ( i <= 0 )
      {
LABEL_9:
        if ( v5 )
        {
          v6 = *v5;
          if ( v6 )
          {
            v7 = *(const char ***)(v6 + 84);
            if ( v7 )
            {
              v8 = *v7;
              if ( !v8 )
                v8 = &byte_629120;
              if ( !_strcmpi(v8, v2) )
              {
                this[216] = i;
                break;
              }
            }
          }
        }
      }
      else
      {
        while ( v5 )
        {
          v5 = (int *)v5[1];
          if ( --v4 <= 0 )
            goto LABEL_9;
        }
      }
    }
  }
  v9 = this[216];
  if ( v9 < 0 || v9 >= this[220] )
  {
    this[219] = 0;
  }
  else
  {
    for ( this[219] = this[217]; v9 > 0; this[219] = *(_DWORD *)(v10 + 4) )
    {
      v10 = this[219];
      if ( !v10 )
        break;
      --v9;
    }
  }
  sub_484090(this);
}
