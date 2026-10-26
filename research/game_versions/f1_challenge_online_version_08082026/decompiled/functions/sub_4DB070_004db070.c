_DWORD *__thiscall sub_4DB070(_DWORD *this, int a2, char a3)
{
  _DWORD *result; // eax

  result = this;
  *this = &off_5AD06C;
  this[1] = a2;
  *((_BYTE *)this + 8) = a3;
  this[3] = 0;
  return result;
}
