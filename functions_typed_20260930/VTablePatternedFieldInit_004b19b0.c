_DWORD *__thiscall sub_4B19B0(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  this[1] = 0;
  this[2] = -1;
  this[3] = 0;
  this[4] = -1;
  *this = off_5ACC20;
  return result;
}

