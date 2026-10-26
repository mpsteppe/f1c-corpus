int __usercall sub_5D1740@<eax>(__int32 a1@<eax>, int a2)
{
  unsigned int v2; // kr00_4
  int v3; // eax
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = a1;
  v2 = __readeflags();
  v3 = dword_16ED918 ^ ~dword_16C6C88;
  __writeeflags(v2);
  _InterlockedExchange(v5, v3);
  return sub_5D1747(a2);
}
