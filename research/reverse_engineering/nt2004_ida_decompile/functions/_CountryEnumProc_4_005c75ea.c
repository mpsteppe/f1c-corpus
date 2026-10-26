unsigned int __stdcall CountryEnumProc(LPSTR a1)
{
  int v1; // esi
  int v2; // eax
  char String2[120]; // [esp+4h] [ebp-78h] BYREF

  v1 = LcidFromHexString(a1);
  v2 = -(dword_7FF24C != 0);
  LOWORD(v2) = v2 & 0xF005;
  if ( dword_7FF268(v1, v2 + 4098, String2, 120) )
  {
    if ( !_strcmpi(dword_7FF25C, String2) )
    {
      if ( TestDefaultCountry(v1) )
      {
        dword_7FF260 |= 4u;
        dword_7FF264 = v1;
        Locale = v1;
      }
    }
    return ((unsigned int)~dword_7FF260 >> 2) & 1;
  }
  else
  {
    dword_7FF260 = 0;
    return 1;
  }
}
