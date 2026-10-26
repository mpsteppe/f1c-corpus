// positive sp value has been detected, the output may be wrong!
int __userpurge sub_52A2F9@<eax>(int a1@<eax>, float a2)
{
  __int32 v2; // eax
  int v4; // [esp-10h] [ebp-18h]
  int v5; // [esp-Ch] [ebp-14h]
  int v6; // [esp-8h] [ebp-10h]
  int v7; // [esp-4h] [ebp-Ch]
  int v8; // [esp+0h] [ebp-8h]
  unsigned int v9; // [esp+4h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+8h] [ebp+0h] BYREF

  if ( !--dword_173A25F )
    dword_173A25F = 269;
  v2 = v8 + (v7 ^ v6 ^ v5 ^ (v4 + a1));
  __writeeflags(v9);
  _InterlockedExchange((volatile __int32 *)&retaddr, v2);
  return sub_540AC0(a2);
}
