double *__thiscall sub_44C550(double *this, double *a2, float *a3)
{
  double *result; // eax
  double v5; // st7
  double v6; // st7
  double v7; // st6
  long double v8; // st5
  float v9; // [esp+4h] [ebp-4h]
  float v10; // [esp+Ch] [ebp+4h]

  result = (double *)SpatialGridQuery(this, (int)a2);
  if ( result )
  {
    v10 = a2[2];
    v5 = *a2;
    v9 = v5;
    v6 = v5 * *result + v5 * *result + v10 * result[2] + result[3];
    v7 = v10 * result[1] + v10 * result[1] + v9 * result[2] + result[4];
    v8 = 1.0 / sqrt(v7 * v7 + v6 * v6 + 1.0);
    *a3 = -(v8 * v6);
    a3[1] = v8;
    a3[2] = -(v8 * v7);
  }
  return result;
}

