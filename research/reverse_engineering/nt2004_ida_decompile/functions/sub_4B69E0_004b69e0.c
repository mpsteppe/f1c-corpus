int sub_4B69E0()
{
  float v1; // [esp+Ch] [ebp-44h]
  char Buffer[61]; // [esp+10h] [ebp-40h] BYREF
  __int16 v3; // [esp+4Dh] [ebp-3h]
  char v4; // [esp+4Fh] [ebp-1h]

  v1 = flt_609128 + 0.64999998;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x3Cu);
  v3 = 0;
  v4 = 0;
  sub_506960(0);
  sub_5072A0(aLapInformation, 0.5, 0, dword_60911C, 2, -1.0, -1.0, 0);
  if ( sub_41F230(dword_62A170, aLap, Destination) )
  {
    strncpy(Destination, aLap, 0x1FFu);
    byte_62A37B = 0;
  }
  sub_5072A0(Destination, 0.64999998, 1, -256, 1, -1.0, -1.0, 0);
  if ( dword_75CBB0 == 5 )
    sub_4B3BC0(Buffer, 64);
  else
    sub_4B3B40(Buffer, 64);
  sub_5072A0(Buffer, v1, 1, -1, 0, -1.0, -1.0, 0);
  if ( sub_41F230(dword_62A170, aCurrentLapTime, Destination) )
  {
    strncpy(Destination, aCurrentLapTime, 0x1FFu);
    byte_62A37B = 0;
  }
  sub_5072A0(Destination, 0.64999998, 2, -256, 1, -1.0, -1.0, 0);
  sub_4B30B0(Buffer, 64);
  sub_5072A0(Buffer, v1, 2, -1, 0, -1.0, -1.0, 0);
  if ( sub_41F230(dword_62A170, aLastLapTime, Destination) )
  {
    strncpy(Destination, aLastLapTime, 0x1FFu);
    byte_62A37B = 0;
  }
  sub_5072A0(Destination, 0.64999998, 3, -256, 1, -1.0, -1.0, 0);
  sub_4B3160(Buffer, 64);
  sub_5072A0(Buffer, v1, 3, -1, 0, -1.0, -1.0, 0);
  if ( sub_41F230(dword_62A170, aBestLapTime, Destination) )
  {
    strncpy(Destination, aBestLapTime, 0x1FFu);
    byte_62A37B = 0;
  }
  sub_5072A0(Destination, 0.64999998, 4, -256, 1, -1.0, -1.0, 0);
  sub_4B3270(Buffer, 64);
  return sub_5072A0(Buffer, v1, 4, -1, 0, -1.0, -1.0, 0);
}
