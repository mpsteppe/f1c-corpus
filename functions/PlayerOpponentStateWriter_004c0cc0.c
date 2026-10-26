char __thiscall sub_4C0CC0(int this, _DWORD *a2, int a3)
{
  int i; // ebx
  _BYTE v6[32]; // [esp+8h] [ebp-20h] BYREF

  if ( *a2 )
  {
    if ( a3 )
    {
      ResourceLookupWithDualPath(a3);
      ResourceLookupWithDualPath(&word_5C30B4);
    }
    BufferWriteWithStringLengthCheck(a2, aSeasonstatusD);
    BufferWriteWithStringLengthCheck(a2, aRacesessionD);
    BufferWriteWithStringLengthCheck(a2, aRaceoverD);
    BufferWriteWithStringLengthCheck(a2, aCurrentraceD);
    SettingsIniFileWriter((int *)(this + 44908), a2, (int)aPlayer);
    for ( i = 0; i < 103; ++i )
    {
      if ( *(_BYTE *)(this + 432) )
      {
        StringFormatWithBufferOverflowCheck(v6, "%s%2.2d]", aOpponent, i);
        SettingsIniFileWriter((int *)this, a2, (int)v6);
      }
      this += 436;
    }
    BufferWriteWithStringLengthCheck(a2, &word_5C30B4);
  }
  return 0;
}
