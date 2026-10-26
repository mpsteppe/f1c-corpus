int __cdecl sub_423830(const char **a1, const char **a2)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = *a2;
  if ( !*a2 )
    v2 = byte_5EA438;
  v3 = *a1;
  if ( !*a1 )
    v3 = byte_5EA438;
  return strcmp(v3, v2);
}

