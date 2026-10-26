int __stdcall UIDebugOverlayRender(int a1)
{
  int v2[16]; // [esp+8h] [ebp-40h] BYREF

  SeasonNameLookup((int)v2, 64);
  UITextRenderWithScale((int)v2, a1, 10, 0xFFFFFF, 1, 2, 1.0, 1.0);
  sub_49C670((int)v2, 64);
  UITextRenderWithScale((int)v2, a1, 10, 0xFFFFFF, 0, 1, 1.0, 1.0);
  DoubleRenderPass(a1, 50);
  sub_49C700((int)v2, 64);
  UITextRenderWithScale((int)v2, a1, 90, 0xFFFFFF, 1, 2, 1.0, 1.0);
  sub_49C770((int)v2, 64);
  return UITextRenderWithScale((int)v2, a1, 90, 0xFFFFFF, 0, 1, 1.0, 1.0);
}

