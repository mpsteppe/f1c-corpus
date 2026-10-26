_DWORD *__thiscall sub_659F73(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[1] = 0;
  *this = a2;
  this[2] = 1;
  return result;
}
