int __thiscall sub_437430(_DWORD *this)
{
  int result; // eax

  sub_4379D0();
  result = 0;
  *(_BYTE *)this = 0;
  this[1] = 0;
  this[4] = 0;
  this[5] = 0x40000000;
  *((_BYTE *)this + 1) = 0;
  this[6] = 0;
  this[7] = 1077936128;
  this[2] = 0;
  this[3] = 0;
  return result;
}
