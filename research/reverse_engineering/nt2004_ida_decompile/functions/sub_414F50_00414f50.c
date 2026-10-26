char __thiscall sub_414F50(_DWORD *this)
{
  int v2; // eax
  char result; // al

  switch ( *this )
  {
    case 0xFFFFFFFF:
    case 0:
    case 1:
      goto LABEL_5;
    case 2:
    case 3:
    case 4:
    case 5:
      v2 = sub_57A720(aCinematicevent);
      if ( !sub_414650(this[29], v2) )
        goto LABEL_4;
      result = 1;
      this[33] = 0;
      this[34] = 0;
      *this = 2;
      break;
    default:
LABEL_4:
      *this = -1;
LABEL_5:
      result = 0;
      break;
  }
  return result;
}
