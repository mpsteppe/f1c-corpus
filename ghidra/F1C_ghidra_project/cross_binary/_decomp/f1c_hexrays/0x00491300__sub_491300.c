// f1c  0x00491300  size=47
_WORD *__thiscall sub_491300(_WORD *this, __int16 a2, __int16 a3, __int16 a4, __int16 a5)
{
  _WORD *result; // eax

  result = this;
  *this = a2;
  this[1] = a3;
  this[2] = a4;
  this[3] = a5;
  *((_DWORD *)this + 3) = 0;
  return result;
}
