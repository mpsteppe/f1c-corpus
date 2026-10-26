// positive sp value has been detected, the output may be wrong!
int __userpurge sub_433150@<eax>(int a1@<esi>, int a2, int a3)
{
  return sprintf((char *const)(a1 + 30), "%d", *(_DWORD *)(a1 + 20) + 1);
}
