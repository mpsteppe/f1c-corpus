_DWORD *__thiscall sub_6603E6(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *result; // eax

  result = this;
  this[3] = 0;
  *this = a2;
  this[1] = a3;
  this[2] = a4;
  this[8] = a5;
  return result;
}
