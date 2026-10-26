// f1c  0x004b1990  size=26
_DWORD *__thiscall sub_4B1990(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  this[1] = 0;
  this[2] = -1;
  this[3] = 0;
  this[4] = -1;
  *this = &off_5ACBCC;
  return result;
}
