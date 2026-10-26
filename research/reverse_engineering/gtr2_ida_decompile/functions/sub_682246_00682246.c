int __stdcall sub_682246(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // eax

  v3 = *(_DWORD *)(a3 + 20);
  v4 = *(_DWORD *)(*(_DWORD *)(v3 + 4 * a1) + 64);
  v5 = *(_DWORD *)(*(_DWORD *)(v3 + 4 * a2) + 64);
  if ( v5 <= v4 )
    return v5 < v4;
  else
    return -1;
}
