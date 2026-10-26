bool __stdcall sub_4D93E0(int a1, int a2)
{
  bool result; // al

  result = 0;
  switch ( a2 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      result = a1 == 0;
      break;
    default:
      return result;
  }
  return result;
}
