// f1c  0x0059a4c9  size=66
_DWORD *__thiscall sub_59A4C9(_DWORD *this)
{
  _DWORD *result; // eax

  this[7] = this + 5;
  this[8] = this + 6;
  this[11] = this + 9;
  this[3] = this + 1;
  this[12] = this + 10;
  this[4] = this + 2;
  this[2] = 0;
  *(_DWORD *)this[8] = 0;
  *(_DWORD *)this[12] = 0;
  *(_DWORD *)this[3] = 0;
  *(_DWORD *)this[7] = 0;
  result = (_DWORD *)this[11];
  *result = 0;
  return result;
}
