int sub_41E840()
{
  int v0; // eax
  int v1; // eax

  if ( !LinkedListDereference(&dword_7D2DB0) )
    return 0;
  v0 = LinkedListDereference(&dword_7D2DB0);
  if ( !FixedOffsetReturn(v0) )
    return 0;
  v1 = LinkedListDereference(&dword_7D2DB0);
  return *(_DWORD *)(FixedOffsetReturn(v1) + 408);
}

