int __stdcall sub_5539F0(void *a1)
{
  DoublyLinkedListNodeUnlinkByMatch(a1);
  if ( a1 )
  {
    ConditionalResourceCleanup_3310(a1);
    FreeWrapper_7bcf(a1);
  }
  return 0;
}

