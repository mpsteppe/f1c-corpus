double __thiscall sub_4C2BB0(_DWORD *this)
{
  double result; // st7

  result = 0.0;
  switch ( this[24] )
  {
    case 1:
      result = 9.4635296;
      break;
    case 2:
      result = 20.819765;
      break;
    case 3:
      result = 41.63953;
      break;
    case 4:
      result = 62.459297;
      break;
    case 5:
      result = 83.27906;
      break;
    default:
      return result;
  }
  return result;
}
