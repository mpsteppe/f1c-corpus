int __thiscall sub_42CF10(_DWORD *this, int a2)
{
  int v3; // edi
  bool v4; // bl
  int v5; // eax
  bool v6; // dl
  bool v7; // cl
  bool v8; // al
  int k; // esi
  int m; // esi
  char v11; // bl
  int i; // esi
  int v13; // eax
  int j; // esi
  int v15; // esi
  int result; // eax

  if ( (unsigned __int8)SessionStateCheckWrapper(&dword_7CD25C) )
  {
    v11 = StateCheckWrapper(&dword_7CD25C);
    if ( v11 )
    {
      if ( this[2] == 5 )
      {
        for ( i = 0; i < dword_5C329C; ++i )
          FieldCopy(dword_7C54F0[i] + 16436);
      }
    }
    v3 = a2;
    if ( a2 == 7 )
    {
      if ( dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(2, aDDevF119992002_11, 215) )
        DebugLogWrite(&dword_8AD25C, aMultiplayerMod);
      if ( v11 )
        ChampionshipStandingsReOrdering(&dword_7CD25C);
      else
        sub_462E20(&dword_7CD25C);
      v13 = dword_5C329C;
      for ( j = 0; j < dword_5C329C; ++j )
      {
        FieldCopy_c330(dword_7C54F0[j] + 16436);
        v13 = dword_5C329C;
      }
      v15 = 0;
      if ( v13 > 0 )
      {
        do
          sub_4C6F10(dword_7C54F0[v15++]);
        while ( v15 < dword_5C329C );
      }
    }
  }
  else
  {
    v3 = a2;
    v4 = a2 == 2 || a2 == 3 || a2 == 4;
    v5 = this[2];
    v6 = v5 == 4 && a2 == 5;
    v7 = v5 == 5 && a2 == 6;
    v8 = v5 == 6 && a2 == 7;
    if ( v4 || v6 )
    {
      sub_4C01A0(&a2);
    }
    else if ( v7 )
    {
      if ( byte_7CEBC4 || dword_7D0410 == 4 )
      {
        for ( k = 0; k < dword_5C329C; ++k )
          FieldCopy(dword_7C54F0[k] + 16436);
        if ( dword_7D0410 == 4 )
          ConditionalSeasonDataFree(1);
      }
    }
    else if ( v8 )
    {
      for ( m = 0; m < dword_5C329C; ++m )
        FieldCopy_c330(dword_7C54F0[m] + 16436);
    }
  }
  this[2] = v3;
  result = dword_7D00F4;
  dword_7D00EC = v3;
  if ( v3 >= dword_7D00F4 )
  {
    if ( v3 > dword_7D00F8 )
      dword_7D00EC = dword_7D00F8;
  }
  else
  {
    dword_7D00EC = dword_7D00F4;
  }
  return result;
}
