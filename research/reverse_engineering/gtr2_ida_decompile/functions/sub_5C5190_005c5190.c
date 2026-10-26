_DWORD *__thiscall sub_5C5190(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[4] = a2;
  this[1] = 9;
  this[2] = 1;
  *((_BYTE *)this + 12) = 0;
  *this = &off_729F68;
  return result;
}
