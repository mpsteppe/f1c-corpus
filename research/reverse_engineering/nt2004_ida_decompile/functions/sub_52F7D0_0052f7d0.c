int __thiscall sub_52F7D0(int this, int a2, int a3)
{
  sub_52F050((_BYTE *)this);
  *(_DWORD *)(this + 11572) = a2;
  *(_DWORD *)(this + 11576) = a3;
  *(_DWORD *)this = &off_5EE3E8;
  return this;
}
