char __thiscall sub_5A6EC0(_BYTE *this, char a2)
{
  char result; // al

  if ( a2 )
  {
    result = this[25] + 1;
    this[25] = result;
  }
  else
  {
    result = this[25];
    if ( result )
      this[25] = --result;
  }
  return result;
}
