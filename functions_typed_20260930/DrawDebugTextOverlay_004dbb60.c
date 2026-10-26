int __stdcall sub_4DBB60(int a1)
{
  char v2[64]; // [esp+8h] [ebp-40h] BYREF

  sub_49C6D0((int)v2, 64);
  UITextRenderWithScale((int)v2, a1 + 50, 46, 16776960, 2, 0, 0.75, 1.0);
  DoubleRenderPass(a1 + 325, 10);
  sub_49C310(v2, 64);
  UITextRenderWithScale((int)v2, a1 + 325, 50, 0xFFFFFF, 1, 2, 1.0, 1.0);
  sub_49C370((int)v2, 64);
  UITextRenderWithScale((int)v2, a1 + 325, 50, 0xFFFFFF, 0, 1, 1.0, 1.0);
  sub_49C490(v2, 64);
  UITextRenderWithScale((int)v2, a1 + 325, 90, 0xFFFFFF, 1, 2, 1.0, 1.0);
  sub_49C4E0((int)v2, 64);
  return UITextRenderWithScale((int)v2, a1 + 325, 90, 0xFFFFFF, 0, 1, 1.0, 1.0);
}

