void __fastcall sub_40C5C0(const char *a1, char *a2, char *Source, unsigned __int16 a4)
{
  char *i; // edi
  char Delimiter[2]; // [esp+Ah] [ebp-40Ah] BYREF
  unsigned int v7; // [esp+Ch] [ebp-408h]
  char *v8; // [esp+10h] [ebp-404h]
  char Destination[509]; // [esp+14h] [ebp-400h] BYREF
  __int16 v10; // [esp+211h] [ebp-203h]
  char v11; // [esp+213h] [ebp-201h]
  char v12[509]; // [esp+214h] [ebp-200h] BYREF
  __int16 v13; // [esp+411h] [ebp-3h]
  char v14; // [esp+413h] [ebp-1h]

  v8 = a2;
  if ( a1 && a2 && Source )
  {
    Destination[0] = byte_629120;
    memset(&Destination[1], 0, 0x1FCu);
    v10 = 0;
    v11 = 0;
    v12[0] = byte_629120;
    memset(&v12[1], 0, 0x1FCu);
    v13 = 0;
    v14 = 0;
    strcpy(Delimiter, " ");
    strncpy(Destination, Source, 0x1FFu);
    v11 = 0;
    for ( i = strtok(Destination, Delimiter); i; i = strtok(0, Delimiter) )
    {
      if ( !strcmp(i, a1) )
        i = v8;
      v7 = strlen(i) + 1;
      qmemcpy(&v12[strlen(v12)], i, v7);
      *(_WORD *)&v12[strlen(v12)] = *(_WORD *)word_5FBEBC;
    }
    strncpy(Source, v12, a4 - 1);
    Source[a4 - 1] = 0;
  }
}
