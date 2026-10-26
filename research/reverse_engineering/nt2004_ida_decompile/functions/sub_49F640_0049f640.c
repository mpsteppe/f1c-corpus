int __stdcall sub_49F640(const char *a1)
{
  if ( !a1 )
    return -1;
  *(_WORD *)&a1[strlen(a1)] = *(_WORD *)word_6014F0;
  return 0;
}
