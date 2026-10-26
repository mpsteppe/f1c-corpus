char **__usercall copy_environ@<eax>(char **a1@<edi>)
{
  int v1; // ecx
  char **result; // eax
  char **v3; // esi
  const char *v4; // eax
  const char **v5; // ebx
  char **v6; // [esp+0h] [ebp-4h]

  v1 = 0;
  result = a1;
  if ( a1 )
  {
    if ( *a1 )
    {
      do
      {
        ++result;
        ++v1;
      }
      while ( *result );
    }
    v3 = (char **)malloc(4 * v1 + 4);
    v6 = v3;
    if ( !v3 )
      _amsg_exit(9u);
    v4 = *a1;
    v5 = (const char **)a1;
    while ( v4 )
    {
      *v3++ = _strdup(v4);
      v4 = *++v5;
    }
    *v3 = 0;
    return v6;
  }
  return result;
}
