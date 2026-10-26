int __usercall sub_4D82A0@<eax>(__int32 a1@<ebx>, int a2)
{
  unsigned int v2; // kr00_4
  int v3; // ebx
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = a1;
  v2 = __readeflags();
  v3 = dword_16D37A7 ^ ~dword_16C6CD0;
  __writeeflags(v2);
  _InterlockedExchange(v5, v3);
  return sub_4D82A7(a2);
}
