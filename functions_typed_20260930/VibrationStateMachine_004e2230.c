int __thiscall sub_4E2230(_DWORD *this, int a2, float a3)
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
      result = this[74 * a2 + 123];
      if ( result )
      {
        this[74 * a2 + 123] = 0;
        sub_5506A0(0, 0, 0);
        v8 = &dword_8AD3EC;
        do
        {
          result = *v8;
          if ( *v8 )
            result = sub_5506A0(this[731], result, 0);
          ++v8;
        }
        while ( (int)v8 < (int)&unk_8AD3F8 );
      }
    }
    else
    {
      result = 1;
      if ( this[74 * a2 + 123] != 1 )
      {
        this[74 * a2 + 123] = 1;
        sub_5506A0(1, 0, 0);
        v7 = &dword_8AD3EC;
        do
        {
          result = *v7;
          if ( *v7 )
            result = sub_5506A0(this[731], result, 0);
          ++v7;
        }
        while ( (int)v7 < (int)&unk_8AD3F8 );
      }
    }
  }
  else
  {
    result = 2;
    if ( this[74 * a2 + 123] != 2 )
    {
      this[74 * a2 + 123] = 2;
      sub_5506A0(2, 0, 0);
      v6 = &dword_8AD3EC;
      do
      {
        result = *v6;
        if ( *v6 )
          result = sub_5506A0(this[731], result, 0);
        ++v6;
      }
      while ( (int)v6 < (int)&unk_8AD3F8 );
    }
  }
  return result;
}

