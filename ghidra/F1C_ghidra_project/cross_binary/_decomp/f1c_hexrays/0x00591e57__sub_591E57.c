// f1c  0x00591e57  size=15
int __usercall sub_591E57@<eax>(__int16 a1@<fpstat>)
{
  __asm { fnclex }
  return a1;
}
