float *__stdcall sub_54AD16(float *a1, float *a2)
{
  float *v3; // ecx
  double v4; // st7
  double v5; // st7
  float v7; // [esp+14h] [ebp+Ch]

  v3 = a1;
  v7 = *a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2] + a2[3] * a2[3];
  if ( v7 <= 1.0842022e-19 )
  {
    *a1 = 0.0;
    a1[1] = 0.0;
    a1[2] = 0.0;
    v5 = 0.0;
    goto LABEL_5;
  }
  *a1 = -*a2;
  a1[1] = -a2[1];
  a1[2] = -a2[2];
  a1[3] = a2[3];
  if ( !sub_548E48(v7, 1.0) )
  {
    v4 = 1.0 / v7;
    *v3 = v4 * *v3;
    v3[1] = v4 * v3[1];
    v3[2] = v4 * v3[2];
    v5 = v4 * v3[3];
LABEL_5:
    v3[3] = v5;
  }
  return v3;
}
