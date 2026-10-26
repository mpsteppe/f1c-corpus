char __thiscall sub_4B9DA0(int *this, int a2)
{
  char result; // al

  switch ( a2 )
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
      *(_DWORD *)(*this + 3980) = a2;
      result = 1;
      break;
    case 9:
      sub_4B81A0((_DWORD *)*this, 0);
      result = 1;
      break;
    case 10:
      sub_4B8360(*this);
      result = 1;
      break;
    case 11:
      sub_4B8480(*this);
      result = 1;
      break;
    case 12:
      sub_4B84F0(*this);
      result = 1;
      break;
    case 13:
      sub_4B85D0(*this);
      goto LABEL_8;
    default:
LABEL_8:
      result = 1;
      break;
  }
  return result;
}
