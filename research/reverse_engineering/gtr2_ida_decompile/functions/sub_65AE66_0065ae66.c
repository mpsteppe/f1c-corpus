unsigned int __stdcall sub_65AE66(_BYTE *a1)
{
  _BYTE *v1; // edx
  unsigned int v2; // eax
  char v3; // cl

  v1 = a1;
  v2 = 103995407;
  if ( !a1 )
    return 0;
  v3 = *a1;
  if ( !*a1 )
    return 0;
  do
  {
    v2 = v3 + 19 * v2;
    v3 = *++v1;
  }
  while ( *v1 );
  return v2 % 0x7F;
}
