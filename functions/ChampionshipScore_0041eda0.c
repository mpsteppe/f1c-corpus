char __thiscall sub_41EDA0(void *this)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // edi
  int v8; // ebp
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // eax
  char v15; // cl
  int v17; // [esp+10h] [ebp-70h]
  int v18; // [esp+14h] [ebp-6Ch]
  int v19; // [esp+14h] [ebp-6Ch]
  _DWORD v20[26]; // [esp+18h] [ebp-68h] BYREF

  if ( !LinkedListDereference(&dword_7D2DB0) )
    return 0;
  v2 = 0;
  v17 = 0;
  v3 = LinkedListDereference(&dword_7D2DB0);
  v18 = FlagsGetter(v3);
  v4 = LinkedListDereference(&dword_7D2DB0);
  v5 = ActiveEntityCounter(v4);
  if ( !this )
    return 0;
  memset(v20, 0, sizeof(v20));
  v6 = LinkedListDereference(&dword_7D2DB0);
  if ( this == (void *)FixedOffsetReturn(v6) )
  {
    v17 = 0;
  }
  else if ( v5 > 0 )
  {
    do
    {
      LinkedListDereference(&dword_7D2DB0);
      if ( this == (void *)ShortComputation_13a0(v2) )
        v17 = v2 + 1;
      ++v2;
    }
    while ( v2 < v5 );
  }
  v7 = 0;
  v19 = v18 - 1;
  if ( v19 <= 0 )
    return 0;
  v8 = v5 + 1;
  while ( 1 )
  {
    v9 = LinkedListDereference(&dword_7D2DB0);
    v10 = FixedOffsetReturn(v9);
    v11 = IndexedFieldGetter(v10, v7);
    v12 = 0;
    v20[0] += v11;
    if ( v5 > 0 )
    {
      do
      {
        LinkedListDereference(&dword_7D2DB0);
        v13 = ShortComputation_13a0(v12);
        v20[++v12] += IndexedFieldGetter(v13, v7);
      }
      while ( v12 < v5 );
    }
    v14 = 0;
    v15 = 1;
    if ( v8 <= 0 )
      break;
    do
    {
      if ( v14 != v17 && v20[v17] < v20[v14] )
        v15 = 0;
      ++v14;
    }
    while ( v14 < v8 );
    if ( v15 )
      break;
    if ( ++v7 >= v19 )
      return 0;
  }
  return 1;
}
