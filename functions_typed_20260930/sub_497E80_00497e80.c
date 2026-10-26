int __thiscall sub_497E80(_DWORD *this, int a2)
{
  int v2; // esi

  if ( !a2 )
    return 0;
  v2 = this[67];
  if ( !v2 )
    return 0;
  while ( sub_588410(v2, a2) )
  {
    v2 = *(_DWORD *)(v2 + 84);
    if ( !v2 )
      return 0;
  }
  return *(_DWORD *)(v2 + 80);
}

