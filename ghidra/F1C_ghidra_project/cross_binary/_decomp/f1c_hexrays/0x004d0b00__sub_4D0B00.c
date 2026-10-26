// f1c  0x004d0b00  size=23
int __thiscall sub_4D0B00(int this)
{
  *(_DWORD *)(this + 100) = 0;
  *(_DWORD *)(this + 108) = 0;
  *(_DWORD *)(this + 116) = 0;
  sub_4A2220((_BYTE *)this);
  return this;
}
