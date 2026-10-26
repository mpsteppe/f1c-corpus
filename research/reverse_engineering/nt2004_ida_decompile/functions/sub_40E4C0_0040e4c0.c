char *__stdcall sub_40E4C0(int a1)
{
  char *v1; // esi
  int v2; // eax

  v1 = aLong;
  if ( a1 )
  {
    if ( a1 == 1 )
      v1 = aMedium;
  }
  else
  {
    v1 = aShort;
  }
  if ( sub_57AE50(aSeasontypes) && (v2 = sub_57A720(v1)) != 0 )
    return (char *)sub_57A6D0(v2);
  else
    return aCareerShortGdb;
}
