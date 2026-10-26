// positive sp value has been detected, the output may be wrong!
int __userpurge sub_4B5CCD@<eax>(
        int a1@<eax>,
        int a2@<ecx>,
        int a3@<ebx>,
        int a4@<edi>,
        int a5@<esi>,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10)
{
  int result; // eax

  result = sub_59FFB0(a2, a5, a9, a4 - a5, a1);
  if ( a3 + 1 < 3 )
    JUMPOUT(0x4B5C88);
  return result;
}
