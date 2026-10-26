_DWORD *__thiscall sub_5D2DD0(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = this;
  this[1] = a2;
  *this = &off_72B4A0;
  return result;
}
