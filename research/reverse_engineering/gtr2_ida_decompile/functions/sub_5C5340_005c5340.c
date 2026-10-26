_DWORD *__thiscall sub_5C5340(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[4] = a2;
  this[1] = 1;
  this[2] = 3;
  *((_BYTE *)this + 12) = 0;
  *this = &off_729FB0;
  return result;
}
