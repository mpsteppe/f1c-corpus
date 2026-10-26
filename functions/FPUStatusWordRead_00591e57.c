int __usercall sub_591E57@<eax>(__int16 a1@<fpstat>)
{
  __asm { fnclex }
  return a1;
}
