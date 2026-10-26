// f1c  0x0049e410  size=121
int __thiscall sub_49E410(_DWORD *this, int a2, int a3, int a4)
{
  char v6[16]; // [esp+8h] [ebp-10h] BYREF

  sub_49BB40((int)v6, 15);
  sub_49F6A0(v6, a2, a4, this[2], *(_DWORD *)(this[5] + 84), 1);
  sub_49BBB0(v6, 15);
  return sub_49F6A0(v6, a3, a4, this[2], *(_DWORD *)(this[5] + 84), 0);
}
