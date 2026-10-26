_DWORD *__thiscall sub_6170B0(_DWORD *this)
{
  _BYTE *v2; // eax

  sub_613B30(this);
  *this = &off_72EAA4;
  sub_6187F0(this + 24);
  this[18] = (*(int (__thiscall **)(_DWORD *))(this[24] + 8))(this + 24);
  this[30] = 512;
  v2 = operator new(0x201u);
  this[29] = v2;
  v2[512] = 0;
  this[31] = -1;
  this[32] = -1;
  *((_BYTE *)this + 132) = 0;
  *((_BYTE *)this + 92) = 1;
  return this;
}
