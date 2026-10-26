int __stdcall sub_4E9550(char *Source, char a2, int a3)
{
  char *v3; // eax
  char *v4; // edi
  char v5; // cl
  int v7; // [esp+4h] [ebp-204h] BYREF
  char Destination[509]; // [esp+8h] [ebp-200h] BYREF
  __int16 v9; // [esp+205h] [ebp-3h]
  char v10; // [esp+207h] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x1FCu);
  v9 = 0;
  v10 = 0;
  strncpy(Destination, Source, 0x1FFu);
  v10 = 0;
  v3 = &Destination[strlen(Destination)];
  if ( v3 > Destination )
  {
    while ( *v3 != 46 )
    {
      if ( --v3 <= Destination )
        goto LABEL_6;
    }
    *v3 = 0;
  }
LABEL_6:
  v4 = &Destination[strlen(Destination) + 1];
  v5 = byte_5FFC78;
  *(_DWORD *)--v4 = dword_5FFC74;
  v4[4] = v5;
  if ( (unsigned __int8)sub_57B490(Destination, a3, (int)&v7) == 1 )
    return v7;
  else
    return -1;
}
