_DWORD *__thiscall sub_5413B0(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  *((_BYTE *)this + 16) = 0;
  this[5] = 0;
  this[6] = 1120403456;
  *((_BYTE *)this + 28) = 0;
  return result;
}
