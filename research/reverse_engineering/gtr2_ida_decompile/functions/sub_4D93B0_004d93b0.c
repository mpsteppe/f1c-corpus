int __userpurge sub_4D93B0@<eax>(
        __int32 a1@<eax>,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        char a10,
        char a11)
{
  unsigned int v11; // kr00_4
  __int32 v12; // eax
  __int32 v14[2]; // [esp+0h] [ebp-8h] BYREF

  v14[1] = -1;
  v14[0] = a1;
  v11 = __readeflags();
  v12 = dword_16C6E48 + 1623710209;
  __writeeflags(v11);
  _InterlockedExchange(v14, v12);
  return sub_4D93B7(a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}
