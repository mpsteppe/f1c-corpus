char __thiscall sub_587230(_BYTE *this, char a2)
{
  char result; // al

  result = this[25];
  if ( a2 )
  {
    this[25] = ++result;
  }
  else if ( result )
  {
    this[25] = --result;
  }
  return result;
}
