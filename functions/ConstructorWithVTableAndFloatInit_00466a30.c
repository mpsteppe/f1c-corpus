int __thiscall ConstructorWithVTableAndFloatInit(int this, int a2, int a3, int a4)
{
  InitVTableSet((_DWORD *)this, a3, a4);
  *(_DWORD *)this = &off_59F380;
  *(_DWORD *)(this + 260) = 1056964608;
  *(_BYTE *)(this + 256) = 0;
  *(_DWORD *)(this + 264) = a2;
  return this;
}
