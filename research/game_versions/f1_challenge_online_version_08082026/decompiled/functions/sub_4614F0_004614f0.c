char __thiscall sub_4614F0(_BYTE *this, char a2, char a3)
{
  char result; // al

  if ( a3 )
  {
    result = a2;
    this[136] |= a2;
  }
  else
  {
    result = ~a2 & this[136];
    this[136] = result;
  }
  return result;
}
