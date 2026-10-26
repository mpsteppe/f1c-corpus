int __thiscall sub_5B16F0(int *this, const char *a2)
{
  int v2; // edi

  v2 = *this;
  if ( !*this )
    return 0;
  while ( strcmp((const char *)v2, a2) )
  {
    v2 = *(_DWORD *)(v2 + 28);
    if ( !v2 )
      return 0;
  }
  return v2;
}
