_DWORD *__thiscall sub_5BFC50(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  *this = &off_729D40;
  this[1] = a2;
  *((_BYTE *)this + 8) = 1;
  return result;
}
