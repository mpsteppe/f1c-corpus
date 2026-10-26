int __thiscall sub_50C860(_DWORD *this, int a2, float a3)
{
  long double v3; // st7
  int result; // eax
  int *v6; // edi
  int *v7; // edi
  int *v8; // edi

  v3 = fabs(a3);
  if ( v3 < 64.0 )
  {
    if ( v3 < 16.0 )
    {
      result = this[76 * a2 + 127];
      if ( result )
      {
        this[76 * a2 + 127] = 0;
        sub_5A2930(0, 0, 0);
        v8 = &dword_7D7A48;
        do
        {
          result = *v8;
          if ( *v8 )
            result = sub_5A2930(this[848], result, 0);
          ++v8;
        }
        while ( (int)v8 < (int)&dword_7D7A54 );
      }
    }
    else
    {
      result = 1;
      if ( this[76 * a2 + 127] != 1 )
      {
        this[76 * a2 + 127] = 1;
        sub_5A2930(1, 0, 0);
        v7 = &dword_7D7A48;
        do
        {
          result = *v7;
          if ( *v7 )
            result = sub_5A2930(this[848], result, 0);
          ++v7;
        }
        while ( (int)v7 < (int)&dword_7D7A54 );
      }
    }
  }
  else
  {
    result = 2;
    if ( this[76 * a2 + 127] != 2 )
    {
      this[76 * a2 + 127] = 2;
      sub_5A2930(2, 0, 0);
      v6 = &dword_7D7A48;
      do
      {
        result = *v6;
        if ( *v6 )
          result = sub_5A2930(this[848], result, 0);
        ++v6;
      }
      while ( (int)v6 < (int)&dword_7D7A54 );
    }
  }
  return result;
}
