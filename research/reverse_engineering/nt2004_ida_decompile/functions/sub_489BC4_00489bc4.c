// positive sp value has been detected, the output may be wrong!
int __userpurge sub_489BC4@<eax>(char a1@<bl>, int a2@<esi>, int a3)
{
  *(_BYTE *)(a2 - 62) += a1;
  return 0;
}
