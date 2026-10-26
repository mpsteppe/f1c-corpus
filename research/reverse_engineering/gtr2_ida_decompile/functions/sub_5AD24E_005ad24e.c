float *__stdcall sub_5AD24E(float *a1, float *a2, int a3, int a4, int a5, int a6)
{
  double v6; // st7
  double v7; // st7
  int v9; // [esp-68h] [ebp-6Ch]
  float v10[22]; // [esp-54h] [ebp-58h] BYREF

  switch ( (a4 != 0) | (2 * ((a5 != 0) | (2 * (a6 != 0)))) )
  {
    case 0:
      v10[14] = 0.0;
      v10[13] = 0.0;
      v10[12] = 0.0;
      v10[11] = 0.0;
      v10[9] = 0.0;
      v10[8] = 0.0;
      v10[7] = 0.0;
      v10[6] = 0.0;
      v10[4] = 0.0;
      v10[3] = 0.0;
      v10[2] = 0.0;
      v10[1] = 0.0;
      v10[15] = 1.0;
      v10[10] = 1.0;
      v10[5] = 1.0;
      v10[0] = 1.0;
      break;
    case 1:
    case 2:
    case 4:
      goto LABEL_8;
    case 3:
      sub_5AA514((int)v10, a5, a4);
      goto LABEL_8;
    case 5:
      v9 = a4;
      goto LABEL_6;
    case 6:
      v9 = a5;
LABEL_6:
      sub_5AA514((int)v10, a6, v9);
      goto LABEL_8;
    case 7:
      sub_5AA514((int)v10, a6, a5);
      sub_5AA514((int)v10, (int)v10, a4);
LABEL_8:
      sub_5AAA3A();
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
  sub_5A9C3F();
  return a1;
}
