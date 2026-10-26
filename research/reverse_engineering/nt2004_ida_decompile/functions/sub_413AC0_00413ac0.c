char *__thiscall sub_413AC0(char *this)
{
  char *result; // eax

  result = this;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = -1;
  *((_DWORD *)this + 2) = 0;
  this[12] = 0;
  this[13] = 0;
  this[14] = 0;
  *(_DWORD *)(this + 15) = 0;
  *(_WORD *)(this + 19) = 0;
  return result;
}
