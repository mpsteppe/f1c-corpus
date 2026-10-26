_DWORD *__thiscall sub_5AF210(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *(_BYTE *)this = 0;
  this[8] = 0;
  this[9] = 0;
  this[10] = 1065353216;
  this[11] = 1065353216;
  this[12] = 1065353216;
  this[13] = 1120403456;
  this[22] = 0;
  this[23] = 0;
  this[25] = 65538;
  this[26] = 0;
  this[27] = 3;
  this[24] = 0xFFFFFF;
  *((_BYTE *)this + 112) = 0;
  *((_BYTE *)this + 144) = 0;
  return result;
}
