// f1c  0x004b2aa0  size=39
_DWORD *__thiscall sub_4B2AA0(_DWORD *this, char a2, char a3)
{
  _DWORD *result; // eax

  result = this;
  this[12] = ((a3 & 1) << a2) | this[12] & ~(1 << a2);
  return result;
}
