// f1c  0x0042e1c0  size=35
_DWORD *__thiscall sub_42E1C0(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  *((_BYTE *)this + 28) = 1;
  *((_BYTE *)this + 29) = 0;
  *((_BYTE *)this + 30) = 0;
  return result;
}
