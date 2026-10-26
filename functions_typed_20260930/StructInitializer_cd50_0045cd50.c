_BYTE *__thiscall sub_45CD50(_BYTE *this)
{
  _BYTE *result; // eax

  result = this;
  *this = 0;
  this[1] = 1;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  return result;
}

