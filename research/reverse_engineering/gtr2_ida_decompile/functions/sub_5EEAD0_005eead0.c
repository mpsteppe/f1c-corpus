int __thiscall sub_5EEAD0(_DWORD *this, int a2, int a3)
{
  int result; // eax

  this[36] = a2;
  result = a3;
  switch ( a3 )
  {
    case 0:
      this[37] = 191;
      break;
    case 1:
      this[37] = 127;
      break;
    case 2:
      this[37] = 63;
      break;
    case 3:
      this[37] = 0;
      break;
    case 4:
      this[37] = 8;
      break;
    default:
      return result;
  }
  return result;
}
