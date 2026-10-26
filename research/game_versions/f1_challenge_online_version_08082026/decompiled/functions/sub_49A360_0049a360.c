int __thiscall sub_49A360(_DWORD *this, LPCSTR lpSrcStr)
{
  unsigned int v3; // eax
  int v4; // esi
  char *v5; // eax

  sub_589901(lpSrcStr);
  v3 = sub_49A330(lpSrcStr);
  if ( v3 == -1 )
    return 0;
  v4 = this[v3];
  if ( !v4 )
    return 0;
  while ( 1 )
  {
    v5 = sub_49A2B0((char **)v4);
    if ( !sub_588410(v5, lpSrcStr) )
      break;
    v4 = *(_DWORD *)(v4 + 24);
    if ( !v4 )
      return 0;
  }
  return v4;
}
