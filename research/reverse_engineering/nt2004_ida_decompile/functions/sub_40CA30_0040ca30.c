char __thiscall sub_40CA30(CHAR **this, _DWORD *ArgList)
{
  char result; // al
  CHAR *v4; // eax
  CHAR *v5; // eax
  CHAR *v6; // eax
  CHAR *v7; // eax
  CHAR *v8; // eax
  CHAR *v9; // eax
  CHAR *v10; // eax
  char v11; // [esp-Ch] [ebp-14h]
  char v12; // [esp-Ch] [ebp-14h]

  result = 0;
  if ( *ArgList )
  {
    sub_57A400((int)ArgList, aS_5, (char)aAwards);
    sub_57A400((int)ArgList, asc_5FC03C, v11);
    v4 = *this;
    if ( !*this )
      v4 = &byte_629120;
    sub_57A400((int)ArgList, aTrackS, (char)v4);
    v5 = this[2];
    if ( !v5 )
      v5 = &byte_629120;
    sub_57A400((int)ArgList, aPoleS, (char)v5);
    v6 = this[5];
    if ( !v6 )
      v6 = &byte_629120;
    sub_57A400((int)ArgList, aRacewinnerS, (char)v6);
    v7 = this[8];
    if ( !v7 )
      v7 = &byte_629120;
    sub_57A400((int)ArgList, aLedmostlapsS, (char)v7);
    v8 = this[11];
    if ( !v8 )
      v8 = &byte_629120;
    sub_57A400((int)ArgList, aBestlapS, (char)v8);
    v9 = this[14];
    if ( !v9 )
      v9 = &byte_629120;
    sub_57A400((int)ArgList, aBestrookieS, (char)v9);
    v10 = this[17];
    if ( !v10 )
      v10 = &byte_629120;
    sub_57A400((int)ArgList, aMostimprovemen_1, (char)v10);
    sub_57A400((int)ArgList, aPolebonusD, (char)this[4]);
    sub_57A400((int)ArgList, aRacewinnerbonu_0, (char)this[7]);
    sub_57A400((int)ArgList, aLedmostlapsbon_0, (char)this[10]);
    sub_57A400((int)ArgList, aBestlapbonusD, (char)this[13]);
    sub_57A400((int)ArgList, aBestrookiebonu_0, (char)this[16]);
    sub_57A400((int)ArgList, aMostimprovemen_2, (char)this[19]);
    sub_57A400((int)ArgList, asc_5FBF2C, v12);
    return 1;
  }
  return result;
}
