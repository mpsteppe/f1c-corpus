void __cdecl __free_lconv_mon(int a1)
{
  void *v1; // eax
  void *v2; // eax
  void *v3; // eax
  void *v4; // eax
  void *v5; // eax
  void *v6; // eax
  void *v7; // esi

  if ( a1 )
  {
    v1 = *(void **)(a1 + 12);
    if ( v1 != off_91318C[3] && v1 != off_913168 )
      free(*(void **)(a1 + 12));
    v2 = *(void **)(a1 + 16);
    if ( v2 != off_91318C[4] && v2 != off_91316C )
      free(*(void **)(a1 + 16));
    v3 = *(void **)(a1 + 20);
    if ( v3 != off_91318C[5] && v3 != off_913170 )
      free(*(void **)(a1 + 20));
    v4 = *(void **)(a1 + 24);
    if ( v4 != off_91318C[6] && v4 != off_913174 )
      free(*(void **)(a1 + 24));
    v5 = *(void **)(a1 + 28);
    if ( v5 != off_91318C[7] && v5 != off_913178 )
      free(*(void **)(a1 + 28));
    v6 = *(void **)(a1 + 32);
    if ( v6 != off_91318C[8] && v6 != off_91317C )
      free(*(void **)(a1 + 32));
    v7 = *(void **)(a1 + 36);
    if ( v7 != off_91318C[9] && v7 != off_913180 )
      free(v7);
  }
}
