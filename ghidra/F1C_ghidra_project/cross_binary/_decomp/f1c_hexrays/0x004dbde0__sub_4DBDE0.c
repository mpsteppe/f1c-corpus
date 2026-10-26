// f1c  0x004dbde0  size=127
int __stdcall sub_4DBDE0(int a1)
{
  int v2[16]; // [esp+8h] [ebp-40h] BYREF

  sub_49C8F0((int)v2, 64);
  sub_4D7E40((int)v2, a1 + 245, 10, 0xFFFFFF, 1, 2, 1.0, 1.0);
  sub_49C960((int)v2, 64);
  return sub_4D7E40((int)v2, a1 + 245, 10, 0xFFFFFF, 0, 1, 1.0, 1.0);
}
