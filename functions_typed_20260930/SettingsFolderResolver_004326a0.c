int __thiscall sub_4326A0(void *this)
{
  int v2; // eax

  if ( SeasonRacesSectionFinder(this) && (v2 = StringKeyedLinkedListSearch(off_5C3FA4[0])) != 0 )
    return DataEntryAccessor(v2);
  else
    return (int)this;
}

