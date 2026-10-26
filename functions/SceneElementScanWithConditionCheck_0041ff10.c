char __thiscall SceneElementScanWithConditionCheck(char *this)
{
  int v2; // edi
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  signed int v7; // esi
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  _BYTE v13[80]; // [esp+Ch] [ebp-50h] BYREF

  v2 = sub_4C2990(dword_7D2DB0);
  v3 = (char *)LinkedListDereference(dword_7D2DB0);
  v4 = FixedOffsetReturn(v3);
  SceneNameLookupBySeason(v4, v13, 0x50u);
  if ( sub_566810(v13, this) )
  {
    v5 = (char *)LinkedListDereference(dword_7D2DB0);
    if ( *(_DWORD *)&FixedOffsetReturn(v5)[4 * v2 + 212] == 10 )
      return 1;
  }
  v7 = 0;
  v8 = (char *)LinkedListDereference(dword_7D2DB0);
  if ( ActiveEntityCounter(v8) > 0 )
  {
    while ( 1 )
    {
      v9 = (char *)LinkedListDereference(dword_7D2DB0);
      v10 = ShortComputation_13a0(v9, v7);
      SceneNameLookupBySeason(v10, v13, 0x50u);
      if ( sub_566810(v13, this) )
      {
        v11 = (char *)LinkedListDereference(dword_7D2DB0);
        if ( *(_DWORD *)&ShortComputation_13a0(v11, v7)[4 * v2 + 212] == 10 )
          break;
      }
      ++v7;
      v12 = (char *)LinkedListDereference(dword_7D2DB0);
      if ( v7 >= ActiveEntityCounter(v12) )
        return 0;
    }
    return 1;
  }
  return 0;
}
