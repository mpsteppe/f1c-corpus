int __stdcall sub_663CC2(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v10; // edx
  unsigned int v11; // ecx

  v3 = *(_DWORD *)(a3 + 24);
  v4 = *(_DWORD *)(*(_DWORD *)(a3 + 8) + 20);
  v5 = *(_DWORD *)(v4 + 4 * *(_DWORD *)(v3 + 4 * a1));
  v6 = *(_DWORD *)(v4 + 4 * *(_DWORD *)(v3 + 4 * a2));
  v7 = *(_DWORD *)(v5 + 108);
  v8 = *(_DWORD *)(v6 + 108);
  if ( v7 < v8 )
    return -1;
  if ( v7 > v8 )
    return 1;
  v10 = *(_DWORD *)(v5 + 16);
  v11 = *(_DWORD *)(v6 + 16);
  if ( v10 < v11 )
    return -1;
  if ( v10 > v11 )
    return 1;
  if ( a2 > a1 )
    return -1;
  return a2 < a1;
}
