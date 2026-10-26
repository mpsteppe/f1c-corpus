bool __fastcall sub_40C4D0(char *Source, unsigned int a2)
{
  char *v3; // esi
  char *v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // eax
  bool result; // al
  char Destination[125]; // [esp+Ch] [ebp-80h] BYREF
  __int16 v9; // [esp+89h] [ebp-3h]
  char v10; // [esp+8Bh] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x7Cu);
  v9 = 0;
  v10 = 0;
  strncpy(Destination, Source, 0x7Fu);
  v10 = 0;
  v3 = strtok(Destination, word_5FBEB8);
  result = 0;
  if ( v3 )
  {
    v4 = strtok(0, word_5FBEB8);
    if ( v4 )
    {
      v5 = atoi(v3);
      v6 = atoi(v4);
      if ( a2 >= v5 && a2 <= v6 )
        return 1;
    }
  }
  return result;
}
