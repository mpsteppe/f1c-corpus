char __stdcall sub_4D2C80(int a1)
{
  char result; // al

  switch ( a1 )
  {
    case 1:
    case 200:
    case 203:
    case 205:
      result = 0;
      break;
    default:
      result = 1;
      break;
  }
  return result;
}
