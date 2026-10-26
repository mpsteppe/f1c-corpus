int __stdcall sub_5051A0(int a1)
{
  char Destination[64]; // [esp+8h] [ebp-40h] BYREF

  sub_4B3EF0(Destination, 64);
  sub_501610((int)Destination, a1, 8, 0xFFFFFF, 1, 0, 1.0, 1.0);
  sub_4B3F60(Destination, 64);
  return sub_501610((int)Destination, a1, 8, 16776960, 0, 0, 1.0, 1.0);
}
