int __userpurge sub_5F5CE0@<eax>(__int32 a1@<esi>, int a2)
{
  unsigned int v2; // kr00_4
  __int32 v3; // esi
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = a1;
  v2 = __readeflags();
  v3 = __ROR4__(dword_16C6D1C, 172);
  __writeeflags(v2);
  _InterlockedExchange(v5, v3);
  return sub_5F5CE7(a2);
}
