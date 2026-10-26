void __cdecl __free_lconv_num(int a1)
{
  void *v1; // eax
  void *v2; // esi

  if ( a1 )
  {
    if ( *(_UNKNOWN **)a1 != *off_91318C && *(_UNKNOWN **)a1 != off_91315C )
      free(*(void **)a1);
    v1 = *(void **)(a1 + 4);
    if ( v1 != off_91318C[1] && v1 != off_913160 )
      free(*(void **)(a1 + 4));
    v2 = *(void **)(a1 + 8);
    if ( v2 != off_91318C[2] && v2 != off_913164 )
      free(v2);
  }
}
