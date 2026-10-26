// f1c  0x00467260  size=86
_DWORD *__thiscall sub_467260(_DWORD *this, int a2, int a3)
{
  sub_48C070(0);
  this[201] = a2;
  *this = &off_59F4F8;
  this[200] = (char *)&unk_7C6270 + 64 * a2;
  this[199] = a3;
  this[202] = 11;
  this[203] = 4;
  *((_BYTE *)this + 773) = 0;
  return this;
}
