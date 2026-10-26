// f1c  0x004a46e4  size=12
// positive sp value has been detected, the output may be wrong!
int __usercall sub_4A46E4@<eax>(int a1@<ecx>, char a2@<bh>, void *a3@<edi>)
{
  int result; // eax

  *(_BYTE *)(a1 + 104) += a2;
  result = 0;
  memset(a3, 0, 4 * a1);
  return result;
}
