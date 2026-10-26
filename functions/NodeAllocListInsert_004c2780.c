char __thiscall sub_4C2780(int *this)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax

  if ( DelegatedFieldGetter(this) == 2 )
    LinkedListNodeRemovalWithCleanup(this);
  v2 = OperatorNewNhMallocWrapper(45396);
  if ( v2 )
    v3 = AudioSubsystemInitializer(v2);
  else
    v3 = 0;
  GameFilterDataLoader(v3);
  if ( v3 )
  {
    v4 = OperatorNewNhMallocWrapper(12);
    if ( v4 )
    {
      *(_DWORD *)v4 = v3;
      *(_DWORD *)(v4 + 4) = 0;
      *(_BYTE *)(v4 + 8) = 1;
    }
    else
    {
      v4 = 0;
    }
    if ( !*this )
    {
      *this = v4;
      this[2] = v4;
      this[1] = v4;
      ++this[3];
      return 0;
    }
    *(_DWORD *)(this[1] + 4) = v4;
    this[1] = v4;
    ++this[3];
  }
  return 0;
}
