_DWORD *__thiscall sub_5C5540(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[4] = a2;
  this[1] = 13;
  this[2] = 2;
  *((_BYTE *)this + 12) = 0;
  *this = &off_72A018;
  return result;
}
