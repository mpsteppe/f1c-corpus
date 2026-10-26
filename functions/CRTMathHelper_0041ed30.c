int __thiscall sub_41ED30(void *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // esi
  int v6; // ecx
  int v7; // edx
  int v8; // esi
  int v9; // edx

  v2 = -1;
  if ( LinkedListDereference(&dword_7D2DB0) )
  {
    v3 = LinkedListDereference(&dword_7D2DB0);
    v4 = FlagsGetter(v3);
    if ( v4 < 2 )
      return -1;
    v6 = ScoringSessionStatsAggregator((int)this, 0);
    if ( !v6 )
      return -1;
    v7 = 0;
    v8 = v4 - 1;
    if ( v8 > 0 )
    {
      do
      {
        v2 += IndexedFieldGetter(v6, v7);
        v7 = v9 + 1;
      }
      while ( v7 < v8 );
    }
  }
  return v2;
}
