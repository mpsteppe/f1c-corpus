int __userpurge sub_616F90@<eax>(__int32 a1@<edi>, int a2, int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // edi
  __int32 v6[2]; // [esp+0h] [ebp-8h] BYREF

  v6[1] = -1;
  v6[0] = a1;
  v3 = __readeflags();
  v4 = dword_16C6DAC + 1391889153;
  __writeeflags(v3);
  _InterlockedExchange(v6, v4);
  return sub_616F97(a2, a3);
}
