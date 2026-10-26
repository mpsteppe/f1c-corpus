int __stdcall sub_681E57(int a1, int a2, int a3)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // esi

  v3 = *(_DWORD *)(a3 + 20);
  v4 = *(_DWORD *)(v3 + 4 * a2);
  v5 = *(_DWORD *)(v3 + 4 * a1);
  v6 = *(_DWORD *)(v5 + 4);
  v7 = *(_DWORD *)(v4 + 4);
  if ( v6 < v7 )
    return -1;
  if ( v6 > v7 )
    return 1;
  if ( *(double *)(v5 + 32) < *(double *)(v4 + 32) )
    return -1;
  return *(double *)(v5 + 32) > *(double *)(v4 + 32);
}
