// f1c  0x00448e90  size=34
int __thiscall sub_448E90(int this)
{
  memset((void *)this, 0, 0x18u);
  *(_DWORD *)(this + 28) = 0;
  *(_BYTE *)(this + 25) = 0;
  *(_WORD *)(this + 26) = -1;
  *(_BYTE *)(this + 24) = 1;
  return this;
}
