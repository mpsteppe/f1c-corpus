int __thiscall sub_5B8770(int *this)
{
  int result; // eax

  result = this[3];
  if ( result )
  {
    sub_5A7FD0(dword_7E6B48, this[3]);
    result = this[3];
    if ( result )
      result = sub_5BE8AE();
    this[3] = 0;
  }
  return result;
}
