int __stdcall sub_502930(int a1)
{
  int result; // eax

  result = 0;
  switch ( a1 )
  {
    case 0:
      result = 100;
      break;
    case 1:
    case 4:
      result = 49;
      break;
    case 2:
      result = 50;
      break;
    default:
      return result;
  }
  return result;
}
