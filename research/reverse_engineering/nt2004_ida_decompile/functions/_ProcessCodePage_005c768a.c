int __cdecl ProcessCodePage(char *String)
{
  const char *v1; // esi
  int result; // eax
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  v1 = String;
  if ( String && *String && strcmp(String, off_5F6E64) )
  {
    if ( strcmp(String, off_5F6E60) )
      return atol(v1);
    result = dword_7FF268(dword_7FF264, 11, v3, 8);
  }
  else
  {
    result = dword_7FF268(dword_7FF264, 4100, v3, 8);
  }
  if ( !result )
    return result;
  v1 = v3;
  return atol(v1);
}
