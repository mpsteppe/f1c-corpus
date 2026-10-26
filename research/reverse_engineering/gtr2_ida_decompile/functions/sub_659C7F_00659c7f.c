_DWORD *__thiscall sub_659C7F(_DWORD *this, int a2, int a3)
{
  _DWORD *result; // eax

  result = this;
  this[2] = 0;
  this[3] = 0;
  *this = a2;
  this[1] = a3;
  return result;
}
