char __thiscall sub_60C8A0(_DWORD *this, char a2)
{
  char result; // al

  this[1] &= 0xFFFFFFE3;
  result = a2;
  if ( (a2 & 0x1C) != 0 )
  {
    if ( (a2 & 4) != 0 )
      this[1] |= 4u;
    if ( (a2 & 8) != 0 )
      this[1] |= 8u;
    if ( (a2 & 0x10) != 0 )
      this[1] |= 0x10u;
  }
  return result;
}
