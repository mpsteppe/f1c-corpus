int __thiscall ConstructorWithVTableAndSubInit(int this)
{
  sub_4893C0(this);
  *(_DWORD *)(this + 372) = 0;
  *(_DWORD *)(this + 376) = -1;
  *(_DWORD *)this = &off_59F938;
  ByteSetterAt0xe0((_BYTE *)this, 0);
  return this;
}
