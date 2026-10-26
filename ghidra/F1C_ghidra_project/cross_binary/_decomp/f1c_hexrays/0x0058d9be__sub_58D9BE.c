// f1c  0x0058d9be  size=67
// positive sp value has been detected, the output may be wrong!
int __usercall sub_58D9BE@<eax>(char a1@<ch>, int _EBP@<ebp>)
{
  int result; // eax
  int v3; // [esp-4h] [ebp-4h]

  __asm
  {
    fld     st
    fabs
    fld     tbyte_5E6C0E
    fcompp
    fstsw   word ptr [ebp-0A0h]
  }
  if ( (*(_BYTE *)(_EBP - 159) & 0x41) != 0 )
  {
    result = v3;
    __asm
    {
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    if ( (*(_BYTE *)(_EBP - 159) & 1) != 0 )
    {
      *(_BYTE *)(_EBP - 144) = 4;
      __asm
      {
        fstp    st
        fldz
      }
    }
    else
    {
      __asm
      {
        fstp    st
        fld     tbyte_5E6BF0
      }
      if ( a1 )
        __asm { fchs }
    }
  }
  else
  {
    __asm
    {
      fld     st
      frndint
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    __asm
    {
      fxch    st(1)
      fsub    st, st(1)
      ftst
      fstsw   word ptr [ebp-0A0h]
      fabs
      f2xm1
    }
  }
  return result;
}
