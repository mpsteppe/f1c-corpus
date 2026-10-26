_DWORD *__thiscall sub_5C4FB0(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[4] = a2;
  this[1] = 3;
  this[2] = 3;
  *((_BYTE *)this + 12) = 0;
  *this = &off_729F18;
  return result;
}
