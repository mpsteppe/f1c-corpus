int __thiscall sub_545150(_DWORD *this, _DWORD *a2)
{
  int v4; // eax
  void *v5; // ebx
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  _DWORD *v9; // ebx
  _DWORD *v10; // eax

  if ( a2[17] )
  {
    F_3DSoundSourceDestructor(a2[17]);
    a2[17] = 0;
  }
  if ( a2[16] && a2[19] )
  {
    F_3DSoundSourceDestructor(a2[19]);
    a2[19] = 0;
  }
  if ( SceneGraph(a2) )
    return -1;
  if ( a2[140] )
  {
    MultiFieldObjectDestructorWithCleanupCalls();
    v4 = a2[16];
    if ( v4 )
    {
      if ( *(_DWORD *)(v4 + 560) )
        DoublyLinkedListNodeUnlink_0f10(a2[140]);
    }
    else
    {
      LinkedListRemove_59d0(a2[140]);
    }
    v5 = (void *)a2[140];
    if ( v5 )
    {
      StateFlagSetterCleanup(a2[140]);
      FreeWrapper_7bcf(v5);
    }
  }
  v6 = 0;
  if ( (int)this[83] > 0 )
  {
    v7 = 0;
    do
    {
      v8 = this[84];
      v9 = *(_DWORD **)(v8 + v7 + 16);
      v10 = (_DWORD *)(v8 + v7 + 16);
      if ( v9 == a2 )
        *v10 = 0;
      ++v6;
      v7 += 24;
    }
    while ( v6 < this[83] );
  }
  LinkedListRemove(a2);
  TwoFunctionCallChain(a2);
  FreeWrapper_7bcf(a2);
  return 0;
}
