int __thiscall sub_407820(int *this)
{
  int result; // eax

  result = this[23];
  if ( result != -1 )
  {
    result = _close(this[23]);
    this[23] = -1;
  }
  return result;
}
