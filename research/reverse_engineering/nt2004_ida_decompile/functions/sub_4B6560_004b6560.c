int sub_4B6560()
{
  int v0; // eax
  int v1; // ebp
  char v2; // al
  float v4; // [esp+Ch] [ebp-44h]
  char Buffer[61]; // [esp+10h] [ebp-40h] BYREF
  __int16 v6; // [esp+4Dh] [ebp-3h]
  char v7; // [esp+4Fh] [ebp-1h]

  v4 = flt_609128 + 0.34999999;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x3Cu);
  v6 = 0;
  v7 = 0;
  sub_506960(0);
  sub_5072A0(aVehicleInforma, 0.5, 0, dword_60911C, 2, -1.0, -1.0, 0);
  if ( sub_41F230(dword_62A170, aPosition_1, Destination) )
  {
    strncpy(Destination, aPosition_1, 0x1FFu);
    byte_62A37B = 0;
  }
  sub_5072A0(Destination, 0.34999999, 1, -256, 1, -1.0, -1.0, 0);
  sub_4B3C90(Buffer, 64);
  sub_5072A0(Buffer, v4, 1, -1, 0, -1.0, -1.0, 0);
  if ( sub_41F230(dword_62A170, aSpeed_0, Destination) )
  {
    strncpy(Destination, aSpeed_0, 0x1FFu);
    byte_62A37B = 0;
  }
  sub_5072A0(Destination, 0.34999999, 2, -256, 1, -1.0, -1.0, 0);
  if ( sub_41F230(dword_62A170, off_5FE038, Destination) )
  {
    strncpy(Destination, off_5FE038, 0x1FFu);
    byte_62A37B = 0;
  }
  v0 = sub_4B2EB0();
  sprintf(Buffer, "%d %s", v0, Destination);
  sub_5072A0(Buffer, v4, 2, -1, 0, -1.0, -1.0, 0);
  v1 = -1;
  if ( sub_41F230(dword_62A170, aGear_0, Destination) )
  {
    strncpy(Destination, aGear_0, 0x1FFu);
    byte_62A37B = 0;
  }
  sub_5072A0(Destination, 0.34999999, 3, -256, 1, -1.0, -1.0, 0);
  v2 = sub_4B2DF0();
  sprintf(Buffer, "%c", v2);
  if ( sub_4B2D40() >= 3 )
    v1 = -65536;
  sub_5072A0(Buffer, v4, 3, v1, 0, -1.0, -1.0, 0);
  if ( sub_41F230(dword_62A170, aFuel, Destination) )
  {
    strncpy(Destination, aFuel, 0x1FFu);
    byte_62A37B = 0;
  }
  sub_5072A0(Destination, 0.34999999, 4, -256, 1, -1.0, -1.0, 0);
  sub_4B3D70(Buffer, 64);
  sub_5072A0(Buffer, v4, 4, -1, 0, -1.0, -1.0, 0);
  if ( sub_41F230(dword_62A170, aFlags, Destination) )
  {
    strncpy(Destination, aFlags, 0x1FFu);
    byte_62A37B = 0;
  }
  sub_5072A0(Destination, 0.34999999, 5, -256, 1, -1.0, -1.0, 0);
  sub_4B4000(Buffer, 64);
  return sub_5072A0(Buffer, v4, 5, -1, 0, -1.0, -1.0, 0);
}
