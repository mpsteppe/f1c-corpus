// bad sp value at call has been detected, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
int __usercall sub_47E3F4@<eax>(char a1@<bl>, int a2@<ebp>)
{
  int v2; // eax
  int v3; // eax
  int v5; // [esp-8h] [ebp-8h]

  *(_BYTE *)(a2 + 95) += a1;
  (*(void (**)(void))(v5 - 117))();
  __asm { icebp }
  if ( SeasonRacesSectionFinder(0) )
  {
    v2 = StringKeyedLinkedListSearch(aRacelaps);
    if ( v2 )
    {
      v3 = DataEntryAccessor(v2);
      UIStringComparison(v3);
    }
  }
  return 0;
}
