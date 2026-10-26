_DWORD *__thiscall sub_5C55D0(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[4] = a2;
  this[1] = 15;
  this[2] = 1;
  *((_BYTE *)this + 12) = 0;
  *this = &off_72A030;
  return result;
}
