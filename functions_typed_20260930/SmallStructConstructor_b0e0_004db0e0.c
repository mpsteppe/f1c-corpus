_DWORD *__thiscall sub_4DB0E0(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  this[1] = 1;
  *((_BYTE *)this + 8) = 1;
  this[3] = 0;
  *this = &off_5AD034;
  return result;
}

