// f1c  0x00488b00  size=47
int __thiscall sub_488B00(int this, int a2, int a3)
{
  sub_485E30((_DWORD *)this);
  *(_DWORD *)(this + 224) = a2;
  *(_DWORD *)this = &off_5ABC28;
  *(_BYTE *)(this + 232) = 1;
  *(_DWORD *)(this + 228) = a3;
  return this;
}
