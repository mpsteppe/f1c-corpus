int __fastcall sub_41F220(int a1, int a2)
{
  int v4; // eax
  int v5; // ebp
  int i; // edi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int j; // esi
  int v12; // eax
  int v13; // [esp+Ch] [ebp-58h]
  _BYTE v15[80]; // [esp+14h] [ebp-50h] BYREF

  v4 = LinkedListDereference(&dword_7D2DB0);
  v5 = 0;
  v13 = ActiveEntityCounter(v4);
  if ( !a1 )
    return -1;
  if ( a2 == -1 )
  {
    LinkedListDereference(&dword_7D2DB0);
    return sub_4C13C0(a1);
  }
  else
  {
    for ( i = 0; i < a2; ++i )
    {
      v8 = LinkedListDereference(&dword_7D2DB0);
      FixedOffsetReturn(v8);
      SceneNameLookupBySeason(v15, 80);
      if ( sub_566810(v15, a1) )
      {
        v9 = LinkedListDereference(&dword_7D2DB0);
        v10 = FixedOffsetReturn(v9);
        v5 += IndexedFieldGetter(v10, i);
      }
      for ( j = 0; j < v13; ++j )
      {
        LinkedListDereference(&dword_7D2DB0);
        ShortComputation_13a0(j);
        SceneNameLookupBySeason(v15, 80);
        if ( sub_566810(v15, a1) )
        {
          LinkedListDereference(&dword_7D2DB0);
          v12 = ShortComputation_13a0(j);
          v5 += IndexedFieldGetter(v12, i);
        }
      }
    }
    return v5;
  }
}
