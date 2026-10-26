int __thiscall sub_43A600(_DWORD *this, const void *a2, _DWORD *a3)
{
  qmemcpy(this + 8, a2, 4 * dword_16C9A74);
  sub_618D20(this);
  this[32] = *a3;
  this[33] = a3[1];
  this[34] = a3[2];
  this[35] = a3[3];
  this[36] = a3[4];
  this[37] = a3[5];
  return sub_618E60(this);
}
