_DWORD *__thiscall sub_4B2950(_DWORD *this)
{
  sub_4D99B0(0, 0);
  *this = &off_700498;
  this[210] = &dword_B7321C;
  this[213] = 0;
  this[212] = 4;
  this[214] = 1;
  this[215] = 1;
  this[216] = 443;
  sub_4D3CF0("Modem < 56K", -1);
  sub_4D3CF0("Modem 56K", -1);
  sub_4D3CF0("ISDN", -1);
  sub_4D3CF0("Cable/DSL", -1);
  sub_4D3CF0(&off_6F6EF4, -1);
  sub_4AC060((int)this);
  return this;
}
