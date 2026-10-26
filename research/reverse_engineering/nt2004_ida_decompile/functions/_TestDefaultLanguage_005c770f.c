BOOL __cdecl TestDefaultLanguage(int a1, int a2)
{
  int v2; // eax
  int PrimaryLen; // esi
  BOOL result; // eax
  _BYTE v5[120]; // [esp+0h] [ebp-78h] BYREF

  v2 = a1 & 0x3FF;
  BYTE1(v2) |= 4u;
  result = 0;
  if ( dword_7FF268(v2, 1, v5, 120) )
  {
    if ( a1 == LcidFromHexString(v5) )
      return 1;
    if ( !a2 )
      return 1;
    PrimaryLen = GetPrimaryLen(dword_7FF258);
    if ( PrimaryLen != strlen(dword_7FF258) )
      return 1;
  }
  return result;
}
