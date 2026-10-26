int __stdcall sub_46CBB0(int a1)
{
  int result; // eax

  switch ( a1 )
  {
    case 1:
      result = 2975;
      break;
    case 2:
      result = 7200;
      break;
    case 3:
      result = 28800;
      break;
    case 4:
      result = 625000;
      break;
    default:
      result = 1487;
      break;
  }
  return result;
}
