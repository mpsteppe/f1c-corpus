_DWORD *__thiscall LinkedListNodeInsert_78a0(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax

  if ( !this[34] )
    return 0;
  v2 = (_DWORD *)OperatorNewNhMallocWrapper(96);
  if ( !v2 )
    return 0;
  v3 = MutexSynchronizationObjectInit(v2, (int)this);
  if ( !v3 )
    return 0;
  v4 = OperatorNewNhMallocWrapper(12);
  if ( v4 )
  {
    *(_DWORD *)v4 = v3;
    *(_DWORD *)(v4 + 4) = 0;
    *(_BYTE *)(v4 + 8) = 0;
  }
  else
  {
    v4 = 0;
  }
  if ( this[6] )
  {
    *(_DWORD *)(this[7] + 4) = v4;
  }
  else
  {
    this[6] = v4;
    this[8] = v4;
  }
  this[7] = v4;
  ++this[9];
  return v3;
}
