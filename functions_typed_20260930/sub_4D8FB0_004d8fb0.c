int sub_4D8FB0()
{
  int result; // eax

  if ( dword_8AD388 )
  {
    StringCompareLinkedListSearch(dword_8AD388);
    dword_8AD388 = 0;
  }
  if ( dword_8AD38C )
  {
    StringCompareLinkedListSearch(dword_8AD38C);
    dword_8AD38C = 0;
  }
  if ( dword_8AD390 )
  {
    StringCompareLinkedListSearch(dword_8AD390);
    dword_8AD390 = 0;
  }
  result = dword_8AD394;
  if ( dword_8AD394 )
  {
    result = StringCompareLinkedListSearch(dword_8AD394);
    dword_8AD394 = 0;
  }
  return result;
}

