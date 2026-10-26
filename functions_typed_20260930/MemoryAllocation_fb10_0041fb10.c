bool __thiscall sub_41FB10(void *this)
{
  char v2; // bl
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  bool v11; // [esp+13h] [ebp-51h]
  _BYTE v12[80]; // [esp+14h] [ebp-50h] BYREF

  v2 = 0;
  v11 = 0;
  v3 = sub_4C2990(&dword_7D2DB0);
  v4 = LinkedListDereference(&dword_7D2DB0);
  FixedOffsetReturn(v4);
  SceneNameLookupBySeason(v12, 80);
  if ( sub_566810(v12, this) )
  {
    v5 = LinkedListDereference(&dword_7D2DB0);
    if ( *(_DWORD *)(FixedOffsetReturn(v5) + 4 * v3 + 212) == 10 )
    {
      v2 = 1;
    }
    else
    {
      v6 = LinkedListDereference(&dword_7D2DB0);
      v11 = *(_DWORD *)(FixedOffsetReturn(v6) + 4 * v3 + 212) == 6;
    }
  }
  v7 = 0;
  v8 = LinkedListDereference(&dword_7D2DB0);
  if ( ActiveEntityCounter(v8) > 0 )
  {
    do
    {
      LinkedListDereference(&dword_7D2DB0);
      ShortComputation_13a0(v7);
      SceneNameLookupBySeason(v12, 80);
      if ( sub_566810(v12, this) )
      {
        LinkedListDereference(&dword_7D2DB0);
        if ( *(_DWORD *)(ShortComputation_13a0(v7) + 4 * v3 + 212) == 10 )
          v2 = 1;
        LinkedListDereference(&dword_7D2DB0);
        if ( *(_DWORD *)(ShortComputation_13a0(v7) + 4 * v3 + 212) == 6 )
          v11 = 1;
      }
      ++v7;
      v9 = LinkedListDereference(&dword_7D2DB0);
    }
    while ( v7 < ActiveEntityCounter(v9) );
  }
  return v2 && v11;
}

