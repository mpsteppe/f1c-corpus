int __thiscall sub_4C0AD0(_DWORD *this, char a2)
{
  int result; // eax

  result = 0;
  if ( a2 )
  {
    result = 2;
    if ( this[7] != 2 )
    {
      this[7] = 2;
      result = 1;
      this[8] = 1;
      this[9] = 1;
    }
  }
  else
  {
    this[7] = 1;
    this[8] = 0;
    this[9] = 0;
  }
  return result;
}
