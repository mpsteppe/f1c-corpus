int __stdcall sub_5054D0(int a1)
{
  char Destination[64]; // [esp+8h] [ebp-40h] BYREF

  sub_4B3AD0(Destination, 64);
  sub_501610((int)Destination, a1, 8, 0xFFFFFF, 1, 0, 1.0, 1.0);
  sub_4B3B40(Destination, 64);
  sub_501610((int)Destination, a1, 8, 16776960, 0, 0, 1.0, 1.0);
  sub_5055C0(a1, 40);
  sub_4B3D00(Destination, 64);
  sub_501610((int)Destination, a1, 72, 0xFFFFFF, 1, 0, 1.0, 1.0);
  sub_4B3D70(Destination, 64);
  return sub_501610((int)Destination, a1, 72, 16776960, 0, 0, 1.0, 1.0);
}
