int __cdecl __addl(unsigned int a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v3; // ecx
  int result; // eax

  v3 = a1 + a2;
  result = 0;
  if ( a1 + a2 < a1 || v3 < a2 )
    result = 1;
  *a3 = v3;
  return result;
}
