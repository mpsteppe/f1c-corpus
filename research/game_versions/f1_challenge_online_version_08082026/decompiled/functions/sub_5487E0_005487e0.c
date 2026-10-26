int __thiscall sub_5487E0(_DWORD *this)
{
  int v1; // esi

  v1 = this[9];
  if ( !v1 )
    return 0;
  while ( sub_5469C0(v1) != -1 )
  {
    v1 = *(_DWORD *)(v1 + 192);
    if ( !v1 )
      return 0;
  }
  return -1;
}
