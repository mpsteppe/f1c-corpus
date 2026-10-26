_DWORD *__thiscall sub_57A080(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  this[1] = 0;
  this[2] = -1;
  *this = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  *((_BYTE *)this + 24) = 0;
  return result;
}
