// f1c  0x004bbec4  size=12
// positive sp value has been detected, the output may be wrong!
int __usercall sub_4BBEC4@<eax>(int result@<eax>, unsigned int a2@<ecx>, char a3@<bh>, void *a4@<edi>)
{
  *(_BYTE *)(a2 + 10) += a3;
  memset32(a4, result, a2);
  return result;
}
