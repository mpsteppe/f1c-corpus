int __stdcall sub_504ED0(int a1)
{
  char Buffer[64]; // [esp+8h] [ebp-40h] BYREF

  sub_4B3C20(Buffer, 64);
  sub_501610((int)Buffer, a1, 8, 0xFFFFFF, 1, 0, 1.0, 1.0);
  sub_4B3C90(Buffer, 64);
  sub_501610((int)Buffer, a1, 8, 16776960, 0, 0, 1.0, 1.0);
  sub_4B37E0(Buffer, 64);
  sub_501610((int)Buffer, a1, 40, 0xFFFFFF, 1, 0, 1.0, 1.0);
  sub_4B3840(Buffer, 64);
  sub_501610((int)Buffer, a1, 40, 16776960, 0, 0, 1.0, 1.0);
  sub_4B3960(Buffer, 64);
  sub_501610((int)Buffer, a1, 72, 0xFFFFFF, 1, 0, 1.0, 1.0);
  sub_4B39B0(Buffer, 64);
  return sub_501610((int)Buffer, a1, 72, 16776960, 0, 0, 1.0, 1.0);
}
