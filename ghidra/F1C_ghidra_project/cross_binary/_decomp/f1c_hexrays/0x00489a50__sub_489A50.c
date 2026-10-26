// f1c  0x00489a50  size=89
char __thiscall sub_489A50(_DWORD *this, int a2, _DWORD *a3)
{
  int v3; // esi
  int v4; // edi
  char *v5; // eax

  v3 = this[36];
  v4 = 0;
  if ( !a2 || !v3 )
    return 0;
  while ( 1 )
  {
    v5 = *(char **)(v3 + 176);
    if ( !v5 )
      v5 = byte_5EA438;
    if ( !sub_588410(v5, a2) )
      break;
    v3 = *(_DWORD *)(v3 + 140);
    ++v4;
    if ( !v3 )
      return 0;
  }
  if ( a3 )
    *a3 = v4;
  return 1;
}
