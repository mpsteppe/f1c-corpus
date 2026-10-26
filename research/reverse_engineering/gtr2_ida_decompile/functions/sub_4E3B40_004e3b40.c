_DWORD *__thiscall sub_4E3B40(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  this[1] = 0;
  this[2] = -1;
  this[3] = 0;
  this[4] = -1;
  *this = 0;
  this[6] = 0;
  this[5] = 0;
  return result;
}
