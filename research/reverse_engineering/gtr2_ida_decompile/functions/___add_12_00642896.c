int __cdecl __add_12(unsigned int *a1, unsigned int *a2)
{
  if ( __addl(*a1, *a2, a1) && __addl(a1[1], 1u, a1 + 1) )
    ++a1[2];
  if ( __addl(a1[1], a2[1], a1 + 1) )
    ++a1[2];
  return __addl(a1[2], a2[2], a1 + 2);
}
