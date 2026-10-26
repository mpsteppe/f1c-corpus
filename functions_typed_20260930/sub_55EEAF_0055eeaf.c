void __cdecl sub_55EEAF(float *a1, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st6

  v3 = a3[1] * *a1 + a3[5] * a1[1] + a3[9] * a1[2] + a3[13];
  v4 = a3[2] * *a1 + a3[6] * a1[1] + a3[10] * a1[2] + a3[14];
  *a2 = *a3 * *a1 + a3[4] * a1[1] + a3[8] * a1[2] + a3[12];
  a2[2] = v4;
  a2[1] = v3;
}

