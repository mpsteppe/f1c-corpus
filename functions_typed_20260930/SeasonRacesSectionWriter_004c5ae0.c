int __stdcall sub_4C5AE0(int a1)
{
  char *v1; // eax
  char *v2; // edi
  char v3; // cl
  int v4; // eax
  char v6[509]; // [esp+0h] [ebp-200h] BYREF
  __int16 v7; // [esp+1FDh] [ebp-3h]
  char v8; // [esp+1FFh] [ebp-1h]

  v6[0] = byte_5EA438[0];
  memset(&v6[1], 0, 0x1FCu);
  v7 = 0;
  v8 = 0;
  sub_587DD0(v6, a1, 511);
  v8 = 0;
  v1 = &v6[strlen(v6)];
  if ( v1 > v6 )
  {
    while ( *v1 != 46 )
    {
      if ( --v1 <= v6 )
        goto LABEL_6;
    }
    *v1 = 0;
  }
LABEL_6:
  v2 = &v6[strlen(v6) + 1];
  v3 = byte_5C5D28;
  *(_DWORD *)--v2 = dword_5C5D24;
  v2[4] = v3;
  v4 = AudioChannelStop(aSeasonraces);
  if ( !v4 )
    v4 = FileDataProcessor(aSeasonraces, 0, 0, 0);
  return AudioFileLoadDecode(v6, v4);
}

