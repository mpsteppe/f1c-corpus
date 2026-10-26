// f1c  0x004a2800  size=56
int __thiscall sub_4A2800(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  this[19] = *a2;
  this[20] = a2[1];
  this[21] = a2[2];
  this[22] = *a3;
  this[23] = a3[1];
  this[24] = a3[2];
  return sub_4A27D0((int)this);
}
