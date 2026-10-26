_DWORD *__thiscall sub_65BC9B(_DWORD *this)
{
  char *v2; // eax
  char *v3; // eax

  sub_67EB04(0x100000, 0x10000);
  sub_65D585(this + 6);
  this[169] = 0;
  sub_65B31F(this);
  this[14] = 0;
  this[15] = 0;
  this[16] = 1;
  this[17] = 0;
  this[18] = 0;
  this[19] = 1;
  this[20] = 1;
  this[21] = 1;
  this[22] = 0;
  this[23] = 0;
  this[24] = 0;
  this[25] = 0;
  this[26] = 0;
  this[154] = 0;
  this[155] = 0;
  memset(this + 27, 0, 0x1FCu);
  memset(this + 158, 0, 0x20u);
  this[166] = 1;
  v2 = setlocale(4, 0);
  v3 = _strdup(v2);
  this[167] = v3;
  if ( !v3 || strcmp(v3, "C") )
    setlocale(4, "C");
  this[168] = _controlfp(0, 0);
  _controlfp(0xFFFFFFFF, 0x8001Fu);
  _controlfp(0, 0x30000u);
  sub_5AF608();
  return this;
}
