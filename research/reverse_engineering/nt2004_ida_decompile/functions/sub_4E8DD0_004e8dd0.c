int __stdcall sub_4E8DD0(char *String2)
{
  int v1; // ebx
  int i; // edi
  int v3; // esi
  char String1[80]; // [esp+10h] [ebp-50h] BYREF

  v1 = 0;
  if ( dword_7D6B50 <= 0 )
    return 0;
  for ( i = 0; ; i += 400 )
  {
    v3 = i + dword_7D6B58;
    String1[0] = 0;
    if ( !sub_4E8E50(String1, 80, aEventname, (char *)(i + dword_7D6B58 + 260)) && !_strcmpi(String1, String2) )
      break;
    if ( ++v1 >= dword_7D6B50 )
      return 0;
  }
  return v3;
}
