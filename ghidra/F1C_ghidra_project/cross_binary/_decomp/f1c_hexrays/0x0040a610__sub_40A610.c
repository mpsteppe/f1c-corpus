// f1c  0x0040a610  size=72
int __thiscall sub_40A610(_DWORD *this, int a2)
{
  int result; // eax

  result = 0;
  switch ( a2 )
  {
    case 0:
      result = this[4];
      break;
    case 1:
      result = this[5];
      break;
    case 2:
      result = this[6];
      break;
    case 3:
      result = this[7];
      break;
    case 4:
      result = this[8];
      break;
    case 5:
      result = this[9];
      break;
    case 6:
      result = this[10];
      break;
    case 7:
      result = this[11];
      break;
    case 8:
      result = this[12];
      break;
    default:
      return result;
  }
  return result;
}
