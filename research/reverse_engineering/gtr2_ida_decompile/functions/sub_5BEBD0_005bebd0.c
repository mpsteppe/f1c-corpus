int __cdecl sub_5BEBD0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v6; // kr00_4
  __int32 v7; // ecx
  __int32 v9; // ecx
  __int32 v10[2]; // [esp+0h] [ebp-8h] BYREF

  v10[1] = -1;
  v10[0] = v9;
  v6 = __readeflags();
  v7 = dword_16E20F6 + dword_16C6E6C;
  __writeeflags(v6);
  _InterlockedExchange(v10, v7);
  return sub_5BEBD7(a1, a2, a3, a4, a5, a6);
}
