int __stdcall sub_4E8E50(char *a1, int a2, char *String1, char *Source)
{
  int v4; // eax
  int v5; // eax
  const char *v6; // eax
  int result; // eax
  char Destination[61]; // [esp+Ch] [ebp-40h] BYREF
  __int16 v9; // [esp+49h] [ebp-3h]
  char v10; // [esp+4Bh] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x3Cu);
  v9 = 0;
  v10 = 0;
  if ( Source )
  {
    strncpy(Destination, Source, 0x3Fu);
    goto LABEL_5;
  }
  v4 = dword_7D6B58 + 400 * dword_7D6B54;
  if ( v4 )
  {
    strncpy(Destination, (const char *)(v4 + 260), 0x3Fu);
LABEL_5:
    v10 = 0;
  }
  if ( sub_57AE50(aSeasonraces) && sub_57A720(Destination) && (v5 = sub_57A720(String1)) != 0 )
  {
    v6 = (const char *)sub_57A6D0(v5);
    strncpy(a1, v6, a2 - 1);
    result = 0;
    a1[a2 - 1] = 0;
  }
  else
  {
    strncpy(a1, Destination, a2 - 1);
    a1[a2 - 1] = 0;
    return 1;
  }
  return result;
}
