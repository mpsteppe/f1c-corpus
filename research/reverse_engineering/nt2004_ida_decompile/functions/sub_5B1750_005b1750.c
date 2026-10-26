int __thiscall sub_5B1750(_DWORD *this, const char *a2)
{
  int v2; // edi

  v2 = this[1];
  if ( !v2 )
    return 0;
  while ( strcmp((const char *)v2, a2) )
  {
    v2 = *(_DWORD *)(v2 + 28);
    if ( !v2 )
      return 0;
  }
  return v2;
}
