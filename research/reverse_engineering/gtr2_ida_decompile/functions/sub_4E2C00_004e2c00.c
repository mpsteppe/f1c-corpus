_BYTE *__thiscall sub_4E2C00(_BYTE *this)
{
  _BYTE *result; // eax

  result = this;
  *(_DWORD *)this = 3;
  this[4] = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  return result;
}
