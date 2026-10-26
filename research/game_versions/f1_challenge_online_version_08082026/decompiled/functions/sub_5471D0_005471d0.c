int __thiscall sub_5471D0(float *this, int a2, int a3)
{
  int result; // eax

  result = a2 - 1;
  switch ( a2 )
  {
    case 1:
      this[24] = (double)a3 * 0.0039215689;
      break;
    case 2:
      this[20] = (double)a3 * 0.0039215689;
      break;
    case 3:
      this[28] = (double)a3 * 0.0039215689;
      break;
    case 4:
      this[32] = (double)a3 * 0.0039215689;
      break;
    default:
      return result;
  }
  return result;
}
