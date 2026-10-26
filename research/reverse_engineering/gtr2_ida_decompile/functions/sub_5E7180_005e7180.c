char __thiscall sub_5E7180(_DWORD *this, int a2, char a3)
{
  char result; // al

  result = a3;
  if ( (a3 & 1) != 0 )
  {
    result = a2;
    this[30] = a2;
  }
  else if ( (a3 & 2) != 0 )
  {
    this[31] = a2;
  }
  return result;
}
