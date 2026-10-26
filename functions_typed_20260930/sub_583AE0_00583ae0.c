int __thiscall sub_583AE0(char *this)
{
  int *v2; // eax
  char *v3; // ebp
  int i; // eax
  int v5; // eax
  int *v6; // eax

  *(_DWORD *)this = off_5B8B60;
  v2 = (int *)*((_DWORD *)this + 71);
  v3 = this + 284;
  *((_DWORD *)this + 73) = v2;
  if ( v2 )
  {
    for ( i = *v2; i; i = *v6 )
    {
      LinkedListNodeAllocPrepend((_DWORD *)this + 67, i, 0);
      v5 = *((_DWORD *)v3 + 2);
      if ( !v5 )
        break;
      v6 = *(int **)(v5 + 4);
      *((_DWORD *)v3 + 2) = v6;
      if ( !v6 )
        break;
    }
  }
  if ( this[1608] && CloseHandle(*((HANDLE *)this + 400)) )
    *((_DWORD *)this + 400) = 0;
  SetVtablePointerAndCallInit(this + 1572);
  if ( this[1568] && CloseHandle(*((HANDLE *)this + 390)) )
    *((_DWORD *)this + 390) = 0;
  if ( this[1472] && CloseHandle(*((HANDLE *)this + 366)) )
    *((_DWORD *)this + 366) = 0;
  if ( this[1456] && CloseHandle(*((HANDLE *)this + 362)) )
    *((_DWORD *)this + 362) = 0;
  WalkLinkedListCallDestructorFreeNodes((_DWORD *)this + 358);
  if ( this[1428] && CloseHandle(*((HANDLE *)this + 355)) )
    *((_DWORD *)this + 355) = 0;
  WalkLinkedListCallDestructorFreeNodes((_DWORD *)this + 351);
  if ( this[1400] && CloseHandle(*((HANDLE *)this + 348)) )
    *((_DWORD *)this + 348) = 0;
  WalkLinkedListCallDestructorFreeNodes((_DWORD *)this + 344);
  CloseHandleWrapper((int)(this + 1348));
  WalkLinkedListCallDestructorFreeNodes((_DWORD *)this + 337);
  EmptyStub_0170();
  LinkedListCleanupWithSubObjectDelete(v3);
  LinkedListCleanupWithSubObjectDelete(this + 268);
  LinkedListCleanupWithSubObjectDelete(this + 268);
  DestroyLinkedListWithVTableDestructorDispatch(this + 252);
  if ( this[248] && CloseHandle(*((HANDLE *)this + 60)) )
    *((_DWORD *)this + 60) = 0;
  if ( this[220] && CloseHandle(*((HANDLE *)this + 53)) )
    *((_DWORD *)this + 53) = 0;
  SingleFunctionCallWrapper_3650();
  return NTimeCallbackLoopWithSEH(this + 4, 40, 1, CloseHandlePairWrapper);
}

