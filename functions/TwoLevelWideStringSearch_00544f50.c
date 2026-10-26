int __thiscall sub_544F50(_DWORD *this, const char *a2)
{
  int v2; // edi
  int v3; // ecx

  v2 = this[62];
  if ( !v2 )
    return 0;
  while ( 1 )
  {
    if ( !strcmp((const char *)(v2 + 140), a2) )
      return v2;
    v3 = *(_DWORD *)(v2 + 432);
    if ( v3 )
    {
      if ( !strcmp((const char *)(v3 + 140), a2) )
        break;
    }
    v2 = *(_DWORD *)(v2 + 440);
    if ( !v2 )
      return 0;
  }
  return *(_DWORD *)(v2 + 432);
}
