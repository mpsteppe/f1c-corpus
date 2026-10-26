int __thiscall sub_489BA0(_DWORD *this, int a2, char a3)
{
  int v4; // esi
  int v5; // edi
  char *v6; // eax

  v4 = this[36];
  v5 = 1;
  if ( !a2 || !v4 )
    return -1;
  while ( 1 )
  {
    v6 = *(char **)(v4 + 176);
    if ( !v6 )
      v6 = byte_5EA438;
    if ( !sub_588410(v6, a2) )
      break;
    v4 = *(_DWORD *)(v4 + 140);
    ++v5;
    if ( !v4 )
      return -1;
  }
  UIListSelectionHandler(this, v5, a3);
  return 0;
}
