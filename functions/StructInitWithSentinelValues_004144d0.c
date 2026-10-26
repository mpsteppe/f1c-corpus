int __thiscall StructInitWithSentinelValues(_DWORD *this)
{
  int result; // eax

  result = -1;
  *this = -1;
  this[2] = -1082130432;
  this[3] = 0;
  this[4] = -1;
  this[5] = -1;
  this[6] = -1;
  this[7] = -1;
  return result;
}
