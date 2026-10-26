int __cdecl sub_4091C6(int a1)
{
  void *v1; // ecx
  unsigned int v2; // kr00_4
  unsigned int v3; // ebx
  __int32 v5; // [esp+0h] [ebp-4h] BYREF

  v2 = __readeflags();
  v3 = dword_16C6C60 ^ 0x9EBC25FF;
  __writeeflags(v2);
  _InterlockedExchange(&v5, v3);
  return sub_5FAB37(v1, a1);
}
