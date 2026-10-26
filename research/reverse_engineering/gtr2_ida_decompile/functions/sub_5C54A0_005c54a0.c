_DWORD *__thiscall sub_5C54A0(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[4] = a2;
  this[1] = 12;
  this[2] = 2;
  *((_BYTE *)this + 12) = 0;
  *this = &off_729FE8;
  return result;
}
