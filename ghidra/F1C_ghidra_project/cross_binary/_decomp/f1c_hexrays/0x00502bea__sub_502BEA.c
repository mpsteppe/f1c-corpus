// f1c  0x00502bea  size=10
_DWORD *__thiscall sub_502BEA(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  this[1] = 0;
  *this = 0;
  return result;
}
