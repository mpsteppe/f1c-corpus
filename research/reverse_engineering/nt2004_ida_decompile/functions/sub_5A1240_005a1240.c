int __thiscall sub_5A1240(_DWORD *this, int a2, void *a3)
{
  int v3; // ecx
  _BYTE *v4; // eax

  v3 = this[120];
  if ( !v3 )
    return 0;
  if ( a2 >= *(_DWORD *)(v3 + 4) )
    return 0;
  v4 = (_BYTE *)(*(_DWORD *)(v3 + 8) + 116 * a2);
  if ( (*v4 & 1) == 0 )
    return 0;
  qmemcpy(a3, v4 + 52, 0x40u);
  return 1;
}
