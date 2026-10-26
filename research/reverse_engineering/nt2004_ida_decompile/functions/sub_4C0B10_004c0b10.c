int __thiscall sub_4C0B10(_DWORD *this, char a2)
{
  int result; // eax

  result = 0;
  if ( a2 )
  {
    result = 2;
    if ( this[55] != 2 )
    {
      this[55] = 2;
      result = 1;
      this[56] = 1;
      this[57] = 1;
    }
  }
  else
  {
    this[55] = 1;
    this[56] = 0;
    this[57] = 0;
  }
  return result;
}
