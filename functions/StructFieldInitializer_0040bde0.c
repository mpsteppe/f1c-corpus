_DWORD *__thiscall StructFieldInitializer(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 2;
  this[5] = -1;
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  *((_BYTE *)this + 44) = 0;
  *((_BYTE *)this + 36) = 0;
  this[10] = 0;
  *((_BYTE *)this + 37) = 0;
  *((_BYTE *)this + 45) = 0;
  *((_BYTE *)this + 46) = 0;
  return result;
}
