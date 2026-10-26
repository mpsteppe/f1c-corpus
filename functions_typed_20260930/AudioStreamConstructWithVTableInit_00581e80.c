int __thiscall sub_581E80(int this)
{
  ConstructorVTableSetInit((_DWORD *)this);
  *(_DWORD *)this = &off_5B8B3C;
  *(_WORD *)(this + 300) = 0;
  *(_DWORD *)(this + 304) = 0;
  SmallStructFieldInit(this);
  return this;
}

