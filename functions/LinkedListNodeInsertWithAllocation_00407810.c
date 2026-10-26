_DWORD *__thiscall LinkedListNodeInsertWithAllocation(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v5; // eax
  _DWORD *v6; // edi
  int v7; // eax

  if ( !this[34] )
    return 0;
  if ( !a2 )
    return 0;
  v5 = (_DWORD *)OperatorNewNhMallocWrapper(108);
  if ( !v5 )
    return 0;
  v6 = ViewProjectionStructInit(v5, a2, a3, a4, (int)this);
  if ( !v6 )
    return 0;
  v7 = OperatorNewNhMallocWrapper(12);
  if ( v7 )
  {
    *(_DWORD *)v7 = v6;
    *(_DWORD *)(v7 + 4) = 0;
    *(_BYTE *)(v7 + 8) = 0;
  }
  else
  {
    v7 = 0;
  }
  if ( this[2] )
  {
    *(_DWORD *)(this[3] + 4) = v7;
  }
  else
  {
    this[2] = v7;
    this[4] = v7;
  }
  this[3] = v7;
  ++this[5];
  return v6;
}
