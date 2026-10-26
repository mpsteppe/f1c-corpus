// positive sp value has been detected, the output may be wrong!
int __userpurge sub_5A11A6@<eax>(int a1@<ecx>, char a2@<bl>, int a3@<esi>, int a4)
{
  *(_BYTE *)(a3 + 93) += a2;
  return a1;
}
