int __usercall sub_4D8470@<eax>(int a1@<ecx>, __int32 a2@<ebx>)
{
  int v3; // eax
  int v5; // [esp+0h] [ebp-14h]

  *(_DWORD *)a1 = &off_711D38;
  v3 = *(_DWORD *)(a1 + 268);
  if ( v3 )
    sub_5F5280(v3);
  if ( *(_DWORD *)(a1 + 280) )
    j_j__free(*(void **)(a1 + 280));
  if ( *(_DWORD *)(a1 + 272) )
    j_j__free(*(void **)(a1 + 272));
  return sub_4D82A0(a2, v5);
}
