int __stdcall sub_4DBE60(int a1)
{
  int v1; // ebx
  int v3[16]; // [esp+Ch] [ebp-40h] BYREF

  if ( dword_8ACF8C == 0x7FFFFFFF )
  {
    sub_49C8F0((int)v3, 64);
    v1 = a1;
    sub_4D7E40((int)v3, a1 + 50, 10, 0xFFFFFF, 1, 2, 1.0, 1.0);
    sub_49C960((int)v3, 64);
    sub_4D7E40((int)v3, a1 + 50, 10, 0xFFFFFF, 0, 1, 1.0, 1.0);
  }
  else
  {
    sub_49C670((int)v3, 64);
    v1 = a1;
    sub_4D7E40((int)v3, a1 + 215, 46, 16776960, 2, 0, 0.75, 1.0);
  }
  sub_49C700((int)v3, 64);
  sub_4D7E40((int)v3, v1 + 50, 50, 0xFFFFFF, 1, 2, 1.0, 1.0);
  sub_49C770((int)v3, 64);
  return sub_4D7E40((int)v3, v1 + 50, 50, 0xFFFFFF, 0, 1, 1.0, 1.0);
}
