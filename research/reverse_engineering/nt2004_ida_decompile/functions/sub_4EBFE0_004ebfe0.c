_DWORD *__thiscall sub_4EBFE0(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *this = 0;
  this[1] = -1;
  this[2] = 0;
  this[3] = 0;
  this[4] = -1;
  this[5] = -1;
  *((_WORD *)this + 12) = 0;
  this[7] = 0;
  this[8] = -1;
  *((_WORD *)this + 18) = -1;
  this[10] = 0;
  return result;
}
