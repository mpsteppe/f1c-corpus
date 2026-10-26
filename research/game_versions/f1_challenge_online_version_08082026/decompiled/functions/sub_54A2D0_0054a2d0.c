int __thiscall sub_54A2D0(_DWORD *this, const char *a2)
{
  int v2; // edi

  v2 = this[64];
  if ( !v2 )
    return 0;
  while ( strcmp((const char *)(v2 + 8), a2) )
  {
    v2 = *(_DWORD *)(v2 + 260);
    if ( !v2 )
      return 0;
  }
  return v2;
}
