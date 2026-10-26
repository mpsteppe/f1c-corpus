int __thiscall sub_552FF0(_DWORD *this, int a2, int a3)
{
  int result; // eax

  this[21] = a2;
  result = a3;
  switch ( a3 )
  {
    case 0:
      this[22] = 191;
      break;
    case 1:
      this[22] = 127;
      break;
    case 2:
      this[22] = 63;
      break;
    case 3:
      this[22] = 0;
      break;
    case 4:
      this[22] = 255;
      break;
    default:
      return result;
  }
  return result;
}
