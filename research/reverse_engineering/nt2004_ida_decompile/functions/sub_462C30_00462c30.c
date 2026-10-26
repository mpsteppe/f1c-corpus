char __thiscall sub_462C30(_BYTE *this, char a2, char a3)
{
  char result; // al

  if ( a3 )
  {
    result = a2;
    this[112] |= a2;
  }
  else
  {
    result = ~a2 & this[112];
    this[112] = result;
  }
  return result;
}
