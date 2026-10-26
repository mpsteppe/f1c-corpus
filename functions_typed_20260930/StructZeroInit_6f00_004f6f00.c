_DWORD *__thiscall StructZeroInit_6f00(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *(_BYTE *)this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  *((_BYTE *)this + 16) = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  return result;
}

