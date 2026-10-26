float *__fastcall sub_505990(int a1, float *a2, float *a3, float a4, float a5, float a6, float *a7)
{
  float *result; // eax

  switch ( a1 )
  {
    case 0:
      result = a3;
      *a2 = *(float *)&a3;
      *a7 = a4;
      break;
    case 1:
      *a2 = *(float *)&a3 - a5;
      *a7 = a4;
      break;
    case 2:
      result = a7;
      *a2 = *(float *)&a3 - a5 * 0.5;
      *a7 = a4;
      break;
    case 3:
      *a2 = *(float *)&a3;
      *a7 = a4 - a6;
      break;
    case 4:
      result = a7;
      *a2 = *(float *)&a3 - a5;
      *a7 = a4 - a6;
      break;
    case 5:
      *a2 = *(float *)&a3 - a5 * 0.5;
      *a7 = a4 - a6;
      break;
    case 6:
      result = a3;
      *a2 = *(float *)&a3;
      *a7 = a4 - a6 * 0.5;
      break;
    case 7:
      *a2 = *(float *)&a3 - a5;
      *a7 = a4 - a6 * 0.5;
      break;
    case 8:
      result = a7;
      *a2 = *(float *)&a3 - a5 * 0.5;
      *a7 = a4 - a6 * 0.5;
      break;
    default:
      return result;
  }
  return result;
}
