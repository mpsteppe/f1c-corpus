int __cdecl __ansicp(LCID Locale)
{
  CHAR LCData[8]; // [esp+0h] [ebp-Ch] BYREF
  int v3; // [esp+8h] [ebp-4h]

  v3 = dword_912B08;
  LCData[6] = 0;
  if ( GetLocaleInfoA(Locale, 0x1004u, LCData, 6) )
    return atol(LCData);
  else
    return -1;
}
