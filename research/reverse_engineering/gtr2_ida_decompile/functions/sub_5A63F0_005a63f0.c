_DWORD *__thiscall sub_5A63F0(_DWORD *this, int a2, int a3)
{
  void *v4; // eax
  DWORD v5; // eax
  _DWORD *v6; // eax
  void *v7; // ebp

  *this = off_7263F0;
  sub_630A11(this + 2, 40, 1, sub_5A4880, sub_5A4660);
  sub_59BAE0(this + 12);
  this[33] = *(unsigned __int16 *)(a2 + 10);
  sub_5A3E40();
  this[56] = 0;
  *((_BYTE *)this + 232) = 0;
  this[57] = -1;
  sub_5A4480();
  this[64] = 0;
  *((_BYTE *)this + 264) = 0;
  this[65] = -1;
  sub_5A4540();
  this[67] = 0;
  this[68] = 0;
  this[69] = 0;
  this[70] = 0;
  this[71] = 0;
  this[72] = 0;
  this[73] = 0;
  this[74] = 0;
  this[75] = 0;
  this[76] = 0;
  this[77] = 0;
  this[78] = 0;
  sub_5A7240(this + 79);
  this[341] = 0;
  this[342] = 0;
  this[343] = 0;
  this[344] = 0;
  this[345] = 0;
  *((_BYTE *)this + 1388) = 0;
  this[346] = -1;
  sub_5A44E0();
  this[348] = 0;
  this[349] = 0;
  this[350] = 0;
  this[351] = 0;
  this[352] = 0;
  *((_BYTE *)this + 1416) = 0;
  this[353] = -1;
  sub_5A44E0();
  this[355] = 0;
  this[356] = 0;
  this[357] = 0;
  this[358] = 0;
  this[359] = 0;
  *((_BYTE *)this + 1444) = 0;
  this[360] = -1;
  sub_5A44E0();
  this[362] = 0;
  this[363] = 0;
  this[364] = 0;
  this[365] = 0;
  this[366] = 0;
  *((_BYTE *)this + 1472) = 0;
  this[367] = -1;
  sub_5A44E0();
  this[369] = 0;
  this[370] = 0;
  *((_BYTE *)this + 1488) = 0;
  this[371] = -1;
  sub_5A4540();
  this[373] = 0;
  *((_BYTE *)this + 1496) = 0;
  this[394] = 0;
  *((_BYTE *)this + 1584) = 0;
  this[395] = -1;
  sub_5A45A0();
  sub_5A6CF0(this + 397, -1, 255, 0);
  this[404] = 0;
  *((_BYTE *)this + 1624) = 0;
  this[405] = -1;
  sub_5A4600();
  *((double *)this + 205) = 0.0;
  this[408] = 0;
  *((_BYTE *)this + 1648) = 0;
  *((double *)this + 207) = 0.0;
  *((double *)this + 208) = 0.0;
  memset(this + 418, 0, 0xFCu);
  *((_WORD *)this + 962) = 0;
  *((_BYTE *)this + 1926) = 0;
  this[482] = 0;
  *((_BYTE *)this + 96) = 0;
  *((_BYTE *)this + 97) = 1;
  this[25] = 64;
  *((_BYTE *)this + 104) = 0;
  this[31] = *(_DWORD *)(a2 + 4);
  this[32] = 0;
  v4 = (void *)this[56];
  if ( v4 && ((v5 = WaitForSingleObject(v4, this[57])) == 0 || v5 == 128) )
    v6 = this + 34;
  else
    v6 = 0;
  *v6 = 0;
  sub_617E70(v6 + 2);
  v7 = (void *)this[56];
  if ( v7 )
    ReleaseMutex(v7);
  *((double *)this + 30) = 100000.0;
  this[62] = 1119092736;
  this[340] = this;
  this[407] = 750;
  return this;
}
