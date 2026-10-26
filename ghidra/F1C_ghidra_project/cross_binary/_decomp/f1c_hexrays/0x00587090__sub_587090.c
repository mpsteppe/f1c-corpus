// f1c  0x00587090  size=55
_DWORD *__thiscall sub_587090(_DWORD *this, int a2)
{
  sub_587490(a2 + 4);
  this[4] = *(_DWORD *)(a2 + 16);
  this[5] = *(_DWORD *)(a2 + 20);
  *((_BYTE *)this + 24) = *(_BYTE *)(a2 + 24);
  *((_BYTE *)this + 25) = 0;
  *this = &off_5B8C30;
  return this;
}
