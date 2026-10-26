double __stdcall sub_4C02D0(_BYTE *a1)
{
  _DWORD *v1; // eax
  int v2; // edi
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  char *v5; // eax
  double result; // st7
  unsigned __int8 *v7; // eax

  if ( !a1 )
    return -1.0;
  v1 = (_DWORD *)SeasonRacesSectionFinder(0);
  if ( !v1 || !StringKeyedLinkedListSearch(v1, (int)aQualifying) )
    return -1.0;
  v2 = 0;
  while ( 1 )
  {
    v3 = (_DWORD *)NullCheckWrapper(v2);
    v4 = v3;
    if ( v3 )
    {
      v5 = StringPointerAccessor(v3);
      if ( !sub_588410(a1, v5) )
        break;
    }
    if ( ++v2 >= 104 )
      return -1.0;
  }
  v7 = (unsigned __int8 *)DataEntryAccessor(v4);
  result = sub_58850F(v7);
  if ( result < 10.0 )
    return -1.0;
  return result;
}
