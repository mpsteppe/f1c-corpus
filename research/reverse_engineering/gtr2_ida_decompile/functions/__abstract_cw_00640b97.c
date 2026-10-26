int __usercall _abstract_cw@<eax>(__int16 a1@<bx>)
{
  int result; // eax
  int v2; // ecx

  result = 0;
  if ( (a1 & 1) != 0 )
    result = 16;
  if ( (a1 & 4) != 0 )
    result |= 8u;
  if ( (a1 & 8) != 0 )
    result |= 4u;
  if ( (a1 & 0x10) != 0 )
    result |= 2u;
  if ( (a1 & 0x20) != 0 )
    result |= 1u;
  if ( (a1 & 2) != 0 )
    result |= 0x80000u;
  v2 = a1 & 0xC00;
  if ( v2 )
  {
    switch ( v2 )
    {
      case 1024:
        result |= 0x100u;
        break;
      case 2048:
        result |= 0x200u;
        break;
      case 3072:
        result |= 0x300u;
        break;
    }
  }
  if ( (a1 & 0x300) != 0 )
  {
    if ( (a1 & 0x300) == 0x200 )
      result |= 0x10000u;
  }
  else
  {
    result |= 0x20000u;
  }
  if ( (a1 & 0x1000) != 0 )
    return result | 0x40000;
  return result;
}
