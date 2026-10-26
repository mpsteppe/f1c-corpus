double __thiscall sub_4FC570(float *this, int a2)
{
  double result; // st7

  switch ( a2 )
  {
    case 0:
      result = this[224];
      break;
    case 1:
      result = (double)sub_52B810(*(_DWORD *)this + 19272);
      break;
    case 2:
      result = this[222];
      break;
    case 3:
      result = this[220];
      break;
    case 4:
      result = this[221];
      break;
    case 5:
      result = this[226];
      break;
    case 6:
      result = this[227];
      break;
    case 7:
      result = this[228];
      break;
    case 8:
      result = this[229];
      break;
    case 9:
      result = this[230];
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}
