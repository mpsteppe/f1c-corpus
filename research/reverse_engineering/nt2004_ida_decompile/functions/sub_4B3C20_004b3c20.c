int __stdcall sub_4B3C20(char *Destination, int a2)
{
  const char *v2; // esi

  v2 = off_6090D4;
  if ( sub_41F230(dword_62A170, off_6090D4, ::Destination) )
  {
    if ( v2 )
    {
      strncpy(::Destination, v2, 0x1FFu);
      byte_62A37B = 0;
    }
    else
    {
      ::Destination[0] = 0;
    }
  }
  strncpy(Destination, ::Destination, a2 - 1);
  Destination[a2 - 1] = 0;
  return 0;
}
