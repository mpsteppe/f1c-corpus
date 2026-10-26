int __fastcall sub_5BCDA0(int a1, __int32 a2, int a3, int a4)
{
  unsigned int v4; // kr00_4
  __int32 v5; // edx
  __int32 v7[2]; // [esp+0h] [ebp-8h] BYREF

  v7[1] = -1;
  v7[0] = a2;
  v4 = __readeflags();
  v5 = dword_16C6E90 - *(_DWORD *)((char *)sub_5BE8C0 + 1);
  __writeeflags(v4);
  _InterlockedExchange(v7, v5);
  return sub_5BCDA7(a3, a4);
}
