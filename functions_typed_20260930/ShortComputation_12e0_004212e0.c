int __thiscall sub_4212E0(void *this)
{
  int v2; // edi
  int v4; // esi
  int v5; // eax
  int v6; // eax
  _BYTE v7[80]; // [esp+8h] [ebp-50h] BYREF

  v2 = 0;
  if ( !this )
    return 0;
  v4 = 0;
  v5 = LinkedListDereference(&dword_7D2DB0);
  if ( ActiveEntityCounter(v5) > 0 )
  {
    do
    {
      LinkedListDereference(&dword_7D2DB0);
      ShortComputation_13a0(v4);
      SceneNameLookupBySeason(v7, 80);
      if ( sub_566810(v7, this) )
      {
        LinkedListDereference(&dword_7D2DB0);
        v2 += *(_DWORD *)(ShortComputation_13a0(v4) + 416);
      }
      ++v4;
      v6 = LinkedListDereference(&dword_7D2DB0);
    }
    while ( v4 < ActiveEntityCounter(v6) );
  }
  return v2;
}

