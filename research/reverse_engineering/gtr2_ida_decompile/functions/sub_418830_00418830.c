int __thiscall sub_418830(_DWORD *this, int a2, float a3)
{
  int result; // eax

  result = this[8];
  switch ( result )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      sub_418410();
      result = sub_4700C0(a2, a3);
      break;
    case 7:
      result = sub_584170(a2);
      break;
    default:
      return result;
  }
  return result;
}
