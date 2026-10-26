int __thiscall sub_59A570(_DWORD *this)
{
  int v1; // esi

  v1 = this[9];
  if ( !v1 )
    return 0;
  while ( !sub_598650(v1, -1) )
  {
    InterlockedDecrement(&Addend);
    sub_598180(0);
    v1 = *(_DWORD *)(v1 + 168);
    if ( !v1 )
      return 0;
  }
  return -1;
}
