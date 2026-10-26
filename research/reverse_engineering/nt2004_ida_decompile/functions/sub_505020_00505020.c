int __stdcall sub_505020(int a1)
{
  char Destination[64]; // [esp+8h] [ebp-40h] BYREF

  sub_4B3C20(Destination, 64);
  sub_501610((int)Destination, a1, 8, 0xFFFFFF, 1, 0, 1.0, 1.0);
  sub_4B3C90(Destination, 64);
  sub_501610((int)Destination, a1, 8, 16776960, 0, 0, 1.0, 1.0);
  sub_4B3630(Destination, 64);
  sub_501610((int)Destination, a1, 40, 0xFFFFFF, 1, 0, 1.0, 1.0);
  sub_4B3750(Destination, 64);
  sub_501610((int)Destination, a1, 40, 16776960, 0, 0, 1.0, 1.0);
  sub_4B3200(Destination, 64);
  sub_501610((int)Destination, a1, 72, 0xFFFFFF, 1, 0, 1.0, 1.0);
  sub_4B3270(Destination, 64);
  sub_501610((int)Destination, a1, 72, 16776960, 0, 0, 1.0, 1.0);
  sub_4B35A0(Destination, 64);
  return sub_501610((int)Destination, a1 + 200, 104, 16776960, 1, 0, 1.0, 1.0);
}
