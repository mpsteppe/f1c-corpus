char *__stdcall sub_473BE0(char *Destination, int a2)
{
  const char *v2; // eax
  size_t v3; // ebp
  const char *v4; // eax
  int v5; // ecx
  char *i; // eax
  int v7; // ecx
  char *j; // eax
  char *v9; // edx
  char *result; // eax
  char v11[2]; // [esp+2h] [ebp-282h] BYREF
  char Source[509]; // [esp+4h] [ebp-280h] BYREF
  __int16 v13; // [esp+201h] [ebp-83h]
  char v14; // [esp+203h] [ebp-81h]
  char v15[125]; // [esp+204h] [ebp-80h] BYREF
  __int16 v16; // [esp+281h] [ebp-3h]
  char v17; // [esp+283h] [ebp-1h]

  v2 = dword_7665D8;
  if ( !dword_7665D8 )
    v2 = &byte_629120;
  v3 = a2 - 1;
  strncpy(Destination, v2, a2 - 1);
  Destination[a2 - 1] = 0;
  Source[0] = byte_629120;
  memset(&Source[1], 0, 0x1FCu);
  v13 = 0;
  v14 = 0;
  v4 = dword_7665D8;
  if ( !dword_7665D8 )
    v4 = &byte_629120;
  strncpy(Source, v4, 0x1FFu);
  v14 = 0;
  v5 = strlen(Source);
  if ( v5 > 0 )
  {
    for ( i = &v11[v5 + 1]; i >= Source; *i-- = 0 )
    {
      if ( *i == 92 )
        break;
    }
  }
  if ( v11[strlen(Source) + 1] == 92 )
    v11[strlen(Source) + 1] = 0;
  v7 = strlen(Source);
  if ( v7 > 0 )
  {
    for ( j = &v11[v7 + 1]; j >= Source; *j-- = 0 )
    {
      if ( *j == 92 )
        break;
    }
  }
  if ( v11[strlen(Source) + 1] == 92 )
    v11[strlen(Source) + 1] = 0;
  v9 = &Source[strlen(Source)];
  if ( v9 > Source )
  {
    while ( *v9 != 92 )
    {
      if ( --v9 <= Source )
        goto LABEL_22;
    }
    ++v9;
  }
LABEL_22:
  if ( v9 )
  {
    v15[0] = byte_629120;
    memset(&v15[1], 0, 0x7Cu);
    v16 = 0;
    v17 = 0;
    strcpy(v15, v9);
    *(_WORD *)&Source[strlen(Source)] = *(_WORD *)word_5FB9F4;
    strcat(Source, v15);
    result = strncpy(Destination, Source, v3);
    Destination[v3] = 0;
  }
  else
  {
    strcpy(Destination, &byte_629120);
  }
  return result;
}
