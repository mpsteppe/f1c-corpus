_DWORD *__thiscall sub_5C5840(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[4] = a2;
  this[1] = 16;
  this[2] = 1;
  *((_BYTE *)this + 12) = 0;
  *this = &off_72A08C;
  return result;
}
