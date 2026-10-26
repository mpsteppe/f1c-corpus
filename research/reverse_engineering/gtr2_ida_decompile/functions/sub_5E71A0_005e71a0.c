char __thiscall sub_5E71A0(_DWORD *this, int a2, char a3)
{
  char result; // al

  result = a3;
  if ( (a3 & 4) != 0 )
  {
    result = a2;
    this[32] = a2;
  }
  else if ( (a3 & 8) != 0 )
  {
    this[33] = a2;
  }
  return result;
}
