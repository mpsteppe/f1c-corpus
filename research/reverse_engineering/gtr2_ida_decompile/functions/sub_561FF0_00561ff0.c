char __stdcall sub_561FF0(int a1, int a2)
{
  char result; // al

  result = 0;
  switch ( a2 )
  {
    case 1:
    case 7:
      switch ( a1 )
      {
        case 1:
        case 3:
        case 6:
        case 7:
        case 9:
        case 10:
        case 11:
        case 12:
        case 20:
        case 21:
        case 22:
        case 23:
          goto LABEL_5;
        default:
          return result;
      }
    case 2:
      switch ( a1 )
      {
        case 0:
        case 1:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 24:
          goto LABEL_5;
        default:
          return result;
      }
    case 3:
    case 4:
    case 5:
      switch ( a1 )
      {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
LABEL_5:
          result = 1;
          break;
        default:
          return result;
      }
      break;
    default:
      return result;
  }
  return result;
}
