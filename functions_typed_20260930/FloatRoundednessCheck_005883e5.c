void __usercall sub_5883E5(double a1@<st0>)
{
  _ST6 = a1;
  __asm { frndint }
  if ( _ST6 == a1 )
  {
    _ST6 = a1 * dbl_5E63B0;
    __asm { frndint }
  }
}

