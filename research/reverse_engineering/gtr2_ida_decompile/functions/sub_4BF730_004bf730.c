int __usercall sub_4BF730@<eax>(__int32 a1@<ebp>, int a2)
{
  unsigned int v2; // kr00_4
  __int32 v3; // ebp
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = a1;
  v2 = __readeflags();
  v3 = __ROR4__(dword_16C6DB0, 37);
  __writeeflags(v2);
  _InterlockedExchange(v5, v3);
  return sub_4BF737(a2);
}
