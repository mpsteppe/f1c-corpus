int __userpurge sub_523D70@<eax>(__int32 a1@<ebx>, int a2, int a3)
{
  unsigned int v3; // kr00_4
  int v4; // ebx
  __int32 v6[2]; // [esp+0h] [ebp-8h] BYREF

  v6[1] = -1;
  v6[0] = a1;
  v3 = __readeflags();
  v4 = dword_16C6CB0 ^ 0x3E75016C;
  __writeeflags(v3);
  _InterlockedExchange(v6, v4);
  return sub_523D77(a2, a3);
}
