int __fastcall sub_41E920(int a1, char a2)
{
  int v3; // edi
  int v4; // ebp
  int v5; // eax
  char *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  char *v12; // eax
  int v13; // eax
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int v18; // esi
  int v19; // eax
  int v20; // edi
  int v21; // eax

  v3 = -1;
  v4 = 0;
  if ( LinkedListDereference(&dword_7D2DB0) )
  {
    if ( !a1 )
      goto LABEL_6;
    v5 = LinkedListDereference(&dword_7D2DB0);
    v6 = *(char **)FixedOffsetReturn(v5);
    if ( !v6 )
      v6 = &byte_5EA438;
    if ( sub_588410(a1, v6) )
    {
LABEL_6:
      v7 = LinkedListDereference(&dword_7D2DB0);
      if ( *(int *)(FixedOffsetReturn(v7) + 408) > -1 )
      {
        v8 = LinkedListDereference(&dword_7D2DB0);
        v4 = FixedOffsetReturn(v8);
        v9 = LinkedListDereference(&dword_7D2DB0);
        v3 = *(_DWORD *)(FixedOffsetReturn(v9) + 408);
      }
    }
    v10 = 0;
    v11 = LinkedListDereference(&dword_7D2DB0);
    if ( ActiveEntityCounter(v11) > 0 )
    {
      do
      {
        LinkedListDereference(&dword_7D2DB0);
        if ( *(_DWORD *)(ShortComputation_13a0(v10) + 408) > v3 )
        {
          if ( !a1 )
            goto LABEL_14;
          LinkedListDereference(&dword_7D2DB0);
          v12 = *(char **)ShortComputation_13a0(v10);
          if ( !v12 )
            v12 = &byte_5EA438;
          if ( sub_588410(a1, v12) )
          {
LABEL_14:
            LinkedListDereference(&dword_7D2DB0);
            v4 = ShortComputation_13a0(v10);
            LinkedListDereference(&dword_7D2DB0);
            v3 = *(_DWORD *)(ShortComputation_13a0(v10) + 408);
          }
        }
        ++v10;
        v13 = LinkedListDereference(&dword_7D2DB0);
      }
      while ( v10 < ActiveEntityCounter(v13) );
    }
    if ( !a2 )
    {
      if ( !v4 )
        return 0;
      v15 = LinkedListDereference(&dword_7D2DB0);
      if ( v4 != FixedOffsetReturn(v15) )
      {
        v16 = *(_DWORD *)(v4 + 408);
        v17 = LinkedListDereference(&dword_7D2DB0);
        if ( v16 == *(_DWORD *)(FixedOffsetReturn(v17) + 408) )
          return 0;
      }
      v18 = 0;
      v19 = LinkedListDereference(&dword_7D2DB0);
      if ( ActiveEntityCounter(v19) > 0 )
      {
        while ( 1 )
        {
          LinkedListDereference(&dword_7D2DB0);
          if ( v4 != ShortComputation_13a0(v18) )
          {
            v20 = *(_DWORD *)(v4 + 408);
            LinkedListDereference(&dword_7D2DB0);
            if ( v20 == *(_DWORD *)(ShortComputation_13a0(v18) + 408) )
              break;
          }
          ++v18;
          v21 = LinkedListDereference(&dword_7D2DB0);
          if ( v18 >= ActiveEntityCounter(v21) )
            return v4;
        }
        return 0;
      }
    }
  }
  return v4;
}
