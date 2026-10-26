int __userpurge sub_5BE180@<eax>(__int32 a1@<esi>, int a2, int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // esi
  __int32 v6[2]; // [esp+0h] [ebp-8h] BYREF

  v6[1] = -1;
  v6[0] = a1;
  v3 = __readeflags();
  v4 = *(_DWORD *)sub_540E90 + dword_16C6C3C;
  __writeeflags(v3);
  _InterlockedExchange(v6, v4);
  return sub_5BE187(a2, a3);
}
