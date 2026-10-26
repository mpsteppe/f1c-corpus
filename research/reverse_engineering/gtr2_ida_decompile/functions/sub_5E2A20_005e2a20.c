int __thiscall sub_5E2A20(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  switch ( a2 )
  {
    case 0:
      this[31] = 191;
      break;
    case 1:
      this[31] = 127;
      break;
    case 2:
      this[31] = 63;
      break;
    case 3:
      this[31] = 1;
      break;
    default:
      return result;
  }
  return result;
}
