// positive sp value has been detected, the output may be wrong!
int __userpurge sub_46C6D1@<eax>(unsigned int a1@<eax>, unsigned int a2@<esi>, char *a3, int a4)
{
  unsigned int v4; // kr00_4
  __int32 v5; // esi
  __int32 v6; // esi
  int v8; // [esp-8h] [ebp-8h]
  unsigned int v9; // [esp-4h] [ebp-4h] BYREF

  __writeeflags(v9);
  memset32(&STACK[0x2C8], v8, a1);
  v9 = a2;
  v4 = __readeflags();
  v5 = loc_57624D + dword_16C67D8;
  __writeeflags(v4);
  v6 = _InterlockedExchange((volatile __int32 *)&v9, v5);
  STACK[0x2B0] = v6;
  STACK[0x2C4] = v6;
  STACK[0x2BC] = v6;
  STACK[0x2C0] = v6;
  LOBYTE(STACK[0x2B4]) = 1;
  return sub_613DE0(a3, a4);
}
