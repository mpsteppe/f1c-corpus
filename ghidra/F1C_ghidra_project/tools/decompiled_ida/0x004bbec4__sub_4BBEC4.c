// Address: 0x004bbec4
// Size: 12 bytes
// Name: sub_4BBEC4
// Type: int __usercall@<eax>(int result@<eax>, unsigned int@<ecx>, char@<bh>, void *@<edi>)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
int __usercall sub_4BBEC4@<eax>(int result@<eax>, unsigned int a2@<ecx>, char a3@<bh>, void *a4@<edi>)
{
  *(_BYTE *)(a2 + 10) += a3;
  memset32(a4, result, a2);
  return result;
}
