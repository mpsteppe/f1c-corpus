// positive sp value has been detected, the output may be wrong!
char __thiscall sub_58119A(_DWORD *this, int a2, int a3)
{
  void *v4; // eax
  _DWORD *v5; // esi
  void *v6; // esi
  void *v8; // esi

  v4 = (void *)this[400];
  v5 = this + 393;
  if ( v4 )
    WaitForSingleObject(v4, this[401]);
  if ( NegatedPredicate(a2, a3) )
  {
    v8 = (void *)v5[7];
    if ( v8 )
      ReleaseMutex(v8);
    return 0;
  }
  else
  {
    CounterIncrementDecrementByFlag(1);
    v6 = (void *)v5[7];
    if ( v6 )
      ReleaseMutex(v6);
    sub_57E280(this, 1.0);
    return 1;
  }
}

