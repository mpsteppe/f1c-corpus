int __stdcall sub_4C0260(_BYTE *a1)
{
  _DWORD *v1; // eax
  int v2; // esi
  _DWORD *v3; // eax
  char *v4; // eax

  if ( !a1 )
    return 104;
  v1 = (_DWORD *)SeasonRacesSectionFinder(0);
  if ( !v1 || !StringKeyedLinkedListSearch(v1, (int)aQualifying) )
    return 104;
  v2 = 0;
  while ( 1 )
  {
    v3 = (_DWORD *)NullCheckWrapper(v2);
    if ( v3 )
    {
      v4 = StringPointerAccessor(v3);
      if ( !sub_588410(a1, v4) )
        break;
    }
    if ( ++v2 >= 104 )
      return 104;
  }
  return v2 + 1;
}

