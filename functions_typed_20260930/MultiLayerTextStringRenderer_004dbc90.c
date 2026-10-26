int __stdcall sub_4DBC90(int a1)
{
  char v2[64]; // [esp+8h] [ebp-40h] BYREF

  sub_49C6D0((int)v2, 64);
  UITextRenderWithScale((int)v2, a1 + 50, 46, 16776960, 2, 0, 0.75, 1.0);
  sub_49BB40((int)v2, 64);
  UITextRenderWithScale((int)v2, a1 + 245, 10, 0xFFFFFF, 1, 2, 1.0, 1.0);
  sub_49BBB0(v2, 64);
  UITextRenderWithScale((int)v2, a1 + 245, 10, 16776960, 0, 1, 1.0, 1.0);
  sub_49BCD0((int)v2, 64);
  UITextRenderWithScale((int)v2, a1 + 245, 50, 0xFFFFFF, 1, 2, 1.0, 1.0);
  sub_49BD40((int)v2, 64);
  UITextRenderWithScale((int)v2, a1 + 245, 50, 16776960, 0, 1, 1.0, 1.0);
  sub_49C0B0(v2, 64);
  return UITextRenderWithScale((int)v2, a1 + 245, 90, 16776960, 0, 1, 1.0, 1.0);
}

