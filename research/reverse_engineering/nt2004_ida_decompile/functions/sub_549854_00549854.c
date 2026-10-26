double __stdcall sub_549854(float *a1)
{
  double v2; // st7
  double v3; // st6
  double v4; // st5
  double v5; // st4
  double v6; // st3
  float v8; // [esp+8h] [ebp+8h]

  v2 = a1[10] * a1[15] - a1[14] * a1[11];
  v3 = a1[15] * a1[9] - a1[13] * a1[11];
  v4 = a1[14] * a1[9] - a1[10] * a1[13];
  v5 = a1[8] * a1[15] - a1[12] * a1[11];
  v6 = a1[14] * a1[8] - a1[12] * a1[10];
  v8 = a1[8] * a1[13] - a1[12] * a1[9];
  return (v2 * a1[5] - v3 * a1[6] + v4 * a1[7]) * *a1
       - (v2 * a1[4] - v5 * a1[6] + v6 * a1[7]) * a1[1]
       + (v3 * a1[4] - v5 * a1[5] + v8 * a1[7]) * a1[2]
       - (v4 * a1[4] - v6 * a1[5] + v8 * a1[6]) * a1[3];
}
