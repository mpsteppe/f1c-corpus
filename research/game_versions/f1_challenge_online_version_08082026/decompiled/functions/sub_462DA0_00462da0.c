char *__stdcall sub_462DA0(int a1)
{
  char *result; // eax

  switch ( a1 )
  {
    case 1:
      result = aIncompatibleGa;
      break;
    case 2:
      result = aTheGameIsFull;
      break;
    case 3:
      result = aGameClosed;
      break;
    case 4:
      result = aBadPassword;
      break;
    case 5:
      result = aJoinTimedOut;
      break;
    default:
      result = aNoJoinFailure;
      break;
  }
  return result;
}
