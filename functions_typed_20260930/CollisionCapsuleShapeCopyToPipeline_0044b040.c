int __stdcall sub_44B040(const void *a1, int a2, _DWORD *a3)
{
  _BYTE v4[32]; // [esp+8h] [ebp-20h] BYREF

  AABBCollisionBodyInitializer((int)v4);
  qmemcpy(v4, a1, 0x18u);
  SmallStructCopy((int)v4, a2);
  return HATPolygonSurfaceFit(a3, (int)v4, 0);
}

