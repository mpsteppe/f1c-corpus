int __stdcall sub_552190(int a1, int a2, int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // ebp
  __int32 v6[2]; // [esp+0h] [ebp-8h] BYREF
  int _8; // [esp+8h] [ebp+0h] BYREF

  v6[1] = -1;
  v6[0] = (__int32)&_8;
  v3 = __readeflags();
  v4 = dword_16C6C80 - 788594324;
  __writeeflags(v3);
  _InterlockedExchange(v6, v4);
  return sub_55219D(a1, a2, a3);
}
