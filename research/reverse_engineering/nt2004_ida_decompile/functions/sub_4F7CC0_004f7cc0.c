int __thiscall sub_4F7CC0(_DWORD *this)
{
  int result; // eax

  for ( result = 0; result < 48; ++result )
  {
    this[2 * result] = -2;
    this[2 * result + 1] = -1082130432;
  }
  this[96] = 0;
  return result;
}
