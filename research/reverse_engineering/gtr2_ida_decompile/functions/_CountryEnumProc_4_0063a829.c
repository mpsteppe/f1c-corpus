BOOL __thiscall CountryEnumProc(void *this, LPSTR a2)
{
  int v2; // esi
  char String2[120]; // [esp+4h] [ebp-7Ch] BYREF
  int v5; // [esp+7Ch] [ebp-4h]

  v5 = dword_912B08;
  v2 = LcidFromHexString((int)this, a2);
  if ( dword_FB83D8(v2, dword_FB83C8 != 0 ? 7 : 4098, String2, 120) )
  {
    if ( !_stricmp(dword_FB83CC, String2) )
    {
      if ( TestDefaultCountry(v2) )
      {
        dword_FB83B8 |= 4u;
        dword_FB83C0 = v2;
        Locale = v2;
      }
    }
    return (dword_FB83B8 & 4) == 0;
  }
  else
  {
    dword_FB83B8 = 0;
    return 1;
  }
}
