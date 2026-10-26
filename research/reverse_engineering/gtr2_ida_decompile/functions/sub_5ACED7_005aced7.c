float *__stdcall sub_5ACED7(float *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // [esp-68h] [ebp-6Ch]
  float v8[22]; // [esp-54h] [ebp-58h] BYREF

  switch ( (a4 != 0) | (2 * ((a5 != 0) | (2 * (a6 != 0)))) )
  {
    case 0:
      v8[14] = 0.0;
      v8[13] = 0.0;
      v8[12] = 0.0;
      v8[11] = 0.0;
      v8[9] = 0.0;
      v8[8] = 0.0;
      v8[7] = 0.0;
      v8[6] = 0.0;
      v8[4] = 0.0;
      v8[3] = 0.0;
      v8[2] = 0.0;
      v8[1] = 0.0;
      v8[15] = 1.0;
      v8[10] = 1.0;
      v8[5] = 1.0;
      v8[0] = 1.0;
      break;
    case 3:
      sub_5AA514((int)v8, a5, a4);
      break;
    case 5:
      v7 = a4;
      goto LABEL_6;
    case 6:
      v7 = a5;
LABEL_6:
      sub_5AA514((int)v8, a6, v7);
      break;
    case 7:
      sub_5AA514((int)v8, a6, a5);
      sub_5AA514((int)v8, (int)v8, a4);
      break;
    default:
      break;
  }
  sub_5A9C3F();
  if ( a3 )
  {
    *a1 = (*a1 + 1.0) * (double)*(unsigned int *)(a3 + 8) * 0.5 + (double)*(unsigned int *)a3;
    a1[1] = (1.0 - a1[1]) * (double)*(unsigned int *)(a3 + 12) * 0.5 + (double)*(unsigned int *)(a3 + 4);
    a1[2] = (*(float *)(a3 + 20) - *(float *)(a3 + 16)) * a1[2] + *(float *)(a3 + 16);
  }
  return a1;
}
