unsigned int __stdcall sub_65EBAB(_BYTE *a1)
{
  _BYTE *v1; // esi
  unsigned int v2; // edi

  v1 = a1;
  v2 = 0;
  if ( !a1 || !*a1 )
    return 0;
  do
  {
    v2 = sub_633CD6() + 19 * v2;
    ++v1;
  }
  while ( *v1 );
  return v2 % 7;
}
