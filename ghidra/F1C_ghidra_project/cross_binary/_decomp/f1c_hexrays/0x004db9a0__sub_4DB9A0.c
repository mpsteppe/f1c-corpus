// f1c  0x004db9a0  size=82
int __stdcall sub_4DB9A0(float a1, int a2, int a3)
{
  int v3; // eax
  int v5[2]; // [esp+0h] [ebp-8h] BYREF

  v3 = sub_587BDC(a1);
  sub_58815F(v5, "%d", v3);
  return sub_4D7E40((int)v5, a2, a3, 16776960, 2, 1, 1.0, 1.0);
}
