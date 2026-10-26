int __userpurge sub_5E7E80@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int **a4,
        const char *ArgList,
        int a6,
        __int16 a7)
{
  _DWORD *v8; // eax
  int *v9; // eax
  int *v11; // esi
  char *v12; // [esp-Ch] [ebp-30h]
  char v13; // [esp-8h] [ebp-2Ch]
  char v14; // [esp-8h] [ebp-2Ch]

  if ( a4 )
  {
    v8 = operator new(0x88u);
    if ( v8 )
      v9 = sub_5E70C0(v8);
    else
      v9 = 0;
    *a4 = v9;
    if ( !sub_5E7880(v9, a2, a3, a1, (int)a4, ArgList, 0, 0, a6, a7) )
    {
      sub_5FDFB0(*a4, 1);
      ++(*a4)[27];
      return 0;
    }
    v11 = *a4;
    if ( *a4 )
    {
      nullsub_7(v11);
      j__free(v11);
    }
    sub_5D8C80(a1, (char *)0xFFFFFFFF, "Error initializing surface", v14);
  }
  else
  {
    sub_5D8C80(a1, (char *)0xFFFFFFFF, v12, v13);
  }
  return -1;
}
