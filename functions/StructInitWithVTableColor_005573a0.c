_DWORD *__thiscall sub_5573A0(_DWORD *this)
{
  GlobalZeroInit_c2a0(this);
  F_10FloatStructInitializer(this + 4);
  *this = 0;
  this[1] = -1;
  this[2] = 0;
  this[3] = 0xFFFFFF;
  Identity44MatrixInit(this + 4);
  this[30] = 0;
  this[31] = 0;
  return this;
}
