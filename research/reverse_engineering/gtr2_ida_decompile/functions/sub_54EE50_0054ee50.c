int __thiscall sub_54EE50(_DWORD *this)
{
  int result; // eax

  for ( result = 0; result < 104; ++result )
  {
    this[2 * result] = -2;
    this[2 * result + 1] = -1082130432;
  }
  this[208] = 0;
  return result;
}
