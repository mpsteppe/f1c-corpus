_DWORD *__thiscall sub_4B1380(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  this[9] = 0;
  this[10] = -1;
  *this = &off_5EA2D4;
  this[4] = 0;
  this[3] = 0;
  this[2] = 0;
  this[1] = 0;
  this[8] = -1;
  this[6] = -1;
  this[7] = -1;
  this[5] = -1;
  *((_BYTE *)this + 44) = 0;
  return result;
}
