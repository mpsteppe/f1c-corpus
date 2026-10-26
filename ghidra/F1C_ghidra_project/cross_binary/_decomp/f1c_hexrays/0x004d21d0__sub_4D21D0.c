// f1c  0x004d21d0  size=30
char sub_4D21D0()
{
  char result; // al

  switch ( dword_7C56A8 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      result = 0;
      break;
    default:
      result = 1;
      break;
  }
  return result;
}
