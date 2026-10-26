_DWORD *__thiscall sub_5C52E0(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[4] = a2;
  this[1] = 0;
  this[2] = 3;
  *((_BYTE *)this + 12) = 0;
  *this = &off_729FA0;
  return result;
}
