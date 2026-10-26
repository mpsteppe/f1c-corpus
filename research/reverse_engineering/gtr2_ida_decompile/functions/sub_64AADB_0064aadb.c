_DWORD *__thiscall sub_64AADB(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  this[1] = 0;
  *this = 0;
  return result;
}
