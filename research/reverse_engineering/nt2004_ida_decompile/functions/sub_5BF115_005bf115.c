void __usercall sub_5BF115(double a1@<st0>)
{
  _ST6 = a1;
  __asm { frndint }
  if ( _ST6 == a1 )
  {
    _ST6 = a1 * dbl_625080;
    __asm { frndint }
  }
}
