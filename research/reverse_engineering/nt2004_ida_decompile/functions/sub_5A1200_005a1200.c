int __thiscall sub_5A1200(_DWORD *this)
{
  int result; // eax

  result = this[120];
  if ( result )
  {
    sub_5BE8AE();
    result = sub_5BE8AE();
    this[120] = 0;
  }
  return result;
}
