int __thiscall sub_454CD0(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( this[2] )
  {
    this[4] = a2;
    return result;
  }
  if ( a2 )
  {
    if ( !this[3] )
    {
      this[4] = a2;
      this[3] = 1;
      return result;
    }
  }
  else
  {
    this[3] = 0;
  }
  this[4] = 0;
  return result;
}
