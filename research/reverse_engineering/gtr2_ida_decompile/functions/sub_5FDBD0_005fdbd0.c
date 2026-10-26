int __usercall sub_5FDBD0@<eax>(int a1@<ecx>, __int32 a2@<ebx>)
{
  int v3; // eax
  void *v4; // edi
  char *v5; // eax
  char *v6; // edi
  void *v7; // esi

  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 64) + 4);
  if ( v3 )
  {
    sub_5EA540((int)dword_FB27F8, a2, v3, 0);
    *(_DWORD *)(*(_DWORD *)(a1 + 64) + 4) = 0;
  }
  sub_5FDB10((_DWORD *)a1);
  if ( *(_DWORD *)(a1 + 96) )
    j__free(*(void **)(a1 + 96));
  if ( *(_DWORD *)(a1 + 80) )
    j__free(*(void **)(a1 + 80));
  if ( *(_DWORD *)(a1 + 88) )
    j__free(*(void **)(a1 + 88));
  v4 = *(void **)(a1 + 64);
  if ( v4 )
  {
    j_nullsub_7(*(void **)(a1 + 64));
    j__free(v4);
  }
  v5 = *(char **)(a1 + 52);
  if ( v5 )
  {
    v6 = v5 - 4;
    `eh vector destructor iterator'(v5, 0x84u, *((_DWORD *)v5 - 1), j_nullsub_7);
    j__free(v6);
  }
  v7 = *(void **)(a1 + 56);
  if ( v7 )
    j__free(v7);
  return 0;
}
