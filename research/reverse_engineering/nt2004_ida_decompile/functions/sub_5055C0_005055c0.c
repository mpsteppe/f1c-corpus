int __stdcall sub_5055C0(int a1, int a2)
{
  char Destination[64]; // [esp+Ch] [ebp-40h] BYREF

  sub_4B3040(Destination, 64);
  sub_501610((int)Destination, a1, a2, 0xFFFFFF, 1, 0, 1.0, 1.0);
  sub_4B30B0(Destination, 64);
  return sub_501610((int)Destination, a1, a2, 16776960, 0, 0, 1.0, 1.0);
}
