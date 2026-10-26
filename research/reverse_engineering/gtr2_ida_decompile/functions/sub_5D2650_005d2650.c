int __usercall sub_5D2650@<eax>(int a1@<ecx>, int a2@<edi>)
{
  void *v3; // edi
  int result; // eax

  if ( *(_DWORD *)(a1 + 16) )
  {
    sub_5D2650(a2);
    v3 = *(void **)(a1 + 16);
    if ( v3 )
    {
      sub_5D1ED0(*(void **)(a1 + 16));
      j__free(v3);
    }
    return off_16C92CC();
  }
  return result;
}
