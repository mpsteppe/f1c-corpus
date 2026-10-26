// f1c  0x00587030  size=50
_DWORD *__thiscall sub_587030(_DWORD *this, int a2, char a3, int a4)
{
  sub_587460(0);
  this[4] = a4;
  this[5] = a2;
  *((_BYTE *)this + 24) = a3;
  *((_BYTE *)this + 25) = 0;
  *this = &off_5B8C30;
  return this;
}
