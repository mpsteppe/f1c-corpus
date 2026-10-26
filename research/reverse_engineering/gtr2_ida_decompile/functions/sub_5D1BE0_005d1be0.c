_DWORD *__thiscall sub_5D1BE0(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *result; // eax

  result = this;
  *this = a2;
  this[1] = a3;
  this[2] = a4;
  this[3] = a6;
  this[4] = a5;
  return result;
}
