float *__stdcall sub_5AFC25(float *a1, float *a2)
{
  float v2; // xmm3_4
  float v3; // xmm4_4
  float v4; // xmm5_4
  float v5; // xmm0_4
  float v6; // xmm6_4
  float v7; // xmm1_4

  v2 = *a2;
  v3 = a2[1];
  v4 = a2[2];
  v5 = (float)((float)(v2 * v2) + (float)(v3 * v3)) + (float)(v4 * v4);
  if ( v5 >= 1.4210855e-14 )
  {
    v6 = 1.0 / fsqrt(v5);
    v7 = (float)(3.0 - (float)((float)(v6 * v5) * v6)) * (float)(v6 * 0.5);
    *a1 = v2 * v7;
    a1[1] = v3 * v7;
    a1[2] = v4 * v7;
  }
  else
  {
    *a1 = 0.0;
    a1[1] = 0.0;
    a1[2] = 0.0;
  }
  return a1;
}
