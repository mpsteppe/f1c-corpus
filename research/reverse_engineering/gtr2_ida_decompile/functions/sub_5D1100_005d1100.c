_DWORD *__thiscall sub_5D1100(_DWORD *this, int a2, int a3)
{
  _DWORD *result; // eax

  result = this;
  *this = a2;
  this[1] = a3;
  return result;
}
