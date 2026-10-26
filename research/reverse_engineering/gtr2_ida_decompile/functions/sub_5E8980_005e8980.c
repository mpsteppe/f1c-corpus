_DWORD *__thiscall sub_5E8980(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *(_BYTE *)this = 0;
  this[4] = 0;
  this[5] = 0;
  return result;
}
