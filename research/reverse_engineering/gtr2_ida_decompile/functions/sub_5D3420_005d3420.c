_DWORD *__thiscall sub_5D3420(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *result; // eax

  result = this;
  this[6] = a2;
  this[3] = a5;
  this[4] = a6;
  this[2] = a4;
  *this = &off_72B4EC;
  this[1] = a3;
  this[5] = a7;
  return result;
}
