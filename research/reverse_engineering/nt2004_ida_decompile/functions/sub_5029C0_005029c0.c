char __stdcall sub_5029C0(int a1, int a2)
{
  char result; // al
  bool v3; // zf

  result = 0;
  switch ( a2 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 8:
      v3 = a1 == 0;
      goto LABEL_4;
    case 6:
      v3 = a1 == 1;
LABEL_4:
      if ( v3 )
        result = 1;
      break;
    default:
      return result;
  }
  return result;
}
