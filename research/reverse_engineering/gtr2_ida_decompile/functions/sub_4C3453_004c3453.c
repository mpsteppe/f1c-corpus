// positive sp value has been detected, the output may be wrong!
int __stdcall sub_4C3453(int a1)
{
  int v2; // [esp-24h] [ebp-24h]
  int v3; // [esp-20h] [ebp-20h]

  if ( operator new(0x114u) )
    return sub_4BC750(v2, v3);
  else
    return ((int (__stdcall *)(int))sub_4CC3A1)(a1);
}
