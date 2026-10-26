_DWORD *__thiscall sub_434AD0(_DWORD *this)
{
  _BYTE *v2; // eax
  _BYTE *v3; // eax
  _BYTE *v4; // eax

  v2 = operator new(0x50u);
  *this = v2;
  *v2 = 0;
  this[1] = 80;
  v3 = operator new(0x50u);
  this[2] = v3;
  *v3 = 0;
  this[3] = 80;
  v4 = operator new(0x80u);
  this[4] = v4;
  *v4 = 0;
  this[5] = 128;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  this[13] = 0;
  this[14] = 0;
  this[15] = 0;
  this[6] = 0;
  this[7] = 0;
  return this;
}
