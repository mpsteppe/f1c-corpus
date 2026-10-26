_DWORD *__thiscall sub_5F4610(_DWORD *this)
{
  sub_5D9010(this);
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  memset(this + 5, 0, 0x100u);
  return this;
}
