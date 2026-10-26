_DWORD *__thiscall sub_502BEA(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  this[1] = 0;
  *this = 0;
  return result;
}
