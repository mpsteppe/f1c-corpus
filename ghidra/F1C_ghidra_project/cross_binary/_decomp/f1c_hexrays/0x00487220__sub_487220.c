// f1c  0x00487220  size=40
int __thiscall sub_487220(int this, char a2, char a3)
{
  sub_485E30((_DWORD *)this);
  *(_BYTE *)(this + 224) = a2;
  *(_DWORD *)this = &off_5AB968;
  *(_BYTE *)(this + 225) = a3;
  return this;
}
