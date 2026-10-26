int __thiscall sub_4D8880(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 == -1 )
  {
    this[2] = -1;
  }
  else if ( this[a2 + 3] )
  {
    if ( dword_7CF788 )
      this[2] = a2;
  }
  return result;
}

