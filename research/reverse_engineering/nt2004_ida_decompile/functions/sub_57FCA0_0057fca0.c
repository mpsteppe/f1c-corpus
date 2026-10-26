int __thiscall sub_57FCA0(_DWORD *this)
{
  int result; // eax

  if ( *this )
  {
    sub_5BE8AE();
    *this = 0;
  }
  if ( this[1] )
  {
    sub_5BE8AE();
    this[1] = 0;
  }
  if ( this[2] )
  {
    sub_5BE8AE();
    this[2] = 0;
  }
  result = this[3];
  if ( result )
  {
    result = sub_5BE8AE();
    this[3] = 0;
  }
  return result;
}
