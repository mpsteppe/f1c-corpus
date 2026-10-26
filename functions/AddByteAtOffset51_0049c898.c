// positive sp value has been detected, the output may be wrong!
int __userpurge sub_49C898@<eax>(char a1@<bl>, int a2@<edi>, int a3, int a4)
{
  *(_BYTE *)(a2 + 51) += a1;
  return 0;
}
