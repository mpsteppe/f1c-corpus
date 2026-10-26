int __thiscall sub_4F1230(_DWORD *this)
{
  int result; // eax

  result = this[3];
  if ( (result & 8) == 0 )
  {
    result |= 8u;
    this[3] = result;
  }
  return result;
}
