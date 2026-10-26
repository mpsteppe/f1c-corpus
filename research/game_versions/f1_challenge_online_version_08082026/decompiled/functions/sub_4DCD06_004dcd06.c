// positive sp value has been detected, the output may be wrong!
int __userpurge sub_4DCD06@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  *(_BYTE *)(a2 + 94) += a1;
  return a1;
}
