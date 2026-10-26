// positive sp value has been detected, the output may be wrong!
int __userpurge sub_592E41@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, int a5, int a6)
{
  int v7; // [esp-8h] [ebp-8h] BYREF

  LOBYTE(a1) = a1 & 8;
  return ((int (__thiscall *)(int, int, int, int *))loc_5A401E)(a1, a2, a3, &v7);
}
