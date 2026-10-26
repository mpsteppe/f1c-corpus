int __stdcall sub_4DC1A0(int a1, int a2)
{
  char v3[64]; // [esp+Ch] [ebp-40h] BYREF

  sub_49BB40((int)v3, 64);
  UITextRenderWithScale((int)v3, a1, a2, 0xFFFFFF, 1, 2, 1.0, 1.0);
  sub_49BBB0(v3, 64);
  return UITextRenderWithScale((int)v3, a1, a2, 0xFFFFFF, 0, 1, 1.0, 1.0);
}

