int __userpurge sub_5F1150@<eax>(
        void *a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        char *ArgList,
        const char *a5,
        int a6,
        int a7,
        int *a8)
{
  int v9; // eax
  int v11; // [esp+0h] [ebp-8h]

  v9 = sub_5F04C0(a1, ArgList);
  if ( v9 )
    return sub_5F0DD0(v9, a2, a3, a5, a6, a7, a8, 0, v11);
  sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Invalid font name %s", (char)ArgList);
  return 0;
}
