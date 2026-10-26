char __thiscall sub_475A00(_DWORD *this, char *String1)
{
  char v3; // bl
  int i; // esi
  int v5; // ecx
  int *v6; // eax
  int v7; // eax
  const char *v8; // eax

  v3 = 0;
  for ( i = 0; i < this[74]; ++i )
  {
    v5 = i;
    if ( i >= 0 && i < this[74] )
    {
      v6 = (int *)this[71];
      if ( i <= 0 )
      {
LABEL_7:
        if ( v6 )
        {
          v7 = *v6;
          if ( v7 )
          {
            v8 = *(const char **)(v7 + 64);
            if ( !v8 )
              v8 = &byte_629120;
            if ( !_strcmpi(String1, v8) )
              v3 = 1;
          }
        }
      }
      else
      {
        while ( v6 )
        {
          v6 = (int *)v6[1];
          if ( --v5 <= 0 )
            goto LABEL_7;
        }
      }
    }
  }
  return v3;
}
