BOOL __thiscall sub_685446(_DWORD *this, int a2, int a3, unsigned int a4, unsigned int a5)
{
  _DWORD *v5; // esi
  unsigned int v6; // eax
  int v7; // eax
  int v8; // edx
  int i; // eax
  int v10; // eax

  v5 = *(_DWORD **)(this[5] + 4 * a2);
  v6 = v5[18];
  if ( v6 == -1 )
    return 1;
  if ( v6 < a4 || v6 >= a5 )
    return 0;
  v7 = *(_DWORD *)(this[5] + 4 * **(_DWORD **)(a3 + 16));
  v8 = *(_DWORD *)(v7 + 24);
  for ( i = *(_DWORD *)(v7 + 20); i != -1; i = *(_DWORD *)(v10 + 20) )
  {
    if ( i == v5[5] )
      break;
    v10 = *(_DWORD *)(this[5] + 4 * i);
    v8 = *(_DWORD *)(v10 + 24);
  }
  return i == v5[5] && v8 == v5[6];
}
