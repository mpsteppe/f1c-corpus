// f1c  0x0050eb73  size=390
float *__stdcall sub_50EB73(float *a1, float *a2, int a3, int a4, int a5, int a6)
{
  double v6; // st7
  double v7; // st7

  switch ( (a4 != 0) | (2 * ((a5 != 0) | (2 * (a6 != 0)))) )
  {
    case 1:
    case 2:
    case 4:
      goto LABEL_4;
    case 3:
    case 5:
    case 6:
      goto LABEL_3;
    case 7:
      sub_50CBB0();
LABEL_3:
      sub_50CBB0();
LABEL_4:
      sub_50D0BC();
      break;
    default:
      break;
  }
  if ( a3 )
  {
    v6 = *a2 - (double)*(unsigned int *)a3;
    *a1 = v6 / (double)*(unsigned int *)(a3 + 8) + v6 / (double)*(unsigned int *)(a3 + 8) - 1.0;
    v7 = a2[1] - (double)*(unsigned int *)(a3 + 4);
    a1[1] = -(v7 / (double)*(unsigned int *)(a3 + 12) + v7 / (double)*(unsigned int *)(a3 + 12) - 1.0);
    a1[2] = (a2[2] - *(float *)(a3 + 16)) / (*(float *)(a3 + 20) - *(float *)(a3 + 16));
  }
  sub_50C5BD();
  return a1;
}
