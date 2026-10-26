BOOL __stdcall sub_408ED0(int a1)
{
  FILE *v1; // eax
  unsigned int *v2; // edi
  void *v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // ebx

  v1 = *(FILE **)(a1 + 12);
  if ( !v1 )
    return 1;
  if ( *(_DWORD *)(a1 + 24) )
    return 1;
  fseek(v1, 0, 0);
  v2 = (unsigned int *)(a1 + 20);
  if ( !sub_5BED6F((void *)(a1 + 20), 4u, 1u, *(FILE **)(a1 + 12)) )
    return 1;
  v3 = operator new(4 * *v2);
  v4 = *v2;
  *(_DWORD *)(a1 + 24) = v3;
  v5 = 0;
  if ( v4 )
  {
    do
      *(_DWORD *)(*(_DWORD *)(a1 + 24) + 4 * v5++) = 0;
    while ( v5 < *v2 );
  }
  v6 = 0;
  if ( *v2 )
  {
    while ( sub_5BED6F((void *)(*(_DWORD *)(a1 + 24) + 4 * v6), 4u, 1u, *(FILE **)(a1 + 12)) )
    {
      if ( ++v6 >= *v2 )
        return v6 != *v2;
    }
    pfnAPC(*(_DWORD *)(a1 + 12));
    sub_5BE8AE(*(LPVOID *)(a1 + 24));
    *(_DWORD *)(a1 + 24) = 0;
  }
  return v6 != *v2;
}
