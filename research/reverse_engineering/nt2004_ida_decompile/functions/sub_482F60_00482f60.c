int sub_482F60()
{
  const char *v0; // esi
  char Buffer[32]; // [esp+8h] [ebp-20h] BYREF

  v0 = (const char *)sub_49D690(0);
  if ( sub_41F230(dword_62A170, v0, Destination) )
  {
    if ( v0 )
    {
      strncpy(Destination, v0, 0x1FFu);
      byte_62A37B = 0;
    }
    else
    {
      Destination[0] = 0;
    }
  }
  sprintf(Buffer, "%d %s", dword_768528, Destination);
  sub_4A1AC0(Buffer);
  return 0;
}
