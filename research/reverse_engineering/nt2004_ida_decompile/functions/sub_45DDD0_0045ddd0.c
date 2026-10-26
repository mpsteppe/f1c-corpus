int __thiscall sub_45DDD0(_DWORD *this, int a2)
{
  int result; // eax

  this[a2 + 5] = 0;
  this[a2 + 54] = 0;
  *((_BYTE *)this + a2 + 412) = 0;
  *((_BYTE *)this + a2 + 461) = 0;
  result = 0;
  memset((char *)&this[8 * a2 + 127] + 2, 0, 0x20u);
  *((_WORD *)this + a2 + 1138) = 0;
  this[a2 + 520] = -1082130432;
  return result;
}
