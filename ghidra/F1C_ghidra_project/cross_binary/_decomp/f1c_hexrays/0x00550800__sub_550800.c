// f1c  0x00550800  size=16
_DWORD *__thiscall sub_550800(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *this = 0;
  this[1] = 0;
  return result;
}
