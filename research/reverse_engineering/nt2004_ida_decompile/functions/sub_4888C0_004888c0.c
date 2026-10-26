char __thiscall sub_4888C0(_DWORD *this, const char *a2)
{
  int v3; // ecx
  char result; // al
  int v5; // edi
  int v6; // esi
  int *v7; // edx
  int v8; // edx
  const char *v9; // esi
  char v10; // [esp+Bh] [ebp-1h]

  v3 = this[219];
  result = 0;
  v5 = 0;
  v10 = 0;
  if ( v3 > 0 )
  {
    do
    {
      v6 = v5;
      if ( v5 >= 0 && v5 < this[219] )
      {
        v7 = (int *)this[216];
        if ( v5 <= 0 )
        {
LABEL_7:
          if ( v7 )
          {
            v8 = *v7;
            if ( v8 )
            {
              v9 = *(const char **)(v8 + 64);
              if ( !v9 )
                v9 = &byte_629120;
              if ( !strcmp(a2, v9) )
                v10 = 1;
            }
          }
        }
        else
        {
          while ( v7 )
          {
            v7 = (int *)v7[1];
            if ( --v6 <= 0 )
              goto LABEL_7;
          }
        }
      }
      ++v5;
    }
    while ( v5 < v3 );
    return v10;
  }
  return result;
}
