int __thiscall sub_421380(void *this)
{
  int v1; // ebx
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // [esp+8h] [ebp-54h]
  _BYTE v11[80]; // [esp+Ch] [ebp-50h] BYREF

  v1 = 0;
  v10 = 0;
  if ( !this )
    return 0;
  v4 = LinkedListDereference(&dword_7D2DB0);
  if ( ActiveEntityCounter(v4) > 0 )
  {
    do
    {
      LinkedListDereference(&dword_7D2DB0);
      ShortComputation_13a0(v1);
      SceneNameLookupBySeason(v11, 80);
      if ( sub_566810(v11, this) )
      {
        v5 = 0;
        v6 = LinkedListDereference(&dword_7D2DB0);
        if ( FlagsGetter(v6) > 0 )
        {
          v7 = 216;
          do
          {
            LinkedListDereference(&dword_7D2DB0);
            if ( *(_DWORD *)(v7 + ShortComputation_13a0(v1)) == 10 )
              ++v10;
            ++v5;
            v7 += 4;
            v8 = LinkedListDereference(&dword_7D2DB0);
          }
          while ( v5 < FlagsGetter(v8) );
        }
      }
      ++v1;
      v9 = LinkedListDereference(&dword_7D2DB0);
    }
    while ( v1 < ActiveEntityCounter(v9) );
  }
  return v10;
}
