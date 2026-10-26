unsigned int __cdecl shortsort(unsigned int a1, unsigned int a2, int a3, int (__cdecl *a4)(unsigned int))
{
  unsigned int result; // eax
  unsigned int i; // edi
  unsigned int v6; // ebx
  unsigned int j; // esi

  result = a1;
  for ( i = a2; i > a1; i -= a3 )
  {
    v6 = a1;
    for ( j = a3 + a1; j <= i; j += a3 )
    {
      if ( a4(j) > 0 )
        v6 = j;
    }
    result = swap(v6, i, a3);
  }
  return result;
}
