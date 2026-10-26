// f1c  0x0044a430  size=25
_DWORD *__thiscall sub_44A430(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *this = 0;
  this[1] = 0;
  *((_WORD *)this + 4) = -3;
  *((_WORD *)this + 5) = -1;
  this[3] = 0;
  return result;
}
