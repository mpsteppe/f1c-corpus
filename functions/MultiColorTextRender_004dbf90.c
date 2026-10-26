int __stdcall sub_4DBF90(int a1)
{
  char v2[64]; // [esp+8h] [ebp-40h] BYREF

  sub_49C670((int)v2, 64);
  UITextRenderWithScale((int)v2, a1 + 215, 46, 16776960, 2, 0, 0.75, 1.0);
  sub_49BDE0((int)v2, 64);
  UITextRenderWithScale((int)v2, a1 + 15, 10, 0xFFFFFF, 1, 2, 1.0, 1.0);
  sub_49BE50(v2, 64);
  UITextRenderWithScale((int)v2, a1 + 15, 10, 16776960, 0, 1, 1.0, 1.0);
  sub_49C700((int)v2, 64);
  UITextRenderWithScale((int)v2, a1 + 15, 90, 0xFFFFFF, 1, 2, 1.0, 1.0);
  sub_49C770((int)v2, 64);
  return UITextRenderWithScale((int)v2, a1 + 15, 90, 16776960, 0, 1, 1.0, 1.0);
}
