// f1c  0x00568fa4  size=12
// positive sp value has been detected, the output may be wrong!
int __userpurge sub_568FA4@<eax>(int a1@<eax>, char a2@<ch>, int a3, int a4, int a5, int a6)
{
  LOBYTE(a1) = a2 + a1;
  return MEMORY[0x5E5F0000] + a1;
}
