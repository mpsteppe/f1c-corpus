_DWORD *__thiscall sub_5BFC10(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  this[2] = 1065353216;
  this[3] = 1065353216;
  *this = 1050253722;
  this[1] = 1050253722;
  this[4] = -1;
  this[6] = 0;
  this[7] = 6;
  *((_BYTE *)this + 33) = 1;
  *((_BYTE *)this + 32) = 0;
  *((_BYTE *)this + 34) = 0;
  this[5] = 0;
  return result;
}
