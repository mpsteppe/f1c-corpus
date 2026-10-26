_DWORD *__thiscall sub_5D1B50(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  *this = &off_72B3F8;
  this[1] = a2;
  *((_BYTE *)this + 8) = 1;
  return result;
}
