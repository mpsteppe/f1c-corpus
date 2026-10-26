int __thiscall sub_5F6540(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int result; // eax

  result = a2;
  this[96] = a3;
  this[98] = a2;
  this[97] = a4;
  if ( a2 == 4096 )
  {
    result = a5;
    this[99] = a5;
  }
  return result;
}
