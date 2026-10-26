_DWORD *__thiscall sub_45E940(_DWORD *this, int a2)
{
  char *v3; // edi
  int v4; // ebp
  char *v5; // edi
  int v6; // ebp

  sub_462C80(this + 11);
  this[34] = 0;
  this[35] = -1;
  this[36] = 0;
  this[37] = -1;
  this[39] = 0;
  this[40] = -1;
  this[108] = 0;
  this[109] = -1;
  v3 = (char *)(this + 188);
  v4 = 48;
  do
  {
    sub_462BC0(v3);
    v3 += 116;
    --v4;
  }
  while ( v4 );
  this[1678] = off_5D6450;
  this[1679] = 0;
  this[1681] = 0;
  this[1682] = 0;
  this[1683] = 0;
  this[1684] = 0;
  v5 = (char *)(this + 1735);
  v6 = 49;
  do
  {
    sub_52D820(v5);
    v5 += 424;
    --v6;
  }
  while ( v6 );
  sub_45DCD0(this + 6929);
  sub_45D550(this + 7523);
  this[7530] = 0;
  this[7531] = 0;
  this[7532] = 0;
  this[7533] = 0;
  sub_45E2D0((_BYTE *)this + 30136);
  *this = a2;
  this[2] = 0;
  *((float *)this + 1) = 1.0 / 24.0;
  this[3] = 1092616192;
  this[4] = 1092616192;
  this[5] = 0;
  *((_BYTE *)this + 24) = 0;
  *((_BYTE *)this + 25) = 0;
  this[7] = 1106247680;
  *((_BYTE *)this + 32) = 0;
  *((_BYTE *)this + 33) = 1;
  this[9] = -1082130432;
  *((_BYTE *)this + 40) = 0;
  *((_BYTE *)this + 152) = 1;
  *((_BYTE *)this + 153) = 0;
  *((_BYTE *)this + 164) = 0;
  *((_BYTE *)this + 165) = 0;
  *((_BYTE *)this + 166) = 0;
  *((_BYTE *)this + 167) = 0;
  *((_BYTE *)this + 252) = 0;
  *((_BYTE *)this + 332) = 0;
  this[99] = -1;
  *((_BYTE *)this + 400) = 0;
  this[110] = 0;
  sub_45FDB0(this);
  *((_BYTE *)this + 636) = 0;
  this[160] = 0;
  this[161] = 0;
  this[162] = 0;
  this[163] = 0;
  this[164] = 0;
  this[165] = 0;
  this[166] = 0;
  this[167] = 0;
  this[168] = 0;
  *((_BYTE *)this + 676) = 0;
  *((_BYTE *)this + 677) = 0;
  this[1628] = 0;
  this[1677] = 0;
  this[1680] = 0;
  *((_BYTE *)this + 6741) = 0;
  *((_BYTE *)this + 30112) = 0;
  *((_BYTE *)this + 30113) = 0;
  *((_BYTE *)this + 30114) = 0;
  *((_BYTE *)this + 30115) = 0;
  *((_BYTE *)this + 30116) = 0;
  *((_BYTE *)this + 30117) = 0;
  *((_BYTE *)this + 30118) = 0;
  this[187] = 1;
  *((_BYTE *)this + 6740) = 9;
  return this;
}
