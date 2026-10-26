double __stdcall sub_497B00(int a1)
{
  double result; // st7

  result = -1.0;
  switch ( a1 )
  {
    case 1:
      result = 0.016666668;
      break;
    case 2:
      result = 0.041666668;
      break;
    case 3:
      result = 0.125;
      break;
    case 4:
      result = 0.25;
      break;
    case 5:
      result = 0.5;
      break;
    case 6:
      result = 1.0;
      break;
    default:
      return result;
  }
  return result;
}
