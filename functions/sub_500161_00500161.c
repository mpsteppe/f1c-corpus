// positive sp value has been detected, the output may be wrong!
int __userpurge sub_500161@<eax>(int a1@<eax>, int a2@<edx>, int a3, int a4, int a5)
{
  int v6; // [esp-4h] [ebp-4h]

  return ((int (__stdcall *)(int, int, int, int))((char *)&loc_4FF715 + 2))(a3, a2, a1, v6);
}
