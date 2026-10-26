bool __usercall ReturnConstant1@<al>(char a1@<fpstat>)
{
  __asm { fninit }
  return a1 == 0;
}
