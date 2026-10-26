int __thiscall sub_59A5B0(_DWORD *this)
{
  int v1; // esi

  v1 = this[9];
  if ( !v1 )
    return 0;
  while ( sub_598C90(v1) != -1 )
  {
    v1 = *(_DWORD *)(v1 + 168);
    if ( !v1 )
      return 0;
  }
  return -1;
}
