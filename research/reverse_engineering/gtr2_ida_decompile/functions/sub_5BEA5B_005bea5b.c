// positive sp value has been detected, the output may be wrong!
int __usercall sub_5BEA5B@<eax>(int a1@<eax>, int a2, int a3, int a4)
{
  __int32 v4; // eax
  int v6; // [esp-Ch] [ebp-10h]
  int v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]
  unsigned int v9; // [esp+0h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+4h] [ebp+0h] BYREF

  if ( !--dword_1739A19 )
    dword_1739A19 = 699;
  if ( !--dword_1739A1E )
    dword_1739A1E = 675;
  v4 = v8 + (v7 ^ (a1 - v6));
  __writeeflags(v9);
  _InterlockedExchange((volatile __int32 *)&retaddr, v4);
  return _lseek(a2, a3, a4);
}
