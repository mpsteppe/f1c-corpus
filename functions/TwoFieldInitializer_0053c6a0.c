_BYTE *__thiscall sub_53C6A0(_BYTE *this)
{
  _BYTE *result; // eax

  result = this;
  *(_DWORD *)this = 0;
  this[4] = 0;
  return result;
}
