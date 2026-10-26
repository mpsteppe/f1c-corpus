int sub_48A320()
{
  char Destination[61]; // [esp+Ch] [ebp-40h] BYREF
  __int16 v2; // [esp+49h] [ebp-3h]
  char v3; // [esp+4Bh] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x3Cu);
  v2 = 0;
  v3 = 0;
  if ( dword_7697F0 )
  {
    if ( dword_7697F0 == 1 )
    {
      strncpy(Destination, a24, 0x3Fu);
      goto LABEL_7;
    }
    if ( dword_7697F0 == 2 )
    {
      strncpy(Destination, a36, 0x3Fu);
      goto LABEL_7;
    }
    dword_7697F0 = 0;
    if ( dword_7697F8 <= 0 )
    {
      if ( dword_7697FC < 0 )
        dword_7697F0 = dword_7697FC;
    }
    else
    {
      dword_7697F0 = dword_7697F8;
    }
  }
  strncpy(Destination, a12, 0x3Fu);
LABEL_7:
  v3 = 0;
  sub_4A1AC0(Destination);
  return 0;
}
