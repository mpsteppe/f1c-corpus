_DWORD *__thiscall sub_5C50A0(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[4] = a2;
  this[1] = 2;
  this[2] = 1;
  *((_BYTE *)this + 12) = 0;
  *this = &off_729F40;
  return result;
}
