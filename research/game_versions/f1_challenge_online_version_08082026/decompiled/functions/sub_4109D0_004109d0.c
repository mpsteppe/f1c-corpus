int __thiscall sub_4109D0(int *this, float a2)
{
  int result; // eax
  int i; // esi
  int j; // edi
  int v6; // edi
  bool v7; // cc
  int v8; // ecx
  int k; // edi
  int v10; // ecx

  if ( dword_8AB6E4 == 2 )
  {
    result = dword_5C329C;
    for ( i = 0; i < dword_5C329C; ++i )
    {
      sub_4F0430(a2);
      sub_4EF180(dword_7C54F0[i] + 12);
      result = dword_5C329C;
    }
  }
  else
  {
    for ( j = 0; j < *this; ++j )
      sub_40F300(*(_DWORD **)(this[2] + 4 * j), a2);
    if ( dword_8AB6E4 == 1 && *((float *)this + 27) + 1.0 < a2 )
    {
      result = *this;
      v6 = 0;
      v7 = *this <= 0;
      *((float *)this + 27) = a2;
      if ( !v7 )
      {
        do
        {
          v8 = *(_DWORD *)(this[2] + 4 * v6);
          if ( *(_DWORD *)(v8 + 28) != 6 )
            sub_40F600(v8);
          result = *this;
          ++v6;
        }
        while ( v6 < *this );
      }
    }
    else
    {
      result = *this;
      for ( k = 0; k < *this; ++k )
      {
        v10 = *(_DWORD *)(this[2] + 4 * k);
        if ( *(_DWORD *)(v10 + 28) != 6 && *(_BYTE *)(v10 + 10) )
          sub_40F600(v10);
        result = *this;
      }
    }
  }
  return result;
}
