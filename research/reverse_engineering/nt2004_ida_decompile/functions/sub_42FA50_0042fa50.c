char __thiscall sub_42FA50(_BYTE *this, char a2)
{
  char result; // al

  result = a2;
  this[16] = a2;
  if ( !a2 )
  {
    if ( sub_41F230(dword_62A170, aPaused, Destination) )
    {
      strncpy(Destination, aPaused, 0x1FFu);
      byte_62A37B = 0;
    }
    return sub_45D270(Destination, 0);
  }
  return result;
}
