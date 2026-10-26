// f1c  0x0058dccc  size=25
double __usercall sub_58DCCC@<st0>(int a1@<eax>, double result@<st0>)
{
  if ( (a1 & 0x80000) == 0 )
    return result + 1.0;
  return result;
}
