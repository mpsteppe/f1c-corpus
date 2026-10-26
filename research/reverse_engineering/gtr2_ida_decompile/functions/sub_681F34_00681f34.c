int __stdcall sub_681F34(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax

  v3 = *(_DWORD *)(a3 + 24);
  v4 = *(_DWORD *)(*(_DWORD *)(v3 + 4 * a1) + 48);
  v5 = *(_DWORD *)(*(_DWORD *)(v3 + 4 * a2) + 48);
  if ( v4 < v5 )
    return -1;
  if ( v4 > v5 )
    return 1;
  if ( a2 > a1 )
    return -1;
  return a2 < a1;
}
