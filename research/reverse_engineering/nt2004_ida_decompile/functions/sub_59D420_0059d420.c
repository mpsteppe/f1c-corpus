int __thiscall sub_59D420(_DWORD *this)
{
  int result; // eax

  result = this[81];
  if ( result )
  {
    result = sub_5BE8AE();
    this[81] = 0;
  }
  return result;
}
