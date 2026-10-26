int __thiscall sub_5A3F60(_DWORD *this, int a2, int a3)
{
  int result; // eax

  this[41] = a2;
  result = a3;
  switch ( a3 )
  {
    case 0:
      this[42] = 191;
      break;
    case 1:
      this[42] = 127;
      break;
    case 2:
      this[42] = 63;
      break;
    case 3:
      this[42] = 0;
      break;
    case 4:
      this[42] = 8;
      break;
    default:
      return result;
  }
  return result;
}
