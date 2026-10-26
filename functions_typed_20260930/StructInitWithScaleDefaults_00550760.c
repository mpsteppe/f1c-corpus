_DWORD *__thiscall sub_550760(_DWORD *this)
{
  GlobalZeroInit_c2a0(this);
  *((_BYTE *)this + 68) = 0;
  *this = -1;
  memset(this + 1, 0, 0x40u);
  this[6] = 1065353216;
  this[11] = 1065353216;
  this[16] = 1065353216;
  this[1] = 1065353216;
  this[33] = 0;
  return this;
}

