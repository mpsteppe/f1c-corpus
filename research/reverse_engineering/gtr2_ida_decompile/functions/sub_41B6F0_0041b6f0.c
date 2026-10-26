int __userpurge sub_41B6F0@<eax>(__int32 a1@<ebp>, int a2)
{
  unsigned int v2; // kr00_4
  int v3; // ebp
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = a1;
  v2 = __readeflags();
  v3 = dword_16C6CBC ^ 0x549000FF;
  __writeeflags(v2);
  _InterlockedExchange(v5, v3);
  return sub_41B6F7(a2);
}
