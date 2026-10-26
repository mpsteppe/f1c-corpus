int __thiscall sub_65B1A2(_DWORD *this, char *a2, _DWORD *a3, _DWORD *a4)
{
  int i; // esi
  int v7; // eax

  if ( sub_65B109(this, a2) )
    return 0;
  for ( i = this[sub_65AE66(a2) + 27]; ; i = *(_DWORD *)(i + 12) )
  {
    if ( !i )
      return 0;
    v7 = strcmp(a2, *(const char **)i);
    if ( v7 < 0 )
      return 0;
    if ( !v7 )
      break;
  }
  if ( a3 )
    *a3 = *(_DWORD *)(i + 4);
  if ( a4 )
    *a4 = *(_DWORD *)(i + 8);
  return 1;
}
