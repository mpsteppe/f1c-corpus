int __thiscall sub_52E170(int this, int a2, int a3)
{
  sub_52D9F0((_BYTE *)this);
  *(_DWORD *)(this + 11572) = a2;
  *(_DWORD *)(this + 11576) = a3;
  *(_DWORD *)this = &off_5B4810;
  return this;
}
