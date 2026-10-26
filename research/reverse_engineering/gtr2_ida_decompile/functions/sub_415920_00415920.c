int __usercall sub_415920@<eax>(__int32 a1@<eax>, int a2)
{
  unsigned int v2; // kr00_4
  __int32 v3; // eax
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = a1;
  v2 = __readeflags();
  v3 = dword_16C6D94 - (loc_125D950 + 1);
  __writeeflags(v2);
  _InterlockedExchange(v5, v3);
  return sub_415927(a2);
}
