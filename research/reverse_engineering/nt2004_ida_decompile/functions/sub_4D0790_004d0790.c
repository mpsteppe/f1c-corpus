double __thiscall sub_4D0790(_BYTE *this)
{
  double result; // st7

  switch ( this[13] & 3 )
  {
    case 1:
      result = 0.72000003;
      break;
    case 2:
      result = 0.86000001;
      break;
    case 3:
      result = 1.0;
      break;
    default:
      result = 0.57999998;
      break;
  }
  return result;
}
