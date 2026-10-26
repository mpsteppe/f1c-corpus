// positive sp value has been detected, the output may be wrong!
int __usercall sub_408491@<eax>(const char *a1@<eax>, char *a2@<edx>)
{
  int v3; // [esp-80h] [ebp-80h] BYREF

  strcpy(a2, a1);
  sub_4CE020(&v3);
  return 0;
}
