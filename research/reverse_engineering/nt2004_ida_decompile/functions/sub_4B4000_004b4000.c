int __stdcall sub_4B4000(char *Destination, int a2)
{
  int v2; // esi
  const char *v4; // [esp-8h] [ebp-10h]
  size_t v5; // [esp-4h] [ebp-Ch]

  if ( sub_4B2F70() )
  {
    if ( sub_41F230(dword_62A170, aCheckered, ::Destination) )
    {
      strncpy(::Destination, aCheckered, 0x1FFu);
      byte_62A37B = 0;
    }
    goto LABEL_4;
  }
  if ( sub_4B2FB0() )
  {
    if ( sub_41F230(dword_62A170, aBlack, ::Destination) )
    {
      strncpy(::Destination, aBlack, 0x1FFu);
      byte_62A37B = 0;
    }
    v2 = a2 - 1;
    v5 = a2 - 1;
    v4 = ::Destination;
    goto LABEL_22;
  }
  if ( sub_4B2FE0() )
  {
    if ( sub_41F230(dword_62A170, aBlue, ::Destination) )
    {
      strncpy(::Destination, aBlue, 0x1FFu);
      byte_62A37B = 0;
    }
    v2 = a2 - 1;
    v5 = a2 - 1;
    v4 = ::Destination;
    goto LABEL_22;
  }
  if ( sub_4B2FD0() )
  {
    if ( sub_41F230(dword_62A170, aYellow, ::Destination) )
    {
      strncpy(::Destination, aYellow, 0x1FFu);
      v2 = a2 - 1;
      v5 = a2 - 1;
      byte_62A37B = 0;
      v4 = ::Destination;
      goto LABEL_22;
    }
LABEL_4:
    v2 = a2 - 1;
    v5 = a2 - 1;
    v4 = ::Destination;
LABEL_22:
    strncpy(Destination, v4, v5);
    Destination[v2] = 0;
    return 0;
  }
  if ( sub_4B3000() )
  {
    if ( sub_41F230(dword_62A170, aWhite, ::Destination) )
      sub_431E20(::Destination, aWhite, 0x1FFu);
    v2 = a2 - 1;
    v5 = a2 - 1;
    v4 = ::Destination;
    goto LABEL_22;
  }
  if ( dword_75CBB4 < 5 )
  {
    v2 = a2 - 1;
    v5 = a2 - 1;
    v4 = &byte_629120;
    goto LABEL_22;
  }
  if ( sub_41F230(dword_62A170, aGreen, ::Destination) )
    sub_431E20(::Destination, aGreen, 0x1FFu);
  sub_431E20(Destination, ::Destination, a2 - 1);
  return 0;
}
