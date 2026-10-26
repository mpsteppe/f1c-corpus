_DWORD *__thiscall sub_4764B0(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *(_BYTE *)this = 0;
  this[32] = 0;
  return result;
}
