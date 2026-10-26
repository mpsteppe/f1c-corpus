int __stdcall sub_6CD318(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // eax

  v3 = *(_DWORD *)(a3 + 60);
  v4 = *(_DWORD *)(v3 + 4 * a1);
  v5 = *(_DWORD *)(v3 + 4 * a2);
  if ( *(_DWORD *)(*(_DWORD *)(a3 + 44) + 4 * v4) > *(_DWORD *)(*(_DWORD *)(a3 + 44) + 4 * v5) )
    return -1;
  if ( *(_DWORD *)(*(_DWORD *)(a3 + 44) + 4 * v4) < *(_DWORD *)(*(_DWORD *)(a3 + 44) + 4 * v5) )
    return 1;
  if ( v5 > v4 )
    return -1;
  return v5 < v4;
}
