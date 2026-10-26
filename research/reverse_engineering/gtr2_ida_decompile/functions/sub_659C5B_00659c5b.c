_DWORD *__thiscall sub_659C5B(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *result; // eax

  result = this;
  this[3] = 0;
  this[4] = 0;
  *this = a2;
  this[1] = a3;
  this[2] = a4;
  return result;
}
