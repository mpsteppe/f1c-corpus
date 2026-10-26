char __thiscall sub_491C70(_DWORD *this, __int16 a2, __int16 a3, __int16 a4, __int16 a5)
{
  int v5; // esi
  void *v6; // ebp
  char v7; // bl

  v5 = *this + 12;
  v6 = (void *)ResourcePoolNodeAllocDealloc(a2, a3, a4, a5);
  v7 = CollisionBroadphaseTraversal(v5, (int)v6);
  LinkedListNodePrepend(v6);
  return v7;
}
