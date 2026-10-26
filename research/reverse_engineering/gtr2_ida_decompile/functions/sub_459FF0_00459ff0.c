_DWORD *__thiscall sub_459FF0(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *this = 0;
  this[1] = 0;
  *((_WORD *)this + 4) = -3;
  *((_BYTE *)this + 10) = -1;
  *((_BYTE *)this + 11) = -1;
  this[3] = 0;
  return result;
}
