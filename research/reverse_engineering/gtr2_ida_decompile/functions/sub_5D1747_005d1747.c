// positive sp value has been detected, the output may be wrong!
void __usercall sub_5D1747(int a1@<ecx>, int a2@<edi>)
{
  int v3; // eax
  int v4; // ecx
  void *v5; // edi
  void *v7; // edi

  *(_DWORD *)a1 = &off_72B39C;
  if ( *(_DWORD *)(a1 + 12) )
  {
    do
    {
      v3 = *(_DWORD *)(a1 + 12);
      v4 = *(_DWORD *)(a1 + 20);
      v5 = *(void **)(v4 + 4 * v3 - 4);
      if ( v5 )
      {
        sub_5C24A0(*(_DWORD **)(v4 + 4 * v3 - 4));
        j__free(v5);
      }
    }
    while ( (*(_DWORD *)(a1 + 12))-- != 1 );
  }
  v7 = *(void **)(a1 + 8);
  if ( v7 )
  {
    sub_5C2280();
    j__free(v7);
  }
  sub_4F14D0(a2);
  sub_5A8D10(*(void **)(a1 + 20));
}
