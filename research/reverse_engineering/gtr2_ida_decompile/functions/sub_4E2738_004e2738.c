int __usercall sub_4E2738@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        char *a3,
        const char *a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  unsigned int v8; // kr00_4
  unsigned int v10[69]; // [esp-Ch] [ebp-114h] BYREF

  v10[67] = *(_DWORD *)(a2 - 21);
  v10[2] = a2;
  v10[1] = a1;
  if ( !*(_DWORD *)dword_91CA70 )
  {
    v8 = __readeflags();
    v10[0] = v8;
    sub_FF9170(dword_16C6320, v10);
    __writeeflags(v10[0]);
  }
  return sprintf(a3, a4, a5, a6, a7, a8);
}
