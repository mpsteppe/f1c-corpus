int __cdecl sub_435800(int a1, int a2)
{
  __int32 v2; // ecx
  unsigned int v3; // kr00_4
  __int32 v4; // ecx
  __int32 v6[2]; // [esp+0h] [ebp-8h] BYREF

  v6[1] = -1;
  v6[0] = v2;
  v3 = __readeflags();
  v4 = dword_16C6ED0 + 1823053861;
  __writeeflags(v3);
  _InterlockedExchange(v6, v4);
  return sub_43580D(a1, a2);
}
