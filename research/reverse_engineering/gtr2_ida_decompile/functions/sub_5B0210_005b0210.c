float *__stdcall sub_5B0210(float *a1, float *a2)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm6_4
  float v7; // xmm5_4

  v2 = a2[1];
  v3 = a2[2];
  v4 = a2[3];
  v5 = (float)((float)(*a2 * *a2) + (float)(v2 * v2)) + (float)((float)(v3 * v3) + (float)(v4 * v4));
  v6 = 1.0 / fsqrt(v5);
  v7 = (float)((float)(*(float *)&dword_905F00 - (float)(v5 * (float)(v6 * v6))) * *(float *)&dword_905EF0) * v6;
  *a1 = *a2 * v7;
  a1[1] = v2 * v7;
  a1[2] = v3 * v7;
  a1[3] = v4 * v7;
  return a1;
}
