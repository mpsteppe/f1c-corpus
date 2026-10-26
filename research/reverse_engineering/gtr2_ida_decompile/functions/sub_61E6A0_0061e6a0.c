int __usercall sub_61E6A0@<eax>(__int32 a1@<edi>, int a2)
{
  unsigned int v2; // kr00_4
  char *v3; // edi
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = a1;
  v2 = __readeflags();
  v3 = &(*off_16C6D0C)[89053];
  __writeeflags(v2);
  _InterlockedExchange(v5, (__int32)v3);
  return sub_61E6A7(a2);
}
