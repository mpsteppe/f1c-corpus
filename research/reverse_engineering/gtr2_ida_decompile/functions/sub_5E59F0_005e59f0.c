int __userpurge sub_5E59F0@<eax>(__int32 a1@<ebx>, int a2, int a3, int a4)
{
  unsigned int v4; // kr00_4
  unsigned int v5; // ebx
  __int32 v7[2]; // [esp+0h] [ebp-8h] BYREF

  v7[1] = -1;
  v7[0] = a1;
  v4 = __readeflags();
  v5 = dword_16C6C9C ^ 0xA5E425FF;
  __writeeflags(v4);
  _InterlockedExchange(v7, v5);
  return sub_5E59F7(a2, a3, a4);
}
