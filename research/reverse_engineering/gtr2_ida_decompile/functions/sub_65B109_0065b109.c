BOOL __thiscall sub_65B109(_DWORD *this, char *a2)
{
  int i; // esi
  int v3; // eax
  _DWORD *v5; // edi

  for ( i = this[sub_65AE66(a2) + 27]; ; i = *(_DWORD *)(i + 12) )
  {
    if ( !i )
      return 0;
    v3 = strcmp(a2, *(const char **)i);
    if ( v3 < 0 )
      return 0;
    if ( !v3 )
      break;
  }
  if ( *(_DWORD *)(i + 16) )
    return 1;
  v5 = *(_DWORD **)(i + 8);
  *(_DWORD *)(i + 16) = 1;
  while ( v5 && (v5[4] != 9 || !sub_65B109(v5[6])) )
    v5 = (_DWORD *)v5[3];
  *(_DWORD *)(i + 16) = 0;
  return v5 != 0;
}
