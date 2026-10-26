int __cdecl sub_4F14D0(int a1)
{
  unsigned int v1; // kr00_4
  char *v2; // ecx
  __int32 v4; // ecx
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = v4;
  v1 = __readeflags();
  v2 = (char *)off_16CC971 + dword_16C6C4C + 1;
  __writeeflags(v1);
  _InterlockedExchange(v5, (__int32)v2);
  return sub_4F14D7(a1);
}
