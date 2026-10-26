int __thiscall sub_48D3A0(int this, int a2, int a3)
{
  ShortComputation_5e30((_DWORD *)this);
  F_5FieldInit(this);
  *(_DWORD *)(this + 244) = a2;
  *(_BYTE *)(this + 240) = 0;
  *(_BYTE *)(this + 241) = 0;
  *(_DWORD *)this = &off_5AC118;
  *(_DWORD *)(this + 248) = a3;
  return this;
}
