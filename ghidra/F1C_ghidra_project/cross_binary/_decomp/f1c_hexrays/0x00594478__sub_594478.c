// f1c  0x00594478  size=177
char *sub_594478()
{
  int v0; // eax
  void *v1; // eax
  char *v2; // esi
  LPVOID v3; // eax
  LPVOID v4; // eax

  v0 = dword_8D48F8;
  if ( dword_8D48F8 == dword_8D48E8 )
  {
    v1 = HeapReAlloc(hHeap, 0, lpMem, 4 * (5 * dword_8D48E8 + 80));
    if ( !v1 )
      return 0;
    dword_8D48E8 += 16;
    lpMem = v1;
    v0 = dword_8D48F8;
  }
  v2 = (char *)lpMem + 20 * v0;
  v3 = HeapAlloc(hHeap, 8u, 0x41C4u);
  *((_DWORD *)v2 + 4) = v3;
  if ( !v3 )
    return 0;
  v4 = VirtualAlloc(0, 0x100000u, 0x2000u, 4u);
  *((_DWORD *)v2 + 3) = v4;
  if ( !v4 )
  {
    HeapFree(hHeap, 0, *((LPVOID *)v2 + 4));
    return 0;
  }
  *((_DWORD *)v2 + 2) = -1;
  *(_DWORD *)v2 = 0;
  *((_DWORD *)v2 + 1) = 0;
  ++dword_8D48F8;
  **((_DWORD **)v2 + 4) = -1;
  return v2;
}
