_DWORD *__thiscall sub_45D550(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  *(_BYTE *)this = 0;
  *((_BYTE *)this + 1) = 0;
  return result;
}
