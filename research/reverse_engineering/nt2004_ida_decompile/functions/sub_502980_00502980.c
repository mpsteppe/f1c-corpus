char __stdcall sub_502980(int a1, int a2)
{
  char result; // al

  result = 0;
  if ( a2 >= 3 && (a2 <= 5 || a2 == 8) )
  {
    switch ( a1 )
    {
      case 0:
      case 1:
      case 2:
      case 4:
        result = 1;
        break;
      default:
        return result;
    }
  }
  return result;
}
