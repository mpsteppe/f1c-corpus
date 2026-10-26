_BYTE *__cdecl sub_58B050(const char *a1, unsigned __int8 a2)
{
  unsigned int v2; // ecx
  const char *v3; // edi
  bool v4; // zf
  _BYTE *v5; // edi

  v2 = strlen(a1) + 1;
  v3 = &a1[v2 - 1];
  do
  {
    if ( !v2 )
      break;
    v4 = *v3-- == a2;
    --v2;
  }
  while ( !v4 );
  v5 = v3 + 1;
  if ( *v5 == a2 )
    return v5;
  else
    return 0;
}
