void __thiscall NetworkMessageDispatch(int this, int a2)
{
  int v2; // ebp
  int *v4; // eax
  char v5; // cl
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int *v9; // eax
  int v10; // eax
  _DWORD *v11; // esi
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  int v14; // eax
  int v15; // [esp-8h] [ebp-20h]
  char v16; // [esp+13h] [ebp-5h]

  v2 = a2;
  v4 = *(int **)(this + 32);
  v5 = *(_BYTE *)(a2 + 8);
  v6 = (*(_DWORD *)a2 >> 18) & 0x3F;
  v16 = v5;
  *(_DWORD *)(this + 40) = v4;
  if ( v4 && (v7 = *v4) != 0 )
  {
    while ( v6 != *(_DWORD *)(v7 + 872) || v5 != *(_BYTE *)(v7 + 876) )
    {
      v8 = *(_DWORD *)(this + 40);
      if ( v8 )
        *(_DWORD *)(this + 40) = *(_DWORD *)(v8 + 4);
      v9 = *(int **)(this + 40);
      if ( v9 )
      {
        v7 = *v9;
        if ( v7 )
          continue;
      }
      goto LABEL_9;
    }
    v11 = (_DWORD *)v7;
  }
  else
  {
LABEL_9:
    v10 = *(_DWORD *)(this + 16);
    v11 = 0;
    *(_DWORD *)(this + 24) = v10;
    if ( v10 )
    {
      v11 = *(_DWORD **)v10;
      v15 = *(_DWORD *)v10;
      *(_BYTE *)(v10 + 8) = 0;
      if ( !DoublyLinkedListNodeRemoval((_DWORD *)(this + 16), v15, 1) )
        v11 = 0;
    }
    if ( !v11 )
    {
      v12 = (_DWORD *)OperatorNewNhMallocWrapper(4);
      if ( v12 )
        v13 = sub_4BA980(v12, 0);
      else
        v13 = 0;
      CollisionNodeListInsertion((_DWORD *)this, v13, 0);
      v11 = LinkedListRemoveByValue((_DWORD *)(this + 16));
    }
    ThunkWithStructInitSubCalls(v11);
    *((_BYTE *)v11 + 876) = -1;
    v11[218] = 0;
    v11[220] = -51331646;
    v11[218] = v6;
    *((_BYTE *)v11 + 876) = v16;
    v11[220] = *(_DWORD *)(this + 48);
    v14 = OperatorNewNhMallocWrapper(12);
    if ( v14 )
    {
      *(_DWORD *)v14 = v11;
      *(_DWORD *)(v14 + 4) = 0;
      *(_BYTE *)(v14 + 8) = 0;
    }
    else
    {
      v14 = 0;
    }
    if ( *(_DWORD *)(this + 32) )
    {
      *(_DWORD *)(*(_DWORD *)(this + 36) + 4) = v14;
    }
    else
    {
      *(_DWORD *)(this + 32) = v14;
      *(_DWORD *)(this + 40) = v14;
    }
    v2 = a2;
    *(_DWORD *)(this + 36) = v14;
    ++*(_DWORD *)(this + 44);
  }
  ZoneThresholdComparisonWithConditionalAction((int)v11, *(float *)(this + 48), v2);
}

