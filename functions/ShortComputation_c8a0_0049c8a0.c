int __stdcall sub_49C8A0(int a1, int a2)
{
  int v2; // eax

  v2 = ChampionshipScoreThresholdSearch(dword_7C54E0 + 13004);
  if ( v2 > 0 )
    StringFormatWithBufferOverflowCheck(a1, "%d", v2);
  else
    StringFormatWithBufferOverflowCheck(a1, &word_5C694C);
  return 0;
}
