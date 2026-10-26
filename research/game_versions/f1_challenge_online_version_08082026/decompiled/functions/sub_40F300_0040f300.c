int __thiscall sub_40F300(_DWORD *this, float a2)
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
      result = sub_45AE00(a2);
      break;
    case 6:
      sub_4F0430(a2);
      result = sub_4EF180(this[8]);
      break;
    default:
      return result;
  }
  return result;
}
