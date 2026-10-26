int __cdecl sub_48412D(int a1)
{
  unsigned int v1; // kr00_4
  int v2; // ebx
  __int32 v4; // [esp+0h] [ebp-4h] BYREF

  v1 = __readeflags();
  v2 = dword_16C6D58 ^ *(_DWORD *)((char *)sub_46C620 + 1);
  __writeeflags(v1);
  _InterlockedExchange(&v4, v2);
  return sub_48CB57(a1);
}
