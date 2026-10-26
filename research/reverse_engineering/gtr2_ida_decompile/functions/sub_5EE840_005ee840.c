int __usercall sub_5EE840@<eax>(void *a1@<ecx>, __int32 a2@<esi>, int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // esi
  __int32 v6[2]; // [esp+0h] [ebp-8h] BYREF

  v6[1] = -1;
  v6[0] = a2;
  v3 = __readeflags();
  v4 = __ROR4__(dword_16C6EE4, 255);
  __writeeflags(v3);
  _InterlockedExchange(v6, v4);
  return sub_5EE847(a1, a3);
}
