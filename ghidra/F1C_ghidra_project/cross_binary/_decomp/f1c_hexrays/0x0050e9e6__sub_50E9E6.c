// f1c  0x0050e9e6  size=365
float *__stdcall sub_50E9E6(float *a1, int a2, int a3, int a4, int a5, int a6)
{
  switch ( (a4 != 0) | (2 * ((a5 != 0) | (2 * (a6 != 0)))) )
  {
    case 3:
    case 5:
    case 6:
      goto LABEL_3;
    case 7:
      sub_50CBB0();
LABEL_3:
      sub_50CBB0();
      break;
    default:
      break;
  }
  sub_50C5BD();
  if ( a3 )
  {
    *a1 = (*a1 + 1.0) * (double)*(unsigned int *)(a3 + 8) * 0.5 + (double)*(unsigned int *)a3;
    a1[1] = (1.0 - a1[1]) * (double)*(unsigned int *)(a3 + 12) * 0.5 + (double)*(unsigned int *)(a3 + 4);
    a1[2] = (*(float *)(a3 + 20) - *(float *)(a3 + 16)) * a1[2] + *(float *)(a3 + 16);
  }
  return a1;
}
