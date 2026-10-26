// f1c  0x004d91e0  size=58
int __stdcall sub_4D91E0(int a1)
{
  int result; // eax

  result = 0;
  switch ( a1 )
  {
    case 0:
      result = 100;
      break;
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 9:
    case 10:
    case 11:
    case 12:
    case 14:
    case 15:
    case 16:
    case 18:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
      result = 50;
      break;
    case 2:
    case 13:
      result = 49;
      break;
    case 7:
    case 8:
    case 19:
      result = 51;
      break;
    case 17:
      result = 52;
      break;
    default:
      return result;
  }
  return result;
}
