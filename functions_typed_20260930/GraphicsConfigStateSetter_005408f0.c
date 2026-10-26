int __thiscall sub_5408F0(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      this[1272] = 1;
      this[1271] = 1;
    }
    else if ( a2 == 2 )
    {
      this[1272] = 2;
      this[1271] = 1;
    }
  }
  else
  {
    this[1272] = 0;
    this[1271] = 0;
  }
  return result;
}

