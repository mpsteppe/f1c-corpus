int __stdcall sub_6BB047(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // eax

  v3 = *(_DWORD *)(a3 + 16);
  v4 = *(_DWORD *)(*(_DWORD *)(v3 + 4 * a1) + 8);
  v5 = *(_DWORD *)(*(_DWORD *)(v3 + 4 * a2) + 8);
  if ( v4 < v5 )
    return 1;
  if ( v4 > v5 )
    return -1;
  if ( a1 > a2 )
    return 1;
  return -(a1 < a2);
}
