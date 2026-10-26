// f1c  0x0058a32a  size=7
// positive sp value has been detected, the output may be wrong!
int __cdecl sub_58A32A(int a1, int a2)
{
  __int32 v3; // [esp-8h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  return ((int (*)(void))_InterlockedExchange((volatile __int32 *)&retaddr, v3))();
}
