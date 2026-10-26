int __thiscall sub_497890(int this, int a2, int a3)
{
  int *v4; // eax
  int v5; // ebp
  int v6; // esi
  int i; // edi
  int v8; // eax
  int *v9; // eax
  int v10; // ebx

  if ( *(_DWORD *)(this + 24) )
    ListIterationWithVTableDispatch();
  v4 = *(int **)(this + 4);
  v5 = 0;
  *(_DWORD *)(this + 12) = v4;
  if ( v4 )
  {
    v6 = *v4;
    if ( *v4 )
    {
      do
      {
        for ( i = FieldGetter_8e30(v6); i; i = *(_DWORD *)(i + 72) )
        {
          if ( i == a2 )
          {
            if ( *(_BYTE *)(this + 5492) )
              sub_4977E0((_DWORD *)this, a2, a3);
            DoublyLinkedListAppend_5a80((_DWORD *)this, v6);
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 44))(v6, 1);
            SetterVirtualCall(i);
            v5 = 1;
          }
        }
        v8 = *(_DWORD *)(this + 12);
        if ( !v8 )
          break;
        v9 = *(int **)(v8 + 4);
        *(_DWORD *)(this + 12) = v9;
        if ( !v9 )
          break;
        v6 = *v9;
      }
      while ( *v9 );
    }
  }
  v10 = *(_DWORD *)(this + 24);
  if ( v10 )
    LinkedListIterationVirtualCall(v10);
  return v5;
}
