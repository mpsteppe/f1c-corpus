int sub_504CB0()
{
  int v0; // eax
  float v2; // [esp+Ch] [ebp-28h]
  float v3; // [esp+10h] [ebp-24h]
  char Buffer[29]; // [esp+14h] [ebp-20h] BYREF
  __int16 v5; // [esp+31h] [ebp-3h]
  char v6; // [esp+33h] [ebp-1h]

  sub_506960(0);
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x1Cu);
  v3 = (double)dword_6152E8 * 0.00078125001;
  v5 = 0;
  v2 = (double)dword_6152EC * 0.0009765625;
  v6 = 0;
  v0 = sub_4B2EB0();
  sprintf(Buffer, "%d", v0);
  sub_5070D0(Buffer, 0.5, 0.5, 0xFFFFFF, 7, v3, v2, 0, 0);
  if ( sub_41F230(dword_62A170, off_5FE038, Destination) )
  {
    strncpy(Destination, off_5FE038, 0x1FFu);
    byte_62A37B = 0;
  }
  sprintf(Buffer, off_5FD810, Destination);
  return sub_5070D0(Buffer, 0.5, 0.5, 0xFFFFFF, 6, v3, v2, 0, 0);
}
