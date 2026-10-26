_DWORD *__thiscall sub_52AC40(_DWORD *this)
{
  _DWORD *v2; // edi

  v2 = this + 7;
  sub_52AAD0(this + 7);
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  sub_52A510(this + 48);
  *this = 1065353216;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  *v2 = 0;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  this[13] = 0;
  this[14] = 0;
  *((_BYTE *)this + 60) = 0;
  this[16] = 0;
  *((_WORD *)this + 34) = 0;
  *((_WORD *)this + 35) = -1;
  *((_WORD *)this + 36) = -1;
  *((_WORD *)this + 37) = 0;
  *((_WORD *)this + 38) = 0x7FFF;
  *((_WORD *)this + 39) = 0x8000;
  sub_52B7E0(this);
  return this;
}
