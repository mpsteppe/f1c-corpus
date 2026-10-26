// f1c  0x0058da01  size=52
double __usercall sub_58DA01@<st0>(double result@<st0>)
{
  _ST6 = result;
  __asm { frndint }
  if ( _ST6 == result )
  {
    _ST5 = result * dbl_5E6C22;
    __asm { frndint }
  }
  return result;
}
