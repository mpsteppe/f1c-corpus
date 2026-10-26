int __thiscall sub_411AB0(_WORD *this)
{
  int i; // eax
  int j; // esi
  bool v4; // zf
  int v5; // eax
  unsigned __int16 *v6; // ecx
  int v7; // edi
  int v8; // edx

  for ( i = 0; i < 537; ++i )
  {
    this[2 * i] = 1;
    this[2 * i + 1] = 0;
  }
  for ( j = 0; j < 537; ++j )
  {
    if ( j > 292 )
    {
      v4 = j == 536;
    }
    else
    {
      if ( j >= 291 )
        continue;
      v4 = j == 0;
    }
    if ( !v4 )
    {
      v5 = TableLookupByIndex(j);
      if ( v5 >= 0 )
      {
        if ( j <= 0 || j >= 291 )
        {
          if ( j <= 292 || j >= 536 )
            continue;
          v6 = word_5BF2F8;
        }
        else
        {
          v6 = word_5BEBB0;
        }
        v7 = v6[v5 + 1] - v6[v5];
        if ( v7 > 0 )
        {
          v8 = RandLCGRandomNumberGenerator() % v7;
          this[2 * j] = v7;
          this[2 * j + 1] = v8;
        }
      }
    }
  }
  return 0;
}

