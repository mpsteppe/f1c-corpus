int __thiscall sub_559200(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v7; // ecx
  int i; // eax

  v4 = (_DWORD *)OperatorNewNhMallocWrapper(108);
  if ( v4 )
    v5 = StructZeroInitWithDefaults(v4);
  else
    v5 = 0;
  if ( FlagConditionalBranchDispatch((const CHAR *)v5, a3) )
  {
    if ( v5 )
    {
      EmptyStub_7470(v5);
      FreeWrapper_7bcf(v5);
    }
    if ( a2 )
      *a2 = 0;
    return -1;
  }
  else
  {
    v7 = this[82];
    if ( v7 )
    {
      for ( i = *(_DWORD *)(v7 + 104); i; i = *(_DWORD *)(i + 104) )
        v7 = i;
      *(_DWORD *)(v7 + 104) = v5;
      v5[25] = v7;
    }
    else
    {
      this[82] = v5;
    }
    ++this[81];
    if ( a2 )
      *a2 = v5;
    return -(VertexBufferResourceAllocation(this) != 0);
  }
}

