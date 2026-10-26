int __thiscall sub_4B5A30(int this)
{
  int v2; // esi
  int v3; // ecx
  int v4; // esi
  _DWORD *v5; // ebx
  int v6; // esi
  bool v7; // zf
  int v9; // [esp+10h] [ebp-4h]

  SpriteOverlayListCleanup();
  sub_4B5E50(this);
  LinkedBufferTransfer(this);
  if ( *(_DWORD *)(this + 3988) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 3988));
  ListRebuildWithNodeTransfer((_DWORD *)(this + 3908));
  LinkedListDestruction(this + 3940);
  LinkedListDestruction(this + 3924);
  LinkedListDestructionWithRefCountLoop(this + 3908);
  EmptyStub_0170();
  EmptyStub_0170();
  if ( *(_DWORD *)(this + 1836) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 1836));
  if ( *(_DWORD *)(this + 1828) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 1828));
  LinkedListDestructor_b400(this + 1812);
  if ( *(_DWORD *)(this + 1804) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 1804));
  if ( *(_DWORD *)(this + 1796) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 1796));
  SubCallWithConditionalFieldFree(this + 1764);
  v2 = *(_DWORD *)(this + 1748);
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 4);
    ConditionalDestructor_46f0(v3, 1);
  }
  *(_DWORD *)(this + 1748) = 0;
  *(_DWORD *)(this + 1752) = 0;
  *(_DWORD *)(this + 1756) = 0;
  *(_DWORD *)(this + 1760) = 0;
  v4 = *(_DWORD *)(this + 1728);
  while ( v4 )
  {
    v4 = *(_DWORD *)(v4 + 4);
    LinkedListNodeDestructor_a900(1);
  }
  *(_DWORD *)(this + 1728) = 0;
  *(_DWORD *)(this + 1732) = 0;
  *(_DWORD *)(this + 1736) = 0;
  *(_DWORD *)(this + 1740) = 0;
  v5 = (_DWORD *)(this + 1728);
  v9 = 104;
  do
  {
    v6 = *(v5 - 4);
    v5 -= 4;
    while ( v6 )
    {
      v6 = *(_DWORD *)(v6 + 4);
      NodeDestructor(1);
    }
    v7 = v9 == 1;
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    --v9;
  }
  while ( !v7 );
  LinkedListFree((int *)(this + 48));
  LinkedListFree((int *)(this + 48));
  ListFullDestruction(this + 32);
  LinkedListDestructorWithCallback(this + 16);
  LinkedListDestructorWithCallback(this + 16);
  return LinkedListDestroy_b5a0(this);
}
