int __thiscall sub_40F4B0(_DWORD *this, int a2, float a3)
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
      sub_40F0D0(this);
      result = sub_4599C0(a2, a3);
      break;
    case 6:
      result = sub_4EBC60(a2, 1);
      break;
    default:
      return result;
  }
  return result;
}
