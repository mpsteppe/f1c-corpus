_DWORD *__thiscall sub_431700(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *(double *)this = 0.0;
  this[4] = 0;
  *((double *)this + 1) = 0.0;
  this[5] = 0;
  this[6] = 0;
  *((_BYTE *)this + 28) = 1;
  *((_BYTE *)this + 29) = 0;
  *((_BYTE *)this + 30) = 0;
  return result;
}
