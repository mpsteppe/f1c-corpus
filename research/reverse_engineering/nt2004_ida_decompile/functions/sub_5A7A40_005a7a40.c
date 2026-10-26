int __thiscall sub_5A7A40(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      this[1297] = 1;
      this[1296] = 1;
    }
    else if ( a2 == 2 )
    {
      this[1297] = 2;
      this[1296] = 1;
    }
  }
  else
  {
    this[1297] = 0;
    this[1296] = 0;
  }
  return result;
}
