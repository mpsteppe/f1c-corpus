_DWORD *__thiscall sub_6801F7(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[1] = 0;
  *this = a2;
  this[2] = 0;
  this[3] = this + 2;
  return result;
}
