_DWORD *__thiscall sub_4DBF80(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // ecx

  v2 = this + 17;
  v3 = 4;
  do
  {
    *v2 = 0;
    v2[1] = 0;
    v2[2] = 0;
    v2 += 3;
    --v3;
  }
  while ( v3 );
  *this = 0;
  this[1] = -1;
  this[40] = 0;
  this[41] = 0;
  this[42] = 0;
  sub_4DC3F0(this);
  this[3] = 0;
  this[5] = 0;
  this[4] = 2;
  this[6] = -1082130432;
  this[7] = -1082130432;
  this[8] = -1082130432;
  this[11] = -1082130432;
  this[12] = -1;
  this[13] = -1;
  this[10] = -1;
  this[14] = 0;
  this[15] = 0;
  this[29] = 0;
  this[30] = 0;
  this[31] = -1082130432;
  this[32] = -1082130432;
  this[33] = -1082130432;
  this[34] = -1082130432;
  this[35] = -1082130432;
  this[36] = -1082130432;
  this[37] = -1082130432;
  this[55] = -8388609;
  this[56] = -8388609;
  this[38] = 0;
  *((_BYTE *)this + 188) = 0;
  this[48] = 0;
  *((_BYTE *)this + 204) = 0;
  this[52] = 0;
  this[53] = 0;
  this[54] = 0;
  this[57] = -1;
  this[58] = 0;
  this[59] = 0;
  this[60] = 0;
  this[61] = 0;
  *((_BYTE *)this + 248) = 0;
  this[63] = 0;
  this[66] = 0;
  this[64] = -1;
  this[67] = 0;
  memset(this + 83, 0xFFu, 0x28u);
  return this;
}
