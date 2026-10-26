_DWORD *__thiscall sub_5770C0(_DWORD *this, int a2, char a3, int a4)
{
  sub_5774F0(0);
  this[4] = a4;
  this[5] = a2;
  *((_BYTE *)this + 24) = a3;
  *((_BYTE *)this + 25) = 0;
  *this = &off_5F6468;
  return this;
}
