char __thiscall sub_41FC60(void *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // eax
  _BYTE v16[80]; // [esp+10h] [ebp-50h] BYREF

  v2 = LinkedListDereference(&dword_7D2DB0);
  FixedOffsetReturn(v2);
  SceneNameLookupBySeason(v16, 80);
  if ( sub_566810(v16, this) && (v3 = 0, v4 = LinkedListDereference(&dword_7D2DB0), FlagsGetter(v4) > 0) )
  {
    v5 = 216;
    while ( 1 )
    {
      v6 = LinkedListDereference(&dword_7D2DB0);
      if ( *(_DWORD *)(v5 + FixedOffsetReturn(v6)) == 10 )
        break;
      ++v3;
      v5 += 4;
      v7 = LinkedListDereference(&dword_7D2DB0);
      if ( v3 >= FlagsGetter(v7) )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v8 = 0;
    v9 = LinkedListDereference(&dword_7D2DB0);
    if ( ActiveEntityCounter(v9) <= 0 )
      return 0;
    while ( 1 )
    {
      LinkedListDereference(&dword_7D2DB0);
      ShortComputation_13a0(v8);
      SceneNameLookupBySeason(v16, 80);
      if ( sub_566810(v16, this) )
      {
        v10 = 0;
        v11 = LinkedListDereference(&dword_7D2DB0);
        if ( FlagsGetter(v11) > 0 )
          break;
      }
LABEL_12:
      ++v8;
      v14 = LinkedListDereference(&dword_7D2DB0);
      if ( v8 >= ActiveEntityCounter(v14) )
        return 0;
    }
    v12 = 216;
    while ( 1 )
    {
      LinkedListDereference(&dword_7D2DB0);
      if ( *(_DWORD *)(v12 + ShortComputation_13a0(v8)) == 10 )
        break;
      ++v10;
      v12 += 4;
      v13 = LinkedListDereference(&dword_7D2DB0);
      if ( v10 >= FlagsGetter(v13) )
        goto LABEL_12;
    }
  }
  return 1;
}

