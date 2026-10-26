int __thiscall sub_599BF0(_DWORD *this, const char *a2)
{
  int v2; // edi

  v2 = this[9];
  if ( !v2 )
    return 0;
  while ( strcmp((const char *)v2, a2) )
  {
    v2 = *(_DWORD *)(v2 + 168);
    if ( !v2 )
      return 0;
  }
  return v2;
}
