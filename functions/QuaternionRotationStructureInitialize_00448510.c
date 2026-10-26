int __thiscall sub_448510(_DWORD *this, _DWORD *a2)
{
  int result; // eax

  *this = *a2;
  this[1] = a2[1];
  this[2] = a2[2];
  this[3] = a2[3];
  this[4] = a2[1];
  this[5] = a2[2];
  this[6] = 0;
  result = 0;
  memset(this + 7, 0, 0x2Cu);
  this[18] = -1;
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  return result;
}
