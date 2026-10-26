int __thiscall sub_4A2C50(int this, int a2, int a3)
{
  sub_49C450((_DWORD *)this);
  sub_49E4D0(this);
  *(_DWORD *)(this + 288) = a2;
  *(_BYTE *)(this + 284) = 0;
  *(_BYTE *)(this + 285) = 0;
  *(_DWORD *)this = &off_5E99E8;
  *(_DWORD *)(this + 292) = a3;
  return this;
}
