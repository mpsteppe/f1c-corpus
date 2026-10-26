_DWORD *__thiscall sub_4E33A0(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *this = 0;
  this[1] = -1;
  this[2] = 0;
  this[4] = 0;
  this[3] = 0;
  this[6] = 0;
  this[5] = 0;
  *((_BYTE *)this + 28) = 1;
  this[8] = 8;
  *((_BYTE *)this + 36) = 0;
  this[10] = 0;
  return result;
}
