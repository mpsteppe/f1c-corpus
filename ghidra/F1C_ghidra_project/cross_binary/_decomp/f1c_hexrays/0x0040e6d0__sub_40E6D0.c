// f1c  0x0040e6d0  size=49
_DWORD *__thiscall sub_40E6D0(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *this = -1;
  this[1] = 0x7FFFFFFF;
  *((_WORD *)this + 4) = -1;
  *((_BYTE *)this + 10) = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 9;
  this[8] = 0;
  return result;
}
