char __stdcall sub_497260(int a1, int a2, int a3, int a4, int a5, int a6)
{
  void *v6; // eax

  RectangleDrawingWithPattern(a5, a6, 1, a1, a2, a3, a4);
  v6 = (void *)Accessor();
  return DualDispatchWithGuard(v6, a3, a1, a4 - a3, a2 - a1);
}

