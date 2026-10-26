int __stdcall sub_4E9480(char *Source)
{
  char *v1; // eax
  char *v2; // edi
  char v3; // cl
  int v4; // eax
  char Destination[509]; // [esp+0h] [ebp-200h] BYREF
  __int16 v7; // [esp+1FDh] [ebp-3h]
  char v8; // [esp+1FFh] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x1FCu);
  v7 = 0;
  v8 = 0;
  strncpy(Destination, Source, 0x1FFu);
  v8 = 0;
  v1 = &Destination[strlen(Destination)];
  if ( v1 > Destination )
  {
    while ( *v1 != 46 )
    {
      if ( --v1 <= Destination )
        goto LABEL_6;
    }
    *v1 = 0;
  }
LABEL_6:
  v2 = &Destination[strlen(Destination) + 1];
  v3 = byte_5FFC78;
  *(_DWORD *)--v2 = dword_5FFC74;
  v2[4] = v3;
  v4 = sub_57AE50(aSeasonraces);
  if ( !v4 )
    v4 = sub_57ACC0(aSeasonraces, 0, 0, 0);
  return sub_57AC50(Destination, v4);
}
