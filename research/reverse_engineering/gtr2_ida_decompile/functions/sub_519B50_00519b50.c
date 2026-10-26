int __cdecl sub_519B50(int a1)
{
  unsigned int v1; // kr00_4
  __int32 v2; // ebp
  sbdt::PlayerFile *v4; // ecx
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF
  int _8; // [esp+8h] [ebp+0h] BYREF

  v5[1] = -1;
  v5[0] = (__int32)&_8;
  v1 = __readeflags();
  v2 = dword_16F79F3 + dword_16C6D08;
  __writeeflags(v1);
  _InterlockedExchange(v5, v2);
  return sub_519B5D(v4, a1);
}
