// f1c  0x0048d3a0  size=61
int __thiscall sub_48D3A0(int this, int a2, int a3)
{
  sub_485E30((_DWORD *)this);
  sub_4883A0(this);
  *(_DWORD *)(this + 244) = a2;
  *(_BYTE *)(this + 240) = 0;
  *(_BYTE *)(this + 241) = 0;
  *(_DWORD *)this = &off_5AC118;
  *(_DWORD *)(this + 248) = a3;
  return this;
}
