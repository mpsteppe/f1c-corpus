BOOL __thiscall sub_49D550(int this, int a2, int a3)
{
  return *(_BYTE *)(this + 101)
      && a2 >= *(_DWORD *)(this + 12)
      && a2 <= *(_DWORD *)(this + 16)
      && a3 >= *(_DWORD *)(this + 4)
      && a3 <= *(_DWORD *)(this + 8);
}
