int __thiscall sub_595B70(_DWORD *this, int a2)
{
  int result; // eax

  if ( a2 == 0x20000 )
  {
    result = this[60] | 0x10000;
    this[107] = 0x20000;
    this[60] = result;
  }
  else if ( a2 == 0x40000 )
  {
    result = this[60] | 0x10000;
    this[107] = 0x40000;
    this[60] = result;
  }
  else
  {
    result = this[60] | 0x10000;
    if ( a2 == 0x80000 )
      this[107] = 0x80000;
    else
      this[107] = 0;
    this[60] = result;
  }
  return result;
}
