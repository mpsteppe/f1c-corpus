int __usercall sub_4B8860@<eax>(int a1@<ecx>, __int32 a2@<edi>)
{
  unsigned int v2; // kr00_4
  __int32 v3; // edi
  __int32 v5; // [esp+0h] [ebp-Ch] BYREF
  int v6; // [esp+4h] [ebp-8h]

  sub_409FB0((_DWORD *)(a1 + 52));
  v6 = -1;
  v5 = a2;
  v2 = __readeflags();
  v3 = dword_16C6DB8 - *(_DWORD *)((char *)sub_413E70 + 1);
  __writeeflags(v2);
  _InterlockedExchange(&v5, v3);
  sub_4D3CF0(v5, v6);
  sub_4D3CF0("Raining", -1);
  sub_4D3CF0("Monsoon", -1);
  return 0;
}
