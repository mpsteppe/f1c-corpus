// f1c  0x0040f130  size=105
int __thiscall sub_40F130(_DWORD *this)
{
  int result; // eax

  result = this[7];
  switch ( result )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      sub_459830(this + 3);
      if ( *this == -1 )
      {
        sub_4BE180(this);
      }
      else
      {
        sub_410AF0(this);
        sub_4BDF90(this);
      }
      result = sub_4BE010(this);
      break;
    default:
      return result;
  }
  return result;
}
