int __fastcall sub_5D6120(int a1, __int32 a2, int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // edx
  __int32 v6[2]; // [esp+0h] [ebp-8h] BYREF

  v6[1] = -1;
  v6[0] = a2;
  v3 = __readeflags();
  v4 = dword_16C6E5C + 1823008805;
  __writeeflags(v3);
  _InterlockedExchange(v6, v4);
  return sub_5D6127(a3);
}
