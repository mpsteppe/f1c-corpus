int __cdecl _ZeroTail(int a1, int a2)
{
  int v2; // eax

  v2 = a2 / 32;
  if ( (~(-1 << (31 - a2 % 32)) & *(_DWORD *)(a1 + 4 * (a2 / 32))) != 0 )
    return 0;
  while ( ++v2 < 3 )
  {
    if ( *(_DWORD *)(a1 + 4 * v2) )
      return 0;
  }
  return 1;
}
