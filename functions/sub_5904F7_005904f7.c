int __stdcall sub_5904F7(LCID Locale, LCTYPE LCType, LPSTR lpLCData, int cchData)
{
  int v4; // esi
  int v5; // edi
  int v6; // eax
  unsigned int v7; // ecx
  char *v9; // eax

  v4 = 0;
  v5 = 26;
  while ( 1 )
  {
    v6 = (v5 + v4) / 2;
    v7 = dword_5E6D60[11 * v6];
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
      v9 = (char *)&unk_5E6D70 + 44 * v6;
      break;
    case 7u:
      v9 = (char *)&unk_5E6D78 + 44 * v6;
      break;
    case 0xBu:
      v9 = (char *)&unk_5E6D7C + 44 * v6;
      break;
    case 0x1001u:
      v9 = (&off_5E6D6C)[11 * v6];
      break;
    case 0x1002u:
      v9 = (&off_5E6D74)[11 * v6];
      break;
    case 0x1004u:
      v9 = &a1252[44 * v6];
      break;
    default:
      return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
  }
  if ( !v9 || cchData < 1 )
    return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
  sub_587DD0(lpLCData, v9, cchData - 1);
  lpLCData[cchData - 1] = 0;
  return 1;
}
