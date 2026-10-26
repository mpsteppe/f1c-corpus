float *__stdcall sub_52035E(float *a1, float *a2)
{
  float *result; // eax
  float v3; // xmm6_4
  float v4; // xmm5_4
  float v5; // xmm3_4
  float v6; // xmm3_4
  float v7; // xmm0_4

  result = a1;
  v3 = a2[1];
  v4 = a2[2];
  v5 = (float)((float)(*a2 * *a2) + (float)(v3 * v3)) + (float)(v4 * v4);
  if ( *(float *)&dword_8D6180 <= v5 )
  {
    v6 = 1.0 / fsqrt(v5);
    v7 = (float)(*(float *)&dword_8D6184 * v6)
       * (float)(*(float *)&dword_8D6188
               - (float)((float)((float)((float)((float)(*a2 * *a2) + (float)(a2[1] * a2[1])) + (float)(a2[2] * a2[2]))
                               * v6)
                       * v6));
    *a1 = v7 * *a2;
    a1[1] = v7 * v3;
    a1[2] = v7 * v4;
  }
  else
  {
    *a1 = 0.0;
    a1[1] = 0.0;
    a1[2] = 0.0;
  }
  return result;
}

