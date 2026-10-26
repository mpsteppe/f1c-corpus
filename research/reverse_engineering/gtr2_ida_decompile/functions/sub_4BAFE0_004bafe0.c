int __thiscall sub_4BAFE0(_DWORD *this)
{
  unsigned int v1; // kr00_4
  __int32 v2; // eax
  __int32 v4; // [esp+0h] [ebp-Ch] BYREF
  int v5; // [esp+4h] [ebp-8h]

  v5 = -1;
  v4 = sub_409FB0(this + 13);
  v1 = __readeflags();
  v2 = __ROR4__(dword_16C6DA4, *(char *)sub_4EA080);
  __writeeflags(v1);
  _InterlockedExchange(&v4, v2);
  sub_4D3CF0(v4, v5);
  sub_4D3CF0("Driver Position:", -1);
  sub_4D3CF0("Team Position:", -1);
  sub_4D3CF0("Next Race:", -1);
  sub_4D3CF0("Overall", -1);
  sub_4D3CF0("Category:", -1);
  sub_4D3CF0("points", -1);
  return 0;
}
