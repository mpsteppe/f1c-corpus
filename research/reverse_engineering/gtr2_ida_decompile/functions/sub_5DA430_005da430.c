int __usercall sub_5DA430@<eax>(__int32 a1@<edi>, int a2)
{
  unsigned int v2; // kr00_4
  char *v3; // edi
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = a1;
  v2 = __readeflags();
  v3 = (char *)off_16EF4A8 + dword_16C6C6C;
  __writeeflags(v2);
  _InterlockedExchange(v5, (__int32)v3);
  return sub_5DA437(a2);
}
