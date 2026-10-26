int sub_4BACD0()
{
  int v0; // esi
  __int16 *i; // edi
  __int16 v2; // ax
  signed int j; // esi
  int result; // eax
  int v5; // ecx
  double v6; // st7
  void *v7; // eax
  CHAR *v8; // eax
  int v9; // esi
  __int16 *k; // edi
  __int16 v11; // ax
  bool v12; // [esp+12h] [ebp-6h]
  bool v13; // [esp+13h] [ebp-5h]

  v12 = dword_75CBB0 == 7;
  v13 = sub_463490(dword_764D70);
  if ( byte_766185 )
  {
    if ( *(_DWORD *)dword_7689CC == 5 )
    {
      byte_766185 = 0;
LABEL_20:
      sub_5074D0(0.0);
      return 4;
    }
    if ( !(unsigned __int8)sub_4D9AE0(&unk_7D5DAC) )
    {
      sub_42FA50(&dword_75CBA8, 1);
      sub_4F0190(&byte_7D6B78);
      v0 = 0;
      for ( i = word_762A08; ; ++i )
      {
        if ( v0 >= ((dword_761FF8 & 3) != 0 ? dword_762A04 : 0) )
          goto LABEL_21;
        v2 = *i;
        if ( *i == 21 )
          break;
        if ( v2 == 49 || v2 == 1 || dword_763B84 )
        {
          byte_766185 = 0;
          sub_42FA50(&dword_75CBA8, 0);
          sub_4F01B0(&byte_7D6B78);
        }
        ++v0;
      }
      if ( dword_75CBB0 == 7 )
      {
        for ( j = 0; j < (int)NumOfElements; ++j )
          sub_4DD150(dword_75AAD0[j] + 20836);
      }
      if ( sub_42DBA0() && *(_DWORD *)(dword_75AACC + 16584) == 1 )
        sub_51BC20(0, 0);
      byte_766185 = 0;
      sub_42FA50(&dword_75CBA8, 0);
      goto LABEL_20;
    }
  }
LABEL_21:
  if ( byte_766186 || byte_766188 )
  {
    byte_766186 = 0;
    return 6;
  }
  if ( dword_76618C == 1 )
  {
    if ( dword_766180 != 1 )
      goto LABEL_32;
    return 6;
  }
  sub_4057C0((void **)&dword_629124);
  if ( sub_405BE0(&dword_629124) && dword_608F60 == 3 )
    return 6;
  if ( !byte_76617C )
  {
LABEL_32:
    if ( !byte_766191 )
      goto LABEL_40;
    v6 = *(float *)&dword_766194 - dbl_7DA9C8;
    *(float *)&dword_766194 = v6;
    if ( v6 <= 2.5 && flt_7D79F4 <= 0.0 )
    {
      v7 = (void *)sub_40C460(&dword_6291CC);
      if ( v7 )
      {
        v8 = sub_459BA0(v7);
        _strcmpi(v8, aTrackside);
      }
      sub_5074A0(0.5);
    }
    if ( *(float *)&dword_766194 <= 0.0 )
    {
      byte_766191 = 0;
      dword_766194 = 0;
      dword_766180 = 1;
    }
    else
    {
LABEL_40:
      if ( dword_766180 != 1 )
      {
        if ( dword_766180 == 2 && !v12 )
          dword_766180 = 1;
        goto LABEL_47;
      }
    }
    if ( dword_76618C == 1 )
      dword_75CBA8 = 6;
    else
      sub_4BA580();
LABEL_47:
    if ( byte_76617C )
    {
LABEL_70:
      sub_4BA250();
      return dword_75CBA8;
    }
    v9 = 0;
    for ( k = word_762A08; ; ++k )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          if ( v9 >= ((dword_761FF8 & 3) != 0 ? dword_762A04 : 0) )
            goto LABEL_70;
          if ( dword_766180 == 2 )
            break;
          if ( *k != 1 )
            goto LABEL_69;
          if ( sub_405BE0(&dword_629124) )
          {
            dword_75CBA8 = 6;
            sub_405C10(&dword_629124);
            ++v9;
            ++k;
          }
          else
          {
            if ( !v12 )
            {
              dword_766180 = 1;
              goto LABEL_69;
            }
            dword_766180 = 2;
            if ( v13 )
              goto LABEL_69;
            sub_42FA50(&dword_75CBA8, 1);
            sub_4F0190(&byte_7D6B78);
            ++v9;
            ++k;
          }
        }
        if ( (unsigned __int8)sub_4D9AE0(&unk_7D5DAC) )
          goto LABEL_69;
        v11 = *k;
        if ( *k == 21 )
          break;
        if ( (v11 == 49 || v11 == 1 || dword_763B84) && dword_766180 == 2 && v12 )
        {
          dword_766180 = 0;
          sub_42FA50(&dword_75CBA8, 0);
          sub_4F01B0(&byte_7D6B78);
          ++v9;
          ++k;
        }
        else
        {
LABEL_69:
          ++v9;
          ++k;
        }
      }
      if ( dword_766180 != 2 || !v12 )
        goto LABEL_69;
      sub_4BA580();
      ++v9;
    }
  }
  v5 = dword_766178++;
  result = sub_49C1D0(v5, byte_766187);
  if ( result == -1 || result == 3 )
    return 6;
  if ( result != 4 )
    goto LABEL_32;
  return result;
}
