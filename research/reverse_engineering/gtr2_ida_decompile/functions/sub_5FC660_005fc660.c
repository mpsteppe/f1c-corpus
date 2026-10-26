_BYTE *__thiscall sub_5FC660(_BYTE *this)
{
  _BYTE *result; // eax

  result = this;
  *(_DWORD *)this = 0;
  this[4] = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 12) = 1065353216;
  *((_DWORD *)this + 11) = 1065353216;
  *((_DWORD *)this + 10) = 1065353216;
  *((_DWORD *)this + 13) = 1120403456;
  *((_DWORD *)this + 78) = 0;
  *((_DWORD *)this + 79) = 0;
  *((_DWORD *)this + 82) = 65538;
  *((_DWORD *)this + 83) = 0;
  *((_DWORD *)this + 84) = 3;
  *((_DWORD *)this + 80) = -1;
  *((_DWORD *)this + 81) = -16777216;
  this[340] = 0;
  this[372] = 0;
  this[404] = 0;
  return result;
}
