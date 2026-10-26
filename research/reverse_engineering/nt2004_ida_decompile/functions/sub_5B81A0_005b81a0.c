int __thiscall sub_5B81A0(_DWORD *this)
{
  int result; // eax

  result = this[111];
  if ( result )
  {
    result = sub_5BE8AE();
    this[111] = 0;
  }
  return result;
}
