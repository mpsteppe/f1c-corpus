int __cdecl sub_59CCA0(const char *a1, int a2, int a3)
{
  unsigned int v3; // kr00_4
  const char *i; // eax

  v3 = strlen(a1);
  for ( i = &a1[v3]; i > a1; --i )
  {
    if ( *i == 92 )
      break;
  }
  return sub_630FE0(a1, a2, a3);
}
