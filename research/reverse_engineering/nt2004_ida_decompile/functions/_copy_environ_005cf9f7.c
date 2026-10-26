_DWORD *__cdecl copy_environ(_DWORD *a1)
{
  int v1; // ecx
  int *v3; // eax
  int v4; // edx
  _DWORD *v5; // esi
  _DWORD *v6; // ebp
  const char *v7; // eax
  const char **v8; // ebx

  v1 = 0;
  if ( !a1 )
    return 0;
  v3 = a1 + 1;
  if ( *a1 )
  {
    do
    {
      v4 = *v3;
      ++v1;
      ++v3;
    }
    while ( v4 );
  }
  v5 = malloc(4 * v1 + 4);
  v6 = v5;
  if ( !v5 )
    _amsg_exit(9u);
  v7 = (const char *)*a1;
  v8 = (const char **)a1;
  while ( v7 )
  {
    ++v8;
    *v5 = _strdup(v7);
    v7 = *v8;
    ++v5;
  }
  *v5 = 0;
  return v6;
}
