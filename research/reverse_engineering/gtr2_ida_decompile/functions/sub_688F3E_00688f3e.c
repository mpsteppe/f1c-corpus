int __thiscall sub_688F3E(_DWORD *this, _DWORD *a2, int a3)
{
  int v5; // eax
  int v6; // eax
  int v8; // [esp+14h] [ebp+8h]

  if ( a2[18] == -1 )
    return sub_6829EC(this, a2 + 5, a2 + 6, *(_DWORD *)(a3 + 20), *(_DWORD *)(a3 + 24));
  v5 = *(_DWORD *)(a3 + 20);
  if ( v5 == -1 )
    return sub_6829EC(this, a2 + 5, a2 + 6, *(_DWORD *)(a3 + 20), *(_DWORD *)(a3 + 24));
  v6 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v5) + 72);
  v8 = 0;
  if ( v6 != -1 )
    v8 = sub_680E9C(*(_DWORD **)(this[6] + 4 * v6));
  if ( !sub_6810DD(*(_DWORD **)(this[6] + 4 * a2[18])) || v8 )
    return sub_6829EC(this, a2 + 5, a2 + 6, *(_DWORD *)(a3 + 20), *(_DWORD *)(a3 + 24));
  a2[5] = -1;
  a2[6] = 1;
  return 0;
}
