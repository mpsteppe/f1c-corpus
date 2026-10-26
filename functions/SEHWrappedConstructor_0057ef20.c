_DWORD *sub_57EF20()
{
  _DWORD *v0; // eax

  v0 = (_DWORD *)OperatorNewNhMallocWrapper(32);
  if ( v0 )
    return ObjectInitWithVTableFieldSet(v0, 0, 0, 0);
  else
    return 0;
}
