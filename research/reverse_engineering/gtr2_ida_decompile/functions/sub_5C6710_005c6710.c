_WORD *__thiscall sub_5C6710(_WORD *this, int a2, float *a3)
{
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  *((_DWORD *)this + 2) = a2;
  this[3] = 0x7FFF;
  *this = (unsigned __int64)(*a3 * 32767.0);
  this[1] = (unsigned __int64)(a3[1] * 32767.0);
  this[2] = (unsigned __int64)(a3[2] * 32767.0);
  this[3] = (unsigned __int64)(a3[3] * 32767.0);
  return this;
}
