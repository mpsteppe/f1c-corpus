int __stdcall sub_4D3FE0(int a1, char *Source)
{
  unsigned __int8 Buffer; // [esp+Bh] [ebp-81h] BYREF
  char Destination[125]; // [esp+Ch] [ebp-80h] BYREF
  __int16 v5; // [esp+89h] [ebp-3h]
  char v6; // [esp+8Bh] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x7Cu);
  v5 = 0;
  v6 = 0;
  strncpy(Destination, Source, 0x7Fu);
  v6 = 0;
  Buffer = strlen(Destination);
  sub_57A3A0(&Buffer, 1u);
  return sub_57A3A0(Destination, Buffer);
}
