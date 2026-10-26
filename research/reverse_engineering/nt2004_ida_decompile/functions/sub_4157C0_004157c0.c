_DWORD *__thiscall sub_4157C0(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *this = -1;
  this[1] = 0x7FFFFFFF;
  *((_WORD *)this + 4) = -1;
  this[3] = 1;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[8] = 9;
  this[9] = 0;
  return result;
}
