int __stdcall crtGetLocaleInfoA(LCID Locale, LCTYPE LCType, LPSTR lpLCData, int cchData)
{
  int v4; // esi
  int v5; // edi
  int v6; // eax
  unsigned int v7; // ecx
  const char *v9; // eax

  v4 = 0;
  v5 = 26;
  while ( 1 )
  {
    v6 = (v5 + v4) / 2;
    v7 = dword_625A30[11 * v6];
    if ( Locale == v7 )
      break;
    if ( Locale >= v7 )
      v4 = v6 + 1;
    else
      v5 = v6 - 1;
    if ( v4 > v5 )
      return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
  }
  switch ( LCType )
  {
    case 1u:
      v9 = &a040a[44 * v6];
      break;
    case 3u:
      v9 = (const char *)(&off_625A40 + 11 * v6);
      break;
    case 7u:
      v9 = (const char *)(&off_625A48 + 11 * v6);
      break;
    case 0xBu:
      v9 = (char *)&unk_625A4C + 44 * v6;
      break;
    case 0x1001u:
      v9 = (&off_625A3C)[11 * v6];
      break;
    case 0x1002u:
      v9 = (&off_625A44)[11 * v6];
      break;
    case 0x1004u:
      v9 = &a1252[44 * v6];
      break;
    default:
      return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
  }
  if ( !v9 || cchData < 1 )
    return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
  strncpy(lpLCData, v9, cchData - 1);
  lpLCData[cchData - 1] = 0;
  return 1;
}
