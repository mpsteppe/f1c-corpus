_DWORD *__thiscall sub_5C5130(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[4] = a2;
  this[1] = 7;
  this[2] = 2;
  *((_BYTE *)this + 12) = 0;
  *this = &off_729F58;
  return result;
}
