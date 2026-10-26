_DWORD *__thiscall sub_524870(_DWORD *this)
{
  _DWORD *v2; // edx
  int v3; // edi
  int v4; // edx
  _DWORD *v5; // eax
  int v6; // ecx

  v2 = this + 56;
  v3 = 45;
  do
  {
    sub_524850(v2);
    v2 = (_DWORD *)(v4 + 32);
    --v3;
  }
  while ( v3 );
  sub_524520(this + 416);
  sub_524520(this + 433);
  *this = 0;
  *((_BYTE *)this + 4) = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  v5 = this + 22;
  v6 = 4;
  do
  {
    *(v5 - 2) = 0;
    *(v5 - 1) = 0;
    *v5 = 0;
    v5 += 3;
    --v6;
  }
  while ( v6 );
  this[32] = 0;
  this[33] = 0;
  this[34] = 0;
  this[35] = 0;
  this[36] = 0;
  *((_BYTE *)this + 152) = 0;
  this[39] = 0;
  this[40] = 1065353216;
  this[41] = 0;
  this[42] = 0;
  this[43] = 0;
  *((_BYTE *)this + 176) = 0;
  memset((char *)this + 177, 1u, 0x2Cu);
  *((_BYTE *)this + 221) = 1;
  this[432] = 0;
  this[449] = 0;
  this[37] = 0;
  return this;
}
