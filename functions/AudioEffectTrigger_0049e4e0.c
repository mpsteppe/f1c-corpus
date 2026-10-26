int __stdcall sub_49E4E0(int a1, int a2)
{
  int result; // eax

  result = dword_7C54E0;
  if ( *(_DWORD *)(dword_7C54E0 + 3984) )
    result = sub_5506A0(a1, a2, 0);
  if ( *(_DWORD *)(dword_7C54E0 + 3964) )
    return sub_5506A0(a1, a2, 0);
  return result;
}
