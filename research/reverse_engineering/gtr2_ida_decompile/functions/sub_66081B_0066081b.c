_DWORD *__thiscall sub_66081B(_DWORD *this, int a2)
{
  memset(this, 0, 0x1Cu);
  memset(this + 7, 0, 0x1Cu);
  memset(this + 14, 0, 0x1Cu);
  memset(this + 21, 0, 0x1Cu);
  memset(this + 28, 0, 0x1Cu);
  this[35] = 0;
  this[36] = 0;
  this[37] = 0;
  this[38] = 0;
  this[43] = 0;
  this[39] = 0;
  this[40] = 0;
  this[41] = 0;
  this[42] = 0;
  this[45] = a2;
  this[44] = 0;
  if ( a2 >= 4 && a2 <= 5 )
    this[44] = 1;
  return this;
}
