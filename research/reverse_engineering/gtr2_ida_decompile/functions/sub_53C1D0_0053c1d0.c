int __usercall sub_53C1D0@<eax>(__int32 a1@<edi>, int a2)
{
  unsigned int v2; // kr00_4
  int v3; // edi
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = a1;
  v2 = __readeflags();
  v3 = ~dword_16C6EF4 ^ 0x3523827F;
  __writeeflags(v2);
  _InterlockedExchange(v5, v3);
  return sub_53C1D7(a2);
}
