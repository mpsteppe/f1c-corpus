int __usercall sub_606750@<eax>(int *a1@<ecx>, int a2@<edi>)
{
  int v3; // esi
  void **v4; // edi
  char v5; // al
  void *v6; // ebp
  int result; // eax
  int v8; // [esp-8h] [ebp-10h]

  v3 = *a1;
  if ( *a1 )
  {
    v8 = a2;
    do
    {
      v4 = (void **)v3;
      v5 = *(_BYTE *)(v3 + 8);
      v3 = *(_DWORD *)(v3 + 4);
      if ( v5 )
      {
        v6 = *v4;
        if ( *v4 )
        {
          sub_5FAB30(v8);
          j__free(v6);
        }
      }
      j__free(v4);
    }
    while ( v3 );
  }
  result = 0;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  return result;
}
