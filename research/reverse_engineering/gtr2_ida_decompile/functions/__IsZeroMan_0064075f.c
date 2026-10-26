int __cdecl _IsZeroMan(int a1)
{
  int v1; // eax

  v1 = 0;
  while ( !*(_DWORD *)(a1 + 4 * v1) )
  {
    if ( ++v1 >= 3 )
      return 1;
  }
  return 0;
}
