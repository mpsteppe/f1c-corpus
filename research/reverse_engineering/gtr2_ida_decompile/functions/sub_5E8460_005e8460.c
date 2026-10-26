int __thiscall sub_5E8460(float *this, int a2, int a3)
{
  int result; // eax

  result = a2 - 1;
  switch ( a2 )
  {
    case 1:
      this[25] = (double)a3 * 0.0039215689;
      break;
    case 2:
      this[21] = (double)a3 * 0.0039215689;
      break;
    case 3:
      this[29] = (double)a3 * 0.0039215689;
      break;
    case 4:
      this[33] = (double)a3 * 0.0039215689;
      break;
    default:
      return result;
  }
  return result;
}
