int __usercall sub_5A01D0@<eax>(char *a1@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v5; // ebx
  void *v6; // eax
  DWORD v7; // eax
  void *v8; // edi

  if ( !a1[2704] )
    return 8;
  v5 = 0;
  (*(void (__thiscall **)(char *, int, int))(*(_DWORD *)a1 + 116))(a1, a3, a2);
  sub_5A47F0(a1);
  sub_59C700();
  sub_59C700();
  sub_5A5A90(a1);
  sub_5A5BD0(a1);
  v6 = (void *)*((_DWORD *)a1 + 701);
  if ( v6 )
  {
    v7 = WaitForSingleObject(v6, *((_DWORD *)a1 + 702));
    if ( !v7 || v7 == 128 )
    {
      sub_59EAD0((int *)a1 + 697);
      v8 = (void *)*((_DWORD *)a1 + 701);
      if ( v8 )
        ReleaseMutex(v8);
    }
  }
  if ( !sub_5A00C0(a1) )
    return 9;
  return v5;
}
