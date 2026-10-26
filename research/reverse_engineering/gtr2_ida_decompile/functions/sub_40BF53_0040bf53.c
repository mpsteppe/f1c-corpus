int __cdecl sub_40BF53(int a1, int a2, int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // edi
  __int32 v6; // [esp+0h] [ebp-4h] BYREF

  v3 = __readeflags();
  v4 = dword_16D29CC + dword_16C6C70;
  __writeeflags(v3);
  _InterlockedExchange(&v6, v4);
  return sub_635D81(a1, a2, a3);
}
