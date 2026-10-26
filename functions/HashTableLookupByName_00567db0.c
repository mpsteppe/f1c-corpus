int __thiscall sub_567DB0(_DWORD *this, const char *a2, int a3)
{
  int v3; // eax
  int v5; // esi
  char *v6; // eax

  v3 = a3;
  if ( a3 == -1 )
  {
    v3 = StringHash(a2);
    if ( v3 == -1 )
      return 0;
  }
  v5 = this[v3];
  if ( !v5 )
    return 0;
  while ( 1 )
  {
    v6 = *(char **)(v5 + 16);
    if ( !v6 )
      v6 = byte_5EA438;
    if ( !sub_588410(v6, a2) )
      break;
    v5 = *(_DWORD *)(v5 + 4);
    if ( !v5 )
      return 0;
  }
  return v5;
}
