int __thiscall sub_40E8B0(int this, __int16 a2, int a3)
{
  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 28) = 8;
  *(_DWORD *)(this + 32) = a3;
  LightFrustumClosestPoint(a3, (float *)(this + 12), (float *)(this + 24));
  return NestedLoopRangeTraversal(this);
}

