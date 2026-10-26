int __thiscall sub_4B59D0(_DWORD *this, int a2, int a3, int a4)
{
  char Destination[16]; // [esp+8h] [ebp-10h] BYREF

  sub_4B3040(Destination, 16);
  sub_505C90(a2, a4, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
  sub_4B30B0(Destination, 16);
  return sub_505C90(a3, a4, -1, 0, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
}
