int __thiscall sub_4B4BC0(_DWORD *this)
{
  int v2; // eax
  char Destination[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = sub_4B2DE0();
  if ( v2 >= 0 )
  {
    if ( v2 )
    {
      sprintf(Destination, "%d", v2);
      return sub_5A3FF0(Destination, 49, 43, *(_DWORD *)(this[4] + 16), 0);
    }
    if ( sub_41F230(dword_62A170, aN, ::Destination) )
    {
      strncpy(::Destination, aN, 0x1FFu);
      byte_62A37B = 0;
    }
  }
  else if ( sub_41F230(dword_62A170, aR_0, ::Destination) )
  {
    strncpy(::Destination, aR_0, 0x1FFu);
    byte_62A37B = 0;
  }
  strncpy(Destination, ::Destination, 2u);
  Destination[2] = 0;
  return sub_5A3FF0(Destination, 49, 43, *(_DWORD *)(this[4] + 16), 0);
}
